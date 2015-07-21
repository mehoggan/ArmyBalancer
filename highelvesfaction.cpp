#include "highelvesfaction.h"

HighElvesFaction::HighElvesFaction() :
  IFaction(nullptr)
{
  m_Units.push_back(tr(""));
  m_Units.push_back(tr("Tyrion"));
  m_Units.push_back(tr("Teclis"));
  m_Units.push_back(tr("Eltharion on Stormwing"));
  m_Units.push_back(tr("Prince Imrik, Dragonlord"));
  m_Units.push_back(tr("Prince Althran"));
  m_Units.push_back(tr("High Elf Prince"));
  m_Units.push_back(tr("High Elf Prince on Griffon"));
  m_Units.push_back(tr("High Elf Prince on Dragon"));
  m_Units.push_back(tr("High Elf Archmage on Dragon"));
  m_Units.push_back(tr("High Elf Mage"));
  m_Units.push_back(tr("Dragon Mage"));
  m_Units.push_back(tr("High Elf Spearmen"));
  m_Units.push_back(tr("High Elf Archers"));
  m_Units.push_back(tr("Silver Helms"));
  m_Units.push_back(tr("Ellyrian Reavers"));
  m_Units.push_back(tr("Dragon Princes of Caledor"));
  m_Units.push_back(tr("Tiranoc Chariots"));
  m_Units.push_back(tr("High Elf Repeater Bolt Thrower"));
  m_Units.push_back(tr("Great Eagles"));
  m_Units.push_back(tr("Alith Anar, The Shadow King"));
  m_Units.push_back(tr("Shadow Warriors"));
  m_Units.push_back(tr("Alarielle the Radiant"));
  m_Units.push_back(tr("Handmaiden of the Everqueen"));
  m_Units.push_back(tr("Sisters of Avelorn"));
  m_Units.push_back(tr("Caradryan"));
  m_Units.push_back(tr("Anointed of Asuryan"));
  m_Units.push_back(tr("Phoenix Guard"));
  m_Units.push_back(tr("Flamespyre Phoenix"));
  m_Units.push_back(tr("Frostheart Phoenix"));
  m_Units.push_back(tr("Loremaster of Hoeth"));
  m_Units.push_back(tr("High Elf Swordmasters of Hoeth"));
  m_Units.push_back(tr("Korhil"));
  m_Units.push_back(tr("White Lions of Chrace"));
  m_Units.push_back(tr("White Lion Chariots"));
  m_Units.push_back(tr("Lothern Sea Helm"));
  m_Units.push_back(tr("Lothern Sea Helm on Skycutter"));
  m_Units.push_back(tr("Lothern Sea Guard"));
  m_Units.push_back(tr("Lothern Skycutters"));
}

const QStringList &HighElvesFaction::getUnits()
{
  return m_Units;
}

void HighElvesFaction::buildUiForBattleScroll(QQuickView * /*ui*/, int scrollIndex)
{
  if (scrollIndex == 0) {
    return;
  }

  Q_ASSERT(scrollIndex < m_Units.size() && scrollIndex >= 0);
  WarScroll ws = WarScrollFactory::getSharedInstance().getWarScroll(getName(),
    m_Units.at(scrollIndex));
}
