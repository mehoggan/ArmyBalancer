#ifndef DARKELVES_H
#define DARKELVES_H

#include "ifaction.h"

class DarkElvesFaction : public IFaction
{
public:
  DarkElvesFaction();

  virtual std::string getName() const override {return "Dark Elves";}
  virtual const std::vector<std::string> &getUnits() const override;
  virtual void getWarScrolls(std::list<WarScroll> &warScrolls) override;

private:
  std::vector<std::string> m_Units;
  typedef std::map<std::string, WarScrollGenerator> WarScrollGeneratorType;
  WarScrollGeneratorType m_NameToWarScroll;
};

#endif // DARKELVES_H
