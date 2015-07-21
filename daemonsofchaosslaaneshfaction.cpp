#include "daemonsofchaosslaaneshfaction.h"

DaemonsOfChaosSlaaneshFaction::DaemonsOfChaosSlaaneshFaction() :
  IFaction(nullptr)
{
  m_Units.push_back(tr(""));
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

const QStringList &DaemonsOfChaosSlaaneshFaction::getUnits()
{
  return m_Units;
}

void DaemonsOfChaosSlaaneshFaction::buildUiForBattleScroll(QQuickView * /*ui*/,
  int scrollIndex)
{
  if (scrollIndex == 0) {
    return;
  }

  Q_ASSERT(scrollIndex < m_Units.size() && scrollIndex >= 0);
  WarScroll ws = WarScrollFactory::getSharedInstance().getWarScroll(getName(),
    m_Units.at(scrollIndex));
}
