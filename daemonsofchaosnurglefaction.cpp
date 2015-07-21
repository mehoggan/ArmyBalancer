#include "daemonsofchaosnurglefaction.h"

DaemonsOfChaosNurgleFaction::DaemonsOfChaosNurgleFaction() :
  IFaction(nullptr)
{
  m_Units.push_back(tr(""));
  m_Units.push_back(tr("Great Unclean One"));
  m_Units.push_back(tr("Epidemius"));
  m_Units.push_back(tr("Herald of Nurgle"));
  m_Units.push_back(tr("Plaguebearers of Nurgle"));
  m_Units.push_back(tr("Plague Drones of Nurgle"));
  m_Units.push_back(tr("Nurglings"));
  m_Units.push_back(tr("Beasts of Nurgle"));
  m_Units.push_back(tr("Daemon Prince"));
  m_Units.push_back(tr("Furies"));
  m_Units.push_back(tr("Soul Grinder"));
}

const QStringList &DaemonsOfChaosNurgleFaction::getUnits()
{
  return m_Units;
}

void DaemonsOfChaosNurgleFaction::buildUiForBattleScroll(QQuickView * /*ui*/,
  int scrollIndex)
{
  if (scrollIndex == 0) {
    return;
  }

  Q_ASSERT(scrollIndex < m_Units.size() && scrollIndex >= 0);
  WarScroll ws = WarScrollFactory::getSharedInstance().getWarScroll(getName(),
    m_Units.at(scrollIndex));
}
