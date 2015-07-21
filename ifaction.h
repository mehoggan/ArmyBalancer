#ifndef IARMY_H
#define IARMY_H

#include <QObject>
#include <QQuickView>
#include <QStringList>

#include "warscrollfactory.h"

class IFaction :
  public QObject
{
  Q_OBJECT

public:
  explicit IFaction(QObject *parent = 0)
    : QObject(parent)
  {}

  virtual ~IFaction()
  {}

  virtual QString getName() const = 0;
  virtual const QStringList &getUnits() = 0;
  virtual void buildUiForBattleScroll(QQuickView * /*ui*/, int scrollIndex) = 0;
};

#endif // IARMY_H
