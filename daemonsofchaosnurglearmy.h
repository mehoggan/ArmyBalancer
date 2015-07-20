#ifndef DAEMONSOFCHAOSNURGLE_H
#define DAEMONSOFCHAOSNURGLE_H

#include "iarmy.h"

class DaemonsOfChaosNurgleArmy : public IArmy
{
public:
  DaemonsOfChaosNurgleArmy();

  virtual const QStringList &getUnits() override;
  virtual void buildUiForBattleScroll(QQuickView *ui, int scrollIndex) override;

private:
  QStringList m_Units;
};

#endif // DAEMONSOFCHAOSNURGLE_H
