#ifndef DAEMONSOFCHAOSSLAANESH_H
#define DAEMONSOFCHAOSSLAANESH_H

#include "ifaction.h"

class DaemonsOfChaosSlaaneshFaction : public IFaction
{
public:
  DaemonsOfChaosSlaaneshFaction();

  virtual QString getName() const override {return "Daemons of Chaos (Slaanesh)";}
  virtual const QStringList &getUnits() override;
  virtual void buildUiForBattleScroll(QQuickView * /*ui*/, int scrollIndex) override;

private:
  QStringList m_Units;
};

#endif // DAEMONSOFCHAOSSLAANESH_H
