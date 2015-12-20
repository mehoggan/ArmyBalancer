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
  Q_PROPERTY(qreal z READ getZ WRITE setZ NOTIFY zChanged)
  Q_PROPERTY(QVector2D focalPoint READ getFocalPoint WRITE setFocalPoint
    NOTIFY focalPointChanged)
  Q_PROPERTY(QVector2D doubleClick READ getDoubleClick WRITE setDoubleClick
    NOTIFY doubleClickChanged)

public:
  WarScrollRelationsGraphScene(QObject *parent = nullptr);

  qreal getT() const {return m_t;}
  void setT(qreal t);

  bool getDraw() const {return m_draw;}
  void setDraw(bool draw);

  qreal getZ() const {return m_z;}
  void setZ(qreal z);

  QVector2D getFocalPoint() const {return m_focalPoint;}
  void setFocalPoint(const QVector2D &focalPoint);

  QVector2D getDoubleClick() const {return m_doubleClick;}
  void setDoubleClick(const QVector2D &doubleClick);

  void setWarScrollSynergyGraph(WarScrollSynergyGraph *graph);

signals:
  void tChanged();
  void drawChanged(bool);
  void zChanged(qreal);
  void focalPointChanged(const QVector2D &);
  void doubleClickChanged(const QVector2D &);

public slots:
  void sync();
  void cleanup();
  void warScrollSelected(int index);
  void resetIndices();

private slots:
  void handleWindowChanged(QQuickWindow *win);

private:
  qreal m_t;
  bool m_draw;
  qreal m_z;
  QVector2D m_focalPoint;
  QVector2D m_doubleClick;
  WarScrollRelationsGraph *m_renderer;
  QQuickWindow *m_win;
};

#endif // WARSCROLLRELATIONSGRAPHSCENE_H
