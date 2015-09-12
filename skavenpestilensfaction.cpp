#include "skavenpestilensfaction.h"

namespace WarScrollGeneration
{
  WarScroll Plague_Censer_Bearers_in_SkavenPestilensFaction(
    const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eChaos);

    return ws;
  }

  WarScroll Plague_Furnace_in_SkavenPestilensFaction(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eChaos);

    return ws;
  }

  WarScroll Plague_Monks_in_SkavenPestilensFaction(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eChaos);

    return ws;
  }

  WarScroll Plague_Priest_in_SkavenPestilensFaction(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eChaos);

    return ws;
  }

  WarScroll Plague_Priest_with_Plague(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eChaos);

    return ws;
  }

  WarScroll Plagueclaw_Catapult(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eChaos);

    return ws;
  }

  WarScroll Verminlord_Corruptor_in_SkavenPestilensFaction(
    const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eChaos);

    return ws;
  }
}

SkavenPestilensFaction::SkavenPestilensFaction() :
  IFaction()
{
  m_Units.push_back("");
  m_Units.push_back("Plague Censer Bearers");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(
    &WarScrollGeneration::Plague_Censer_Bearers_in_SkavenPestilensFaction,
    m_Units.back())));
  m_Units.push_back("Plague Furnace");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Plague_Furnace_in_SkavenPestilensFaction,
    m_Units.back())));
  m_Units.push_back("Plague Monks");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Plague_Monks_in_SkavenPestilensFaction,
    m_Units.back())));
  m_Units.push_back("Plague Priest");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Plague_Priest_in_SkavenPestilensFaction,
    m_Units.back())));
  m_Units.push_back("Plague Priest with Plague");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Plague_Priest_with_Plague,
    m_Units.back())));
  m_Units.push_back("Plagueclaw Catapult");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Plagueclaw_Catapult,
    m_Units.back())));
  m_Units.push_back("Verminlord Corruptor");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(
      &WarScrollGeneration::Verminlord_Corruptor_in_SkavenPestilensFaction,
    m_Units.back())));

  std::sort(m_Units.begin(), m_Units.end());
}

const std::vector<std::string> &SkavenPestilensFaction::getUnits() const
{
  return m_Units;
}

void SkavenPestilensFaction::getWarScrolls(std::list<WarScroll>& warScrolls)
{
  for (const std::string &unit : m_Units) {
    if (unit.empty()) {
      continue;
    }
    WarScroll ws = m_NameToWarScroll[unit](unit);
    warScrolls.push_back(ws);
  }
}
