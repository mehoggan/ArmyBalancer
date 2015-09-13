﻿#include "warscrollrelationsgraphscene.h"

WarScrollRelationsGraphScene::WarScrollRelationsGraphScene() :
  m_t(0),
  m_renderer(nullptr)
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

void WarScrollRelationsGraphScene::sync()
{
  if (!m_renderer) {
    m_renderer = new WarScrollRelationsGraph();
    connect(window(), SIGNAL(beforeRendering()), m_renderer, SLOT(paint()),
      Qt::DirectConnection);
  }
  m_renderer->setViewportSize(window()->size() * window()->devicePixelRatio());
  m_renderer->setT(m_t);
}
