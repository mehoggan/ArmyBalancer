#ifndef TOMBKINGS_H
#define TOMBKINGS_H

#include "ifaction.h"

class TombKingsFaction : public IFaction
{
public:
  TombKingsFaction();

  virtual std::string getName() const override {return "Tomb Kings";}
  virtual const std::vector<std::string> &getUnits() const override;
  virtual void getWarScrolls(std::list<WarScroll> &warScrolls) override;

private:
  std::vector<std::string> m_Units;
  typedef std::map<std::string, WarScrollGenerator> WarScrollGeneratorType;
  WarScrollGeneratorType m_NameToWarScroll;
};

#endif // TOMBKINGS_H
