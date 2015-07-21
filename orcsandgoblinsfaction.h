#ifndef ORCSANDGOBLINS_H
#define ORCSANDGOBLINS_H

#include "ifaction.h"

class OrcsAndGoblinsFaction : public IFaction
{
public:
  OrcsAndGoblinsFaction();

  virtual QString getName() const override {return "Orcs and Goblins";}
  virtual const QStringList &getUnits() override;
  virtual void buildUiForBattleScroll(QQuickView * /*ui*/, int scrollIndex) override;

private:
  QStringList m_Units;
};

#endif // ORCSANDGOBLINS_H
