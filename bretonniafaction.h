#ifndef BRETONNIA_H
#define BRETONNIA_H

#include "ifaction.h"

class BretonniaFaction : public IFaction
{
public:
  BretonniaFaction();

  virtual std::string getName() const override {return "Bretonnia";}
  virtual const std::vector<std::string> &getUnits() const override;
  virtual void getWarScrolls(std::list<WarScroll> &warScrolls) override;

private:
  std::vector<std::string> m_Units;
  typedef std::map<std::string, WarScrollGenerator> WarScrollGeneratorType;
  WarScrollGeneratorType m_NameToWarScroll;
};

#endif // BRETONNIA_H
