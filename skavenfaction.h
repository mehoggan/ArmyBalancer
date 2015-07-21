#ifndef SKAVEN_H
#define SKAVEN_H

#include "ifaction.h"

class SkavenFaction : public IFaction
{
public:
  SkavenFaction();

  virtual QString getName() const override {return "Skaven";}
  virtual const QStringList &getUnits() override;
  virtual void buildUiForBattleScroll(QQuickView * /*ui*/, int scrollIndex) override;

private:
  QStringList m_Units;
};

#endif // SKAVEN_H
