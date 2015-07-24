#include "daemonsofchaosslaaneshfaction.h"

namespace WarScrollGeneration
{
  WarScroll Keeper_of_Secrets(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll The_Masque_of_Slaanesh(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Herald_of_Slaanesh(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Herald_of_Slaanesh_on_Seeker_Chariot(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Herald_of_Slaanesh_on_Exalted_Seeker_Chariot(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Daemonettes_of_Slaanesh(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Seekers_of_Slaanesh(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Fiends_of_Slaanesh(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Seeker_Chariots_of_Slaanesh(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Exalted_Seeker_Chariots_of_Slaanesh(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Hellflayers_of_Slaanesh(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Daemon_Prince_in_Slaanesh(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Furies_in_Slaanesh(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Soul_Grinder_in_Slaanesh(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }
}

DaemonsOfChaosSlaaneshFaction::DaemonsOfChaosSlaaneshFaction() :
  IFaction(nullptr)
{
  m_Units.push_back("");
  m_Units.push_back("Keeper of Secrets");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Keeper_of_Secrets, m_Units.back())));
  m_Units.push_back("The Masque of Slaanesh");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::The_Masque_of_Slaanesh, m_Units.back())));
  m_Units.push_back("Herald of Slaanesh");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Herald_of_Slaanesh, m_Units.back())));
  m_Units.push_back("Herald of Slaanesh on Seeker Chariot");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Herald_of_Slaanesh_on_Seeker_Chariot,
    m_Units.back())));
  m_Units.push_back("Herald of Slaanesh on Exalted Seeker Chariot");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(
      &WarScrollGeneration::Herald_of_Slaanesh_on_Exalted_Seeker_Chariot,
      m_Units.back())));
  m_Units.push_back("Daemonettes of Slaanesh");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Daemonettes_of_Slaanesh, m_Units.back())));
  m_Units.push_back("Seekers of Slaanesh");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Seekers_of_Slaanesh, m_Units.back())));
  m_Units.push_back("Fiends of Slaanesh");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Fiends_of_Slaanesh, m_Units.back())));
  m_Units.push_back("Seeker Chariots of Slaanesh");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Seeker_Chariots_of_Slaanesh,
    m_Units.back())));
  m_Units.push_back("Exalted Seeker Chariots of Slaanesh");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Exalted_Seeker_Chariots_of_Slaanesh,
    m_Units.back())));
  m_Units.push_back("Hellflayers of Slaanesh");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Hellflayers_of_Slaanesh, m_Units.back())));
  m_Units.push_back("Daemon Prince");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Daemon_Prince_in_Slaanesh,
    m_Units.back())));
  m_Units.push_back("Furies");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Furies_in_Slaanesh, m_Units.back())));
  m_Units.push_back("Soul Grinder");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Soul_Grinder_in_Slaanesh, m_Units.back())));
}

const std::vector<std::string> &DaemonsOfChaosSlaaneshFaction::getUnits() const
{
  return m_Units;
}

void DaemonsOfChaosSlaaneshFaction::getWarScrolls(
  std::list<WarScroll>& warScrolls)
{
  for (const std::string &unit : m_Units) {
    if (unit.empty()) {
      continue;
    }
    WarScroll ws = m_NameToWarScroll[unit](unit);
    warScrolls.push_back(ws);
  }
}
