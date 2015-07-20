#include "daemonsofchaosnurglearmy.h"

DaemonsOfChaosNurgleArmy::DaemonsOfChaosNurgleArmy() :
  IArmy(nullptr)

{
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

const QStringList &DaemonsOfChaosNurgleArmy::getUnits()
{
  return m_Units;
}

void DaemonsOfChaosNurgleArmy::buildUiForBattleScroll(QQuickView *ui,
  int scrollIndex)
{

}
