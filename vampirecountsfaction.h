#ifndef VAMPIRECOUNTS_H
#define VAMPIRECOUNTS_H

#include "ifaction.h"

class VampireCountsFaction : public IFaction
{
public:
  VampireCountsFaction();

  virtual QString getName() const override {return "Vampire Counts";}
  virtual const QStringList &getUnits() override;
  virtual void buildUiForBattleScroll(QQuickView * /*ui*/, int scrollIndex) override;

private:
  QStringList m_Units;
};

#endif // VAMPIRECOUNTS_H
