#ifndef DWARFS_H
#define DWARFS_H

#include "iarmy.h"

class DwarfsArmy : public IArmy
{
public:
  DwarfsArmy();

  virtual const QStringList &getUnits() override;
  virtual void buildUiForBattleScroll(QQuickView *ui, int scrollIndex) override;

private:
  QStringList m_Units;
};

#endif // DWARFS_H
