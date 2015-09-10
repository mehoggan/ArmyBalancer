#ifndef NURGLE_ROTBRINGERS_FACTION_H
#define NURGLE_ROTBRINGERS_FACTION_H

#include "ifaction.h"

class NurgleRotbringersFaction : public IFaction
{
public:
  NurgleRotbringersFaction();

  virtual std::string getName() const override {return "Nurgle Rotbringers";}
  virtual const std::vector<std::string> &getUnits() const override;
  virtual void getWarScrolls(std::list<WarScroll> &warScrolls) override;

private:
  std::vector<std::string> m_Units;
  typedef std::map<std::string, WarScrollGenerator> WarScrollGeneratorType;
  WarScrollGeneratorType m_NameToWarScroll;
};

#endif // NURGLE_ROTBRINGERS_FACTION_H
