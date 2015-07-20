#include "armybalancer.h"

ArmyBalancer::ArmyBalancer(QQuickItem *parent)
  : QQuickItem(parent)
  , m_CurrentArmyIndex(0)
  , m_WarScrollFactory(WarScrollFactory::getSharedInstance())
{
  m_ArmyList.push_back(tr(""));

  m_ArmyList.push_back(tr("Beastmen"));
  m_ArmyNameToArmyMap.insert(m_ArmyList.back(),
    std::make_shared<BeastmenArmy>());
  m_ArmyList.push_back(tr("Bretonia"));
  m_ArmyNameToArmyMap.insert(m_ArmyList.back(),
    std::make_shared<BretonniaArmy>());
  m_ArmyList.push_back(tr("Daemons of Chaos (Khorne)"));
  m_ArmyNameToArmyMap.insert(m_ArmyList.back(),
    std::make_shared<DaemonsOfChaosKhorneArmy>());
  m_ArmyList.push_back(tr("Daemons of Chaos (Nurgle)"));
  m_ArmyNameToArmyMap.insert(m_ArmyList.back(),
    std::make_shared<DaemonsOfChaosNurgleArmy>());
  m_ArmyList.push_back(tr("Daemons of Chaos (Tzeentch)"));
  m_ArmyNameToArmyMap.insert(m_ArmyList.back(),
    std::make_shared<DaemonsOfChaosTzeentchArmy>());
  m_ArmyList.push_back(tr("Daemons of Chaos (Slaanesh)"));
  m_ArmyNameToArmyMap.insert(m_ArmyList.back(),
    std::make_shared<DaemonsOfChaosSlaaneshArmy>());
  m_ArmyList.push_back(tr("Dark Elves"));
  m_ArmyNameToArmyMap.insert(m_ArmyList.back(),
    std::make_shared<DarkElvesArmy>());
  m_ArmyList.push_back(tr("Dwarfs"));
  m_ArmyNameToArmyMap.insert(m_ArmyList.back(),
    std::make_shared<DwarfsArmy>());
  m_ArmyList.push_back(tr("The Empire"));
  m_ArmyNameToArmyMap.insert(m_ArmyList.back(),
    std::make_shared<TheEmpireArmy>());
  m_ArmyList.push_back(tr("High Elves"));
  m_ArmyNameToArmyMap.insert(m_ArmyList.back(),
    std::make_shared<HighElvesArmy>());
  m_ArmyList.push_back(tr("Lizardmen"));
  m_ArmyNameToArmyMap.insert(m_ArmyList.back(),
    std::make_shared<LizardmenArmy>());
  m_ArmyList.push_back(tr("Ogre Kingdoms"));
  m_ArmyNameToArmyMap.insert(m_ArmyList.back(),
    std::make_shared<OgreKingdomsArmy>());
  m_ArmyList.push_back(tr("Orcs and Goblins"));
  m_ArmyNameToArmyMap.insert(m_ArmyList.back(),
    std::make_shared<OrcsAndGoblinsArmy>());
  m_ArmyList.push_back(tr("Skaven"));
  m_ArmyNameToArmyMap.insert(m_ArmyList.back(),
    std::make_shared<SkavenArmy>());
  m_ArmyList.push_back(tr("Tomb Kings"));
  m_ArmyNameToArmyMap.insert(m_ArmyList.back(),
    std::make_shared<TombKingsArmy>());
  m_ArmyList.push_back(tr("Vampire Counts"));
  m_ArmyNameToArmyMap.insert(m_ArmyList.back(),
    std::make_shared<VampireCountsArmy>());
  m_ArmyList.push_back(tr("Warriors of Chaos"));
  m_ArmyNameToArmyMap.insert(m_ArmyList.back(),
    std::make_shared<WarriorsOfChaosArmy>());
  m_ArmyList.push_back(tr("Wood Elves"));
  m_ArmyNameToArmyMap.insert(m_ArmyList.back(),
    std::make_shared<WoodElvesArmy>());
}

void ArmyBalancer::setRootView(QQuickView *root)
{
  m_Root = root;
  setArmyList(m_ArmyList);
}

void ArmyBalancer::setArmyList(const QStringList &armyList)
{
  m_ArmyList = armyList;
  emit armyListChanged();
}


void ArmyBalancer::setWarScrolls(const QStringList &warScrolls)
{
  m_CurrentWarScrolls = warScrolls;
  emit warScrollsChanged();
}

void ArmyBalancer::getNextWarScrolls(QStringList &output,
  const QString &armyName)
{
  if (!armyName.isEmpty()) {
    output = m_ArmyNameToArmyMap[armyName]->getUnits();
  }
}

void ArmyBalancer::armySelectionChanged(int index)
{
  QStringList nextWarScrolls;
  Q_ASSERT(index < m_ArmyList.size() && index >= 0);
  m_CurrentArmyIndex = index;
  getNextWarScrolls(nextWarScrolls, m_ArmyList.at(index));
  setWarScrolls(nextWarScrolls);
}

void ArmyBalancer::warScrollSelectionChanged(int index)
{
  std::shared_ptr<IArmy> currentArmy = m_ArmyNameToArmyMap[
    m_ArmyList.at(m_CurrentArmyIndex)];
  currentArmy->buildUiForBattleScroll(m_Root, index);
}
