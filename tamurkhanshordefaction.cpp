#include "tamurkhanshordefaction.h"

namespace WarScrollGeneration
{
  WarScroll Bile_Trolls(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eOrder);

    return ws;
  }

  WarScroll Chaos_War_Mammoth(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eOrder);

    return ws;
  }

  WarScroll Daemon_Plague_Toads_of_Nurgle(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eOrder);

    return ws;
  }

  WarScroll Daemon_Pox_Riders_of_Nurgle(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eOrder);

    return ws;
  }

  WarScroll Gigantic_Chaos_Spawn(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eOrder);

    return ws;
  }

  WarScroll Kayzk_the_Befouled(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eOrder);

    return ws;
  }

  WarScroll Nightmaw(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eOrder);

    return ws;
  }

  WarScroll Plague_Ogres(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eOrder);

    return ws;
  }

  WarScroll Sayl_the_Faithless(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eOrder);

    return ws;
  }

  WarScroll Tamurkhan_the_Maggot_Lord(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eOrder);

    return ws;
  }
}

TamurkhansHordeFaction::TamurkhansHordeFaction() :
  IFaction()
{
  m_Units.push_back("");
  m_Units.push_back("Bile Trolls");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Bile_Trolls, m_Units.back())));
  m_Units.push_back("Chaos War Mammoth");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Chaos_War_Mammoth, m_Units.back())));
  m_Units.push_back("Daemon_Plague Toads of Nurgle");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Daemon_Plague_Toads_of_Nurgle,
    m_Units.back())));
  m_Units.push_back("Daemon Pox Riders of Nurgle");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Daemon_Pox_Riders_of_Nurgle,
    m_Units.back())));
  m_Units.push_back("Gigantic Chaos Spawn");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Gigantic_Chaos_Spawn, m_Units.back())));
  m_Units.push_back("Kayzk the Befouled");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Kayzk_the_Befouled, m_Units.back())));
  m_Units.push_back("Nightmaw");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Nightmaw, m_Units.back())));
  m_Units.push_back("Plague Ogres");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Plague_Ogres, m_Units.back())));
  m_Units.push_back("Sayl the Faithless");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Sayl_the_Faithless, m_Units.back())));
  m_Units.push_back("Tamurkhan The Maggot Lord");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Tamurkhan_the_Maggot_Lord,
    m_Units.back())));

  std::sort(m_Units.begin(), m_Units.end());
}

const std::vector<std::string> &TamurkhansHordeFaction::getUnits() const
{
  return m_Units;
}

void TamurkhansHordeFaction::getWarScrolls(std::list<WarScroll>& warScrolls)
{
  for (const std::string &unit : m_Units) {
    if (unit.empty()) {
      continue;
    }
    WarScroll ws = m_NameToWarScroll[unit](unit);
    warScrolls.push_back(ws);
  }
}
