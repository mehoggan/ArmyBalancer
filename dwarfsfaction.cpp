#include "dwarfsfaction.h"

DwarfsFaction::DwarfsFaction() :
  IFaction(nullptr)
{
  m_Units.push_back(tr(""));
  m_Units.push_back(tr("High King Thorgrim Grudgebearer"));
  m_Units.push_back(tr("Thorek Ironbrow"));
  m_Units.push_back(tr("Kraggi"));
  m_Units.push_back(tr("Belgar Ironhammer"));
  m_Units.push_back(tr("Ungrim Ironfist the Slayer King"));
  m_Units.push_back(tr("Josef Bugman"));
  m_Units.push_back(tr("Grimm Burloksson"));
  m_Units.push_back(tr("Dwarf Lord"));
  m_Units.push_back(tr("Runelord"));
  m_Units.push_back(tr("Dragon Slayer"));
  m_Units.push_back(tr("Dwarf Engineer"));
  m_Units.push_back(tr("Thane with Battle Standard"));
  m_Units.push_back(tr("Hammerers"));
  m_Units.push_back(tr("Ironbreakers"));
  m_Units.push_back(tr("Irondrakes"));
  m_Units.push_back(tr("Longbeards"));
  m_Units.push_back(tr("Dwarf Warriors"));
  m_Units.push_back(tr("Miners"));
  m_Units.push_back(tr("Quarrellers"));
  m_Units.push_back(tr("Slayers"));
  m_Units.push_back(tr("Thunderers"));
  m_Units.push_back(tr("Gyrocopters"));
  m_Units.push_back(tr("Gyrobombers"));
  m_Units.push_back(tr("Dwarf Bolt Thrower"));
  m_Units.push_back(tr("Dwarf Cannon"));
  m_Units.push_back(tr("Flame Cannon"));
  m_Units.push_back(tr("Organ Gun"));
  m_Units.push_back(tr("Grudge Thrower"));
}

const QStringList &DwarfsFaction::getUnits()
{
  return m_Units;
}

void DwarfsFaction::buildUiForBattleScroll(QQuickView * /*ui*/, int scrollIndex)
{
  if (scrollIndex == 0) {
    return;
  }

  Q_ASSERT(scrollIndex < m_Units.size() && scrollIndex >= 0);
  WarScroll ws = WarScrollFactory::getSharedInstance().getWarScroll(getName(),
    m_Units.at(scrollIndex));
}
