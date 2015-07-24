#include "daemonsofchaostzeentchfaction.h"

namespace WarScrollGeneration
{
  WarScroll Kairos_Fateweaver(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Lord_of_Change(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll The_Changeling(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Herald_of_Tzeentch(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Herald_of_Tzeentch_on_Disc_of_Tzeentch(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Herald_of_Tzeentch_on_Burning_Chariot(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll The_Blue_Scribes(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Pink_Horrors_of_Tzeentch(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Exalted_Flamers(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Flamers_of_Tzeentch(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Screamers_of_Tzeentch(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Burning_Chariots_of_Tzeeentch(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Daemon_Prince_in_Tzeentch(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Furies_in_Tzeentch(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Soul_Grinder_in_Tzeentch(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }
}

DaemonsOfChaosTzeentchFaction::DaemonsOfChaosTzeentchFaction() :
  IFaction(nullptr)
{
  m_Units.push_back("");
  m_Units.push_back("Kairos Fateweaver");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Kairos_Fateweaver, m_Units.back())));
  m_Units.push_back("Lord of Change");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Lord_of_Change, m_Units.back())));
  m_Units.push_back("The Changeling");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::The_Changeling, m_Units.back())));
  m_Units.push_back("Herald of Tzeentch");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Herald_of_Tzeentch, m_Units.back())));
  m_Units.push_back("Herald of Tzeentch on Disc of Tzeentch");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Herald_of_Tzeentch_on_Disc_of_Tzeentch,
    m_Units.back())));
  m_Units.push_back("Herald of Tzeentch on Burning Chariot");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Herald_of_Tzeentch_on_Burning_Chariot,
    m_Units.back())));
  m_Units.push_back("The Blue Scribes");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::The_Blue_Scribes, m_Units.back())));
  m_Units.push_back("Pink Horrors of Tzeentch");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Pink_Horrors_of_Tzeentch, m_Units.back())));
  m_Units.push_back("Exalted Flamers");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Exalted_Flamers, m_Units.back())));
  m_Units.push_back("Flamers of Tzeentch");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Flamers_of_Tzeentch, m_Units.back())));
  m_Units.push_back("Screamers of Tzeentch");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Screamers_of_Tzeentch, m_Units.back())));
  m_Units.push_back("Burning Chariots of Tzeeentch");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Burning_Chariots_of_Tzeeentch,
    m_Units.back())));
  m_Units.push_back("Daemon Prince");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Daemon_Prince_in_Tzeentch,
    m_Units.back())));
  m_Units.push_back("Furies");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Furies_in_Tzeentch, m_Units.back())));
  m_Units.push_back("Soul Grinder");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Soul_Grinder_in_Tzeentch, m_Units.back())));
}

const std::vector<std::string> &DaemonsOfChaosTzeentchFaction::getUnits() const
{
  return m_Units;
}

void DaemonsOfChaosTzeentchFaction::getWarScrolls(
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
