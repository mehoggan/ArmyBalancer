#ifndef WOODELVES_H
#define WOODELVES_H

#include "iarmy.h"

class WoodElvesArmy : public IArmy
{
public:
  WoodElvesArmy();

  virtual const QStringList &getUnits() override;
  virtual void buildUiForBattleScroll(QQuickView *ui, int scrollIndex) override;

private:
  QStringList m_Units;
};

#endif // WOODELVES_H
