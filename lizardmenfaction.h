#ifndef LIZARDMEN_H
#define LIZARDMEN_H

#include "ifaction.h"

class LizardmenFaction : public IFaction
{
public:
  LizardmenFaction();

  virtual std::string getName() const override {return "Lizardmen";}
  virtual const std::vector<std::string> &getUnits() const override;
  virtual void getWarScrolls(std::list<WarScroll> &warScrolls) override;

private:
  std::vector<std::string> m_Units;
  typedef std::map<std::string, WarScrollGenerator> WarScrollGeneratorType;
  WarScrollGeneratorType m_NameToWarScroll;
};

#endif // LIZARDMEN_H
