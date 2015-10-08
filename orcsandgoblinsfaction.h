#ifndef ORCSANDGOBLINS_H
#define ORCSANDGOBLINS_H

#include "ifaction.h"

class OrcsAndGoblinsFaction : public IFaction
{
public:
  OrcsAndGoblinsFaction();

  virtual std::string getName() const override {return "Orcs and Goblins";}
  virtual const std::vector<std::string> &getUnits() const override;
  virtual void getWarScrolls(std::list<WarScroll> &warScrolls) override;

private:
  std::vector<std::string> m_Units;
  typedef std::map<std::string, WarScrollGenerator> WarScrollGeneratorType;
  WarScrollGeneratorType m_NameToWarScroll;
};

#endif // ORCSANDGOBLINS_H
