#ifndef OGREKINGDOMS_H
#define OGREKINGDOMS_H

#include "ifaction.h"

class OgreKingdomsFaction : public IFaction
{
public:
  OgreKingdomsFaction();

  virtual QString getName() const override {return "Ogre Kingdom";}
  virtual const QStringList &getUnits() const override;
  virtual QList<WarScroll> getWarScrolls() const override;

private:
  QStringList m_Units;
  typedef QMap<QString, WarScrollGenerator> WarScrollGeneratorType;
  WarScrollGeneratorType m_NameToWarScroll;
};

#endif // OGREKINGDOMS_H
