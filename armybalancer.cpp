#include "armybalancer.h"

#include <QDate>

#include <iostream>
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

    if (m_Root) {
      QVariantList list;
      const std::list<WarScroll::WeaponUpgrade> &upgrades =
        m_CurrentWarScroll.getWeaponUpgrades();
      for(const WarScroll::WeaponUpgrade &upgrade : upgrades) {
        const std::string &weapon = upgrade.getWeapon().getName();
        if (weapon.empty()) {
          const std::string &ability = upgrade.getAbility().getName();
          list.append(ability.c_str());
        } else {
          list.append(weapon.c_str());
        }
      }
      QMetaObject::invokeMethod(
        m_Root->rootObject()->findChild<QObject *>("warScrollForm"),
        "addUpgrades",
        Q_ARG(QVariant, QVariant::fromValue(list)));
    }
  }
}

void ArmyBalancer::warScrollAccepted(QVariantMap data)
{
  Q_ASSERT(!m_CurrentWarScroll.getTitle().empty());
  std::string title = m_CurrentWarScroll.getTitle();

  QVariantMap::const_iterator unitCountIt = data.find("unitCount");
  if (unitCountIt != data.end()) {
    bool ok = false;
    int unitCount = unitCountIt->toInt(&ok);
    Q_ASSERT(ok);
    m_CurrentWarScroll.setUnitCount(unitCount);
  } else {
    Q_ASSERT(false && "Failed to get unit count from xml");
  }

  QVariantMap::const_iterator upgradeNameIt = data.find("weaponUpgrade");
  if (upgradeNameIt != data.end()) {
    QString weaponUpgrade = upgradeNameIt->toString();
    Q_ASSERT(!weaponUpgrade.isEmpty());
    const WarScroll::WeaponUpgrade & upgrade =
      m_CurrentWarScroll.getWeaponUpgrade(weaponUpgrade.toStdString());
    Q_ASSERT(!upgrade.getWeapon().getName().empty() ||
      !upgrade.getAbility().getName().empty());
    m_CurrentWarScroll.applyWeaponUpgrade(upgrade);
  }

  WarScroll tmpWarScroll = m_CurrentWarScroll;
  tmpWarScroll.refreshPointsCost();
  tmpWarScroll.regenGuid();
  std::cout << tmpWarScroll << std::endl;
  m_CurrentWarScrollsAdded.insert(std::make_pair(
    tmpWarScroll.getGuid().toString().toStdString(), tmpWarScroll));
  qDebug() << "War Scroll Accepted " << tmpWarScroll.getTitle().c_str();
  qDebug() << "\t Current War Scrolls " << m_CurrentWarScrollsAdded.size();

  if (m_Root) {
    QVariant val = tmpWarScroll.getPointsCost();
    QMetaObject::invokeMethod(m_Root->rootObject(), "addToCurrentPoints",
      Q_ARG(QVariant, QVariant::fromValue(val)));
  }
  clearCurrentWarScroll();

  if (m_Root) {
    QVariantMap toAdd;
    toAdd.insert("name", QString(tmpWarScroll.getTitle().c_str()));
    toAdd.insert("guid", QVariant(tmpWarScroll.getGuid().toString()));
    toAdd.insert("unit", QVariant(tmpWarScroll.getUnitCount()));
    QMetaObject::invokeMethod(
    m_Root->rootObject()->findChild<QObject *>("currentWarScrolls"),
    "addNewUnit",
    Q_ARG(QVariant, QVariant::fromValue(toAdd)));
  }
}

void ArmyBalancer::clearCurrentWarScroll()
{
  m_CurrentWarScroll = WarScroll();
  qDebug() << "Cleared Warscoll --" << m_CurrentWarScroll.getTitle().c_str()
    << "--";
  if (m_Root) {
    QVariantList list;
    QMetaObject::invokeMethod(
    m_Root->rootObject()->findChild<QObject *>("warScrollForm"),
    "addUpgrades",
    Q_ARG(QVariant, QVariant::fromValue(list)));
  }
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

  clearCurrentWarScroll();

  if (m_Root) {
    QMetaObject::invokeMethod(
      m_Root->rootObject()->findChild<QObject *>("currentWarScrolls"),
      "clearAllUnits");
  }
}

void ArmyBalancer::removeCurrentWarScroll(QVariant guid)
{
  std::string guidStr = guid.toString().toStdString();
  auto it = m_CurrentWarScrollsAdded.find(guidStr);
  if (it != m_CurrentWarScrollsAdded.end()) {
    if (m_Root) {
      QVariant val = -it->second.getPointsCost();
      QMetaObject::invokeMethod(m_Root->rootObject(), "addToCurrentPoints",
        Q_ARG(QVariant, QVariant::fromValue(val)));
    }

    qDebug() << "War Scroll Removed " << it->second.getTitle().c_str();
    m_CurrentWarScrollsAdded.erase(it);
  }
  qDebug() << "\t Current War Scrolls " << m_CurrentWarScrollsAdded.size();
}
