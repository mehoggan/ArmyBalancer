#ifndef HIGHELVES_H
#define HIGHELVES_H

#include "ifaction.h"

class HighElvesFaction : public IFaction
{
public:
  HighElvesFaction();

  virtual std::string getName() const override {return "High Elves";}
  virtual const std::vector<std::string> &getUnits() const override;
  virtual void getWarScrolls(std::list<WarScroll> &warScrolls) override;

private:
  std::vector<std::string> m_Units;
  typedef std::map<std::string, WarScrollGenerator> WarScrollGeneratorType;
  WarScrollGeneratorType m_NameToWarScroll;
};

#endif // HIGHELVES_H
