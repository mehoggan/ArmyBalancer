#include "stormcasteternalsfaction.h"

namespace WarScrollGeneration
{
  WarScroll Celestant_Prime(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eOrder);

    return ws;
  }

  WarScroll Decimators(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eOrder);

    return ws;
  }

  WarScroll Gryph_Hounds(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eOrder);

    return ws;
  }

  WarScroll Judicators(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eOrder);

    return ws;
  }

  WarScroll Knight_Azyros(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eOrder);

    return ws;
  }

  WarScroll Knight_Venator(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eOrder);

    return ws;
  }

  WarScroll Liberators(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eOrder);

    return ws;
  }

  WarScroll Lord_Castellant(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eOrder);

    return ws;
  }

  
  WarScroll Lord_Celestant(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eOrder);

    return ws;
  }

  WarScroll Lord_Celestant_on_Dracoth(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eOrder);

    return ws;
  }

  WarScroll Lord_Relictor(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eOrder);

    return ws;
  }

  WarScroll Prosecutors_with_Celestial(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eOrder);

    return ws;
  }

  WarScroll Prosecutors_with_Stormcall(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eOrder);

    return ws;
  }

  WarScroll Protectors(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eOrder);

    return ws;
  }

  WarScroll Retributors(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eOrder);

    return ws;
  }
}

StormCastEternalsFaction::StormCastEternalsFaction() :
  IFaction()
{
  m_Units.push_back("");
  m_Units.push_back("Celestant-Prime");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Celestant_Prime, m_Units.back())));
  m_Units.push_back("Decimators");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Decimators, m_Units.back())));
  m_Units.push_back("Gryph-Hounds");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Gryph_Hounds, m_Units.back())));
  m_Units.push_back("Judicators");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Judicators, m_Units.back())));
  m_Units.push_back("Knight-Azyros");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Knight_Azyros, m_Units.back())));
  m_Units.push_back("Knight-Venator");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Knight_Venator, m_Units.back())));
  m_Units.push_back("Liberators");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Liberators, m_Units.back())));
  m_Units.push_back("Lord-Castellant");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Lord_Castellant, m_Units.back())));
  m_Units.push_back("Lord-Celestant");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Lord_Celestant, m_Units.back())));
  m_Units.push_back("Lord-Celestant on Dracoth");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Lord_Celestant_on_Dracoth,
    m_Units.back())));
  m_Units.push_back("Lord-Relictor");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Lord_Relictor, m_Units.back())));
  m_Units.push_back("Prosecutors with Celestial");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Prosecutors_with_Celestial,
    m_Units.back())));
  m_Units.push_back("Prosecutors with Stormcall");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Prosecutors_with_Stormcall,
    m_Units.back())));
  m_Units.push_back("Protectors");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Protectors, m_Units.back())));
  m_Units.push_back("Retributors");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Retributors, m_Units.back())));

  std::sort(m_Units.begin(), m_Units.end());
}

const std::vector<std::string> &StormCastEternalsFaction::getUnits() const
{
  return m_Units;
}

void StormCastEternalsFaction::getWarScrolls(std::list<WarScroll>& warScrolls)
{
  for (const std::string &unit : m_Units) {
    if (unit.empty()) {
      continue;
    }
    WarScroll ws = m_NameToWarScroll[unit](unit);
    warScrolls.push_back(ws);
  }
}
