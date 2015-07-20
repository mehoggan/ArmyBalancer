#ifndef LIZARDMEN_H
#define LIZARDMEN_H

#include "iarmy.h"

class LizardmenArmy : public IArmy
{
public:
  LizardmenArmy();

  virtual const QStringList &getUnits() override;
  virtual void buildUiForBattleScroll(QQuickView *ui, int scrollIndex) override;

private:
  QStringList m_Units;
};

#endif // LIZARDMEN_H
