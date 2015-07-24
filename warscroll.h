#ifndef WARSCROLL_H
#define WARSCROLL_H

#include <QQuickItem>

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
    int m_InitialToDamage;

  public:
    Weapon(std::string name = "", int range = -1, int attacks = -1,
      int toHit = -1, int toWound = -1, int toRend = -1, int toDamage = -1)
      : m_Name(name)
      , m_InitialRange(range)
      , m_InitialAttacks(attacks)
      , m_InitialToHit(toHit)
      , m_InitialToWound(toWound)
      , m_InitialToRend(toRend)
      , m_InitialToDamage(toDamage)
    {}

    const std::string &getName() const {return m_Name;}
    int getRange() const {return m_InitialRange;}
    int getAttacks() const {return m_InitialAttacks;}
    int getToHit() const {return m_InitialToHit;}
    int getToWound() const {return m_InitialToWound;}
    int getToRend() const {return m_InitialToRend;}
    int getToDamage() const {return m_InitialToDamage;}
  };

  class WeaponUpgrade
  {
  private:
    Weapon m_Weapon;
    Ability m_Ability;

    std::list<Weapon> m_WeaponsToReplace;
    std::list<Ability> m_AbilitiesToReplace;

  public:
    WeaponUpgrade();
    WeaponUpgrade(const Weapon &weapon, const Ability &ability);

    void registerWeaponToReplace(const Weapon &weapon);
    void registerAbilityToReplace(const Ability &ability);

    const Weapon &getWeapon() const {return m_Weapon;}
    const Ability &getAbility() const {return m_Ability;}

    const std::list<Weapon> &weaponsToReplace() const
    {return m_WeaponsToReplace;}
    const std::list<Ability> &abilitiesToReplace() const
    {return m_AbilitiesToReplace;}
  };

private:
  std::string m_Title;
  std::map<std::string, int> m_Characteristics;
  int m_MinUnitCount;
  int m_MaxUnitCount;
  int m_PointsCost;
  std::map<std::string, Ability> m_Abilities;
  std::map<std::string, Weapon> m_Weapons;
  std::set<std::string> m_Keywords;
  GrandAllianceType m_AllianceType;

  std::list<WeaponUpgrade> m_WeaponUpgrades;

public:
  WarScroll();

  WarScroll(const WarScroll &rhs);
  WarScroll &operator=(const WarScroll &rhs);

  std::string getTitle() const {return m_Title;}
  void setTitle(const std::string& title) {m_Title = title;}

  void setCharacteristics(int move, int wounds, int bravery, int save);
  int getCharacteristic(const std::string &characteristic) const;
  void incrementCharacteristic(const std::string &characteristic);
  void decrementCharacteristic(const std::string &characteristic);

  void setMinMaxUnitCount(int minUnitCount, int maxUnitCount);
  int getMinUnitCount() const {return m_MinUnitCount;}
  int getMaxUnitCount() const {return m_MaxUnitCount;}

  int getPointsCost() const {return m_PointsCost;}
  void refreshPointsCost();

  std::map<std::string, Ability> &getAbilities() {return m_Abilities;}
  const Ability &getAbility(const std::string &name) const;
  void addAbility(const Ability &ability);

  std::map<std::string, Weapon> &getWeapons() {return m_Weapons;}
  const Weapon &getWeapon(const std::string &name) const;
  void addWeapon(const Weapon &weapon);

  void addKeyWord(const std::string &keyWord);
  void addKeyWords(const std::list<std::string>& keyWords);
  bool keyWordExists(const std::string &keyWord);

  GrandAllianceType getGrandAllianceType() const {return m_AllianceType;}
  void setGrandAllianceType(GrandAllianceType a) {m_AllianceType = a;}

  void addWeaponUpgrade(const WeaponUpgrade &upgrade);
};

#endif // WARSCROLL_H
