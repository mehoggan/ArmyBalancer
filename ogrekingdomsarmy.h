#ifndef OGREKINGDOMS_H
#define OGREKINGDOMS_H

#include "iarmy.h"

class OgreKingdomsArmy : public IArmy
{
public:
  OgreKingdomsArmy();

  virtual const QStringList &getUnits() override;
  virtual void buildUiForBattleScroll(QQuickView *ui, int scrollIndex) override;

private:
  QStringList m_Units;
};

#endif // OGREKINGDOMS_H
