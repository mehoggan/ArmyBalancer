#ifndef IFACTION_H
#define IFACTION_H

#include <QObject>

#include <list>
#include <QQuickView>

#include <functional>
#include <memory>
#include <string>
#include <vector>

#include "warscroll.h"
#include "warscrollfactory.h"

class IFaction :
  public QObject
{
  Q_OBJECT
protected:
  typedef std::function<WarScroll(std::string)> WarScrollGenerator;

public:
  explicit IFaction(QObject *parent = 0)
    : QObject(parent)
  {}

  virtual ~IFaction()
  {}

  virtual std::string getName() const = 0;
  virtual const std::vector<std::string> &getUnits() const = 0;
  virtual void getWarScrolls(std::list<WarScroll> &warScrolls) = 0;
};

#endif // IFACTION_H
