#ifndef DAEMONSOFCHAOSTZEENTCH_H
#define DAEMONSOFCHAOSTZEENTCH_H

#include "iarmy.h"

class DaemonsOfChaosTzeentchArmy : public IArmy
{
public:
  DaemonsOfChaosTzeentchArmy();

  virtual const QStringList &getUnits() override;
  virtual void buildUiForBattleScroll(QQuickView *ui, int scrollIndex) override;

private:
  QStringList m_Units;
};

#endif // DAEMONSOFCHAOSTZEENTCH_H
