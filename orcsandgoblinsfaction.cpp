#include "orcsandgoblinsfaction.h"

OrcsAndGoblinsFaction::OrcsAndGoblinsFaction() :
  IFaction(nullptr)
{
  m_Units.push_back(tr(""));
  m_Units.push_back(tr("Gorbad Ironclaw"));
  m_Units.push_back(tr("Azhag the Slaughterer"));
  m_Units.push_back(tr("Orc Warboss"));
  m_Units.push_back(tr("Orc Warboss on Wyvern"));
  m_Units.push_back(tr("Orc Great Shaman"));
  m_Units.push_back(tr("Orc Bully"));
  m_Units.push_back(tr("Orcs"));
  m_Units.push_back(tr("Orc Arrer Boyz"));
  m_Units.push_back(tr("Orc Boar Chariots"));
  m_Units.push_back(tr("Ruglud's Armoureed Orcs"));
  m_Units.push_back(tr("Grimgor Ironhide"));
  m_Units.push_back(tr("Black Orc Big Boss"));
  m_Units.push_back(tr("Black Orcs"));
  m_Units.push_back(tr("Wurrzag, da Great Green Prophet"));
  m_Units.push_back(tr("Savage Orc Warboss"));
  m_Units.push_back(tr("Savage Orc Shaman"));
  m_Units.push_back(tr("Savage Orcs"));
  m_Units.push_back(tr("Savage Orc Boar Boyz"));
  m_Units.push_back(tr("Grom the Paunch"));
  m_Units.push_back(tr("Goblin Warboss"));
  m_Units.push_back(tr("Goblin Shaman"));
  m_Units.push_back(tr("Goblins"));
  m_Units.push_back(tr("Goblin Wolf Riders"));
  m_Units.push_back(tr("Goblin Wold Chariots"));
  m_Units.push_back(tr("Goblin Spear Chukka"));
  m_Units.push_back(tr("Goblin Rock Lobber"));
  m_Units.push_back(tr("Doom Diver Catapult"));
  m_Units.push_back(tr("Nasty Skulkers"));
  m_Units.push_back(tr("Skarsnik, Warlord of the Eight Peaks"));
  m_Units.push_back(tr("Night Goblin Warboss"));
  m_Units.push_back(tr("Night Goblin Warboss on Great Cave Squig"));
  m_Units.push_back(tr("Night Goblin Shaman"));
  m_Units.push_back(tr("Night Goblins"));
  m_Units.push_back(tr("Night Goblin Fanatics"));
  m_Units.push_back(tr("Night Goblin Squig Hoppers"));
  m_Units.push_back(tr("Night Goblin Squig Herders"));
  m_Units.push_back(tr("Mangler Squigs"));
  m_Units.push_back(tr("Cave Squigs"));
  m_Units.push_back(tr("Goblin Big Boss on Gigantic Spider"));
  m_Units.push_back(tr("Forest Goblin Spider Riders"));
  m_Units.push_back(tr("Arachnarok Spider"));
  m_Units.push_back(tr("Snotlings"));
  m_Units.push_back(tr("Snotling Pump Wagon"));
  m_Units.push_back(tr("Trolls"));
  m_Units.push_back(tr("Stone Troll"));
  m_Units.push_back(tr("River Trolls"));
  m_Units.push_back(tr("Giant"));
}

const QStringList &OrcsAndGoblinsFaction::getUnits()
{
  return m_Units;
}

void OrcsAndGoblinsFaction::buildUiForBattleScroll(QQuickView * /*ui*/, int scrollIndex)
{
  if (scrollIndex == 0) {
    return;
  }

  Q_ASSERT(scrollIndex < m_Units.size() && scrollIndex >= 0);
  WarScroll ws = WarScrollFactory::getSharedInstance().getWarScroll(getName(),
    m_Units.at(scrollIndex));
}
