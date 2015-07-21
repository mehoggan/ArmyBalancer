#ifndef DAEMONSOFCHAOSKHORNE_H
#define DAEMONSOFCHAOSKHORNE_H

#include "ifaction.h"

class DaemonsOfChaosKhorneFaction : public IFaction
{
public:
  DaemonsOfChaosKhorneFaction();

  virtual QString getName() const override {return "Daemons of Chaos (Khorne)";}
  virtual const QStringList &getUnits() override;
  virtual void buildUiForBattleScroll(QQuickView * /*ui*/, int scrollIndex) override;

private:
  QStringList m_Units;
};

#endif // DAEMONSOFCHAOSKHORNE_H
