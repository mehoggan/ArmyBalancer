#ifndef LIZARDMEN_H
#define LIZARDMEN_H

#include "ifaction.h"

class LizardmenFaction : public IFaction
{
public:
  LizardmenFaction();

  virtual QString getName() const override {return "Lizardmen";}
  virtual const QStringList &getUnits() const override;
  virtual QList<WarScroll> getWarScrolls() const override;

private:
  QStringList m_Units;
  typedef QMap<QString, WarScrollGenerator> WarScrollGeneratorType;
  WarScrollGeneratorType m_NameToWarScroll;
};

#endif // LIZARDMEN_H
