#ifndef DAEMONSOFCHAOSNURGLE_H
#define DAEMONSOFCHAOSNURGLE_H

#include "ifaction.h"

class DaemonsOfChaosNurgleFaction : public IFaction
{
public:
  DaemonsOfChaosNurgleFaction();

  virtual std::string getName() const override
  {return "Daemons of Chaos (Nurgle)";}
  virtual const std::vector<std::string> &getUnits() const override;
  virtual void getWarScrolls(std::list<WarScroll> &warScrolls) override;

private:
  std::vector<std::string> m_Units;
  typedef std::map<std::string, WarScrollGenerator> WarScrollGeneratorType;
  WarScrollGeneratorType m_NameToWarScroll;
};

#endif // DAEMONSOFCHAOSNURGLE_H
