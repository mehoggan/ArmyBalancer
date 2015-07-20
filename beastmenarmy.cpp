﻿#include "beastmenarmy.h"

BeastmenArmy::BeastmenArmy() :
  IArmy(nullptr)
{
  m_Units.push_back(tr("Gorthor the Beastlord"));
  m_Units.push_back(tr("Khazrak the One-Eye"));
  m_Units.push_back(tr("Beastlord"));
  m_Units.push_back(tr("Wargor Standard Bearer"));
  m_Units.push_back(tr("Malagor, The Dark Omen"));
  m_Units.push_back(tr("Great Bray-shaman"));
  m_Units.push_back(tr("Morghur, Master of Skulls"));
  m_Units.push_back(tr("Gors"));
  m_Units.push_back(tr("Bestigors"));
  m_Units.push_back(tr("Tuskgor Chariots"));
  m_Units.push_back(tr("Ungors"));
  m_Units.push_back(tr("Ungor Raiders"));
  m_Units.push_back(tr("Doombull"));
  m_Units.push_back(tr("Minotaurs"));
  m_Units.push_back(tr("Cygor"));
  m_Units.push_back(tr("Ghorgon"));
  m_Units.push_back(tr("Centigors"));
  m_Units.push_back(tr("Ghorros Warhoof"));
  m_Units.push_back(tr("Razorgors"));
  m_Units.push_back(tr("Chaos Warhounds"));
  m_Units.push_back(tr("Harpies"));
  m_Units.push_back(tr("Chaos Spawn"));
  m_Units.push_back(tr("Giant"));
  m_Units.push_back(tr("Jabberslythe"));
}

const QStringList &BeastmenArmy::getUnits()
{
  return m_Units;
}

void BeastmenArmy::buildUiForBattleScroll(QQuickView *ui, int scrollIndex)
{

}
