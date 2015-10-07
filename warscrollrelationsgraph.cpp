#include "warscrollrelationsgraph.h"

#include "geometries/nonprojectedblinkinguniformredtriangle.h"
#include "geometries/nonprojectedwhitetriangle.h"

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

  for (auto *geometry : m_geometries) {
    geometry = nullptr;
    (void)geometry;
  }
}

WarScrollRelationsGraph::~WarScrollRelationsGraph()
{
  m_initialize = f;
  m_draw = f;
  m_create = f;

  for (auto *geometry : m_geometries) {
    if (geometry) {
      delete geometry;
      geometry = nullptr;
    }
  }
}

void WarScrollRelationsGraph::setViewportSize(const QSize &size)
{
  m_viewportSize = size;
}

void WarScrollRelationsGraph::creatStaticData()
{
  initializeOpenGLFunctions();

  for (auto *geometry : m_geometries) {
    if (geometry) {
      delete geometry;
      geometry = nullptr;
    }
  }

  m_geometries[0] = new NonProjectedWhiteTriangle();
  m_geometries[0]->create();

  m_geometries[1] = new NonProjectedBlinkingUniformRedTriangle();
  m_geometries[1]->create();
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

  for (auto *geometry : m_geometries) {
    if (geometry) {
      geometry->draw();
    }
  }
}
