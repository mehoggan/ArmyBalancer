#include "daemonsofchaostzeentchfaction.h"

namespace WarScrollGeneration
{
  WarScroll Kairos_Fateweaver()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll Lord_of_Change()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll The_Changeling()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll Herald_of_Tzeentch()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll Herald_of_Tzeentch_on_Disc_of_Tzeentch()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll Herald_of_Tzeentch_on_Burning_Chariot()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll The_Blue_Scribes()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll Pink_Horrors_of_Tzeentch()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll Exalted_Flamers()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll Flamers_of_Tzeentch()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll Screamers_of_Tzeentch()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll Burning_Chariots_of_Tzeeentch()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll Daemon_Prince_in_Tzeentch()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll Furies_in_Tzeentch()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll Soul_Grinder_in_Tzeentch()
  {
    WarScroll ws;
    return ws;
  }
}

DaemonsOfChaosTzeentchFaction::DaemonsOfChaosTzeentchFaction() :
  IFaction(nullptr)
{
  m_Units.push_back(tr(""));
  m_Units.push_back(tr("Kairos Fateweaver"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::Kairos_Fateweaver);
  m_Units.push_back(tr("Lord of Change"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::Lord_of_Change);
  m_Units.push_back(tr("The Changeling"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::The_Changeling);
  m_Units.push_back(tr("Herald of Tzeentch"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::Herald_of_Tzeentch);
  m_Units.push_back(tr("Herald of Tzeentch on Disc of Tzeentch"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::Herald_of_Tzeentch_on_Disc_of_Tzeentch);
  m_Units.push_back(tr("Herald of Tzeentch on Burning Chariot"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::Herald_of_Tzeentch_on_Burning_Chariot);
  m_Units.push_back(tr("The Blue Scribes"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::The_Blue_Scribes);
  m_Units.push_back(tr("Pink Horrors of Tzeentch"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::Pink_Horrors_of_Tzeentch);
  m_Units.push_back(tr("Exalted Flamers"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::Exalted_Flamers);
  m_Units.push_back(tr("Flamers of Tzeentch"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::Flamers_of_Tzeentch);
  m_Units.push_back(tr("Screamers of Tzeentch"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::Screamers_of_Tzeentch);
  m_Units.push_back(tr("Burning Chariots of Tzeeentch"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::Burning_Chariots_of_Tzeeentch);
  m_Units.push_back(tr("Daemon Prince"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::Daemon_Prince_in_Tzeentch);
  m_Units.push_back(tr("Furies"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::Furies_in_Tzeentch);
  m_Units.push_back(tr("Soul Grinder"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::Soul_Grinder_in_Tzeentch);
}

const QStringList &DaemonsOfChaosTzeentchFaction::getUnits() const
{
  return m_Units;
}

QList<WarScroll> DaemonsOfChaosTzeentchFaction::getWarScrolls() const
{
  QList<WarScroll> warScrolls;
  return warScrolls;
}
