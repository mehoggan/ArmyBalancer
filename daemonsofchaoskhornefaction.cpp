#include "daemonsofchaoskhornefaction.h"

namespace WarScrollGeneration
{
  WarScroll Bloodthirster_of_Insensate_Rage(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Bloodthirster_of_Unfettered_Fury(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Wrath_of_Khorne_Bloodthirster(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Skulltaker(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Herald_of_Khorne(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Herald_of_Khorne_on_Juggernaut(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Blood_Throne_of_Khorne(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Bloodletters_of_Khorne(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Bloodcrushers_of_Khorne(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Karanak(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Flesh_Hounds_of_Khorne(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Skull_Cannons_of_Khorne(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Daemon_Prince_in_Khorne(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Furies_in_Khorne(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Soul_Grinder_in_Khorne(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }
}

DaemonsOfChaosKhorneFaction::DaemonsOfChaosKhorneFaction() :
  IFaction(nullptr)
{
  m_Units.push_back("");
  m_Units.push_back("Bloodthirster of Insensate Rage");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Bloodthirster_of_Insensate_Rage,
    m_Units.back())));
  m_Units.push_back("Bloodthirster of Unfettered Fury");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Bloodthirster_of_Unfettered_Fury,
    m_Units.back())));
  m_Units.push_back("Wrath of Khorne Bloodthirster");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Wrath_of_Khorne_Bloodthirster,
    m_Units.back())));
  m_Units.push_back("Skulltaker");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Skulltaker, m_Units.back())));
  m_Units.push_back("Herald of Khorne");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Herald_of_Khorne, m_Units.back())));
  m_Units.push_back("Herald of Khorne on Juggernaut");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Herald_of_Khorne_on_Juggernaut,
    m_Units.back())));
  m_Units.push_back("Blood Throne of Khorne");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Blood_Throne_of_Khorne, m_Units.back())));
  m_Units.push_back("Bloodletters of Khorne");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Bloodletters_of_Khorne, m_Units.back())));
  m_Units.push_back("Bloodcrushers of Khorne");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Bloodcrushers_of_Khorne, m_Units.back())));
  m_Units.push_back("Karanak");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Karanak, m_Units.back())));
  m_Units.push_back("Flesh Hounds of Khorne");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Flesh_Hounds_of_Khorne, m_Units.back())));
  m_Units.push_back("Skull Cannons of Khorne");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Skull_Cannons_of_Khorne, m_Units.back())));
  m_Units.push_back("Daemon Prince");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Daemon_Prince_in_Khorne, m_Units.back())));
  m_Units.push_back("Furies");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Furies_in_Khorne, m_Units.back())));
  m_Units.push_back("Soul Grinder");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Soul_Grinder_in_Khorne, m_Units.back())));
}

const std::vector<std::string> &DaemonsOfChaosKhorneFaction::getUnits() const
{
  return m_Units;
}

void DaemonsOfChaosKhorneFaction::getWarScrolls(
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
