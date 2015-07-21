#include "vampirecountsfaction.h"

VampireCountsFaction::VampireCountsFaction() :
  IFaction(nullptr)
{
  m_Units.push_back(tr(""));
  m_Units.push_back(tr("Nagash, Supreme Lord of the Undead"));
  m_Units.push_back(tr("Arkhan the Black"));
  m_Units.push_back(tr("Mannfred, Mortarch of Night"));
  m_Units.push_back(tr("Neferata, Mortarch of Blood"));
  m_Units.push_back(tr("Morghast Harbingers"));
  m_Units.push_back(tr("Morghast Archai"));
  m_Units.push_back(tr("Vlad von Carstein"));
  m_Units.push_back(tr("Count Mannfred"));
  m_Units.push_back(tr("Konrad von Carstein"));
  m_Units.push_back(tr("Isabella von Carstein"));
  m_Units.push_back(tr("Vampire Lord"));
  m_Units.push_back(tr("Vampire Lord on Abyssal Terror"));
  m_Units.push_back(tr("Coven Throne"));
  m_Units.push_back(tr("Vargheists"));
  m_Units.push_back(tr("Blood Knights"));
  m_Units.push_back(tr("Fell Bats"));
  m_Units.push_back(tr("Bat Swarms"));
  m_Units.push_back(tr("Heinrich Kemmler, the Lichemaster"));
  m_Units.push_back(tr("Necromancer"));
  m_Units.push_back(tr("Zombies"));
  m_Units.push_back(tr("Dire Wolves"));
  m_Units.push_back(tr("Corpse Cart"));
  m_Units.push_back(tr("Mortis Engine"));
  m_Units.push_back(tr("Krell, Lord of Undeath"));
  m_Units.push_back(tr("Wight King"));
  m_Units.push_back(tr("Skeleton Warriors"));
  m_Units.push_back(tr("Grave Guard"));
  m_Units.push_back(tr("Black Knights"));
  m_Units.push_back(tr("Strigoi Ghoul King"));
  m_Units.push_back(tr("Crypt Ghouls"));
  m_Units.push_back(tr("Crypt Horrors"));
  m_Units.push_back(tr("Varghulf"));
  m_Units.push_back(tr("Cairn Wraith"));
  m_Units.push_back(tr("Tomb Banshee"));
  m_Units.push_back(tr("Spirit Hosts"));
  m_Units.push_back(tr("Hexwraiths"));
  m_Units.push_back(tr("Black Coach"));
  m_Units.push_back(tr("Terrorgheist"));
  m_Units.push_back(tr("Zombie Dragon"));
}

const QStringList &VampireCountsFaction::getUnits()
{
  return m_Units;
}

void VampireCountsFaction::buildUiForBattleScroll(QQuickView * /*ui*/, int scrollIndex)
{
  if (scrollIndex == 0) {
    return;
  }

  Q_ASSERT(scrollIndex < m_Units.size() && scrollIndex >= 0);
  WarScroll ws = WarScrollFactory::getSharedInstance().getWarScroll(getName(),
    m_Units.at(scrollIndex));
}
