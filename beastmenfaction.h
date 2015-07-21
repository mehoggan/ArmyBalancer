#ifndef BEASTMEN_H
#define BEASTMEN_H

#include "ifaction.h"

class BeastmenFaction : public IFaction
{
public:
  BeastmenFaction();

  virtual QString getName() const override {return "Beastmen";}
  virtual const QStringList &getUnits() override;
  virtual void buildUiForBattleScroll(QQuickView * /*ui*/, int scrollIndex) override;

private:
  QStringList m_Units;
};

#endif // BEASTMEN_H
