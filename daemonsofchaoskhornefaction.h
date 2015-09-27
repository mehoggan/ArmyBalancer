#ifndef DAEMONSOFCHAOSKHORNE_H
#define DAEMONSOFCHAOSKHORNE_H

#include "ifaction.h"

class DaemonsOfChaosKhorneFaction : public IFaction
{
public:
  DaemonsOfChaosKhorneFaction();

  virtual std::string getName() const override
  {return "Daemons of Chaos (Khorne)";}
  virtual const std::vector<std::string> &getUnits() const override;
  virtual void getWarScrolls(std::list<WarScroll> &warScrolls) override;

private:
  std::vector<std::string> m_Units;
  typedef std::map<std::string, WarScrollGenerator> WarScrollGeneratorType;
  WarScrollGeneratorType m_NameToWarScroll;
};

#endif // DAEMONSOFCHAOSKHORNE_H
