﻿#ifndef WARSCROLL_H
#define WARSCROLL_H

#include <QQuickItem>
#include <QUuid>

#include <functional>
#include <set>

class WarScrollFactory;

class WarScroll
{
public:
  enum class GrandAllianceType
  {
    eChaos,
    eDeath,
    eDestruction,
    eOrder
  };

  class Ability
  {
  private:
    std::string m_Name;
    int m_Value;
    bool m_IsCommandAbility;

  public:
    Ability(std::string name = "", int value = 0, bool commandAbility = false)
      : m_Name(name)
      , m_Value(value)
      , m_IsCommandAbility(commandAbility)
    {}

    const std::string &getName() const {return m_Name;}
    int getValue() const {return m_Value;}
    bool getIsCommandAbility() const {return m_IsCommandAbility;}

    friend std::ostream &operator<<(std::ostream &out, const Ability &ability)
    {
      out << "\tName: " << ability.m_Name << std::endl
        << "\tCost: " << ability.m_Value << std::endl
        << "\t" << (ability.m_IsCommandAbility ? "Command Ability" : "")
        << std::endl;

      return out;
    }
  };

  class Weapon
  {
  private:
    std::string m_Name;
    int m_InitialRange;
    int m_InitialAttacks;
    int m_InitialToHit;
    int m_InitialToWound;
    int m_InitialToRend;
    int m_InitialDamage;

  public:
    Weapon(std::string name = "", int range = -1, int attacks = -1,
      int toHit = -1, int toWound = -1, int toRend = -1, int toDamage = -1)
      : m_Name(name)
      , m_InitialRange(range)
      , m_InitialAttacks(attacks)
      , m_InitialToHit(toHit)
      , m_InitialToWound(toWound)
      , m_InitialToRend(toRend)
      , m_InitialDamage(toDamage)
    {}

    const std::string &getName() const {return m_Name;}
    int getRange() const {return m_InitialRange;}
    int getAttacks() const {return m_InitialAttacks;}
    int getToHit() const {return m_InitialToHit;}
    int getToWound() const {return m_InitialToWound;}
    int getToRend() const {return m_InitialToRend;}
    int getDamage() const {return m_InitialDamage;}

    friend std::ostream &operator<<(std::ostream &out, const Weapon &weapon)
    {
      out << "\tName: " << weapon.m_Name << std::endl
        << "\tRange: " << weapon.m_InitialRange << std::endl
        << "\tAttacks: " << weapon.m_InitialAttacks << std::endl
        << "\tTo Hit: " << weapon.m_InitialToHit << std::endl
        << "\tTo Wound: " << weapon.m_InitialToWound << std::endl
        << "\tTo Rend: " << weapon.m_InitialToWound << std::endl
        << "\tTo Damage: " << weapon.m_InitialDamage << std::endl;
      return out;
    }
  };

  class Spell
  {
  private:
    std::string m_Name;
    int m_InitialRange;
    int m_InitialAttacks;
    int m_InitialToHit;
    int m_InitialToWound;
    int m_InitialToRend;
    int m_InitialDamage;

    int m_PointCost;

  public:
    Spell(std::string name = "", int range = -1, int attacks = -1,
      int toHit = -1, int toWound = -1, int toRend = -1, int toDamage = -1)
      : m_Name(name)
      , m_InitialRange(range)
      , m_InitialAttacks(attacks)
      , m_InitialToHit(toHit)
      , m_InitialToWound(toWound)
      , m_InitialToRend(toRend)
      , m_InitialDamage(toDamage)
      , m_PointCost(0)
    {}

    const std::string &getName() const {return m_Name;}
    int getRange() const {return m_InitialRange;}
    int getAttacks() const {return m_InitialAttacks;}
    int getToHit() const {return m_InitialToHit;}
    int getToWound() const {return m_InitialToWound;}
    int getToRend() const {return m_InitialToRend;}
    int getDamage() const {return m_InitialDamage;}
    void setPointCost(int cost) {m_PointCost = cost;}

    friend std::ostream &operator<<(std::ostream &out, const Spell &spell)
    {
      out << "\tName: " << spell.m_Name << std::endl
        << "\tRange: " << spell.m_InitialRange << std::endl
        << "\tAttacks: " << spell.m_InitialAttacks << std::endl
        << "\tTo Hit: " << spell.m_InitialToHit << std::endl
        << "\tTo Wound: " << spell.m_InitialToWound << std::endl
        << "\tTo Rend: " << spell.m_InitialToWound << std::endl
        << "\tTo Damage: " << spell.m_InitialDamage << std::endl
        << "\tPoint Cost: " << spell.m_PointCost << std::endl;
      return out;
    }
  };

  class WeaponUpgrade
  {
  private:
    Weapon m_Weapon;
    Ability m_Ability;

    std::list<Weapon> m_WeaponsToReplace;
    std::list<Ability> m_AbilitiesToReplace;
    std::list<std::pair<std::string, int>> m_CharacteristicsToUpdate;

  public:
    WeaponUpgrade();
    WeaponUpgrade(const Weapon &weapon, const Ability &ability);

    void registerWeaponToReplace(const Weapon &weapon);
    void registerAbilityToReplace(const Ability &ability);

    void registerCharacteristicToIncrease(const std::string& name, int val);
    const std::list<std::pair<std::string, int>> getCharacteristicsToUpdate()
      const {return m_CharacteristicsToUpdate;}

    const Weapon &getWeapon() const {return m_Weapon;}
    const Ability &getAbility() const {return m_Ability;}

    const std::list<Weapon> &weaponsToReplace() const
    {return m_WeaponsToReplace;}
    const std::list<Ability> &abilitiesToReplace() const
    {return m_AbilitiesToReplace;}
  };

  class UnitUpgrade
  {
  public:
    enum class UnitUpgradeType
    {
      eChampion, eMusician, eBannerBearer, eShield, eNone
    };
  private:
    std::string m_Name;
    UnitUpgradeType m_Type;
    int m_PointsCost;
    std::list<std::pair<std::string, int>> m_CharacteristicsToUpdate;

  public:
    UnitUpgrade(std::string name = "",
      UnitUpgradeType type = UnitUpgradeType::eNone, int pointsCost = 0)
      : m_Name(name)
      , m_Type(type)
      , m_PointsCost(pointsCost)
    {}

    const std::string &getName() const {return m_Name;}
    UnitUpgradeType getUpgradeType() const {return m_Type;}
    int getPointsCost() const {return m_PointsCost;}

    void registerCharacteristicToIncrease(const std::string& name, int val);
    const std::list<std::pair<std::string, int>> getCharacteristicsToUpdate()
      const {return m_CharacteristicsToUpdate;}

    friend std::ostream &operator<<(std::ostream &out,
      const UnitUpgrade &upgrade)
    {
      out << "\tName: " << upgrade.m_Name << std::endl
        << "\tCost: " << upgrade.m_PointsCost << std::endl;

      switch (upgrade.m_Type) {
      case UnitUpgradeType::eChampion: out << "\tChampion";
          break;
      case UnitUpgradeType::eMusician: out << "\tMusician";
          break;
      case UnitUpgradeType::eBannerBearer: out << "\tBanner Bearer";
          break;
      default:
          break;
      }
      out << std::endl;

      return out;
    }
  };

private:
  std::string m_Title;
  std::map<std::string, int> m_Characteristics;
  int m_MinUnitCount;
  int m_MaxUnitCount;
  int m_UnitCount;
  int m_PointsCost;
  typedef std::map<std::string, Ability>::iterator AbilityIterator;
  std::map<std::string, Ability> m_Abilities;
  typedef std::map<std::string, Weapon>::iterator WeaponIterator;
  std::map<std::string, Weapon> m_Weapons;
  std::list<Spell> m_Spells;
  std::list<UnitUpgrade> m_AppliedUpgrades;
  std::list<UnitUpgrade> m_RegisteredUpgrades;
  bool m_CanFly;
  std::set<std::string> m_Keywords;
  GrandAllianceType m_AllianceType;
  std::list<WeaponUpgrade> m_WeaponUpgrades;
  WeaponUpgrade m_EmptyUpgrade;
  Spell m_EmptySpell;
  QUuid m_Guid;

public:
  WarScroll();

  WarScroll(const WarScroll &rhs);
  WarScroll &operator=(const WarScroll &rhs);

  std::string getTitle() const {return m_Title;}
  void setTitle(const std::string& title) {m_Title = title;}

  void setCharacteristics(int move, int wounds, int bravery, int save);
  int getCharacteristic(const std::string &characteristic) const;
  void incrementCharacteristic(const std::string &characteristic, int val);
  void decrementCharacteristic(const std::string &characteristic, int val);

  void setMinMaxUnitCount(int minUnitCount, int maxUnitCount);
  int getMinUnitCount() const {return m_MinUnitCount;}
  int getMaxUnitCount() const {return m_MaxUnitCount;}

  int getUnitCount() const {return m_UnitCount;}
  void setUnitCount(int unitCount) {m_UnitCount = unitCount;}

  int getPointsCost() const {return m_PointsCost;}
  void refreshPointsCost();

  std::map<std::string, Ability> &getAbilities() {return m_Abilities;}
  const Ability &getAbility(const std::string &name) const;
  void addAbility(const Ability &ability);

  std::map<std::string, Weapon> &getWeapons() {return m_Weapons;}
  const Weapon &getWeapon(const std::string &name) const;
  void addWeapon(const Weapon &weapon);

  const std::list<Spell> &getSpells() {return m_Spells;}
  const Spell &getSpell(const std::string &name) const;
  void addSpell(const Spell &spell, int cost = 0);

  const std::list<UnitUpgrade> getRegisteredUnitUpgrades() const
  {return m_RegisteredUpgrades;}
  const std::list<UnitUpgrade> getAppliedUnitUpgrades() const
  {return m_RegisteredUpgrades;}
  void registerUnitUpgrade(const UnitUpgrade &upgrade);
  void applyRegisteredUpgrade(const std::string &upgradeName);

  bool getCanFly() const {return m_CanFly;}
  void setCanFly(bool canFly) {m_CanFly = canFly;}

  void addKeyWord(const std::string &keyWord);
  void addKeyWords(const std::list<std::string>& keyWords);
  bool keyWordExists(const std::string &keyWord);

  GrandAllianceType getGrandAllianceType() const {return m_AllianceType;}
  void setGrandAllianceType(GrandAllianceType a) {m_AllianceType = a;}

  void addWeaponUpgrade(const WeaponUpgrade &upgrade);
  const std::list<WeaponUpgrade> getWeaponUpgrades() const
  {return m_WeaponUpgrades;}
  const WeaponUpgrade &getWeaponUpgrade(const std::string &weaponUpgrade) const;
  void applyWeaponUpgrade(const WeaponUpgrade &weaponUpgrade);

  void regenGuid()
  {
    m_Guid = QUuid(
      std::rand() % 1024,
      std::rand() % 256,
      std::rand() % 256,
      std::rand() % 128,
      std::rand() % 128,
      std::rand() % 128,
      std::rand() % 128,
      std::rand() % 128,
      std::rand() % 128,
      std::rand() % 128,
      std::rand() % 128);
  }
  const QUuid &getGuid() const {return m_Guid;}

  friend std::ostream &operator<<(std::ostream &out, const WarScroll &ws)
  {
    out << "Title: " << ws.m_Title << std::endl
      << "\tUnit Count: " << ws.m_UnitCount << std::endl
      << "\tPoint Count: " << ws.m_PointsCost << std::endl
      << std::endl;
    out << (ws.m_CanFly ? "Flyer\n" : "");


    bool first = true;
    for (auto it : ws.m_Characteristics) {
      if (first) {
        out << "\t";
      }
      out << it.first << ": " << it.second << " ";
    }
    out << std::endl << std::endl;
    out << "\t" << "Weapons:" << std::endl;
    for (auto it : ws.m_Weapons) {
      out << it.second;
      out << std::endl;
    }
    out << "\t" << "Ablities:" << std::endl;
    for (auto it : ws.m_Abilities) {
      out << it.second;
      out << std::endl;
    }
    out << "\t" << "Spells:" << std::endl;
    for (const auto &spell : ws.m_Spells) {
      out << spell;
      out << std::endl;
    }
    out << "\t" << "Unit Upgrades:" << std::endl;
    for (const auto &upgrade : ws.m_AppliedUpgrades) {
      out << upgrade;
      out << std::endl;
    }
    first = true;
    out << "\t" << "Keywords:" << std::endl;
    for (const auto &key : ws.m_Keywords) {
      if (first) {
        out << "\t";
      }
      out << key << " ";
    }
    out << std::endl << "\t" << ws.m_Guid.toString().toStdString() << std::endl;
    return out;
  }
};

#endif // WARSCROLL_H
