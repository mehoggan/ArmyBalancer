#ifndef WOODELVES_H
#define WOODELVES_H

#include "ifaction.h"

class WoodElvesFaction : public IFaction
{
public:
  WoodElvesFaction();

  virtual QString getName() const override {return "Wood Elves";}
  virtual const QStringList &getUnits() override;
  virtual void buildUiForBattleScroll(QQuickView * /*ui*/, int scrollIndex) override;

private:
  QStringList m_Units;
};

#endif // WOODELVES_H
