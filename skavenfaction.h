#ifndef SKAVEN_H
#define SKAVEN_H

#include "ifaction.h"

class SkavenFaction : public IFaction
{
public:
  SkavenFaction();

  virtual std::string getName() const override {return "Skaven";}
  virtual const std::vector<std::string> &getUnits() const override;
  virtual void getWarScrolls(std::list<WarScroll> &warScrolls) override;

private:
  std::vector<std::string> m_Units;
  typedef std::map<std::string, WarScrollGenerator> WarScrollGeneratorType;
  WarScrollGeneratorType m_NameToWarScroll;
};

#endif // SKAVEN_H
