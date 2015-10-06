#ifndef WARSCROLLRELATIONSGRAPH_H
#define WARSCROLLRELATIONSGRAPH_H

#include <QObject>
#include <QtGui/QOpenGLFunctions>
#include <QMatrix4x4>

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

  std::mutex m_graphMutex;
  WarScrollSynergyGraph *m_graph;

  GLuint m_shaderProgram;
  GLuint m_vertexShader;
  GLuint m_fragmentShader;
  GLuint m_vbo;

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
