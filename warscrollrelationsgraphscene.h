#ifndef WARSCROLLRELATIONSGRAPHSCENE_H
#define WARSCROLLRELATIONSGRAPHSCENE_H

#include <QQuickItem>
#include <QQuickWindow>

#include "warscrollrelationsgraph.h"

class WarScrollRelationsGraphScene : public QQuickItem
{
    Q_OBJECT
    Q_PROPERTY(qreal t READ getT WRITE setT NOTIFY tChanged)

public:
    WarScrollRelationsGraphScene();

    qreal getT() const {return m_t;}
    void setT(qreal t);

signals:
  void tChanged();

public slots:
  void sync();
  void cleanup();

private slots:
  void handleWindowChanged(QQuickWindow *win);

private:
  qreal m_t;
  WarScrollRelationsGraph *m_renderer;
};

#endif // WARSCROLLRELATIONSGRAPHSCENE_H
