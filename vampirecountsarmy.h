#ifndef VAMPIRECOUNTS_H
#define VAMPIRECOUNTS_H

#include "iarmy.h"

class VampireCountsArmy : public IArmy
{
public:
  VampireCountsArmy();

  virtual const QStringList &getUnits() override;
  virtual void buildUiForBattleScroll(QQuickView *ui, int scrollIndex) override;

private:
  QStringList m_Units;
};

#endif // VAMPIRECOUNTS_H
