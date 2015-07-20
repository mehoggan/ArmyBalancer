#ifndef TOMBKINGS_H
#define TOMBKINGS_H

#include "iarmy.h"

class TombKingsArmy : public IArmy
{
public:
  TombKingsArmy();

  virtual const QStringList &getUnits() override;
  virtual void buildUiForBattleScroll(QQuickView *ui, int scrollIndex) override;

private:
  QStringList m_Units;
};

#endif // TOMBKINGS_H
