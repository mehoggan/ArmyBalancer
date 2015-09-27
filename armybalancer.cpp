#include "armybalancer.h"

#include <QDate>
#include <QMessageBox>

#include <algorithm>
#include <functional>
#include <cctype>
#include <iostream>
#include <locale>
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
  insertFaction<BeastmenFaction>();
  insertFaction<BretonniaFaction>();
  insertFaction<DaemonsOfChaosKhorneFaction>();
  insertFaction<DaemonsOfChaosNurgleFaction>();
  insertFaction<DaemonsOfChaosTzeentchFaction>();
  insertFaction<DaemonsOfChaosSlaaneshFaction>();
  insertFaction<DarkElvesFaction>();
  insertFaction<DwarfsFaction>();
  insertFaction<TheEmpireFaction>();
  insertFaction<HighElvesFaction>();
  insertFaction<KhorneBloodboundFaction>();
  insertFaction<TheLegionOfAzgorhFaction>();
  insertFaction<LizardmenFaction>();
  insertFaction<NurgleRotbringersFaction>();
  insertFaction<OgreKingdomsFaction>();
  insertFaction<OrcsAndGoblinsFaction>();
  insertFaction<SkavenFaction>();
  insertFaction<SkavenPestilensFaction>();
  insertFaction<StormCastEternalsFaction>();
  insertFaction<SylvanethFaction>();
  insertFaction<TamurkhansHordeFaction>();
  insertFaction<TombKingsFaction>();
  insertFaction<VampireCountsFaction>();
  insertFaction<WarriorsOfChaosFaction>();
  insertFaction<WoodElvesFaction>();
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
  QString displayScrollName(m_CurrentWarScroll.getTitle().c_str());

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

  { // Weapon Upgrades: If there are any present one will always be selected.
    QVariantMap::const_iterator upgradeNameIt = data.find("weaponUpgrade");
    if (upgradeNameIt != data.end()) {
      QString weaponUpgrade = upgradeNameIt->toString();
      Q_ASSERT(!weaponUpgrade.isEmpty());

      // A bit of UI parsing before we can find the right upgrade
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
        m_CurrentWarScroll.applyWeaponUpgrade(upgrade);
        displayScrollName += (std::string(" with ") + tokens[0]).c_str();
      } else if (tokens.size() == 2){
        const WarScroll::WeaponUpgrade &upgrade =
          m_CurrentWarScroll.getWeaponUpgrade(tokens[0], tokens[1], "");
        m_CurrentWarScroll.applyWeaponUpgrade(upgrade);
        displayScrollName += (std::string(" with ") + tokens[0] +
          std::string(" and ") + tokens[1]).c_str();
      } else {
        const WarScroll::WeaponUpgrade &upgrade =
          m_CurrentWarScroll.getWeaponUpgrade(tokens[0], tokens[1], tokens[2]);
        m_CurrentWarScroll.applyWeaponUpgrade(upgrade);
        displayScrollName += (std::string(" with ") + tokens[0] +
          std::string(" and ") + tokens[1] + std::string(" and ") +
          tokens[2]).c_str();
      }
    }
  }

  { // Unit Upgrades
    std::size_t unitUpgradeCount =
      m_CurrentWarScroll.getRegisteredUnitUpgrades().size();
    QString upgradeAppend;
    for (std::size_t i = 0; i < unitUpgradeCount; ++i) {
      // Build the key string to find which upgrade was selected.
      std::stringstream ss;
      ss << i;
      std::string key = std::string("unitUpgrade") + ss.str();
      QVariantMap::const_iterator upgradeNameIt = data.find(key.c_str());
      // If we find the upgrade in the data returned from the UI we need to
      // map that to the correct unit upgrade.
      if (upgradeNameIt != data.end()) {
        QString unitUpgrade = upgradeNameIt->toString();
        const std::list<WarScroll::UnitUpgrade> unitUpgrades =
          m_CurrentWarScroll.getRegisteredUnitUpgrades();
        for (const auto &currUnitUpgrade : unitUpgrades) {
          if (currUnitUpgrade.getName() == unitUpgrade.toStdString()) {
            // Before we go to apply the unit upgrade. If that upgrade already
            // exists, then we need to bypass applying it.
            if (currUnitUpgrade.makesUnitUnique()) {
              for (const std::map<std::string, WarScroll>::value_type &scroll
                : m_CurrentWarScrollsAdded) {
                if (scroll.second.getTitle() ==
                  m_CurrentWarScroll.getTitle()) {
                  // Pedantic check.
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

            const std::string name = currUnitUpgrade.getName();
            if (upgradeAppend.isEmpty()) {
              upgradeAppend += (std::string(" with ") + name).c_str();
            } else {
              upgradeAppend += (std::string(" and ") + name).c_str();
            }
            m_CurrentWarScroll.applyRegisteredUpgrade(name);

            break;
          }
        }
      }
    }
    displayScrollName += upgradeAppend;
  }

  { // Mount Upgrade
    QVariantMap::const_iterator upgradeNameIt = data.find("mountUpgrade");
    if (upgradeNameIt != data.end()) {
      QString mountName = upgradeNameIt->toString();
      const std::list<WarScroll::MountUpgrade> mounts =
        m_CurrentWarScroll.getRegisteredMountUpgrades();
      for (const auto &mount : mounts) {
        if (mount.getName() == mountName.toStdString()) {
          // Before we go to apply the unit upgrade. If that upgrade already
          // exists, then we need to bypass applying it.
          if (mount.makesUnitUnique()) {
            for (const std::map<std::string, WarScroll>::value_type &scroll :
              m_CurrentWarScrollsAdded) {
              // Pedantic Check
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

          m_CurrentWarScroll.applyRegisteredMount(mount.getName());

          break;
        }
      }
    }
  }

  { // Champion Upgrade
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

  { // Magical Upgrade
    QVariantMap::const_iterator magicUpgrade = data.find("magicUpgrade");
    if (magicUpgrade != data.end()) {
      QString magicUpgradeName = magicUpgrade->toString();

      const std::list<WarScroll::MagicalSpecialization> &magics =
        m_CurrentWarScroll.getRegisteredMagicalSpecializations();

      for (const auto &magic : magics) {
        if (magic.getName() == magicUpgradeName.toStdString()) {
          m_CurrentWarScroll.applyRegisteredMagicalSpecialization(
            magic.getName());
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

    if (displayScrollName.size() > 40) {
      displayScrollName = displayScrollName.mid(0, 40);
      displayScrollName += "...";
    }

    toAdd.insert("name", displayScrollName);
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

void ArmyBalancer::buildAndPublishSynergyGraph()
{
  m_WarScrollSynergyGraph.clear();

  for (const WarScrollAddedType &warscroll : m_CurrentWarScrollsAdded) {

    std::list<WarScroll::KeyWordConnection> connections =
      warscroll.second.getKeyWordConnections();

    for (const WarScroll::KeyWordConnection &connection : connections) {
      buildGraphFromConnectionString(connection, warscroll.second);
    }
  }

  m_WarScrollSynergyGraph.print();
}

namespace
{
  std::string &ltrim(std::string &s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(),
      std::not1(std::ptr_fun<int, int>(std::isspace))));
    return s;
  }

  std::string &rtrim(std::string &s) {
    s.erase(std::find_if(s.rbegin(), s.rend(),
      std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
    return s;
  }

  std::string &trim(std::string &s) {
    return ltrim(rtrim(s));
  }

  void parseStringToKeyWords(std::vector<std::string> &outKeyWords,
    const std::string &keyWordLogic) {

    std::string curr;
    for (auto it = keyWordLogic.begin(); it != keyWordLogic.end();) {
      if ((*it) == 'a') {
        outKeyWords.push_back(trim(curr));
        Q_ASSERT(*(++it) == 'n');
        Q_ASSERT(*(++it) == 'd');
        Q_ASSERT(*(++it) == ' ');
      } else if ((*it) == 'o') {
        outKeyWords.push_back(trim(curr));
        Q_ASSERT(*(++it) == 'r');
        Q_ASSERT(*(++it) == ' ');
      } else {
        curr += (*it);
        ++it;
      }
    }
  }
}

void ArmyBalancer::buildGraphFromConnectionString(
  const WarScroll::KeyWordConnection &keyWordConnection,
  const WarScroll &from)
{
  const std::string &keyWords = keyWordConnection.getKeyWord();

  bool AND = keyWords.find(" and ") != std::string::npos;
  bool OR = keyWords.find(" or ") != std::string::npos;

  std::vector<std::string> keyWordsBroken;
  if (AND || OR) {
    parseStringToKeyWords(keyWordsBroken, keyWords);
  } else {
    keyWordsBroken.push_back(keyWords);
  }

  for (const WarScrollAddedType &to : m_CurrentWarScrollsAdded) {
    const std::list<std::string> &toKeyWords = to.second.getKeyWords();
    bool found = true;
    if (OR) {
      found = false;
    }
    for (const std::string &keyWord : keyWordsBroken) {
      const auto it = std::find(toKeyWords.begin(), toKeyWords.end(), keyWord);
      bool tmp = it != toKeyWords.end();
      if (AND) {
        found &= tmp;
      } else if (OR) {
        found |= tmp;
      } else {
        found = tmp;
      }
    }

    if (found && (keyWordConnection.getAffectType() !=
      WarScroll::KeyWordConnection::ConnectionAffectType::eEnemy)) {

      m_WarScrollSynergyGraph.connect(from, to.second, keyWordConnection);
    }
  }
}
