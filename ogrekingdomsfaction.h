#ifndef OGREKINGDOMS_H
#define OGREKINGDOMS_H

#include "ifaction.h"

class OgreKingdomsFaction : public IFaction
{
public:
  OgreKingdomsFaction();

  virtual QString getName() const override {return "Ogre Kingdom";}
  virtual const QStringList &getUnits() override;
  virtual void buildUiForBattleScroll(QQuickView * /*ui*/, int scrollIndex) override;

private:
  QStringList m_Units;
};

#endif // OGREKINGDOMS_H
