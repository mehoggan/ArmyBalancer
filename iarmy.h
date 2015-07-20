#ifndef IARMY_H
#define IARMY_H

#include <QObject>
#include <QQuickView>
#include <QStringList>

class IArmy :
  public QObject
{
  Q_OBJECT

public:
  explicit IArmy(QObject *parent = 0)
    : QObject(parent)
  {}

  virtual ~IArmy()
  {}

  virtual const QStringList &getUnits() = 0;
  virtual void buildUiForBattleScroll(QQuickView *ui, int scrollIndex) = 0;
};

#endif // IARMY_H
