﻿#ifndef WARSCROLLRELATIONSGRAPH_H
#define WARSCROLLRELATIONSGRAPH_H

#include <QObject>
#include <QtGui/QOpenGLFunctions>

#include "warscrollsynergygraph.h"

#include "core/platform.h"
#include "geometries/geometry.h"
#include "geometries/splines.h"
#include "primitives/points/type_point_3d.h"

#include <array>
#include <atomic>
#include <memory>
#include <mutex>

class WarScrollRelationsGraph :
  public QObject, public QOpenGLFunctions
{
  Q_OBJECT

private:
  std::atomic_bool m_draw;
  std::atomic_bool m_create;
  std::atomic_bool m_initialize;
  QSize m_viewportSize;

  std::mutex m_graphMutex;
  WarScrollSynergyGraph *m_graph;

  std::array<std::shared_ptr<Spline>, 1> m_splines;

private:
  void renderBackground();
  void renderGraph();
  void creatStaticData();
  void createGraph();

public:
  WarScrollRelationsGraph();
  ~WarScrollRelationsGraph();

  void setViewportSize(const QSize &size);
  void setDraw(bool draw) {m_draw = draw;}
  void setGraph(WarScrollSynergyGraph &graph);

public slots:
  void paint();
};

#endif // WARSCROLLRELATIONSGRAPH_H
