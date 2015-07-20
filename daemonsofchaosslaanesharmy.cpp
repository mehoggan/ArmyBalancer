#include "daemonsofchaosslaanesharmy.h"

DaemonsOfChaosSlaaneshArmy::DaemonsOfChaosSlaaneshArmy() :
  IArmy(nullptr)
{
  m_Units.push_back(tr("Keeper of Secrets"));
  m_Units.push_back(tr("The Masque of Slaanesh"));
  m_Units.push_back(tr("Herald of Slaanesh"));
  m_Units.push_back(tr("Herald of Slaanesh on Seeker Chariot"));
  m_Units.push_back(tr("Herald of Slaanesh on Exalted Seeker Chariot"));
  m_Units.push_back(tr("Daemonettes of Slaanesh"));
  m_Units.push_back(tr("Seekers of Slaanesh"));
  m_Units.push_back(tr("Fiends of Slaanesh"));
  m_Units.push_back(tr("Seeker Chariots of Slaanesh"));
  m_Units.push_back(tr("Exalted Seeker Chariots of Slaanesh"));
  m_Units.push_back(tr("Hellflayers of Slaanesh"));
  m_Units.push_back(tr("Daemon Prince"));
  m_Units.push_back(tr("Furies"));
  m_Units.push_back(tr("Soul Grinder"));
}

const QStringList &DaemonsOfChaosSlaaneshArmy::getUnits()
{
  return m_Units;
}

void DaemonsOfChaosSlaaneshArmy::buildUiForBattleScroll(QQuickView *ui,
  int scrollIndex)
{

}
