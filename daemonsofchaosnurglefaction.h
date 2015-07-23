#ifndef DAEMONSOFCHAOSNURGLE_H
#define DAEMONSOFCHAOSNURGLE_H

#include "ifaction.h"

class DaemonsOfChaosNurgleFaction : public IFaction
{
public:
  DaemonsOfChaosNurgleFaction();

  virtual QString getName() const override {return "Daemons of Chaos (Nurgle)";}
  virtual const QStringList &getUnits() const override;
  virtual QList<WarScroll> getWarScrolls() const override;

private:
  QStringList m_Units;
  typedef QMap<QString, WarScrollGenerator> WarScrollGeneratorType;
  WarScrollGeneratorType m_NameToWarScroll;
};

#endif // DAEMONSOFCHAOSNURGLE_H
