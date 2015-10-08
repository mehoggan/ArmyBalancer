#ifndef THE_EMPIRE_H
#define THE_EMPIRE_H

#include "ifaction.h"

class TheEmpireFaction : public IFaction
{
public:
  TheEmpireFaction();

  virtual std::string getName() const override {return "The Empire";}
  virtual const std::vector<std::string> &getUnits() const override;
  virtual void getWarScrolls(std::list<WarScroll> &warScrolls) override;

private:
  std::vector<std::string> m_Units;
  typedef std::map<std::string, WarScrollGenerator> WarScrollGeneratorType;
  WarScrollGeneratorType m_NameToWarScroll;
};

#endif // THE_EMPIRE_H
