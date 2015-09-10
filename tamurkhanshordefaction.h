#ifndef TAMURKHANS_HORDE_FACTION_H
#define TAMURKHANS_HORDE_FACTION_H

#include "ifaction.h"

class TamurkhansHordeFaction : public IFaction
{
public:
  TamurkhansHordeFaction();

  virtual std::string getName() const override {return "Tamurkahan's Horde";}
  virtual const std::vector<std::string> &getUnits() const override;
  virtual void getWarScrolls(std::list<WarScroll> &warScrolls) override;

private:
  std::vector<std::string> m_Units;
  typedef std::map<std::string, WarScrollGenerator> WarScrollGeneratorType;
  WarScrollGeneratorType m_NameToWarScroll;
};

#endif // TAMURKHANS_HORDE_FACTION_H
