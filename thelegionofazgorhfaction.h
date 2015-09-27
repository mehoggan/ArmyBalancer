#ifndef THE_LEGION_OF_AZGORH_FACTION_H
#define THE_LEGION_OF_AZGORH_FACTION_H

#include "ifaction.h"

class TheLegionOfAzgorhFaction : public IFaction
{
public:
  TheLegionOfAzgorhFaction();

  virtual std::string getName() const override {return "The Legion of Azgorh";}
  virtual const std::vector<std::string> &getUnits() const override;
  virtual void getWarScrolls(std::list<WarScroll> &warScrolls) override;

private:
  std::vector<std::string> m_Units;
  typedef std::map<std::string, WarScrollGenerator> WarScrollGeneratorType;
  WarScrollGeneratorType m_NameToWarScroll;
};

#endif // THE_LEGION_OF_AZGORH_FACTION_H
