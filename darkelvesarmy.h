#ifndef DARKELVES_H
#define DARKELVES_H

#include "iarmy.h"

class DarkElvesArmy : public IArmy
{
public:
  DarkElvesArmy();

  virtual const QStringList &getUnits() override;
  virtual void buildUiForBattleScroll(QQuickView *ui, int scrollIndex) override;

private:
  QStringList m_Units;
};

#endif // DARKELVES_H
