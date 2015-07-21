#include "lizardmenfaction.h"

LizardmenFaction::LizardmenFaction() :
  IFaction(nullptr)
{
  m_Units.push_back(tr(""));
  m_Units.push_back(tr("Lord Kroak"));
  m_Units.push_back(tr("Slann Mage-Priest"));
  m_Units.push_back(tr("Kroq-Gar on Carnosaur"));
  m_Units.push_back(tr("Saurus Oldblood"));
  m_Units.push_back(tr("Saurus Oldblood on Cold One"));
  m_Units.push_back(tr("Chakax, the Eternity Warden"));
  m_Units.push_back(tr("Gor-Rok"));
  m_Units.push_back(tr("Scar-vetran with Battle Standard"));
  m_Units.push_back(tr("Scar-vetran on Carnosaur"));
  m_Units.push_back(tr("Saurus Warriors"));
  m_Units.push_back(tr("Temple Guard"));
  m_Units.push_back(tr("Saurus Cavalry"));
  m_Units.push_back(tr("Tehenhauin, Prophet of Sotek"));
  m_Units.push_back(tr("Tetto'eko"));
  m_Units.push_back(tr("Oxyotl"));
  m_Units.push_back(tr("Skink Priest"));
  m_Units.push_back(tr("Skink Chief"));
  m_Units.push_back(tr("Skinks"));
  m_Units.push_back(tr("Chameleon Skinks"));
  m_Units.push_back(tr("Terradon Riders"));
  m_Units.push_back(tr("Pipperdactyl Riders"));
  m_Units.push_back(tr("Skink Handlers"));
  m_Units.push_back(tr("Salamanders"));
  m_Units.push_back(tr("Razordons"));
  m_Units.push_back(tr("Kroxigor"));
  m_Units.push_back(tr("Stegadon"));
  m_Units.push_back(tr("Engine of the Gods"));
  m_Units.push_back(tr("Bastiladon"));
  m_Units.push_back(tr("Troglodon"));
  m_Units.push_back(tr("Jungle Swarms"));
}

const QStringList &LizardmenFaction::getUnits()
{
  return m_Units;
}

void LizardmenFaction::buildUiForBattleScroll(QQuickView * /*ui*/, int scrollIndex)
{
  if (scrollIndex == 0) {
    return;
  }

  Q_ASSERT(scrollIndex < m_Units.size() && scrollIndex >= 0);
  WarScroll ws = WarScrollFactory::getSharedInstance().getWarScroll(getName(),
    m_Units.at(scrollIndex));
}
