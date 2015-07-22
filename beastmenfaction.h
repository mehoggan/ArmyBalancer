#ifndef BEASTMEN_H
#define BEASTMEN_H

#include <functional>

#include "ifaction.h"

class BeastmenFaction : public IFaction
{
public:
  BeastmenFaction();

  virtual QString getName() const override {return "Beastmen";}
  virtual const QStringList &getUnits() const override;
  virtual QList<WarScroll> getWarScrolls() const override;

private:
  QStringList m_Units;
  QMap<QString, WarScrollGenerator> m_NameToWarScroll;
};

#endif // BEASTMEN_H
