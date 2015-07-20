#ifndef ORCSANDGOBLINS_H
#define ORCSANDGOBLINS_H

#include "iarmy.h"

class OrcsAndGoblinsArmy : public IArmy
{
public:
  OrcsAndGoblinsArmy();

  virtual const QStringList &getUnits() override;
  virtual void buildUiForBattleScroll(QQuickView *ui, int scrollIndex) override;

private:
  QStringList m_Units;
};

#endif // ORCSANDGOBLINS_H
