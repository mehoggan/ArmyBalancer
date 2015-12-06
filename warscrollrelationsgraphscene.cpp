#include "warscrollrelationsgraphscene.h"

#include <QQmlContext>
#include <QQmlEngine>

WarScrollRelationsGraphScene::WarScrollRelationsGraphScene(QObject *)
  : m_t(0)
  , m_renderer(nullptr)
{
  connect(this, SIGNAL(windowChanged(QQuickWindow*)),
    this, SLOT(handleWindowChanged(QQuickWindow*)));
}

void WarScrollRelationsGraphScene::setT(qreal t)
{
  if (t == m_t) {
    return;
  }

  m_t = t;
  emit tChanged();
  if (window()) {
    window()->update();
  }
}

void WarScrollRelationsGraphScene::setDraw(bool draw)
{
  if (draw == m_draw) {
    return;
  }

  m_draw = draw;
  emit drawChanged(m_draw);
}

void WarScrollRelationsGraphScene::setZ(qreal z)
{
  m_z = z;
  emit zChanged(m_z);
}

void WarScrollRelationsGraphScene::setFocalPoint(const QVector2D &focalPoint)
{
  if (focalPoint == m_focalPoint) {
    return;
  }

  m_focalPoint = focalPoint;
  emit focalPointChanged(m_focalPoint);
}

void WarScrollRelationsGraphScene::setWarScrollSynergyGraph(
  WarScrollSynergyGraph *graph)
{
  if (m_renderer) {
    m_renderer->setGraph(graph);
  }
}

void WarScrollRelationsGraphScene::handleWindowChanged(QQuickWindow *win)
{
  if (win) {
    connect(win, SIGNAL(beforeSynchronizing()), this, SLOT(sync()),
      Qt::DirectConnection);
    connect(win, SIGNAL(sceneGraphInvalidated()), this, SLOT(cleanup()),
      Qt::DirectConnection);
    win->setClearBeforeRendering(false);
  }
}

void WarScrollRelationsGraphScene::cleanup()
{
  if (m_renderer) {
    delete m_renderer;
    m_renderer = 0;
  }
}

void WarScrollRelationsGraphScene::warScrollSelected(int index)
{
  if (m_renderer) {
    m_renderer->warScrollSelected(index);
  }
}

void WarScrollRelationsGraphScene::sync()
{
  if (!m_renderer) {
    m_renderer = new WarScrollRelationsGraph();
    connect(window(), SIGNAL(afterRendering()), m_renderer, SLOT(paint()),
      Qt::DirectConnection);
    connect(this, SIGNAL(drawChanged(bool)), m_renderer,
      SLOT(drawChanged(bool)));
    connect(this, SIGNAL(zChanged(qreal)), m_renderer,
      SLOT(zChanged(qreal)));
    connect(this, SIGNAL(focalPointChanged(QVector2D)), m_renderer,
      SLOT(focalPointChanged(QVector2D)));
  }
  m_renderer->setViewportSize(QSize(width(), height())
    * window()->devicePixelRatio());
}

