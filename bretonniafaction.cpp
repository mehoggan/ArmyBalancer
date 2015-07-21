#include "bretonniafaction.h"

BretonniaFaction::BretonniaFaction() :
  IFaction(nullptr)
{
  m_Units.push_back(tr(""));
  m_Units.push_back(tr("King Louen Leoncoeur"));
  m_Units.push_back(tr("The Fay Enchantress"));
  m_Units.push_back(tr("The Green Knight"));
  m_Units.push_back(tr("Bretonnian Lord"));
  m_Units.push_back(tr("Paladin"));
  m_Units.push_back(tr("Paladin Standard Bearer"));
  m_Units.push_back(tr("Damsel of the Lady"));
  m_Units.push_back(tr("Knights Errant"));
  m_Units.push_back(tr("Knights of the Realm"));
  m_Units.push_back(tr("Questing Knights"));
  m_Units.push_back(tr("Grail Knights"));
  m_Units.push_back(tr("Pegasus Knights"));
  m_Units.push_back(tr("Battle Pilgrims"));
  m_Units.push_back(tr("Men-at-Arms"));
  m_Units.push_back(tr("Peasant Bowmen"));
  m_Units.push_back(tr("Mounted Yeomen"));
  m_Units.push_back(tr("Field Trebuchet"));
}

const QStringList &BretonniaFaction::getUnits()
{
  return m_Units;
}

void BretonniaFaction::buildUiForBattleScroll(QQuickView * /*ui*/, int scrollIndex)
{
  if (scrollIndex == 0) {
    return;
  }

  Q_ASSERT(scrollIndex < m_Units.size() && scrollIndex >= 0);
  WarScroll ws = WarScrollFactory::getSharedInstance().getWarScroll(getName(),
    m_Units.at(scrollIndex));
}
