#ifndef BEASTMEN_H
#define BEASTMEN_H

#include "iarmy.h"

class BeastmenArmy : public IArmy
{
public:
  BeastmenArmy();

  virtual const QStringList &getUnits() override;
  virtual void buildUiForBattleScroll(QQuickView *ui, int scrollIndex) override;

private:
  QStringList m_Units;
};

#endif // BEASTMEN_H
