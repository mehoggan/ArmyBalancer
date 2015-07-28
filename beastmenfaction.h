﻿#ifndef BEASTMEN_H
#define BEASTMEN_H

#include <functional>

#include "ifaction.h"

class BeastmenFaction : public IFaction
{
public:
  BeastmenFaction();

  virtual std::string getName() const override {return "Beastmen";}
  virtual const std::vector<std::string> &getUnits() const override;
  virtual void getWarScrolls(std::list<WarScroll> &warScrolls) override;

private:
  std::vector<std::string> m_Units;
  typedef std::map<std::string, WarScrollGenerator> WarScrollGeneratorType;
  WarScrollGeneratorType m_NameToWarScroll;
};

#endif // BEASTMEN_H