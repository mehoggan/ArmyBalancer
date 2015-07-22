#ifndef VAMPIRECOUNTS_H
#define VAMPIRECOUNTS_H

#include "ifaction.h"

class VampireCountsFaction : public IFaction
{
public:
  VampireCountsFaction();

  virtual QString getName() const override {return "Vampire Counts";}
  virtual const QStringList &getUnits() const override;
  virtual QList<WarScroll> getWarScrolls() const override;

private:
  QStringList m_Units;
  QMap<QString, WarScrollGenerator> m_NameToWarScroll;
};

#endif // VAMPIRECOUNTS_H
