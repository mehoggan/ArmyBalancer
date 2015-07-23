#ifndef DAEMONSOFCHAOSKHORNE_H
#define DAEMONSOFCHAOSKHORNE_H

#include "ifaction.h"

class DaemonsOfChaosKhorneFaction : public IFaction
{
public:
  DaemonsOfChaosKhorneFaction();

  virtual QString getName() const override {return "Daemons of Chaos (Khorne)";}
  virtual const QStringList &getUnits() const override;
  virtual QList<WarScroll> getWarScrolls() const override;

private:
  QStringList m_Units;
  typedef QMap<QString, WarScrollGenerator> WarScrollGeneratorType;
  WarScrollGeneratorType m_NameToWarScroll;
};

#endif // DAEMONSOFCHAOSKHORNE_H
