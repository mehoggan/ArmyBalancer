#include "ogrekingdomsfaction.h"

namespace WarScrollGeneration
{
  WarScroll Greasus_Goldtooth(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(3, 9, 8, 4);

    ws.addWeapon(WarScroll::Weapon("The Sceptre of Titans", 1, 4, 3, 3, 2, 6));

    ws.addAbility(WarScroll::Ability("Too Rich To Walk", 1));
    ws.addAbility(WarScroll::Ability("Overtyrant's Crown", 3));
    ws.addAbility(WarScroll::Ability("Everyone Has Their Price", 3, true));

    ws.addKeyWords({"DESTRUCTION", "OGOR", "GUTBUSTER", "HERO", "TYRANT",
      "GREASUS GOLDTOOTH"});

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eDestruction);

    return ws;
  }

  WarScroll Skrag_the_Slaughterer(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(6, 8, 10, 4);

    ws.addWeapon(WarScroll::Weapon("Stump Blades", 1, 12 ,4, 3, 0, 1));

    ws.addAbility(WarScroll::Ability("Cauldron of the Great Maw", 3));
    ws.addAbility(WarScroll::Ability("Prophet of the Great Maw", 1));

    ws.addKeyWords({"DESTRUCTION", "OGOR", "GUTBUSTER", "HERO", "PRIEST",
      "BUTCHER", "SKRAG THE SLAUGHTERER"});

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eDestruction);

    return ws;
  }

  WarScroll Tyrant(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(6, 8, 8, 4);

    {
      WarScroll::WeaponUpgrade upgrade(
        WarScroll::Weapon("Massive Ogre Club", 2, 4, 3, 3, 2, 3),
        WarScroll::Ability());
      ws.addWeaponUpgrade(upgrade);
    }
    {
      WarScroll::WeaponUpgrade upgrade(
        WarScroll::Weapon("Club, Basher or Slicer", 1, 6, 3, 3, 1, 2),
        WarScroll::Ability("Club'em then Club 'em Again", 1));
      ws.addWeaponUpgrade(upgrade);
    }
    {
      WarScroll::WeaponUpgrade upgrade(
        WarScroll::Weapon("Club, Basher or Slicer", 1, 6, 3, 3, 1, 2),
        WarScroll::Ability()
      );
      upgrade.setSecondaryWeapon(WarScroll::Weapon("Brace of Ogre Pistols",
        12, 2, 4, 3, 1, 3));
      ws.addWeaponUpgrade(upgrade);
    }

    ws.addAbility(WarScroll::Ability("Big Name", 3));
    ws.addAbility(WarScroll::Ability("Bully of the First Degree", 2));

    ws.addKeyWords({"DESTRUCTION", "OGOR", "GUTBUSTER", "HERO", "TYRANT"});

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eDestruction);

    return ws;
  }

  WarScroll Bragg_the_Gutsman(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(6, 7, 7, 5);

    ws.addWeapon(WarScroll::Weapon("Great Gutgouger", 3, 3, 4, 3, 1, 3));

    ws.addAbility(WarScroll::Ability("Gutgouger", 1));
    ws.addAbility(WarScroll::Ability("Slayer of Champions", 1));
    ws.addAbility(WarScroll::Ability("The Gutsman", 1));

    ws.addKeyWords({"DESTRUCTION", "OGOR", "GUTBUSTER", "HERO",
      "BRAGG THE GUTSMAN"});

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eDestruction);

    return ws;
  }

  WarScroll Bruiser_Standard_Bearer(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(6, 7, 7, 4);

    ws.addWeapon(WarScroll::Weapon("Bruiser's Club or Blade",
      1, 4, 3, 3, 1, 2));

    WarScroll::UnitUpgrade pistol("Ogre Pistol",
      WarScroll::UnitUpgrade::UnitUpgradeType::eChampion, 1);
    pistol.addWeapon(WarScroll::Weapon("Ogre Pistol", 12 , 1, 4, 3, 1, 3));
    ws.registerUnitUpgrade(pistol);

    ws.addAbility(WarScroll::Ability("Muscle-bound Bully", 1));
    ws.addAbility(WarScroll::Ability("Banner of the Great Maw", 2));

    ws.addKeyWords({"DESTRUCTION", "OGOR", "GUTBUSTER", "HERO", "TOTEM",
      "BRUISER STANDARD BEARER"});

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eDestruction);

    return ws;
  }

  WarScroll Butcher(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(6, 7, 8, 5);

    ws.addWeapon(WarScroll::Weapon("Butcher's Cleaver or Tenderiser",
      1, 2, 4, 3, 1, 3));

    ws.addAbility(WarScroll::Ability("Bloodgruel", 3));

    ws.addSpell(WarScroll::Spell("The Maw"), 7, 3);

    ws.addKeyWords({"DESTRUCTION", "OGOR", "GUTBUSTER", "HERO", "WIZARD",});

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eDestruction);

    return ws;
  }

  WarScroll Ogres(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(6, 4, 6, 5);

    {
      ws.addWeaponUpgrade(WarScroll::WeaponUpgrade(
        WarScroll::Weapon("Ogre Clubs and Blades", 1, 3, 4, 3, 0, 2),
        WarScroll::Ability("Iron Fists", 1)));
    }
    {
      ws.addWeaponUpgrade(WarScroll::WeaponUpgrade(
        WarScroll::Weapon("Ogre Clubs and Blades", 1, 3, 4, 3, 0, 2),
        WarScroll::Ability("Ogre Clubs and Blades", 1)));
    }

    ws.setMinMaxUnitCount(3, IFaction::s_MaxUnitSize);

    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Crusher",
      WarScroll::UnitUpgrade::UnitUpgradeType::eChampion, 1));
    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Bellower",
      WarScroll::UnitUpgrade::UnitUpgradeType::eMusician, 1));
    WarScroll::UnitUpgrade banner("Icon Bearer",
      WarScroll::UnitUpgrade::UnitUpgradeType::eBannerBearer, 1);
    banner.addAbility(WarScroll::Ability("Tribal Banner", 1));
    ws.registerUnitUpgrade(banner);

    ws.addAbility(WarScroll::Ability("Bull Charge", 1));
    ws.addAbility(WarScroll::Ability("Great Beast Skull", 1));
    ws.addAbility(WarScroll::Ability("Look Out Gnoblar", 1));

    ws.addKeyWords({"DESTRUCTION", "OGOR", "GUTBUSTER", "OGRES"});

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eDestruction);

    return ws;
  }

  WarScroll Ironguts(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(6, 4, 7, 4);

    ws.addWeapon(WarScroll::Weapon("Might Bashing Weapon", 2, 3, 4, 3, 1, 3));

    ws.setMinMaxUnitCount(3, IFaction::s_MaxUnitSize);

    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Gutlord",
      WarScroll::UnitUpgrade::UnitUpgradeType::eChampion, 1));
    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Bellower",
      WarScroll::UnitUpgrade::UnitUpgradeType::eMusician, 1));
    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Rune Maw Bearer",
      WarScroll::UnitUpgrade::UnitUpgradeType::eBannerBearer, 1));

    ws.addAbility(WarScroll::Ability("Down to the Ironguts", 1));

    ws.addKeyWords({"DESTRUCTION", "OGOR", "GUTBUSTER", "IRONGUTS"});

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eDestruction);

    return ws;
  }

  WarScroll Leadbelchers(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(6, 4, 6, 5);

    ws.addWeapon(WarScroll::Weapon("Leadbelcher Gun", 12, 3, 4, 3, 1, 1));
    ws.addWeapon(WarScroll::Weapon("Leadbelcher Gun", 1, 2, 4, 3, 1, 2));

    ws.setMinMaxUnitCount(3, IFaction::s_MaxUnitSize);

    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Thunderfist",
      WarScroll::UnitUpgrade::UnitUpgradeType::eChampion, 1));
    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Bellower",
      WarScroll::UnitUpgrade::UnitUpgradeType::eMusician, 1));

    ws.addAbility(WarScroll::Ability("Thunderous Blasts of Hot Metal", 2));

    ws.addKeyWords({"DESTRUCTION", "OGOR", "GUTBUSTER", "LEADBELCHERS"});

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eDestruction);

    return ws;
  }

  WarScroll Gorgers(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(6, 5, 8, 6);

    ws.addWeapon(WarScroll::Weapon("Long Claws", 1, 4, 4, 3, 0, 2));
    ws.addWeapon(WarScroll::Weapon("Distensible Jaw", 1, 1, 4, 3, 1, 3));

    ws.addAbility(WarScroll::Ability("Ambushing Hunters", 2));
    ws.addAbility(WarScroll::Ability("Insatiable Hunger", 2));

    ws.addKeyWords({"DESTRUCTION", "OGOR", "GUTBUSTER", "GORGERS"});

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eDestruction);

    return ws;
  }

  WarScroll Ironblaster(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(7, 9, 6, 4);

    ws.addWeapon(WarScroll::Weapon("Cannon of the Sky-Titans",
      22, 1, 4, 2, 2, 6));
    ws.addWeapon(WarScroll::Weapon("Ironblaster Gunner's Club",
      1, 3, 4, 3, 0, 2));
    ws.addWeapon(WarScroll::Weapon("Rhinox's Sharp Horns",
      1, 1, 4, 3, 1, 3));
    ws.addWeapon(WarScroll::Weapon("Gnoblar Scrapper's Jagged Blade",
      1, 1, 5, 5, 0, 1));

    ws.addAbility(WarScroll::Ability("Rhinox Charge", 1));
    ws.addAbility(WarScroll::Ability("Cannon Shell", 2));

    ws.addKeyWords({"DESTRUCTION", "OGOR", "GUTBUSTER", "IRONBLASTER"});

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eDestruction);

    return ws;
  }

  WarScroll Gnoblar_Scraplauncher(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(7, 9, 4, 4);

    ws.addWeapon(WarScroll::Weapon("Scraplauncher",
      33, 1, 3, 4, 0, 3));
    ws.addWeapon(WarScroll::Weapon("Gnoblar Scrappers' Weapons",
      1, 7, 5, 5, 0, 1));
    ws.addWeapon(WarScroll::Weapon("Rhinox's Sharp Horns",
      1, 1, 4, 3, 1, 3));

    ws.addAbility(WarScroll::Ability("Rhinox Charge", 1));
    ws.addAbility(WarScroll::Ability("Deadly Rain of Scrap", 2));

    ws.addKeyWords({"DESTRUCTION", "GNOBLAR", "GUTBUSTER",
      "GNOBLAR SCRAPLAUNCHER"});

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eDestruction);

    return ws;
  }

  WarScroll Gnoblar_Fighters(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(5, 1, 3, 6);

    ws.addWeapon(WarScroll::Weapon("Sharp Stuff",
      8, 1, 4, 6, 0, 1));
    ws.addWeapon(WarScroll::Weapon("Motley Assortment of Weapons",
      1, 1,5, 5, 0, 1));

    ws.setMinMaxUnitCount(10, IFaction::s_MaxUnitSize);

    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Groinbiter",
      WarScroll::UnitUpgrade::UnitUpgradeType::eChampion, 1));

    ws.addAbility(WarScroll::Ability("Screeching Horde", 1));
    ws.addAbility(WarScroll::Ability("Trappers", 2));

    ws.addKeyWords({"DESTRUCTION", "GNOBLAR", "GNOBLAR FIGHTERS"});

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eDestruction);

    return ws;
  }

  WarScroll Firebelly(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(6, 7, 6, 5);

    ws.addWeapon(WarScroll::Weapon("Fire Breath", 6, 1, 4, 0, 7, 3));
    ws.addWeapon(WarScroll::Weapon("Basalt Hammer", 2, 2, 4, 3, 1, 3));

    ws.addAbility(WarScroll::Ability("Fire Breath", 1));

    ws.addSpell(WarScroll::Spell("Cascading Fire-Cloak"), 6, 2);

    ws.addKeyWords({"DESTRUCTION", "OGOR", "FIREBELLY", "HERO", "WIZARD"});

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eDestruction);

    return ws;
  }

  WarScroll Hunter(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(6, 7, 7, 5);

    ws.addWeapon(WarScroll::Weapon("Great Throwing Spear", 9, 1, 4, 3, 1, 3));
    ws.addWeapon(WarScroll::Weapon("Hunter's Culling Club", 1, 4, 4, 3, 0, 2));

    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Hunter's Crossbow",
      WarScroll::UnitUpgrade::UnitUpgradeType::eChampion, 1));

    ws.addAbility(WarScroll::Ability("A Hunter of Beasts", 1));
    ws.addAbility(WarScroll::Ability("Might Throw", 2));

    ws.addKeyWords({"DESTRUCTION", "OGOR", "BEASTCLAW", "HERO", "HUNTER"});

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eDestruction);

    return ws;
  }

  WarScroll Sabertusks(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(9, 2, 5, 6);

    ws.addWeapon(WarScroll::Weapon("Elongated Tusks", 1, 3, 4, 3, 1, 1));

    ws.setMinMaxUnitCount(1, IFaction::s_MaxUnitSize);

    ws.addAbility(WarScroll::Ability("Their Master's Voice", 1));

    ws.addKeyWords({"DESTRUCTION", "BEASTCLAW", "SABRETUSKS"});

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eDestruction);

    return ws;
  }

  WarScroll Mournfang_Cavalry(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(9, 6, 6, 4);

    ws.addWeapon(WarScroll::Weapon("Mournfang's Tusks", 1, 4, 4, 3, 1, 1));

    {
      ws.addWeaponUpgrade(WarScroll::WeaponUpgrade(
        WarScroll::Weapon("Ogre Clubs and Blades", 1, 3, 4, 3, 0, 2),
        WarScroll::Ability("Iron Fists", 1)));
    }
    {
      ws.addWeaponUpgrade(WarScroll::WeaponUpgrade(
        WarScroll::Weapon("Ogre Clubs and Blades", 1, 3, 4, 3, 0, 2),
        WarScroll::Ability("Ogre Clubs and Blades", 1)));
    }

    ws.setMinMaxUnitCount(2, IFaction::s_MaxUnitSize);

    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Crusher",
      WarScroll::UnitUpgrade::UnitUpgradeType::eChampion, 1));
    {
      WarScroll::ChampionWithOptions crusher(
        "Crusher with Ogre Clubs and Blades and Iron Fists", 1);
      crusher.addWeapon(WarScroll::Weapon(
        "Ogre Clubs and Blades", 1, 3, 4, 3, 0, 2));
      crusher.addAbility(WarScroll::Ability("Iron Fists", 1));
      ws.registerChampionWithOptions(crusher);
    }
    {
      WarScroll::ChampionWithOptions crusher(
        "Crusher with dual Ogre Clubs and Blades", 1);
      crusher.addWeapon(WarScroll::Weapon(
        "Ogre Clubs and Blades", 1, 3, 4, 3, 0, 2));
      crusher.addAbility(WarScroll::Ability("Ogre Clubs and Blades", 1));
      ws.registerChampionWithOptions(crusher);
    }
    {
      WarScroll::ChampionWithOptions crusher(
        "Crusher with Ogre Pistol and Clubs and Blades and Iron Fists", 1);
      crusher.addWeapon(WarScroll::Weapon(
        "Ogre Clubs and Blades", 1, 3, 4, 3, 0, 2));
      crusher.addAbility(WarScroll::Ability("Iron Fists", 1));
      crusher.addWeapon(WarScroll::Weapon("Ogre Pistol",
        12, 1, 4, 3, 1, 3));
      ws.registerChampionWithOptions(crusher);
    }
    {
      WarScroll::ChampionWithOptions crusher(
        "Crusher with Ogre Pistol and dual Clubs and Blades", 1);
      crusher.addWeapon(WarScroll::Weapon(
        "Ogre Clubs and Blades", 1, 3, 4, 3, 0, 2));
      crusher.addAbility(WarScroll::Ability("Ogre Clubs and Blades", 1));
      crusher.addWeapon(WarScroll::Weapon("Ogre Pistol",
        12, 1, 4, 3, 1, 3));
      ws.registerChampionWithOptions(crusher);
    }
    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Horn Blower",
      WarScroll::UnitUpgrade::UnitUpgradeType::eMusician, 2));
    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Banner Bearer",
      WarScroll::UnitUpgrade::UnitUpgradeType::eBannerBearer, 1));

    ws.addAbility(WarScroll::Ability("Mournfang Charge", 1));

    ws.addKeyWords({"DESTRUCTION", "OGOR", "BEASTCLAW", "MOURNFANG",
      "CAVALRY"});

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eDestruction);

    return ws;
  }

  WarScroll Stonehorn(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(12, 12, 7, 4);

    ws.addWeapon(WarScroll::Weapon("Beastrider's Punches and Kicks",
      1, 3, 4, 4, 0, 1));
    ws.addWeapon(WarScroll::Weapon("Stonehorn's Horns",
      2, 6, 4, 3, 2, 3));
    ws.addWeapon(WarScroll::Weapon("Stonehorn's Crushing Hooves",
      1, 6, 3, 2, 1, 3));

    ws.addWeaponUpgrade(WarScroll::WeaponUpgrade(
      WarScroll::Weapon("Harpoon Launcher", 20, 1, 4, 3, 0, 3),
      WarScroll::Ability()));
    ws.addWeaponUpgrade(WarScroll::WeaponUpgrade(
      WarScroll::Weapon("Chaintrap", 12, 1, 4, 3, 0, 3),
      WarScroll::Ability()));
    ws.addWeaponUpgrade(WarScroll::WeaponUpgrade(
      WarScroll::Weapon("Beastrider's Hunting Spear", 2, 2, 4, 3, 0, 2),
      WarScroll::Ability()));
    ws.addWeaponUpgrade(WarScroll::WeaponUpgrade(
      WarScroll::Weapon("Blood Vulture", 30, 1, 1, 1, 7, 1),
      WarScroll::Ability("Blood Vulture", 2)));

    ws.addAbility(WarScroll::Ability("Earth-shattering Charge", 2));
    ws.addAbility(WarScroll::Ability("Stone Skeleton", 2));

    ws.addKeyWords({"DESTRUCTION", "OGOR", "BEASTCLAW", "MONSTER",
      "STONEHORN"});

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eDestruction);

    return ws;
  }

  WarScroll Thundertusk(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(8, 12, 7, 4);

    ws.addWeapon(WarScroll::Weapon("Frost-wreathed Ice", 18, 6, 2, 1, 7, 1));
    ws.addWeapon(WarScroll::Weapon("Harpoon Launcher", 20, 1, 4, 3, 0, 3));
    ws.addWeapon(WarScroll::Weapon("Beastrider's Punches and Kicks",
      1, 6, 4, 4, 0, 1));
    ws.addWeapon(WarScroll::Weapon("Thundertusk's Crushing Blows",
      2, 4, 3, 2, 1, 3));

    ws.addWeaponUpgrade(WarScroll::WeaponUpgrade(
      WarScroll::Weapon("Chaintrap", 12, 1, 4, 3, 0, 3),
      WarScroll::Ability()));
    ws.addWeaponUpgrade(WarScroll::WeaponUpgrade(
      WarScroll::Weapon("Blood Vulture", 30, 1, 1, 1, 7, 1),
      WarScroll::Ability("Blood Vulture", 2)));

    ws.addAbility(WarScroll::Ability("Blasts of Frost-wreathed Ice", 2));
    ws.addAbility(WarScroll::Ability("Numbing Chill", 2));

    ws.addKeyWords({"DESTRUCTION", "OGOR", "BEASTCLAW", "MONSTER",
      "THUNDERTUSK"});

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eDestruction);

    return ws;
  }

  WarScroll Golgfag_Maneater(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(6, 7, 8, 4);

    ws.addWeapon(WarScroll::Weapon("Ogre Pistol", 12, 1, 4, 3, 1, 3));
    ws.addWeapon(WarScroll::Weapon("Slicer and Basher", 1, 6, 3, 3, 1, 2));

    ws.addAbility(WarScroll::Ability("Golgfag's Maneaters", 1));
    ws.addAbility(WarScroll::Ability("Easy Come, Easy Go", 2));

    ws.addKeyWords({"DESTRUCTION", "OGOR", "MANEATER", "HERO", "GOLGFAG"});

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eDestruction);

    return ws;
  }

  WarScroll Maneaters(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(6, 4, 7, 5);

    ws.addWeapon(WarScroll::Weapon("Slicers and Bashers", 1, 4, 3, 3, 1, 2));

    WarScroll::UnitUpgrade stars("Ogre Pistols or Throwing Stars",
      WarScroll::UnitUpgrade::UnitUpgradeType::eOther, 1);
    stars.addWeapon(WarScroll::Weapon("Ogre Pistols or Throwing Stars",
      12, 1, 3, 3, 1, 3));
    ws.registerUnitUpgrade(stars);

    ws.setMinMaxUnitCount(1, IFaction::s_MaxUnitSize);

    ws.addAbility(WarScroll::Ability("Been There, Done That", 2));

    ws.addKeyWords({"DESTRUCTION", "OGOR", "MANEATERS"});

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eDestruction);

    return ws;
  }

  WarScroll Yhetees(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(9, 4, 6, 6);

    ws.addWeapon(WarScroll::Weapon("Claws and Ice-encrusted Clubs",
      1, 3, 4, 3, 1, 2));

    ws.setMinMaxUnitCount(3, IFaction::s_MaxUnitSize);

    ws.addAbility(WarScroll::Ability("Bounding Leaps", 2));
    ws.addAbility(WarScroll::Ability("Aura of Frost", 2));

    ws.addKeyWords({"DESTRUCTION", "YHETEES"});

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eDestruction);

    return ws;
  }

  WarScroll Giant_in_Ogre_Kingdoms(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(8, 12, 6, 5);

    ws.addWeapon(WarScroll::Weapon("Massive Club", 3, 18, 3, 3, 1, 1));
    ws.addWeapon(WarScroll::Weapon("'Eadbutt", 1, 1, 4, 3, 3, 6));
    ws.addWeapon(WarScroll::Weapon("Mighty Kick", 2, 1, 3, 3, 2, 3));

    ws.addAbility(WarScroll::Ability("Timber", 2));
    ws.addAbility(WarScroll::Ability("Stuff'Em In Me Bag", 1));
    ws.addAbility(WarScroll::Ability("Drunken Stagger", 1));

    ws.addKeyWords(
      {"DESTRUCTION", "GARGANT", "ALEGUZZLER", "MONSTER", "GIANT"});

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eDestruction);

    return ws;
  }
}

OgreKingdomsFaction::OgreKingdomsFaction() :
  IFaction()
{
  m_Units.push_back("");
  m_Units.push_back("Greasus Goldtooth");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Greasus_Goldtooth, m_Units.back())));
  m_Units.push_back("Skrag the Slaughterer");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Skrag_the_Slaughterer, m_Units.back())));
  m_Units.push_back("Tyrant");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Tyrant, m_Units.back())));
  m_Units.push_back("Bragg the Gutsman");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Bragg_the_Gutsman, m_Units.back())));
  m_Units.push_back("Bruiser Standard Bearer");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Bruiser_Standard_Bearer, m_Units.back())));
  m_Units.push_back("Butcher");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Butcher, m_Units.back())));
  m_Units.push_back("Ogres");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Ogres, m_Units.back())));
  m_Units.push_back("Ironguts");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Ironguts, m_Units.back())));
  m_Units.push_back("Leadbelchers");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Leadbelchers, m_Units.back())));
  m_Units.push_back("Gorgers");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Gorgers, m_Units.back())));
  m_Units.push_back("Ironblaster");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Ironblaster, m_Units.back())));
  m_Units.push_back("Gnoblar Scraplauncher");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Gnoblar_Scraplauncher, m_Units.back())));
  m_Units.push_back("Gnoblar Fighters");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Gnoblar_Fighters, m_Units.back())));
  m_Units.push_back("Firebelly");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Firebelly, m_Units.back())));
  m_Units.push_back("Hunter");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Hunter, m_Units.back())));
  m_Units.push_back("Sabertusks");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Sabertusks, m_Units.back())));
  m_Units.push_back("Mournfang Cavalry");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Mournfang_Cavalry, m_Units.back())));
  m_Units.push_back("Stonehorn");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Stonehorn, m_Units.back())));
  m_Units.push_back("Thundertusk");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Thundertusk, m_Units.back())));
  m_Units.push_back("Golgfag Maneater");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Golgfag_Maneater, m_Units.back())));
  m_Units.push_back("Maneaters");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Maneaters, m_Units.back())));
  m_Units.push_back("Yhetees");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Yhetees, m_Units.back())));
  m_Units.push_back("Giant");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Giant_in_Ogre_Kingdoms, m_Units.back())));
}

const std::vector<std::string> &OgreKingdomsFaction::getUnits() const
{
  return m_Units;
}

void OgreKingdomsFaction::getWarScrolls(std::list<WarScroll>& warScrolls)
{
  for (const std::string &unit : m_Units) {
    if (unit.empty()) {
      continue;
    }
    WarScroll ws = m_NameToWarScroll[unit](unit);
    warScrolls.push_back(ws);
  }
}
