#ifndef SKAVEN_H
#define SKAVEN_H

#include "iarmy.h"

class SkavenArmy : public IArmy
{
public:
  SkavenArmy();

  virtual const QStringList &getUnits() override;
  virtual void buildUiForBattleScroll(QQuickView *ui, int scrollIndex) override;

private:
  QStringList m_Units;
};

#endif // SKAVEN_H
