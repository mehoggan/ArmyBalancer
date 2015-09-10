#include "stormcasteternalsfaction.h"

namespace WarScrollGeneration
{
  WarScroll Celestant_Prime(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    //ws.setCharacteristics(10, 14, 10, 4);
    //ws.setCanFly(true);

    //ws.addWeapon(WarScroll::Weapon("Great Axe of Khorne", 2, 4, 4, 2, 2, 6));

    //ws.addAbility(WarScroll::Ability("Rage Unbound", 1));
    //ws.addAbility(WarScroll::Ability("Outrageous Carnage", 2));
    //ws.addAbility(WarScroll::Ability("Bloodthirsty Charge", 2, true));

    //ws.addKeyWords({"CHAOS", "DAEMON", "KHORNE", "MONSTER", "HERO",
    //  "BLOODTHIRSTER OF INSENSATE RAGE"});

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eOrder);

    //ws.addKeyWordConnection(WarScroll::KeyWordConnection("KHORNE and DAEMON",
    //  8, WarScroll::Ability("Bloodthirsty Charge", 2, true), 1,
    //  WarScroll::KeyWordConnection::ConnectionAffectType::eFriendly,
    //  WarScroll::Spell()));
    //WarScroll::addSummonable(ws, name, 10, 3, 16, 1, {"CHAOS", "WIZARD"});

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
