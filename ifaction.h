#ifndef IFACTION_H
#define IFACTION_H

#include <list>

#include <functional>
#include <memory>
#include <string>
#include <vector>

#include "warscroll.h"
#include "warscrollfactory.h"

class IFaction
{
public:
  static const int s_MaxUnitSize = 500;

protected:
  typedef std::function<WarScroll(std::string)> WarScrollGenerator;

public:
  IFaction()
  {}

  virtual ~IFaction()
  {}

  virtual std::string getName() const = 0;
  virtual const std::vector<std::string> &getUnits() const = 0;
  virtual void getWarScrolls(std::list<WarScroll> &warScrolls) = 0;
};

#endif // IFACTION_H
