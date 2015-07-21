#ifndef DWARFS_H
#define DWARFS_H

#include "ifaction.h"

class DwarfsFaction : public IFaction
{
public:
  DwarfsFaction();

  virtual QString getName() const override {return "Dwarfs";}
  virtual const QStringList &getUnits() override;
  virtual void buildUiForBattleScroll(QQuickView * /*ui*/, int scrollIndex) override;

private:
  QStringList m_Units;
};

#endif // DWARFS_H
