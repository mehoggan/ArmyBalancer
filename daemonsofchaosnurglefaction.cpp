#include "daemonsofchaosnurglefaction.h"

namespace WarScrollGeneration
{
  WarScroll Great_Unclean_One(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Epidemius(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Herald_of_Nurgle(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Plaguebearers_of_Nurgle(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Plague_Drones_of_Nurgle(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Nurglings(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Beasts_of_Nurgle(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Daemon_Prince_in_Nurgle(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Furies_in_Nurgle(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Soul_Grinder_in_Nurgle(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }
}

DaemonsOfChaosNurgleFaction::DaemonsOfChaosNurgleFaction() :
  IFaction(nullptr)
{
  m_Units.push_back("");
  m_Units.push_back("Great Unclean One");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Great_Unclean_One, m_Units.back())));
  m_Units.push_back("Epidemius");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Epidemius, m_Units.back())));
  m_Units.push_back("Herald of Nurgle");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Herald_of_Nurgle, m_Units.back())));
  m_Units.push_back("Plaguebearers of Nurgle");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Plaguebearers_of_Nurgle, m_Units.back())));
  m_Units.push_back("Plague Drones of Nurgle");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Plague_Drones_of_Nurgle, m_Units.back())));
  m_Units.push_back("Nurglings");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Nurglings, m_Units.back())));
  m_Units.push_back("Beasts of Nurgle");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Beasts_of_Nurgle, m_Units.back())));
  m_Units.push_back("Daemon Prince");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Daemon_Prince_in_Nurgle, m_Units.back())));
  m_Units.push_back("Furies");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Furies_in_Nurgle, m_Units.back())));
  m_Units.push_back("Soul Grinder");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Soul_Grinder_in_Nurgle, m_Units.back())));
}

const std::vector<std::string> &DaemonsOfChaosNurgleFaction::getUnits() const
{
  return m_Units;
}

void DaemonsOfChaosNurgleFaction::getWarScrolls(
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
