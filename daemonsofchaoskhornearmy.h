#ifndef DAEMONSOFCHAOSKHORNE_H
#define DAEMONSOFCHAOSKHORNE_H

#include "iarmy.h"

class DaemonsOfChaosKhorneArmy : public IArmy
{
public:
  DaemonsOfChaosKhorneArmy();

  virtual const QStringList &getUnits() override;
  virtual void buildUiForBattleScroll(QQuickView *ui, int scrollIndex) override;

private:
  QStringList m_Units;
};

#endif // DAEMONSOFCHAOSKHORNE_H
