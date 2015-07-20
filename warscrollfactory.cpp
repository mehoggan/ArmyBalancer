#include "armies.h"
#include "warscrollfactory.h"

#include <QDebug>

WarScrollFactory &WarScrollFactory::getSharedInstance()
{
  static WarScrollFactory s_WarScrollFactory(Private{});

  return s_WarScrollFactory;
}

WarScrollFactory::WarScrollFactory(const Private &)
{
  BeastmenArmy beastmen;
  BretonniaArmy bretonnia;
  DaemonsOfChaosKhorneArmy daemonsOfKhorne;
  DaemonsOfChaosNurgleArmy daemonsOfNurgle;
  DaemonsOfChaosSlaaneshArmy daemonsOfSlaanesh;
  DaemonsOfChaosTzeentchArmy daemonsOfTzeentch;
  DarkElvesArmy darkElves;
  DwarfsArmy dwarfs;
  HighElvesArmy highElves;
  LizardmenArmy lizardmen;
  OgreKingdomsArmy ogres;
  OrcsAndGoblinsArmy orcsAndGoblins;
  SkavenArmy skaven;
  TheEmpireArmy theEmpire;
  TombKingsArmy tombKings;
  VampireCountsArmy vampireCounts;
  WarriorsOfChaosArmy warriorsOfChaos;
  WoodElvesArmy woodElves;

  QStringList units;
  foreach(const QString &unit, beastmen.getUnits()) units.push_back(unit);
  foreach(const QString &unit, bretonnia.getUnits()) units.push_back(unit);
  foreach(const QString &unit, daemonsOfKhorne.getUnits())
    units.push_back(unit);
  foreach(const QString &unit, daemonsOfNurgle.getUnits())
    units.push_back(unit);
  foreach(const QString &unit, daemonsOfSlaanesh.getUnits())
    units.push_back(unit);
  foreach(const QString &unit, daemonsOfTzeentch.getUnits())
    units.push_back(unit);
  foreach(const QString &unit, darkElves.getUnits()) units.push_back(unit);
  foreach(const QString &unit, dwarfs.getUnits()) units.push_back(unit);
  foreach(const QString &unit, highElves.getUnits()) units.push_back(unit);
  foreach(const QString &unit, lizardmen.getUnits()) units.push_back(unit);
  foreach(const QString &unit, ogres.getUnits()) units.push_back(unit);
  foreach(const QString &unit, orcsAndGoblins.getUnits()) units.push_back(unit);
  foreach(const QString &unit, skaven.getUnits()) units.push_back(unit);
  foreach(const QString &unit, theEmpire.getUnits()) units.push_back(unit);
  foreach(const QString &unit, tombKings.getUnits()) units.push_back(unit);
  foreach(const QString &unit, vampireCounts.getUnits()) units.push_back(unit);
  foreach(const QString &unit, warriorsOfChaos.getUnits())
    units.push_back(unit);
  foreach(const QString &unit, woodElves.getUnits()) units.push_back(unit);

  foreach(const QString &unit, units) {
    qDebug() << unit;
  }
}

