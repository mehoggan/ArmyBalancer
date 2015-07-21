#ifndef DARKELVES_H
#define DARKELVES_H

#include "ifaction.h"

class DarkElvesFaction : public IFaction
{
public:
  DarkElvesFaction();

  virtual QString getName() const override {return "Dark Elves";}
  virtual const QStringList &getUnits() override;
  virtual void buildUiForBattleScroll(QQuickView * /*ui*/, int scrollIndex) override;

private:
  QStringList m_Units;
};

#endif // DARKELVES_H
