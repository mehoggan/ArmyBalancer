#include "daemonsofchaostzeentchfaction.h"

DaemonsOfChaosTzeentchFaction::DaemonsOfChaosTzeentchFaction() :
  IFaction(nullptr)
{
  m_Units.push_back(tr(""));
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

const QStringList &DaemonsOfChaosTzeentchFaction::getUnits()
{
  return m_Units;
}

void DaemonsOfChaosTzeentchFaction::buildUiForBattleScroll(QQuickView * /*ui*/,
  int scrollIndex)
{
  if (scrollIndex == 0) {
    return;
  }

  Q_ASSERT(scrollIndex < m_Units.size() && scrollIndex >= 0);
  WarScroll ws = WarScrollFactory::getSharedInstance().getWarScroll(getName(),
    m_Units.at(scrollIndex));
}
