#include "tombkingsfaction.h"

TombKingsFaction::TombKingsFaction() :
  IFaction(nullptr)
{
  m_Units.push_back(tr(""));
  m_Units.push_back(tr("Settra the Imperishable"));
  m_Units.push_back(tr("High Queen Khalida"));
  m_Units.push_back(tr("Tomb King"));
  m_Units.push_back(tr("Tomb King in Royal Chariot"));
  m_Units.push_back(tr("Prince Apophas"));
  m_Units.push_back(tr("Tomb Herald"));
  m_Units.push_back(tr("Liche Priest"));
  m_Units.push_back(tr("Casket of Souls"));
  m_Units.push_back(tr("Skeleton Warriors"));
  m_Units.push_back(tr("Skeleton Archers"));
  m_Units.push_back(tr("Skeleton Horsemen"));
  m_Units.push_back(tr("Skeleton Horse Archers"));
  m_Units.push_back(tr("Skeleton Chariots"));
  m_Units.push_back(tr("Tomb Guard"));
  m_Units.push_back(tr("Necrtect"));
  m_Units.push_back(tr("Necropolis Knights"));
  m_Units.push_back(tr("Tomb Scorpions"));
  m_Units.push_back(tr("Ushabti"));
  m_Units.push_back(tr("Khemrian Warsphinx"));
  m_Units.push_back(tr("Royal Warsphinx"));
  m_Units.push_back(tr("Necrosphinx"));
  m_Units.push_back(tr("Sepulchral Stalkers"));
  m_Units.push_back(tr("Bone Giant"));
  m_Units.push_back(tr("Screaming Skull Catapult"));
  m_Units.push_back(tr("Carrion"));
  m_Units.push_back(tr("Tomb Swarm"));
}

const QStringList &TombKingsFaction::getUnits()
{
  return m_Units;
}

void TombKingsFaction::buildUiForBattleScroll(QQuickView * /*ui*/, int scrollIndex)
{
  if (scrollIndex == 0) {
    return;
  }

  Q_ASSERT(scrollIndex < m_Units.size() && scrollIndex >= 0);
  WarScroll ws = WarScrollFactory::getSharedInstance().getWarScroll(getName(),
    m_Units.at(scrollIndex));
}
