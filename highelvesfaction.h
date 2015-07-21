#ifndef HIGHELVES_H
#define HIGHELVES_H

#include "ifaction.h"

class HighElvesFaction : public IFaction
{
public:
  HighElvesFaction();

  virtual QString getName() const override {return "High Elves";}
  virtual const QStringList &getUnits() override;
  virtual void buildUiForBattleScroll(QQuickView * /*ui*/, int scrollIndex) override;

private:
  QStringList m_Units;
};

#endif // HIGHELVES_H
