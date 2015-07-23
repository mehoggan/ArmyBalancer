#include "daemonsofchaosslaaneshfaction.h"

namespace WarScrollGeneration
{
  WarScroll Keeper_of_Secrets(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll The_Masque_of_Slaanesh(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Herald_of_Slaanesh(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Herald_of_Slaanesh_on_Seeker_Chariot(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Herald_of_Slaanesh_on_Exalted_Seeker_Chariot(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Daemonettes_of_Slaanesh(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Seekers_of_Slaanesh(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Fiends_of_Slaanesh(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Seeker_Chariots_of_Slaanesh(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Exalted_Seeker_Chariots_of_Slaanesh(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Hellflayers_of_Slaanesh(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Daemon_Prince_in_Slaanesh(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Furies_in_Slaanesh(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Soul_Grinder_in_Slaanesh(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }
}

DaemonsOfChaosSlaaneshFaction::DaemonsOfChaosSlaaneshFaction() :
  IFaction(nullptr)
{
  m_Units.push_back(tr(""));
  m_Units.push_back(tr("Keeper of Secrets"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Keeper_of_Secrets, m_Units.back()));
  m_Units.push_back(tr("The Masque of Slaanesh"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::The_Masque_of_Slaanesh, m_Units.back()));
  m_Units.push_back(tr("Herald of Slaanesh"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Herald_of_Slaanesh, m_Units.back()));
  m_Units.push_back(tr("Herald of Slaanesh on Seeker Chariot"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Herald_of_Slaanesh_on_Seeker_Chariot,
    m_Units.back()));
  m_Units.push_back(tr("Herald of Slaanesh on Exalted Seeker Chariot"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(
      &WarScrollGeneration::Herald_of_Slaanesh_on_Exalted_Seeker_Chariot,
      m_Units.back()));
  m_Units.push_back(tr("Daemonettes of Slaanesh"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Daemonettes_of_Slaanesh, m_Units.back()));
  m_Units.push_back(tr("Seekers of Slaanesh"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Seekers_of_Slaanesh, m_Units.back()));
  m_Units.push_back(tr("Fiends of Slaanesh"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Fiends_of_Slaanesh, m_Units.back()));
  m_Units.push_back(tr("Seeker Chariots of Slaanesh"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Seeker_Chariots_of_Slaanesh,
    m_Units.back()));
  m_Units.push_back(tr("Exalted Seeker Chariots of Slaanesh"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Exalted_Seeker_Chariots_of_Slaanesh,
    m_Units.back()));
  m_Units.push_back(tr("Hellflayers of Slaanesh"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Hellflayers_of_Slaanesh, m_Units.back()));
  m_Units.push_back(tr("Daemon Prince"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Daemon_Prince_in_Slaanesh, m_Units.back()));
  m_Units.push_back(tr("Furies"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Furies_in_Slaanesh, m_Units.back()));
  m_Units.push_back(tr("Soul Grinder"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Soul_Grinder_in_Slaanesh, m_Units.back()));
}

const QStringList &DaemonsOfChaosSlaaneshFaction::getUnits() const
{
  return m_Units;
}

QList<WarScroll> DaemonsOfChaosSlaaneshFaction::getWarScrolls() const
{
  QList<WarScroll> warScrolls;
  for (auto ws : m_NameToWarScroll.toStdMap()) {
    warScrolls.push_back(ws.second(ws.first));
  }
  return warScrolls;
}
