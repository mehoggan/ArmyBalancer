#include "thelegionofazgorhfaction.h"

namespace WarScrollGeneration
{
  WarScroll Bull_Centaur_Renders(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eOrder);

    return ws;
  }

  WarScroll Bull_Centaur_Taur_uk(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eOrder);

    return ws;
  }

  WarScroll Chaos_Siege_Giant(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eOrder);

    return ws;
  }

  WarScroll Daemonsmith(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eOrder);

    return ws;
  }

  WarScroll Deathshrieker_Rocket(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eOrder);

    return ws;
  }

  WarScroll Drazhoath_the_Ashen(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eOrder);

    return ws;
  }

  WarScroll Dreadquake_Mortar(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eOrder);

    return ws;
  }

  WarScroll Infernal_Guard_Battle_Standard(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eOrder);

    return ws;
  }

  WarScroll Infernal_Guard_Castellan(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eOrder);

    return ws;
  }

  WarScroll Infernal_Guard_Fireglaives(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eOrder);

    return ws;
  }

  WarScroll Infernal_Guard_Ironsworn(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eOrder);

    return ws;
  }

  WarScroll Iron_Daemon_War_Engine(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eOrder);

    return ws;
  }

  WarScroll K_daai_Fireborn(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eOrder);

    return ws;
  }

  WarScroll Magma_Cannon(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eOrder);

    return ws;
  }

  WarScroll Skullcracker_War_Engine(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eOrder);

    return ws;
  }
}

TheLegionOfAzgorhFaction::TheLegionOfAzgorhFaction() :
  IFaction()
{
  m_Units.push_back("");
  m_Units.push_back("Bull Centaur Renders");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Bull_Centaur_Renders, m_Units.back())));
  m_Units.push_back("Bull Centaur Taur'uk");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Bull_Centaur_Taur_uk, m_Units.back())));
  m_Units.push_back("Chaos Siege Giant");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Chaos_Siege_Giant, m_Units.back())));
  m_Units.push_back("Daemonsmith");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Daemonsmith, m_Units.back())));
  m_Units.push_back("Deathshrieker Rocket");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Deathshrieker_Rocket, m_Units.back())));
  m_Units.push_back("Drazhoath the Ashen");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Drazhoath_the_Ashen, m_Units.back())));
  m_Units.push_back("Dreadquake Mortar");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Dreadquake_Mortar, m_Units.back())));
  m_Units.push_back("Infernal Guard Battle Standard");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Infernal_Guard_Battle_Standard,
    m_Units.back())));
  m_Units.push_back("Infernal Guard Castellan");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Infernal_Guard_Castellan,
    m_Units.back())));
  m_Units.push_back("Infernal Guard Fireglaives");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Infernal_Guard_Fireglaives,
    m_Units.back())));
  m_Units.push_back("Infernal Guard Ironsworn");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Infernal_Guard_Ironsworn, m_Units.back())));
  m_Units.push_back("Iron Daemon War Engine");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Iron_Daemon_War_Engine, m_Units.back())));
  m_Units.push_back("K'daai Fireborn");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::K_daai_Fireborn, m_Units.back())));
  m_Units.push_back("Magma Cannon");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Magma_Cannon, m_Units.back())));
  m_Units.push_back("Skullcracker War Engine");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Skullcracker_War_Engine, m_Units.back())));

  std::sort(m_Units.begin(), m_Units.end());
}

const std::vector<std::string> &TheLegionOfAzgorhFaction::getUnits() const
{
  return m_Units;
}

void TheLegionOfAzgorhFaction::getWarScrolls(std::list<WarScroll>& warScrolls)
{
  for (const std::string &unit : m_Units) {
    if (unit.empty()) {
      continue;
    }
    WarScroll ws = m_NameToWarScroll[unit](unit);
    warScrolls.push_back(ws);
  }
}
