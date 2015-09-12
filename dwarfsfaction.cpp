#include "dwarfsfaction.h"

namespace WarScrollGeneration
{
  WarScroll High_King_Thorgrim_Grudgebearer(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(4, 8, 9, 4);

    ws.addWeapon(WarScroll::Weapon("The Axe of Grimnir", 1, 4, 3, 3, 2, 3));
    ws.addWeapon(WarScroll::Weapon("Runic Hammers", 1, 4, 3, 4, 0, 1));

    ws.addAbility(WarScroll::Ability("The Armour of Skaldour", 1));
    ws.addAbility(WarScroll::Ability("Great Book of Grudges", 1));
    ws.addAbility(WarScroll::Ability("The High King", 1, true));

    ws.addKeyWords({"ORDER", "DUARDIN", "DISPOSSESSED", "HERO", "DWARF LORD",
      "HIGH KING THORGRIM GRUDGEBEARER"});

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eOrder);

    {
      WarScroll::KeyWordConnection connection("DISPOSSESSED",
        WarScroll::s_MaxDistance,
        WarScroll::Ability("Great Book of Grudges", 1), 1,
        WarScroll::KeyWordConnection::ConnectionAffectType::eFriendly,
        WarScroll::Spell());
      connection.setMaxConnections(1);
      ws.addKeyWordConnection(connection);
    }

    ws.addKeyWordConnection(WarScroll::KeyWordConnection("DISPOSSESSED",
      8, WarScroll::Ability("The High King", 1, true), 1,
      WarScroll::KeyWordConnection::ConnectionAffectType::eFriendly,
      WarScroll::Spell()));

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
    ws.addAbility(WarScroll::Ability("Master Runes of Spellbreaking", 2));
    ws.addAbility(WarScroll::Ability("Strike the Runes", 3));

    ws.addKeyWords({"ORDER", "DUARDIN", "DISPOSSESSED", "HERO", "PRIEST",
      "RUNELORD", "THOREK IRONBROW"});

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eOrder);

    ws.addKeyWordConnection(WarScroll::KeyWordConnection("DISPOSSESSED",
      24, WarScroll::Ability("Strike the Runes", 3), 1,
      WarScroll::KeyWordConnection::ConnectionAffectType::eFriendly,
      WarScroll::Spell()));
    ws.addKeyWordConnection(WarScroll::KeyWordConnection("KRAGGI",
      4, WarScroll::Ability("Strike the Runes", 3), 1,
      WarScroll::KeyWordConnection::ConnectionAffectType::eFriendly,
      WarScroll::Spell()));

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

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eOrder);

    ws.addKeyWordConnection(WarScroll::KeyWordConnection("THOREK IRONBROW",
      5, WarScroll::Ability("Overworked", 1), 1,
      WarScroll::KeyWordConnection::ConnectionAffectType::eFriendly,
      WarScroll::Spell()));

    return ws;
  }

  WarScroll Belgar_Ironhammer(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(4, 5, 8, 3);

    ws.addWeapon(WarScroll::Weapon("Hammer of Angrund", 1, 4, 3, 3, 1, 3));

    ws.addAbility(WarScroll::Ability("Shield of Defiance", 2));
    ws.addAbility(WarScroll::Ability("Belgar's Oath Stone", 2));
    ws.addAbility(WarScroll::Ability("Revenge Incarnate", 1));
    ws.addAbility(WarScroll::Ability("Oath of Vengeance", 1, true));

    ws.addKeyWords({"ORDER", "DUARDIN", "DISPOSSESSED", "HERO", "DWARF LORD",
      "BELGAR IRONHAMMER"});

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eOrder);

    ws.addKeyWordConnection(WarScroll::KeyWordConnection("DISPOSSESSED",
      18, WarScroll::Ability("Belgar's Oath Stone", 2), 1,
      WarScroll::KeyWordConnection::ConnectionAffectType::eFriendly,
      WarScroll::Spell()));
    ws.addKeyWordConnection(WarScroll::KeyWordConnection("DISPOSSESSED",
      16, WarScroll::Ability("Oath of Vengeance", 1, true), 1,
      WarScroll::KeyWordConnection::ConnectionAffectType::eFriendly,
      WarScroll::Spell()));

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

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eOrder);

    ws.addKeyWordConnection(WarScroll::KeyWordConnection("DISPOSSESSED",
      16, WarScroll::Ability("The Slayer King", 2, true), 1,
      WarScroll::KeyWordConnection::ConnectionAffectType::eFriendly,
      WarScroll::Spell()));

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
    ws.addAbility(WarScroll::Ability("Liquid Fortification", 1));

    ws.addKeyWords({"ORDER", "DUARDIN", "DISPOSSESSED", "HERO",
      "JOSEF BUGMAN"});

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eOrder);

    {
      WarScroll::KeyWordConnection connection("QUARRELLERS",
        WarScroll::s_MaxDistance, WarScroll::Ability("Bugman's Rangers", 1), 1,
        WarScroll::KeyWordConnection::ConnectionAffectType::eFriendly,
        WarScroll::Spell());
      connection.setMaxConnections(1);
      ws.addKeyWordConnection(connection);
    }
    ws.addKeyWordConnection(WarScroll::KeyWordConnection(
      "DISPOSSESSED and HERO", 4, WarScroll::Ability("Bugman's Tankard", 3), 1,
      WarScroll::KeyWordConnection::ConnectionAffectType::eFriendly,
      WarScroll::Spell()));
    ws.addKeyWordConnection(WarScroll::KeyWordConnection(
      "DISPOSSESSED", 4, WarScroll::Ability("Liquid Fortification", 1),
      1, WarScroll::KeyWordConnection::ConnectionAffectType::eFriendly,
      WarScroll::Spell()));

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

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eOrder);

    ws.addKeyWordConnection(WarScroll::KeyWordConnection("WAR MACHINE",
      4, WarScroll::Ability("Master Engineer", 2), 1,
      WarScroll::KeyWordConnection::ConnectionAffectType::eFriendly,
      WarScroll::Spell()));
    ws.addKeyWordConnection(WarScroll::KeyWordConnection(
      "QUARRELLERS or THUNDERERS", 6,
      WarScroll::Ability("Experimental Weaponry", 3), 1,
      WarScroll::KeyWordConnection::ConnectionAffectType::eFriendly,
      WarScroll::Spell()));

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
      WarScroll::Weapon("Rune Weapon", 1, 4, 3, 3, 1, 3),
      WarScroll::Ability());
    pistolHammerUpgrade.setSecondaryWeapon(WarScroll::Weapon("Dwarf Pistol",
      8, 1, 3, 3, 1, 1));
    ws.addWeaponUpgrade(pistolHammerUpgrade);

    WarScroll::UnitUpgrade shieldbearersUpgrade("Shieldbearers",
      WarScroll::UnitUpgrade::UnitUpgradeType::eMount, 3);
    shieldbearersUpgrade.registerCharacteristicToIncrease("Wounds", 2);
    shieldbearersUpgrade.addWeapon(WarScroll::Weapon("Shieldbearers' Hammers",
      1, 2, 4, 4, 0, 1));
    ws.registerUnitUpgrade(shieldbearersUpgrade);

    ws.addAbility(WarScroll::Ability("Stubborn Oath Keeper", 2));
    ws.addAbility(WarScroll::Ability("Ancestral Grudge", 1, true));

    ws.addKeyWords({"ORDER", "DUARDIN", "DISPOSSESSED", "HERO", "DWARF LORD"});

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eOrder);

    ws.addKeyWordConnection(WarScroll::KeyWordConnection("DISPOSSESSED",
      18, WarScroll::Ability("Stubborn Oath Keeper", 2), 1,
      WarScroll::KeyWordConnection::ConnectionAffectType::eFriendly,
      WarScroll::Spell()));
    ws.addKeyWordConnection(WarScroll::KeyWordConnection("DISPOSSESSED",
      16, WarScroll::Ability("Ancestral Grudge", 1, true), 1,
      WarScroll::KeyWordConnection::ConnectionAffectType::eFriendly,
      WarScroll::Spell()));

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

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eOrder);

    ws.addKeyWordConnection(WarScroll::KeyWordConnection("DISPOSSESSED",
      16, WarScroll::Ability("Rune Lore", 2), 1,
      WarScroll::KeyWordConnection::ConnectionAffectType::eFriendly,
      WarScroll::Spell()));
    ws.addKeyWordConnection(WarScroll::KeyWordConnection("THOREK IRONBROW",
      8, WarScroll::Ability("Rune Lore", 2), 1,
      WarScroll::KeyWordConnection::ConnectionAffectType::eFriendly,
      WarScroll::Spell()));

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

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eOrder);

    ws.addKeyWordConnection(WarScroll::KeyWordConnection("MONSTER",
      1, WarScroll::Ability("Epic Deathblow", 2), 1,
      WarScroll::KeyWordConnection::ConnectionAffectType::eEnemy,
      WarScroll::Spell()));
    ws.addKeyWordConnection(WarScroll::KeyWordConnection("MONSTER",
      1, WarScroll::Ability("Master Slayer", 2), 1,
      WarScroll::KeyWordConnection::ConnectionAffectType::eEnemy,
      WarScroll::Spell()));
    ws.addKeyWordConnection(WarScroll::KeyWordConnection(
      "UNGRIM IRONFIST THE SLAYER KING", 8,
      WarScroll::Ability("The Slayer King", 1), 1,
      WarScroll::KeyWordConnection::ConnectionAffectType::eFriendly,
      WarScroll::Spell()));

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
    ws.addWeaponUpgrade(dwarfHandgunUpgrade);

    ws.addAbility(WarScroll::Ability("Engineer", 1));

    ws.addKeyWords({"ORDER", "DUARDIN", "DISPOSSESSED", "HERO", "ENGINEER"});

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eOrder);

    ws.addKeyWordConnection(WarScroll::KeyWordConnection("WAR MACHINE",
      4, WarScroll::Ability("Engineer", 1), 1,
      WarScroll::KeyWordConnection::ConnectionAffectType::eFriendly,
      WarScroll::Spell()));

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

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eOrder);

    ws.addKeyWordConnection(WarScroll::KeyWordConnection("DISPOSSESSED",
      16, WarScroll::Ability("Ancestral Rune Standard", 2), 1,
      WarScroll::KeyWordConnection::ConnectionAffectType::eFriendly,
      WarScroll::Spell()));
    ws.addKeyWordConnection(WarScroll::KeyWordConnection("WIZARD",
      16, WarScroll::Ability("Ancestral Rune Standard", 2), 1,
      WarScroll::KeyWordConnection::ConnectionAffectType::eEnemy,
      WarScroll::Spell()));

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

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eOrder);

    ws.addKeyWordConnection(WarScroll::KeyWordConnection(
      "DISPOSSESSED and HERO", 16, WarScroll::Ability("Kingsguard", 3), 1,
      WarScroll::KeyWordConnection::ConnectionAffectType::eFriendly,
      WarScroll::Spell()));

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

    WarScroll::ChampionWithOptions option1("Ironbeard", 2);
    option1.addWeapon(WarScroll::Weapon("Ironbreaker Axe or Hammer",
      1, 2, 3, 4, 0, 1));
    option1.addAbility(WarScroll::Ability("Gromril Shields", 1));
    ws.registerChampionWithOptions(option1);

    WarScroll::ChampionWithOptions option2("Ironbeard with Drakefire Pistol"
      " and Cinderblast", 2);
    option2.addWeapon(WarScroll::Weapon("Drakefire Pistol", 8, 1, 4, 3, 1, 1));
    option2.addWeapon(WarScroll::Weapon("Drakefire Pistol", 1, 1, 4, 4, 0, 1));
    option2.addAbility(WarScroll::Ability("Cinderblast Bomb", 2));
    ws.registerChampionWithOptions(option2);

    WarScroll::ChampionWithOptions option3(
      "Ironbeard with Dual Drakefire Pistols", 2);
    option3.addWeapon(WarScroll::Weapon("Drakefire Pistol", 8, 2, 4, 3, 1, 1));
    option3.addWeapon(WarScroll::Weapon("Drakefire Pistol", 1, 2, 4, 4, 0, 1));
    option3.addAbility(WarScroll::Ability("Brace of Drakefire Pistols", 1));
    ws.registerChampionWithOptions(option3);

    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Ironbeard",
      WarScroll::UnitUpgrade::UnitUpgradeType::eChampion, 2));
    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Icon Bearer",
      WarScroll::UnitUpgrade::UnitUpgradeType::eBannerBearer, 2));
    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Drummer",
      WarScroll::UnitUpgrade::UnitUpgradeType::eMusician, 2));

    ws.addAbility(WarScroll::Ability("Gromril Shields", 1));
    ws.addAbility(WarScroll::Ability("Forge-proven Gromril Armor", 2));

    ws.addKeyWords({"ORDER", "DUARDIN", "DISPOSSESSED", "IRONBREAKERS"});

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eOrder);

    return ws;
  }

  WarScroll Irondrakes(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(4, 1, 7, 4);

    ws.addWeapon(WarScroll::Weapon("Drakegun", 16, 1, 3, 3, 1, 1));
    ws.addWeapon(WarScroll::Weapon("Mailed Fist", 1, 1, 4, 5, 0, 1));

    ws.setMinMaxUnitCount(5, IFaction::s_MaxUnitSize);

    WarScroll::ChampionWithOptions option1("Ironwarden", 2);
    option1.addWeapon(WarScroll::Weapon("Drakegun", 16, 1, 2, 3, 1, 1));
    option1.addWeapon(WarScroll::Weapon("Mailed Fist", 1, 1, 4, 5, 0, 1));
    option1.addAbility(WarScroll::Ability("Blaze Away", 1));
    ws.registerChampionWithOptions(option1);

    WarScroll::ChampionWithOptions option2(
      "Ironwarden with Trollhammer Torpedo", 2);
    option2.addWeapon(WarScroll::Weapon("Trollhammer Torpedo",
      20, 1, 3, 3, 2, 3));
    option2.addWeapon(WarScroll::Weapon("Mailed Fist", 1, 1, 4, 5, 0, 1));
    WarScroll::KeyWordConnection connection("MONSTER",
      20, WarScroll::Ability(), 1,
      WarScroll::KeyWordConnection::ConnectionAffectType::eEnemy,
      WarScroll::Spell());
    connection.setName("Trollhammer Torpedo");
    option2.addKeyWordConnection(connection);
    ws.registerChampionWithOptions(option2);

    WarScroll::ChampionWithOptions option3(
      "Ironwarden with Drakefire Pistol and Cinderblast bomb", 2);
    option3.addWeapon(WarScroll::Weapon("Drakefire Pistol", 8, 1, 4, 3, 1, 1));
    option3.addWeapon(WarScroll::Weapon("Drakefire Pistol", 1, 1, 4, 4, 0, 1));
    option3.addAbility(WarScroll::Ability("Cinderblast Bomb", 2));
    ws.registerChampionWithOptions(option3);

    WarScroll::ChampionWithOptions option4(
      "Ironwarden with Dual Drakefire Pistols", 2);
    option4.addWeapon(WarScroll::Weapon("Drakefire Pistol", 8, 2, 4, 3, 1, 1));
    option4.addWeapon(WarScroll::Weapon("Drakefire Pistol", 1, 2, 4, 4, 0, 1));
    option4.addAbility(WarScroll::Ability("Brace of Drakefire Pistols", 1));
    ws.registerChampionWithOptions(option4);

    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Iron Warden",
      WarScroll::UnitUpgrade::UnitUpgradeType::eChampion, 2));
    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Icon Bearer",
      WarScroll::UnitUpgrade::UnitUpgradeType::eBannerBearer, 2));
    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Hornblowers",
      WarScroll::UnitUpgrade::UnitUpgradeType::eMusician, 1));

    ws.addAbility(WarScroll::Ability("Forge-proven Gromril Armor", 2));

    ws.addKeyWords({"ORDER", "DUARDIN", "DISPOSSESSED", "IRONDRAKES"});

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eOrder);

    return ws;
  }

  WarScroll Longbeards(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(4, 1, 7, 4);

    ws.setMinMaxUnitCount(10,  IFaction::s_MaxUnitSize);

    ws.addWeaponUpgrade(WarScroll::WeaponUpgrade(
      WarScroll::Weapon("Ancestral Axe or Ancestral Hammer", 1, 1, 3, 4, 0, 1),
      WarScroll::Ability()));
    ws.addWeaponUpgrade(WarScroll::WeaponUpgrade(
      WarScroll::Weapon("Ancestral Great Axe", 1, 1, 4, 3, 1, 1),
      WarScroll::Ability()));
    ws.addWeaponUpgrade(WarScroll::WeaponUpgrade(
      WarScroll::Weapon("Ancestral Axe or Ancestral Hammer with Shield",
        1, 1, 3, 4, 0, 1), WarScroll::Ability("Gromril Shields", 2)));
    ws.addWeaponUpgrade(WarScroll::WeaponUpgrade(
      WarScroll::Weapon("Ancestral Great Axe with Shield",
        1, 1, 4, 3, 1, 1), WarScroll::Ability("Gromril Shields", 2)));

    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Old Guard",
      WarScroll::UnitUpgrade::UnitUpgradeType::eChampion, 1));
    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Standard Bearer",
      WarScroll::UnitUpgrade::UnitUpgradeType::eBannerBearer, 2));
    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Throng Musician",
      WarScroll::UnitUpgrade::UnitUpgradeType::eMusician, 2));

    ws.addAbility(WarScroll::Ability("Old Grumblers", 3));

    ws.addKeyWords({"ORDER", "DUARDIN", "DISPOSSESSED", "LONGBEARDS"});

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eOrder);

    ws.addKeyWordConnection(WarScroll::KeyWordConnection("DISPOSSESSED",
      8, WarScroll::Ability("Old Grumblers", 3), 1,
      WarScroll::KeyWordConnection::ConnectionAffectType::eFriendly,
      WarScroll::Spell()));
    ws.addKeyWordConnection(WarScroll::KeyWordConnection(
      "DISPOSSESSED and HERO", 8, WarScroll::Ability("Old Grumblers", 3), 1,
      WarScroll::KeyWordConnection::ConnectionAffectType::eFriendly,
      WarScroll::Spell()));

    return ws;
  }

  WarScroll Dwarf_Warriors(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(4, 1, 6, 5);

    ws.setMinMaxUnitCount(10, IFaction::s_MaxUnitSize);

    ws.addWeaponUpgrade(WarScroll::WeaponUpgrade(
      WarScroll::Weapon("Dwarf Axe or Dwarf Hammer", 1, 1, 3, 4, 0, 1),
      WarScroll::Ability()));
    ws.addWeaponUpgrade(WarScroll::WeaponUpgrade(
      WarScroll::Weapon("Double-handed Dwarf Axe", 1, 1, 4, 3, 1, 1),
      WarScroll::Ability()));
    ws.addWeaponUpgrade(WarScroll::WeaponUpgrade(
      WarScroll::Weapon("Dwarf Axe or Dwarf Hammer with Shield",
        1, 1, 3, 4, 0, 1), WarScroll::Ability("Dwarf Shields", 2)));
    ws.addWeaponUpgrade(WarScroll::WeaponUpgrade(
      WarScroll::Weapon("Double-handed Dwarf Axe with Shield",
        1, 1, 4, 3, 1, 1), WarScroll::Ability("Dwarf Shields", 2)));

    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Vetran",
      WarScroll::UnitUpgrade::UnitUpgradeType::eChampion, 1));
    WarScroll::UnitUpgrade runicIcon("Standard Bearer/Runic Icon",
      WarScroll::UnitUpgrade::UnitUpgradeType::eBannerBearer, 1);
    runicIcon.addAbility(WarScroll::Ability("Runic Icon", 2));
    ws.registerUnitUpgrade(runicIcon);
    WarScroll::UnitUpgrade clanBanner("Standard Bearer/Clan Banner",
      WarScroll::UnitUpgrade::UnitUpgradeType::eBannerBearer, 1);
    clanBanner.addAbility(WarScroll::Ability("Clan Banner", 2));
    ws.registerUnitUpgrade(clanBanner);
    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Hornblowers",
      WarScroll::UnitUpgrade::UnitUpgradeType::eMusician, 2));

    ws.addAbility(WarScroll::Ability("Dwarf Shields", 2));

    ws.addKeyWords({"ORDER", "DUARDIN", "DISPOSSESSED", "DWARF WARRIORS"});

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eOrder);

    return ws;
  }

  WarScroll Miners(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(4, 1, 6, 5);

    ws.addWeapon(WarScroll::Weapon("Miner's Pickaxe", 1, 1, 4, 3, 1, 1));

    ws.setMinMaxUnitCount(10, IFaction::s_MaxUnitSize);

    WarScroll::WeaponUpgrade noMinningCart(
      WarScroll::Weapon("No Minning Cart", 0, 0, 7, 7, 0, 0),
      WarScroll::Ability());
    WarScroll::WeaponUpgrade minningCart(
      WarScroll::Weapon("Mule's Bite", 1, 1, 5, 6, 1, 1),
      WarScroll::Ability());
    minningCart.setSecondaryWeapon(WarScroll::Weapon("Blasting Charges",
      6, 1, 4, 3, 2, 1));
    ws.addWeaponUpgrade(minningCart);
    WarScroll::WeaponUpgrade minningCartWithSteamHarpoon(
      WarScroll::Weapon("Mule's Bite", 1, 1, 5, 6, 1, 1),
      WarScroll::Ability(WarScroll::Ability("Steam Harpoon", 2)));
    minningCartWithSteamHarpoon.setSecondaryWeapon(
      WarScroll::Weapon("Blasting Charges", 6, 1, 4, 3, 2, 1));
    minningCartWithSteamHarpoon.setTertiaryWeapon(
      WarScroll::Weapon("Steam Harpoon", 16, 1, 4, 3, 1, 3));
    ws.addWeaponUpgrade(minningCartWithSteamHarpoon);

    WarScroll::ChampionWithOptions prospectorWithPickAxe("Prospector", 1);
    prospectorWithPickAxe.addWeapon(WarScroll::Weapon("Miner's Pickaxe",
      1, 2, 4, 3, 1, 1));
    ws.registerChampionWithOptions(prospectorWithPickAxe);
    WarScroll::ChampionWithOptions prospectorWithSteamDrill("Prospector "
      "with Steam Drill", 2);
    prospectorWithSteamDrill.addWeapon(WarScroll::Weapon("Steam Drill",
      1, 1, 4, 3, 3, 3));
    ws.registerChampionWithOptions(prospectorWithSteamDrill);

    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Prospector",
      WarScroll::UnitUpgrade::UnitUpgradeType::eChampion, 1));

    WarScroll::UnitUpgrade runicIconBearer("Standard Bearer/Runic Icon",
      WarScroll::UnitUpgrade::UnitUpgradeType::eBannerBearer, 2);
    runicIconBearer.addAbility(WarScroll::Ability("Runic Icon", 2));
    ws.registerUnitUpgrade(runicIconBearer);
    WarScroll::UnitUpgrade clanBanner("Standard Bearer/Clan Banner",
      WarScroll::UnitUpgrade::UnitUpgradeType::eBannerBearer, 2);
    clanBanner.addAbility(WarScroll::Ability("Clan Banner", 2));
    ws.registerUnitUpgrade(clanBanner);
    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Hornblowers",
      WarScroll::UnitUpgrade::UnitUpgradeType::eMusician, 2));

    ws.addAbility(WarScroll::Ability("Underground Advance", 2));

    ws.addKeyWords({ "ORDER", "DUARDIN", "DISPOSSESSED", "MINERS"});

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eOrder);

    return ws;
  }

  WarScroll Quarrellers(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(4, 1, 6, 5);

    ws.addWeapon(WarScroll::Weapon("Dwarf Crossbow", 20, 1, 4, 4, 0, 1));
    ws.addWeapon(WarScroll::Weapon("Ranger's Axe", 1, 1, 4, 4, 0, 1));

    ws.setMinMaxUnitCount(10, IFaction::s_MaxUnitSize);

    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Vetran",
      WarScroll::UnitUpgrade::UnitUpgradeType::eChampion, 1));
    WarScroll::UnitUpgrade runicIcon("Standard Bearer/Runic Icon",
      WarScroll::UnitUpgrade::UnitUpgradeType::eBannerBearer, 1);
    runicIcon.addAbility(WarScroll::Ability("Runic Icon", 2));
    ws.registerUnitUpgrade(runicIcon);
    WarScroll::UnitUpgrade clanBanner("Standard Bearer/Clan Banner",
      WarScroll::UnitUpgrade::UnitUpgradeType::eBannerBearer, 1);
    clanBanner.addAbility(WarScroll::Ability("Clan Banner", 2));
    ws.registerUnitUpgrade(clanBanner);
    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Drummers",
      WarScroll::UnitUpgrade::UnitUpgradeType::eMusician, 2));
    WarScroll::UnitUpgrade dwarfBucklers("Dwarf Bucklers",
      WarScroll::UnitUpgrade::UnitUpgradeType::eShield, 1);
    dwarfBucklers.addAbility(WarScroll::Ability("Dwarf Bucklers", 1));
    ws.registerUnitUpgrade(dwarfBucklers);

    ws.addAbility(WarScroll::Ability("Volley Fire", 2));

    ws.addKeyWords({"ORDER", "DUARDIN", "DISPOSSESSED", "QUARRELLERS"});

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eOrder);

    return ws;
  }

  WarScroll Slayers(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(4, 1, 10, 6);

    ws.setMinMaxUnitCount(5, IFaction::s_MaxUnitSize);

    ws.addWeapon(WarScroll::Weapon("Slayer Axes", 1, 2, 3, 4, 0, 1));

    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Giant Slayer",
      WarScroll::UnitUpgrade::UnitUpgradeType::eChampion, 1));
    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Icon Bearer",
      WarScroll::UnitUpgrade::UnitUpgradeType::eBannerBearer, 2));
    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Hornblower",
      WarScroll::UnitUpgrade::UnitUpgradeType::eMusician, 2));

    ws.addAbility(WarScroll::Ability("Seeking a Glorious Death", 2));
    ws.addAbility(WarScroll::Ability("Deathblow", 1));
    ws.addAbility(WarScroll::Ability("Slayer Oath", 2));
    ws.addAbility(WarScroll::Ability("The Slayer King", 1));

    ws.addKeyWords({"ORDER", "DUARDIN", "DISPOSSESSED", "SLAYERS"});

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eOrder);

    ws.addKeyWordConnection(WarScroll::KeyWordConnection("MONSTER",
      1, WarScroll::Ability("Seeking a Glorious Death", 2), 1,
      WarScroll::KeyWordConnection::ConnectionAffectType::eEnemy,
      WarScroll::Spell()));
    ws.addKeyWordConnection(WarScroll::KeyWordConnection(
      "UNGRIM IRONFIST THE SLAYER KING", 8,
      WarScroll::Ability("The Slayer King", 1), 1,
      WarScroll::KeyWordConnection::ConnectionAffectType::eFriendly,
      WarScroll::Spell()));

    return ws;
  }

  WarScroll Thunderers(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(4, 1, 6, 5);

    ws.addWeapon(WarScroll::Weapon("Dwarf Handgun", 16, 1, 4, 3, 1, 1));
    ws.addWeapon(WarScroll::Weapon("Gun-butts", 1, 1, 4, 5, 0, 1));

    ws.setMinMaxUnitCount(10, IFaction::s_MaxUnitSize);

    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Vetran",
      WarScroll::UnitUpgrade::UnitUpgradeType::eChampion, 1));
    WarScroll::UnitUpgrade runicIcon("Standard Bearer/Runic Icon",
      WarScroll::UnitUpgrade::UnitUpgradeType::eBannerBearer, 1);
    runicIcon.addAbility(WarScroll::Ability("Runic Icon", 2));
    ws.registerUnitUpgrade(runicIcon);
    WarScroll::UnitUpgrade clanBanner("Standard Bearer/Clan Banner",
      WarScroll::UnitUpgrade::UnitUpgradeType::eBannerBearer, 2);
    clanBanner.addAbility(WarScroll::Ability("Clan Banner", 2));
    ws.registerUnitUpgrade(clanBanner);
    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Drummers",
      WarScroll::UnitUpgrade::UnitUpgradeType::eMusician, 2));
    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Dwarf Bucklers",
      WarScroll::UnitUpgrade::UnitUpgradeType::eShield, 1));

    WarScroll::ChampionWithOptions veteran("Veteran", 1);
    veteran.addWeapon(WarScroll::Weapon("Dwarf Handgun", 16, 1, 3, 3, 1, 1));
    veteran.addWeapon(WarScroll::Weapon("Gun-butts", 1, 1, 4, 5, 0, 1));
    ws.registerChampionWithOptions(veteran);
    WarScroll::ChampionWithOptions veteranBraceofDwarfPistols(
      "Veteran with Brace of Dwarf Pistols", 1);
    veteranBraceofDwarfPistols.addWeapon(WarScroll::Weapon(
      "Brace of Dwarf Pistols", 8, 2, 4, 3, 1, 1));
    veteranBraceofDwarfPistols.addWeapon(WarScroll::Weapon(
      "Brace of Dwarf Pistols", 1, 2, 4, 4, 0, 1));
    ws.registerChampionWithOptions(veteranBraceofDwarfPistols);

    ws.addAbility(WarScroll::Ability("Precision Fire", 1));

    ws.addKeyWords({"ORDER", "DUARDIN", "DISPOSSESSED", "THUNDERERS"});

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eOrder);

    return ws;
  }

  WarScroll Gyrocopters(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(14, 4, 6, 4);

    ws.addWeapon(WarScroll::Weapon("Rotor Blades", 1, 3, 5, 4, 0, 1));

    ws.setMinMaxUnitCount(1, IFaction::s_MaxUnitSize);

    ws.setCanFly(true);

    WarScroll::WeaponUpgrade brimstoneGun(
      WarScroll::Weapon("Brimstone Gun", 16, 3, 3, 3, 1, 1),
      WarScroll::Ability());
    ws.addWeaponUpgrade(brimstoneGun);
    WarScroll::WeaponUpgrade steamGun(
      WarScroll::Weapon("Steam Gun", 6, 20, 3, 4, 1, 1),
      WarScroll::Ability("Steam Gun Ability", 3));
    ws.addWeaponUpgrade(steamGun);

    ws.addAbility(WarScroll::Ability("Guild Bombs", 2));

    ws.addKeyWords({"ORDER", "DUARDIN", "DISPOSSESSED", "WAR MACHINE",
      "GYROCOPTERS"});

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eOrder);

    return ws;
  }

  WarScroll Gyrobombers(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(12, 5, 6, 4);

    ws.addWeapon(WarScroll::Weapon("Rotor Blades", 1, 3, 5, 4, 0, 1));
    ws.addWeapon(WarScroll::Weapon("Clattergun", 20, 4, 4, 3, 1, 1));

    ws.setMinMaxUnitCount(1, IFaction::s_MaxUnitSize);

    ws.setCanFly(true);

    ws.addAbility(WarScroll::Ability("Grudgebuster Bombs", 2));

    ws.addKeyWords({"ORDER", "DUARDIN", "DISPOSSESSED", "WAR MACHINE",
      "GYROBOMBERS"});

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eOrder);

    return ws;
  }

  WarScroll Dwarf_Bolt_Thrower(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(4, 4, 10, 4);

    ws.addWeapon(WarScroll::Weapon("Runic Bolts", 38, 2, 3, 3, 1, 2));
    ws.addWeapon(WarScroll::Weapon("Crew's Tools", 1, 3, 4, 5, 0, 1));

    ws.addAbility(WarScroll::Ability("Duardin Artillery", 1));
    ws.addAbility(WarScroll::Ability("Penetrating Shot", 2));
    ws.addAbility(WarScroll::Ability("Rune of Skewering", 1));

    ws.addKeyWords({"ORDER", "WAR MACHINE", "DWARF BOLT THROWER", "DUARDIN",
      "DISPOSSESSED", "CREW"});

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eOrder);

    ws.addKeyWordConnection(WarScroll::KeyWordConnection(
      "DUARDIN and ENGINEERS", 1, WarScroll::Ability("Rune of Skewering", 1),
      1, WarScroll::KeyWordConnection::ConnectionAffectType::eFriendly,
      WarScroll::Spell()));

    return ws;
  }

  WarScroll Dwarf_Cannon(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(4, 4, 10, 4);

    ws.addWeapon(WarScroll::Weapon("Runic Bolts", 32, 2, 4, 2, 2, 6));
    ws.addWeapon(WarScroll::Weapon("Crew's Tools", 1, 3, 4, 5, 0, 1));

    ws.addAbility(WarScroll::Ability("Duardin Artillery", 1));
    ws.addAbility(WarScroll::Ability("Explosive Shells", 2));
    ws.addAbility(WarScroll::Ability("Rune of Accuracy", 1));

    ws.addKeyWords({"ORDER", "WAR MACHINE", "DWARF CANNON", "DUARDIN",
      "DISPOSSESSED", "CREW"});

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eOrder);

    ws.addKeyWordConnection(WarScroll::KeyWordConnection(
      "DUARDIN and ENGINEER", 1, WarScroll::Ability("Rune of Accuracy", 1),
      1, WarScroll::KeyWordConnection::ConnectionAffectType::eFriendly,
      WarScroll::Spell()));

    return ws;
  }

  WarScroll Flame_Cannon(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(4, 5, 10, 4);

    ws.addWeapon(WarScroll::Weapon("Flaming Burst", 24, 1, 0, 0, 0, 0));
    ws.addWeapon(WarScroll::Weapon("Crew's Tools", 1, 3, 4, 5, 0, 1));

    ws.addAbility(WarScroll::Ability("Duardin Artillery", 1));
    ws.addAbility(WarScroll::Ability("Flame Burst", 2));
    ws.addAbility(WarScroll::Ability("Rune of Burning", 1));

    ws.addKeyWords({"ORDER", "WAR MACHINE", "FLAME CANNON", "DUARDIN",
      "DISPOSSESSED", "CREW"});

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eOrder);

    ws.addKeyWordConnection(WarScroll::KeyWordConnection(
      "DUARDIN and ENGINEER", 1, WarScroll::Ability("Rune of Burning", 1),
      1, WarScroll::KeyWordConnection::ConnectionAffectType::eFriendly,
      WarScroll::Spell()));

    return ws;
  }

  WarScroll Organ_Gun(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(4, 4, 10, 4);

    ws.addWeapon(WarScroll::Weapon("Barrage of Shots", 28, 6, 3, 3, 1, 1));
    ws.addWeapon(WarScroll::Weapon("Crew's Tools", 1, 3, 4, 5, 0, 1));

    ws.addAbility(WarScroll::Ability("Duardin Artillery", 1));
    ws.addAbility(WarScroll::Ability("Organ Fire", 2));
    ws.addAbility(WarScroll::Ability("Rune of Forging", 1));

    ws.addKeyWords({"ORDER", "WAR MACHINE", "ORGAN GUN", "DUARDIN",
      "DISPOSSESSED", "CREW"});

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eOrder);

    ws.addKeyWordConnection(WarScroll::KeyWordConnection(
      "DUARDIN and ENGINEER", 1, WarScroll::Ability("Rune of Forging", 1),
      1, WarScroll::KeyWordConnection::ConnectionAffectType::eFriendly,
      WarScroll::Spell()));

    return ws;
  }

  WarScroll Grudge_Thrower(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(4, 4, 10, 4);

    ws.addWeapon(WarScroll::Weapon("Grudge Rock", 40, 1, 3, 3, 2, 3));
    ws.addWeapon(WarScroll::Weapon("Crew's Tools", 1, 3, 4, 5, 0, 1));

    ws.addAbility(WarScroll::Ability("Duardin Artillery", 1));
    ws.addAbility(WarScroll::Ability("Lobbed Shot", 2));
    ws.addAbility(WarScroll::Ability("Settling a Grudge", 2));
    ws.addAbility(WarScroll::Ability("Rune of Reloading", 1));

    ws.addKeyWords({"ORDER", "WAR MACHINE", "GRUDGE THROWER", "DUARDIN",
      "DISPOSSESSED", "CREW"});

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eOrder);

    ws.addKeyWordConnection(WarScroll::KeyWordConnection(
      "DUARDIN and ENGINEER", 1, WarScroll::Ability("Rune of Reloading", 1),
      1, WarScroll::KeyWordConnection::ConnectionAffectType::eFriendly,
      WarScroll::Spell()));

    return ws;
  }
}

DwarfsFaction::DwarfsFaction() :
  IFaction()
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

  std::sort(m_Units.begin(), m_Units.end());
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
