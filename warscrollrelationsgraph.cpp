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
{
  m_draw = f;
  m_create = f;
  m_initialize = t;

  for (auto spline : m_splines) {
    spline = nullptr;
    (void)spline;
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
}

void WarScrollRelationsGraph::setViewportSize(const QSize &size)
{
  m_viewportSize = size;
  for (auto spline : m_splines) {
    if (spline) {
      float den = (m_viewportSize.height() == 0) ? 1.0f :
        static_cast<float>(m_viewportSize.height());
      float num = static_cast<float>(m_viewportSize.width());
      spline->setProjection(
        opengl_math::perspective<float, opengl_math::column>(
          45.0f, num / den, 1.0, 100.0, opengl_math::degrees));
    }
  }
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
  } else {
    int x = 0; x = x;
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

  for (auto spline : m_splines) {
    if (spline) {
      spline->draw();
    }
  }
}
