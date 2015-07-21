#ifndef TOMBKINGS_H
#define TOMBKINGS_H

#include "ifaction.h"

class TombKingsFaction : public IFaction
{
public:
  TombKingsFaction();

  virtual QString getName() const override {return "Tomb Kings";}
  virtual const QStringList &getUnits() override;
  virtual void buildUiForBattleScroll(QQuickView * /*ui*/, int scrollIndex) override;

private:
  QStringList m_Units;
};

#endif // TOMBKINGS_H
