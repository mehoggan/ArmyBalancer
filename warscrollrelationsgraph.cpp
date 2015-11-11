#include "warscrollrelationsgraph.h"

#include "geometries/collision.h"
#include "geometries/ellipse.h"

#include "math/matrix.h"

#include <QDebug>
#include <QPainter>
#include <QDebug>
#include <QGLWidget>

#include <iostream>

#if __OPENGL_CORE_WINDOWS__
const std::atomic_bool t{true};
const std::atomic_bool f{false};
#else
const bool t = true;
const bool f = false;
#endif

namespace Detail
{
  void drawText(QPainter & painter, qreal x, qreal y, Qt::Alignment flags,
    const QString & text, qreal fontSize, QRectF * boundingRect = 0)
  {
    const qreal size = 32767.0;
    QPointF corner(x, y - size);
    if (flags & Qt::AlignHCenter) {
      corner.rx() -= size/2.0;
    } else if (flags & Qt::AlignRight) {
      corner.rx() -= size;
    }

    if (flags & Qt::AlignVCenter) {
      corner.ry() += size/2.0;
    } else if (flags & Qt::AlignTop) {
      corner.ry() += size;
    } else {
      flags |= Qt::AlignBottom;
    }

    QRectF rect(corner, QSizeF(size, size));

    QFont font = painter.font() ;
    font.setPointSize(fontSize);
    painter.setFont(font);

    painter.drawText(rect, flags, text, boundingRect);
  }

  void drawText(QPainter & painter, const QPointF & point, Qt::Alignment flags,
    const QString & text, qreal fontSize, QRectF * boundingRect = 0)
  {
    drawText(painter, point.x(), point.y(), flags, text, fontSize,
      boundingRect);
  }
}

WarScrollRelationsGraph::WarScrollRelationsGraph()
  : m_projection(opengl_math::identity)
  , m_view(opengl_math::identity)
  , m_z(10.0f)
  , m_zoom(Zoom::None)
  , m_y(0.0)
  , m_x(0.0)
{
  m_draw = f;
  m_create = f;
  m_initialize = t;

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

void WarScrollRelationsGraph::setViewportSize(const QSize &size)
{
  m_viewportSize = size;
  float den = (m_viewportSize.height() == 0) ? 1.0f :
    static_cast<float>(m_viewportSize.height());
  float num = static_cast<float>(m_viewportSize.width());
  m_projection = opengl_math::perspective<float, opengl_math::column>(
    45.0f, num / den, 1.0, 100.0, opengl_math::degrees);
}

void WarScrollRelationsGraph::creatStaticData()
{
  initializeOpenGLFunctions();
}

void WarScrollRelationsGraph::createGraph()
{
  m_ellipses.clear();

  // Constructs an ellipse for each Vertex in the SynergyGraph. This does not
  // handle layout of the graph (aka transformations).
  std::for_each(m_graph->begin(), m_graph->end(),
    [&](const WarScrollSynergyGraph::Vertex &node)
  {
    std::shared_ptr<Ellipse> ellipse(new Ellipse());
    m_ellipses.push_back(ellipse);
    QImage img(512, 512, QImage::Format_RGBA8888);
    img.fill(Qt::white);
    QPainter painter(&img);
    painter.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing |
      QPainter::SmoothPixmapTransform);
    QRadialGradient radialGrad(QPointF(img.width() / 2.0f, img.height() / 2.0f),
      100);
    radialGrad.setColorAt(0.00, QColor(255, 215, 0, 150));
    radialGrad.setColorAt(0.95, QColor(150, 0, 0, 150));
    radialGrad.setColorAt(1.00, QColor(0, 0, 150, 150));
    painter.fillRect(0, 0, img.width(), img.height(), radialGrad);
    Detail::drawText(painter,
      QPointF(img.width() / 2.0f, img.height() / 2.0f),
      Qt::AlignHCenter | Qt::AlignVCenter,
      node.getWarScroll()->getTitle().c_str(), 36.0);
    QImage tex = QGLWidget::convertToGLFormat(img);
    m_ellipses.back()->setNameTexture(tex);

    m_ellipses.back()->create();
  });

  // Rough draft spread all ellipses out such that non collide
  if (m_ellipses.size() > 1) {
    for (auto it = m_ellipses.begin(); it < m_ellipses.end() - 1; ++it) {
      if (Collision::collide(**it, **(it + 1))) {
        std::cout << "Collision" << std::endl;
      }
    }
  }
}

void WarScrollRelationsGraph::setGraph(WarScrollSynergyGraph *graph)
{
  std::lock_guard<std::mutex> lock(m_graphMutex);
  m_graph = graph;
  m_create = t;
}

void WarScrollRelationsGraph::drawChanged(bool draw)
{
  // We only want to turn drawing off. The setting of a non empty graph
  // will handle turning drawing on.
  if (!draw) {
    std::cout << "Drawing OFF" << std::endl;
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

void WarScrollRelationsGraph::paint()
{
  if (m_initialize) {
    creatStaticData();
    m_initialize = f;
  }

  if (m_create) {
    createGraph();
    m_create = f;
    // Why waist gpu and cpu cycles if not needed.
    if (std::distance(m_graph->begin(), m_graph->end()) == 0) {
      m_draw = f;
    } else {
      m_draw = t;
    }
  }

  if (m_draw) {
    renderGraph();
  }
}

void WarScrollRelationsGraph::renderGraph()
{
  if (m_zoom == Zoom::In) {
    m_z = m_z - 0.1;
    m_zoom = Zoom::None;
  } else if(m_zoom == Zoom::Out) {
    m_z = m_z + 0.1;
    m_zoom = Zoom::None;
  }

  // At this point the graph is right infrot of our face.
  if (m_z < 1.5) {
    m_z = 1.5;
  }

  m_view = opengl_math::look_at<float, opengl_math::column>(
    opengl_math::point_3d<float>(m_x, m_y, static_cast<float>(m_z)),
    opengl_math::point_3d<float>(m_x, m_y, 0.0f),
    opengl_math::vector_3d<float>(0.0f, 1.0f, 0.0f));

  auto mv = (m_projection * m_view);

  qreal width = m_viewportSize.width();
  qreal height = m_viewportSize.height();
  glViewport(0, 0.1125 * height, width, height);
  glDisable(GL_DEPTH_TEST);

  for (auto ellipse : m_ellipses) {
    if (ellipse) {
      ellipse->setMVPMatrix(mv * ellipse->getTransform());
      ellipse->draw();
    }
  }
}
