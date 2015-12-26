#include "warscrollrelationsgraph.h"

#include "graphvisualizer.h"

#include "geometries/ellipse.h"

#include "math/matrix.h"
#include "planes/plane_3d.h"

#include <QQuickWindow>

#include <iostream>
#include <map>
#include <utility>

#if __OPENGL_CORE_WINDOWS__
const std::atomic_bool t{true};
const std::atomic_bool f{false};
#else
const bool t = true;
const bool f = false;
#endif

const float initZ = 10.0;

WarScrollRelationsGraph::WarScrollRelationsGraph()
  : m_projection(opengl_math::identity)
  , m_view(opengl_math::identity)
  , m_z(initZ)
  , m_zoom(Zoom::None)
  , m_y(0.0)
  , m_x(0.0)
  , m_currScrollIndex(-1)
  , m_prevScrollIndex(-1)
  , m_doubleClickedEllipse(nullptr)
{
  m_draw = f;
  m_create = f;
  m_initialize = t;
  m_scrollChanged = f;

  for (auto ellipse : m_ellipses) {
    ellipse = nullptr;
    (void)ellipse;
  }
}

WarScrollRelationsGraph::~WarScrollRelationsGraph()
{
  m_initialize = f;
  m_draw = f;
  m_create = f;

  for (auto ellipse : m_ellipses) {
    if (ellipse) {
      ellipse.reset();
    }
  }
}

void WarScrollRelationsGraph::setViewport(const QPointF &lowerLeft,
  const QSize &size)
{
  float x = lowerLeft.x();
  float y = lowerLeft.y();

  m_viewport = opengl_math::axis_aligned_2d<float>(
    opengl_math::point_2d<float>(x, y), size.width(), size.height());

  float den = (m_viewport.height() == 0) ? 1.0f :
    static_cast<float>(m_viewport.height());
  float num = static_cast<float>(m_viewport.width());
  m_projection = opengl_math::perspective<float, opengl_math::column>(
    45.0f, num / den, 1.0, 100.0, opengl_math::degrees);
}

void WarScrollRelationsGraph::creatStaticData()
{
  initializeOpenGLFunctions();
}

void WarScrollRelationsGraph::initGraphData()
{
  m_ellipses.clear();
  m_vertices.clear();

  std::vector<std::string> names = extractNamesFromGraph(m_graph);

  m_atlasNameMap.clearAtlas();
  m_atlasNameMap.backgroundColor(QColor(200, 200, 200, 255));
  m_atlasNameMap.generateAtlas(names);
  m_atlasNameMap.createTexture();

  generateEllipses(m_ellipses, m_vertices, m_graph, &m_atlasNameMap);

  QVariantList list;
  for (const WarScrollSynergyGraph::Vertex &vert : m_vertices) {
    QString name(vert.getWarScroll()->getTitle().c_str());
    list.push_back(QVariant::fromValue(name));
  }

  Q_ASSERT(RootView::getRootView());
  QMetaObject::invokeMethod(RootView::getRootView()->rootObject(),
    "updateWarScrollGraphList", Q_ARG(QVariant, QVariant::fromValue(list)));

  m_prevScrollIndex = -1;
  m_currScrollIndex = -1;
  m_create = t;

  if (std::distance(m_graph->begin(), m_graph->end()) > 0) {
    warScrollSelected(0);
  }

  m_scrollChanged = t;
}

void WarScrollRelationsGraph::updateGraph()
{
  if (m_vertices.empty()) {
    m_currScrollIndex = -1;
    m_prevScrollIndex = -1;
    return;
  }
  const WarScrollSynergyGraph::Vertex &vertex = m_vertices[m_currScrollIndex];
  const std::vector<WarScrollSynergyGraph::Edge> &edges =
    vertex.adjacents();

  std::size_t adjacents = edges.size();
  for (const WarScrollSynergyGraph::Edge edge : edges) {
    if (edge.adjacent().getWarScroll() == vertex.getWarScroll()) {
      --adjacents;
      break;
    }
  }

  float angleDelta = 360.0f / adjacents;

  m_currEllipses.clear();
  m_currSplines.clear();
  m_currEdgeLabels.clear();
  m_doubleClickedEllipse = nullptr;

  std::vector<std::string> names;
  Protection::Ellipse copy = *(m_ellipses[m_currScrollIndex].get());
  m_currEllipses.push_back(copy);
  names.push_back(copy.getWarScroll().getTitle());
  const float radius = 3.0f;

  std::vector<std::string> edgeLabels;

  float currAngle = 270.0;
  for (const WarScrollSynergyGraph::Edge &edge : edges) {
    const WarScrollSynergyGraph::Vertex &vertex = edge.adjacent();
    auto it = std::find(m_vertices.begin(), m_vertices.end(), vertex);
    Q_ASSERT(it != m_vertices.end());

    std::size_t index = std::distance(m_vertices.begin(), it);

    if (index != static_cast<std::size_t>(m_currScrollIndex)) {
      copy = *(m_ellipses[index].get());
      copy.setTransform(opengl_math::translate_by(copy.getTransform(),
        opengl_math::vector_3d<float>(
          radius * opengl_math::cos<float, opengl_math::degrees>(currAngle),
          radius * opengl_math::sin<float, opengl_math::degrees>(currAngle),
          0.0f)));
      names.push_back(copy.getWarScroll().getTitle());
      m_currEllipses.push_back(copy);
      edgeLabels.push_back(edge.keyWordConnection().getKeyWord());

      currAngle += angleDelta;
    }
  }

  m_atlasKeywordMap.clearAtlas();
  m_atlasKeywordMap.backgroundColor(QColor(200, 200, 200, 0));
  m_atlasKeywordMap.generateAtlas(edgeLabels);
  m_atlasKeywordMap.createTexture();

  // The first node in m_currEllipses will be the center node of the graph,
  // so we don't consider it in collisions.
  bool collision = false;
  for (auto it = m_currEllipses.begin() + 1; it != m_currEllipses.end(); ++it) {
    Protection::Ellipse ccw;
    Protection::Ellipse cw;
    Protection::Ellipse &curr = (*it);

    if (*(m_currEllipses.begin()) == (*it)) {
      ccw = (*(it + 1));
      cw = (*(m_currEllipses.end() - 1));
    } else if ((*(m_currEllipses.end() - 1) == (*it))) {
      ccw = *(m_currEllipses.begin());
      cw = (*(it - 1));
    } else {
      ccw = (*(it + 1));
      cw = (*(it - 1));
    }

    // Clean up layout if there are collisions with adjacent ellipses
    auto &ellipse = curr;
    collision = ellipse.collides(ccw) || ellipse.collides(cw);
    if (collision) {
      break;
    }
  }

  if (collision) {
    currAngle = 270.0;
    float vradius = 3.0 * (m_currEllipses.size() / 10.0);
    for (auto it = m_currEllipses.begin() + 1; it != m_currEllipses.end();
      ++it) {
      auto trans = it->getTransform();
      trans = opengl_math::translate_to(trans,
        opengl_math::point_3d<float>(0.0f, 0.0f, 0.0f));
      trans = opengl_math::translate_by(trans,
        opengl_math::vector_3d<float>(
          vradius * opengl_math::cos<float, opengl_math::degrees>(currAngle),
          vradius * opengl_math::sin<float, opengl_math::degrees>(currAngle),
          0.0f));
      it->setTransform(trans);
      currAngle += angleDelta;
    }
  }

  generateSplines(m_currSplines, m_currEdgeLabels, m_currEllipses, edgeLabels,
    &m_atlasKeywordMap);

  // Reset the camera to stare at (0, 0).
  m_z = initZ;
  m_x = 0.0f;
  m_y = 0.0f;
  m_view = opengl_math::look_at<float, opengl_math::column>(
    opengl_math::point_3d<float>(m_x, m_y, static_cast<float>(m_z)),
    opengl_math::point_3d<float>(m_x, m_y, 0.0f),
    opengl_math::vector_3d<float>(0.0f, 1.0f, 0.0f));

  // Zoom out until frustum displays entire graph.
  while (ellipseOutsideFrustum()) {
    m_z = m_z + 0.1f;
    m_view = opengl_math::look_at<float, opengl_math::column>(
      opengl_math::point_3d<float>(m_x, m_y, static_cast<float>(m_z)),
      opengl_math::point_3d<float>(m_x, m_y, 0.0f),
      opengl_math::vector_3d<float>(0.0f, 1.0f, 0.0f));
  }
}

bool WarScrollRelationsGraph::ellipseOutsideFrustum() const
{
  bool insideFrustum = true;
  std::for_each(m_currEllipses.begin(), m_currEllipses.end(),
    [&](const Protection::Ellipse &ellipse)
    {
      insideFrustum &= (ellipse.insideFrustum(m_projection, m_view));
    });

  return !insideFrustum;
}

void WarScrollRelationsGraph::setGraph(WarScrollSynergyGraph *graph)
{
  std::lock_guard<std::mutex> lock(m_graphMutex);
  m_graph = graph;
  m_create = t;
}

void WarScrollRelationsGraph::warScrollSelected(int index)
{
  if (m_currScrollIndex == -1 && m_currScrollIndex == -1) {
    m_prevScrollIndex = index;
    m_currScrollIndex = index;
    m_scrollChanged = t;
  } else {
    m_prevScrollIndex = m_currScrollIndex.load();
    m_currScrollIndex = index;
    m_scrollChanged = t;
  }
}

void WarScrollRelationsGraph::resetIndices()
{
  m_prevScrollIndex = 0;
  m_currScrollIndex = 0;
  m_scrollChanged = f;
}

void WarScrollRelationsGraph::drawChanged(bool draw)
{
  // We only want to turn drawing off. The setting of a non empty graph
  // will handle turning drawing on.
  if (!draw) {
    m_draw = f;
  }
}

void WarScrollRelationsGraph::zChanged(qreal zDir)
{
  if (zDir < 0) {
    m_zoom = Zoom::In;
  } else if (zDir > 0) {
    m_zoom = Zoom::Out;
  }
}

void WarScrollRelationsGraph::focalPointChanged(const QVector2D &focalPoint)
{
  m_x = (m_x - static_cast<double>(focalPoint.x() / 100.0f));
  m_y = (m_y + static_cast<double>(focalPoint.y() / 100.0f));
}

namespace Detail
{
  template <typename T>
  opengl_math::vector_3d<T> get_camera_pos_no_scale(
    const opengl_math::matrix_4X4<T, opengl_math::column> &mv)
  {
    auto orientation = opengl_math::orientation_matrix(mv);
    auto d = opengl_math::vector_3d<float>(mv[3].x(), mv[3].y(), mv[3].z());

    auto ret = orientation * -d;
    return ret;
  }

  template <typename T>
  opengl_math::vector_3d<T> get_camera_pos(
    const opengl_math::matrix_4X4<T, opengl_math::column> &mv)
  {
    auto mvT = mv.transposed();

    auto n0 = opengl_math::vector3d_from_vector4d(mvT[0]);
    auto n1 = opengl_math::vector3d_from_vector4d(mvT[1]);
    auto n2 = opengl_math::vector3d_from_vector4d(mvT[2]);

    float d0(mvT[0].w());
    float d1(mvT[1].w());
    float d2(mvT[2].w());

    auto n1n2 = n1.cross(n2);
    auto n2n0 = n2.cross(n0);
    auto n0n1 = n0.cross(n1);

    auto top = (d0 * n1n2) + (d1 * n2n0) + (d2 * n0n1);
    float denom = n0.dot(n1n2);
    return -denom * top;
  }
}

void WarScrollRelationsGraph::doubleClickChanged(const QVector2D &point)
{
  float xndc = (2.0f * point.x()) / m_viewport.width() - 1.0f;
  float yndc = (1.0f - (2.0f * point.y()) / m_viewport.height());

  opengl_math::matrix_4X4<float, opengl_math::column> pvi =
    (m_projection * m_view).inversion();
  auto ndc = opengl_math::vector_4d<float>(xndc, yndc, 1.0f, 1.0f);
  auto world = pvi * ndc;

  m_pickVector = opengl_math::vector_3d<float>(
    opengl_math::vector3d_from_vector4d(world));
}

void WarScrollRelationsGraph::paint()
{
  if (m_initialize) {
    creatStaticData();
    m_initialize = f;
  }

  if (m_create) {
    initGraphData();
    m_create = f;
    // Why waist gpu and cpu cycles if not needed.
    if (std::distance(m_graph->begin(), m_graph->end()) == 0) {
      m_draw = f;
    } else {
      m_draw = t;
    }
  }

  if (m_scrollChanged) {
    updateGraph();
    m_scrollChanged = f;
  }

  if (m_draw) {
    renderGraph();
  }
}

void WarScrollRelationsGraph::renderGraph()
{
  if (m_zoom == Zoom::In) {
    m_z = m_z - 0.3;
    m_zoom = Zoom::None;
  } else if(m_zoom == Zoom::Out) {
    m_z = m_z + 0.3;
    m_zoom = Zoom::None;
  }

  // At this point the graph is right in front of our face.
  if (m_z < 1.5) {
    m_z = 1.5;
  }

  if (m_currEllipses.empty()) {
    return;
  }

  if (m_pickVector != opengl_math::vector_3d<float>(0.0f, 0.0f, 0.0f)) {

    auto c = Detail::get_camera_pos(m_view);
    auto r = m_pickVector;

    // Parametric equation for line:
    // x = c.x() + r.x() * t;
    // y = c.y() + r.y() * t;
    // z = c.z() + r.z() * t;

    // We know the plane is of the form
    // A * x + B * y + C * z = D;
    // We substitute and get:
    // A * (c.x + r.x * t) + B * (c.y + r.y * t) + C * (c.z + r.z * t) = D
    // Since our plane is always parallel with the xy-plane we cane reduce to
    // D = C * (c.z + r.z * t)
    // Simplifying we get
    // t = (D / (C * r.z)) - (c.z / r.z);

    if (r.z() != 0.0) {
      float D = m_currEllipses[0].getCenter().z();
      float C = opengl_math::plane_3d<float>(0.0f, 0.0f, 1.0f, D).c();
      float t = (D / (C * r.z())) - (c.z() / r.z());

      float x = c.x() + r.x() * t;
      float y = c.y() + r.y() * t;
      float z = c.z() + r.z() * t;
      auto pos3 = opengl_math::point_3d<float>(x, y, z);

      if (m_doubleClickedEllipse.load() != nullptr) {
        m_doubleClickedEllipse.load()->setUnifromColor(
          opengl_math::color_rgba<float>(1.0f, 1.0f, 1.0f, 1.0f));
      }

      m_doubleClickedEllipse = nullptr;

      for (auto &ellipse : m_currEllipses) {
        if (ellipse.contains(pos3)) {
          m_doubleClickedEllipse = &ellipse;
          break;
        }
      }
      if (m_doubleClickedEllipse.load() != nullptr) {
        m_doubleClickedEllipse.load()->setUnifromColor(
          opengl_math::color_rgba<float>(1.0f, 0.0f, 0.0f, 1.0f));
          connect(&m_doubleClickedTimer, &QTimer::timeout, [&]() {
            if (m_doubleClickedEllipse.load() != nullptr) {
              m_doubleClickedEllipse.load()->setUnifromColor(
                opengl_math::color_rgba<float>(1.0f, 1.0f, 1.0f, 1.0f));
              int currIndex(0);
              bool found = false;
              for (std::shared_ptr<Protection::Ellipse> ellipse : m_ellipses) {
                if (m_doubleClickedEllipse.load()->getWarScroll().getGuid()
                  == ellipse->getWarScroll().getGuid()) {
                  found = true;
                  break;
                }
                ++currIndex;
              }
              if (currIndex != m_currScrollIndex.load() && found) {
                QMetaObject::invokeMethod(RootView::getRootView()->rootObject(),
                  "setCurrentGraphIndex",
                  Q_ARG(QVariant, QVariant::fromValue(currIndex)));
              }
            }
            m_doubleClickedEllipse = nullptr;
          });
          // milli seconds
          m_doubleClickedTimer.setSingleShot(true);
          m_doubleClickedTimer.start(500);
      }
    }

    m_pickVector = opengl_math::vector_3d<float>();
  }

  m_view = opengl_math::look_at<float, opengl_math::column>(
    opengl_math::point_3d<float>(m_x, m_y, static_cast<float>(m_z)),
    opengl_math::point_3d<float>(m_x, m_y, 0.0f),
    opengl_math::vector_3d<float>(0.0f, 1.0f, 0.0f));

  auto pv = (m_projection * m_view);

  float llx = m_viewport.r_ll().x();
  float lly = m_viewport.r_ll().y();
  float w = m_viewport.width();
  float h = m_viewport.height();
  glViewport(llx, lly, w, h);
  glDisable(GL_DEPTH_TEST);
  glEnable (GL_BLEND);
  glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

  for (auto spline : m_currSplines) {
    spline->setMVPMatrix(pv * spline->getTransform());
    spline->draw();
  }

  for (auto ellipse : m_currEllipses) {
    ellipse.setMVPMatrix(pv * ellipse.getTransform());
    ellipse.draw();
  }

  for (auto label : m_currEdgeLabels) {
    label->setMVPMatrix(pv * label->getTransform());
    label->draw();
  }
}
