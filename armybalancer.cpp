#include "armybalancer.h"

#include <QDate>

#include <utility>

ArmyBalancer::ArmyBalancer(QQuickItem *parent)
  : QQuickItem(parent)
  , m_CurrentFactionIndex(0)
  , m_CurrentWarScrollIndex(0)
  , m_Root(nullptr)
  , m_WarScrollFactory(WarScrollFactory::getSharedInstance())
{
  clearCurrentWarScroll();

  m_FactionList.push_back("");

  std::pair<FactionMapType::const_iterator, bool> insert;

  insert = m_NameToFactionMap.insert(std::make_pair(
    BeastmenFaction().getName(),
    std::make_shared<BeastmenFaction>()));
  m_FactionList.push_back(insert.first->second->getName().c_str());
  insert = m_NameToFactionMap.insert(std::make_pair(
    BretonniaFaction().getName(),
    std::make_shared<BretonniaFaction>()));
  m_FactionList.push_back(insert.first->second->getName().c_str());
  insert = m_NameToFactionMap.insert(std::make_pair(
    DaemonsOfChaosKhorneFaction().getName(),
    std::make_shared<DaemonsOfChaosKhorneFaction>()));
  m_FactionList.push_back(insert.first->second->getName().c_str());
  insert = m_NameToFactionMap.insert(std::make_pair(
    DaemonsOfChaosNurgleFaction().getName(),
    std::make_shared<DaemonsOfChaosNurgleFaction>()));
  m_FactionList.push_back(insert.first->second->getName().c_str());
  insert = m_NameToFactionMap.insert(std::make_pair(
    DaemonsOfChaosTzeentchFaction().getName(),
    std::make_shared<DaemonsOfChaosTzeentchFaction>()));
  m_FactionList.push_back(insert.first->second->getName().c_str());
  insert = m_NameToFactionMap.insert(std::make_pair(
    DaemonsOfChaosSlaaneshFaction().getName(),
    std::make_shared<DaemonsOfChaosSlaaneshFaction>()));
  m_FactionList.push_back(insert.first->second->getName().c_str());
  insert = m_NameToFactionMap.insert(std::make_pair(
    DarkElvesFaction().getName(),
    std::make_shared<DarkElvesFaction>()));
  m_FactionList.push_back(insert.first->second->getName().c_str());
  insert = m_NameToFactionMap.insert(std::make_pair(
    DwarfsFaction().getName(),
    std::make_shared<DwarfsFaction>()));
  m_FactionList.push_back(insert.first->second->getName().c_str());
  insert = m_NameToFactionMap.insert(std::make_pair(
    TheEmpireFaction().getName(),
    std::make_shared<TheEmpireFaction>()));
  m_FactionList.push_back(insert.first->second->getName().c_str());
  insert = m_NameToFactionMap.insert(std::make_pair(
    HighElvesFaction().getName(),
    std::make_shared<HighElvesFaction>()));
  m_FactionList.push_back(insert.first->second->getName().c_str());
  insert = m_NameToFactionMap.insert(std::make_pair(
    LizardmenFaction().getName(),
    std::make_shared<LizardmenFaction>()));
  m_FactionList.push_back(insert.first->second->getName().c_str());
  insert = m_NameToFactionMap.insert(std::make_pair(
    OgreKingdomsFaction().getName(),
    std::make_shared<OgreKingdomsFaction>()));
  m_FactionList.push_back(insert.first->second->getName().c_str());
  insert = m_NameToFactionMap.insert(std::make_pair(
    OrcsAndGoblinsFaction().getName(),
    std::make_shared<OrcsAndGoblinsFaction>()));
  m_FactionList.push_back(insert.first->second->getName().c_str());
  insert = m_NameToFactionMap.insert(std::make_pair(
    SkavenFaction().getName(),
    std::make_shared<SkavenFaction>()));
  m_FactionList.push_back(insert.first->second->getName().c_str());
  insert = m_NameToFactionMap.insert(std::make_pair(
    TombKingsFaction().getName(),
    std::make_shared<TombKingsFaction>()));
  m_FactionList.push_back(insert.first->second->getName().c_str());
  insert = m_NameToFactionMap.insert(std::make_pair(
    VampireCountsFaction().getName(),
    std::make_shared<VampireCountsFaction>()));
  m_FactionList.push_back(insert.first->second->getName().c_str());
  insert = m_NameToFactionMap.insert(std::make_pair(
    WarriorsOfChaosFaction().getName(),
    std::make_shared<WarriorsOfChaosFaction>()));
  m_FactionList.push_back(insert.first->second->getName().c_str());
  insert = m_NameToFactionMap.insert(std::make_pair(
    WoodElvesFaction().getName(),
    std::make_shared<WoodElvesFaction>()));
  m_FactionList.push_back(insert.first->second->getName().c_str());
}

void ArmyBalancer::setRootView(QQuickView *root)
{
  m_Root = root;
}

const QStringList &ArmyBalancer::getFactionList() const
{
  return m_FactionList;
}

void ArmyBalancer::setFactionList(const QStringList &factionList)
{
  m_FactionList = factionList;
  emit factionListChanged();
}

const QStringList &ArmyBalancer::getWarScrolls() const
{
  return m_CurrentWarScrolls;
}

void ArmyBalancer::setWarScrolls(const QStringList &warScrolls)
{
  m_CurrentWarScrolls = warScrolls;
  emit warScrollsChanged();

  if (m_Root) {
    QVariantList list;
    for(const QString &scroll : warScrolls) {
      list.append(scroll);
    }
    QMetaObject::invokeMethod(m_Root->rootObject(), "updateWarScrollList",
      Q_ARG(QVariant, QVariant::fromValue(list)));
  }
}

void ArmyBalancer::getNextWarScrolls(std::vector<std::string> &output,
  const std::string &factionName)
{
  if (!factionName.empty()) {
    output = m_NameToFactionMap[factionName]->getUnits();
  }
}

void ArmyBalancer::factionSelectionChanged(int index)
{
  std::vector<std::string> nextWarScrolls;
  m_CurrentFactionIndex = index;
  getNextWarScrolls(nextWarScrolls, m_FactionList.at(index).toStdString());
  QStringList vals;
  for(const std::string &scroll : nextWarScrolls)
  {
    vals.push_back(scroll.c_str());
  }
  setWarScrolls(vals);
}

void ArmyBalancer::warScrollSelectionChanged(int index)
{
  m_CurrentWarScrollIndex = index;
}

void ArmyBalancer::warScrollSeleted()
{
  Q_ASSERT(m_CurrentFactionIndex > 0 && m_CurrentWarScrollIndex > 0);
  std::shared_ptr<IFaction> faction = m_NameToFactionMap[
    m_FactionList.at(m_CurrentFactionIndex).toStdString()];
  m_CurrentWarScroll = m_WarScrollFactory.getSharedInstance().getWarScroll(
    faction->getName(), faction->getUnits()[m_CurrentWarScrollIndex]);
  qDebug() << "Configuring Warscoll " << m_CurrentWarScroll.getTitle().c_str();

  if (m_Root) {
    QVariant val = m_CurrentWarScroll.getTitle().c_str();
    QMetaObject::invokeMethod(
      m_Root->rootObject()->findChild<QObject *>("warScrollForm"),
      "setWarScrollTitleName",
      Q_ARG(QVariant, QVariant::fromValue(val)));

    QVariant min = m_CurrentWarScroll.getMinUnitCount();
    QVariant max = m_CurrentWarScroll.getMaxUnitCount();
    QMetaObject::invokeMethod(
      m_Root->rootObject()->findChild<QObject *>("warScrollForm"),
      "setMinMaxUnitCount",
      Q_ARG(QVariant, QVariant::fromValue(min)),
      Q_ARG(QVariant, QVariant::fromValue(max)));
  }
}

void ArmyBalancer::warScrollAccepted()
{
  Q_ASSERT(!m_CurrentWarScroll.getTitle().empty());
  std::string title = m_CurrentWarScroll.getTitle();
  // TODO: Get the data from ui and cram it into current war scroll
  m_CurrentWarScrollsAdded.insert(title, m_CurrentWarScroll);
  qDebug() << "War Scroll Accepted " << m_CurrentWarScroll.getTitle().c_str();
  qDebug() << "\t Current War Scrolls " << m_CurrentWarScrollsAdded.size();

  if (m_Root) {
    m_CurrentWarScroll.refreshPointsCost();
    QVariant val = m_CurrentWarScroll.getPointsCost();
    QMetaObject::invokeMethod(m_Root->rootObject(), "addToCurrentPoints",
      Q_ARG(QVariant, QVariant::fromValue(val)));
  }
  clearCurrentWarScroll();
}

void ArmyBalancer::clearCurrentWarScroll()
{
  m_CurrentWarScroll = WarScroll();
  qDebug() << "Cleared Warscoll --" << m_CurrentWarScroll.getTitle().c_str()
    << "--";
}

void ArmyBalancer::clearCurrentWarScrolls()
{
  m_CurrentWarScrollsAdded.clear();
  qDebug() << "Cleared all Previously Selected WarScrolls.";
  qDebug() << "\t Current War Scrolls " << m_CurrentWarScrollsAdded.size();
  if (m_Root) {
    QVariant val = m_CurrentWarScroll.getPointsCost();
    QMetaObject::invokeMethod(m_Root->rootObject(), "clearCurrentPoints");
  }
}
