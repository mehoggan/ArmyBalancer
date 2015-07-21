#ifndef DAEMONSOFCHAOSTZEENTCH_H
#define DAEMONSOFCHAOSTZEENTCH_H

#include "ifaction.h"

class DaemonsOfChaosTzeentchFaction : public IFaction
{
public:
  DaemonsOfChaosTzeentchFaction();

  virtual QString getName() const override {return "Daemons of Chaos (Tzeentch)";}
  virtual const QStringList &getUnits() override;
  virtual void buildUiForBattleScroll(QQuickView * /*ui*/, int scrollIndex) override;

private:
  QStringList m_Units;
};

#endif // DAEMONSOFCHAOSTZEENTCH_H
