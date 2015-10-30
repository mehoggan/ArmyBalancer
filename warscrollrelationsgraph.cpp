#include "warscrollrelationsgraph.h"

#include "geometries/projectedrainbow2texturedsquare.h"
#include "math/matrix.h"

#include <QDebug>

#include <iostream>

#if __OPENGL_CORE_WINDOWS__
const std::atomic_bool t{true};
const std::atomic_bool f{false};
#else
const bool t = true;
const bool f = false;
#endif

WarScrollRelationsGraph::WarScrollRelationsGraph()
  : m_projection(opengl_math::identity)
  , m_view(opengl_math::identity)
{
  m_draw = f;
  m_create = f;
  m_initialize = t;

  for (auto spline : m_splines) {
    spline = nullptr;
    (void)spline;
  }

  for (auto square : m_squares) {
    square = nullptr;
    (void)square;
  }
}

WarScrollRelationsGraph::~WarScrollRelationsGraph()
{
  m_initialize = f;
  m_draw = f;
  m_create = f;

  for (auto spline : m_splines) {
    if (spline) {
      spline.reset();
    }
  }

  for (auto square : m_squares) {
    if (square) {
      square.reset();
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

  for (auto spline : m_splines) {
    if (spline) {
      spline.reset();
    }
  }

  opengl_math::point_3d<float> p0(+0.00f, +0.00f, +0.00f);
  opengl_math::point_3d<float> p1(-2.00f, +1.00f, +0.00f);
  opengl_math::point_3d<float> p2(+2.00f, +3.00f, +0.00f);
  opengl_math::point_3d<float> p3(+2.50f, +5.67f, +0.00f);
  m_splines[0] = Spline::createBezier(p0, p1, p2, p3);
  m_splines[0]->create();
  m_splines[0]->setDisplayColor(opengl_math::color_rgba<float>(
    0.0f, 0.0f, 0.0f, 1.0f));
  m_splines[0]->setLineWidth(1.0f);

  std::size_t index = 0;
  for (auto square : m_squares) {
    square.reset();
    m_squares[index].reset(new ProjectedRainbow2TexturedSquare());
    m_squares[index]->create();
    float one = (float)((std::rand() % 5) - (std::rand() % 10));
    float two = (float)((std::rand() % 5) - (std::rand() % 10));
    m_squares[index]->setTransform(opengl_math::translate_to(
      m_squares[index]->getTransform(),
      opengl_math::point_3d<float>(one, two, 0.0f)));
    ++index;
  }
}

void WarScrollRelationsGraph::createGraph()
{
}

void WarScrollRelationsGraph::setGraph(WarScrollSynergyGraph &graph)
{
  std::lock_guard<std::mutex> lock(m_graphMutex);
  m_graph = &graph;
  m_create = t;
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
  }

  if (m_draw) {
    renderGraph();
  }
}

void WarScrollRelationsGraph::renderGraph()
{
  qreal width = m_viewportSize.width();
  qreal height = m_viewportSize.height();
  glViewport(0, 0.1125 * height, width, height);
  glDisable(GL_DEPTH_TEST);

  m_view = opengl_math::look_at<float, opengl_math::column>(
    opengl_math::point_3d<float>(0.0f, 0.0f, 20.0f),
    opengl_math::point_3d<float>(0.0f, 0.0f, 0.0f),
    opengl_math::vector_3d<float>(0.0f, 1.0f, 0.0f));

  auto mv = (m_projection * m_view);

  for (auto square : m_squares) {
    if (square) {
      square->setMVPMatrix(mv * square->getTransform());
      square->draw();
    }
  }

  for (auto spline : m_splines) {
    if (spline) {
      spline->setMVPMatrix(mv * spline->getTransform());
      spline->draw();
    }
  }
}
