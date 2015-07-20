#ifndef WARRIORSOFCHAOS_H
#define WARRIORSOFCHAOS_H

#include "iarmy.h"

class WarriorsOfChaosArmy : public IArmy
{
public:
  WarriorsOfChaosArmy();

  virtual const QStringList &getUnits() override;
  virtual void buildUiForBattleScroll(QQuickView *ui, int scrollIndex) override;

private:
  QStringList m_Units;
};

#endif // WARRIORSOFCHAOS_H
