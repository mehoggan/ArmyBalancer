#include "warscroll.h"

#include <utility>

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

void WarScroll::UnitUpgrade::registerCharacteristicToIncrease(
  const std::string& name, int val)
{
  m_CharacteristicsToUpdate.push_back(std::make_pair(name, val));
}

WarScroll::WarScroll()
  : m_MinUnitCount(1)
  , m_MaxUnitCount(1)
  , m_UnitCount(1)
  , m_PointsCost(0)
  , m_CanFly(false)
{}

WarScroll::WarScroll(const WarScroll &rhs)
  : m_Title(rhs.m_Title)
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
  , m_CanFly(rhs.m_CanFly)
  , m_Keywords(rhs.m_Keywords)
  , m_AllianceType(rhs.m_AllianceType)
  , m_WeaponUpgrades(rhs.m_WeaponUpgrades)
  , m_Guid(QUuid())
{}

WarScroll &WarScroll::operator=(const WarScroll &rhs)
{
  m_Title = rhs.m_Title;
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
  m_CanFly = rhs.m_CanFly;
  m_Keywords = rhs.m_Keywords;
  m_AllianceType = rhs.m_AllianceType;
  m_WeaponUpgrades = rhs.m_WeaponUpgrades;
  m_Guid = QUuid();

  return (*this);
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

const WarScroll::Ability &WarScroll::getAbility(const std::string &name) const
{
  std::map<std::string, Ability>::const_iterator it = m_Abilities.find(name);
  if (it != m_Abilities.end()) {
    return it->second;
  }
  Q_ASSERT(false && "Failed to find ability");
}

void WarScroll::addAbility(const WarScroll::Ability &ability)
{
  m_Abilities.insert(std::make_pair(ability.getName(), ability));
}

const WarScroll::Weapon &WarScroll::getWeapon(const std::string &name) const
{
  std::map<std::string, Weapon>::const_iterator it = m_Weapons.find(name);
  if (it != m_Weapons.end()) {
    return it->second;
  }
  Q_ASSERT(false && "Failed to find ability");
}

void WarScroll::addWeapon(const WarScroll::Weapon &weapon)
{
  m_Weapons.insert(std::make_pair(weapon.getName(), weapon));
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

void WarScroll::addSpell(const WarScroll::Spell &spell, int cost)
{
  m_Spells.push_back(spell);
  m_Spells.back().setPointCost(cost);
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
  const std::string &weaponUpgrade) const
{
  for (const WeaponUpgrade &weaponUpgradeI : m_WeaponUpgrades) {
    if (weaponUpgrade == weaponUpgradeI.getWeapon().getName() ||
      weaponUpgrade == weaponUpgradeI.getAbility().getName()) {
      return weaponUpgradeI;
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
      m_Weapons.insert(std::make_pair(weaponUpgrade.getWeapon().getName(),
        weaponUpgrade.getWeapon()));
      break;
    }
  }

  const std::list<Ability> &abilitiesToReplace =
    weaponUpgrade.abilitiesToReplace();
  for (const Ability &ability : abilitiesToReplace) {
    AbilityIterator it = m_Abilities.find(ability.getName());
    if (it != m_Abilities.end()) {
      m_Abilities.erase(it);
      m_Abilities.insert(std::make_pair(weaponUpgrade.getAbility().getName(),
        weaponUpgrade.getAbility()));
      break;
    }
  }
}
