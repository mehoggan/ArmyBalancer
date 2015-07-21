#include "skavenfaction.h"

SkavenFaction::SkavenFaction() :
  IFaction(nullptr)
{
  m_Units.push_back(tr(""));
  m_Units.push_back(tr("Thanquol and Boneripper"));
  m_Units.push_back(tr("Skaven Grey Seer"));
  m_Units.push_back(tr("Screaming Bell"));
  m_Units.push_back(tr("Lord Skreech Verminking"));
  m_Units.push_back(tr("Verminlord Warbriner"));
  m_Units.push_back(tr("Verminlord Corruptor"));
  m_Units.push_back(tr("Verminlord Deceiver"));
  m_Units.push_back(tr("Verminlord Warpseer"));
  m_Units.push_back(tr("Queek Headtaker"));
  m_Units.push_back(tr("Warlord Spinetail"));
  m_Units.push_back(tr("Tretch Craventail"));
  m_Units.push_back(tr("Skaven Warlord"));
  m_Units.push_back(tr("Skaven Chieftain with Battle Standard"));
  m_Units.push_back(tr("Clanrats"));
  m_Units.push_back(tr("Stormvermin"));
  m_Units.push_back(tr("Skavenslaves"));
  m_Units.push_back(tr("Ikit Claw"));
  m_Units.push_back(tr("Warlock Engineer"));
  m_Units.push_back(tr("Doom-Flayer Weapon Team"));
  m_Units.push_back(tr("Ratling Gun Weapon Team"));
  m_Units.push_back(tr("Warpfire Thrower Weapon Team"));
  m_Units.push_back(tr("Warp-Grinder Weapon Team"));
  m_Units.push_back(tr("Poisoned Wind Mortar Weapon Team"));
  m_Units.push_back(tr("Poisoned Wind Globadiers"));
  m_Units.push_back(tr("Warplock Jezzails"));
  m_Units.push_back(tr("Doomwheel"));
  m_Units.push_back(tr("Warp Lightning Cannon"));
  m_Units.push_back(tr("Stormfiends"));
  m_Units.push_back(tr("Throt the Unclean"));
  m_Units.push_back(tr("Packmaster Skweel Gnawtooth"));
  m_Units.push_back(tr("Packmaster"));
  m_Units.push_back(tr("Giant Rats"));
  m_Units.push_back(tr("Rat Swarms"));
  m_Units.push_back(tr("Rat Ogres"));
  m_Units.push_back(tr("Hell Pit Abomination"));
  m_Units.push_back(tr("Lord Skrolk"));
  m_Units.push_back(tr("Plague Priest"));
  m_Units.push_back(tr("Plague Furnace"));
  m_Units.push_back(tr("Plague Monks"));
  m_Units.push_back(tr("Plague Censer Bearers"));
  m_Units.push_back(tr("PlagueClaw Catapult"));
  m_Units.push_back(tr("Deathmaster Snikch"));
  m_Units.push_back(tr("Skaven Assassin"));
  m_Units.push_back(tr("Night Runners"));
  m_Units.push_back(tr("Gutter Runners"));
}

const QStringList &SkavenFaction::getUnits()
{
  return m_Units;
}

void SkavenFaction::buildUiForBattleScroll(QQuickView * /*ui*/, int scrollIndex)
{
  if (scrollIndex == 0) {
    return;
  }

  Q_ASSERT(scrollIndex < m_Units.size() && scrollIndex >= 0);
  WarScroll ws = WarScrollFactory::getSharedInstance().getWarScroll(getName(),
    m_Units.at(scrollIndex));
}
