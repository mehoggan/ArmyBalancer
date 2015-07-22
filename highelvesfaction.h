#ifndef HIGHELVES_H
#define HIGHELVES_H

#include "ifaction.h"

class HighElvesFaction : public IFaction
{
public:
  HighElvesFaction();

  virtual QString getName() const override {return "High Elves";}
  virtual const QStringList &getUnits() const override;
  virtual QList<WarScroll> getWarScrolls() const override;

private:
  QStringList m_Units;
  QMap<QString, WarScrollGenerator> m_NameToWarScroll;
};

#endif // HIGHELVES_H
