#ifndef WARSCROLL_H
#define WARSCROLL_H

#include <QQuickItem>
#include <QUuid>

#include <functional>
#include <set>
#include <tuple>

class WarScrollFactory;

class WarScroll
{
public:
  typedef std::tuple<std::string, int> Characteristic;

  enum class GrandAllianceType
  {
    eChaos,
    eDeath,
    eDestruction,
    eOrder
  };

  static const int s_MaxDistance = 72;

  static void addSummonable(WarScroll &ws, const std::string &name, int toCast,
    int pointCost, int distance, int summonCount,
    const std::list<std::string> &keyWords);

  class Ability
  {
  public:
    typedef std::list<std::tuple<std::string, int, int>>
      CharacteristicIncreaseOverN_t;

  private:
    std::string m_Name;
    int m_Value;
    bool m_IsCommandAbility;
    int m_EveryNModel;
    int m_OverNModels;
    CharacteristicIncreaseOverN_t m_CharacteristicsToIncreaseIfOverN;

  public:
    Ability(std::string name = "", int value = 0, bool commandAbility = false)
      : m_Name(name)
      , m_Value(value)
      , m_IsCommandAbility(commandAbility)
      , m_EveryNModel(-1)
      , m_OverNModels(1)
    {}

    const std::string &getName() const {return m_Name;}
    int getValue() const {return m_Value;}
    bool getIsCommandAbility() const {return m_IsCommandAbility;}

    int getEveryNModels() const {return m_EveryNModel;}
    void setEveryNModels(int N) {m_EveryNModel = N;}

    int getOverNModels() const {return m_OverNModels;}
    void setOverNModels(int N) {m_OverNModels = N;}

    const CharacteristicIncreaseOverN_t &getCharacteristicsToIncreaseIfOverN()
      const {return m_CharacteristicsToIncreaseIfOverN;}
    void registerCharacteristicToIncreaseIfOverN(
      const std::string &characteristic, int delta, int N);

    friend bool operator==(const Ability &lhs, const Ability &rhs)
    {
      return (lhs.m_Name == rhs.m_Name && lhs.m_Value == rhs.m_Value &&
        lhs.m_IsCommandAbility == rhs.m_IsCommandAbility);
    }

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

    friend bool operator==(const Weapon &lhs, const Weapon &rhs)
    {
      return (lhs.m_Name == rhs.m_Name &&
        lhs.m_InitialDamage == rhs.m_InitialDamage &&
        lhs.m_InitialAttacks == rhs.m_InitialAttacks &&
        lhs.m_InitialToHit == rhs.m_InitialToHit &&
        lhs.m_InitialToWound == rhs.m_InitialToWound &&
        lhs.m_InitialToRend == rhs.m_InitialToRend &&
        lhs.m_InitialDamage == rhs.m_InitialDamage);
    }

    friend std::ostream &operator<<(std::ostream &out, const Weapon &weapon)
    {
      out << "\tName: " << weapon.m_Name << std::endl
        << "\tRange: " << weapon.m_InitialRange << "\"" << std::endl
        << "\tAttacks: " << weapon.m_InitialAttacks << std::endl
        << "\tTo Hit: " << weapon.m_InitialToHit << "+" << std::endl
        << "\tTo Wound: " << weapon.m_InitialToWound << "+" << std::endl
        << "\tRend: -" << weapon.m_InitialToRend << std::endl
        << "\tDamage: " << weapon.m_InitialDamage << std::endl;
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
    int m_ToCast;

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
      , m_ToCast(12)
    {}

    const std::string &getName() const {return m_Name;}
    int getRange() const {return m_InitialRange;}
    int getAttacks() const {return m_InitialAttacks;}
    int getToHit() const {return m_InitialToHit;}
    int getToWound() const {return m_InitialToWound;}
    int getToRend() const {return m_InitialToRend;}
    int getDamage() const {return m_InitialDamage;}
    int getPointsCost() const {return m_PointCost;}
    void setPointCost(int cost) {m_PointCost = cost;}
    int getToCast() const {return m_ToCast;}
    void setToCast(int cast) {m_ToCast = cast;}

    friend bool operator==(const Spell &lhs, const Spell &rhs)
    {
      return lhs.m_Name == rhs.m_Name &&
        lhs.m_InitialRange == rhs.m_InitialRange &&
        lhs.m_InitialAttacks == rhs.m_InitialAttacks &&
        lhs.m_InitialToHit == rhs.m_InitialToHit &&
        lhs.m_InitialToWound == rhs.m_InitialToWound &&
        lhs.m_InitialToRend == rhs.m_InitialToRend &&
        lhs.m_InitialDamage == rhs.m_InitialDamage &&
        lhs.m_PointCost == rhs.m_PointCost &&
        lhs.m_ToCast == rhs.m_ToCast;
    }

    friend std::ostream &operator<<(std::ostream &out, const Spell &spell)
    {
      out << "\tName: " << spell.m_Name << std::endl;
      if (spell.m_InitialRange >= 0) {
        out << "\tRange: " << spell.m_InitialRange << std::endl;
      }
      if (spell.m_InitialAttacks >= 0) {
        out << "\tAttacks: " << spell.m_InitialAttacks << std::endl;
      }
      if (spell.m_InitialToHit >= 0) {
        out << "\tTo Hit: " << spell.m_InitialToHit << std::endl;
      }
      if (spell.m_InitialToWound >= 0) {
        out << "\tTo Wound: " << spell.m_InitialToWound << std::endl;
      }
      if (spell.m_InitialToRend >= 0) {
        out << "\tTo Rend: " << spell.m_InitialToRend << std::endl;
      }
      if (spell.m_InitialDamage >= 0) {
        out << "\tTo Damage: " << spell.m_InitialDamage << std::endl;
      }
      out << "\tPoint Cost: " << spell.m_PointCost << std::endl;
      out << "\tTo Cast: " << spell.m_ToCast << std::endl;
      return out;
    }
  };

  class MagicalSpecialization
  {
  private:
    std::string m_Name;
    Spell m_Spell;

  public:
    MagicalSpecialization()
    {}

    MagicalSpecialization(const std::string &name, const Spell &spell)
      : m_Name(name)
      , m_Spell(spell)
    {}

    const std::string &getName() const {return m_Name;}
    const Spell &getSpell() const {return m_Spell;}
  };

  class WeaponUpgrade
  {
  private:
    Weapon m_Weapon;
    Ability m_Ability;
    Weapon m_SecondaryWeapon;
    Weapon m_TertiaryWeapon;

    std::list<Weapon> m_WeaponsToReplace;
    std::list<Ability> m_AbilitiesToReplace;
    std::list<std::pair<std::string, int>> m_CharacteristicsToUpdate;
    std::list<Ability> m_AbilitiesToAdd;

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

    const Weapon &getSecondaryWeapon() const {return m_SecondaryWeapon;}
    void setSecondaryWeapon(const Weapon &weapon) {m_SecondaryWeapon = weapon;}

    const Weapon &getTertiaryWeapon() const {return m_TertiaryWeapon;}
    void setTertiaryWeapon(const Weapon &weapon) {m_TertiaryWeapon = weapon;}

    const std::list<Ability> &getAbilitiesToAdd() const
    {return m_AbilitiesToAdd;}
    void addAbility(const Ability &ability);
  };

  class KeyWordConnection
  {
  public:
    enum class ConnectionAffectType
    {
      eEnemy, eFriendly, eSummons, eFriendOrFoe, eNone
    };

    static const int s_MaxConnections = 100;

  private:
    std::string m_KeyWord;
    int m_WithinDistance;
    Ability m_AbilityConnection;
    int m_ApplyIfOverNModels;
    ConnectionAffectType m_Affects;
    Spell m_SpellConnection;
    int m_MaxConnections;
    int m_CurrentConnections;
    std::string m_Name;
    int m_SummonCount;
    QUuid m_Guid;

  public:
    KeyWordConnection()
      : m_WithinDistance(-1)
      , m_ApplyIfOverNModels(-1)
      , m_Affects(ConnectionAffectType::eNone)
      , m_MaxConnections(-1)
      , m_CurrentConnections(-1)
      , m_SummonCount(-1)
    {}

    KeyWordConnection(const std::string &keyWord, int withinDistance,
      const Ability &viaAbility, int applyIfOverNModels,
      ConnectionAffectType affects, const Spell &spellConnection)
      : m_KeyWord(keyWord)
      , m_WithinDistance(withinDistance)
      , m_AbilityConnection(viaAbility)
      , m_ApplyIfOverNModels(applyIfOverNModels)
      , m_Affects(affects)
      , m_SpellConnection(spellConnection)
      , m_MaxConnections(s_MaxConnections)
      , m_CurrentConnections(0)
      , m_SummonCount(-1)
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

    const std::string &getName() const {return m_Name;}
    void setName(const std::string &name) {m_Name = name;}

    const std::string &getKeyWord() const {return m_KeyWord;}
    int getWithinDistance() const {return m_WithinDistance;}
    const Ability &getAbility() const {return m_AbilityConnection;}
    const Spell &getSpell() const {return m_SpellConnection;}
    int getApplyIfOverNModels() const {return m_ApplyIfOverNModels;}
    ConnectionAffectType getAffectType() const {return m_Affects;}

    int getMaxConnections() const {return m_MaxConnections;}
    void setMaxConnections(int max) {m_MaxConnections = max;}

    int getCurrentConnections() const {return m_CurrentConnections;}
    void incrementCurrentConnections() {m_CurrentConnections++;}

    int getSummonCount() const {return m_SummonCount;}
    void setSummonCount(int count) {m_SummonCount = count;}

    friend bool operator==(const KeyWordConnection &lhs,
      const KeyWordConnection &rhs)
    {
      return lhs.m_KeyWord == rhs.m_KeyWord &&
        lhs.m_WithinDistance == rhs.m_WithinDistance &&
        lhs.m_AbilityConnection == rhs.m_AbilityConnection &&
        lhs.m_ApplyIfOverNModels == rhs.m_ApplyIfOverNModels &&
        lhs.m_Affects == rhs.m_Affects &&
        lhs.m_SpellConnection == rhs.m_SpellConnection &&
        lhs.m_MaxConnections == rhs.m_MaxConnections &&
        lhs.m_CurrentConnections == rhs.m_CurrentConnections &&
        lhs.m_Name == rhs.m_Name &&
        lhs.m_SummonCount == rhs.m_SummonCount &&
        lhs.m_Guid == rhs.m_Guid;
    }

    friend std::ostream &operator<<(std::ostream &out,
      const KeyWordConnection &connection)
    {
      out << "Key Word: " << connection.m_KeyWord << " <== " << std::endl;
      if (!connection.m_AbilityConnection.getName().empty()) {
        out << connection.m_AbilityConnection << std::endl;
      } else if (!connection.m_SpellConnection.getName().empty()) {
        out << connection.m_SpellConnection << std::endl;
      } else {
        out << "\tName: " << connection.getName() << std::endl;
      }
      return out;
    }
  };

  class UnitUpgrade
  {
  public:
    enum class UnitUpgradeType
    {
      eChampion, eMusician, eBannerBearer, eShield, eMount, eOther, eNone
    };

  private:
    std::string m_Name;
    UnitUpgradeType m_Type;
    int m_PointsCost;
    std::list<std::pair<std::string, int>> m_CharacteristicsToUpdate;
    std::list<Ability> m_Abilities;
    std::list<Weapon> m_Weapons;
    bool m_CanFly;
    bool m_MakesScrollUnique;
    int m_EveryNModel;
    std::list<KeyWordConnection> m_KeyWordConnections;

  public:
    UnitUpgrade(std::string name = "",
      UnitUpgradeType type = UnitUpgradeType::eNone, int pointsCost = 0)
      : m_Name(name)
      , m_Type(type)
      , m_PointsCost(pointsCost)
      , m_CanFly(false)
      , m_MakesScrollUnique(false)
      , m_EveryNModel(-1)
    {}

    const std::string &getName() const {return m_Name;}
    UnitUpgradeType getUpgradeType() const {return m_Type;}
    int getPointsCost() const {return m_PointsCost;}

    bool providesCanFly() const {return m_CanFly;}
    void setProvidesFly(bool fly) {m_CanFly = fly;}

    bool makesUnitUnique() const {return m_MakesScrollUnique;}
    void setMakesUnitUnique(bool makesUnique)
    {m_MakesScrollUnique = makesUnique;}

    void registerCharacteristicToIncrease(const std::string& name, int val);
    const std::list<std::pair<std::string, int>> getCharacteristicsToUpdate()
      const {return m_CharacteristicsToUpdate;}

    const std::list<Ability> getAbilities() const {return m_Abilities;}
    void addAbility(const Ability &ability);

    const std::list<Weapon> getWeapons() const {return m_Weapons;}
    void addWeapon(const Weapon &weapon);

    int getEveryNModels() const {return m_EveryNModel;}
    void setEveryNModels(int N) {m_EveryNModel = N;}

    const std::list<KeyWordConnection> &getKeyWordConnections() const
    {return m_KeyWordConnections;}
    void addKeyWordConnection(const KeyWordConnection &connection);

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

  class MountUpgrade
  {
  public:
    typedef std::list<WarScroll::Characteristic> RiderCharacteristics;

  private:
    std::string m_Name;
    std::list<std::pair<std::string, int>> m_CharacteristicsToUpdate;
    std::list<Ability> m_Abilities;
    std::list<Weapon> m_Weapons;
    std::list<Weapon> m_RiderWeaponsToReplace;
    std::list<Ability> m_RiderAbilitiesToRemove;
    std::list<Spell> m_Spells;
    RiderCharacteristics m_CharacteristicsToSet;
    bool m_CanFly;
    bool m_MakesScrollUnique;
    std::list<KeyWordConnection> m_KeyWordConnections;

  public:
    MountUpgrade(std::string name = "", bool canFly = false)
      : m_Name(name)
      , m_CanFly(canFly)
      , m_MakesScrollUnique(false)
    {}

    const std::string &getName() const {return m_Name;}

    bool makesUnitUnique() const {return m_MakesScrollUnique;}
    void setMakesUnitUnique(bool makesUnique)
    {m_MakesScrollUnique = makesUnique;}

    bool providesCanFly() const {return m_CanFly;}
    void setProvidesFly(bool fly) {m_CanFly = fly;}

    void registerCharacteristicToIncrease(const std::string& name, int val);
    const std::list<std::pair<std::string, int>> getCharacteristicsToUpdate()
      const {return m_CharacteristicsToUpdate;}

    const std::list<Weapon> &getWeapons() const {return m_Weapons;}
    void addWeapon(const Weapon &weapon);

    const std::list<Weapon> &getRiderWeaponsToReplace() const
    {return m_RiderWeaponsToReplace;}
    void addRiderWeaponToReplace(const Weapon &weapon);

    const std::list<Ability> &getRiderAbilitiesToRemove() const
    {return m_RiderAbilitiesToRemove;}
    void addRiderAbilityToRemove(const Ability &ability);

    const std::list<Ability> getAbilities() const {return m_Abilities;}
    void addAbility(const Ability &ability);

    const std::list<Spell> getSpells() const {return m_Spells;}
    void addSpell(const Spell &spell);

    void setCharacteristics(const Characteristic& characteristic);
    const RiderCharacteristics &getChacarteristicsToSet() const
    {return m_CharacteristicsToSet;}

    const std::list<KeyWordConnection> &getKeyWordConnections() const
    {return m_KeyWordConnections;}
    void addKeyWordConnection(const KeyWordConnection &connection);

    friend std::ostream &operator<<(std::ostream &out,
      const MountUpgrade &upgrade)
    {
      out << "\tName: " << upgrade.m_Name << std::endl;
      return out;
    }
  };

  class ChampionWithOptions
  {
  private:
    std::string m_Name;
    int m_PointsCost;
    std::list<Weapon> m_Weapons;
    std::list<Ability> m_Abilities;
    int m_EveryNModel;
    std::list<KeyWordConnection> m_KeyWordConnections;

  public:
    ChampionWithOptions(std::string name = "", int pointsCost = -1)
      : m_Name(name)
      , m_PointsCost(pointsCost)
      , m_EveryNModel(-1)
    {}

    const std::string &getName() const {return m_Name;}
    int getPointsCost() const {return m_PointsCost;}

    const std::list<Weapon> &getWeapons() const {return m_Weapons;}
    void addWeapon(const Weapon &weapon);

    const std::list<Ability> &getAbilities() const {return m_Abilities;}
    void addAbility(const Ability &ability);

    int getEveryNModels() const {return m_EveryNModel;}
    void setEveryNModels(int N) {m_EveryNModel = N;}

    const std::list<KeyWordConnection> &getKeyWordConnections() const
    {return m_KeyWordConnections;}
    void addKeyWordConnection(const KeyWordConnection &connection);

    friend std::ostream &operator<<(std::ostream &out,
      const ChampionWithOptions &upgrade)
    {
      out << "\tName: " << upgrade.m_Name << std::endl;
      for (const auto &weapon : upgrade.m_Weapons) {
        out << weapon;
        out << std::endl;
      }
      for (const auto &ability : upgrade.m_Abilities) {
        out << ability;
        out << std::endl;
      }
      return out;
    }
  };

private:
  std::string m_Title;
  bool m_IsUnique;
  std::map<std::string, int> m_Characteristics;
  int m_MinUnitCount;
  int m_MaxUnitCount;
  int m_UnitCount;
  int m_PointsCost;
  typedef std::map<std::string, Ability>::iterator AbilityIterator;
  std::map<std::string, Ability> m_Abilities;
  typedef std::map<std::string, Weapon>::iterator WeaponIterator;
  std::multimap<std::string, Weapon> m_Weapons;
  std::list<Spell> m_Spells;
  std::list<UnitUpgrade> m_AppliedUpgrades;
  std::list<UnitUpgrade> m_RegisteredUpgrades;
  std::list<MountUpgrade> m_AppliedMounts;
  std::list<MountUpgrade> m_RegisteredMounts;
  std::list<ChampionWithOptions> m_AppliedChampionWithOptions;
  std::list<ChampionWithOptions> m_RegisteredChampionWithOptions;
  std::list<MagicalSpecialization> m_AppliedMagicalSpecilizations;
  std::list<MagicalSpecialization> m_RegisteredMagicalSpecilizations;
  bool m_CanFly;
  std::list<std::string> m_Keywords;
  GrandAllianceType m_AllianceType;
  std::list<WeaponUpgrade> m_WeaponUpgrades;
  WeaponUpgrade m_EmptyUpgrade;
  Spell m_EmptySpell;
  QUuid m_Guid;

  std::list<KeyWordConnection> m_KeyWordConnections;

public:
  WarScroll();

  WarScroll(const WarScroll &rhs);
  WarScroll &operator=(const WarScroll &rhs);

  std::string getTitle() const {return m_Title;}
  void setTitle(const std::string& title) {m_Title = title;}

  bool getIsUnique() const {return m_IsUnique;}
  void setIsUnique(bool isUnique) {m_IsUnique = isUnique;}

  void setMove(int move);
  void setWounds(int wounds);
  void setBravery(int bravery);
  void setSave(int save);
  void setCharacteristic(const Characteristic &characteristic);
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
  std::string refreshPointsCost();

  std::map<std::string, Ability> &getAbilities() {return m_Abilities;}
  const Ability &getAbility(const std::string &name) const;
  void addAbility(const Ability &ability);
  void removeAbility(const Ability &ability);

  std::multimap<std::string, Weapon> &getWeapons() {return m_Weapons;}
  const Weapon &getWeapon(const std::string &name) const;
  void addWeapon(const Weapon &weapon);
  void removeWeapon(const Weapon &weapon);

  const std::list<Spell> &getSpells() {return m_Spells;}
  const Spell &getSpell(const std::string &name) const;
  void addSpell(const Spell &spell, int toCast, int cost = 0);
  void addSpell(const WarScroll::Spell &spell);
  void addArcaneBolt();
  void addMysticShield();

  const std::list<UnitUpgrade> getRegisteredUnitUpgrades() const
  {return m_RegisteredUpgrades;}
  const std::list<UnitUpgrade> getAppliedUnitUpgrades() const
  {return m_AppliedUpgrades;}
  void registerUnitUpgrade(const UnitUpgrade &upgrade);
  void applyRegisteredUpgrade(const std::string &upgradeName);

  const std::list<MountUpgrade> getRegisteredMountUpgrades() const
  {return m_RegisteredMounts;}
  const std::list<MountUpgrade> getAppliedMountUpgrades() const
  {return m_AppliedMounts;}
  void registerMountUpgrade(const MountUpgrade &upgrade);
  void applyRegisteredMount(const std::string &mountName);

  const std::list<ChampionWithOptions> getRegisteredChampionWithOptions() const
  {return m_RegisteredChampionWithOptions;}
  const std::list<ChampionWithOptions> getAppliedChampionWithOptions() const
  {return m_AppliedChampionWithOptions;}
  void registerChampionWithOptions(const ChampionWithOptions &upgrade);
  void applyRegisteredChampionWithOptions(const std::string &championName);

  const std::list<MagicalSpecialization>
  getRegisteredMagicalSpecializations() const
  {
    return m_RegisteredMagicalSpecilizations;
  }
  const std::list<MagicalSpecialization>
  getAppliedMagicalSpecializations() const
  {
    return m_AppliedMagicalSpecilizations;
  }
  void registerMagicalSpecialization(const MagicalSpecialization &upgrade);
  void applyRegisteredMagicalSpecialization(const std::string &specialization);

  bool getCanFly() const {return m_CanFly;}
  void setCanFly(bool canFly) {m_CanFly = canFly;}

  const std::list<std::string> &getKeyWords() const {return m_Keywords;}
  void addKeyWord(const std::string &keyWord);
  void addKeyWords(const std::list<std::string>& keyWords);
  bool keyWordExists(const std::string &keyWord);

  GrandAllianceType getGrandAllianceType() const {return m_AllianceType;}
  void setGrandAllianceType(GrandAllianceType a) {m_AllianceType = a;}

  void addWeaponUpgrade(const WeaponUpgrade &upgrade);
  const std::list<WeaponUpgrade> getWeaponUpgrades() const
  {return m_WeaponUpgrades;}
  const WeaponUpgrade &getWeaponUpgrade(const std::string &weaponUpgrade,
    const std::string &abilityUpgrade,
    const std::string &secondaryweapon) const;
  void applyWeaponUpgrade(const WeaponUpgrade &weaponUpgrade);

  std::string toString() const;

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

  void addKeyWordConnection(const KeyWordConnection &connection);
  const std::list<KeyWordConnection> &getKeyWordConnections() const
  {return m_KeyWordConnections;}

  friend std::ostream &operator<<(std::ostream &out, const WarScroll &ws)
  {
    out << "Title: " << ws.m_Title << std::endl
      << "\tUnit Count: " << ws.m_UnitCount << std::endl
      << "\tPoint Count: " << ws.m_PointsCost << std::endl
      << std::endl;
    out << (ws.m_CanFly ? "\tFlyer\n" : "");
    out << std::endl;

    if (ws.m_Characteristics.size() == 4) {
      WarScroll &tmpWs = const_cast<WarScroll &>(ws);
      out << "\t" <<
        "Move: " << tmpWs.m_Characteristics["Move"] << "\" " <<
        "Wounds: " << tmpWs.m_Characteristics["Wounds"] << " " <<
        "Bravery: " << tmpWs.m_Characteristics["Bravery"] << " " <<
        "Save: " << tmpWs.m_Characteristics["Save"] << "+" << std::endl;
    }
    if (!ws.m_AppliedMounts.empty()) {
      out << "\t" << "Mounts:" << std::endl;
    }
    for (auto it : ws.m_AppliedMounts) {
      out << it;
      out << std::endl;
    }
    if (!ws.m_Weapons.empty()) {
      out << "\t" << "Weapons:" << std::endl;
    }
    for (auto it : ws.m_Weapons) {
      out << it.second;
      out << std::endl;
    }
    if (!ws.m_Abilities.empty()) {
      out << "\t" << "Possible Abilities:" << std::endl;
    }
    for (auto it : ws.m_Abilities) {
      out << it.second;
      out << std::endl;
    }
    if (!ws.m_Spells.empty()) {
      out << "\t" << "Spells:" << std::endl;
    }
    for (const auto &spell : ws.m_Spells) {
      out << spell;
      out << std::endl;
    }
    if (!ws.m_AppliedUpgrades.empty()) {
      out << "\t" << "Unit Upgrades:" << std::endl;
    }
    for (const auto &upgrade : ws.m_AppliedUpgrades) {
      out << upgrade;
      out << std::endl;
    }
    if (!ws.m_AppliedChampionWithOptions.empty()) {
      out << "\t" << "Champion's Abilities:" << std::endl;
    }
    for (const auto &champion : ws.m_AppliedChampionWithOptions) {
      out << champion;
      out << std::endl;
    }
    out << "\t" << "Keywords:" << std::endl;
    for (const auto &key : ws.m_Keywords) {
      out << "\t";
      out << key << ((key == *(ws.m_Keywords.rbegin())) ? " " : ", ");
      out << std::endl;
    }
    out << std::endl << "\t" << "Possible Connections:" << std::endl;
    for (const auto &connection : ws.m_KeyWordConnections) {
      out << "\t";
      out << connection;
    }
    //out << std::endl << "\t" << ws.m_Guid.toString().toStdString() <<
      //std::endl;
    return out;
  }
};

#endif // WARSCROLL_H
