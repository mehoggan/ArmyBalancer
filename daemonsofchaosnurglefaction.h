#ifndef DAEMONSOFCHAOSNURGLE_H
#define DAEMONSOFCHAOSNURGLE_H

#include "ifaction.h"

class DaemonsOfChaosNurgleFaction : public IFaction
{
public:
  DaemonsOfChaosNurgleFaction();

  virtual QString getName() const override {return "Daemons of Chaos (Nurgle)";}
  virtual const QStringList &getUnits() override;
  virtual void buildUiForBattleScroll(QQuickView * /*ui*/, int scrollIndex) override;

private:
  QStringList m_Units;
};

#endif // DAEMONSOFCHAOSNURGLE_H
