#ifndef TheEmpire_H
#define TheEmpire_H

#include "iarmy.h"

class TheEmpireArmy : public IArmy
{
public:
  TheEmpireArmy();

  virtual const QStringList &getUnits() override;
  virtual void buildUiForBattleScroll(QQuickView *ui, int scrollIndex) override;

private:
  QStringList m_Units;
};

#endif // TheEmpire_H
