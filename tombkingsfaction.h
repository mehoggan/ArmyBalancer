#ifndef TOMBKINGS_H
#define TOMBKINGS_H

#include "ifaction.h"

class TombKingsFaction : public IFaction
{
public:
  TombKingsFaction();

  virtual QString getName() const override {return "Tomb Kings";}
  virtual const QStringList &getUnits() const override;
  virtual QList<WarScroll> getWarScrolls() const override;

private:
  QStringList m_Units;
  QMap<QString, WarScrollGenerator> m_NameToWarScroll;
};

#endif // TOMBKINGS_H
