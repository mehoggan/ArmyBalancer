#include "daemonsofchaosslaaneshfaction.h"

namespace WarScrollGeneration
{
  WarScroll Keeper_of_Secrets()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll The_Masque_of_Slaanesh()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll Herald_of_Slaanesh()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll Herald_of_Slaanesh_on_Seeker_Chariot()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll Herald_of_Slaanesh_on_Exalted_Seeker_Chariot()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll Daemonettes_of_Slaanesh()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll Seekers_of_Slaanesh()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll Fiends_of_Slaanesh()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll Seeker_Chariots_of_Slaanesh()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll Exalted_Seeker_Chariots_of_Slaanesh()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll Hellflayers_of_Slaanesh()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll Daemon_Prince_in_Slaanesh()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll Furies_in_Slaanesh()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll Soul_Grinder_in_Slaanesh()
  {
    WarScroll ws;
    return ws;
  }

}

DaemonsOfChaosSlaaneshFaction::DaemonsOfChaosSlaaneshFaction() :
  IFaction(nullptr)
{
  m_Units.push_back(tr(""));
  m_Units.push_back(tr("Keeper of Secrets"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::Keeper_of_Secrets);
  m_Units.push_back(tr("The Masque of Slaanesh"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::The_Masque_of_Slaanesh);
  m_Units.push_back(tr("Herald of Slaanesh"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::Herald_of_Slaanesh);
  m_Units.push_back(tr("Herald of Slaanesh on Seeker Chariot"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::Herald_of_Slaanesh_on_Seeker_Chariot);
  m_Units.push_back(tr("Herald of Slaanesh on Exalted Seeker Chariot"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::Herald_of_Slaanesh_on_Exalted_Seeker_Chariot);
  m_Units.push_back(tr("Daemonettes of Slaanesh"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::Daemonettes_of_Slaanesh);
  m_Units.push_back(tr("Seekers of Slaanesh"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::Seekers_of_Slaanesh);
  m_Units.push_back(tr("Fiends of Slaanesh"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::Fiends_of_Slaanesh);
  m_Units.push_back(tr("Seeker Chariots of Slaanesh"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::Seeker_Chariots_of_Slaanesh);
  m_Units.push_back(tr("Exalted Seeker Chariots of Slaanesh"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::Exalted_Seeker_Chariots_of_Slaanesh);
  m_Units.push_back(tr("Hellflayers of Slaanesh"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::Hellflayers_of_Slaanesh);
  m_Units.push_back(tr("Daemon Prince"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::Daemon_Prince_in_Slaanesh);
  m_Units.push_back(tr("Furies"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::Furies_in_Slaanesh);
  m_Units.push_back(tr("Soul Grinder"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::Soul_Grinder_in_Slaanesh);
}

const QStringList &DaemonsOfChaosSlaaneshFaction::getUnits() const
{
  return m_Units;
}

QList<WarScroll> DaemonsOfChaosSlaaneshFaction::getWarScrolls() const
{
  QList<WarScroll> warScrolls;
  return warScrolls;
}
