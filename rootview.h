#ifndef ROOTVIEW_H
#define ROOTVIEW_H

#include <QQuickView>

#include <atomic>

class RootView
{
private:
  static std::atomic<QQuickView*> s_rootView;

public:
  static void setRootView(QQuickView *rootView);
  static QQuickView *getRootView();
};

#endif // ROOTVIEW_H
