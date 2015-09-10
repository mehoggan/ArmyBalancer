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
