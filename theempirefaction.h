#ifndef TheEmpire_H
#define TheEmpire_H

#include "ifaction.h"

class TheEmpireFaction : public IFaction
{
public:
  TheEmpireFaction();

  virtual QString getName() const override {return "The Empire";}
  virtual const QStringList &getUnits() override;
  virtual void buildUiForBattleScroll(QQuickView * /*ui*/, int scrollIndex) override;

private:
  QStringList m_Units;
};

#endif // TheEmpire_H
