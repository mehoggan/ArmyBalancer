#ifndef LIZARDMEN_H
#define LIZARDMEN_H

#include "ifaction.h"

class LizardmenFaction : public IFaction
{
public:
  LizardmenFaction();

  virtual QString getName() const override {return "Lizardmen";}
  virtual const QStringList &getUnits() override;
  virtual void buildUiForBattleScroll(QQuickView * /*ui*/, int scrollIndex) override;

private:
  QStringList m_Units;
};

#endif // LIZARDMEN_H
