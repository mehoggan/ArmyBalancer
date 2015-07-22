#include <QApplication>
#include <QQuickView>
#include <QQuickItem>
#include <QtQml>
#include <QObject>

#include "armybalancer.h"

int main(int argc, char *argv[])
{
  QApplication app(argc, argv);

  qmlRegisterType<ArmyBalancer>("ArmyBalancer", 1, 0, "ArmyBalancer");

  QQuickView * quickView = new QQuickView;
#ifdef Q_OS_ANDROID
  quickView->setSource(QUrl(QStringLiteral("qrc:/ArmyBalancerAndroid.qml")));
#else
  quickView->setSource(QUrl(QStringLiteral("qrc:/ArmyBalancer.qml")));
  quickView->setMinimumSize(QSize(350, 450));
#endif

  QObject *root = quickView->rootObject();
  QQuickItem *item = qobject_cast<QQuickItem *>(root);
  ArmyBalancer *armyBalancer = item->findChild<ArmyBalancer *>("armyBalancer");

  quickView->setResizeMode(QQuickView::SizeRootObjectToView);
  quickView->show();
  armyBalancer->setRootView(quickView);

  return app.exec();
}
