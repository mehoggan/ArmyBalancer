#include "rootview.h"

std::atomic<QQuickView*> RootView::s_rootView;

void RootView::setRootView(QQuickView *rootView)
{
  s_rootView = rootView;
}

QQuickView *RootView::getRootView()
{
  return s_rootView;
}
