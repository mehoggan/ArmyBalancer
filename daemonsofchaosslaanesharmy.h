#ifndef DAEMONSOFCHAOSSLAANESH_H
#define DAEMONSOFCHAOSSLAANESH_H

#include "iarmy.h"

class DaemonsOfChaosSlaaneshArmy : public IArmy
{
public:
  DaemonsOfChaosSlaaneshArmy();

  virtual const QStringList &getUnits() override;
  virtual void buildUiForBattleScroll(QQuickView *ui, int scrollIndex) override;

private:
  QStringList m_Units;
};

#endif // DAEMONSOFCHAOSSLAANESH_H
