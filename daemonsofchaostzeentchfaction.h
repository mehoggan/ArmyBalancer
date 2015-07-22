#ifndef DAEMONSOFCHAOSTZEENTCH_H
#define DAEMONSOFCHAOSTZEENTCH_H

#include "ifaction.h"

class DaemonsOfChaosTzeentchFaction : public IFaction
{
public:
  DaemonsOfChaosTzeentchFaction();

  virtual QString getName() const override
  {
    return "Daemons of Chaos (Tzeentch)";
  }
  virtual const QStringList &getUnits() const override;
  virtual QList<WarScroll> getWarScrolls() const override;

private:
  QStringList m_Units;
  QMap<QString, WarScrollGenerator> m_NameToWarScroll;
};

#endif // DAEMONSOFCHAOSTZEENTCH_H
