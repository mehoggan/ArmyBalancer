#ifndef KHORNE_BLOODBOUND_H
#define KHORNE_BLOODBOUND_H

#include "ifaction.h"

class KhorneBloodboundFaction : public IFaction
{
public:
  KhorneBloodboundFaction();

  virtual std::string getName() const override {return "Khorne Bloodbound";}
  virtual const std::vector<std::string> &getUnits() const override;
  virtual void getWarScrolls(std::list<WarScroll> &warScrolls) override;

private:
  std::vector<std::string> m_Units;
  typedef std::map<std::string, WarScrollGenerator> WarScrollGeneratorType;
  WarScrollGeneratorType m_NameToWarScroll;
};

#endif // KHORNE_BLOODBOUND_H
