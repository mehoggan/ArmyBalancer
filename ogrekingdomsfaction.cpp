#include "ogrekingdomsfaction.h"

OgreKingdomsFaction::OgreKingdomsFaction() :
  IFaction(nullptr)
{
  m_Units.push_back(tr(""));
  m_Units.push_back(tr("Greasus Goldtooth"));
  m_Units.push_back(tr("Skrag the Slaughterer"));
  m_Units.push_back(tr("Tyrant"));
  m_Units.push_back(tr("Bragg the Gutsman"));
  m_Units.push_back(tr("Bruiser Standard Bearer"));
  m_Units.push_back(tr("Butcher"));
  m_Units.push_back(tr("Ogres"));
  m_Units.push_back(tr("Ironguts"));
  m_Units.push_back(tr("Leadbelchers"));
  m_Units.push_back(tr("Gorgers"));
  m_Units.push_back(tr("Ironblaster"));
  m_Units.push_back(tr("Gnoblar Scraplauncher"));
  m_Units.push_back(tr("Gnoblar Fighters"));
  m_Units.push_back(tr("Firebelly"));
  m_Units.push_back(tr("Hunter"));
  m_Units.push_back(tr("Sabertusks"));
  m_Units.push_back(tr("Mournfang Cavalry"));
  m_Units.push_back(tr("Stonehorn"));
  m_Units.push_back(tr("Thundertusk"));
  m_Units.push_back(tr("Golgfag Maneater"));
  m_Units.push_back(tr("Maneaters"));
  m_Units.push_back(tr("Yhetees"));
  m_Units.push_back(tr("Giant"));
}

const QStringList &OgreKingdomsFaction::getUnits()
{
  return m_Units;
}

void OgreKingdomsFaction::buildUiForBattleScroll(QQuickView * /*ui*/, int scrollIndex)
{
  if (scrollIndex == 0) {
    return;
  }

  Q_ASSERT(scrollIndex < m_Units.size() && scrollIndex >= 0);
  WarScroll ws = WarScrollFactory::getSharedInstance().getWarScroll(getName(),
    m_Units.at(scrollIndex));
}
