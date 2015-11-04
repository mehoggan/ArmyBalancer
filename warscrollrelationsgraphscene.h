#ifndef WARSCROLLRELATIONSGRAPHSCENE_H
#define WARSCROLLRELATIONSGRAPHSCENE_H

#include <QQuickItem>
#include <QQuickWindow>

#include "warscrollrelationsgraph.h"

class WarScrollSynergyGraph;

class WarScrollRelationsGraphScene : public QQuickItem
{
  Q_OBJECT
  Q_PROPERTY(qreal t READ getT WRITE setT NOTIFY tChanged)
  Q_PROPERTY(bool draw READ getDraw WRITE setDraw NOTIFY drawChanged)

public:
  WarScrollRelationsGraphScene(QObject *parent = nullptr);

  qreal getT() const {return m_t;}
  void setT(qreal t);

  bool getDraw() const {return m_draw;}
  void setDraw(bool draw);

  void setWarScrollSynergyGraph(WarScrollSynergyGraph *graph);

signals:
  void tChanged();
  void drawChanged();

public slots:
  void sync();
  void cleanup();

private slots:
  void handleWindowChanged(QQuickWindow *win);

private:
  qreal m_t;
  bool m_draw;
  WarScrollRelationsGraph *m_renderer;
};

#endif // WARSCROLLRELATIONSGRAPHSCENE_H
