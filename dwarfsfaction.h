#ifndef DWARFS_H
#define DWARFS_H

#include "ifaction.h"

class DwarfsFaction : public IFaction
{
public:
  DwarfsFaction();

  virtual std::string getName() const override {return "Dwarfs";}
  virtual const std::vector<std::string> &getUnits() const override;
  virtual void getWarScrolls(std::list<WarScroll> &warScrolls) override;

private:
  std::vector<std::string> m_Units;
  typedef std::map<std::string, WarScrollGenerator> WarScrollGeneratorType;
  WarScrollGeneratorType m_NameToWarScroll;
};

#endif // DWARFS_H
