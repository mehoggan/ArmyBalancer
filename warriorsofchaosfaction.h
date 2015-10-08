#ifndef WARRIORSOFCHAOS_H
#define WARRIORSOFCHAOS_H

#include "ifaction.h"

class WarriorsOfChaosFaction : public IFaction
{
public:
  WarriorsOfChaosFaction();

  virtual std::string getName() const override {return "Warriors of Chaos";}
  virtual const std::vector<std::string> &getUnits() const override;
  virtual void getWarScrolls(std::list<WarScroll> &warScrolls) override;

private:
  std::vector<std::string> m_Units;
  typedef std::map<std::string, WarScrollGenerator> WarScrollGeneratorType;
  WarScrollGeneratorType m_NameToWarScroll;
};

#endif // WARRIORSOFCHAOS_H
