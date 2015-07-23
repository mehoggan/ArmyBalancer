#include "armybalancer.h"

ArmyBalancer::ArmyBalancer(QQuickItem *parent)
  : QQuickItem(parent)
  , m_CurrentFactionIndex(0)
  , m_WarScrollFactory(WarScrollFactory::getSharedInstance())
{
  m_FactionList.push_back(tr(""));

  FactionMapType::const_iterator insert;

  insert = m_NameToFactionMap.insert(BeastmenFaction().getName(),
    std::make_shared<BeastmenFaction>());
  m_FactionList.push_back((*insert)->getName());
  insert = m_NameToFactionMap.insert(BretonniaFaction().getName(),
    std::make_shared<BretonniaFaction>());
  m_FactionList.push_back((*insert)->getName());
  insert = m_NameToFactionMap.insert(DaemonsOfChaosKhorneFaction().getName(),
    std::make_shared<DaemonsOfChaosKhorneFaction>());
  m_FactionList.push_back((*insert)->getName());
  insert = m_NameToFactionMap.insert(DaemonsOfChaosNurgleFaction().getName(),
    std::make_shared<DaemonsOfChaosNurgleFaction>());
  m_FactionList.push_back((*insert)->getName());
  insert = m_NameToFactionMap.insert(DaemonsOfChaosTzeentchFaction().getName(),
    std::make_shared<DaemonsOfChaosTzeentchFaction>());
  m_FactionList.push_back((*insert)->getName());
  insert = m_NameToFactionMap.insert(DaemonsOfChaosSlaaneshFaction().getName(),
    std::make_shared<DaemonsOfChaosSlaaneshFaction>());
  m_FactionList.push_back((*insert)->getName());
  insert = m_NameToFactionMap.insert(DarkElvesFaction().getName(),
    std::make_shared<DarkElvesFaction>());
  m_FactionList.push_back((*insert)->getName());
  insert = m_NameToFactionMap.insert(DwarfsFaction().getName(),
    std::make_shared<DwarfsFaction>());
  m_FactionList.push_back((*insert)->getName());
  insert = m_NameToFactionMap.insert(TheEmpireFaction().getName(),
    std::make_shared<TheEmpireFaction>());
  m_FactionList.push_back((*insert)->getName());
  insert = m_NameToFactionMap.insert(HighElvesFaction().getName(),
    std::make_shared<HighElvesFaction>());
  m_FactionList.push_back((*insert)->getName());
  insert = m_NameToFactionMap.insert(LizardmenFaction().getName(),
    std::make_shared<LizardmenFaction>());
  m_FactionList.push_back((*insert)->getName());
  insert = m_NameToFactionMap.insert(OgreKingdomsFaction().getName(),
    std::make_shared<OgreKingdomsFaction>());
  m_FactionList.push_back((*insert)->getName());
  insert = m_NameToFactionMap.insert(OrcsAndGoblinsFaction().getName(),
    std::make_shared<OrcsAndGoblinsFaction>());
  m_FactionList.push_back((*insert)->getName());
  insert = m_NameToFactionMap.insert(SkavenFaction().getName(),
    std::make_shared<SkavenFaction>());
  m_FactionList.push_back((*insert)->getName());
  insert = m_NameToFactionMap.insert(TombKingsFaction().getName(),
    std::make_shared<TombKingsFaction>());
  m_FactionList.push_back((*insert)->getName());
  insert = m_NameToFactionMap.insert(VampireCountsFaction().getName(),
    std::make_shared<VampireCountsFaction>());
  m_FactionList.push_back((*insert)->getName());
  insert = m_NameToFactionMap.insert(WarriorsOfChaosFaction().getName(),
    std::make_shared<WarriorsOfChaosFaction>());
  m_FactionList.push_back((*insert)->getName());
  insert = m_NameToFactionMap.insert(WoodElvesFaction().getName(),
    std::make_shared<WoodElvesFaction>());
  m_FactionList.push_back((*insert)->getName());
}

void ArmyBalancer::setRootView(QQuickView *root)
{
  m_Root = root;
}

void ArmyBalancer::setFactionList(const QStringList &factionList)
{
  m_FactionList = factionList;
  emit factionListChanged();
}


void ArmyBalancer::setWarScrolls(const QStringList &warScrolls)
{
  m_CurrentWarScrolls = warScrolls;
  emit warScrollsChanged();
}

void ArmyBalancer::getNextWarScrolls(QStringList &output,
  const QString &factionName)
{
  if (!factionName.isEmpty()) {
    output = m_NameToFactionMap[factionName]->getUnits();
  }
}

void ArmyBalancer::factionSelectionChanged(int index)
{
  QStringList nextWarScrolls;
  Q_ASSERT(index < m_FactionList.size() && index >= 0);
  m_CurrentFactionIndex = index;
  getNextWarScrolls(nextWarScrolls, m_FactionList.at(index));
  setWarScrolls(nextWarScrolls);
}

void ArmyBalancer::warScrollSelectionChanged(int index)
{
  std::shared_ptr<IFaction> currentFaction = m_NameToFactionMap[
    m_FactionList.at(m_CurrentFactionIndex)];
  WarScroll ws = m_WarScrollFactory.getSharedInstance().getWarScroll(
    currentFaction->getName(), currentFaction->getUnits()[index]);
  qDebug() << ws.getTitle() << " Selected";
}
