#ifndef DAEMONSOFCHAOSSLAANESH_H
#define DAEMONSOFCHAOSSLAANESH_H

#include "ifaction.h"

class DaemonsOfChaosSlaaneshFaction : public IFaction
{
public:
  DaemonsOfChaosSlaaneshFaction();

  virtual QString getName() const override
  {
    return "Daemons of Chaos (Slaanesh)";
  }
  virtual const QStringList &getUnits() const override;
  virtual QList<WarScroll> getWarScrolls() const override;

private:
  QStringList m_Units;
  typedef QMap<QString, WarScrollGenerator> WarScrollGeneratorType;
  WarScrollGeneratorType m_NameToWarScroll;
};

#endif // DAEMONSOFCHAOSSLAANESH_H
