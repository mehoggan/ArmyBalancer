#ifndef SYLVANETH_FACTION_H
#define SYLVANETH_FACTION_H

#include "ifaction.h"

class SylvanethFaction : public IFaction
{
public:
  SylvanethFaction();

  virtual std::string getName() const override {return "Sylvaneth";}
  virtual const std::vector<std::string> &getUnits() const override;
  virtual void getWarScrolls(std::list<WarScroll> &warScrolls) override;

private:
  std::vector<std::string> m_Units;
  typedef std::map<std::string, WarScrollGenerator> WarScrollGeneratorType;
  WarScrollGeneratorType m_NameToWarScroll;
};

#endif // SYLVANETH_FACTION_H
