#include "warscroll.h"

#include <sstream>
#include <utility>
#include <iostream>
#include <sstream>

void WarScroll::addSummonable(WarScroll &ws, const std::string &name,
  int toCast, int pointCost, int distance, int summonCount,
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

std::string WarScroll::refreshPointsCost()
{
  std::stringstream out;
  m_PointsCost = 0;

  /***
   * Characterstics Calculations
   */
  // Because this is a map order will be {Bravery, Move, Save, Wounds};
  int bravery = m_Characteristics["Bravery"];
  int move = m_Characteristics["Move"];
  int save = m_Characteristics["Save"];
  int wounds = m_Characteristics["Wounds"];

  m_PointsCost = bravery + move + (7 - save) + wounds;
  m_PointsCost *= m_UnitCount;

  out << "POINTS CALCULATIONS" << std::endl;

  out << "CHARACTERISTICS: " << std::endl;
  out << "models * (bravery + move + (7 - save) + wounds) = points" <<
    std::endl;
  out << m_UnitCount << " * (" << bravery << " + " << move <<
    " + (7 - " << save << ") + " << wounds << ") = " <<
    m_PointsCost << std::endl;

  // Decrease unit size by one if there is a champion present. He is calculated
  // separatly from the unit.
  m_UnitCount -= static_cast<int>(m_AppliedChampionWithOptions.size());

  out << "Points = " << m_PointsCost << std::endl << std::endl;

  /***
   * Ability Calculations
   */
  out << "ABILTIES:" << std::endl;
  out << getTitle() << " has " << m_Abilities.size() << " abities." <<
    std::endl;
  out << "cost * (models / N) = points" << std::endl;
  for (const auto &ability : m_Abilities) {
    int hasToBeOverN = ability.second.getOverNModels();
    int modelsWithAbiliy = m_UnitCount;
    int everyNModels = ability.second.getEveryNModels();
    if (m_UnitCount >= hasToBeOverN) {
      if (everyNModels > 0) {
        modelsWithAbiliy = m_UnitCount / everyNModels;
      } else {
        everyNModels = 1;
      }
    } else if (everyNModels < 0){
      everyNModels = 1;
    }
    int abilityCost = (ability.second.getValue() * modelsWithAbiliy);

    out << ability.second.getName() << ": " <<
      ability.second.getValue() << " * (" << m_UnitCount << " / " <<
      everyNModels << ") = " << abilityCost << std::endl;
    m_PointsCost += abilityCost;
  }

  out << "Points = " << m_PointsCost << std::endl << std::endl;

  /***
   * Weapon Calculations
   */
  out << "WEAPONS:" << std::endl;
  out << getTitle() << " has " << m_Weapons.size() << " weapons." <<
    std::endl;
  out << "ceil((range + ((attacks * models) * ((7 - to hit) / 6) * " <<
    "((7 - to wound) / 6)) * damage + rend) = weaponCost" <<
    std::endl;
  for (const auto &weapon : m_Weapons) {
    int range = weapon.second.getRange();
    int attacks = weapon.second.getAttacks();
    int hit = weapon.second.getToHit();
    int wound = weapon.second.getToWound();
    int rend = weapon.second.getToRend();
    int damage = weapon.second.getDamage();

    float weaponCost = (static_cast<float>(range) +
      (static_cast<float>(attacks * m_UnitCount) * ((7 - hit) / 6.0f) *
      ((7 - wound) / 6.0f)) * static_cast<float>(damage) +
      static_cast<float>(rend));

    out << weapon.second.getName() <<
      ": ceil((" << range << " + ((" << attacks << " * " << m_UnitCount <<
      ") * ((7 - " << hit << ") / 6) * ((7 - " << wound << ") / 6)) * " <<
      damage << ") + " << rend << ") = " << std::ceil(weaponCost) << std::endl;

    m_PointsCost += std::ceil(weaponCost);
  }

  out << "Points = " << m_PointsCost << std::endl << std::endl;

  /***
   * Spell Calculations
   */
  out << "SPELLS:" << std::endl;
  out << getTitle() << " has " << m_Spells.size() << " spell." <<
    std::endl;
  out << "ceil((range + (attacks * ((7 - to hit) / 6) * " <<
    "((7 - to wound) / 6)) * damage + rend) + ((13 - to cast) * cost) = " <<
    "spellCost" << std::endl;
  for (const auto &spell : m_Spells) {
    int range = spell.getRange();
    int attacks = spell.getAttacks();
    int hit = spell.getToHit();
    int wound = spell.getToWound();
    int rend = spell.getToRend();
    int damage = spell.getDamage();
    int cost = spell.getPointsCost();
    int cast = spell.getToCast();

    int points = 0;

    if (range > 0 && hit > 0 && wound > 0) {
      float weaponCost = (static_cast<float>(range) +
        (static_cast<float>(attacks) * ((7 - hit) / 6.0f) *
        ((7 - wound) / 6.0f)) * static_cast<float>(damage) +
        static_cast<float>(rend));
      out << spell.getName() <<
        ": ceil((" << range << " + (" << attacks <<
        " * ((7 - " << hit << ") / 6) * ((7 - " << wound << ") / 6)) * " <<
        damage << ") + " << rend << ") = " << std::ceil(weaponCost) <<
        std::endl;

      points += std::ceil(weaponCost);
    }

    if (points != 0) {
      int tmp = points;
      points += ((13 - cast) * cost);
      out << tmp << " + ((13 - " << cast << ") * " <<
        cost << ") = " << points << std::endl;
    } else {
      points += ((13 - cast) * cost);
      out << "  " << spell.getName() << ": ((13 - " << cast << ") * " <<
        cost << ") = " << points <<
        std::endl;
    }

    m_PointsCost += points;
  }

  out << "Points = " << m_PointsCost << std::endl << std::endl;

  /***
   * Champions with Options
   */
  out << "UPGRADABLE CHAMPIONS:" << std::endl;
  out << "ceil((range + (attacks * ((7 - to hit) / 6) * " <<
        "((7 - to wound) / 6)) * damage + rend) = weaponCost" <<
        std::endl;
  for (const auto &champion : m_AppliedChampionWithOptions) {
    out << "  Cost of " << champion.getName() << ": " <<
      champion.getPointsCost() << std::endl;
    m_PointsCost += champion.getPointsCost();

    for (const auto &weapon : champion.getWeapons()) {
      int range = weapon.getRange();
      int attacks = weapon.getAttacks();
      int hit = weapon.getToHit();
      int wound = weapon.getToWound();
      int rend = weapon.getToRend();
      int damage = weapon.getDamage();

      float weaponCost = (static_cast<float>(range) +
        (static_cast<float>(attacks) * ((7 - hit) / 6.0f) *
        ((7 - wound) / 6.0f)) * static_cast<float>(damage) +
        static_cast<float>(rend));

      out << weapon.getName() <<
        ": ceil((" << range << " + (" << attacks <<
        " * ((7 - " << hit << ") / 6) * ((7 - " << wound << ") / 6)) * " <<
        damage << ") + " << rend << ") = " << std::ceil(weaponCost) <<
        std::endl;
      m_PointsCost += std::ceil(weaponCost);
    }

    for (const auto &ability : champion.getAbilities()) {
      int modelsWithAbiliy = 1;
      int abilityCost = (ability.getValue() * modelsWithAbiliy);
      out << ability.getName() << ": " <<
        ability.getValue() << " = " << abilityCost << std::endl;
      m_PointsCost += abilityCost;
    }
  }

  out << "Points = " << m_PointsCost << std::endl << std::endl;

  /***
   * Unit Upgrades
   */
  out << "UNIT UPGRADES" << std::endl;
  for (const auto &upgrade : m_AppliedUpgrades) {
    out << "Cost of " << upgrade.getName() << ": " <<
      upgrade.getPointsCost() << std::endl;
    m_PointsCost += upgrade.getPointsCost();
  }

  out << "Points = " << m_PointsCost << std::endl << std::endl;

  out << (m_CanFly ? "FLYS = 2" : "");
  if (m_CanFly) {
    m_PointsCost += 2;
  }

  out << "Points = " << m_PointsCost << std::endl << std::endl;

  out << "TOTAL POINTS COST FOR " << getTitle() << " = " <<
    m_PointsCost << std::endl;

  std::cout << out.str() << std::endl;
  return out.str();
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
      bool unitCanFly = m_CanFly;
      m_AppliedUpgrades.push_back(upgrade);

      const std::list<std::pair<std::string, int>> characteristics =
        upgrade.getCharacteristicsToUpdate();
      for (const auto &upgradeCharacteristic : characteristics) {
        incrementCharacteristic(upgradeCharacteristic.first,
          upgradeCharacteristic.second);
      }
      for (const auto &ability : upgrade.getAbilities()) {
        addAbility(ability);
      }
      for (const auto &weapon : upgrade.getWeapons()) {
        addWeapon(weapon);
      }
      for (const auto &connection : upgrade.getKeyWordConnections()) {
        addKeyWordConnection(connection);
      }
      if (upgrade.getUpgradeType() == UnitUpgrade::UnitUpgradeType::eMount) {
        registerMountUpgrade(WarScroll::MountUpgrade(upgrade.getName()));
        applyRegisteredMount(upgrade.getName());
      }

      unitCanFly |= upgrade.providesCanFly();

      if (upgrade.makesUnitUnique()) {
        setIsUnique(true);
      }

      setCanFly(unitCanFly);

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

      // Remove old things first in the case that mount adds them back
      for (const auto &weapon : upgrade.getRiderWeaponsToReplace()) {
        removeWeapon(weapon);
      }
      for (const auto &ability : upgrade.getRiderAbilitiesToRemove()) {
        removeAbility(ability);
      }
      for (const auto &characteristic : upgrade.getChacarteristicsToSet()){
        setCharacteristic(characteristic);
      }
      // Now that old abilities and weapons gone it is now okay to add
      // all the new items.
      const std::list<WarScroll::Weapon> weapons = upgrade.getWeapons();
      for (const auto &weapon : weapons) {
        addWeapon(weapon);
      }
      const std::list<WarScroll::Ability> abilities = upgrade.getAbilities();
      for (const auto &ability : abilities) {
        addAbility(ability);
      }
      for (const auto &stat : upgrade.getCharacteristicsToUpdate()) {
        incrementCharacteristic(stat.first, stat.second);
      }
      setCanFly(upgrade.providesCanFly() || getCanFly());

      for (const auto &connection : upgrade.getKeyWordConnections()) {
        addKeyWordConnection(connection);
      }
      if (upgrade.makesUnitUnique()) {
        setIsUnique(true);
      }
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

      for (const auto &connection : upgrade.getKeyWordConnections()) {
        addKeyWordConnection(connection);
      }

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
      addSpell(upgrade.getSpell());
      break;
    }
  }
}

void WarScroll::addKeyWord(const std::string &keyWord)
{
  m_Keywords.push_back(keyWord);
}

void WarScroll::addKeyWords(const std::list<std::string>& keyWords)
{
  for (const std::string &keyWord : keyWords) {
    m_Keywords.push_back(keyWord);
  }
}

bool WarScroll::keyWordExists(const std::string &keyWord)
{
  std::list<std::string>::const_iterator it = std::find(m_Keywords.begin(),
    m_Keywords.end(), keyWord);
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

  for (const auto &i : weaponUpgrade.getCharacteristicsToUpdate()) {
    incrementCharacteristic(i.first, i.second);
  }
  for (const auto &i : weaponUpgrade.getAbilitiesToAdd()) {
    addAbility(i);
  }
  if (!weaponUpgrade.getTertiaryWeapon().getName().empty()) {
    addWeapon(weaponUpgrade.getTertiaryWeapon());
  }
}

std::string WarScroll::toString() const
{
  std::ostringstream out;
  out << (*this) << std::endl << std::endl;
  out << const_cast<WarScroll &>(*this).refreshPointsCost();
  return out.str();
}

void WarScroll::addKeyWordConnection(const KeyWordConnection &connection)
{
  m_KeyWordConnections.push_back(connection);
}
