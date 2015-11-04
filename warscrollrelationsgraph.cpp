#include "warscrollrelationsgraph.h"

#include "geometries/ellipse.h"

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

  std::size_t index = 0;
  for (auto ellipse : m_ellipses) {
    ellipse.reset();
    m_ellipses[index].reset(new Ellipse());
    m_ellipses[index]->create();
    m_ellipses[index]->setTransform(opengl_math::scale_by(
      m_ellipses[index]->getTransform(), 2.5f, 2.0f, 0.0f));
    ++index;
  }
}

void WarScrollRelationsGraph::createGraph()
{
}

void WarScrollRelationsGraph::setGraph(WarScrollSynergyGraph *graph)
{
  std::lock_guard<std::mutex> lock(m_graphMutex);
  m_graph = graph;
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

  for (auto ellipse : m_ellipses) {
    if (ellipse) {
      ellipse->setMVPMatrix(mv * ellipse->getTransform());
      ellipse->draw();
    }
  }
}
