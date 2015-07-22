#ifndef DARKELVES_H
#define DARKELVES_H

#include "ifaction.h"

class DarkElvesFaction : public IFaction
{
public:
  DarkElvesFaction();

  virtual QString getName() const override {return "Dark Elves";}
  virtual const QStringList &getUnits() const override;
  virtual QList<WarScroll> getWarScrolls() const override;

private:
  QStringList m_Units;
  QMap<QString, WarScrollGenerator> m_NameToWarScroll;
};

#endif // DARKELVES_H
