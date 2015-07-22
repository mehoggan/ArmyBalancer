#include "daemonsofchaosnurglefaction.h"

namespace WarScrollGeneration
{
  WarScroll Great_Unclean_One()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll Epidemius()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll Herald_of_Nurgle()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll Plaguebearers_of_Nurgle()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll Plague_Drones_of_Nurgle()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll Nurglings()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll Beasts_of_Nurgle()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll Daemon_Prince_in_Nurgle()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll Furies_in_Nurgle()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll Soul_Grinder_in_Nurgle()
  {
    WarScroll ws;
    return ws;
  }
}

DaemonsOfChaosNurgleFaction::DaemonsOfChaosNurgleFaction() :
  IFaction(nullptr)
{
  m_Units.push_back(tr(""));
  m_Units.push_back(tr("Great Unclean One"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::Great_Unclean_One);
  m_Units.push_back(tr("Epidemius"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::Epidemius);
  m_Units.push_back(tr("Herald of Nurgle"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::Herald_of_Nurgle);
  m_Units.push_back(tr("Plaguebearers of Nurgle"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::Plaguebearers_of_Nurgle);
  m_Units.push_back(tr("Plague Drones of Nurgle"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::Plague_Drones_of_Nurgle);
  m_Units.push_back(tr("Nurglings"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::Nurglings);
  m_Units.push_back(tr("Beasts of Nurgle"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::Beasts_of_Nurgle);
  m_Units.push_back(tr("Daemon Prince"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::Daemon_Prince_in_Nurgle);
  m_Units.push_back(tr("Furies"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::Furies_in_Nurgle);
  m_Units.push_back(tr("Soul Grinder"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::Soul_Grinder_in_Nurgle);
}

const QStringList &DaemonsOfChaosNurgleFaction::getUnits() const
{
  return m_Units;
}

QList<WarScroll> DaemonsOfChaosNurgleFaction::getWarScrolls() const
{
  QList<WarScroll> warScrolls;
  return warScrolls;
}
