#include "daemonsofchaostzeentcharmy.h"

DaemonsOfChaosTzeentchArmy::DaemonsOfChaosTzeentchArmy() :
  IArmy(nullptr)
{
  m_Units.push_back(tr("Kairos Fateweaver"));
  m_Units.push_back(tr("Lord of Change"));
  m_Units.push_back(tr("The Changeling"));
  m_Units.push_back(tr("Herald of Tzeentch"));
  m_Units.push_back(tr("Herald of Tzeentch on Disc of Tzeentch"));
  m_Units.push_back(tr("Herald of Tzeentch on Burning Chariot"));
  m_Units.push_back(tr("The Blue Scribes"));
  m_Units.push_back(tr("Pink Horrors of Tzeentch"));
  m_Units.push_back(tr("Exalted Flamers"));
  m_Units.push_back(tr("Flamers of Tzeentch"));
  m_Units.push_back(tr("Screamers of Tzeentch"));
  m_Units.push_back(tr("Burning Chariots of Tzeeentch"));
  m_Units.push_back(tr("Daemon Prince"));
  m_Units.push_back(tr("Furies"));
  m_Units.push_back(tr("Soul Grinder"));
}

const QStringList &DaemonsOfChaosTzeentchArmy::getUnits()
{
  return m_Units;
}

void DaemonsOfChaosTzeentchArmy::buildUiForBattleScroll(QQuickView *ui,
  int scrollIndex)
{

}
