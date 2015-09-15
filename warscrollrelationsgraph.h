#ifndef WARSCROLLRELATIONSGRAPH_H
#define WARSCROLLRELATIONSGRAPH_H

#include <QObject>
#include <QtGui/QOpenGLShaderProgram>
#include <QtGui/QOpenGLFunctions>

#include <atomic>

class WarScrollRelationsGraph :
  public QObject, public QOpenGLFunctions
{
  Q_OBJECT
public:
  WarScrollRelationsGraph();
  ~WarScrollRelationsGraph();

  void setT(qreal t) {m_t = t;}
  void setViewportSize(const QSize &size) {m_viewportSize = size;}
  void setDraw(bool draw) {m_draw = draw;}

public slots:
  void paint();

private:
  std::atomic_bool m_draw;
  QSize m_viewportSize;
  qreal m_t;
  QOpenGLShaderProgram *m_program;
};

#endif // WARSCROLLRELATIONSGRAPH_H
