#include "khornebloodboundfaction.h"

namespace WarScrollGeneration
{
  WarScroll Blood_Warriors(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eChaos);

    return ws;
  }

  WarScroll Bloodreavers(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eChaos);

    return ws;
  }

  WarScroll Bloodsecrators(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eChaos);

    return ws;
  }

  WarScroll Bloodstokers(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eChaos);

    return ws;
  }

  WarScroll Exalted_Deathbringer(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eChaos);

    return ws;
  }

  WarScroll Khorgoraths(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eChaos);

    return ws;
  }

  WarScroll Mighty_Lord_of_Khorne(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eChaos);

    return ws;
  }

  WarScroll Wrathmongers_in_Khorne_Bloodbound(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eChaos);

    return ws;
  }
}

KhorneBloodboundFaction::KhorneBloodboundFaction() :
  IFaction()
{
  m_Units.push_back("");

  m_Units.push_back("Blood Warriors");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Blood_Warriors,
    m_Units.back())));

  m_Units.push_back("Bloodreavers");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Bloodreavers,
    m_Units.back())));

  m_Units.push_back("Bloodsecrators");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Bloodsecrators,
    m_Units.back())));

  m_Units.push_back("Bloodstokers");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Bloodstokers,
    m_Units.back())));

  m_Units.push_back("Exalted Deathbringer");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Exalted_Deathbringer,
    m_Units.back())));

  m_Units.push_back("Khorgoraths");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Khorgoraths,
    m_Units.back())));

  m_Units.push_back("Mighty Lord of Khorne");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Mighty_Lord_of_Khorne,
    m_Units.back())));

  m_Units.push_back("Wrathmongers");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Wrathmongers_in_Khorne_Bloodbound,
    m_Units.back())));

  std::sort(m_Units.begin(), m_Units.end());
}

const std::vector<std::string> &KhorneBloodboundFaction::getUnits() const
{
  return m_Units;
}

void KhorneBloodboundFaction::getWarScrolls(std::list<WarScroll>& warScrolls)
{
  for (const std::string &unit : m_Units) {
    if (unit.empty()) {
      continue;
    }
    WarScroll ws = m_NameToWarScroll[unit](unit);
    warScrolls.push_back(ws);
  }
}
