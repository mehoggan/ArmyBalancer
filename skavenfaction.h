#ifndef SKAVEN_H
#define SKAVEN_H

#include "ifaction.h"

class SkavenFaction : public IFaction
{
public:
  SkavenFaction();

  virtual QString getName() const override {return "Skaven";}
  virtual const QStringList &getUnits() const override;
  virtual QList<WarScroll> getWarScrolls() const override;

private:
  QStringList m_Units;
  QMap<QString, WarScrollGenerator> m_NameToWarScroll;
};

#endif // SKAVEN_H
