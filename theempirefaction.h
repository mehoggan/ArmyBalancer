#ifndef TheEmpire_H
#define TheEmpire_H

#include "ifaction.h"

class TheEmpireFaction : public IFaction
{
public:
  TheEmpireFaction();

  virtual QString getName() const override {return "The Empire";}
  virtual const QStringList &getUnits() const override;
  virtual QList<WarScroll> getWarScrolls() const override;

private:
  QStringList m_Units;
  typedef QMap<QString, WarScrollGenerator> WarScrollGeneratorType;
  WarScrollGeneratorType m_NameToWarScroll;
};

#endif // TheEmpire_H
