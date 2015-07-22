#ifndef DWARFS_H
#define DWARFS_H

#include "ifaction.h"

class DwarfsFaction : public IFaction
{
public:
  DwarfsFaction();

  virtual QString getName() const override {return "Dwarfs";}
  virtual const QStringList &getUnits() const override;
  virtual QList<WarScroll> getWarScrolls() const override;

private:
  QStringList m_Units;
  QMap<QString, WarScrollGenerator> m_NameToWarScroll;
};

#endif // DWARFS_H
