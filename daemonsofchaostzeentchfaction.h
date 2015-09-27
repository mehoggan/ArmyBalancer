#ifndef DAEMONSOFCHAOSTZEENTCH_H
#define DAEMONSOFCHAOSTZEENTCH_H

#include "ifaction.h"

class DaemonsOfChaosTzeentchFaction : public IFaction
{
public:
  DaemonsOfChaosTzeentchFaction();

  virtual std::string getName() const override
  {
    return "Daemons of Chaos (Tzeentch)";
  }
  virtual const std::vector<std::string> &getUnits() const override;
  virtual void getWarScrolls(std::list<WarScroll> &warScrolls) override;

private:
  std::vector<std::string> m_Units;
  typedef std::map<std::string, WarScrollGenerator> WarScrollGeneratorType;
  WarScrollGeneratorType m_NameToWarScroll;
};

#endif // DAEMONSOFCHAOSTZEENTCH_H
