#ifndef BRETONNIA_H
#define BRETONNIA_H

#include "ifaction.h"

class BretonniaFaction : public IFaction
{
public:
  BretonniaFaction();

  virtual QString getName() const override {return "Bretonnia";}
  virtual const QStringList &getUnits() const override;
  virtual QList<WarScroll> getWarScrolls() const override;

private:
  QStringList m_Units;
  QMap<QString, WarScrollGenerator> m_NameToWarScroll;
};

#endif // BRETONNIA_H
