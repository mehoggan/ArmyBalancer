#include "nurglerotbringersfaction.h"

namespace WarScrollGeneration
{
  WarScroll Chaos_Spawn_in_Nurgle_Rotbringers(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eChaos);

    return ws;
  }

  WarScroll Bloab_Rotspawned_in_Nurgle_Rotbringers(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eChaos);

    return ws;
  }

  WarScroll Festus_the_Leechlord_in_Nurgle_Rotbringers(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eChaos);

    return ws;
  }

  WarScroll Gutrot_Spume_in_Nurgle_Rotbringers(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eChaos);

    return ws;
  }

  WarScroll Harbinger_of_Decay(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eChaos);

    return ws;
  }

  WarScroll Lord_of_Plagues(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eChaos);

    return ws;
  }

  WarScroll Morbidex_Twiceborn_in_Nurgle_Rotbringers(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eChaos);

    return ws;
  }

  WarScroll Orghotts_Daemonspew_in_Nurgle_Rotbringers(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eChaos);

    return ws;
  }

  WarScroll Putrid_Blightkings_in_Nurgle_Rotbringers(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eChaos);

    return ws;
  }

  WarScroll Rotbringers_Sorceror(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eChaos);

    return ws;
  }

  WarScroll The_Glotkin(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eChaos);

    return ws;
  }
}

NurgleRotbringersFaction::NurgleRotbringersFaction() :
  IFaction()
{
  m_Units.push_back("");
  m_Units.push_back("Chaos Spawn");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Chaos_Spawn_in_Nurgle_Rotbringers,
    m_Units.back())));
  m_Units.push_back("Bloab Rotspawned");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Bloab_Rotspawned_in_Nurgle_Rotbringers,
    m_Units.back())));
  m_Units.push_back("Festus the Leechlord");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Festus_the_Leechlord_in_Nurgle_Rotbringers,
    m_Units.back())));
  m_Units.push_back("Gutrot Spume");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Gutrot_Spume_in_Nurgle_Rotbringers,
    m_Units.back())));
  m_Units.push_back("Harbinger of Decay");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Harbinger_of_Decay,
    m_Units.back())));
  m_Units.push_back("Lord of Plagues");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Lord_of_Plagues,
    m_Units.back())));
  m_Units.push_back("Morbidex Twiceborn");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Morbidex_Twiceborn_in_Nurgle_Rotbringers,
    m_Units.back())));
  m_Units.push_back("Orghotts Deamonspew");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Orghotts_Daemonspew_in_Nurgle_Rotbringers,
    m_Units.back())));
  m_Units.push_back("Putrid Blightkings");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Putrid_Blightkings_in_Nurgle_Rotbringers,
    m_Units.back())));
  m_Units.push_back("Rotbringers Sorceror");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Rotbringers_Sorceror,
    m_Units.back())));
  m_Units.push_back("The Glottkin");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::The_Glotkin,
    m_Units.back())));

  std::sort(m_Units.begin(), m_Units.end());
}

const std::vector<std::string> &NurgleRotbringersFaction::getUnits() const
{
  return m_Units;
}

void NurgleRotbringersFaction::getWarScrolls(std::list<WarScroll>& warScrolls)
{
  for (const std::string &unit : m_Units) {
    if (unit.empty()) {
      continue;
    }
    WarScroll ws = m_NameToWarScroll[unit](unit);
    warScrolls.push_back(ws);
  }
}
