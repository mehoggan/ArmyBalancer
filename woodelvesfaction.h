#ifndef WOODELVES_H
#define WOODELVES_H

#include "ifaction.h"

class WoodElvesFaction : public IFaction
{
public:
  WoodElvesFaction();

  virtual QString getName() const override {return "Wood Elves";}
  virtual const QStringList &getUnits() const override;
  virtual QList<WarScroll> getWarScrolls() const override;

private:
  QStringList m_Units;
  typedef QMap<QString, WarScrollGenerator> WarScrollGeneratorType;
  WarScrollGeneratorType m_NameToWarScroll;
};

#endif // WOODELVES_H
