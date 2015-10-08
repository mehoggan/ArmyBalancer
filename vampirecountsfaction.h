#ifndef VAMPIRECOUNTS_H
#define VAMPIRECOUNTS_H

#include "ifaction.h"

class VampireCountsFaction : public IFaction
{
public:
  VampireCountsFaction();

  virtual std::string getName() const override {return "Vampire Counts";}
  virtual const std::vector<std::string> &getUnits() const override;
  virtual void getWarScrolls(std::list<WarScroll> &warScrolls) override;

private:
  std::vector<std::string> m_Units;
  typedef std::map<std::string, WarScrollGenerator> WarScrollGeneratorType;
  WarScrollGeneratorType m_NameToWarScroll;
};

#endif // VAMPIRECOUNTS_H
