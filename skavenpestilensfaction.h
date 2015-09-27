#ifndef SKAVEN_PESTILENS_FACTION_H
#define SKAVEN_PESTILENS_FACTION_H

#include "ifaction.h"

class SkavenPestilensFaction : public IFaction
{
public:
  SkavenPestilensFaction();

  virtual std::string getName() const override {return "Skaven Pestilens";}
  virtual const std::vector<std::string> &getUnits() const override;
  virtual void getWarScrolls(std::list<WarScroll> &warScrolls) override;

private:
  std::vector<std::string> m_Units;
  typedef std::map<std::string, WarScrollGenerator> WarScrollGeneratorType;
  WarScrollGeneratorType m_NameToWarScroll;
};

#endif // SKAVEN_PESTILENS_FACTION_H
