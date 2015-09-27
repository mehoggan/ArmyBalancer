#include "theempirefaction.h"

namespace WarScrollGeneration
{
  WarScroll Karl_Franz_on_Deathclaw(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(15, 13, 8, 4);

    ws.addWeapon(WarScroll::Weapon("Deathclaw's Deadly Beak",
      2, 2, 3, 3, 2, 6));
    ws.addWeapon(WarScroll::Weapon("Deathclaw's Razor Claws",
      2, 6, 3, 3, 1, 2));

    ws.addWeaponUpgrade(WarScroll::WeaponUpgrade(
      WarScroll::Weapon("The Reikland Runefang", 1, 4, 3, 3, 1, 3),
      WarScroll::Ability()));
    ws.addWeaponUpgrade(WarScroll::WeaponUpgrade(
      WarScroll::Weapon("Ghal Maraz", 1, 3, 4, 3, 2, 3),
      WarScroll::Ability()));

    ws.addAbility(WarScroll::Ability("Piercing Bloodroar", 1));
    ws.addAbility(WarScroll::Ability("The Silver Seal", 2));
    ws.addAbility(WarScroll::Ability("Loyal Beast", 2));
    ws.addAbility(WarScroll::Ability("Stirring Valour", 3));
    ws.addAbility(WarScroll::Ability("Leader of Men", 2, true));

    ws.setCanFly(true);

    ws.addKeyWords({"ORDER", "HUMAN", "GRIFFON", "FREE PEOPLE", "MONSTER",
      "HERO", "KARL FRANZ ON DEATHCLAW"});

    ws.addKeyWordConnection(WarScroll::KeyWordConnection("FREE PEOPLE",
      15, WarScroll::Ability("Stirring Valour", 3), 1,
      WarScroll::KeyWordConnection::ConnectionAffectType::eFriendly,
      WarScroll::Spell()));
    ws.addKeyWordConnection(WarScroll::KeyWordConnection("FREE PEOPLE",
      15, WarScroll::Ability("Leader of Men", 2, true), 1,
      WarScroll::KeyWordConnection::ConnectionAffectType::eFriendly,
      WarScroll::Spell()));

    return ws;
  }

  WarScroll Kurt_Helborg(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(10, 5, 7, 4);

    ws.addWeapon(WarScroll::Weapon("The Solland Runefang", 1, 4, 3, 3, 1, 3));
    ws.addWeapon(WarScroll::Weapon("Krieglust's Hooves", 1, 2, 4, 4, 0, 1));

    ws.addAbility(WarScroll::Ability("Laurels of Victory", 1));
    ws.addAbility(WarScroll::Ability("Pride fo the Reiksguard", 1));
    ws.addAbility(WarScroll::Ability("The Reiksmarshal", 1, true));

    ws.addKeyWords({"ORDER", "HUMAN", "FREE PEOPLE", "KNIGHTLY ORDERS",
      "HERO", "GRAND MASTER", "KURT HELBORG"});

    ws.addKeyWordConnection(WarScroll::KeyWordConnection("FREE PEOPLE",
      15, WarScroll::Ability("The Reiksmarshal", 1, true), 1,
      WarScroll::KeyWordConnection::ConnectionAffectType::eFriendly,
      WarScroll::Spell()));

    return ws;
  }

  WarScroll Balthasar_Gelt_the_Supreme_Patriarch(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(12, 5, 8, 4);

    ws.addWeapon(WarScroll::Weapon("Staff of Volans", 1, 2, 4, 3, 1, 3));
    ws.addWeapon(WarScroll::Weapon("Pegasus' Iron-hard Hooves",
      1, 2, 4, 4, 0, 1));

    ws.setCanFly(true);

    ws.addAbility(WarScroll::Ability("Amulet of Sea Gold", 1));
    ws.addAbility(WarScroll::Ability("Alchemist Supreme", 1));

    ws.addSpell(WarScroll::Spell("Searing Doom"), 6, 2);

    ws.addKeyWords({"ORDER", "HUMAN", "FREE PEOPLE", "HERO", "WIZARD",
      "BALTHASAR GELT"});

    ws.addKeyWordConnection(WarScroll::KeyWordConnection("WIZARD",
      18, WarScroll::Ability("Amulet of Sea Gold", 1), 1,
      WarScroll::KeyWordConnection::ConnectionAffectType::eEnemy,
      WarScroll::Spell()));

    return ws;
  }

  WarScroll Valten(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(5, 5, 7, 5);

    ws.addWeapon(WarScroll::Weapon("Blacksmith's Hammers", 1, 6, 3, 4, 0, 1));

    WarScroll::MountUpgrade mountUpgrade("Warhorse");
    mountUpgrade.addWeapon(WarScroll::Weapon("Ghal Maraz", 1, 3, 4, 3, 2, 3));
    mountUpgrade.addWeapon(WarScroll::Weapon("Warhorses's Steel-shod Hooves",
      1, 2, 4, 4, 0, 1));
    mountUpgrade.registerCharacteristicToIncrease("Move", 5);
    mountUpgrade.registerCharacteristicToIncrease("Save", -1);
    mountUpgrade.addRiderWeaponToReplace(WarScroll::Weapon(
      "Blacksmith's Hammers", 1, 6, 3, 4, 0, 1));
    ws.registerMountUpgrade(mountUpgrade);

    ws.addAbility(WarScroll::Ability("Iron Resolve", 3));
    ws.addAbility(WarScroll::Ability("Marked for Greatness", 2));

    ws.addKeyWords({"ORDER", "HUMAN", "FREE PEOPLE", "HERO", "VALTEN"});

    return ws;
  }

  WarScroll Marius_Leitdorf(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(10, 6, 7, 4);

    ws.addWeapon(WarScroll::Weapon("The Averland Runefang", 1, 3, 3, 3, 1, 3));
    ws.addWeapon(WarScroll::Weapon("Stiletto Dagger", 1, 2, 4, 4, 0, 1));
    ws.addWeapon(WarScroll::Weapon("Daisy's Steel-shod Hooves",
      1, 2, 4, 4, 0, 1));

    ws.addAbility(WarScroll::Ability("The Mad Count", 1));
    ws.addAbility(WarScroll::Ability("Lunatic Ravings", 2, true));

    ws.addKeyWords({"ORDER", "HUMAN", "FREE PEOPLE", "HERO", "EMPIRE GENERAL",
      "Marius Leitdorf"});

    ws.addKeyWordConnection(WarScroll::KeyWordConnection("STATE REGIMENT",
      15, WarScroll::Ability("Lunatic Ravings", 2, true), 1,
      WarScroll::KeyWordConnection::ConnectionAffectType::eFriendly,
      WarScroll::Spell()));

    return ws;
  }

  WarScroll Empire_General(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(5, 5, 7, 4);

    ws.addWeaponUpgrade(WarScroll::WeaponUpgrade(
      WarScroll::Weapon("Great Weapon", 1, 3, 3, 3, 2, 3),
      WarScroll::Ability()));
    WarScroll::WeaponUpgrade imperialWeaponUpgrade(
      WarScroll::Weapon("Sigmarite Weapon", 1, 5, 3, 4, 1, 1),
      WarScroll::Ability());
    ws.addWeaponUpgrade(imperialWeaponUpgrade);
    WarScroll::WeaponUpgrade imperialShieldUpgrade(
      WarScroll::Weapon("Sigmarite Weapon", 1, 5, 3, 4, 1, 1),
      WarScroll::Ability("Imperial Shield", 2));
    imperialShieldUpgrade.registerCharacteristicToIncrease("Save", -1);
    ws.addWeaponUpgrade(imperialShieldUpgrade);
    WarScroll::WeaponUpgrade pistolUpgrade(
      WarScroll::Weapon("Sigmarite Weapon", 1, 5, 3, 4, 1, 1),
      WarScroll::Ability());
    pistolUpgrade.setSecondaryWeapon(WarScroll::Weapon(
      "Pistol", 9, 1, 4, 3, 1, 1));
    pistolUpgrade.registerCharacteristicToIncrease("Save", -1);
    ws.addWeaponUpgrade(pistolUpgrade);

    WarScroll::MountUpgrade warHorse("Warhorse");
    warHorse.addWeapon(WarScroll::Weapon(
      "Warhorse's Steel-shod Hooves", 1, 2, 4, 4, 0, 1));
    warHorse.registerCharacteristicToIncrease("Move", 7);
    ws.registerMountUpgrade(warHorse);

    WarScroll::MountUpgrade warHorseWithLanceAndShield(
      "Warhorse with Lance and Shield");
    warHorseWithLanceAndShield.addWeapon(WarScroll::Weapon(
      "Imperial Lance", 2, 3, 3, 4, 1, 2));
    warHorseWithLanceAndShield.addWeapon(WarScroll::Weapon(
      "Warhorse's Steel-shod Hooves", 1, 2, 4, 4, 0, 1));
    warHorseWithLanceAndShield.addAbility(WarScroll::Ability(
      "Imperial Shield", 2));
    warHorseWithLanceAndShield.addAbility(WarScroll::Ability(
      "Charging Lance", 1));
    warHorseWithLanceAndShield.addAbility(WarScroll::Ability(
      "Imperial Shield", 2));
    warHorseWithLanceAndShield.registerCharacteristicToIncrease("Save", -1);
    warHorseWithLanceAndShield.registerCharacteristicToIncrease("Move", 7);
    warHorseWithLanceAndShield.addRiderWeaponToReplace(WarScroll::Weapon(
      "Sigmarite Weapon", 1, 5, 3, 4, 1, 1));
    warHorseWithLanceAndShield.addRiderWeaponToReplace(WarScroll::Weapon(
      "Great Weapon", 1, 3, 3, 3, 2, 3));
    warHorseWithLanceAndShield.addRiderWeaponToReplace(WarScroll::Weapon(
      "Pistol", 9, 1, 4, 3, 1, 1));
    warHorseWithLanceAndShield.addRiderAbilityToRemove(WarScroll::Ability(
      "Imperial Shield", 2));
    ws.registerMountUpgrade(warHorseWithLanceAndShield);

    WarScroll::MountUpgrade warHorseWithLance("Warhorse with Lance");
    warHorseWithLance.addWeapon(WarScroll::Weapon(
      "Imperial Lance", 2, 3, 3, 4, 1, 2));
    warHorseWithLance.addWeapon(WarScroll::Weapon(
      "Warhorse's Steel-shod Hooves", 1, 2, 4, 4, 0, 1));
    warHorseWithLance.addAbility(WarScroll::Ability("Charging Lance", 1));
    warHorseWithLance.registerCharacteristicToIncrease("Move", 7);
    warHorseWithLance.addRiderWeaponToReplace(WarScroll::Weapon(
      "Sigmarite Weapon", 1, 5, 3, 4, 1, 1));
    warHorseWithLance.addRiderWeaponToReplace(WarScroll::Weapon(
      "Great Weapon", 1, 3, 3, 3, 2, 3));
    warHorseWithLance.addRiderWeaponToReplace(WarScroll::Weapon(
      "Pistol", 9, 1, 4, 3, 1, 1));
    warHorseWithLance.addRiderAbilityToRemove(WarScroll::Ability(
      "Imperial Shield", 2));
    warHorseWithLance.setCharacteristics(std::make_tuple("Save", 4));
    ws.registerMountUpgrade(warHorseWithLance);

    {
      WarScroll::UnitUpgrade upgrade("Stately War Banner",
        WarScroll::UnitUpgrade::UnitUpgradeType::eBannerBearer, 2);
      upgrade.addAbility(WarScroll::Ability("Stately War Banner", 1));
      upgrade.addKeyWordConnection(WarScroll::KeyWordConnection(
        "STATE REGIMENT", 24, WarScroll::Ability("Stately War Banner", 1), 1,
        WarScroll::KeyWordConnection::ConnectionAffectType::eFriendly,
        WarScroll::Spell()));
      ws.registerUnitUpgrade(upgrade);
    }

    ws.addAbility(WarScroll::Ability("Hold the Line", 1, true));

    ws.addKeyWords({"ORDER", "HUMAN", "FREE PEOPLE", "HERO", "EMPIRE GENERAL"});

    ws.addKeyWordConnection(WarScroll::KeyWordConnection("STATE REGIMENTS",
      15, WarScroll::Ability("Hold the Line", 1, true), 1,
      WarScroll::KeyWordConnection::ConnectionAffectType::eFriendly,
      WarScroll::Spell()));

    return ws;
  }

  WarScroll General_of_the_Empire_on_Imperial_Griffon(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(15, 13, 7, 4);

    ws.addWeapon(WarScroll::Weapon("Imperial Griffon's Deadly Beak",
      2, 2, 3, 3, 2, 6));
    ws.addWeapon(WarScroll::Weapon("Imperial Griffon's Razor Claws",
      2, 6, 4, 3, 1, 2));

    WarScroll::WeaponUpgrade lance(
      WarScroll::Weapon("Imperial Lance", 2, 3, 3, 4, 1, 2),
      WarScroll::Ability("Charging Lance", 1));
    ws.addWeaponUpgrade(lance);
    WarScroll::WeaponUpgrade runeFang(
      WarScroll::Weapon("Runefang", 1, 4, 3, 3, 1, 3),
      WarScroll::Ability());
    ws.addWeaponUpgrade(runeFang);
    WarScroll::WeaponUpgrade warHammer(
      WarScroll::Weapon("Magical Warhammer", 1, 2, 4, 3, 2, 3),
      WarScroll::Ability());
    ws.addWeaponUpgrade(warHammer);

    WarScroll::UnitUpgrade imperialShield("Imperial Shield",
      WarScroll::UnitUpgrade::UnitUpgradeType::eShield, 2);
    imperialShield.registerCharacteristicToIncrease("Save", -1);
    ws.registerUnitUpgrade(imperialShield);

    ws.addAbility(WarScroll::Ability("Piercing Bloodroar", 2));
    ws.addAbility(WarScroll::Ability("Rousing Battle Cry", 2, true));

    ws.setCanFly(true);

    ws.addKeyWords({"ORDER", "HUMAN", "GRIFFON", "FREE PEOPLE", "MONSTER",
      "HERO", "EMPIRE GENERAL"});

    ws.addKeyWordConnection(WarScroll::KeyWordConnection(
      "STATE REGIMENT or KNIGHTLY ORDER", 15,
      WarScroll::Ability("Rousing Battle Cry", 2, true), 1,
      WarScroll::KeyWordConnection::ConnectionAffectType::eFriendly,
      WarScroll::Spell()));

    return ws;
  }

  WarScroll Ludwig_Schwarzhelm(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(10, 5, 7, 4);

    ws.addWeapon(WarScroll::Weapon("The Sword of Justice",
      1, 4, 3, 3, 0, 2));
    ws.addWeapon(WarScroll::Weapon("Warhorse's Steel-shod Hooves",
      1, 2, 4, 4, 0, 1));

    ws.addAbility(WarScroll::Ability("The Sword of Justice", 2));
    ws.addAbility(WarScroll::Ability("The Emperor's Bodyguard", 1));

    ws.addAbility(WarScroll::Ability("The Emperor's Standard", 2));

    ws.addKeyWords({"ORDER", "HUMANS", "FREE PEOPLE", "HERO", "TOTEM",
      "LUDWIG SCHWARZHELM"});

    ws.addKeyWordConnection(WarScroll::KeyWordConnection("KARL FRANZ",
      3, WarScroll::Ability("The Emperor's Bodyguard", 1), 1,
      WarScroll::KeyWordConnection::ConnectionAffectType::eFriendly,
      WarScroll::Spell()));
    ws.addKeyWordConnection(WarScroll::KeyWordConnection(
      "STATE REGIMENT or KNIGHTLY ORDER", 24,
      WarScroll::Ability("The Emperor's Standard", 2), 1,
      WarScroll::KeyWordConnection::ConnectionAffectType::eFriendly,
      WarScroll::Spell()));

    return ws;
  }

  WarScroll Markus_Wulfhart(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(6, 5, 7, 5);

    ws.addWeapon(WarScroll::Weapon("The Amber Bow", 20, 1, 3, 3, 1, 3));
    ws.addWeapon(WarScroll::Weapon("Woodman's Longsword", 1, 3, 4, 4, 0, 1));

    ws.addAbility(WarScroll::Ability("Monster Hunter", 1));
    ws.addAbility(WarScroll::Ability("The Amber Bow", 2));

    ws.addAbility(WarScroll::Ability("Wulfhart's Hunters", 2));

    ws.addKeyWords({"ORDER", "HUMAN", "FREE PEOPLE", "HERO", "WULFHART"});

    return ws;
  }

  WarScroll Grand_Master(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(10, 5, 7, 4);

    ws.addWeapon(WarScroll::Weapon("Heirloom Weapon", 1, 4, 3, 3, 1, 1));
    ws.addWeapon(WarScroll::Weapon("Warhorse's Steel-shod Hooves",
      1, 2, 4, 4, 0, 1));

    WarScroll::UnitUpgrade imperialShield("Imperial Shield",
      WarScroll::UnitUpgrade::UnitUpgradeType::eShield, 2);
    imperialShield.registerCharacteristicToIncrease("Save", -1);
    ws.registerUnitUpgrade(imperialShield);

    ws.addAbility(WarScroll::Ability("Knights of the Inner Circle", 1));
    ws.addAbility(WarScroll::Ability("Master of Battle", 2, true));

    ws.addKeyWords({"ORDER", "HUMAN", "FREE PEOPLE", "KNIGHTLY ORDERS",
      "HERO", "GRAND MASTER"});

    return ws;
  }

  WarScroll Demigryph_Knights(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(10, 4, 6, 4);

    ws.addWeapon(WarScroll::Weapon("Demigryph's Razor-sharp Talons",
      1, 3, 4, 3, 1, 1));

    ws.setMinMaxUnitCount(3, IFaction::s_MaxUnitSize);

    ws.addWeaponUpgrade(WarScroll::WeaponUpgrade(
      WarScroll::Weapon("Lance and Sword", 2, 2, 4, 4, 0, 1),
      WarScroll::Ability("Charging Lance", 1)));
    ws.addWeaponUpgrade(WarScroll::WeaponUpgrade(
      WarScroll::Weapon("Cavalry Hallberd", 2, 2, 4, 3, 0, 1),
      WarScroll::Ability()));

    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Preceptor",
      WarScroll::UnitUpgrade::UnitUpgradeType::eChampion, 1));

    WarScroll::ChampionWithOptions preceptorWithLance(
      "Preceptor with Lance", 1);
    preceptorWithLance.addWeapon(WarScroll::Weapon("Lance and Sword",
      2, 2, 4, 4, 0, 1));
    ws.registerChampionWithOptions(preceptorWithLance);
    WarScroll::ChampionWithOptions preceptorWithHalberd(
      "Preceptor with Hallberd", 1);
    preceptorWithLance.addWeapon(WarScroll::Weapon("Cavalry Hallberd",
      2, 2, 4, 3, 0, 1));
    ws.registerChampionWithOptions(preceptorWithHalberd);

    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Standard Bearer",
      WarScroll::UnitUpgrade::UnitUpgradeType::eBannerBearer, 1));
    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Hornblower",
      WarScroll::UnitUpgrade::UnitUpgradeType::eMusician, 1));

    ws.addAbility(WarScroll::Ability("Shield", 1));
    ws.addAbility(WarScroll::Ability("Savage Ferocity", 1));

    ws.addKeyWords({"ORDER", "HUMAN", "FREE PEOPLE", "KNIGHTLY ORDERS",
      "DEMIGRYPH KNIGHTS"});

    return ws;
  }

  WarScroll Empire_Knights(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(10, 4, 6, 4);

    ws.addWeapon(WarScroll::Weapon("Warhorse's Steel-shod Hooves",
      1, 2, 4, 4, 0, 1));

    ws.setMinMaxUnitCount(5, IFaction::s_MaxUnitSize);

    WarScroll::WeaponUpgrade lanceUpgrade(
      WarScroll::Weapon("Lance and Sword", 2, 1, 4, 4, 0, 1),
      WarScroll::Ability("Charging Lance", 1));
    lanceUpgrade.addAbility(WarScroll::Ability("Shield", 1));
    ws.addWeaponUpgrade(lanceUpgrade);

    ws.addWeaponUpgrade(WarScroll::WeaponUpgrade(
      WarScroll::Weapon("Cavalry Hammer", 1, 2, 4, 4, 0, 1),
      WarScroll::Ability()));

    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Preceptor",
      WarScroll::UnitUpgrade::UnitUpgradeType::eChampion, 1));

    WarScroll::ChampionWithOptions preceptorWithLance(
      "Preceptor with Lance", 1);
    preceptorWithLance.addWeapon(WarScroll::Weapon("Lance and Sword",
      2, 2, 4, 4, 0, 1));
    preceptorWithLance.addAbility(WarScroll::Ability("Shield", 1));
    ws.registerChampionWithOptions(preceptorWithLance);

    WarScroll::ChampionWithOptions preceptorWithHammer(
      "Preceptor with Hallberd", 1);
    preceptorWithLance.addWeapon(WarScroll::Weapon("Cavalry Hammer",
      2, 2, 4, 3, 0, 1));
    ws.registerChampionWithOptions(preceptorWithHammer);

    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Standard Bearer",
      WarScroll::UnitUpgrade::UnitUpgradeType::eBannerBearer, 1));
    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Hornblower",
      WarScroll::UnitUpgrade::UnitUpgradeType::eMusician, 1));

    ws.addAbility(WarScroll::Ability("Duty and Honour", 1));

    ws.addKeyWords({ "ORDER", "HUMAN", "FREE PEOPLE", "KNIGHTLY ORDERS",
      "EMPIRE KNIGHTS" });

    return ws;
  }

  WarScroll Reiksguard_Knights(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(10, 2, 7, 4);

    ws.addWeapon(WarScroll::Weapon("Reiklance and Sword", 1, 1, 3, 4, 0, 1));
    ws.addWeapon(WarScroll::Weapon("Warhorse's Steel-shod Hooves",
      1, 2, 4, 4, 0, 1));

    ws.setMinMaxUnitCount(5, IFaction::s_MaxUnitSize);

    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Reikscaptin",
      WarScroll::UnitUpgrade::UnitUpgradeType::eChampion, 1));
    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Standard Bearer",
      WarScroll::UnitUpgrade::UnitUpgradeType::eBannerBearer, 1));
    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Hornblower",
      WarScroll::UnitUpgrade::UnitUpgradeType::eMusician, 1));

    ws.addAbility(WarScroll::Ability("Shields", 1));
    ws.addAbility(WarScroll::Ability("The Emperor's Chosen", 1));
    ws.addAbility(WarScroll::Ability("Charging Lance", 1));

    ws.addKeyWords({"ORDER", "HUMAN", "FREE PEOPLE", "KNIGHTLY ORDERS",
      "REIKSGUARD KNIGHTS"});

    return ws;
  }

  WarScroll Empire_Crossbowmen(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(5, 1, 5, 6);

    ws.addWeapon(WarScroll::Weapon("Crossbow", 20, 1, 4, 4, 0, 1));
    ws.addWeapon(WarScroll::Weapon("Dagger", 1, 1, 5, 5, 0, 1));

    ws.setMinMaxUnitCount(10, IFaction::s_MaxUnitSize);

    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Marksman",
      WarScroll::UnitUpgrade::UnitUpgradeType::eChampion, 1));
    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Standard Bearer",
      WarScroll::UnitUpgrade::UnitUpgradeType::eBannerBearer, 1));
    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Pipers",
      WarScroll::UnitUpgrade::UnitUpgradeType::eMusician, 1));

    ws.addAbility(WarScroll::Ability("Piercing Bolts", 1));
    ws.addAbility(WarScroll::Ability("Reload, Fire", 1));

    ws.addKeyWords({"ORDER", "HUMAN", "FREE PEOPLE", "STATE REGIMENT",
      "EMPIRE CROSSBOWMEN"});

    return ws;
  }

  WarScroll Empire_Handgunners(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(5, 1, 5, 6);

    ws.addWeapon(WarScroll::Weapon("Imperial Handgun", 16, 1, 5, 3, 1, 1));
    ws.addWeapon(WarScroll::Weapon("Dagger", 1, 1, 5, 5, 0, 1));

    ws.setMinMaxUnitCount(10, IFaction::s_MaxUnitSize);

    WarScroll::ChampionWithOptions marksmanWithHandGun(
      "Marksman with Handgun", 1);
    marksmanWithHandGun.addWeapon(WarScroll::Weapon(
      "Imperial Handgun", 16, 1, 5, 3, 1, 1));
    ws.registerChampionWithOptions(marksmanWithHandGun);
    WarScroll::ChampionWithOptions marksmanWithHochlandLongRifle(
      "Marksman with Hochland Long Rifle", 2);
    ws.registerChampionWithOptions(marksmanWithHochlandLongRifle);
    marksmanWithHochlandLongRifle.addWeapon(WarScroll::Weapon(
      "Hochland Long Rifle", 30, 1, 4, 3, 1, 2));
    WarScroll::ChampionWithOptions marksmanWithRepeaterHandgun(
      "Marksman with Repeater Handgun", 1);
    marksmanWithRepeaterHandgun.addWeapon(WarScroll::Weapon(
      "Repeater Handgun", 10, 3, 4, 3, 1, 1));
    ws.registerChampionWithOptions(marksmanWithRepeaterHandgun);

    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Marksman",
      WarScroll::UnitUpgrade::UnitUpgradeType::eChampion, 1));
    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Standard Bearer",
      WarScroll::UnitUpgrade::UnitUpgradeType::eBannerBearer, 1));
    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Pipers",
      WarScroll::UnitUpgrade::UnitUpgradeType::eMusician, 1));

    ws.addAbility(WarScroll::Ability("Steady Aim", 1));
    ws.addAbility(WarScroll::Ability("Handgun Volley", 1));

    ws.addKeyWords({"ORDER", "HUMAN", "FREE PEOPLE", "STATE REGIMENT", 
      "EMPIRE HANDGUNNERS"});

    return ws;
  }

  WarScroll Empire_Archers(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(5, 1, 5, 6);

    ws.addWeapon(WarScroll::Weapon("Bow", 18, 1, 4, 4, 0, 1));
    ws.addWeapon(WarScroll::Weapon("Imperial Shortsword", 1, 1, 5, 4, 0, 1));

    ws.setMinMaxUnitCount(10, IFaction::s_MaxUnitSize);

    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Marksman",
      WarScroll::UnitUpgrade::UnitUpgradeType::eChampion, 1));

    ws.addAbility(WarScroll::Ability("Huntsmen", 1));
    ws.addAbility(WarScroll::Ability("Ordered Volleys", 1));

    ws.addKeyWords({"ORDER", "HUMAN", "FREE PEOPLE", "STATE REGIMENT",
      "EMPIRE ARCHERS"});

    return ws;
  }

  WarScroll Empire_Greatswords(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(5, 1, 6, 4);

    ws.addWeapon(WarScroll::Weapon("Zweihonder", 1, 2, 4, 3, 1, 1));

    ws.setMinMaxUnitCount(5, IFaction::s_MaxUnitSize);

    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Count's Champion",
      WarScroll::UnitUpgrade::UnitUpgradeType::eChampion, 1));
    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Standard Bearer",
      WarScroll::UnitUpgrade::UnitUpgradeType::eBannerBearer, 1));
    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Hornblower",
      WarScroll::UnitUpgrade::UnitUpgradeType::eMusician, 1));

    ws.addAbility(WarScroll::Ability("Oathsworn Honuor Guard", 1));

    ws.addKeyWords({"ORDER", "HUMAN", "FREE PEOPLE", "STATE REGIMENT",
      "EMPIRE GREATSWORD"});

    return ws;
  }

  WarScroll Empire_Pistoliers(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(12, 2, 5, 5);

    ws.addWeapon(WarScroll::Weapon("Brace of Pistols", 9, 2, 5, 3, 1, 1));
    ws.addWeapon(WarScroll::Weapon("Brace of Pistols", 1, 2, 5, 3, 1, 1));
    ws.addWeapon(WarScroll::Weapon("Steed's Stamping Hooves",
      1, 2, 4, 5, 0, 1));

    ws.setMinMaxUnitCount(5, IFaction::s_MaxUnitSize);

    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Trumpeters",
      WarScroll::UnitUpgrade::UnitUpgradeType::eMusician, 2));
    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Outrider",
      WarScroll::UnitUpgrade::UnitUpgradeType::eChampion, 1));

    WarScroll::ChampionWithOptions outriderWithBraceOfPistols(
      "Outrider with Brace of Pistols", 1);
    outriderWithBraceOfPistols.addWeapon(WarScroll::Weapon(
      "Brace of Pistols", 9, 3, 4, 3, 1, 1));
    outriderWithBraceOfPistols.addWeapon(WarScroll::Weapon(
      "Brace of Pistols", 1, 3, 4, 3, 1, 1));
    outriderWithBraceOfPistols.addWeapon(WarScroll::Weapon(
      "Cavalry Sabre", 1, 1, 4, 4, 0, 1));
    outriderWithBraceOfPistols.addWeapon(WarScroll::Weapon(
      "Steed's Stamping Hooves", 1, 2, 4, 5, 0, 1));
    outriderWithBraceOfPistols.addAbility(WarScroll::Ability(
      "Repeater Pistol", 1));
    ws.registerChampionWithOptions(outriderWithBraceOfPistols);

    WarScroll::ChampionWithOptions outriderWithRepeaterHandgun(
      "Outrider with Repater Handgun", 1);
    outriderWithRepeaterHandgun.addWeapon(WarScroll::Weapon(
      "Repeater Handgun", 14, 3, 4, 3, 1, 1));
    outriderWithRepeaterHandgun.addWeapon(WarScroll::Weapon(
      "Cavalry Sabre", 1, 1, 4, 4, 0, 1));
    outriderWithRepeaterHandgun.addWeapon(WarScroll::Weapon(
      "Steed's Stamping Hooves", 1, 2, 4, 5, 0, 1));
    ws.registerChampionWithOptions(outriderWithRepeaterHandgun);

    ws.addAbility(WarScroll::Ability("Reckless Riders", 1));

    ws.addKeyWords({"ORDER", "HUMAN", "FREE PEOPLE", "STATE REGIMENT",
      "EMPIRE PISTOLIERS"});
    
    return ws;
  }

  WarScroll Empire_Outriders(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(12, 2, 6, 5);

    ws.addWeapon(WarScroll::Weapon("Repeater Handgun", 14, 3, 5, 3, 1, 1));
    ws.addWeapon(WarScroll::Weapon("Cavalry Sabre", 1, 1, 4, 4, 0, 1));
    ws.addWeapon(WarScroll::Weapon("Steed's Stamping Hooves",
      1, 2, 4, 5, 0, 1));

    ws.setMinMaxUnitCount(5, IFaction::s_MaxUnitSize);

    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Trumpeters",
      WarScroll::UnitUpgrade::UnitUpgradeType::eMusician, 2));
    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Outrider",
      WarScroll::UnitUpgrade::UnitUpgradeType::eChampion, 1));

    WarScroll::ChampionWithOptions sharpshooterWithRepeaterHandgun(
      "Outrider with Repater Handgun", 1);
    sharpshooterWithRepeaterHandgun.addWeapon(WarScroll::Weapon(
      "Repeater Handgun", 14, 3, 4, 3, 1, 1));
    sharpshooterWithRepeaterHandgun.addWeapon(WarScroll::Weapon(
      "Cavalry Sabre", 1, 2, 4, 4, 0, 1));
    sharpshooterWithRepeaterHandgun.addWeapon(WarScroll::Weapon(
      "Steed's Stamping Hooves", 1, 2, 4, 5, 0, 1));
    sharpshooterWithRepeaterHandgun.addAbility(WarScroll::Ability(
      "Expert Gunners", 1));
    ws.registerChampionWithOptions(sharpshooterWithRepeaterHandgun);

    WarScroll::ChampionWithOptions sharpshooterWithBraceOfPistols(
      "Outrider with Brace of Pistols", 1);
    sharpshooterWithBraceOfPistols.addWeapon(WarScroll::Weapon(
      "Brace of Pistols", 9, 3, 4, 3, 1, 1));
    sharpshooterWithBraceOfPistols.addWeapon(WarScroll::Weapon(
      "Brace of Pistols", 1, 3, 4, 3, 1, 1));
    sharpshooterWithBraceOfPistols.addWeapon(WarScroll::Weapon(
      "Cavalry Sabre", 1, 2, 4, 4, 0, 1));
    sharpshooterWithBraceOfPistols.addWeapon(WarScroll::Weapon(
      "Steed's Stamping Hooves", 1, 2, 4, 5, 0, 1));
    sharpshooterWithBraceOfPistols.addAbility(WarScroll::Ability(
      "Repeater Pistol", 1));
    sharpshooterWithBraceOfPistols.addAbility(WarScroll::Ability(
      "Expert Gunners", 1));
    ws.registerChampionWithOptions(sharpshooterWithBraceOfPistols);

    WarScroll::ChampionWithOptions sharpshooterWithGenadeLaunchingBlunderbuss(
      "Sharpshooter with Grenade Launching Blunderbuss", 1);
    sharpshooterWithGenadeLaunchingBlunderbuss.addWeapon(WarScroll::Weapon(
      "Grenade Launching Bluderbuss", 10, 1, 4, 3, 2, 3));
    sharpshooterWithGenadeLaunchingBlunderbuss.addWeapon(WarScroll::Weapon(
      "Cavalry Sabre", 1, 2, 4, 4, 0, 1));
    sharpshooterWithGenadeLaunchingBlunderbuss.addWeapon(WarScroll::Weapon(
      "Steed's Stamping Hooves", 1, 2, 4, 5, 0, 1));
    sharpshooterWithGenadeLaunchingBlunderbuss.addAbility(WarScroll::Ability(
      "Expert Gunners", 1));
    ws.registerChampionWithOptions(sharpshooterWithGenadeLaunchingBlunderbuss);

    ws.addKeyWords({ "ORDER", "HUMAN", "FREE PEOPLE", "STATE REGIMENT",
      "EMPIRE OUTRIDERS" });

    return ws;
  }

  WarScroll Empire_State_Troops(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(5, 1, 5, 5);

    ws.setMinMaxUnitCount(10, IFaction::s_MaxUnitSize);

    WarScroll::WeaponUpgrade halberdUpgrade(
      WarScroll::Weapon("Halberd", 1, 1, 4, 4, 1, 1),
      WarScroll::Ability());
    WarScroll::WeaponUpgrade spearUpgrade(
      WarScroll::Weapon("Spear", 2, 1, 4, 4, 0, 1),
      WarScroll::Ability());
    WarScroll::WeaponUpgrade swordUpgrade(
      WarScroll::Weapon("Sword", 1, 1, 4, 4, 0, 1),
      WarScroll::Ability("Parry", 1));

    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Sergeant",
      WarScroll::UnitUpgrade::UnitUpgradeType::eChampion, 1));
    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Standard Bearer",
      WarScroll::UnitUpgrade::UnitUpgradeType::eBannerBearer, 1));
    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Drummers",
      WarScroll::UnitUpgrade::UnitUpgradeType::eMusician, 1));
    WarScroll::UnitUpgrade shield("Shield",
      WarScroll::UnitUpgrade::UnitUpgradeType::eShield, 1);
    shield.addAbility(WarScroll::Ability("Shield", 1));
    ws.registerUnitUpgrade(shield);

    ws.addAbility(WarScroll::Ability("Massed Ranks", 1));

    ws.addKeyWords({"ORDER", "HUMAN", "FREE PEOPLE", "STATE REGIMENT",
      "STATE TROOPS"});

    return ws;
  }

  WarScroll Empire_Free_Company_Militia(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(5, 1, 5, 6);

    ws.addWeapon(WarScroll::Weapon("Militia Weapon", 14, 1, 5, 4, 0, 1));
    ws.addWeapon(WarScroll::Weapon("Militia Weapon", 1, 1, 4, 4, 0, 1));

    ws.setMinMaxUnitCount(10, IFaction::s_MaxUnitSize);

    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Militia Leader",
      WarScroll::UnitUpgrade::UnitUpgradeType::eChampion, 1));

    ws.addAbility(WarScroll::Ability("Reckless Mob", 1));

    ws.addKeyWords({"ORDER", "HUMAN", "FREE PEOPLE", "EMPIRE FREE COMPANY",
      "MILITIA"});

    return ws;
  }

  WarScroll Empire_Master_Engineer(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(5, 5, 6, 6);

    ws.addWeapon(WarScroll::Weapon("Engineer's Telescope or Tool",
      1, 2, 5, 5, 0, 1));

    WarScroll::WeaponUpgrade pistolAndRepeaterHandgun(
      WarScroll::Weapon("Pistol", 9, 1, 4, 3, 1, 1),
      WarScroll::Ability());
    pistolAndRepeaterHandgun.setSecondaryWeapon(WarScroll::Weapon(
      "Repeater Handgun", 14, 3, 4, 3, 1, 1));
    ws.addWeaponUpgrade(pistolAndRepeaterHandgun);

    WarScroll::WeaponUpgrade pistolAndArtisanRepeaterPistol(
      WarScroll::Weapon("Pistol", 9, 1, 4, 3, 1, 1),
      WarScroll::Ability());
    pistolAndArtisanRepeaterPistol.setSecondaryWeapon(WarScroll::Weapon(
      "Artisian Repeater Pistol", 9, 3, 4, 3, 1, 1));
    ws.addWeaponUpgrade(pistolAndArtisanRepeaterPistol);

    WarScroll::WeaponUpgrade pistolAndRepeaterHandgunWithLongRifle(
      WarScroll::Weapon("Pistol", 9, 1, 4, 3, 1, 1),
      WarScroll::Ability());
    pistolAndRepeaterHandgunWithLongRifle.setSecondaryWeapon(
      WarScroll::Weapon("Repeater Handgun", 14, 3, 4, 3, 1, 1));
    pistolAndRepeaterHandgunWithLongRifle.setTertiaryWeapon(
      WarScroll::Weapon("Hochland Long Rifle", 30, 1, 3, 3, 1, 2));
    ws.addWeaponUpgrade(pistolAndRepeaterHandgunWithLongRifle);

    WarScroll::WeaponUpgrade pistolAndArtisanRepeaterPistolWithLongRifle(
      WarScroll::Weapon("Pistol", 9, 1, 4, 3, 1, 1),
      WarScroll::Ability());
    pistolAndArtisanRepeaterPistolWithLongRifle.setSecondaryWeapon(
      WarScroll::Weapon("Artisian Repeater Pistol", 9, 3, 4, 3, 1, 1));
    pistolAndArtisanRepeaterPistolWithLongRifle.setTertiaryWeapon(
      WarScroll::Weapon("Hochland Long Rifle", 30, 1, 3, 3, 1, 2));
    ws.addWeaponUpgrade(pistolAndArtisanRepeaterPistolWithLongRifle);

    WarScroll::UnitUpgrade pigeonBomb("Pigeon Bombs",
      WarScroll::UnitUpgrade::UnitUpgradeType::eOther, 2);
    pigeonBomb.addAbility(WarScroll::Ability());
    ws.registerUnitUpgrade(pigeonBomb);

    ws.addKeyWords({ "ORDER", "HUMAN", "FREE PEOPLE", "HERO", "ENGINEER",
      "EMPIRE MASTER ENGINEER" });

    return ws;
  }

  WarScroll Master_Engineer_on_Mechanical_Steed(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(5, 5, 6, 6);

    ws.addWeapon(WarScroll::Weapon("Mechanical Steed's Steel Hooves",
      1, 2, 5, 4, 1, 1));

    WarScroll::WeaponUpgrade imperialHandgun(
      WarScroll::Weapon("Imperial Handgun", 16, 1, 4, 3, 1, 1),
      WarScroll::Ability());
    ws.addWeaponUpgrade(imperialHandgun);

    WarScroll::WeaponUpgrade grenadeLaunchingBlunderBuss(
      WarScroll::Weapon("Grenade Launching Blunderbuss", 10, 1, 4, 3, 2, 3),
      WarScroll::Ability());
    ws.addWeaponUpgrade(grenadeLaunchingBlunderBuss);

    WarScroll::WeaponUpgrade repeaterHandGun(
      WarScroll::Weapon("Repeater Handgun", 14, 3, 4, 3, 1, 1),
      WarScroll::Ability());
    ws.addWeaponUpgrade(repeaterHandGun);

    WarScroll::WeaponUpgrade hochlandLongRifle(
      WarScroll::Weapon("Hochland Long Rifle", 30, 1, 3, 3, 1, 2),
      WarScroll::Ability());
    ws.addWeaponUpgrade(hochlandLongRifle);

    ws.addAbility(WarScroll::Ability("Range-finding Optics", 1));
    ws.addAbility(WarScroll::Ability("Clockwork Charge", 2));

    ws.addKeyWords({"ORDER", "HUMAN", "FREE PEOPLE", "HERO", "ENGINEER",
      "MASTER ENGINEER ON MECHANICAL STEED"});

    return ws;
  }

  WarScroll Empire_Cannon(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(4, 4, 10, 4);

    ws.addWeapon(WarScroll::Weapon("Cannon Ball", 40, 2, 4, 2, 2, 6));
    ws.addWeapon(WarScroll::Weapon("Crew's Tools", 1, 3, 5, 5, 0, 1));

    ws.addAbility(WarScroll::Ability("Crewed Artillery", 1));
    ws.addAbility(WarScroll::Ability("Grapeshot", 2));
    ws.addAbility(WarScroll::Ability("Artillery Master", 1));

    ws.addKeyWords({"ORDER", "WAR MACHINE", "EMPIRE CANNON", "HUMAN",
      "FREE PEOPLE", "CREW"});

    return ws;
  }

  WarScroll Empire_Mortor(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(4, 4, 10, 4);

    ws.addWeapon(WarScroll::Weapon("Mortar Shell", 30, 1, 2, 3, 1, 3));
    ws.addWeapon(WarScroll::Weapon("Crew's Tools", 1, 3, 5, 5, 0, 1));

    ws.addAbility(WarScroll::Ability("Crewed Artillery", 1));
    ws.addAbility(WarScroll::Ability("Artillery Barrage", 1));
    ws.addAbility(WarScroll::Ability("High Explosive", 2));
    ws.addAbility(WarScroll::Ability("My Own Recipe", 2)); // HUMAN ENGINEER

    ws.addKeyWords({"ORDER", "WAR MACHINE", "EMPIRE EMPIRE", "HUMAN",
      "FREE PEOPLE", "CREW"});

    return ws;
  }

  WarScroll Hellblaster_Volley_Gun(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(4, 4, 10, 4);

    ws.addWeapon(WarScroll::Weapon("Volley of Shots", 26, 6, 3, 3, 1, 1));
    ws.addWeapon(WarScroll::Weapon("Crew's Tools", 1, 3, 5, 5, 0, 1));

    ws.addAbility(WarScroll::Ability("Point Blank", 1));
    ws.addAbility(WarScroll::Ability("Crewed Artillery", 1));
    ws.addAbility(WarScroll::Ability("Hellblaster Volley", 3));
    ws.addAbility(WarScroll::Ability("Working Like Clockwork", 2)); // HUMAN ENGINEER

    ws.addKeyWords({"ORDER", "WAR MACHINE", "HELBLASTER VOLLEY GUN", "HUMAN",
      "FREE PEOPLE", "CREW"});

    return ws;
  }

  WarScroll Hellstorm_Rocket_Battery(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(4, 4, 10, 4);

    ws.addWeapon(WarScroll::Weapon("Volley of Shots", 36, 3, 5, 3, 2, 6));
    ws.addWeapon(WarScroll::Weapon("Crew's Tools", 1, 3, 5, 5, 0, 1));

    ws.addAbility(WarScroll::Ability("Crewed Artillery", 1));
    ws.addAbility(WarScroll::Ability("Arcing Ordanance", 1));
    ws.addAbility(WarScroll::Ability("Rocket Salvo", 2));
    ws.addAbility(WarScroll::Ability("I Meant to Hit That One, Honest", 2)); // HUMAN ENGINEER

    ws.addKeyWords({"ORDER", "WAR MACHINE", "HELLSTORM ROCKET BATTERY",
      "HUMAN", "FREE PEOPLE", "CREW"});

    return ws;
  }

  WarScroll Empire_Steam_Tank(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(12, 12, 8, 3);

    ws.addWeapon(WarScroll::Weapon("Crushing Wheels and Ironclad bulk",
      1, 6, 4, 3, 1, 2));
    ws.addWeapon(WarScroll::Weapon("Commander's Sword or Rod",
      1, 2, 5, 4, 0, 1));
    ws.addWeapon(WarScroll::Weapon("Steam Cannon", 30, 1, 4, 2, 2, 6));
    ws.addWeapon(WarScroll::Weapon("Steam Gun", 8, 12, 4, 2, 0, 1));

    WarScroll::UnitUpgrade repeaterHandGun("Repeater Handgun",
      WarScroll::UnitUpgrade::UnitUpgradeType::eOther, 1);
    repeaterHandGun.addWeapon(WarScroll::Weapon(
      "Repeater Handgun", 14, 3, 4, 3, 1, 1));
    ws.registerUnitUpgrade(repeaterHandGun);

    WarScroll::UnitUpgrade hochlandLongRiffle("Hochland Long Rifle",
      WarScroll::UnitUpgrade::UnitUpgradeType::eOther, 1);
    hochlandLongRiffle.addWeapon(WarScroll::Weapon(
      "Hochland Long Rifle", 30, 1, 3, 3, 1, 2));
    ws.registerUnitUpgrade(hochlandLongRiffle);

    ws.addAbility(WarScroll::Ability("More Pressure", 2));
    ws.addAbility(WarScroll::Ability("Steel Behemoth", 2));
    ws.addAbility(WarScroll::Ability("Bouncing Cannon Balls", 1));
    ws.addAbility(WarScroll::Ability("I'll Fix It", 2));

    ws.addKeyWords({"ORDER", "HUMAN", "FREE PEOPLE", "WAR MACINE",
      "EMPIRE STEAM TANK"});

    return ws;
  }

  WarScroll Volkmar_the_Grim(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(5, 5, 7, 4);

    ws.addWeapon(WarScroll::Weapon("Sigmarite Warhammer", 1, 2, 4, 4, 0, 1));
    ws.addWeapon(WarScroll::Weapon("The Staff of Command", 2, 4, 4, 3, 1, 1));

    ws.addAbility(WarScroll::Ability("Grand Theogonist", 2));
    ws.addAbility(WarScroll::Ability("The Jade Griffon", 2));
    ws.addAbility(WarScroll::Ability("Battle Prayers", 2));

    ws.addKeyWords({"ORDER", "HUMAN", "CELESTIAL", "FREE PEOPLE", "HERO",
      "PRIEST", "VOLKMAR THE GRIM"});

    return ws;
  }

  WarScroll The_War_Alter_of_Sigmar(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(10, 11, 7, 4);

    ws.addWeapon(WarScroll::Weapon("Warhorses' Steel-shod Hooves",
      1, 4, 4, 4, 0, 1));
    ws.addWeapon(WarScroll::Weapon("Light of Banishment",
      20, 3, 3, 2, 1, 3));
    ws.addWeapon(WarScroll::Weapon("Sigmarite Greathammer",
      1, 2, 4, 3, 1, 1));

    WarScroll::MountUpgrade volkmarTheGrim("Volkmar the Grim");
    volkmarTheGrim.addWeapon(WarScroll::Weapon("Sigmarite Warhammer",
      1, 2, 4, 4, 0, 1));
    volkmarTheGrim.addWeapon(WarScroll::Weapon("The Staff of Command",
      2, 4, 4, 3, 1, 1));
    volkmarTheGrim.addRiderWeaponToReplace(WarScroll::Weapon(
      "Sigmarite Greathammer", 1, 2, 4, 3, 1, 1));
    ws.registerMountUpgrade(volkmarTheGrim);

    ws.addAbility(WarScroll::Ability("Divine Power", 2));
    ws.addAbility(WarScroll::Ability("The Horn of Sigismund", 2));
    ws.addAbility(WarScroll::Ability("Sigmar's Shield", 2));
    ws.addAbility(WarScroll::Ability("The Power of Faith", 3));
    ws.addAbility(WarScroll::Ability("Light of Banishment", 3));
    ws.addAbility(WarScroll::Ability("Battle Prayers", 2));
    ws.addAbility(WarScroll::Ability("The Jade Griffon", 3));

    ws.addKeyWords({"ORDER", "HUMAN", "CELESTIAL", "FREE PEOPLE", "TOTEM",
      "HERO", "PRIEST", "WAR ALTAR OF SIGMAR", "VOLKMAR THE GRIM"});

    return ws;
  }

  WarScroll Luthor_Huss_Prophet_of_Sigmar(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(10, 5, 7, 4);

    ws.addWeapon(WarScroll::Weapon("Sigmarite Greathammer",
      1, 2, 4, 3, 1, 1));
    ws.addWeapon(WarScroll::Weapon("Warhorse's Steel-shod Hooves",
      1, 2, 4, 4, 0, 1));

    ws.addAbility(WarScroll::Ability("Divine Power", 1));
    ws.addAbility(WarScroll::Ability("Prophet of Sigmar", 1));
    ws.addAbility(WarScroll::Ability("Battle Prayers", 2));

    ws.addKeyWords({"ORDER", "HUMAN", "CELESTIAL", "FREE PEOPLE",
      "HERO", "PRIEST", "LUTHOR HUSS"});

    return ws;
  }

  WarScroll Warrior_Priest(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(5, 5, 7, 4);

    WarScroll::WeaponUpgrade warhammerShield(
      WarScroll::Weapon("Sigmarite Warhammer", 1, 4, 4, 4, 0, 1),
      WarScroll::Ability("Sigmarite Shield", 2));
    warhammerShield.registerCharacteristicToIncrease("Save", -1);
    ws.addWeaponUpgrade(warhammerShield);
    WarScroll::WeaponUpgrade greatHammer(
      WarScroll::Weapon("Sigmarite Greathammer", 1, 2, 4, 3, 1, 1),
      WarScroll::Ability());
    ws.addWeaponUpgrade(greatHammer);
    WarScroll::WeaponUpgrade dualWarhammer(
      WarScroll::Weapon("Sigmarite Warhammer", 1, 4, 4, 4, 0, 1),
      WarScroll::Ability("Sigmarite Warhammers", 1));
    ws.addWeaponUpgrade(dualWarhammer);

    ws.addAbility(WarScroll::Ability("Divine Power", 1));
    ws.addAbility(WarScroll::Ability("Battle Prayers", 2));

    ws.addKeyWords({"ORDER", "HUMAN", "CELESTIAL", "FREE PEOPLE", "HERO",
      "PRIEST", "WARRIOR PRIEST"});

    return ws;
  }

  WarScroll Witch_Hunter(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(5, 5, 7, 5);

    ws.addWeapon(WarScroll::Weapon("Baroque Pistol", 9, 1, 3, 3, 1, 1));

    WarScroll::WeaponUpgrade dualPistolRapier(
      WarScroll::Weapon("Baroque Pistol", 9, 2, 3, 3, 1, 1),
      WarScroll::Ability("Baroque Pistols", 1));
    dualPistolRapier.registerWeaponToReplace(WarScroll::Weapon(
      "Baroque Pistol", 9, 1, 3, 3, 1, 1));
    ws.addWeaponUpgrade(dualPistolRapier);
    WarScroll::WeaponUpgrade silverGreatsword(
      WarScroll::Weapon("Silver Greatsword", 1, 3, 3, 3, 1, 1),
      WarScroll::Ability());
    ws.addWeaponUpgrade(silverGreatsword);

    ws.addAbility(WarScroll::Ability("Grim Resolve", 2));
    ws.addAbility(WarScroll::Ability("Sigmar's Judgement", 1));

    ws.addKeyWords({"ORDER", "HUMAN", "CELESTIAL", "FREE PEOPLE", "HERO",
      "WITCH HUNTER"});

    return ws;
  }

  WarScroll Empire_Flagellants_Warband(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(6, 1, 8, 7);

    ws.addWeapon(WarScroll::Weapon("Castigating Flails and Clubs",
      1, 2, 5, 4, 0, 1));

    ws.setMinMaxUnitCount(10, IFaction::s_MaxUnitSize);

    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Prophet of Doom",
      WarScroll::UnitUpgrade::UnitUpgradeType::eChampion, 1));

    ws.addAbility(WarScroll::Ability("Glorious Martyrs", 2));
    ws.addAbility(WarScroll::Ability("Fanatical Fury", 1));
    ws.addAbility(WarScroll::Ability("Reckless Abondon", 1));

    ws.addKeyWords({"ORDER", "HUMAN", "CELESTIAL", "FREE PEOPLE",
      "FLAGELLANTS"});

    return ws;
  }

  WarScroll Celestial_Hurricanum(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(10, 11, 6, 4);

    ws.addWeapon(WarScroll::Weapon("Storm of Shemtek", 18, 6, 6, 1, 0, 1));
    ws.addWeapon(WarScroll::Weapon("Acolytes' Arcane Tools", 1, 4, 5, 5, 0, 1));
    ws.addWeapon(WarScroll::Weapon("Warhorses' Steel-shod Hooves",
      1, 4, 4, 4, 0, 1));

    WarScroll::MountUpgrade celestialWizard("Celestial Wizard");
    celestialWizard.addWeapon(WarScroll::Weapon("Wizard's Staff",
      2, 1, 4, 3, 1, 3));
    WarScroll::Spell comet("Comet of Casandora");
    comet.setPointCost(2);
    comet.setToCast(6);
    celestialWizard.addSpell(comet);
    ws.registerMountUpgrade(celestialWizard);

    ws.addAbility(WarScroll::Ability("Locus of Azyr", 2));
    ws.addAbility(WarScroll::Ability("Portents of Battle", 2));
    ws.addAbility(WarScroll::Ability("Storm of Shemtek", 2));

    ws.addKeyWords({"ORDER", "HUMAN", "CELESTIAL", "FREE PEOPLE", "WAR MACHINE", 
      "CELESTIAL HURRICANUM", "HERO", "WIZARD"});

    return ws;
  }

  WarScroll Empire_Battle_Wizard(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(5, 5, 6, 6);

    ws.addWeapon(WarScroll::Weapon("Wizard's Staff", 2, 1, 4, 3, 1, 3));
   
    WarScroll::MountUpgrade horse("Horse");
    horse.registerCharacteristicToIncrease("Move", 7);
    horse.addWeapon(WarScroll::Weapon("Horse's Stamping Hooves",
      1, 2, 4, 5, 0, 1));
    ws.registerMountUpgrade(horse);

    {
      WarScroll::Spell spell("Chain Lightning");
      spell.setPointCost(2);
      spell.setToCast(6);
      ws.registerMagicalSpecialization(WarScroll::MagicalSpecialization(
        "Heavens", spell));
    }
    {
      WarScroll::Spell spell("Fireball");
      spell.setPointCost(2);
      spell.setToCast(5);
      ws.registerMagicalSpecialization(WarScroll::MagicalSpecialization(
        "Bright", spell));
    }
    {
      WarScroll::Spell spell("Soul Steal");
      spell.setPointCost(2);
      spell.setToCast(5);
      ws.registerMagicalSpecialization(WarScroll::MagicalSpecialization(
        "Amethyst", spell));
    }
    {
      WarScroll::Spell spell("Light of Battle");
      spell.setPointCost(2);
      spell.setToCast(4);
      ws.registerMagicalSpecialization(WarScroll::MagicalSpecialization(
        "White", spell));
    }
    {
      WarScroll::Spell spell("Final Transmutation");
      spell.setPointCost(2);
      spell.setToCast(6);
      ws.registerMagicalSpecialization(WarScroll::MagicalSpecialization(
        "Gold", spell));
    }
    {
      WarScroll::Spell spell("Mystifying Miasma");
      spell.setPointCost(2);
      spell.setToCast(6);
      ws.registerMagicalSpecialization(WarScroll::MagicalSpecialization(
        "Grey", spell));
    }
    {
      WarScroll::Spell spell("Wildform");
      spell.setPointCost(2);
      spell.setToCast(6);
      ws.registerMagicalSpecialization(WarScroll::MagicalSpecialization(
        "Amber", spell));
    }
    {
      WarScroll::Spell spell("Lifebloom");
      spell.setPointCost(2);
      spell.setToCast(5);
      ws.registerMagicalSpecialization(WarScroll::MagicalSpecialization(
        "Jade", spell));
    }

    ws.addKeyWords({"ORDER", "HUMAN", "FREE PEOPLE", "HERO", "WIZARD",
      "EMPIRE BATTLE WIZARD"});

    return ws;
  }

  WarScroll Amber_Battle_Wizard_on_Imperial_Griffon(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(15, 13, 6, 5);

    ws.addWeapon(WarScroll::Weapon("Beaststaff", 2, 1, 4, 3, 1, 3));
    ws.addWeapon(WarScroll::Weapon("Imperial Griffon's Twin Beaks",
      2, 4, 3, 3, 1, 3));
    ws.addWeapon(WarScroll::Weapon("Imperial Griffon's Razor Claws",
      2, 6, 4, 3, 1, 2));

    ws.setCanFly(true);

    ws.addAbility(WarScroll::Ability("Amber Wizard", 1));
    ws.addAbility(WarScroll::Ability("Two Headed", 1));

    ws.addSpell(WarScroll::Spell("Amber Spear"), 7, 1);

    ws.addKeyWords({"ORDER", "HUMAN", "GRIFFON", "FREE PEOPLE", "MONSTER",
      "HERO", "WIZARD", "AMBER WIZARD"});

    return ws;
  }

  WarScroll Luminark_of_Hysh(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(10, 11, 6, 4);

    ws.addWeapon(WarScroll::Weapon("Searing Beam of Light", 30, 1, 3, 3, 2, 6));
    ws.addWeapon(WarScroll::Weapon("Acolytes' Arcane Tools", 1, 4, 5, 5, 0, 1));
    ws.addWeapon(WarScroll::Weapon("Warhorses' Steel-shod Hooves",
      1, 4, 4, 4, 0, 1));

    WarScroll::MountUpgrade celestialWizard("White Wizard");
    celestialWizard.addWeapon(WarScroll::Weapon("Wizard's Staff",
      2, 1, 4, 3, 1, 3));
    WarScroll::Spell burningGaze("Burning Gaze");
    burningGaze.setPointCost(2);
    burningGaze.setToCast(6);
    celestialWizard.addSpell(burningGaze);
    ws.registerMountUpgrade(celestialWizard);

    ws.addAbility(WarScroll::Ability("Locus of Hysh", 2));
    ws.addAbility(WarScroll::Ability("Aura of Protection", 2));

    ws.addKeyWords({"ORDER", "HUMAN", "LIGHT", "FREE PEOPLE", "WAR MACHINE",
      "LUMINARK OF HYSH", "HERO", "WIZARD"});

    return ws;
  }
}

TheEmpireFaction::TheEmpireFaction() :
  IFaction()
{
  m_Units.push_back("");
  m_Units.push_back("Karl Franz on Deathclaw");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Karl_Franz_on_Deathclaw, m_Units.back())));
  m_Units.push_back("Kurt Helborg");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Kurt_Helborg, m_Units.back())));
  m_Units.push_back("Balthasar Gelt, the Supreme Patriarch");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Balthasar_Gelt_the_Supreme_Patriarch,
    m_Units.back())));
  m_Units.push_back("Valten");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Valten, m_Units.back())));
  m_Units.push_back("Marius Leitdorf");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Marius_Leitdorf, m_Units.back())));
  m_Units.push_back("Empire General");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Empire_General, m_Units.back())));
  m_Units.push_back("General of the Empire on Imperial Griffon");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::General_of_the_Empire_on_Imperial_Griffon,
    m_Units.back())));
  m_Units.push_back("Ludwig Schwarzhelm");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Ludwig_Schwarzhelm, m_Units.back())));
  m_Units.push_back("Markus Wulfhart");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Markus_Wulfhart, m_Units.back())));
  m_Units.push_back("Grand Master");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Grand_Master, m_Units.back())));
  m_Units.push_back("Demigryph Knights");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Demigryph_Knights, m_Units.back())));
  m_Units.push_back("Empire Knights");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Empire_Knights, m_Units.back())));
  m_Units.push_back("Reiksguard Knights");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Reiksguard_Knights, m_Units.back())));
  m_Units.push_back("Empire Crossbowmen");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Empire_Crossbowmen, m_Units.back())));
  m_Units.push_back("Empire Handgunners");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Empire_Handgunners, m_Units.back())));
  m_Units.push_back("Empire Archers");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Empire_Archers, m_Units.back())));
  m_Units.push_back("Empire Greatswords");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Empire_Greatswords, m_Units.back())));
  m_Units.push_back("Empire Pistoliers");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Empire_Pistoliers, m_Units.back())));
  m_Units.push_back("Empire Outriders");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Empire_Outriders, m_Units.back())));
  m_Units.push_back("Empire State Troops");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Empire_State_Troops, m_Units.back())));
  m_Units.push_back("Empire Free Company Militia");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Empire_Free_Company_Militia,
    m_Units.back())));
  m_Units.push_back("Empire Master Engineer");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Empire_Master_Engineer, m_Units.back())));
  m_Units.push_back("Master Engineer on Mechanical Steed");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Master_Engineer_on_Mechanical_Steed,
    m_Units.back())));
  m_Units.push_back("Empire Cannon");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Empire_Cannon, m_Units.back())));
  m_Units.push_back("Empire Mortor");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Empire_Mortor, m_Units.back())));
  m_Units.push_back("Hellblaster Volley Gun");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Hellblaster_Volley_Gun, m_Units.back())));
  m_Units.push_back("Hellstorm Rocket Battery");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Hellstorm_Rocket_Battery, m_Units.back())));
  m_Units.push_back("Empire Steam Tank");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Empire_Steam_Tank, m_Units.back())));
  m_Units.push_back("Volkmar the Grim");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Volkmar_the_Grim, m_Units.back())));
  m_Units.push_back("The War Alter of Sigmar");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::The_War_Alter_of_Sigmar, m_Units.back())));
  m_Units.push_back("Luthor Huss, Prophet of Sigmar");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Luthor_Huss_Prophet_of_Sigmar,
    m_Units.back())));
  m_Units.push_back("Warrior Priest");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Warrior_Priest, m_Units.back())));
  m_Units.push_back("Witch Hunter");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Witch_Hunter, m_Units.back())));
  m_Units.push_back("Empire Flagellants Warband");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Empire_Flagellants_Warband,
    m_Units.back())));
  m_Units.push_back("Celestial Hurricanum");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Celestial_Hurricanum, m_Units.back())));
  m_Units.push_back("Empire Battle Wizard");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Empire_Battle_Wizard, m_Units.back())));
  m_Units.push_back("Amber Battle Wizard on Imperial Griffon");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Amber_Battle_Wizard_on_Imperial_Griffon,
    m_Units.back())));
  m_Units.push_back("Luminark of Hysh");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Luminark_of_Hysh, m_Units.back())));

  std::sort(m_Units.begin(), m_Units.end());
}

const std::vector<std::string> &TheEmpireFaction::getUnits() const
{
  return m_Units;
}

void TheEmpireFaction::getWarScrolls(std::list<WarScroll>& warScrolls)
{
  for (const std::string &unit : m_Units) {
    if (unit.empty()) {
      continue;
    }
    WarScroll ws = m_NameToWarScroll[unit](unit);
    warScrolls.push_back(ws);
  }
}
