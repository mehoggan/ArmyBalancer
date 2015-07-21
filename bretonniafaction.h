#ifndef BRETONNIA_H
#define BRETONNIA_H

#include "ifaction.h"

class BretonniaFaction : public IFaction
{
public:
  BretonniaFaction();

  virtual QString getName() const override {return "Bretonnia";}
  virtual const QStringList &getUnits() override;
  virtual void buildUiForBattleScroll(QQuickView * /*ui*/, int scrollIndex) override;

private:
  QStringList m_Units;
};

#endif // BRETONNIA_H
