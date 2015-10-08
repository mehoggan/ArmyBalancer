#ifndef WOODELVES_H
#define WOODELVES_H

#include "ifaction.h"

class WoodElvesFaction : public IFaction
{
public:
  WoodElvesFaction();

  virtual std::string getName() const override {return "Wood Elves";}
  virtual const std::vector<std::string> &getUnits() const override;
  virtual void getWarScrolls(std::list<WarScroll> &warScrolls) override;

private:
  std::vector<std::string> m_Units;
  typedef std::map<std::string, WarScrollGenerator> WarScrollGeneratorType;
  WarScrollGeneratorType m_NameToWarScroll;
};

#endif // WOODELVES_H
