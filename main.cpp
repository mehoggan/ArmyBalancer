#include <QApplication>
#include <QQuickView>
#include <QQuickItem>
#include <QtQml>
#include <QObject>

#include "armybalancer.h"
#include "warscrollrelationsgraphscene.h"

int main(int argc, char *argv[])
{
  QApplication app(argc, argv);

  qmlRegisterType<ArmyBalancer>("ArmyBalancer", 1, 0, "ArmyBalancer");
  qmlRegisterType<WarScrollRelationsGraphScene>("WarScrollRelationsGraphScene",
    1, 0, "WarScrollRelationsGraphScene");

  QQuickView * quickView = new QQuickView;
  quickView->setSource(QUrl("qrc:/ArmyBalancer.qml"));
  quickView->setMinimumSize(QSize(500, 800));

  QObject *root = quickView->rootObject();
  QQuickItem *item = qobject_cast<QQuickItem *>(root);
  ArmyBalancer *armyBalancer = item->findChild<ArmyBalancer *>("armyBalancer");

  quickView->setResizeMode(QQuickView::SizeRootObjectToView);
  quickView->show();
  armyBalancer->setRootView(quickView);

  return app.exec();
}
