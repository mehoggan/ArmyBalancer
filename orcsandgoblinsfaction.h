#ifndef ORCSANDGOBLINS_H
#define ORCSANDGOBLINS_H

#include "ifaction.h"

class OrcsAndGoblinsFaction : public IFaction
{
public:
  OrcsAndGoblinsFaction();

  virtual QString getName() const override {return "Orcs and Goblins";}
  virtual const QStringList &getUnits() const override;
  virtual QList<WarScroll> getWarScrolls() const override;

private:
  QStringList m_Units;
  typedef QMap<QString, WarScrollGenerator> WarScrollGeneratorType;
  WarScrollGeneratorType m_NameToWarScroll;
};

#endif // ORCSANDGOBLINS_H
