#include "orcsandgoblinsfaction.h"

namespace WarScrollGeneration
{
  WarScroll Gorbad_Ironclaw(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(9, 7, 8, 4);

    ws.addWeapon(WarScroll::Weapon("Morglor the Mangler", 1, 5, 3, 3, 2, 3));
    ws.addWeapon(WarScroll::Weapon("Gnarla's Giant Tusks", 1, 2, 4, 3, 0, 1));

    ws.addAbility(WarScroll::Ability("Greenskinz are da Best", 1));
    ws.addAbility(WarScroll::Ability("Da Great Leader", 2));

    ws.addKeyWords({"DESTRUCTION", "ORRUK", "GREENSKINZ", "HERO",
      "ORC WARBOSS", "GORBAD IRONCLAW"});

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eDestruction);
    return ws;
  }

  WarScroll Azhag_the_Slaughterer(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(12, 12, 8, 4);

    ws.addWeapon(WarScroll::Weapon("Slagga's Slashas", 1, 6, 3, 3, 1, 1));
    ws.addWeapon(WarScroll::Weapon("Skullmuncha's Horns, Claws and Teeth",
      2, 6, 4, 3, 1, 2));
    ws.addWeapon(WarScroll::Weapon("Skullmuncha's Barbed, Venomous Tail",
      3, 2, 4, 2, 1, 3));

    ws.setCanFly(true);

    ws.addAbility(WarScroll::Ability("Agonising Venom", 2));
    ws.addAbility(WarScroll::Ability("Slagga's Slashas", 2));
    ws.addAbility(WarScroll::Ability("Get on Wiv It!", 3, true));

    ws.addSpell(WarScroll::Spell("Life Drain"), 5, 1);

    ws.addKeyWords({"DESTRUCTION", "ORRUK", "WYVERN", "GREENSKINZ", "MONSTER",
      "HERO", "WIZARD", "ORC WARBOSS", "AZHAG THE SLAUGHTERER"});

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eDestruction);
    return ws;
  }

  WarScroll Orc_Warboss(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(5, 6, 7, 4);

    {
      WarScroll::WeaponUpgrade upgrade(
        WarScroll::Weapon("Boss Choppa", 1, 6, 3, 3, 1, 1),
        WarScroll::Ability("Boss Shield", 1));
      ws.addWeaponUpgrade(upgrade);
    }
    {
      WarScroll::WeaponUpgrade upgrade(
        WarScroll::Weapon("Boss Choppa", 1, 8, 3, 3, 1, 1),
        WarScroll::Ability("Choppa Boss", 1));
      ws.addWeaponUpgrade(upgrade);
    }
    {
      WarScroll::WeaponUpgrade upgrade(
        WarScroll::Weapon("Massive Choppa", 1, 3, 4, 3, 2, 3),
        WarScroll::Ability());
      ws.addWeaponUpgrade(upgrade);
    }
    {
      WarScroll::WeaponUpgrade upgrade(
        WarScroll::Weapon("Great Waaagh! Banner", 2, 4, 4, 4, 0, 1),
        WarScroll::Ability("Great Waaagh! Banner", 3));
      ws.addWeaponUpgrade(upgrade);
    }

    WarScroll::UnitUpgrade mount("War Boar",
      WarScroll::UnitUpgrade::UnitUpgradeType::eMount, 2);
    mount.registerCharacteristicToIncrease("Move", 4);
    mount.addWeapon(WarScroll::Weapon("War Boar's Tusks", 1, 2, 4, 4, 0, 1));
    ws.registerUnitUpgrade(mount);

    ws.addAbility(WarScroll::Ability("Waaagh!", 2, true));

    ws.addKeyWords({"DESTRUCTION", "ORRUK", "GREENSKINZ", "HERO",
      "ORC WARBOSS"});

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eDestruction);

    return ws;
  }

  WarScroll Orc_Warboss_on_Wyvern(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(12, 10, 7, 4);

    ws.addWeapon(WarScroll::Weapon("Boss Choppa", 1, 6, 3, 3, 1, 1));
    ws.addWeapon(WarScroll::Weapon("Wyvern's Horns, Claws and Teeth",
      2, 5, 4, 3, 1, 2));
    ws.addWeapon(WarScroll::Weapon("Wyvern's Barbed, Venomous Tail",
      3, 2, 4, 2, 1, 3));

    ws.setCanFly(true);

    ws.addAbility(WarScroll::Ability("Agonising Venom", 2));
    ws.addAbility(WarScroll::Ability("Boss Shield", 1));
    ws.addAbility(WarScroll::Ability("Waaagh!", 2, true));

    ws.addKeyWords({"DESTRUCTION", "ORRUK", "WYVERN", "GREENSKINZ", "MONSTER",
      "HERO", "ORC WARBOSS"});

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eDestruction);
    return ws;
  }

  WarScroll Orc_Great_Shaman(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(5, 4, 6, 5);

    ws.addWeapon(WarScroll::Weapon("Totemic Staff", 2, 1, 4, 3, 0, 3));

    WarScroll::UnitUpgrade mount("War Boar",
      WarScroll::UnitUpgrade::UnitUpgradeType::eMount, 2);
    mount.registerCharacteristicToIncrease("Move", 4);
    mount.addWeapon(WarScroll::Weapon("War Boar's Tusks", 1, 2, 4, 4, 0, 1));
    ws.registerUnitUpgrade(mount);

    ws.addAbility(WarScroll::Ability("Waaagh!", 2, true));

    ws.addSpell(WarScroll::Spell("Gaze of Mork"), 6, 2);

    ws.addKeyWords({"DESTRUCTION", "ORRUK", "GREENSKINZ", "HERO", "WIZARD",
      "ORC GREAT SHAMAN"});

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eDestruction);
    return ws;
  }

  WarScroll Orc_Bully(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(5, 4, 6, 5);

    ws.addWeapon(WarScroll::Weapon("Bully's Whip", 2, 2, 4, 4, 0, 1));

    ws.addAbility(WarScroll::Ability("Get Back to Work, Maggots", 1));

    ws.addKeyWords({"DESTRUCTION", "ORRUK", "GREENSKINZ", "HERO", "ORC BULLY"});

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eDestruction);
    return ws;
  }

  WarScroll Orcs(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(5, 1, 5, 5);

    ws.setMinMaxUnitCount(10, IFaction::s_MaxUnitSize);

    ws.addWeaponUpgrade(WarScroll::WeaponUpgrade(
      WarScroll::Weapon("Choppa", 1, 1, 4, 4, 1, 1),
      WarScroll::Ability("Waaagh! Shield", 2)));
    ws.addWeaponUpgrade(WarScroll::WeaponUpgrade(
      WarScroll::Weapon("Pikstikka Spear", 2, 1, 4, 4, 0, 1),
      WarScroll::Ability("Waaagh! Shield", 2)));
    ws.addWeaponUpgrade(WarScroll::WeaponUpgrade(
      WarScroll::Weapon("Choppa", 1, 1, 4, 4, 1, 1),
      WarScroll::Ability("Choppas", 2)));

    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Orc Boss",
      WarScroll::UnitUpgrade::UnitUpgradeType::eChampion, 1));
    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Waaagh! Drummer",
      WarScroll::UnitUpgrade::UnitUpgradeType::eMusician, 1));
    {
      WarScroll::UnitUpgrade upgrade("Orc Banner",
        WarScroll::UnitUpgrade::UnitUpgradeType::eBannerBearer, 1);
      upgrade.addAbility(WarScroll::Ability("Orc Banner", 1));
      ws.registerUnitUpgrade(upgrade);
    }
    {
      WarScroll::UnitUpgrade upgrade("Skull Icon",
        WarScroll::UnitUpgrade::UnitUpgradeType::eBannerBearer, 1);
      upgrade.addAbility(WarScroll::Ability("Skull Icon", 1));
      ws.registerUnitUpgrade(upgrade);
    }

    ws.addAbility(WarScroll::Ability("Mob Rule", 2));

    ws.addKeyWords({"DESTRUCTION", "ORRUK", "GREENSKINZ", "ORCS"});

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eDestruction);
    return ws;
  }

  WarScroll Orc_Arrer_Boyz(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(5, 1, 5, 5);

    ws.addWeapon(WarScroll::Weapon("Orc Bow", 18, 1, 5, 4, 0, 1));
    ws.addWeapon(WarScroll::Weapon("Cutta", 1, 1, 4, 5, 0, 1));

    ws.setMinMaxUnitCount(3, IFaction::s_MaxUnitSize);

    ws.addAbility(WarScroll::Ability("Ready Boyz! Aim! Fire!", 1));

    ws.addKeyWords({"DESTRUCTION", "ORRUK", "GREENSKINZ", "ORC ARRER BOYZ"});

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eDestruction);
    return ws;
  }

  WarScroll Orc_Boar_Boyz(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(9, 2, 5, 5);

    ws.addWeapon(WarScroll::Weapon("War Boar's Tusks", 1, 2, 4, 4, 0, 1));

    ws.addWeaponUpgrade(WarScroll::WeaponUpgrade(
      WarScroll::Weapon("Pigstikka Spear", 2, 1, 4, 4, 0, 1),
      WarScroll::Ability("Tusker Shield", 1)));
    ws.addWeaponUpgrade(WarScroll::WeaponUpgrade(
      WarScroll::Weapon("Choppa", 1, 1, 4, 4, 1, 1),
      WarScroll::Ability("Tusker Shield", 1)));

    ws.setMinMaxUnitCount(5, IFaction::s_MaxUnitSize);

    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Orc Boar Boy Boss",
      WarScroll::UnitUpgrade::UnitUpgradeType::eChampion, 1));
    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Glyph Bearer",
      WarScroll::UnitUpgrade::UnitUpgradeType::eBannerBearer, 2));
    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Waaagh! Horns",
      WarScroll::UnitUpgrade::UnitUpgradeType::eMusician, 1));

    ws.addAbility(WarScroll::Ability("Tusker Charge", 1));

    ws.addKeyWords({"DESTRUCTION", "ORRUK", "GREENSKINZ", "ORC BOAR BOYS"});

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eDestruction);
    return ws;
  }

  WarScroll Orc_Boar_Chariots(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(9, 6, 6, 4);

    ws.addWeapon(WarScroll::Weapon("Crew's Pigstikka Spears",
      2, 2, 4, 4, 0, 1));
    ws.addWeapon(WarScroll::Weapon("War Boars' Tusks",
      1, 4, 4, 4, 0, 1));

    ws.addAbility(WarScroll::Ability("Scythed Wheels", 2));
    ws.addAbility(WarScroll::Ability("Tusker Charge", 1));

    ws.addKeyWords({"DESTRUCTION", "ORRUK", "GREENSKINZ", "ORC BOAR CHARIOTS"});

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eDestruction);
    return ws;
  }

  WarScroll Ruglud_s_Armoureed_Orcs(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(5, 1, 5, 4);

    ws.addWeapon(WarScroll::Weapon("Orc Crossbow", 12, 1, 5, 3, 0, 1));
    ws.addWeapon(WarScroll::Weapon("Cutta", 1, 1, 4, 5, 0, 1));

    ws.setMinMaxUnitCount(10, IFaction::s_MaxUnitSize);

    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Ruglud",
      WarScroll::UnitUpgrade::UnitUpgradeType::eChampion, 1));
    WarScroll::ChampionWithOptions ruglud("Ruglud", 1);
    ruglud.addWeapon(WarScroll::Weapon("Cutta", 2, 1, 4, 3, 0, 1));
    ruglud.addWeapon(WarScroll::Weapon("Orc Crossbow", 12, 1, 5, 3, 0, 1));
    ruglud.addAbility(WarScroll::Ability("Shoot'em Again Boyz", 2));
    ws.registerChampionWithOptions(ruglud);
    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Maggot",
      WarScroll::UnitUpgrade::UnitUpgradeType::eBannerBearer, 1));
    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Waaagh! Drummer",
      WarScroll::UnitUpgrade::UnitUpgradeType::eMusician, 1));

    ws.addKeyWords({"DESTRUCTION", "ORRUK", "GREENSKINZ",
      "RUGLUD'S ARMOURED ORCS"});

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eDestruction);
    return ws;
  }

  WarScroll Grimgor_Ironhide(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(5, 7, 9, 4);

    ws.addWeapon(WarScroll::Weapon("Gitsnik", 1, 4, 3, 3, 2, 2));
    ws.addWeapon(WarScroll::Weapon("Almighty 'Eadbutt", 1, 1, 3, 4, 0, 3));

    ws.addAbility(WarScroll::Ability("I'm Da Best", 1));
    ws.addAbility(WarScroll::Ability("Da Immortulz", 1));
    ws.addAbility(WarScroll::Ability("Everyone Fights, or Else!", 2, true));

    ws.addKeyWords({"DESTRUCTION", "ORRUK", "IRONJAW", "HERO",
      "BLACK ORC BIG BOSS", "GRIMGOR IRONHIDE"});

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eDestruction);
    return ws;
  }

  WarScroll Black_Orc_Big_Boss(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(5, 6, 7, 4);

    {
      WarScroll::WeaponUpgrade upgrade(
        WarScroll::Weapon("Deff Choppa", 1, 6, 3, 3, 1, 1),
        WarScroll::Ability("Tusker Shield", 1));
      ws.addWeaponUpgrade(upgrade);
    }
    {
      WarScroll::WeaponUpgrade upgrade(
        WarScroll::Weapon("Deff Choppa", 1, 6, 3, 3, 1, 1),
        WarScroll::Ability("Chop Chop Chop", 1));
      ws.addWeaponUpgrade(upgrade);
    }
    {
      WarScroll::WeaponUpgrade upgrade(
        WarScroll::Weapon("Slaughter-choppa", 1, 3, 3, 3, 2, 3),
        WarScroll::Ability());
      ws.addWeaponUpgrade(upgrade);
    }

    ws.addAbility(WarScroll::Ability("I'm Da Best", 1));
    ws.addAbility(WarScroll::Ability("Keepin' Order", 2, true));

    ws.addKeyWords({"DESTRUCTION", "ORRUK", "IRONJAW", "HERO",
      "BLACK ORC BIG BOSS"});

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eDestruction);
    return ws;
  }

  WarScroll Black_Orcs(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(5, 2, 6, 4);

    ws.addWeapon(WarScroll::Weapon("Array of Kill-choppas", 1, 2, 4, 3, 1, 1));

    ws.setMinMaxUnitCount(5, IFaction::s_MaxUnitSize);

    {
      WarScroll::UnitUpgrade upgrade("Waaagh! Drummer",
        WarScroll::UnitUpgrade::UnitUpgradeType::eMusician, 1);
      ws.registerUnitUpgrade(upgrade);
    }
    {
      WarScroll::UnitUpgrade upgrade("Black Orc Boss",
        WarScroll::UnitUpgrade::UnitUpgradeType::eChampion, 1);
      ws.registerUnitUpgrade(upgrade);
    }
    {
      WarScroll::UnitUpgrade upgrade("Standard Bearer",
        WarScroll::UnitUpgrade::UnitUpgradeType::eBannerBearer);
      ws.registerUnitUpgrade(upgrade);
    }

    ws.addAbility(WarScroll::Ability("Orc Banner", 2));
    ws.addAbility(WarScroll::Ability("Icon of Mork (or possibly Gork)", 2));
    ws.addAbility(WarScroll::Ability("We's da Best", 2));

    ws.addKeyWords({"DESTRUCTION", "ORRUK", "IRONJAW", "BLACK ORCS"});

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eDestruction);
    return ws;
  }

  WarScroll Wurrzag_da_Great_Green_Prophet(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(5, 5, 6, 6);

    ws.addWeapon(WarScroll::Weapon("Baleful Mask", 12, 1, 5, 5, 0, 1));
    ws.addWeapon(WarScroll::Weapon("Bonewood Staff", 2, 2, 4, 3, 0, 3));

    ws.addAbility(WarScroll::Ability("Warpaint", 1));
    ws.addAbility(WarScroll::Ability("Squiggly Beast", 1));

    ws.addSpell(WarScroll::Spell("Wurrzag's Revenge"), 6, 2);

    ws.addKeyWords({"DESTRUCTION", "ORRUK", "BONESPLITTAS", "HERO", "WIZARD",
      "WURRZAG"});

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eDestruction);
    return ws;
  }

  WarScroll Savage_Orc_Warboss(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(5, 6, 7, 5);

    {
      WarScroll::WeaponUpgrade upgrade(
        WarScroll::Weapon("Stonecleava", 2, 4, 4, 3, 2, 3),
        WarScroll::Ability());
      ws.addWeaponUpgrade(upgrade);
    }
    {
      WarScroll::WeaponUpgrade upgrade(
        WarScroll::Weapon("Granite Choppa", 1, 7, 4, 3, 1, 1),
        WarScroll::Ability("Bone Shield", 1));
      ws.addWeaponUpgrade(upgrade);
    }
    {
      WarScroll::WeaponUpgrade upgrade(
        WarScroll::Weapon("Granite Choppa", 1, 7, 4, 3, 1, 1),
        WarScroll::Ability("Granite Choppas", 1));
      ws.addWeaponUpgrade(upgrade);
    }

    {
      WarScroll::MountUpgrade upgrade("War Boar");
      upgrade.addWeapon(WarScroll::Weapon("War Boar's Tusks",
        1, 2, 4, 4, 0, 1));
      upgrade.registerCharacteristicToIncrease("Move", 4);
    }

    ws.addAbility(WarScroll::Ability("Warpaint", 1));
    ws.addAbility(WarScroll::Ability("More Choppin!", 1, true));

    ws.addKeyWords({"DESTURUCTION", "ORRUK", "BONESPLITTAS", "HERO",
      "SAVAGE ORC WARBOSS"});

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eDestruction);
    return ws;
  }

  WarScroll Savage_Orc_Shaman(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(5, 5, 6, 6);

    ws.addWeapon(WarScroll::Weapon("Totemic Bone-staff", 2, 1, 4, 3, 0, 3));

    {
      WarScroll::MountUpgrade upgrade("War Boar");
      upgrade.addWeapon(WarScroll::Weapon("War Boar's Tusks",
        1, 2, 4, 2, 0, 1));
      upgrade.registerCharacteristicToIncrease("Move", 4);
    }

    ws.addAbility(WarScroll::Ability("Waaagh! Energy", 1));
    ws.addAbility(WarScroll::Ability("Warpaint", 1));

    ws.addSpell(WarScroll::Spell("Foot of Gork"), 6, 2);

    ws.addKeyWords({"DESTRUCTION", "ORRUK", "BONESPLITTAS", "HERO", "WIZARD",
      "SAVAGE ORC SHAMAN"});

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eDestruction);
    return ws;
  }

  WarScroll Savage_Orcs(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(5, 1, 5, 6);

    ws.setMinMaxUnitCount(10, IFaction::s_MaxUnitSize);

    {
      WarScroll::WeaponUpgrade upgrade(
        WarScroll::Weapon("Stone Choppa", 1, 1, 4, 4, 1, 1),
        WarScroll::Ability("Crude Shield", 1));
      ws.addWeaponUpgrade(upgrade);
    }
    {
      WarScroll::WeaponUpgrade upgrade(
        WarScroll::Weapon("Flint Spear", 2, 1, 4, 4, 0, 1),
        WarScroll::Ability("Crude Shield", 1));
      ws.addWeaponUpgrade(upgrade);
    }
    {
      WarScroll::WeaponUpgrade upgrade(
        WarScroll::Weapon("Stone Choppa", 1, 1, 4, 4, 1, 1),
        WarScroll::Ability());
      upgrade.setSecondaryWeapon(WarScroll::Weapon("Bone Shiv or Gnarled Fist",
        1, 1, 4, 5, 0, 1));
      ws.addWeaponUpgrade(upgrade);
    }
    {
      WarScroll::WeaponUpgrade upgrade(
        WarScroll::Weapon("Flint Spear", 2, 1, 4, 4, 0, 1),
        WarScroll::Ability());
      upgrade.setSecondaryWeapon(WarScroll::Weapon("Bone Shiv or Gnarled Fist",
        1, 1, 4, 5, 0, 1));
      ws.addWeaponUpgrade(upgrade);
    }
    {
      WarScroll::WeaponUpgrade upgrade(
        WarScroll::Weapon("Feral Bow", 18, 1, 5, 4, 0, 1),
        WarScroll::Ability());
      upgrade.setSecondaryWeapon(WarScroll::Weapon("Stone Choppa",
        1, 1, 4, 4, 1, 1));
      ws.addWeaponUpgrade(upgrade);
    }
    {
      WarScroll::WeaponUpgrade upgrade(
        WarScroll::Weapon("Feral Bow", 18, 1, 5, 4, 0, 1),
        WarScroll::Ability("Lodsa Arrers", 1));
      ws.addWeaponUpgrade(upgrade);
    }
    {
      WarScroll::WeaponUpgrade upgrade(
        WarScroll::Weapon("Feral Bow", 18, 1, 5, 4, 0, 1),
        WarScroll::Ability());
      upgrade.setSecondaryWeapon(WarScroll::Weapon("Bone Shiv or Gnarled Fist",
        1, 1, 4, 5, 0, 1));
      ws.addWeaponUpgrade(upgrade);
    }

    {
      WarScroll::UnitUpgrade upgrade("Big Stabba",
        WarScroll::UnitUpgrade::UnitUpgradeType::eOther, 2);
      upgrade.addAbility(WarScroll::Ability("Big Stabba", 1));
      upgrade.addWeapon(WarScroll::Weapon("Big Stabba", 2, 2, 4, 3, 1, 3));
      upgrade.setEveryNModels(10);
      ws.registerUnitUpgrade(upgrade);
    }
    {
      WarScroll::UnitUpgrade upgrade("Savage Orc Boss",
        WarScroll::UnitUpgrade::UnitUpgradeType::eChampion, 1);
      ws.registerUnitUpgrade(upgrade);
    }
    {
      WarScroll::UnitUpgrade upgrade("Icon Bearer",
        WarScroll::UnitUpgrade::UnitUpgradeType::eBannerBearer, 1);
      ws.registerUnitUpgrade(upgrade);
    }
    {
      WarScroll::UnitUpgrade upgrade("Skull Bashers",
        WarScroll::UnitUpgrade::UnitUpgradeType::eMusician, 1);
      ws.registerUnitUpgrade(upgrade);
    }

    WarScroll::Ability ability("Frenzied Mob", 1);
    ability.setEveryNModels(20);
    ws.addAbility(ability);
    ws.addAbility(WarScroll::Ability("Warpaint", 1));

    ws.addKeyWords({"DESTRUCTION", "ORRUK", "BONESPLITTAS", "SAVAGE ORCS"});

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eDestruction);
    return ws;
  }

  WarScroll Savage_Orc_Boar_Boyz(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(9, 2, 5, 6);

    ws.addWeapon(WarScroll::Weapon("War Boar's Tusks", 1, 2, 4, 4, 0, 1));

    {
      WarScroll::WeaponUpgrade upgrade(
        WarScroll::Weapon("Crude Choppa", 1, 1, 4, 4, 1, 1),
        WarScroll::Ability("Crude Shield", 1));
      ws.addWeaponUpgrade(upgrade);
    }
    {
      WarScroll::WeaponUpgrade upgrade(
        WarScroll::Weapon("Crude Choppa", 1, 1, 4, 4, 1, 1),
        WarScroll::Ability("Crude Choppas", 1));
      ws.addWeaponUpgrade(upgrade);
    }
    {
      WarScroll::WeaponUpgrade upgrade(
        WarScroll::Weapon("Flint Spear", 2, 1, 4, 4, 0, 1),
        WarScroll::Ability("Crude Shield", 1));
      ws.addWeaponUpgrade(upgrade);
    }

    ws.setMinMaxUnitCount(5, IFaction::s_MaxUnitSize);

    {
      WarScroll::UnitUpgrade upgrade("Savage Orc Boar Boy Boss",
        WarScroll::UnitUpgrade::UnitUpgradeType::eChampion, 1);
      ws.registerUnitUpgrade(upgrade);
    }
    {
      WarScroll::UnitUpgrade upgrade("Icon Bearer",
        WarScroll::UnitUpgrade::UnitUpgradeType::eBannerBearer, 1);
      ws.registerUnitUpgrade(upgrade);
    }
    {
      WarScroll::UnitUpgrade upgrade("Tribal Drummer",
        WarScroll::UnitUpgrade::UnitUpgradeType::eMusician, 1);
      ws.registerUnitUpgrade(upgrade);
    }

    ws.addAbility(WarScroll::Ability("Tusker Charge", 1));
    ws.addAbility(WarScroll::Ability("Warpaint", 1));

    ws.addKeyWords({"DESTRUCTION", "ORRUK", "BONESPLITTAS",
      "SAVAGE ORC BOAR BOYZ"});

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eDestruction);
    return ws;
  }

  WarScroll Grom_the_Paunch(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(12, 6, 7, 4);

    ws.addWeapon(WarScroll::Weapon("Axe of Grom", 1, 3, 3, 3, 1, 3));
    ws.addWeapon(WarScroll::Weapon("Niblet's Slasha", 1, 2, 5, 5, 0, 1));
    ws.addWeapon(WarScroll::Weapon("Giant Wolves' Slavering Jaws",
      1, 6, 4, 4, 0, 1));

    ws.addAbility(WarScroll::Ability("Fat on Troll Flesh", 2));
    ws.addAbility(WarScroll::Ability("Da Lucky Banner", 1));
    ws.addAbility(WarScroll::Ability("Grom's Waaagh!", 2 , true));

    ws.addKeyWords({"DESTRUCTION", "GROT", "GITMOB", "HERO", "GOBLIN WARBOSS",
      "GROM THE PAUCH"});

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eDestruction);
    return ws;
  }

  WarScroll Goblin_Warboss(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(5, 4, 6, 5);

    {
      WarScroll::WeaponUpgrade upgrade(
        WarScroll::Weapon("Git-cutta", 1, 5, 3, 4, 0, 1),
        WarScroll::Ability("Git Shield", 1));
      ws.addWeaponUpgrade(upgrade);
    }
    {
      WarScroll::WeaponUpgrade upgrade(
        WarScroll::Weapon("Git-cutta", 1, 5, 3, 4, 0, 1),
        WarScroll::Ability("Git-cuttas", 1));
      ws.addWeaponUpgrade(upgrade);
    }
    {
      WarScroll::WeaponUpgrade upgrade(
        WarScroll::Weapon("Git-slicer", 1, 3, 3, 4, 1, 3),
        WarScroll::Ability());
      ws.addWeaponUpgrade(upgrade);
    }

    {
      WarScroll::MountUpgrade mount("Giant Wolves");
      mount.registerCharacteristicToIncrease("Move", 7);
      mount.addWeapon(WarScroll::Weapon("Giant Wolf's Slavering Jaws",
        1, 2, 4, 4, 0, 1));
    }

    ws.addAbility(WarScroll::Ability("Kunnin' (or just Lucky)", 1));
    ws.addAbility(WarScroll::Ability("Wot I Sez Goes, Now Get 'em!", 2, true));

    ws.addKeyWords({"DESTURCTION", "GROT", "GITMOB", "HERO", "GOBLIN WARBOSS"});

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eDestruction);
    return ws;
  }

  WarScroll Goblin_Shaman(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(5, 4, 5, 6);

    ws.addWeapon(WarScroll::Weapon("Shaman Stick", 2, 1, 5, 4, 1, 3));

    {
      WarScroll::MountUpgrade mount("Giant Wolves");
      mount.registerCharacteristicToIncrease("Move", 7);
      mount.addWeapon(WarScroll::Weapon("Giant Wolf's Slavering Jaws",
        1, 2, 4, 4, 0, 1));
    }

    ws.addAbility(WarScroll::Ability("Kunnin' (or just Lucky)", 1));
    ws.addSpell(WarScroll::Spell("Sneaky Stabbin"), 7, 2);

    ws.addKeyWords({"DESTRUCTION", "GROT", "GITMOB", "HERO", "WIZARD",
      "GOBLIN SHAMAN"});

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eDestruction);
    return ws;
  }

  WarScroll Goblins(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(5, 1, 4, 6);

    ws.setMinMaxUnitCount(10, IFaction::s_MaxUnitSize);

    {
      WarScroll::Ability shield("Gobbo Shields", 1);
      shield.registerCharacteristicToIncreaseIfOverN("Save", -1, 10);
      WarScroll::WeaponUpgrade upgrade(
        WarScroll::Weapon("Jabbin' Spear", 2, 1, 5, 4, 0, 1),
        shield);
    }

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eDestruction);
    return ws;
  }

  WarScroll Goblin_Wolf_Riders(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eDestruction);
    return ws;
  }

  WarScroll Goblin_Wolf_Chariots(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eDestruction);
    return ws;
  }

  WarScroll Goblin_Spear_Chukka(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eDestruction);
    return ws;
  }

  WarScroll Goblin_Rock_Lobber(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eDestruction);
    return ws;
  }

  WarScroll Doom_Diver_Catapult(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eDestruction);
    return ws;
  }

  WarScroll Nasty_Skulkers(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eDestruction);
    return ws;
  }

  WarScroll Skarsnik_Warlord_of_the_Eight_Peaks(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eDestruction);
    return ws;
  }

  WarScroll Night_Goblin_Warboss(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eDestruction);
    return ws;
  }

  WarScroll Night_Goblin_Warboss_on_Great_Cave_Squig(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eDestruction);
    return ws;
  }

  WarScroll Night_Goblin_Shaman(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eDestruction);
    return ws;
  }

  WarScroll Night_Goblins(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eDestruction);
    return ws;
  }

  WarScroll Night_Goblin_Fanatics(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eDestruction);
    return ws;
  }

  WarScroll Night_Goblin_Squig_Hoppers(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eDestruction);
    return ws;
  }

  WarScroll Night_Goblin_Squig_Herders(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eDestruction);
    return ws;
  }

  WarScroll Mangler_Squigs(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eDestruction);
    return ws;
  }

  WarScroll Cave_Squigs(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eDestruction);
    return ws;
  }

  WarScroll Goblin_Big_Boss_on_Gigantic_Spider(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eDestruction);
    return ws;
  }

  WarScroll Forest_Goblin_Spider_Riders(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eDestruction);
    return ws;
  }

  WarScroll Arachnarok_Spider(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eDestruction);
    return ws;
  }

  WarScroll Snotlings(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eDestruction);
    return ws;
  }

  WarScroll Snotling_Pump_Wagon(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eDestruction);
    return ws;
  }

  WarScroll Trolls_in_Orcs_and_Goblins(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eDestruction);
    return ws;
  }

  WarScroll Stone_Troll(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eDestruction);
    return ws;
  }

  WarScroll River_Trolls(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eDestruction);
    return ws;
  }

  WarScroll Giant_in_Orcs_and_Goblins(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eDestruction);
    return ws;
  }
}

OrcsAndGoblinsFaction::OrcsAndGoblinsFaction() :
  IFaction()
{
  m_Units.push_back("");
  m_Units.push_back("Gorbad Ironclaw");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Gorbad_Ironclaw, m_Units.back())));
  m_Units.push_back("Azhag the Slaughterer");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Azhag_the_Slaughterer, m_Units.back())));
  m_Units.push_back("Orc Warboss");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Orc_Warboss, m_Units.back())));
  m_Units.push_back("Orc Warboss on Wyvern");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Orc_Warboss_on_Wyvern, m_Units.back())));
  m_Units.push_back("Orc Great Shaman");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Orc_Great_Shaman, m_Units.back())));
  m_Units.push_back("Orc Bully");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Orc_Bully, m_Units.back())));
  m_Units.push_back("Orcs");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Orcs, m_Units.back())));
  m_Units.push_back("Orc Arrer Boyz");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Orc_Arrer_Boyz, m_Units.back())));
  m_Units.push_back("Orc Boar Boyz");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Orc_Boar_Boyz, m_Units.back())));
  m_Units.push_back("Orc Boar Chariots");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Orc_Boar_Chariots, m_Units.back())));
  m_Units.push_back("Ruglud's Armoureed Orcs");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Ruglud_s_Armoureed_Orcs, m_Units.back())));
  m_Units.push_back("Grimgor Ironhide");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Grimgor_Ironhide, m_Units.back())));
  m_Units.push_back("Black Orc Big Boss");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Black_Orc_Big_Boss, m_Units.back())));
  m_Units.push_back("Black Orcs");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Black_Orcs, m_Units.back())));
  m_Units.push_back("Wurrzag, da Great Green Prophet");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Wurrzag_da_Great_Green_Prophet,
    m_Units.back())));
  m_Units.push_back("Savage Orc Warboss");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Savage_Orc_Warboss, m_Units.back())));
  m_Units.push_back("Savage Orc Shaman");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Savage_Orc_Shaman, m_Units.back())));
  m_Units.push_back("Savage Orcs");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Savage_Orcs, m_Units.back())));
  m_Units.push_back("Savage Orc Boar Boyz");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Savage_Orc_Boar_Boyz, m_Units.back())));
  m_Units.push_back("Grom the Paunch");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Grom_the_Paunch, m_Units.back())));
  m_Units.push_back("Goblin Warboss");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Goblin_Warboss, m_Units.back())));
  m_Units.push_back("Goblin Shaman");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Goblin_Shaman, m_Units.back())));
  m_Units.push_back("Goblins");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Goblins, m_Units.back())));
  m_Units.push_back("Goblin Wolf Riders");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Goblin_Wolf_Riders, m_Units.back())));
  m_Units.push_back("Goblin Wolf Chariots");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Goblin_Wolf_Chariots, m_Units.back())));
  m_Units.push_back("Goblin Spear Chukka");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Goblin_Spear_Chukka, m_Units.back())));
  m_Units.push_back("Goblin Rock Lobber");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Goblin_Rock_Lobber, m_Units.back())));
  m_Units.push_back("Doom Diver Catapult");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Doom_Diver_Catapult, m_Units.back())));
  m_Units.push_back("Nasty Skulkers");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Nasty_Skulkers, m_Units.back())));
  m_Units.push_back("Skarsnik, Warlord of the Eight Peaks");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Skarsnik_Warlord_of_the_Eight_Peaks,
    m_Units.back())));
  m_Units.push_back("Night Goblin Warboss");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Night_Goblin_Warboss, m_Units.back())));
  m_Units.push_back("Night Goblin Warboss on Great Cave Squig");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Night_Goblin_Warboss_on_Great_Cave_Squig,
    m_Units.back())));
  m_Units.push_back("Night Goblin Shaman");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Night_Goblin_Shaman, m_Units.back())));
  m_Units.push_back("Night Goblins");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Night_Goblins, m_Units.back())));
  m_Units.push_back("Night Goblin Fanatics");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Night_Goblin_Fanatics, m_Units.back())));
  m_Units.push_back("Night Goblin Squig Hoppers");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Night_Goblin_Squig_Hoppers,
    m_Units.back())));
  m_Units.push_back("Night Goblin Squig Herders");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Night_Goblin_Squig_Herders,
    m_Units.back())));
  m_Units.push_back("Mangler Squigs");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Mangler_Squigs, m_Units.back())));
  m_Units.push_back("Cave Squigs");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Cave_Squigs, m_Units.back())));
  m_Units.push_back("Goblin Big Boss on Gigantic Spider");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Goblin_Big_Boss_on_Gigantic_Spider,
    m_Units.back())));
  m_Units.push_back("Forest Goblin Spider Riders");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Forest_Goblin_Spider_Riders,
    m_Units.back())));
  m_Units.push_back("Arachnarok Spider");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Arachnarok_Spider, m_Units.back())));
  m_Units.push_back("Snotlings");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Snotlings, m_Units.back())));
  m_Units.push_back("Snotling Pump Wagon");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Snotling_Pump_Wagon, m_Units.back())));
  m_Units.push_back("Trolls");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Trolls_in_Orcs_and_Goblins,
    m_Units.back())));
  m_Units.push_back("Stone Troll");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Stone_Troll, m_Units.back())));
  m_Units.push_back("River Trolls");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::River_Trolls, m_Units.back())));
  m_Units.push_back("Giant");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Giant_in_Orcs_and_Goblins, m_Units.back())));
}

const std::vector<std::string> &OrcsAndGoblinsFaction::getUnits() const
{
  return m_Units;
}

void OrcsAndGoblinsFaction::getWarScrolls(std::list<WarScroll>& warScrolls)
{
  for (const std::string &unit : m_Units) {
    if (unit.empty()) {
      continue;
    }
    WarScroll ws = m_NameToWarScroll[unit](unit);
    warScrolls.push_back(ws);
  }
}
