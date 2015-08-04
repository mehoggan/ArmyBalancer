#include "darkelvesfaction.h"

namespace WarScrollGeneration
{
  WarScroll Malekith_the_Witch_King(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(14, 14, 9, 4);

    ws.addWeapon(WarScroll::Weapon("The Destroyer", 1, 3, 3, 3, 1, 3));
    ws.addWeapon(WarScroll::Weapon("Sepaphon's Claws", 2, 6, 4, 3, 1, 2));
    ws.addWeapon(WarScroll::Weapon("Sepaphon's Fearsome Jaws",
      3, 3, 3, 2, 2, 6));

    ws.setCanFly(true);

    ws.addAbility(WarScroll::Ability("Armour of Midnight", 3));
    ws.addAbility(WarScroll::Ability("Noxious Breath", 2));
    ws.addAbility(WarScroll::Ability("Absolute Power", 3, true));

    ws.addSpell(WarScroll::Spell("Soul Stealer"), 6, 3);

    ws.addKeyWords({"ORDER", "AELF", "DRAGON", "EXILES", "HERO", "WIZARD",
      "MONSTER", "MALEKITH"});

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eOrder);

    return ws;
  }

  WarScroll Malus_Darkblade(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(10, 6, 8, 4);

    ws.addWeapon(WarScroll::Weapon("Warpsword of Khaine", 2, 3, 3, 3, 1, 3));
    ws.addWeapon(WarScroll::Weapon("Spite's Ferocious Jaws", 1, 3, 3, 4, 0, 1));

    ws.addAbility(WarScroll::Ability("Tz'arkan", 2));
    ws.addAbility(WarScroll::Ability("The Tyrant of Hag Graef", 2, true));

    ws.addKeyWords({"ORDER", "AELF", "EXILES", "HERO", "DREADLORD",
      "MALUS DARKBLADE"});

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eOrder);

    return ws;
  }

  WarScroll Dreadlord(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(6, 5, 8, 4);

    ws.addAbility(WarScroll::Ability("The Price of Failure", 2));
    ws.addAbility(WarScroll::Ability("Cruel Tyrant", 2));

    WarScroll::WeaponUpgrade dualExileBlades(
      WarScroll::Weapon("Exile Blade", 1, 6, 3, 4, 0, 1),
      WarScroll::Ability("Exile Blade", 1));
    ws.addWeaponUpgrade(dualExileBlades);
    WarScroll::WeaponUpgrade shieldUpgrade(
      WarScroll::Weapon("Exile Blade", 1, 6, 3, 4, 0, 1),
      WarScroll::Ability("Tyrant Shield", 1));
    ws.addWeaponUpgrade(shieldUpgrade);
    WarScroll::WeaponUpgrade chillBladeUpgrade(
      WarScroll::Weapon("Chillblade", 1, 3, 3, 3, 1, 3),
      WarScroll::Ability(""));
    ws.addWeaponUpgrade(chillBladeUpgrade);

    ws.addKeyWords({"ORDER", "AELF", "EXILES", "HERO", "DREADLORD"});

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eOrder);

    return ws;
  }

  WarScroll Dreadlord_on_Black_Dragon(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(14, 14, 8, 4);

    ws.addWeapon(WarScroll::Weapon("Black Dragon's Claws",
      2, 6, 4, 3, 1, 2));
    ws.addWeapon(WarScroll::Weapon("Black Dragon's Fearsome Jaws",
      3, 3, 4, 2, 2, 6));

    ws.setCanFly(true);

    ws.addAbility(WarScroll::Ability("Noxious Breath", 1));
    ws.addAbility(WarScroll::Ability("Do Not Disappoint Me", 2, true));

    WarScroll::WeaponUpgrade shieldUpgrade(
      WarScroll::Weapon("Exile Blade", 1, 6, 3, 4, 0, 1),
      WarScroll::Ability("Tyrant Shield", 1));
    ws.addWeaponUpgrade(shieldUpgrade);
    WarScroll::WeaponUpgrade lanceOfSpiteUpgrade(
      WarScroll::Weapon("Lance of Spite", 2, 3, 3, 3, 1, 1),
      WarScroll::Ability("Tyrant Shield", 1));
    lanceOfSpiteUpgrade.addAbility(WarScroll::Ability("Lance of Spite", 1));
    ws.addWeaponUpgrade(lanceOfSpiteUpgrade);
    WarScroll::WeaponUpgrade exileWithCrossBowUpgrade(
      WarScroll::Weapon("Exile Blade", 1, 6, 3, 4, 0, 1),
      WarScroll::Ability());
    exileWithCrossBowUpgrade.setSecondaryWeapon(WarScroll::Weapon(
      "Repeater Crossbow", 16, 4, 4, 4, 0, 1));
    ws.addWeaponUpgrade(exileWithCrossBowUpgrade);
    WarScroll::WeaponUpgrade lanceWithCrossBowUpgrade(
      WarScroll::Weapon("Lance of Spite", 2, 3, 3, 3, 1, 1),
      WarScroll::Ability());
    lanceWithCrossBowUpgrade.setSecondaryWeapon(WarScroll::Weapon(
      "Repeater Crossbow", 16, 4, 4, 4, 0, 1));
    ws.addWeaponUpgrade(lanceWithCrossBowUpgrade);
    WarScroll::WeaponUpgrade dualExileBlades(
      WarScroll::Weapon("Exile Blade", 1, 6, 3, 4, 0, 1),
      WarScroll::Ability("Exile Blades", 1));
    ws.addWeaponUpgrade(dualExileBlades);

    ws.addKeyWords({"ORDER", "AELF", "DRAGON", "EXILES", "HERO", "MONSTER",
      "DREADLORD"});

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eOrder);

    return ws;
  }

  WarScroll Dreadlord_on_Cold_One(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(10, 6, 8, 4);

    ws.addWeapon(WarScroll::Weapon("Hydra Blade", 1, 6, 3, 3, 1, 1));
    ws.addWeapon(WarScroll::Weapon("Cold One's Ferocious Jaws",
      1, 2, 3, 4, 1, 1));

    ws.addAbility(WarScroll::Ability("Tyrant Shield", 1));
    ws.addAbility(WarScroll::Ability("Bladed Barding", 1));
    ws.addAbility(WarScroll::Ability("Single-minded Hunting Beasts", 1));

    ws.addKeyWords({"ORDER", "AELF", "EXILE", "HERO", "DREADLORD"});

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eOrder);

    return ws;
  }

  WarScroll Dark_Elf_Sorceress(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(6, 5, 7, 6);

    ws.addWeapon(WarScroll::Weapon("Witchstaff", 2, 1, 4, 3, 1, 3));

    ws.addAbility(WarScroll::Ability("Blood Sacrifice", 1));

    ws.addSpell(WarScroll::Spell("Word of Pain"), 7, 1);

    ws.addKeyWords({"ORDER", "AELF", "EXILES", "HERO", "WIZARD", "SORCERESS"});

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eOrder);

    return ws;
  }

  WarScroll Sorceress_on_Black_Dragon(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(14, 14, 7, 5);

    ws.addWeapon(WarScroll::Weapon("Black Dragon's Claws", 2, 6, 4, 3, 1, 2));
    ws.addWeapon(WarScroll::Weapon("Black Dragon's Fearsome Jaws",
      3, 3, 4, 2, 2, 6));

    ws.setCanFly(true);

    ws.addAbility(WarScroll::Ability("Blood Sacrifice", 1));
    ws.addAbility(WarScroll::Ability("Noxious Breath", 1));

    ws.addSpell(WarScroll::Spell("Bladewind"), 6, 1);

    WarScroll::WeaponUpgrade witchRodUpgrade(
      WarScroll::Weapon("Witch Rod", 1, 1, 4, 3, 1, 3),
      WarScroll::Ability());
    ws.addWeaponUpgrade(witchRodUpgrade);
    WarScroll::WeaponUpgrade swordOfGhrondUpgrade(
      WarScroll::Weapon("Sword of Ghrond", 1, 3, 4, 4, 0, 1),
      WarScroll::Ability());
    ws.addWeaponUpgrade(swordOfGhrondUpgrade);
    WarScroll::WeaponUpgrade witchRodWitchLashUpgrade(
      WarScroll::Weapon("Witch Rod", 1, 1, 4, 3, 1, 3),
      WarScroll::Ability());
    witchRodWitchLashUpgrade.setSecondaryWeapon(WarScroll::Weapon("Witch Lash",
      2, 1, 3, 4, 0, 1));
    ws.addWeaponUpgrade(witchRodWitchLashUpgrade);
    WarScroll::WeaponUpgrade swordOfGhrondWitchLashUpgrade(
      WarScroll::Weapon("Sword of Ghrond", 1, 3, 4, 4, 0, 1),
      WarScroll::Ability());
    swordOfGhrondWitchLashUpgrade.setSecondaryWeapon(WarScroll::Weapon(
      "Witch Lash", 2, 1, 3, 4, 0, 1));
    ws.addWeaponUpgrade(swordOfGhrondWitchLashUpgrade);

    ws.addKeyWords({"ORDER", "AELF", "DRAGON", "EXILES", "HERO", "WIZARD",
      "MONSTER", "SORCERESS"});

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eOrder);

    return ws;
  }

  WarScroll Sorceress_on_Cold_One(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(10, 6, 7, 5);

    ws.addWeapon(WarScroll::Weapon("Witchstaff", 2, 1, 4, 3, 1, 3));
    ws.addWeapon(WarScroll::Weapon("Cold One's Ferocious Jaws",
      1, 2, 3, 4, 0, 1));

    ws.addAbility(WarScroll::Ability("Blood Sacrifice", 1));

    ws.addSpell(WarScroll::Spell("Chillwind"), 5, 2);

    ws.addKeyWords({"ORDER", "AELF", "EXILES", "HERO", "WIZARD", "SORCERESS"});

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eOrder);

    return ws;
  }

  WarScroll Cold_One_Knights(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(10, 2, 7, 4);

    ws.addWeapon(WarScroll::Weapon("Barded Lance and Blade", 2, 1, 3, 4, 0, 1));
    ws.addWeapon(WarScroll::Weapon("Cold One's Ferocious Jaws",
      1, 2, 3, 4, 0, 1));

    ws.setMinMaxUnitCount(5, IFaction::s_MaxUnitSize);

    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Dread Knight",
      WarScroll::UnitUpgrade::UnitUpgradeType::eChampion, 1));
    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Standard Bearer",
      WarScroll::UnitUpgrade::UnitUpgradeType::eBannerBearer, 2));
    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Hornblower",
      WarScroll::UnitUpgrade::UnitUpgradeType::eMusician, 1));

    ws.addAbility(WarScroll::Ability("Lance Charge", 1));
    ws.addAbility(WarScroll::Ability("Darkshields", 1));

    ws.addKeyWords({"ORDER", "AELF", "EXILES", "COLD ONE KNIGHTS"});

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eOrder);

    return ws;
  }

  WarScroll Cold_One_Chariots(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(10, 6, 7, 4);

    ws.addWeapon(WarScroll::Weapon("Repeater Crossbow", 16, 4, 5, 4, 0, 1));
    ws.addWeapon(WarScroll::Weapon("Charioteers' Barbed Spears and Blades",
      2, 2, 3, 4, 0, 1));
    ws.addWeapon(WarScroll::Weapon("Cold Ones' Ferocious Jaws",
      1, 4, 3, 4, 0, 1));

    ws.setMinMaxUnitCount(1, IFaction::s_MaxUnitSize);

    ws.addAbility(WarScroll::Ability("Scythed Runners", 1));

    ws.addKeyWords({"ORDER", "AELF", "EXILES", "COLD ONE CHARIOTS"});

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eOrder);

    return ws;
  }

  WarScroll Beastmaster_on_Manticore(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(12, 10, 7, 5);

    ws.addWeapon(WarScroll::Weapon("Great Scourge", 2, 3, 4, 4, 0, 1));
    ws.addWeapon(WarScroll::Weapon("Savage Jaws and Claws", 2, 3, 4, 3, 1, 2));
    ws.addWeapon(WarScroll::Weapon("Barbed Tail", 2, 3, 4, 3, 0, 3));

    ws.addAbility(WarScroll::Ability("Spiteful Dominance", 1));
    ws.addAbility(WarScroll::Ability("Sea Dragon Cloak", 1));

    ws.addKeyWords({"ORDER", "AELF", "MANTICORE", "EXILES", "HERO", "MONSTER",
      "BEASTMASTER"});

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eOrder);

    return ws;
  }

  WarScroll Black_Ark_Fleetmaster(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(6, 5, 7, 4);

    ws.addWeapon(WarScroll::Weapon("Black Ark Cutlass", 1, 3, 3, 4, 0, 1));
    ws.addWeapon(WarScroll::Weapon("Murder Hook", 1, 2, 4, 3, 1, 1));

    ws.addAbility(WarScroll::Ability("Sea Dragon Cloak", 1));
    ws.addAbility(WarScroll::Ability("Murderous Swashbuckler", 1));
    ws.addAbility(WarScroll::Ability("At Them, You Curs!", 2, true));

    ws.addKeyWords({"ORDER", "AELF", "EXILES", "HERO",
      "BLACK ARK FLEETMASTER"});

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eOrder);

    return ws;
  }

  WarScroll Lokhir_Fellheart(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(6, 5, 7, 4);

    ws.addWeapon(WarScroll::Weapon("The Red Blades", 1, 5, 3, 4, 0, 1));

    ws.addAbility(WarScroll::Ability("The Red Blades", 2));
    ws.addAbility(WarScroll::Ability("Sea Dragon Cloak", 1));
    ws.addAbility(WarScroll::Ability("Helm of the Kraken", 2));
    ws.addAbility(WarScroll::Ability("Daring Leap", 2));
    ws.addAbility(WarScroll::Ability("Take Them Alive!", 2, true));

    ws.addKeyWords({"ORDER", "AELF", "EXILES", "HERO", "BLACK ARK FLEETMASTER",
      "LOKHIR FELLHEART"});

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eOrder);

    return ws;
  }

  WarScroll Black_Ark_Corsairs(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(6, 1, 6, 5);

    ws.setMinMaxUnitCount(10, IFaction::s_MaxUnitSize);

    WarScroll::WeaponUpgrade handBowViciousBladeUpgrade(
      WarScroll::Weapon("Vicious Blade", 1, 1, 4, 5, 0, 1),
      WarScroll::Ability());
    handBowViciousBladeUpgrade.setSecondaryWeapon(WarScroll::Weapon(
      "Repeater Handbow", 9, 2, 5, 4, 0, 1));
    ws.addWeaponUpgrade(handBowViciousBladeUpgrade);

    WarScroll::WeaponUpgrade wickedCutlassViciousBladeUpgrade(
      WarScroll::Weapon("Vicious Blade", 1, 1, 4, 5, 0, 1),
      WarScroll::Ability());
    wickedCutlassViciousBladeUpgrade.setSecondaryWeapon(WarScroll::Weapon(
      "Wicked Cutlass", 1, 1, 4, 4, 0, 1));
    ws.addWeaponUpgrade(wickedCutlassViciousBladeUpgrade);

    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Reaver",
      WarScroll::UnitUpgrade::UnitUpgradeType::eChampion, 1));
    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Standard Bearer",
      WarScroll::UnitUpgrade::UnitUpgradeType::eBannerBearer, 1));
    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Hornblower",
      WarScroll::UnitUpgrade::UnitUpgradeType::eMusician, 1));

    ws.addAbility(WarScroll::Ability("Sea Dragon Cloaks", 1));
    ws.addAbility(WarScroll::Ability("Flashing Steel", 1));
    ws.addAbility(WarScroll::Ability("Ravagers and Slavers", 1));

    ws.addKeyWords({"ORDER", "AELF", "EXILES", "BLACK ARK CORSAIRS"});

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eOrder);

    return ws;
  }

  WarScroll Master_with_Battle_Standard(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(6, 5, 8, 4);

    ws.addWeapon(WarScroll::Weapon("Barbed Blade", 1, 4, 3, 3, 0, 1));

    WarScroll::UnitUpgrade darkSteedUpgrade("Dark Steed",
      WarScroll::UnitUpgrade::UnitUpgradeType::eMount, 2);
    darkSteedUpgrade.registerCharacteristicToIncrease("Move", 8);
    darkSteedUpgrade.addWeapon(WarScroll::Weapon("Dark Steed's Vicious Bite",
      1, 2, 4, 5, 0, 1));
    darkSteedUpgrade.addWeapon(WarScroll::Weapon("Barbed Blade",
      1, 4, 3, 3, 0, 1));
    ws.registerUnitUpgrade(darkSteedUpgrade);

    ws.addAbility(WarScroll::Ability("Treachery and Power", 2));
    ws.addAbility(WarScroll::Ability("Banner of Murder", 2));

    ws.addKeyWords({"ORDER", "AELF", "EXILES", "HERO", "TOTEM",
      "MASTER WITH BATTLE STANDARD"});

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eOrder);

    return ws;
  }

  WarScroll Dreadspears(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(6, 1, 6, 5);

    ws.addWeapon(WarScroll::Weapon("Druchii Spear", 2, 1, 4, 4, 0, 1));

    ws.setMinMaxUnitCount(10, IFaction::s_MaxUnitSize);

    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Lordling",
      WarScroll::UnitUpgrade::UnitUpgradeType::eChampion, 1));
    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Standard Bearer",
      WarScroll::UnitUpgrade::UnitUpgradeType::eBannerBearer, 1));
    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Hornblower",
      WarScroll::UnitUpgrade::UnitUpgradeType::eMusician, 1));

    ws.addAbility(WarScroll::Ability("Darkshields", 1));
    ws.addAbility(WarScroll::Ability("City Guard", 1));
    ws.addAbility(WarScroll::Ability("Formidable Bastion", 1));

    ws.addKeyWords({"ORDER", "AELF", "EXILES", "DREADSPEAR"});

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eOrder);

    return ws;
  }

  WarScroll Bleakswords(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(6, 1, 6, 5);

    ws.addWeapon(WarScroll::Weapon("Druchii Sword", 1, 1, 3, 4, 0, 1));

    ws.setMinMaxUnitCount(10, IFaction::s_MaxUnitSize);

    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Lordling",
      WarScroll::UnitUpgrade::UnitUpgradeType::eChampion, 1));
    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Standard Bearer",
      WarScroll::UnitUpgrade::UnitUpgradeType::eBannerBearer, 1));
    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Hornblower",
      WarScroll::UnitUpgrade::UnitUpgradeType::eMusician, 1));

    ws.addAbility(WarScroll::Ability("Quicksilver Strike", 1));
    ws.addAbility(WarScroll::Ability("Darkshields", 1));

    ws.addKeyWords({"ORDER", "AELF", "EXILES", "BLEAKSWORDS"});

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eOrder);

    return ws;
  }

  WarScroll Darkshards(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(6, 1, 6, 5);

    ws.addWeapon(WarScroll::Weapon("Repeater Crossbow", 16, 2, 5, 4, 0, 1));
    ws.addWeapon(WarScroll::Weapon("Cruel Dagger", 1, 1, 5, 5, 0, 1));

    ws.setMinMaxUnitCount(1, IFaction::s_MaxUnitSize);

    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Guardmaster",
      WarScroll::UnitUpgrade::UnitUpgradeType::eChampion, 1));
    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Standard Bearer",
      WarScroll::UnitUpgrade::UnitUpgradeType::eBannerBearer, 1));
    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Hornblower",
      WarScroll::UnitUpgrade::UnitUpgradeType::eMusician, 1));
    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Darkshields",
      WarScroll::UnitUpgrade::UnitUpgradeType::eShield, 1));

    ws.addAbility(WarScroll::Ability("Storm of Iron-tipped Bolts", 1));

    ws.addKeyWords({"ORDER", "AELF", "EXILES", "DARKSHARDS"});

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eOrder);

    return ws;
  }

  WarScroll Dark_Riders(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(14, 2, 6, 5);

    ws.addWeapon(WarScroll::Weapon("Repeater Crossbow", 16, 3, 5, 4, 0, 1));
    ws.addWeapon(WarScroll::Weapon("Barbed Spears and Swords",
      2, 1, 4, 4, 0, 1));
    ws.addWeapon(WarScroll::Weapon("Dark Steeds' Vicious Bites",
      1, 2, 4, 5, 0, 1));

    ws.setMinMaxUnitCount(5, IFaction::s_MaxUnitSize);

    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Herald",
      WarScroll::UnitUpgrade::UnitUpgradeType::eChampion, 1));
    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Standard Bearer",
      WarScroll::UnitUpgrade::UnitUpgradeType::eBannerBearer, 1));
    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Hornblower",
      WarScroll::UnitUpgrade::UnitUpgradeType::eMusician, 1));

    ws.addAbility(WarScroll::Ability("Sow Terror and Confusion", 1));
    ws.addAbility(WarScroll::Ability("Darkshields", 1));

    ws.addKeyWords({"ORDER", "AELF", "EXILES", "DARK RIDERS"});

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eOrder);

    return ws;
  }

  WarScroll Black_Guard_of_Naggarond(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(6, 1, 7, 4);

    ws.addWeapon(WarScroll::Weapon("Ebon Halbred", 2, 2, 3, 3, 1, 1));

    ws.setMinMaxUnitCount(5, IFaction::s_MaxUnitSize);

    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Tower Master",
      WarScroll::UnitUpgrade::UnitUpgradeType::eChampion, 1));
    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Standard Bearer",
      WarScroll::UnitUpgrade::UnitUpgradeType::eBannerBearer, 1));
    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Drummers",
      WarScroll::UnitUpgrade::UnitUpgradeType::eMusician, 1));

    ws.addAbility(WarScroll::Ability("The Witch King's Retinue", 1));
    ws.addAbility(WarScroll::Ability("Eternal Hatred", 1));

    ws.addKeyWords({"ORDER", "AELF", "EXILES", "BLACK GUARD"});

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eOrder);

    return ws;
  }

  WarScroll Shades(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(6, 1, 6, 6);

    ws.addWeapon(WarScroll::Weapon("Repeater Crossbow", 16, 2, 4, 4, 0, 1));
    ws.addWeapon(WarScroll::Weapon("Barbed Sword", 1, 2, 4, 4, 0, 1));

    ws.setMinMaxUnitCount(5, IFaction::s_MaxUnitSize);

    ws.addAbility(WarScroll::Ability("A Shadow Moves Unseen", 2));
    ws.addAbility(WarScroll::Ability("Blend with Darkness", 1));

    ws.addKeyWords({"ORDER", "AELF", "EXILES", "SHADES"});

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eOrder);

    return ws;
  }

  WarScroll Reaper_Bolt_Thrower(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(4, 4, 7, 5);

    ws.addWeapon(WarScroll::Weapon("Reaper Bolts", 36, 12, 4, 3, 1, 1));
    ws.addWeapon(WarScroll::Weapon("Druchii Sword", 1, 2, 4, 4, 0, 1));

    ws.addAbility(WarScroll::Ability("Crewed War Machine", 1));
    ws.addAbility(WarScroll::Ability("Reaper Bolts", 2));

    ws.addKeyWords({"ORDER", "WAR MACHINE", "REAPER BOLT THROWER", "AELF",
      "EXILES", "CREWS"});

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eOrder);

    return ws;
  }

  WarScroll Harpies_in_DarkElves(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(16, 1, 3, 6);

    ws.addWeapon(WarScroll::Weapon("Claws and Fangs", 1, 2, 4, 4, 0, 1));

    ws.setMinMaxUnitCount(5, IFaction::s_MaxUnitSize);

    ws.setCanFly(true);

    ws.addAbility(WarScroll::Ability("Prey Upon the Weak", 1));

    ws.addKeyWords({"CHAOS", "HARPIES"});

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eOrder);

    return ws;
  }

  WarScroll Scourgerunner_Chariots(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(12, 6, 6, 5);

    ws.addWeapon(WarScroll::Weapon("Repeater Crossbow", 16, 4, 5, 4, 0, 1));
    ws.addWeapon(WarScroll::Weapon("Ravager Harpoon", 18, 1, 4, 3, 1, 3));
    ws.addWeapon(WarScroll::Weapon("Hook-spears", 2, 2, 4, 4, 0, 1));
    ws.addWeapon(WarScroll::Weapon("Dark Steeds' Vicious Bites",
      1, 4, 4, 5, 0, 1));

    ws.setMinMaxUnitCount(1, IFaction::s_MaxUnitSize);

    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("High Beastmaster",
      WarScroll::UnitUpgrade::UnitUpgradeType::eChampion, 1));

    ws.addAbility(WarScroll::Ability("Lay the Beast Low", 1));

    ws.addKeyWords({"ORDER", "AELF", "EXILES", "SCOURGERUNNER CHARIOTS"});

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eOrder);

    return ws;
  }

  WarScroll War_Hydra(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(8, 12, 6, 4);

    ws.addWeapon(WarScroll::Weapon("Fiery Breath", 9, 6, 3, 3, 1, 1));
    ws.addWeapon(WarScroll::Weapon("Razor-sharp Fangs", 2, 6, 4, 3, 1, 3));
    ws.addWeapon(WarScroll::Weapon("Clawed Limbs", 1, 2, 3, 3, 1, 1));
    ws.addWeapon(WarScroll::Weapon("Handlers' Cruel Goads and Whips",
      2, 2, 4, 4, 0, 1));

    ws.addAbility(WarScroll::Ability("Sever One Head, Another Takes Its Place",
      3));
    ws.addAbility(WarScroll::Ability("Quick with the Lash", 2));

    ws.addKeyWords({"ORDER", "AELF" "EXILES", "MONSTER", "BEASTMASTER",
      "WAR HYDRA"});

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eOrder);

    return ws;
  }

  WarScroll Doomfire_Warlocks(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(14, 2, 6, 5);

    ws.addWeapon(WarScroll::Weapon("Cursed Scimitar", 1, 2, 4, 4, 0, 1));
    ws.addWeapon(WarScroll::Weapon("Dark Steed's Vicious Bite",
      1, 2, 4, 5, 0, 1));

    ws.setMinMaxUnitCount(5, IFaction::s_MaxUnitSize);

    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Master of Warlocks",
      WarScroll::UnitUpgrade::UnitUpgradeType::eChampion, 1));

    ws.addSpell(WarScroll::Spell("Doombolt"), 5, 2);

    ws.addKeyWords({"ORDER", "AELF", "EXILES", "WIZARD", "DOOMFIRE WARLOCKS"});

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eOrder);

    return ws;
  }

  WarScroll Kharibdyss(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(7, 12, 6, 4);

    ws.addWeapon(WarScroll::Weapon("Fanged Tentacles", 3, 6, 4, 3, 1, 2));
    ws.addWeapon(WarScroll::Weapon("Clawed Limbs", 1, 2, 3, 3, 1, 1));
    ws.addWeapon(WarScroll::Weapon("Spiked Tail", 2, 6, 4, 2, 0, 1));
    ws.addWeapon(WarScroll::Weapon("Handlers' Cruel Goads and Whips",
      2, 2, 4, 4, 0, 1));

    ws.addAbility(WarScroll::Ability("Abyssal Howl", 1));
    ws.addAbility(WarScroll::Ability("Feast of Bones", 1));
    ws.addAbility(WarScroll::Ability("Quick With The Lash", 1));

    ws.addKeyWords({"ORDER", "AELF", "EXILES", "MONSTER", "BEASTMASTER",
      "KHARIBDYSS"});

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eOrder);

    return ws;
  }

  WarScroll Sisters_of_Slaughter(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(6, 1, 7, 6);

    ws.addWeapon(WarScroll::Weapon("Barbed Whip", 2, 2, 3, 4, 0, 1));

    ws.setMinMaxUnitCount(5, IFaction::s_MaxUnitSize);

    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Handmaiden",
      WarScroll::UnitUpgrade::UnitUpgradeType::eChampion, 1));
    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Standard Bearer",
      WarScroll::UnitUpgrade::UnitUpgradeType::eBannerBearer, 1));
    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Hornblower",
      WarScroll::UnitUpgrade::UnitUpgradeType::eMusician, 1));

    ws.addAbility(WarScroll::Ability("Bladed Buckler", 2));
    ws.addAbility(WarScroll::Ability("Dance of Death", 2));

    ws.addKeyWords({"ORDER", "AELF", "EXILES", "SISTERS OF SLAUGHTER"});

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eOrder);

    return ws;
  }

  WarScroll Morathi(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(16, 6, 8, 4);

    ws.addWeapon(WarScroll::Weapon("Heartrender", 2, 2, 3, 3, 1, 3));
    ws.addWeapon(WarScroll::Weapon("Dark Pegasus' Cruel Horns",
      1, 2, 4, 3, 0, 1));

    ws.setCanFly(true);

    ws.addAbility(WarScroll::Ability("The First Sorceress", 3));
    ws.addAbility(WarScroll::Ability("Enchanting Beauty", 1));

    ws.addSpell(WarScroll::Spell("Arnzipal's Black Horror"), 7, 2);

    ws.addKeyWords({"ORDER", "AELF", "EXILES", "HERO", "WIZARD", "SORCERESS",
      "MORATHI"});

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eOrder);

    return ws;
  }

  WarScroll Bloodwrack_Medusae(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eOrder);

    ws.setCharacteristics(8, 5, 6, 5);

    ws.addWeapon(WarScroll::Weapon("Bloodwrack Stare", 10, 20, 0, 0, 0, 1));
    ws.addWeapon(WarScroll::Weapon("Whisperclaw", 1, 4, 4, 3, 0, 1));
    ws.addWeapon(WarScroll::Weapon("Bloodwrack Spear", 2, 1, 3, 3, 1, 3));

    ws.setMinMaxUnitCount(1, IFaction::s_MaxUnitSize);

    ws.addAbility(WarScroll::Ability("Bloodwrack Stare", 2));

    ws.addKeyWords({"ORDER", "BLOODWRACK MEDUSAE"});

    return ws;
  }

  WarScroll Bloodwrack_Shrine(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(6, 13, 7, 5);

    ws.addWeapon(WarScroll::Weapon("Bloodwrack Stare", 10, 20, 0, 0, 0, 1));
    ws.addWeapon(WarScroll::Weapon("Whisperclaw", 1, 4, 4, 3, 0, 1));
    ws.addWeapon(WarScroll::Weapon("Bloodwrack Spear", 2, 1, 3, 3, 1, 3));
    ws.addWeapon(WarScroll::Weapon("Shrinekeepers' Goadstaves",
      2, 6, 4, 4, 0, 1));

    ws.addAbility(WarScroll::Ability("Bloodwrack Stare", 2));
    ws.addAbility(WarScroll::Ability("Aura of Agony", 1));

    ws.addKeyWords({"ORDER", "AELF", "EXILES", "BLOODWRACK MEDUSA",
      "BLOODWRACK SHRINE"});

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eOrder);

    return ws;
  }

  WarScroll Cauldron_of_Blood(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(6, 13, 7, 5);

    ws.addWeapon(WarScroll::Weapon("Witch Elves' Sacrificial Knives",
      1, 6, 3, 4, 0, 1));

    WarScroll::MountUpgrade hellebronUpgrade("Hellebron");
    hellebronUpgrade.addWeapon(WarScroll::Weapon("Hellebron's Deathsword",
      1, 2, 3, 3, 1, 3));
    hellebronUpgrade.addWeapon(WarScroll::Weapon("Hellebron's Cursed Blade",
      1, 2, 3, 4, 0, 1));
    hellebronUpgrade.addAbility(WarScroll::Ability("Amulet of Dark Fire", 2));
    hellebronUpgrade.addAbility(WarScroll::Ability("Orgy of Slaughter", 3));
    hellebronUpgrade.setMakesUnitUnique(true);
    ws.registerMountUpgrade(hellebronUpgrade);
    WarScroll::MountUpgrade deathHagUpgrade("Death Hag");
    deathHagUpgrade.addWeapon(WarScroll::Weapon("Death Hag's Blade of Khaine",
      1, 4, 3, 4, 0, 1));
    ws.registerMountUpgrade(deathHagUpgrade);

    ws.addAbility(WarScroll::Ability("Bloodshield", 1));
    ws.addAbility(WarScroll::Ability("Witchbrew", 2));
    ws.addAbility(WarScroll::Ability("Strength of Khaine", 1));

    ws.addKeyWords({"ORDER", "AELF", "EXILES", "TOTEM", "HERO", "PRIEST",
      "WITCH ELVES", "DEATH HAG", "CAULDRON OF BLOOD"});

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eOrder);

    return ws;
  }

  WarScroll Witch_Elves(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(7, 1, 7, 0);

    ws.addWeapon(WarScroll::Weapon("Sacrificial Knives", 1, 2, 3, 4, 0, 1));

    ws.setMinMaxUnitCount(5, IFaction::s_MaxUnitSize);

    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Hag",
      WarScroll::UnitUpgrade::UnitUpgradeType::eChampion, 1));
    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Standard Bearer",
      WarScroll::UnitUpgrade::UnitUpgradeType::eBannerBearer, 1));
    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Hornblower",
      WarScroll::UnitUpgrade::UnitUpgradeType::eMusician, 1));

    ws.addAbility(WarScroll::Ability("Frenzied Fervour", 2));
    ws.addAbility(WarScroll::Ability("Sacrificial Knives", 1));

    ws.addKeyWords({"ORDER", "AELF", "EXILES", "WITCH ELVES"});

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eOrder);

    return ws;
  }

  WarScroll Hellebron(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(6, 5, 7, 5);

    ws.addWeapon(WarScroll::Weapon("Deathsword", 1, 2, 3, 3, 1, 3));
    ws.addWeapon(WarScroll::Weapon("Cursed Blade", 1, 2, 3, 4, 0, 1));

    ws.addAbility(WarScroll::Ability("Amulet of Dark Fire", 2));
    ws.addAbility(WarScroll::Ability("The Blood Queen", 2));
    ws.addAbility(WarScroll::Ability("Orgy of Slaughter", 3));

    ws.addKeyWords({"ORDER", "AELF", "EXILES", "HERO", "PRIEST", "DEATH HAG",
      "HELLEBRON"});

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eOrder);

    return ws;
  }

  WarScroll Shadowblade(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(8, 5, 8, 4);

    ws.addWeapon(WarScroll::Weapon("Poison-coated Daggers", 1, 6, 3, 3, 1, 1));

    ws.addAbility(WarScroll::Ability("Black Lotus Venom", 2));
    ws.addAbility(WarScroll::Ability("Heart of Woe", 1));
    ws.addAbility(WarScroll::Ability("Master of Disguise", 2));
    ws.addAbility(WarScroll::Ability("Master of Assassins", 1));

    ws.addKeyWords({"ORDER", "AELF", "EXILES", "HERO", "DARK ELF ASSASSIN",
      "SHADOWBLADE"});

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eOrder);

    return ws;
  }

  WarScroll Death_Hag(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(7, 5, 7, 6);

    ws.addWeapon(WarScroll::Weapon("Blade of Khaine", 1, 4, 3, 4, 0, 1));

    ws.addAbility(WarScroll::Ability("Priestess of Khaine", 2));
    ws.addAbility(WarScroll::Ability("Witchbrew", 1));

    ws.addKeyWords({"ORDER", "AELF", "EXILES", "HERO", "PRIEST", "DEATH HAG"});

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eOrder);

    return ws;
  }

  WarScroll Dark_Elf_Assassin(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(6, 5, 7, 5);

    ws.addWeapon(WarScroll::Weapon("Envenomed Throwing Blades",
      12, 2, 4, 4, 0, 1));
    ws.addWeapon(WarScroll::Weapon("Poison-coated Blades", 1, 5, 3, 3, 0, 1));

    ws.addAbility(WarScroll::Ability("Black Lotus Venom", 1));
    ws.addAbility(WarScroll::Ability("Hidden Murderer", 2));

    ws.addKeyWords({"ORDER", "AELF", "EXILES", "HERO", "DARK ELF ASSASSIN"});

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eOrder);

    return ws;
  }

  WarScroll Har_Ganeth_Executioners(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(6, 1, 7, 4);

    ws.addWeapon(WarScroll::Weapon("Executioner's Draich", 1, 2, 3, 3, 0, 1));

    ws.setMinMaxUnitCount(5, IFaction::s_MaxUnitSize);

    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Draich Master",
      WarScroll::UnitUpgrade::UnitUpgradeType::eChampion, 1));
    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Standard Bearer",
      WarScroll::UnitUpgrade::UnitUpgradeType::eBannerBearer, 1));
    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Drummers",
      WarScroll::UnitUpgrade::UnitUpgradeType::eMusician, 1));

    ws.addAbility(WarScroll::Ability("Severing Strike", 2));

    ws.addKeyWords({"ORDER", "AELF", "EXILES", "HAR GANETH EXECUTIONERS"});

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eOrder);

    return ws;
  }
}

DarkElvesFaction::DarkElvesFaction() :
  IFaction(nullptr)
{
  m_Units.push_back("");
  m_Units.push_back("Malekith, the Witch King");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Malekith_the_Witch_King, m_Units.back())));
  m_Units.push_back("Malus Darkblade");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Malus_Darkblade, m_Units.back())));
  m_Units.push_back("Dreadlord");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Dreadlord, m_Units.back())));
  m_Units.push_back("Dreadlord on Black Dragon");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Dreadlord_on_Black_Dragon,
    m_Units.back())));
  m_Units.push_back("Dreadlord on Cold One");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Dreadlord_on_Cold_One, m_Units.back())));
  m_Units.push_back("Dark Elf Sorceress");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Dark_Elf_Sorceress, m_Units.back())));
  m_Units.push_back("Sorceress on Black Dragon");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Sorceress_on_Black_Dragon,
    m_Units.back())));
  m_Units.push_back("Sorceress on Cold One");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Sorceress_on_Cold_One, m_Units.back())));
  m_Units.push_back("Cold One Knights");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Cold_One_Knights, m_Units.back())));
  m_Units.push_back("Cold One Chariots");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Cold_One_Chariots, m_Units.back())));
  m_Units.push_back("Beastmaster on Manticore");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Beastmaster_on_Manticore, m_Units.back())));
  m_Units.push_back("Black Ark Fleetmaster");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Black_Ark_Fleetmaster, m_Units.back())));
  m_Units.push_back("Lokhir Fellheart");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Lokhir_Fellheart, m_Units.back())));
  m_Units.push_back("Black Ark Corsairs");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Black_Ark_Corsairs, m_Units.back())));
  m_Units.push_back("Master with Battle Standard");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Master_with_Battle_Standard,
    m_Units.back())));
  m_Units.push_back("Dreadspears");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Dreadspears, m_Units.back())));
  m_Units.push_back("Bleakswords");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Bleakswords, m_Units.back())));
  m_Units.push_back("Darkshards");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Darkshards, m_Units.back())));
  m_Units.push_back("Dark Riders");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Dark_Riders, m_Units.back())));
  m_Units.push_back("Black Guard of Naggarond");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Black_Guard_of_Naggarond, m_Units.back())));
  m_Units.push_back("Shades");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Shades, m_Units.back())));
  m_Units.push_back("Reaper Bolt Thrower");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Reaper_Bolt_Thrower, m_Units.back())));
  m_Units.push_back("Harpies");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Harpies_in_DarkElves, m_Units.back())));
  m_Units.push_back("Scourgerunner Chariots");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Scourgerunner_Chariots, m_Units.back())));
  m_Units.push_back("War Hydra");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::War_Hydra, m_Units.back())));
  m_Units.push_back("Doomfire Warlocks");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Doomfire_Warlocks, m_Units.back())));
  m_Units.push_back("Kharibdyss");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Kharibdyss, m_Units.back())));
  m_Units.push_back("Sisters of Slaughter");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Sisters_of_Slaughter, m_Units.back())));
  m_Units.push_back("Morathi");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Morathi, m_Units.back())));
  m_Units.push_back("Bloodwrack Medusae");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Bloodwrack_Medusae, m_Units.back())));
  m_Units.push_back("Bloodwrack Shrine");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Bloodwrack_Shrine, m_Units.back())));
  m_Units.push_back("Cauldron of Blood");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Cauldron_of_Blood, m_Units.back())));
  m_Units.push_back("Witch Elves");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Witch_Elves, m_Units.back())));
  m_Units.push_back("Hellebron");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Hellebron, m_Units.back())));
  m_Units.push_back("Shadowblade");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Shadowblade, m_Units.back())));
  m_Units.push_back("Death Hag");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Death_Hag, m_Units.back())));
  m_Units.push_back("Dark Elf Assassin");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Dark_Elf_Assassin, m_Units.back())));
  m_Units.push_back("Har Ganeth Executioners");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Har_Ganeth_Executioners, m_Units.back())));
}

const std::vector<std::string> &DarkElvesFaction::getUnits() const
{
  return m_Units;
}

void DarkElvesFaction::getWarScrolls(std::list<WarScroll>& warScrolls)
{
  for (const std::string &unit : m_Units) {
    if (unit.empty()) {
      continue;
    }
    WarScroll ws = m_NameToWarScroll[unit](unit);
    warScrolls.push_back(ws);
  }
}
