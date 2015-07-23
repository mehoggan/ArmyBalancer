#ifndef WARRIORSOFCHAOS_H
#define WARRIORSOFCHAOS_H

#include "ifaction.h"

class WarriorsOfChaosFaction : public IFaction
{
public:
  WarriorsOfChaosFaction();

  virtual QString getName() const override {return "Warriors of Chaos";}
  virtual const QStringList &getUnits() const override;
  virtual QList<WarScroll> getWarScrolls() const override;

private:
  QStringList m_Units;
  typedef QMap<QString, WarScrollGenerator> WarScrollGeneratorType;
  WarScrollGeneratorType m_NameToWarScroll;
};

#endif // WARRIORSOFCHAOS_H
