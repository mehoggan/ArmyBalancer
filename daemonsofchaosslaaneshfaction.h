#ifndef DAEMONSOFCHAOSSLAANESH_H
#define DAEMONSOFCHAOSSLAANESH_H

#include "ifaction.h"

class DaemonsOfChaosSlaaneshFaction : public IFaction
{
public:
  DaemonsOfChaosSlaaneshFaction();

  virtual std::string getName() const override
  {
    return "Daemons of Chaos (Slaanesh)";
  }
  virtual const std::vector<std::string> &getUnits() const override;
  virtual void getWarScrolls(std::list<WarScroll> &warScrolls) override;

private:
  std::vector<std::string> m_Units;
  typedef std::map<std::string, WarScrollGenerator> WarScrollGeneratorType;
  WarScrollGeneratorType m_NameToWarScroll;
};

#endif // DAEMONSOFCHAOSSLAANESH_H
