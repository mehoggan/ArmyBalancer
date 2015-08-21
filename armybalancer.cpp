#include "armybalancer.h"

#include <QDate>
#include <QMessageBox>

#include <iostream>
#include <sstream>
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
      for (const WarScroll::WeaponUpgrade &upgrade : upgrades) {
        const std::string &weapon = upgrade.getWeapon().getName();
        if (weapon.empty()) {
          const std::string &ability = upgrade.getAbility().getName();
          list.append(ability.c_str());
        } else {
          if (upgrade.getAbility().getName().empty() &&
            upgrade.getSecondaryWeapon().getName().empty()) {
            list.append(weapon.c_str());
          } else if (upgrade.getAbility().getName().empty() &&
            !upgrade.getSecondaryWeapon().getName().empty()) {
            list.append((weapon + "//" +
              upgrade.getSecondaryWeapon().getName()).c_str());
          } else if (!upgrade.getAbility().getName().empty() &&
            upgrade.getSecondaryWeapon().getName().empty()){
            list.append((weapon + "/" +
              upgrade.getAbility().getName()).c_str());
          } else {
            list.append((weapon + "/" +
              upgrade.getAbility().getName() + "/" +
              upgrade.getSecondaryWeapon().getName()).c_str());
          }
        }
      }
      QMetaObject::invokeMethod(
        m_Root->rootObject()->findChild<QObject *>("warScrollForm"),
        "addArsenalUpgrades",
        Q_ARG(QVariant, QVariant::fromValue(list)));
    }

    if (m_Root) {
      QVariantList list;
      QVariantList championList;
      const std::list<WarScroll::UnitUpgrade> &upgrades =
        m_CurrentWarScroll.getRegisteredUnitUpgrades();
      for (const WarScroll::UnitUpgrade &upgrade : upgrades) {
        Q_ASSERT(!upgrade.getName().empty());
        const std::string &unitUpgrade = upgrade.getName();

        if (upgrade.getUpgradeType() ==
          WarScroll::UnitUpgrade::UnitUpgradeType::eChampion &&
          !m_CurrentWarScroll.getRegisteredChampionWithOptions().empty()) {
          for (const auto &champion :
            m_CurrentWarScroll.getRegisteredChampionWithOptions()) {
            championList.append(champion.getName().c_str());
          }
        } else {
          list.append(unitUpgrade.c_str());
        }
      }
      QMetaObject::invokeMethod(
        m_Root->rootObject()->findChild<QObject *>("warScrollForm"),
        "addUnitUpgrades",
        Q_ARG(QVariant, QVariant::fromValue(list)));
      QMetaObject::invokeMethod(
        m_Root->rootObject()->findChild<QObject *>("warScrollForm"),
          "addChampionOption",
          Q_ARG(QVariant, QVariant::fromValue(championList)));
    }

    if (m_Root) {
      QVariantList list;
      const std::list<WarScroll::MountUpgrade> &upgrades =
        m_CurrentWarScroll.getRegisteredMountUpgrades();
      for (const auto &mount : upgrades) {
        const std::string &name = mount.getName();
        list.append(name.c_str());
      }
      QMetaObject::invokeMethod(
        m_Root->rootObject()->findChild<QObject *>("warScrollForm"),
        "addMountUpgrades",
        Q_ARG(QVariant, QVariant::fromValue(list)));
    }

    if (m_Root) {
      QVariantList list;
      const std::list<WarScroll::MagicalSpecialization> &upgrades =
        m_CurrentWarScroll.getRegisteredMagicalSpecializations();
      for (const auto &magicSpecialization : upgrades) {
        const std::string &name = magicSpecialization.getName();
        list.append(name.c_str());
      }
      QMetaObject::invokeMethod(
        m_Root->rootObject()->findChild<QObject *>("warScrollForm"),
        "addMagicSpecializations",
        Q_ARG(QVariant, QVariant::fromValue(list)));
    }
  }
}

void ArmyBalancer::warScrollAccepted(QVariantMap data)
{
  Q_ASSERT(!m_CurrentWarScroll.getTitle().empty());
  {
    QVariantMap::const_iterator unitCountIt = data.find("unitCount");
    if (unitCountIt != data.end()) {
      bool ok = false;
      int unitCount = unitCountIt->toInt(&ok);
      Q_ASSERT(ok);
      m_CurrentWarScroll.setUnitCount(unitCount);
    } else {
      Q_ASSERT(false && "Failed to get unit count from xml");
    }
  }

  {
    QVariantMap::const_iterator upgradeNameIt = data.find("weaponUpgrade");
    if (upgradeNameIt != data.end()) {
      QString weaponUpgrade = upgradeNameIt->toString();
      Q_ASSERT(!weaponUpgrade.isEmpty());

      std::vector<std::string> tokens;
      std::istringstream iss(weaponUpgrade.toStdString());
      std::string s;
      while (getline(iss, s, '/')) {
        tokens.push_back(s);
      }

      if (tokens.size() == 1) {
        const WarScroll::WeaponUpgrade &upgrade =
          m_CurrentWarScroll.getWeaponUpgrade(tokens[0], "", "");
        if (upgrade.getWeapon().getName().empty() &&
          upgrade.getAbility().getName().empty()) {
          const_cast<WarScroll::WeaponUpgrade &>(upgrade) =
            m_CurrentWarScroll.getWeaponUpgrade("", tokens[0], "");
        }
        Q_ASSERT(!upgrade.getWeapon().getName().empty() ||
          !upgrade.getAbility().getName().empty());
        m_CurrentWarScroll.applyWeaponUpgrade(upgrade);
        for (const auto &i : upgrade.getCharacteristicsToUpdate()) {
          m_CurrentWarScroll.incrementCharacteristic(i.first, i.second);
        }
        for (const auto &i : upgrade.getAbilitiesToAdd()) {
          m_CurrentWarScroll.addAbility(i);
        }
      } else if (tokens.size() == 2){
        const WarScroll::WeaponUpgrade &upgrade =
          m_CurrentWarScroll.getWeaponUpgrade(tokens[0], tokens[1], "");
        m_CurrentWarScroll.applyWeaponUpgrade(upgrade);
        for (const auto &i : upgrade.getCharacteristicsToUpdate()) {
          m_CurrentWarScroll.incrementCharacteristic(i.first, i.second);
        }
        for (const auto &i : upgrade.getAbilitiesToAdd()) {
          m_CurrentWarScroll.addAbility(i);
        }
      } else {
        const WarScroll::WeaponUpgrade &upgrade =
          m_CurrentWarScroll.getWeaponUpgrade(tokens[0], tokens[1], tokens[2]);
        m_CurrentWarScroll.applyWeaponUpgrade(upgrade);
        for (const auto &i : upgrade.getCharacteristicsToUpdate()) {
          m_CurrentWarScroll.incrementCharacteristic(i.first, i.second);
        }
        for (const auto &i : upgrade.getAbilitiesToAdd()) {
          m_CurrentWarScroll.addAbility(i);
        }

        if (!upgrade.getTertiaryWeapon().getName().empty()) {
          m_CurrentWarScroll.addWeapon(upgrade.getTertiaryWeapon());
        }
      }
    }
  }

  {
    std::size_t unitUpgradeCount =
      m_CurrentWarScroll.getRegisteredUnitUpgrades().size();
    bool unitCanFly = m_CurrentWarScroll.getCanFly();
    for (std::size_t i = 0; i < unitUpgradeCount; ++i) {
      std::stringstream ss;
      ss << i;
      std::string key = std::string("unitUpgrade") + ss.str();
      QVariantMap::const_iterator upgradeNameIt = data.find(key.c_str());
      if (upgradeNameIt != data.end()) {
        QString unitUpgrade = upgradeNameIt->toString();
        Q_ASSERT(!unitUpgrade.isEmpty());
        const std::list<WarScroll::UnitUpgrade> unitUpgrades =
          m_CurrentWarScroll.getRegisteredUnitUpgrades();
        for (const auto &currUnitUpgrade : unitUpgrades) {
          if (currUnitUpgrade.getName() == unitUpgrade.toStdString()) {
            m_CurrentWarScroll.applyRegisteredUpgrade(
              currUnitUpgrade.getName());
            const std::list<std::pair<std::string, int>> characteristics =
              currUnitUpgrade.getCharacteristicsToUpdate();
            for (const auto &upgradeCharacteristic : characteristics) {
              m_CurrentWarScroll.incrementCharacteristic(
                upgradeCharacteristic.first, upgradeCharacteristic.second);
            }
            for (const auto &ability : currUnitUpgrade.getAbilities()) {
              m_CurrentWarScroll.addAbility(ability);
            }
            for (const auto &weapon :  currUnitUpgrade.getWeapons()) {
              m_CurrentWarScroll.addWeapon(weapon);
            }
            if (currUnitUpgrade.getUpgradeType() ==
              WarScroll::UnitUpgrade::UnitUpgradeType::eMount) {
              m_CurrentWarScroll.registerMountUpgrade(WarScroll::MountUpgrade(
                currUnitUpgrade.getName()));
              m_CurrentWarScroll.applyRegisteredMount(
                currUnitUpgrade.getName());
            }
            unitCanFly |= currUnitUpgrade.providesCanFly();

            if (currUnitUpgrade.makesUnitUnique()) {
              m_CurrentWarScroll.setIsUnique(true);
              for (const std::map<std::string, WarScroll>::value_type &scroll :
                m_CurrentWarScrollsAdded) {
                if (scroll.second.getTitle() == m_CurrentWarScroll.getTitle()) {
                  if (scroll.second.getIsUnique()) {
                    QMessageBox::warning(nullptr, "Mulitiples Not Allowed",
                      tr("Multiples of %1 not allowed.").
                      arg(scroll.second.getTitle().c_str()));
                    clearCurrentWarScroll();
                    return;
                  }
                }
              }
            }
            break;
          }
        }
      }
    }
    m_CurrentWarScroll.setCanFly(unitCanFly);
  }

  {
    QVariantMap::const_iterator upgradeNameIt = data.find("mountUpgrade");
    if (upgradeNameIt != data.end()) {
      QString mountName = upgradeNameIt->toString();

      const std::list<WarScroll::MountUpgrade> mounts =
        m_CurrentWarScroll.getRegisteredMountUpgrades();
      for (const auto &mount : mounts) {
        if (mount.getName() == mountName.toStdString()) {
          // Remove old things first in the case that mount adds them back
          for (const auto &weapon : mount.getRiderWeaponsToReplace()) {
            m_CurrentWarScroll.removeWeapon(weapon);
          }
          for (const auto &ability : mount.getRiderAbilitiesToRemove()) {
            m_CurrentWarScroll.removeAbility(ability);
          }
          for (const auto &characteristic :
            mount.getChacarteristicsToSet()){
            m_CurrentWarScroll.setCharacteristic(characteristic);
          }
          // Now that old abilities and weapons gone it is now okay to add
          // all the new items.
          const std::list<WarScroll::Weapon> weapons = mount.getWeapons();
          for (const auto &weapon : weapons) {
            m_CurrentWarScroll.addWeapon(weapon);
          }
          const std::list<WarScroll::Ability> abilities = mount.getAbilities();
          for (const auto &ability : abilities) {
            m_CurrentWarScroll.addAbility(ability);
          }
          for (const auto &stat : mount.getCharacteristicsToUpdate()) {
            m_CurrentWarScroll.incrementCharacteristic(stat.first,
              stat.second);
          }
          m_CurrentWarScroll.setCanFly(mount.providesCanFly() ||
            m_CurrentWarScroll.getCanFly());
          m_CurrentWarScroll.applyRegisteredMount(mount.getName());

          if (mount.makesUnitUnique()) {
            m_CurrentWarScroll.setIsUnique(true);
            for (const std::map<std::string, WarScroll>::value_type &scroll :
              m_CurrentWarScrollsAdded) {
              if (scroll.second.getTitle() == m_CurrentWarScroll.getTitle()) {
                if (scroll.second.getIsUnique()) {
                  QMessageBox::warning(nullptr, "Mulitiples Not Allowed",
                    tr("Multiples of %1 not allowed.").
                    arg(scroll.second.getTitle().c_str()));
                  clearCurrentWarScroll();
                  return;
                }
              }
            }
          }

          break;
        }
      }
    }
  }

  {
    QVariantMap::const_iterator championUpgrade = data.find("championUpgrade");
    if (championUpgrade != data.end()) {
      QString championName = championUpgrade->toString();

      const std::list<WarScroll::ChampionWithOptions> &champions =
        m_CurrentWarScroll.getRegisteredChampionWithOptions();

      for (const auto &champion : champions) {
        if (champion.getName() == championName.toStdString()) {
          m_CurrentWarScroll.applyRegisteredChampionWithOptions(
            champion.getName());
          break;
        }
      }
    }
  }

  {
    QVariantMap::const_iterator magicUpgrade = data.find("magicUpgrade");
    if (magicUpgrade != data.end()) {
      QString magicUpgradeName = magicUpgrade->toString();

      const std::list<WarScroll::MagicalSpecialization> &magics =
        m_CurrentWarScroll.getRegisteredMagicalSpecializations();

      for (const auto &magic : magics) {
        if (magic.getName() == magicUpgradeName.toStdString()) {
          m_CurrentWarScroll.applyRegisteredMagicalSpecialization(
            magic.getName());
          m_CurrentWarScroll.addSpell(magic.getSpell());
        }
      }
    }
  }

  WarScroll tmpWarScroll = m_CurrentWarScroll;
  tmpWarScroll.refreshPointsCost();
  tmpWarScroll.regenGuid();
  m_CurrentWarScrollsAdded.insert(std::make_pair(
    tmpWarScroll.getGuid().toString().toStdString(), tmpWarScroll));

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
  if (m_Root) {
    QVariantList list;
    QMetaObject::invokeMethod(
    m_Root->rootObject()->findChild<QObject *>("warScrollForm"),
    "addArsenalUpgrades",
    Q_ARG(QVariant, QVariant::fromValue(list)));
  }
  if (m_Root) {
    QVariantList list;
    QMetaObject::invokeMethod(
    m_Root->rootObject()->findChild<QObject *>("warScrollForm"),
    "addUnitUpgrades",
    Q_ARG(QVariant, QVariant::fromValue(list)));
  }
  if (m_Root) {
    QVariantList list;
    QMetaObject::invokeMethod(
      m_Root->rootObject()->findChild<QObject *>("warScrollForm"),
      "addMountUpgrades",
      Q_ARG(QVariant, QVariant::fromValue(list)));
  }
  if (m_Root) {
    QVariantList list;
    QMetaObject::invokeMethod(
      m_Root->rootObject()->findChild<QObject *>("warScrollForm"),
      "addChampionOption",
      Q_ARG(QVariant, QVariant::fromValue(list)));
  }
  if (m_Root) {
    QVariantList list;
    QMetaObject::invokeMethod(
      m_Root->rootObject()->findChild<QObject *>("warScrollForm"),
      "addMagicSpecializations",
      Q_ARG(QVariant, QVariant::fromValue(list)));
  }
}

void ArmyBalancer::clearCurrentWarScrolls()
{
  m_CurrentWarScrollsAdded.clear();
  if (m_Root) {
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
      qDebug() << "Removing " << guid.toString() << " which points to " <<
        it->second.getTitle().c_str();
    }
    m_CurrentWarScrollsAdded.erase(it);
  }
}

QVariant ArmyBalancer::getCurrentScrollText(QVariant guid)
{
  std::string guidStr = guid.toString().toStdString();
  auto it = m_CurrentWarScrollsAdded.find(guidStr);
  if (it != m_CurrentWarScrollsAdded.end()) {
    std::string str = it->second.toString();
    QString val(str.c_str());
    return QVariant::fromValue(val);
  } else {
    return QVariant::fromValue(QString(""));
  }
}
