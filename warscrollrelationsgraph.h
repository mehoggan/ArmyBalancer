#ifndef WARSCROLLRELATIONSGRAPH_H
#define WARSCROLLRELATIONSGRAPH_H

#include <QObject>
#include <QtGui/QOpenGLShaderProgram>
#include <QtGui/QOpenGLFunctions>

#include "warscrollsynergygraph.h"

#include <atomic>
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
  qreal m_t;
  QOpenGLShaderProgram *m_program;

  std::mutex m_graphMutex;
  WarScrollSynergyGraph *m_graph;

private:
  void renderBackground();
  void renderGraph();
  void creatStaticData();
  void createGraph();

public:
  WarScrollRelationsGraph();
  ~WarScrollRelationsGraph();

  void setT(qreal t) {m_t = t;}
  void setViewportSize(const QSize &size) {m_viewportSize = size;}
  void setDraw(bool draw) {m_draw = draw;}
  void setGraph(WarScrollSynergyGraph &graph);

public slots:
  void paint();
};

#endif // WARSCROLLRELATIONSGRAPH_H
