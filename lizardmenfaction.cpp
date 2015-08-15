#include "lizardmenfaction.h"

namespace WarScrollGeneration
{
  WarScroll Lord_Kroak(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(5, 10, 10, 4);
    ws.addWeapon(WarScroll::Weapon("Ancient Spirits' Spectral Claws",
      3, 12, 3, 3, 1, 1));

    ws.setCanFly(true);

    ws.addAbility(WarScroll::Ability("Dead for Innumerable Ages", 3));
    ws.addSpell(WarScroll::Spell("Celestial Deliverance"), 7, 2);
    ws.addSpell(WarScroll::Spell("Comet's Call"), 7, 2);

    ws.addAbility(WarScroll::Ability("Impeccable Foresight", 2));

    ws.addKeyWords({"ORDER", "CELESTIAL", "SERAPHON", "SLANN", "HERO",
      "WIZARD", "LORD KROAK"});

    return ws;
  }

  WarScroll Slann_Mage_Priest(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(5, 7, 10, 4);

    ws.addWeapon(WarScroll::Weapon("Azure Lightning", 3, 6, 4, 3, 1, 1));

    ws.setCanFly(true);

    ws.addAbility(WarScroll::Ability("Celestial Configuration", 3));
    ws.addAbility(WarScroll::Ability("Arcane Vassal", 2));

    ws.addSpell(WarScroll::Spell("Light of the Heavens"), 6, 1);

    ws.addAbility(WarScroll::Ability("Gift from the Heavens", 2, true));

    ws.addKeyWords({"ORDER", "CELESTIAL", "SERAPHON", "SLANN", "HERO",
      "WIZARD", "SLANN MAGE-PRIEST"});

    return ws;
  }

  WarScroll Kroq_Gar_on_Carnosaur(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(10, 12, 10, 4);

    ws.addWeapon(WarScroll::Weapon("Sunbolt Gauntlet", 18, 6, 3, 4, 1, 1));
    ws.addWeapon(WarScroll::Weapon("Sunstone Spear", 2, 3, 3, 3, 1, 3));
    ws.addWeapon(WarScroll::Weapon("Carnosaur's Clawed Forelimbs",
      2, 2, 3, 3, 0, 2));
    ws.addWeapon(WarScroll::Weapon("Carnosaur's Massive Jaws",
      2, 5, 4, 3, 1, 3));

    ws.addAbility(WarScroll::Ability("Pinned Down", 2));
    ws.addAbility(WarScroll::Ability("Blood Frenzy", 2));
    ws.addAbility(WarScroll::Ability("Bloodroar", 3));
    ws.addAbility(WarScroll::Ability("Blazing Sunbolts", 2));
    ws.addAbility(WarScroll::Ability("Ancient Warlord", 2));

    ws.addKeyWords({"ORDER", "DAEMON", "CELESTIAL", "SERAPHON", "CARNOSAUR",
      "SAURUS", "MONSTER", "HERO", "KROQ-GAR"});

    return ws;
  }

  WarScroll Saurus_Oldblood(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(5, 7, 10, 4);

    ws.addWeapon(WarScroll::Weapon("Fearsome Jaws and Stardrake Shield",
      1, 1, 4, 3, 0, 1));

    ws.addWeaponUpgrade(WarScroll::WeaponUpgrade(
      WarScroll::Weapon("Suntooth Maul", 1, 2, 3, 4, 1, 3),
      WarScroll::Ability()));
    ws.addWeaponUpgrade(WarScroll::WeaponUpgrade(
      WarScroll::Weapon("Celestite Warblade", 1, 4, 3, 3, 0, 1),
      WarScroll::Ability()));
    ws.addWeaponUpgrade(WarScroll::WeaponUpgrade(
      WarScroll::Weapon("Celestite War-spear", 2, 4, 4, 3, 1, 1),
      WarScroll::Ability()));
    ws.addWeaponUpgrade(WarScroll::WeaponUpgrade(
      WarScroll::Weapon("Celestite Greatblade", 1, 2, 4, 3, 1, 2),
      WarScroll::Ability()));

    ws.addAbility(WarScroll::Ability("Stardrake Shields", 2));
    ws.addAbility(WarScroll::Ability("Wrath of the Seraphon", 1));
    ws.addAbility(WarScroll::Ability("Paragon of Order", 2, true));

    ws.addKeyWords({"ORDER", "DAEMON", "CELESTIAL", "SERAPHON", "SAURUS",
      "HERO", "SAURUS OLDBLOOD"});

    return ws;
  }

  WarScroll Saurus_Oldblood_on_Cold_One(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(10, 7, 10, 4);

    ws.addWeapon(WarScroll::Weapon("Celestite War-pick", 1, 3, 3, 3, 1, 1));
    ws.addWeapon(WarScroll::Weapon("Fearsome Jaws and Stardrake Shield",
      1, 1, 4, 3, 0, 1));
    ws.addWeapon(WarScroll::Weapon("Cold One's Vicious Bite",
      1, 2, 3, 4, 0, 1));

    ws.addAbility(WarScroll::Ability("Stardrake Shield", 2));
    ws.addAbility(WarScroll::Ability("Fury of the Seraphon", 1));
    ws.addAbility(WarScroll::Ability("Savage Charge", 2));

    ws.addKeyWords({"ORDER", "DAEMON", "CELESTIAL", "SERAPHON", "SAURUS",
      "HERO", "SAURUS OLDBLOOD ON COLD ONE"});

    return ws;
  }

  WarScroll Chakax_the_Eternity_Warden(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(5, 7, 10, 4);

    ws.addWeapon(WarScroll::Weapon("Star-stone Mace", 1, 3, 3, 3, 1, 2));
    ws.addWeapon(WarScroll::Weapon("Fearsome Jaws", 1, 1, 4, 4, 0, 1));

    ws.addAbility(WarScroll::Ability("Selfless Protector", 1));
    ws.addAbility(WarScroll::Ability("Alpha Warden", 2)); // --> Temple guard.

    ws.addKeyWords({"ORDER", "DAEMON", "CELESTIAL", "SERAPHON", "SAURUS",
      "HERO", "CHAKAX"});

    return ws;
  }

  WarScroll Gor_Rok(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(5, 7, 10, 4);

    ws.addWeapon(WarScroll::Weapon("Celestite War-mace", 1, 5, 3, 3, 1, 1));
    ws.addWeapon(WarScroll::Weapon("Fearsome Jaws and Aeon Shield",
      1, 2, 4, 3, 0, 1));

    ws.addAbility(WarScroll::Ability("Aeon Shield", 1));
    ws.addAbility(WarScroll::Ability("Ferocious Rage", 1));
    ws.addAbility(WarScroll::Ability("Scent of Weakness", 2, true));

    ws.addKeyWords({"ORDER", "DAEMON", "CELESTIAL", "SERAPHON", "SAURUS",
      "HERO", "GOR-ROK"});

    return ws;
  }

  WarScroll Scar_vetran_with_Battle_Standard(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(5, 6, 10, 4);

    ws.addWeapon(WarScroll::Weapon("Celestile War-pick", 1, 3, 3, 3, 1, 1));
    ws.addWeapon(WarScroll::Weapon("Fearsome Jaws", 1, 1, 4, 4, 0, 1));

    ws.addWeapon(WarScroll::Weapon("Celestial Conduit", 2));
    ws.addWeapon(WarScroll::Weapon("Proud Defiance", 2));

    ws.addKeyWords({"ORDER", "DAEMON", "CELESTIAL", "SERAPHON", "SAURUS",
      "HERO", "TOTEM", "SCAR-VETRAN WITH BATTLE STANDARD"});

    return ws;
  }

  WarScroll Scar_vetran_on_Carnosaur(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(10, 12, 10, 4);

    ws.addWeapon(WarScroll::Weapon("Fearsome Jaws and Stardrake Shield",
      1, 1, 4, 3, 0, 1));
    ws.addWeapon(WarScroll::Weapon("Carnosaur's Clawed Forelimbs",
      2, 2, 3, 3, 0, 2));
    ws.addWeapon(WarScroll::Weapon("Carnosaur's Massive Jaws",
      2, 5, 3, 3, 1, 3));

    ws.addWeaponUpgrade(WarScroll::WeaponUpgrade(
      WarScroll::Weapon("Celestite Warblade", 1, 6, 3, 3, 0, 1),
      WarScroll::Ability()));
    ws.addWeaponUpgrade(WarScroll::WeaponUpgrade(
      WarScroll::Weapon("Celestite War-spear", 2, 6, 4, 3, 1, 1),
      WarScroll::Ability()));
    ws.addWeaponUpgrade(WarScroll::WeaponUpgrade(
      WarScroll::Weapon("Celestite Greatblade", 1, 3, 4, 3, 1, 2),
      WarScroll::Ability()));

    ws.addAbility(WarScroll::Ability("Pinned Down", 1));
    ws.addAbility(WarScroll::Ability("Blood Frenzy", 2));
    ws.addAbility(WarScroll::Ability("Bloodroar", 2));
    ws.addAbility(WarScroll::Ability("Stardrake Shield", 2));
    ws.addAbility(WarScroll::Ability("Saurian Savagery", 2));

    ws.addKeyWords({"ORDER", "DAEMON", "CELESTIAL", "SERAPHON",
      "CARNOSAUR", "SAURUS", "MONSTER", "HERO", "SCAR-VETRAN"});

    return ws;
  }

  WarScroll Saurus_Warriors(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(5, 1, 10, 5);

    ws.addWeapon(WarScroll::Weapon("Powerful Jaws and Stardrake Shield",
      1, 1, 5, 4, 0, 1));

    ws.setMinMaxUnitCount(10, IFaction::s_MaxUnitSize);

    ws.addWeaponUpgrade(WarScroll::WeaponUpgrade(
      WarScroll::Weapon("Celestite Club", 1, 1, 4, 3, 0, 1),
      WarScroll::Ability()));
    ws.addWeaponUpgrade(WarScroll::WeaponUpgrade(
      WarScroll::Weapon("Celestite Spear", 2, 1, 4, 4, 0, 1),
      WarScroll::Ability()));

    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Alpha Talon",
      WarScroll::UnitUpgrade::UnitUpgradeType::eChampion, 1));
    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Stardrake Icon",
      WarScroll::UnitUpgrade::UnitUpgradeType::eBannerBearer, 1));
    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Wardrum",
      WarScroll::UnitUpgrade::UnitUpgradeType::eMusician, 1));

    ws.addAbility(WarScroll::Ability("Stardrake Shields", 2));
    ws.addAbility(WarScroll::Ability("Ordered Cohort", 1));

    ws.addKeyWords({"ORDER", "DAEMON", "CELESTIAL", "SERAPHON", "SAURUS",
      "SAURUS WARRIORS"});

    return ws;
  }

  WarScroll Temple_Guard(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(5, 1, 10, 4);

    ws.addWeapon(WarScroll::Weapon("Celestite Polearm", 1, 2, 3, 3, 1, 1));
    ws.addWeapon(WarScroll::Weapon("Powerful Jaws and Stardrake Shield",
      1, 1, 5, 4, 0, 1));

    ws.setMinMaxUnitCount(5, IFaction::s_MaxUnitSize);

     ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Alpha Guardian",
      WarScroll::UnitUpgrade::UnitUpgradeType::eChampion, 1));
    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Stardrake Icon",
      WarScroll::UnitUpgrade::UnitUpgradeType::eBannerBearer, 1));
    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Wardrum",
      WarScroll::UnitUpgrade::UnitUpgradeType::eMusician, 1));

    ws.addAbility(WarScroll::Ability("Stardrake Shields", 2));

    ws.addKeyWords({"ORDER", "DAEMON", "CELESTIAL", "SERAPHON", "SAURUS",
      "TEMPLE GUARD"});

    return ws;
  }

  WarScroll Saurus_Cavalry(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(7, 2, 10, 5);

    ws.addWeapon(WarScroll::Weapon("Powerful Jaws and Stardrake Shield",
      1, 1, 5, 4, 0, 1));
    ws.addWeapon(WarScroll::Weapon("Cold One's Vicious Bite",
      1, 2, 3, 4, 0, 1));

    ws.addWeaponUpgrade(WarScroll::WeaponUpgrade(
      WarScroll::Weapon("Celestite Blade", 1, 1, 3, 3, 0, 1),
      WarScroll::Ability()));
    ws.addWeaponUpgrade(WarScroll::WeaponUpgrade(
      WarScroll::Weapon("Celestite Lance", 1, 1, 4, 3, 0, 1),
      WarScroll::Ability("Blazing Lances", 1)));

    ws.setMinMaxUnitCount(5, IFaction::s_MaxUnitSize);

    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Alpha Knight",
      WarScroll::UnitUpgrade::UnitUpgradeType::eChampion, 1));
    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Stardrake Icon",
      WarScroll::UnitUpgrade::UnitUpgradeType::eBannerBearer, 1));
    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Wardrum",
      WarScroll::UnitUpgrade::UnitUpgradeType::eMusician, 1));

    ws.addAbility(WarScroll::Ability("Stardrake Shields", 2));

    ws.addKeyWords({"ORDER", "DAEMON", "CELESTIAL", "SERAPHON",
      "SAURUS CAVALRY"});

    return ws;
  }

  WarScroll Tehenhauin_Prophet_of_Sotek(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(8, 5, 10, 5);

    ws.addWeapon(WarScroll::Weapon("Tide of Serpents", 8, 4, 5, 4, 0, 1));
    ws.addWeapon(WarScroll::Weapon("Blade of the Serpent's Tongue",
      2, 4, 3, 4, 1, 1));

    ws.addAbility(WarScroll::Ability("Deadly Venom", 1));
    ws.addAbility(WarScroll::Ability("Priestly Rites", 1));
    ws.addAbility(WarScroll::Ability("Prophet of Sotek", 2));

    ws.addKeyWords({"ORDER", "DAEMON", "CELESTIAL", "SERAPHON", "SKINK",
      "HERO", "PRIEST", "TEHENHAUIN"});

    return ws;
  }

  WarScroll Tetto_eko(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(5, 5, 10, 4);

    ws.addWeapon(WarScroll::Weapon("Astromancer's Staff", 2, 1, 4, 4, 1, 3));

    ws.setCanFly(true);

    ws.addAbility(WarScroll::Ability("Cosmic Herald", 3));

    ws.addSpell(WarScroll::Spell("Curse of Fates"), 4, 1);

    ws.addKeyWords({"ORDER", "DAEMON", "CELESTIAL", "SERAPHON", "SKINK",
      "HERO", "WIZARD", "TETTO'EKO"});

    return ws;
  }

  WarScroll Oxyotl(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(8, 4, 10, 6);

    ws.addWeapon(WarScroll::Weapon("Golden Blowpipe of P'toohee",
      16, 6, 3, 4, 0, 1));
    ws.addWeapon(WarScroll::Weapon("Dart", 1, 2, 5, 5, 0, 1));

    ws.addAbility(WarScroll::Ability("Chamelon Ambush", 3));
    ws.addAbility(WarScroll::Ability("Disappear from Sight", 3));
    ws.addAbility(WarScroll::Ability("Flawless Mimicry", 2));
    ws.addAbility(WarScroll::Ability("Master Predator", 2));

    ws.addKeyWords({"ORDER", "DAEMON", "CELESTIAL", "SERAPHON", "SKINK",
      "HERO", "OXYOTL"});

    return ws;
  }

  WarScroll Skink_Priest(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(8, 4, 10, 5);

    ws.addWeapon(WarScroll::Weapon("Starbolt", 18, 3, 3, 3, 1, 1));
    ws.addWeapon(WarScroll::Weapon("Star-stone Staff", 1, 3, 4, 3, 1, 1));

    ws.addAbility(WarScroll::Ability("Celestial Rites", 1));

    WarScroll::MountUpgrade cloak("Cloak of Feathers");
    cloak.addAbility(WarScroll::Ability("Cloak of Feathers", 2));
    cloak.registerCharacteristicToIncrease("Save", -1);
    cloak.registerCharacteristicToIncrease("Move", 6);

    ws.addAbility(WarScroll::Ability("Priestly Trappings", 1));

    ws.addKeyWords({"ORDER", "DAEMON", "CELESTIAL", "SERAPHON", "SKINK",
      "HERO", "PRIEST", "SKINK PRIEST"});

    return ws;
  }

  WarScroll Skink_Chief(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(8, 4, 10, 5);

    ws.addWeaponUpgrade(WarScroll::WeaponUpgrade(
      WarScroll::Weapon("Ornate Club", 1, 4, 4, 3, 0, 1),
      WarScroll::Ability()));
    ws.addWeaponUpgrade(WarScroll::WeaponUpgrade(
      WarScroll::Weapon("Golden Sickle", 1, 4, 4, 4, 1, 1),
      WarScroll::Ability()));

    WarScroll::UnitUpgrade unitUpgrade("Blowpipe",
      WarScroll::UnitUpgrade::UnitUpgradeType::eOther, 2);
    unitUpgrade.addWeapon(WarScroll::Weapon("Blowpipe", 16, 1, 4, 4, 0, 1));
    ws.registerUnitUpgrade(unitUpgrade);

    ws.addAbility(WarScroll::Ability("Marked for Greatness", 1));
    ws.addAbility(WarScroll::Ability("Star-buckler", 2));
    ws.addAbility(WarScroll::Ability("Skink War Leader", 1));

    ws.addKeyWords({"ORDER", "DAEMON", "CELESTIAL", "SERAPHON", "SKINK",
      "HERO", "SKINK CHIEF"});

    return ws;
  }

  WarScroll Skinks(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(8, 1, 10, 6);

    ws.setMinMaxUnitCount(10, IFaction::s_MaxUnitSize);

    ws.addWeaponUpgrade(WarScroll::WeaponUpgrade(
      WarScroll::Weapon("Meteoric Javelins", 8, 1, 5, 4, 0, 1),
      WarScroll::Ability("Star-buckler", 2)));
    {
      WarScroll::WeaponUpgrade upgrade(
        WarScroll::Weapon("Boltspitter", 16, 1, 5, 5, 0, 1),
        WarScroll::Ability());
      upgrade.setSecondaryWeapon(WarScroll::Weapon(
        "Moonstone Club", 1, 1, 5, 4, 0, 1));
      ws.addWeaponUpgrade(upgrade);
    }
    ws.addWeaponUpgrade(WarScroll::WeaponUpgrade(
      WarScroll::Weapon("Boltspitter", 16, 1, 5, 5, 0, 1),
      WarScroll::Ability("Star-buckler", 2)));
    ws.addWeaponUpgrade(WarScroll::WeaponUpgrade(
      WarScroll::Weapon("Moonstone Club", 1, 1, 5, 4, 0, 1),
      WarScroll::Ability("Star-buckler", 2)));

    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Alpha",
      WarScroll::UnitUpgrade::UnitUpgradeType::eChampion, 1));

    ws.addAbility(WarScroll::Ability("Celestial Cohort", 1));
    ws.addAbility(WarScroll::Ability("Wary Fighters", 2));

    ws.addKeyWords({"ORDER", "DAEMON", "CELESTIAL", "SERAPHON", "SKINKS"});

    return ws;
  }

  WarScroll Chameleon_Skinks(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(8, 1, 10, 6);

    ws.addWeapon(WarScroll::Weapon("Dartpipe", 16, 2, 3, 4, 0, 1));
    ws.addWeapon(WarScroll::Weapon("Envenomed Dart", 1, 1, 5, 5, 0, 1));

    ws.setMinMaxUnitCount(5, IFaction::s_MaxUnitSize);

    ws.addAbility(WarScroll::Ability("Chameleon Ambush", 3));
    ws.addAbility(WarScroll::Ability("Disappear from Sight", 3));
    ws.addAbility(WarScroll::Ability("Star-venom", 2));

    ws.addKeyWords({"ORDER", "DAEMON", "CELESTIAL", "SERAPHON", "SKINK",
      "CHAMELEON SKINKS"});

    return ws;
  }

  WarScroll Terradon_Riders(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(14, 3, 10, 5);

    ws.addWeapon(WarScroll::Weapon("Terradon's Razor-sharp Beak",
      1, 4, 4, 4, 0, 1));

    ws.setMinMaxUnitCount(3, IFaction::s_MaxUnitSize);

    ws.addWeaponUpgrade(WarScroll::WeaponUpgrade(
      WarScroll::Weapon("Starstrike Javelins", 10, 2, 4, 3, 0, 1),
      WarScroll::Ability()));
    ws.addWeaponUpgrade(WarScroll::WeaponUpgrade(
      WarScroll::Weapon("Sunleech Bolas", 5, 1, 4, 4, 0, 1),
      WarScroll::Ability("Sunleech Bolas", 2)));

    {
      WarScroll::ChampionWithOptions unitLeader(
        "Alpha Unit Leader with Starstrike Javelin", 1);
      unitLeader.addWeapon(WarScroll::Weapon("Starstrike Javelin",
        10, 2, 4, 3, 0, 1));
      ws.registerChampionWithOptions(unitLeader);
    }
    {
      WarScroll::ChampionWithOptions unitLeader(
        "Alpha Unit Leader with Sunleech Bolas", 1);
      unitLeader.addWeapon(WarScroll::Weapon("Sunleech Bolas",
        10, 2, 3, 3, 0, 1));
      unitLeader.addAbility(WarScroll::Ability("Sunleech Bolas", 2));
      ws.registerChampionWithOptions(unitLeader);
    }
    {
      WarScroll::ChampionWithOptions unitLeader(
        "Master of the Skies", 1);
      unitLeader.addWeapon(WarScroll::Weapon("Skyblade",
        1, 3, 3, 4, 0, 1));
      unitLeader.addAbility(WarScroll::Ability("Skyblade", 2));
      ws.registerChampionWithOptions(unitLeader);
    }
    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Unit Leader",
      WarScroll::UnitUpgrade::UnitUpgradeType::eChampion, 1));

    ws.addAbility(WarScroll::Ability("Deadly Cargo", 1));
    ws.addAbility(WarScroll::Ability("Swooping Dive", 1));

    ws.addKeyWords({"ORDER", "DAEMON", "CELESTIAL", "SERAPHON", "SKINK",
      "TERRADON RIDERS"});

    return ws;
  }

  WarScroll Ripperdactyl_Riders(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(14, 3, 10, 5);

    ws.addWeapon(WarScroll::Weapon("Moonstone War-spear", 2, 1, 4, 4, 0, 1));
    ws.addWeapon(WarScroll::Weapon("Ripperdactyl's Slashing Claws",
      1, 3, 3, 3, 0, 1));
    ws.addWeapon(WarScroll::Weapon("Ripperdactyl's Vicious Beak",
      1, 1, 4, 3, 0, 1));

    ws.setMinMaxUnitCount(3, IFaction::s_MaxUnitSize);

    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Alpha",
      WarScroll::UnitUpgrade::UnitUpgradeType::eChampion, 1));

    ws.setCanFly(true);

    ws.addAbility(WarScroll::Ability("Voracious", 3));
    ws.addAbility(WarScroll::Ability("Star-bucklers", 2));
    ws.addAbility(WarScroll::Ability("Swooping Dive", 1));
    ws.addAbility(WarScroll::Ability("Toad Rage", 3));

    ws.addKeyWords({"ORDER", "DAEMON", "CELESTIAL", "SERAPHON", "SKINK",
      "RIPPERDACTYL RIDERS"});

    return ws;
  }

  WarScroll Skink_Handlers(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(8, 1, 10, 6);

    ws.addWeapon(WarScroll::Weapon("Goad-spears", 2, 1, 5, 5, 0, 1));

    ws.setMinMaxUnitCount(1, IFaction::s_MaxUnitSize);

    ws.addAbility(WarScroll::Ability("Aim for their Eyes", 1));

    ws.addKeyWords({"ORDER", "DAEMON", "CELESTIAL", "SERAPHON", "SKINK",
      "HANDLERS"});

    return ws;
  }

  WarScroll Salamanders(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(8, 3, 10, 5);

    ws.addWeapon(WarScroll::Weapon("Stream of Fire", 8, 1, 3, 3, 2, 6));
    ws.addWeapon(WarScroll::Weapon("Corrosive Bite", 1, 3, 3, 3, 1, 1));

    ws.setMinMaxUnitCount(1, IFaction::s_MaxUnitSize);

    ws.addAbility(WarScroll::Ability("Goaded to Fury", 2));
    ws.addAbility(WarScroll::Ability("It Burns!", 2));

    ws.addKeyWords({"ORDER", "DAEMON", "CELESTIAL", "SERAPHON", "SALAMANDERS"});

    return ws;
  }

  WarScroll Razordons(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(8, 3, 10, 4);

    ws.addWeapon(WarScroll::Weapon("Volley of Spikes", 12, 12, 3, 4, 0, 1));
    ws.addWeapon(WarScroll::Weapon("Fierce Bite and Spiked Tail",
      1, 3, 4, 3, 0, 1));

    ws.setMinMaxUnitCount(1, IFaction::s_MaxUnitSize);
    ws.addAbility(WarScroll::Ability("Piercing Barbs", 1));
    ws.addAbility(WarScroll::Ability("Instinctive Defence", 2));
    ws.addAbility(WarScroll::Ability("Goaded to Anger", 2));

    ws.addKeyWords({"ORDER", "DAEMON", "CELESTIAL", "SERAPHON", "RAZORDONS"});

    return ws;
  }

  WarScroll Kroxigor(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(8, 4, 10, 4);

    ws.addWeapon(WarScroll::Weapon("Drakebite Maul", 2, 4, 4, 3, 1, 2));
    ws.addWeapon(WarScroll::Weapon("Vice-like Jaws", 1, 1, 4, 3, 1, 1));

    ws.setMinMaxUnitCount(3, IFaction::s_MaxUnitSize);

    WarScroll::ChampionWithOptions moonHammer("Moon Hammer");
    moonHammer.addWeapon(WarScroll::Weapon("Moon Hammer", 2, 10, 4, 3, 1, 2));
    moonHammer.addAbility(WarScroll::Ability("Sweeping Blows", 3));
    moonHammer.setEveryNModels(3);
    ws.registerChampionWithOptions(moonHammer);
    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Moon Hammer",
      WarScroll::UnitUpgrade::UnitUpgradeType::eChampion, 1));

    ws.addAbility(WarScroll::Ability("Energy Transference", 1));
    ws.addAbility(WarScroll::Ability("Jaws like a Steel Trap", 2));

    ws.addKeyWords({"ORDER", "DAEMON", "CELESTIAL", "SERAPHON", "KROXIGOR"});

    return ws;
  }

  WarScroll Stegadon(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(8, 10, 10, 4);

    ws.addWeapon(WarScroll::Weapon("Massive Horns", 2, 3, 3, 3, 3, 2));
    ws.addWeapon(WarScroll::Weapon("Crushing Stomps", 1, 18, 4, 0, 1));
    ws.addWeapon(WarScroll::Weapon("Meteoric Javelins", 8, 4, 5, 4, 0, 1));

    ws.addWeaponUpgrade(WarScroll::WeaponUpgrade(
      WarScroll::Weapon("Skystreak Bow", 25, 3, 4, 3, 1, 3),
      WarScroll::Ability()));
    ws.addWeaponUpgrade(WarScroll::WeaponUpgrade(
      WarScroll::Weapon("Sunfire Throwers", 8, 10, 4, 3, 1, 3),
      WarScroll::Ability("Gout of Sunfire", 2)));

    ws.addAbility(WarScroll::Ability("Unstoppable Stampede", 1));
    ws.addAbility(WarScroll::Ability("Steadfast Majesty", 1));

    WarScroll::UnitUpgrade alpha("Skink Alpha",
      WarScroll::UnitUpgrade::UnitUpgradeType::eChampion, 1);
    alpha.addAbility(WarScroll::Ability("Skink Alpha", 1));
    ws.registerUnitUpgrade(alpha);

    ws.addKeyWords({"ORDER", "DAEMON", "CELESTIAL", "SERAPHON", "SKINK",
      "MONSTER", "STEGADON"});

    return ws;
  }

  WarScroll Engine_of_the_Gods(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(8, 10, 10, 4);

    ws.addWeapon(WarScroll::Weapon("Sharpened Horns", 2, 4, 3, 3, 1, 2));
    ws.addWeapon(WarScroll::Weapon("Crushing Stomps", 1, 18, 4, 4, 0, 1));

    ws.addWeapon(WarScroll::Weapon("Meteroic Javelins", 8, 4, 5, 4, 0, 1));

    ws.addAbility(WarScroll::Ability("Unstoppable Stampede", 1));
    ws.addAbility(WarScroll::Ability("Cosmic Engine", 3));
    ws.addAbility(WarScroll::Ability("Steadfast Majesty", 1));

    ws.addKeyWords({"ORDER", "DAEMON", "CELESTIAL", "SERAPHON", "STEGADON",
      "SKINK", "MONSTER", "HERO", "PRIEST", "SKINK PRIEST",
      "ENGINE OF THE GODS"});

    return ws;
  }

  WarScroll Bastiladon(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(5, 8, 10, 3);

    ws.addWeapon(WarScroll::Weapon("Bludgeoning Tail", 2, 3, 3, 3, 1, 3));
    ws.addWeapon(WarScroll::Weapon("Meteoric Javelins", 8, 4, 5, 4, 0, 1));

    ws.addWeaponUpgrade(WarScroll::WeaponUpgrade(
      WarScroll::Weapon("Searing Beam", 20, 12, 4, 3, 1, 2),
      WarScroll::Ability("Light of the Heavens", 1)));
    ws.addWeaponUpgrade(WarScroll::WeaponUpgrade(
      WarScroll::Weapon("Tides of Snakes", 0, 0, 0, 0, 0, 0),
      WarScroll::Ability("Tide of Snakes", 3)));

    ws.addAbility(WarScroll::Ability("Impervious Defence", 1));

    ws.addKeyWords({"ORDER", "DAEMON", "CELESTIAL", "SERAPHON", "SKINK",
      "MONSTER", "BASTILADON"});

    return ws;
  }

  WarScroll Troglodon(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(10, 12, 10, 4);

    ws.addWeapon(WarScroll::Weapon("Noxious Spittle", 18, 3, 3, 3, 0, 2));
    ws.addWeapon(WarScroll::Weapon("Venomous Bite", 2, 6, 4, 2, 0, 2));
    ws.addWeapon(WarScroll::Weapon("Troglodon's Clawed Forelimbs",
      2, 2, 4, 3, 0, 2));
    ws.addWeapon(WarScroll::Weapon("Skink Oracle's Divining Rod",
      1, 1, 4, 5, 0, 1));

    ws.addAbility(WarScroll::Ability("Divining Rod", 1));
    ws.addAbility(WarScroll::Ability("Primeval Roar", 1));
    ws.addAbility(WarScroll::Ability("Drawn to the Screams", 2));

    ws.addKeyWords({"ORDER", "DAEMON", "CELESTIAL", "SERAPHON", "SKINK",
      "MONSTER", "TROGLODON"});

    return ws;
  }

  WarScroll Jungle_Swarms(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(6, 5, 10, 7);

    ws.addWeapon(WarScroll::Weapon("Envenomed Teech and Fangs",
      1, 5, 5, 5, 0, 1));

    ws.setMinMaxUnitCount(1, IFaction::s_MaxUnitSize);

    ws.addAbility(WarScroll::Ability("Swarming Tide", 2));
    ws.addAbility(WarScroll::Ability("Deadly Venom", 1));

    ws.addKeyWords({"ORDER", "JUNGLE SWARMS"});

    return ws;
  }
}

LizardmenFaction::LizardmenFaction() :
  IFaction(nullptr)
{
  m_Units.push_back("");
  m_Units.push_back("Lord Kroak");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Lord_Kroak, m_Units.back())));
  m_Units.push_back("Slann Mage-Priest");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Slann_Mage_Priest, m_Units.back())));
  m_Units.push_back("Kroq-Gar on Carnosaur");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Kroq_Gar_on_Carnosaur, m_Units.back())));
  m_Units.push_back("Saurus Oldblood");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Saurus_Oldblood, m_Units.back())));
  m_Units.push_back("Saurus Oldblood on Cold One");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Saurus_Oldblood_on_Cold_One,
    m_Units.back())));
  m_Units.push_back("Chakax, the Eternity Warden");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Chakax_the_Eternity_Warden, m_Units.back())));
  m_Units.push_back("Gor-Rok");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Gor_Rok, m_Units.back())));
  m_Units.push_back("Scar-vetran with Battle Standard");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Scar_vetran_with_Battle_Standard,
    m_Units.back())));
  m_Units.push_back("Scar-vetran on Carnosaur");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Scar_vetran_on_Carnosaur, m_Units.back())));
  m_Units.push_back("Saurus Warriors");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Saurus_Warriors, m_Units.back())));
  m_Units.push_back("Temple Guard");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Temple_Guard, m_Units.back())));
  m_Units.push_back("Saurus Cavalry");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Saurus_Cavalry, m_Units.back())));
  m_Units.push_back("Tehenhauin, Prophet of Sotek");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Tehenhauin_Prophet_of_Sotek,
    m_Units.back())));
  m_Units.push_back("Tetto'eko");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Tetto_eko, m_Units.back())));
  m_Units.push_back("Oxyotl");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Oxyotl, m_Units.back())));
  m_Units.push_back("Skink Priest");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Skink_Priest, m_Units.back())));
  m_Units.push_back("Skink Chief");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Skink_Chief, m_Units.back())));
  m_Units.push_back("Skinks");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Skinks, m_Units.back())));
  m_Units.push_back("Chameleon Skinks");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Chameleon_Skinks, m_Units.back())));
  m_Units.push_back("Terradon Riders");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Terradon_Riders, m_Units.back())));
  m_Units.push_back("Ripperdactyl Riders");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Ripperdactyl_Riders, m_Units.back())));
  m_Units.push_back("Skink Handlers");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Skink_Handlers, m_Units.back())));
  m_Units.push_back("Salamanders");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Salamanders, m_Units.back())));
  m_Units.push_back("Razordons");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Razordons, m_Units.back())));
  m_Units.push_back("Kroxigor");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Kroxigor, m_Units.back())));
  m_Units.push_back("Stegadon");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Stegadon, m_Units.back())));
  m_Units.push_back("Engine of the Gods");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Engine_of_the_Gods, m_Units.back())));
  m_Units.push_back("Bastiladon");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Bastiladon, m_Units.back())));
  m_Units.push_back("Troglodon");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Troglodon, m_Units.back())));
  m_Units.push_back("Jungle Swarms");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Jungle_Swarms, m_Units.back())));
}

const std::vector<std::string> &LizardmenFaction::getUnits() const
{
  return m_Units;
}

void LizardmenFaction::getWarScrolls(std::list<WarScroll>& warScrolls)
{
  for (const std::string &unit : m_Units) {
    if (unit.empty()) {
      continue;
    }
    WarScroll ws = m_NameToWarScroll[unit](unit);
    warScrolls.push_back(ws);
  }
}
