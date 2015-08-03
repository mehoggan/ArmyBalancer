#include "dwarfsfaction.h"

namespace WarScrollGeneration
{
  WarScroll High_King_Thorgrim_Grudgebearer(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(4, 8, 9, 4);

    ws.addWeapon(WarScroll::Weapon("The Axe of Grimmir", 1, 4, 3, 3, 2, 3));
    ws.addWeapon(WarScroll::Weapon("Runic Hammer", 1, 4, 3, 4, 0, 1));

    ws.addAbility(WarScroll::Ability("The Armour of Skaldour", 1));
    ws.addAbility(WarScroll::Ability("Great Book of Grudges", 1));
    ws.addAbility(WarScroll::Ability("The High King", 1, true));

    ws.addKeyWords({"ORDER", "DUARDIN", "DISPOSSESSED", "HERO", "DWARF LORD",
      "HIGH KING THORGRIM GRUDGEBEARER"});

    return ws;
  }

  WarScroll Thorek_Ironbrow(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(1, 8, 8, 4);

    ws.addWeapon(WarScroll::Weapon("Klad Brakak", 2, 2, 3, 3, 1, 2));
    ws.addWeapon(WarScroll::Weapon("Runic Hammers", 1, 4, 3, 4, 1, 1));

    ws.addAbility(WarScroll::Ability("Anvil of Doom", 3));
    ws.addAbility(WarScroll::Ability("Strike the Runes", 3));

    ws.addKeyWords({"ORDER", "DUARDIN", "DISPOSSESSED", "HERO", "PRIEST",
      "RUNELORD", "THOREK IRONBROW"});

    return ws;
  }

  WarScroll Kraggi(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(1, 3, 7, 5);

    ws.addWeapon(WarScroll::Weapon("Forging Tongs", 1, 1, 4, 5, 0, 1));

    ws.addAbility(WarScroll::Ability("Overworked", 1));
    ws.addAbility(WarScroll::Ability("Enthusiastic Young Assistant", 1));

    ws.addKeyWords({"ORDER", "DUARDIN", "DISPOSSESSED", "HERO", "PRIEST",
      "KRAGGI"});

    return ws;
  }

  WarScroll Belgar_Ironhammer(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(4, 5, 8, 3);

    ws.addWeapon(WarScroll::Weapon(1, 4, 3, 3, 1, 3));

    ws.addAbility(WarScroll::Ability("Belgar's Oath Stone", 2));
    ws.addAbility(WarScroll::Ability("Revenge Incarnate", 1));
    ws.addAbility(WarScroll::Ability("Oath of Vengeance", 1, true));

    ws.addKeyWords({"ORDER", "DUARDIN", "DISPOSSESSED", "HERO", "DWARF LORD",
      "BELGAR IRONHAMMER"});

    return ws;
  }

  WarScroll Ungrim_Ironfist_the_Slayer_King(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(4, 6, 10, 4);

    ws.addWeapon(WarScroll::Weapon("Axe of Dargo", 1, 4, 3, 3, 2, 2));

    ws.addAbility(WarScroll::Ability("Slayer Oath", 2));
    ws.addAbility(WarScroll::Ability("A Mighty Death", 2));
    ws.addAbility(WarScroll::Ability("Dragon Cloak of Fyrskar", 2));
    ws.addAbility(WarScroll::Ability("The Slayer King", 2, true));

    ws.addKeyWords({"ORDER", "DUARDIN", "DISPOSSESSED", "HERO", "DWARF LORD",
      "UNGRIM IRONFIST THE SLAYER KING"});

    return ws;
  }

  WarScroll Josef_Bugman(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(4, 5, 7, 4);

    ws.addWeapon(WarScroll::Weapon("Bugman's Crossbow", 20, 1, 3, 4, 0, 1));
    ws.addWeapon(WarScroll::Weapon("Ol' Trustworthy", 1, 4, 3, 3, 1, 1));

    ws.addAbility(WarScroll::Ability("Bugman's Rangers", 1));
    ws.addAbility(WarScroll::Ability("Bugman's Tankard", 3));
    ws.addAbility(WarScroll::Ability("Liquid Fortification",1));

    ws.addKeyWords({"ORDER", "DUARDIN", "DISPOSSESSED", "HERO",
      "JOSEF BUGMAN"});

    return ws;
  }

  WarScroll Grimm_Burloksson(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(4, 5, 7, 4);

    ws.addWeapon(WarScroll::Weapon("Grudge-Raker", 16, 6, 3, 3, 1, 1));
    ws.addWeapon(WarScroll::Weapon("Brace of Dwarf Pistols", 9, 2, 3, 3, 1, 1));
    ws.addWeapon(WarScroll::Weapon("Steam-powered Gauntlet", 1, 1, 4, 3, 1, 3));
    ws.addWeapon(WarScroll::Weapon("Cog Axe", 1, 3, 3, 3, 1, 1));

    ws.addAbility(WarScroll::Ability("Master Engineer", 2));
    ws.addAbility(WarScroll::Ability("Experimental Weaponry", 3));

    ws.addKeyWords({"ORDER", "DUARDIN", "DISPOSSESSED", "HERO", "ENGINEER",
      "GRIMM BURLOKSSON"});

    return ws;
  }

  WarScroll Dwarf_Lord(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(4, 5, 8, 4);

    WarScroll::WeaponUpgrade shieldHammerUpgrade(
      WarScroll::Weapon("Rune Weapon", 1, 4, 3, 3, 1, 3),
      WarScroll::Ability("Ancestor Shield", 2));
    shieldHammerUpgrade.registerCharacteristicToIncrease("Save", -1);
    ws.addWeaponUpgrade(shieldHammerUpgrade);
    WarScroll::WeaponUpgrade greatRuneWeapon(
      WarScroll::Weapon("Great Rune Weapon", 1, 3, 3, 3, 2, 3),
      WarScroll::Ability());
    ws.addWeaponUpgrade(greatRuneWeapon);
    WarScroll::WeaponUpgrade pistolHammerUpgrade(
      WarScroll::Weapon("Rune Weapon", 1, 4, 3, 3, 1, 1),
      WarScroll::Ability());
    pistolHammerUpgrade.setSecondaryWeapon(WarScroll::Weapon("Dwarf Pistol",
      8, 1, 3, 3, 1, 1));

    WarScroll::UnitUpgrade shieldbearersUpgrade("Shieldbearers",
      WarScroll::UnitUpgrade::UnitUpgradeType::eMount, 3);
    shieldbearersUpgrade.registerCharacteristicToIncrease("Wounds", 2);
    shieldbearersUpgrade.addWeapon(WarScroll::Weapon("Shieldbearers' Hammers",
      1, 2, 4, 4, 0, 1));
    ws.registerUnitUpgrade(shieldbearersUpgrade);

    ws.addAbility(WarScroll::Ability("Stubborn Oath Keeper", 2));
    ws.addAbility(WarScroll::Ability("Ancestral Grudge", 1, true));

    ws.addKeyWords({"ORDER", "DUARDIN", "DISPOSSESSED", "HERO", "DWARF LORD"});

    return ws;
  }

  WarScroll Runelord(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(4, 5, 7, 4);

    ws.addWeapon(WarScroll::Weapon("Rune Staff", 1, 1, 4, 3, 0, 3));
    ws.addWeapon(WarScroll::Weapon("Forgehammer", 1, 2, 4, 4, 0, 1));

    ws.addAbility(WarScroll::Ability("Runes of Spellbreaking", 1));
    ws.addAbility(WarScroll::Ability("Rune Lore", 2));

    ws.addKeyWords({"ORDER", "DUARDIN", "DISPOSSESSED", "HERO", "PRIEST",
      "RUNELORD"});

    return ws;
  }

  WarScroll Dragon_Slayer(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(4, 5, 10, 6);

    WarScroll::WeaponUpgrade dualRunicAxes(
      WarScroll::Weapon("Runic Axes", 1, 6, 3, 3, 1, 1),
      WarScroll::Ability("Runic Axes", 1));
    ws.addWeaponUpgrade(dualRunicAxes);
    WarScroll::WeaponUpgrade runicGreatAxe(
      WarScroll::Weapon("Runic Great Axe", 1, 3, 3, 3, 2, 3),
      WarScroll::Ability());
    ws.addWeaponUpgrade(runicGreatAxe);

    ws.addAbility(WarScroll::Ability("Epic Deathblow", 2));
    ws.addAbility(WarScroll::Ability("Master Slayer", 2));
    ws.addAbility(WarScroll::Ability("Slayer Oath", 1));
    ws.addAbility(WarScroll::Ability("The Slayer King", 1));

    ws.addKeyWords({"ORDER", "DUARDIN", "DISPOSSESSED", "HERO",
      "DRAGON SLAYER"});

    return ws;
  }

  WarScroll Dwarf_Engineer(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(4, 5, 7, 5);

    ws.addWeapon(WarScroll::Weapon("Guild Hammer and Tools", 1, 4, 4, 4, 0, 1));

    WarScroll::WeaponUpgrade steamHammerUpgrade(
      WarScroll::Weapon("Steam Hammer", 1, 2, 3, 3, 1, 2),
      WarScroll::Ability());
    steamHammerUpgrade.setSecondaryWeapon(WarScroll::Weapon("Dwarf Pistol",
        8, 1, 3, 3, 1, 1));
    ws.addWeaponUpgrade(steamHammerUpgrade);
    WarScroll::WeaponUpgrade dualDwarfPistols(
      WarScroll::Weapon("Dwarf Pistol", 8, 1, 3, 3, 1, 1),
      WarScroll::Ability("Brace of Dwarf Pistols", 1));
    ws.addWeaponUpgrade(dualDwarfPistols);
    WarScroll::WeaponUpgrade dwarfHandgunUpgrade(
      WarScroll::Weapon("Dwarf Handgun", 16, 1, 3, 3, 1, 1),
      WarScroll::Ability());
    ws.addWeaponUpgrade(dualDwarfPistols);

    ws.addAbility(WarScroll::Ability("Engineer", 1));

    ws.addKeyWords({"ORDER", "DUARDIN", "DISPOSSESSED", "HERO", "ENGINEER"});

    return ws;
  }

  WarScroll Thane_with_Battle_Standard(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(4, 5, 7, 4);

    ws.addWeapon(WarScroll::Weapon("Ancestral Hammer", 1, 4, 3, 3, 0, 1));

    ws.addAbility(WarScroll::Ability("Honour of the Clan", 1));
    ws.addAbility(WarScroll::Ability("Ancestral Rune Standard", 2));

    ws.addKeyWords({"ORDER", "DUARDIN", "DISPOSSESSED", "HERO", "TOTEM",
      "THANE WITH BATTLE STANDARD"});

    return ws;
  }

  WarScroll Hammerers(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(4, 1, 7, 4);

    ws.addWeapon(WarScroll::Weapon("Gromril Great Hammer", 1, 2, 3, 3, 1, 1));

    ws.setMinMaxUnitCount(5, IFaction::s_MaxUnitSize);

    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Throng Musician",
      WarScroll::UnitUpgrade::UnitUpgradeType::eMusician, 2));
    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Standard Bearer",
      WarScroll::UnitUpgrade::UnitUpgradeType::eBannerBearer, 2));
    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Keeper of the Gate",
      WarScroll::UnitUpgrade::UnitUpgradeType::eChampion, 1));

    ws.addAbility(WarScroll::Ability("Kingsguard", 3));

    ws.addKeyWords({"ORDER", "DUARDIN", "DISPOSSESSED", "HAMMERERS"});

    return ws;
  }

  WarScroll Ironbreakers(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(4, 1, 7, 4);

    ws.addWeapon(WarScroll::Weapon("Ironbreaker Axe or Hammer",
      1, 2, 3, 4, 0, 1));

    ws.setMinMaxUnitCount(5, IFaction::s_MaxUnitSize);

    // TODO Unit Upgrades with upgrades.
    WarScroll::UnitUpgrade ironbeardUpgrade("Ironbeard",
      WarScroll::UnitUpgrade::UnitUpgradeType::eChampion, 2);
    ironbeardUpgrade.addWeapon(WarScroll::Weapon("Drakefire Pistol",
      1, 1, 4, 4, 0, 1)); // <-- Missed ability if two pistols given
    ironbeardUpgrade.addAbility(WarScroll::Ability("Cinderblast Bomb", 1));
    ws.registerUnitUpgrade(ironbeardUpgrade);
    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Icon Bearer",
      WarScroll::UnitUpgrade::UnitUpgradeType::eBannerBearer, 2));
    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Drummer",
      WarScroll::UnitUpgrade::UnitUpgradeType::eMusician, 2));

    ws.addAbility(WarScroll::Ability("Gromril Shields", 1));
    ws.addAbility(WarScroll::Ability("Forge-proven Gromril Armor", 2));

    ws.addKeyWords({"ORDER", "DUARDIN", "DISPOSSESSED", "IRONBREAKERS"});

    return ws;
  }

  WarScroll Irondrakes(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Longbeards(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Dwarf_Warriors(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Miners(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Quarrellers(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Slayers(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Thunderers(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Gyrocopters(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Gyrobombers(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Dwarf_Bolt_Thrower(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Dwarf_Cannon(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Flame_Cannon(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Organ_Gun(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Grudge_Thrower(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }
}

DwarfsFaction::DwarfsFaction() :
  IFaction(nullptr)
{
  m_Units.push_back("");
  m_Units.push_back("High King Thorgrim Grudgebearer");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::High_King_Thorgrim_Grudgebearer,
    m_Units.back())));
  m_Units.push_back("Thorek Ironbrow");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Thorek_Ironbrow, m_Units.back())));
  m_Units.push_back("Kraggi");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Kraggi, m_Units.back())));
  m_Units.push_back("Belgar Ironhammer");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Belgar_Ironhammer, m_Units.back())));
  m_Units.push_back("Ungrim Ironfist the Slayer King");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Ungrim_Ironfist_the_Slayer_King,
    m_Units.back())));
  m_Units.push_back("Josef Bugman");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Josef_Bugman, m_Units.back())));
  m_Units.push_back("Grimm Burloksson");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Grimm_Burloksson, m_Units.back())));
  m_Units.push_back("Dwarf Lord");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Dwarf_Lord, m_Units.back())));
  m_Units.push_back("Runelord");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Runelord, m_Units.back())));
  m_Units.push_back("Dragon Slayer");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Dragon_Slayer, m_Units.back())));
  m_Units.push_back("Dwarf Engineer");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Dwarf_Engineer, m_Units.back())));
  m_Units.push_back("Thane with Battle Standard");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Thane_with_Battle_Standard,
    m_Units.back())));
  m_Units.push_back("Hammerers");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Hammerers, m_Units.back())));
  m_Units.push_back("Ironbreakers");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Ironbreakers, m_Units.back())));
  m_Units.push_back("Irondrakes");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Irondrakes, m_Units.back())));
  m_Units.push_back("Longbeards");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Longbeards, m_Units.back())));
  m_Units.push_back("Dwarf Warriors");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Dwarf_Warriors, m_Units.back())));
  m_Units.push_back("Miners");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Miners, m_Units.back())));
  m_Units.push_back("Quarrellers");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Quarrellers, m_Units.back())));
  m_Units.push_back("Slayers");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Slayers, m_Units.back())));
  m_Units.push_back("Thunderers");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Thunderers, m_Units.back())));
  m_Units.push_back("Gyrocopters");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Gyrocopters, m_Units.back())));
  m_Units.push_back("Gyrobombers");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Gyrobombers, m_Units.back())));
  m_Units.push_back("Dwarf Bolt Thrower");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Dwarf_Bolt_Thrower, m_Units.back())));
  m_Units.push_back("Dwarf Cannon");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Dwarf_Cannon, m_Units.back())));
  m_Units.push_back("Flame Cannon");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Flame_Cannon, m_Units.back())));
  m_Units.push_back("Organ Gun");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Organ_Gun, m_Units.back())));
  m_Units.push_back("Grudge Thrower");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Grudge_Thrower, m_Units.back())));
}

const std::vector<std::string> &DwarfsFaction::getUnits() const
{
  return m_Units;
}

void DwarfsFaction::getWarScrolls(std::list<WarScroll>& warScrolls)
{
  for (const std::string &unit : m_Units) {
    if (unit.empty()) {
      continue;
    }
    WarScroll ws = m_NameToWarScroll[unit](unit);
    warScrolls.push_back(ws);
  }
}
