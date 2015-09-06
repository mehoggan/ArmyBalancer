#include "warscroll.h"

#include <sstream>
#include <utility>

void WarScroll::addSummonable(WarScroll &ws, const std::string &name, int toCast,
  int pointCost, int distance, int summonCount,
  const std::list<std::string> &keyWords)
{
  std::string andKeyWords;
  for (auto it = keyWords.begin(); it != keyWords.end(); ++it) {
    andKeyWords += (*it);
    if (*it != *keyWords.rbegin()) {
      andKeyWords += " and ";
    }
  }

  WarScroll::Spell spell("Summon " + name);
  spell.setToCast(toCast);
  spell.setPointCost(pointCost);
  WarScroll::KeyWordConnection connection(andKeyWords,
    distance, WarScroll::Ability(), 1,
    WarScroll::KeyWordConnection::ConnectionAffectType::eSummons,
    spell);
  connection.setSummonCount(summonCount);
  ws.addKeyWordConnection(connection);
}

void WarScroll::Ability::registerCharacteristicToIncreaseIfOverN(
  const std::string &characteristic, int delta, int N)
{
  m_CharacteristicsToIncreaseIfOverN.push_back(
    std::make_tuple(characteristic, delta, N));
}

WarScroll::WeaponUpgrade::WeaponUpgrade()
{}

WarScroll::WeaponUpgrade::WeaponUpgrade(const WarScroll::Weapon &weapon,
  const WarScroll::Ability &ability)
  : m_Weapon(weapon)
  , m_Ability(ability)
{}

void WarScroll::WeaponUpgrade::registerWeaponToReplace(const Weapon &weapon)
{
  m_WeaponsToReplace.push_back(weapon);
}

void WarScroll::WeaponUpgrade::registerAbilityToReplace(const Ability &ability)
{
  m_AbilitiesToReplace.push_back(ability);
}

void WarScroll::WeaponUpgrade::registerCharacteristicToIncrease(
  const std::string& name, int val)
{
  m_CharacteristicsToUpdate.push_back(std::make_pair(name, val));
}

void WarScroll::WeaponUpgrade::addAbility(const Ability &ability)
{
  m_AbilitiesToAdd.push_back(ability);
}

void WarScroll::UnitUpgrade::registerCharacteristicToIncrease(
  const std::string& name, int val)
{
  m_CharacteristicsToUpdate.push_back(std::make_pair(name, val));
}


void WarScroll::UnitUpgrade::addAbility(const WarScroll::Ability &ability)
{
  m_Abilities.push_back(ability);
}

void WarScroll::UnitUpgrade::addWeapon(const WarScroll::Weapon &weapon)
{
  m_Weapons.push_back(weapon);
}

void WarScroll::UnitUpgrade::addKeyWordConnection(
  const KeyWordConnection &connection)
{
  m_KeyWordConnections.push_back(connection);
}

void WarScroll::MountUpgrade::registerCharacteristicToIncrease(
  const std::string& name, int val)
{
  m_CharacteristicsToUpdate.push_back(std::make_pair(name, val));
}

void WarScroll::MountUpgrade::addWeapon(const WarScroll::Weapon &weapon)
{
  m_Weapons.push_back(weapon);
}

void WarScroll::MountUpgrade::addRiderWeaponToReplace(const Weapon &weapon)
{
  m_RiderWeaponsToReplace.push_back(weapon);
}

void WarScroll::MountUpgrade::addRiderAbilityToRemove(const Ability &ability)
{
  m_RiderAbilitiesToRemove.push_back(ability);
}

void WarScroll::MountUpgrade::addAbility(const Ability &ability)
{
  m_Abilities.push_back(ability);
}

void WarScroll::MountUpgrade::addSpell(const Spell &spell)
{
  m_Spells.push_back(spell);
}

void WarScroll::MountUpgrade::setCharacteristics(
  const Characteristic& characteristic)
{
  m_CharacteristicsToSet.push_back(characteristic);
}

void WarScroll::MountUpgrade::addKeyWordConnection(
  const KeyWordConnection &connection)
{
  m_KeyWordConnections.push_back(connection);
}

void WarScroll::ChampionWithOptions::addWeapon(const WarScroll::Weapon &weapon)
{
  m_Weapons.push_back(weapon);
}

void WarScroll::ChampionWithOptions::addAbility(
  const WarScroll::Ability &ability)
{
  m_Abilities.push_back(ability);
}

void WarScroll::ChampionWithOptions::addKeyWordConnection(
  const KeyWordConnection &connection)
{
  m_KeyWordConnections.push_back(connection);
}

WarScroll::WarScroll()
  : m_IsUnique(false)
  , m_MinUnitCount(1)
  , m_MaxUnitCount(1)
  , m_UnitCount(1)
  , m_PointsCost(0)
  , m_CanFly(false)
{}

WarScroll::WarScroll(const WarScroll &rhs)
  : m_Title(rhs.m_Title)
  , m_IsUnique(rhs.m_IsUnique)
  , m_Characteristics(rhs.m_Characteristics)
  , m_MinUnitCount(rhs.m_MinUnitCount)
  , m_MaxUnitCount(rhs.m_MaxUnitCount)
  , m_UnitCount(rhs.m_UnitCount)
  , m_PointsCost(rhs.m_PointsCost)
  , m_Abilities(rhs.m_Abilities)
  , m_Weapons(rhs.m_Weapons)
  , m_Spells(rhs.m_Spells)
  , m_AppliedUpgrades(rhs.m_AppliedUpgrades)
  , m_RegisteredUpgrades(rhs.m_RegisteredUpgrades)
  , m_AppliedMounts(rhs.m_AppliedMounts)
  , m_RegisteredMounts(rhs.m_RegisteredMounts)
  , m_AppliedChampionWithOptions(rhs.m_AppliedChampionWithOptions)
  , m_RegisteredChampionWithOptions(rhs.m_RegisteredChampionWithOptions)
  , m_AppliedMagicalSpecilizations(rhs.m_AppliedMagicalSpecilizations)
  , m_RegisteredMagicalSpecilizations(rhs.m_RegisteredMagicalSpecilizations)
  , m_CanFly(rhs.m_CanFly)
  , m_Keywords(rhs.m_Keywords)
  , m_AllianceType(rhs.m_AllianceType)
  , m_WeaponUpgrades(rhs.m_WeaponUpgrades)
  , m_Guid(rhs.m_Guid)
  , m_KeyWordConnections(rhs.m_KeyWordConnections)
{}

WarScroll &WarScroll::operator=(const WarScroll &rhs)
{
  m_Title = rhs.m_Title;
  m_IsUnique = rhs.m_IsUnique;
  m_Characteristics = rhs.m_Characteristics;
  m_MinUnitCount = rhs.m_MinUnitCount;
  m_MaxUnitCount = rhs.m_MaxUnitCount;
  m_UnitCount = rhs.m_UnitCount;
  m_PointsCost = rhs.m_PointsCost;
  m_Abilities = rhs.m_Abilities;
  m_Weapons = rhs.m_Weapons;
  m_Spells = rhs.m_Spells;
  m_AppliedUpgrades = rhs.m_AppliedUpgrades;
  m_RegisteredUpgrades = rhs.m_RegisteredUpgrades;
  m_AppliedMounts = rhs.m_AppliedMounts;
  m_RegisteredChampionWithOptions = rhs.m_RegisteredChampionWithOptions;
  m_AppliedChampionWithOptions = rhs.m_AppliedChampionWithOptions;
  m_AppliedMagicalSpecilizations = rhs.m_AppliedMagicalSpecilizations;
  m_RegisteredMagicalSpecilizations = rhs.m_RegisteredMagicalSpecilizations;
  m_RegisteredMounts = rhs.m_RegisteredMounts;
  m_CanFly = rhs.m_CanFly;
  m_Keywords = rhs.m_Keywords;
  m_AllianceType = rhs.m_AllianceType;
  m_WeaponUpgrades = rhs.m_WeaponUpgrades;
  m_Guid = rhs.m_Guid;
  m_KeyWordConnections = rhs.m_KeyWordConnections;

  return (*this);
}

void WarScroll::setMove(int move)
{
  auto it = m_Characteristics.find("Move");
  if (it != m_Characteristics.end()) {
    m_Characteristics["Move"] = move;
  } else {
    m_Characteristics.insert(std::make_pair("Move", move));
  }
}

void WarScroll::setWounds(int wounds)
{
  auto it = m_Characteristics.find("Wounds");
  if (it != m_Characteristics.end()) {
    m_Characteristics["Wounds"] = wounds;
  } else {
    m_Characteristics.insert(std::make_pair("Wounds", wounds));
  }
}

void WarScroll::setBravery(int bravery)
{
  auto it = m_Characteristics.find("Bravery");
  if (it != m_Characteristics.end()) {
    m_Characteristics["Bravery"] = bravery;
  } else {
    m_Characteristics.insert(std::make_pair("Bravery", bravery));
  }
}

void WarScroll::setSave(int save)
{
  auto it = m_Characteristics.find("Save");
  if (it != m_Characteristics.end()) {
    m_Characteristics["Save"] = save;
  } else {
    m_Characteristics.insert(std::make_pair("Save", save));
  }
}

void WarScroll::setCharacteristic(const Characteristic &characteristic)
{
  std::string stat = std::get<0>(characteristic);
  auto it = m_Characteristics.find(stat);
  if (it != m_Characteristics.end()) {
    m_Characteristics[stat] = std::get<1>(characteristic);
  } else {
    m_Characteristics.insert(std::make_pair(stat, std::get<1>(characteristic)));
  }
}

void WarScroll::setCharacteristics(int move, int wounds, int bravery, int save)
{
  m_Characteristics.insert(std::make_pair("Move", move));
  m_Characteristics.insert(std::make_pair("Wounds", wounds));
  m_Characteristics.insert(std::make_pair("Bravery", bravery));
  m_Characteristics.insert(std::make_pair("Save", save));
}

int WarScroll::getCharacteristic(const std::string &characteristic) const
{
  std::map<std::string, int>::const_iterator it =
    m_Characteristics.find(characteristic);
  if (it != m_Characteristics.end()) {
    return it->second;
  }
  return 0;
}

void WarScroll::incrementCharacteristic(const std::string &characteristic,
  int val)
{
  m_Characteristics[characteristic] += val;
}

void WarScroll::decrementCharacteristic(const std::string &characteristic,
  int val)
{
  m_Characteristics[characteristic] -= val;
}

void WarScroll::setMinMaxUnitCount(int minUnitCount, int maxUnitCount)
{
  Q_ASSERT(minUnitCount <= maxUnitCount);
  m_MinUnitCount = minUnitCount;
  m_MaxUnitCount = maxUnitCount;
  if (m_UnitCount < m_MinUnitCount) {
    m_UnitCount = m_MinUnitCount;
  } else if (m_UnitCount > m_MaxUnitCount) {
    m_UnitCount = m_MaxUnitCount;
  }
}

void WarScroll::refreshPointsCost()
{
  m_PointsCost = 1;
}

#ifdef Q_OS_WIN32
#pragma warning(disable : 4715)
#else
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wreturn-type"
#endif
const WarScroll::Ability &WarScroll::getAbility(const std::string &name) const
{
  std::map<std::string, Ability>::const_iterator it = m_Abilities.find(name);
  if (it != m_Abilities.end()) {
    return it->second;
  }
  Q_ASSERT(false && "Failed to find ability");
}
#ifdef Q_OS_WIN32
#pragma warning(default : 4715)
#else
#pragma GCC diagnostic pop
#endif

void WarScroll::addAbility(const WarScroll::Ability &ability)
{
  m_Abilities.insert(std::make_pair(ability.getName(), ability));
}

void WarScroll::removeAbility(const Ability &ability)
{
  auto it = m_Abilities.find(ability.getName());
  if (it != m_Abilities.end()) {
    if (ability == it->second) {
      m_Abilities.erase(it);
    }
  }
}

#ifdef Q_OS_WIN32
#pragma warning(disable : 4715)
#else
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wreturn-type"
#endif
const WarScroll::Weapon &WarScroll::getWeapon(const std::string &name) const
{
  std::map<std::string, Weapon>::const_iterator it = m_Weapons.find(name);
  if (it != m_Weapons.end()) {
    return it->second;
  }
  Q_ASSERT(false && "Failed to find ability");
}
#ifdef Q_OS_WIN32
#pragma warning(default : 4715)
#else
#pragma GCC diagnostic pop
#endif

void WarScroll::addWeapon(const WarScroll::Weapon &weapon)
{
  m_Weapons.insert(std::make_pair(weapon.getName(), weapon));
}

void WarScroll::removeWeapon(const WarScroll::Weapon &weapon)
{
  auto it = m_Weapons.find(weapon.getName());
  if (it != m_Weapons.end()) {
    if (weapon == it->second) {
      m_Weapons.erase(it);
    }
  }
}

const WarScroll::Spell &WarScroll::getSpell(const std::string &name) const
{
  for (const Spell &spell : m_Spells) {
    if (spell.getName() == name) {
      return spell;
    }
  }
  return m_EmptySpell;
}

void WarScroll::addSpell(const WarScroll::Spell &spell, int toCast, int cost)
{
  m_Spells.push_back(spell);
  m_Spells.back().setPointCost(cost);
  m_Spells.back().setToCast(toCast);
}

void WarScroll::addSpell(const WarScroll::Spell &spell)
{
  m_Spells.push_back(spell);
}

void WarScroll::addArcaneBolt()
{
  addSpell(WarScroll::Spell("Arcane Bolt"), 5, 1);
}

void WarScroll::addMysticShield()
{
  addSpell(WarScroll::Spell("Mystic Shield"), 6, 2);
}

void WarScroll::registerUnitUpgrade(const WarScroll::UnitUpgrade &upgrade)
{
  m_RegisteredUpgrades.push_back(upgrade);
}

void WarScroll::applyRegisteredUpgrade(const std::string &upgradeName)
{
  for (const UnitUpgrade &upgrade : m_RegisteredUpgrades) {
    if (upgrade.getName() == upgradeName) {
      m_AppliedUpgrades.push_back(upgrade);
      break;
    }
  }
}

void WarScroll::registerMountUpgrade(const WarScroll::MountUpgrade &upgrade)
{
  m_RegisteredMounts.push_back(upgrade);
}

void WarScroll::applyRegisteredMount(const std::string &mountName)
{
  for (const MountUpgrade &upgrade : m_RegisteredMounts) {
    if (upgrade.getName() == mountName) {
      m_AppliedMounts.push_back(upgrade);
      break;
    }
  }
}

void WarScroll::registerChampionWithOptions(
  const WarScroll::ChampionWithOptions &upgrade)
{
  m_RegisteredChampionWithOptions.push_back(upgrade);
}

void WarScroll::applyRegisteredChampionWithOptions(
  const std::string &championName)
{
  for (const ChampionWithOptions &upgrade : m_RegisteredChampionWithOptions) {
    if (upgrade.getName() == championName) {
      m_AppliedChampionWithOptions.push_back(upgrade);
      break;
    }
  }
}

void WarScroll::registerMagicalSpecialization(
  const MagicalSpecialization &upgrade)
{
  m_RegisteredMagicalSpecilizations.push_back(upgrade);
}

void WarScroll::applyRegisteredMagicalSpecialization(
  const std::string &specialization)
{
  for (const MagicalSpecialization &upgrade
    : m_RegisteredMagicalSpecilizations) {
    if (upgrade.getName() == specialization) {
      m_AppliedMagicalSpecilizations.push_back(upgrade);
      break;
    }
  }
}

void WarScroll::addKeyWord(const std::string &keyWord)
{
  m_Keywords.insert(keyWord);
}

void WarScroll::addKeyWords(const std::list<std::string>& keyWords)
{
  for (const std::string &keyWord : keyWords) {
    m_Keywords.insert(keyWord);
  }
}

bool WarScroll::keyWordExists(const std::string &keyWord)
{
  std::set<std::string>::const_iterator it = m_Keywords.find(keyWord);
  return (it == m_Keywords.end());
}

void WarScroll::addWeaponUpgrade(const WarScroll::WeaponUpgrade &upgrade)
{
  m_WeaponUpgrades.push_back(upgrade);
}

const WarScroll::WeaponUpgrade &WarScroll::getWeaponUpgrade(
  const std::string &weaponUpgrade, const std::string &abilityUpgrade,
  const std::string &secondaryWeapon) const
{
  if (!weaponUpgrade.empty() && !abilityUpgrade.empty()) {
    for (const WeaponUpgrade &weaponUpgradeI : m_WeaponUpgrades) {
      if (weaponUpgrade == weaponUpgradeI.getWeapon().getName() &&
        abilityUpgrade == weaponUpgradeI.getAbility().getName() &&
        secondaryWeapon == weaponUpgradeI.getSecondaryWeapon().getName()) {
          return weaponUpgradeI;
      }
    }
  } else {
    for (const WeaponUpgrade &weaponUpgradeI : m_WeaponUpgrades) {
      if (weaponUpgrade == weaponUpgradeI.getWeapon().getName() &&
        !weaponUpgradeI.getWeapon().getName().empty() &&
        weaponUpgradeI.getSecondaryWeapon().getName() == secondaryWeapon) {
        return weaponUpgradeI;
      } else if (abilityUpgrade == weaponUpgradeI.getAbility().getName() &&
        !weaponUpgradeI.getAbility().getName().empty() &&
        weaponUpgradeI.getSecondaryWeapon().getName() == secondaryWeapon) {
        return weaponUpgradeI;
      }
    }
  }
  return m_EmptyUpgrade;
}

void WarScroll::applyWeaponUpgrade(
  const WarScroll::WeaponUpgrade &weaponUpgrade)
{
  const std::list<Weapon> &weaponsToReplace =
    weaponUpgrade.weaponsToReplace();
  for (const Weapon &weapon : weaponsToReplace) {
    WeaponIterator it = m_Weapons.find(weapon.getName());
    if (it != m_Weapons.end()) {
      m_Weapons.erase(it);
      break;
    }
  }
  if (!weaponUpgrade.getWeapon().getName().empty()) {
    m_Weapons.insert(std::make_pair(weaponUpgrade.getWeapon().getName(),
      weaponUpgrade.getWeapon()));
  }

  const std::list<Ability> &abilitiesToReplace =
    weaponUpgrade.abilitiesToReplace();
  for (const Ability &ability : abilitiesToReplace) {
    AbilityIterator it = m_Abilities.find(ability.getName());
    if (it != m_Abilities.end()) {
      m_Abilities.erase(it);
      break;
    }
  }
  if (!weaponUpgrade.getAbility().getName().empty()) {
    m_Abilities.insert(std::make_pair(weaponUpgrade.getAbility().getName(),
    weaponUpgrade.getAbility()));
  }
  if (!weaponUpgrade.getSecondaryWeapon().getName().empty()) {
    m_Weapons.insert(std::make_pair(
      weaponUpgrade.getSecondaryWeapon().getName(),
      weaponUpgrade.getSecondaryWeapon()));
  }
}

std::string WarScroll::toString() const
{
  std::ostringstream out;
  out << (*this);
  return out.str();
}

void WarScroll::addKeyWordConnection(const KeyWordConnection &connection)
{
  m_KeyWordConnections.push_back(connection);
}
