#ifndef OGREKINGDOMS_H
#define OGREKINGDOMS_H

#include "ifaction.h"

class OgreKingdomsFaction : public IFaction
{
public:
  OgreKingdomsFaction();

  virtual std::string getName() const override {return "Ogre Kingdom";}
  virtual const std::vector<std::string> &getUnits() const override;
  virtual void getWarScrolls(std::list<WarScroll> &warScrolls) override;

private:
  std::vector<std::string> m_Units;
  typedef std::map<std::string, WarScrollGenerator> WarScrollGeneratorType;
  WarScrollGeneratorType m_NameToWarScroll;
};

#endif // OGREKINGDOMS_H
