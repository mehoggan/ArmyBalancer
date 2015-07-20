#include "ogrekingdomsarmy.h"

OgreKingdomsArmy::OgreKingdomsArmy() :
  IArmy(nullptr)
{
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

const QStringList &OgreKingdomsArmy::getUnits()
{
  return m_Units;
}

void OgreKingdomsArmy::buildUiForBattleScroll(QQuickView *ui, int scrollIndex)
{

}
