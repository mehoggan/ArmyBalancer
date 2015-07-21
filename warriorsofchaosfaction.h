#ifndef WARRIORSOFCHAOS_H
#define WARRIORSOFCHAOS_H

#include "ifaction.h"

class WarriorsOfChaosFaction : public IFaction
{
public:
  WarriorsOfChaosFaction();

  virtual QString getName() const override {return "Warriors of Chaos";}
  virtual const QStringList &getUnits() override;
  virtual void buildUiForBattleScroll(QQuickView * /*ui*/, int scrollIndex) override;

private:
  QStringList m_Units;
};

#endif // WARRIORSOFCHAOS_H
