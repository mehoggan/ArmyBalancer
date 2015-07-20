#include "daemonsofchaoskhornearmy.h"

DaemonsOfChaosKhorneArmy::DaemonsOfChaosKhorneArmy() :
  IArmy(nullptr)

{
  m_Units.push_back(tr("Bloodthirster of Insensate Rage"));
  m_Units.push_back(tr("Bloodthirster of Unfettered Fury"));
  m_Units.push_back(tr("Wrath of Khorne Bloodthirster"));
  m_Units.push_back(tr("Skulltaker"));
  m_Units.push_back(tr("Herald of Khorne"));
  m_Units.push_back(tr("Herald of Khorne on Juggernaut"));
  m_Units.push_back(tr("Blood Throne of Khorne"));
  m_Units.push_back(tr("Bloodletters of Khorne"));
  m_Units.push_back(tr("Bloodcrushers of Khorne"));
  m_Units.push_back(tr("Karanak"));
  m_Units.push_back(tr("Flesh Hounds of Khorne"));
  m_Units.push_back(tr("Skull Cannons of Khorne"));
  m_Units.push_back(tr("Daemon Prince"));
  m_Units.push_back(tr("Furies"));
  m_Units.push_back(tr("Soul Grinder"));
}

const QStringList &DaemonsOfChaosKhorneArmy::getUnits()
{
  return m_Units;
}

void DaemonsOfChaosKhorneArmy::buildUiForBattleScroll(QQuickView *ui,
  int scrollIndex)
{

}
