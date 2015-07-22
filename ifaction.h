#ifndef IFACTION_H
#define IFACTION_H

#include <QObject>

#include <QList>
#include <QQuickView>
#include <QStringList>

#include <functional>
#include <memory>

#include "warscroll.h"
#include "warscrollfactory.h"

class IFaction :
  public QObject
{
  Q_OBJECT
protected:
  typedef std::function<WarScroll()> WarScrollGenerator;

public:
  explicit IFaction(QObject *parent = 0)
    : QObject(parent)
  {}

  virtual ~IFaction()
  {}

  virtual QString getName() const = 0;
  virtual const QStringList &getUnits() const = 0;
  virtual QList<WarScroll> getWarScrolls() const = 0;
};

#endif // IFACTION_H
