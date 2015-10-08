#ifndef STORMCAST_ETERNALS_FACTION_H
#define STORMCAST_ETERNALS_FACTION_H

#include "ifaction.h"

class StormCastEternalsFaction : public IFaction
{
public:
  StormCastEternalsFaction();

  virtual std::string getName() const override {return "Stormcast Eternals";}
  virtual const std::vector<std::string> &getUnits() const override;
  virtual void getWarScrolls(std::list<WarScroll> &warScrolls) override;

private:
  std::vector<std::string> m_Units;
  typedef std::map<std::string, WarScrollGenerator> WarScrollGeneratorType;
  WarScrollGeneratorType m_NameToWarScroll;
};

#endif // STORMCAST_ETERNALS_FACTION_H
