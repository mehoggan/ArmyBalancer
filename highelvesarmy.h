#ifndef HIGHELVES_H
#define HIGHELVES_H

#include "iarmy.h"

class HighElvesArmy : public IArmy
{
public:
  HighElvesArmy();

  virtual const QStringList &getUnits() override;
  virtual void buildUiForBattleScroll(QQuickView *ui, int scrollIndex) override;

private:
  QStringList m_Units;
};

#endif // HIGHELVES_H
