#ifndef BRETONNIA_H
#define BRETONNIA_H

#include "iarmy.h"

class BretonniaArmy : public IArmy
{
public:
  BretonniaArmy();

  virtual const QStringList &getUnits() override;
  virtual void buildUiForBattleScroll(QQuickView *ui, int scrollIndex) override;

private:
  QStringList m_Units;
};

#endif // BRETONNIA_H
