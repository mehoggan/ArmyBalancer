#include "highelvesfaction.h"

namespace WarScrollGeneration
{
  WarScroll Tyrion(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(12, 6, 9, 3);

    ws.addWeapon(WarScroll::Weapon("Sunfang", 8, 6, 3, 4, 0, 1));
    ws.addWeapon(WarScroll::Weapon("Sunfang", 1, 6, 3, 3, 2, 3));
    ws.addWeapon(WarScroll::Weapon("Malhandir's Mighty Hooves",
      1, 2, 4, 3, 0, 1));

    ws.addAbility(WarScroll::Ability("Heart of Avelorn", 2));
    ws.addAbility(WarScroll::Ability("The Dragon Armour of Aenarion", 3));
    ws.addAbility(WarScroll::Ability("Defender of Ulthuan", 2, true));

    ws.addKeyWords({"ORDER", "AELF", "HIGHBORN", "HERO", "HIGH ELF PRINCE",
      "TYRION"});

    return ws;
  }

  WarScroll Teclis(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(6, 5, 8, 4);

    ws.addWeapon(WarScroll::Weapon("Moon Staff of Lileath", 2, 1, 4, 3, 1, 3));
    ws.addWeapon(WarScroll::Weapon("The Sword of Teclis", 1, 1, 4, 3, 2, 1));

    ws.addAbility(WarScroll::Ability("Blessings of Lileath", 2));
    ws.addAbility(WarScroll::Ability("War Crown of Saphery", 2));

    ws.addSpell(WarScroll::Spell("Tempest"), 5, 2);

    ws.addKeyWords({"ORDER", "AELF", "HIGHBORN", "HERO", "WIZARD",
      "HIGH ELF MAGE", "TECLIS"});

    return ws;
  }

  WarScroll Eltharion_on_Stormwing(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(16, 10, 8, 4);

    ws.addWeapon(WarScroll::Weapon("Fangsword of Eltharion", 1, 4, 3, 3, 2, 3));
    ws.addWeapon(WarScroll::Weapon("Starwood Lance", 2, 2, 3, 4, 1, 2));
    ws.addWeapon(WarScroll::Weapon("Stormwing's Razor-sharp Beak",
      2, 1, 3, 3, 2, 6));
    ws.addWeapon(WarScroll::Weapon("Stormwing's Wicked Talons",
      2, 6, 4, 3, 1, 1));

    ws.setCanFly(true);

    ws.addAbility(WarScroll::Ability("Helm of Yvresse", 2));
    ws.addAbility(WarScroll::Ability("Starwood Lance", 2));

    ws.addAbility(WarScroll::Ability("Call to Glory", 2, true));

    ws.addKeyWords({"ORDER", "AELF", "GRIFFON", "HIGHBORN", "HERO", "WIZARD",
      "MONSTER", "HIGH ELF PRINCE", "ELTHARION ON STORMWING"});

    return ws;
  }

  WarScroll Prince_Imrik_Dragonlord(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(14, 14, 8, 4);

    ws.addWeapon(WarScroll::Weapon("Imrik's Star Lance", 2, 3, 3, 3, 1, 2));
    ws.addWeapon(WarScroll::Weapon("Minaithnir's Claws", 2, 6, 4, 3, 1, 2));
    ws.addWeapon(WarScroll::Weapon("Minaithnir's Fearsome Jaws",
      3, 3, 4, 2, 6));

    ws.setCanFly(true);

    ws.addAbility(WarScroll::Ability("Star Lance", 1));
    ws.addAbility(WarScroll::Ability("The Dragonhorn", 1));
    ws.addAbility(WarScroll::Ability("Dragonfire", 2));
    ws.addAbility(WarScroll::Ability("Lord of Dragons", 1, true));

    ws.addKeyWords({"ORDER", "AELF", "DRAGON", "HIGHBORN", "HERO", "MONSTER",
      "HIGH ELF PRINCE", "PRINCE IMRIK"});

    return ws;
  }

  WarScroll Prince_Althran(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(6, 5, 8, 4);

    ws.addWeapon(WarScroll::Weapon("The Stormrider's Sword", 1, 4, 3, 4, 0, 2));

    ws.addAbility(WarScroll::Ability("Enchanted Shield", 2));
    ws.addAbility(WarScroll::Ability("Armour of Fortune", 2));
    ws.addAbility(WarScroll::Ability("Glory of the Elves", 1));

    ws.addKeyWords({"ORDER", "AELF", "HIGHBORN", "HERO", "HIGH ELF PRINCE",
      "PRINCE ALTHRAN"});

    return ws;
  }

  WarScroll High_Elf_Prince(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(6, 5, 8, 4);

    {
      WarScroll::WeaponUpgrade weaponUpgrade(
        WarScroll::Weapon("Starblade", 1, 6, 3, 4, 0, 1),
        WarScroll::Ability());
      ws.addWeaponUpgrade(weaponUpgrade);
    }
    {
      WarScroll::WeaponUpgrade weaponUpgrade(
        WarScroll::Weapon("Enchanted Polearm", 1, 3, 3, 3, 1, 3),
        WarScroll::Ability());
      ws.addWeaponUpgrade(weaponUpgrade);
    }
    {
      WarScroll::WeaponUpgrade weaponUpgrade(
        WarScroll::Weapon("Starblade", 1, 6, 3, 4, 0, 1),
        WarScroll::Ability("Enchanted Shield", 1));
      ws.addWeaponUpgrade(weaponUpgrade);
    }
    {
      WarScroll::WeaponUpgrade weaponUpgrade(
        WarScroll::Weapon("Enchanted Polearm", 1, 3, 3, 3, 1, 3),
        WarScroll::Ability("Enchanted Shield", 1));
      ws.addWeaponUpgrade(weaponUpgrade);
    }
    {
      WarScroll::WeaponUpgrade weaponUpgrade(
        WarScroll::Weapon("Starblade", 1, 6, 3, 4, 0, 1),
        WarScroll::Ability());
      weaponUpgrade.setSecondaryWeapon(WarScroll::Weapon(
        "Reaver Bow", 20, 3, 3, 3, 0, 1));
      ws.addWeaponUpgrade(weaponUpgrade);
    }
    {
      WarScroll::WeaponUpgrade weaponUpgrade(
        WarScroll::Weapon("Enchanted Polearm", 1, 3, 3, 3, 1, 3),
        WarScroll::Ability());
      weaponUpgrade.setSecondaryWeapon(WarScroll::Weapon(
        "Reaver Bow", 20, 3, 3, 3, 0, 1));
      ws.addWeaponUpgrade(weaponUpgrade);
    }

    {
      WarScroll::MountUpgrade elvenPurebread(
        "Elven Purebred");
      elvenPurebread.registerCharacteristicToIncrease("Move", 6);
      elvenPurebread.addRiderAbilityToRemove(WarScroll::Ability(
        "Enchanted Shield", 1));
      elvenPurebread.addAbility(WarScroll::Ability("Elven Purebred", 1));
      elvenPurebread.addWeapon(WarScroll::Weapon(
        "Purebreed's Ithilmar-shod Hooves", 1, 2, 4, 4, 0, 1));
      ws.registerMountUpgrade(elvenPurebread);
    }

    {
      WarScroll::MountUpgrade elvenPurebread(
        "Elven Purebred with Lance");
      elvenPurebread.registerCharacteristicToIncrease("Move", 6);
      elvenPurebread.addRiderWeaponToReplace(WarScroll::Weapon(
        "Starblade", 1, 6, 3, 4, 0, 1));
      elvenPurebread.addRiderWeaponToReplace(WarScroll::Weapon(
        "Enchanted Polearm", 1, 3, 3, 3, 1, 3));
      elvenPurebread.addRiderWeaponToReplace(WarScroll::Weapon(
        "Reaver Bow", 20, 3, 3, 3, 0, 1));
      elvenPurebread.addRiderAbilityToRemove(WarScroll::Ability(
        "Enchanted Shield", 1));
      elvenPurebread.addAbility(WarScroll::Ability("Elven Purebred", 1));
      elvenPurebread.addWeapon(WarScroll::Weapon(
        "Purebreed's Ithilmar-shod Hooves", 1, 2, 4, 4, 0, 1));
      elvenPurebread.addWeapon(WarScroll::Weapon(
        "Star Lance", 2, 3, 3, 4, 1, 2));
      elvenPurebread.addAbility(WarScroll::Ability("Star Lance", 1));
      ws.registerMountUpgrade(elvenPurebread);
    }

    {
      WarScroll::MountUpgrade elvenPurebread(
        "Elven Purebred with Lance and Shield");
      elvenPurebread.registerCharacteristicToIncrease("Move", 6);
      elvenPurebread.addRiderWeaponToReplace(WarScroll::Weapon(
        "Starblade", 1, 6, 3, 4, 0, 1));
      elvenPurebread.addRiderWeaponToReplace(WarScroll::Weapon(
        "Enchanted Polearm", 1, 3, 3, 3, 1, 3));
      elvenPurebread.addRiderWeaponToReplace(WarScroll::Weapon(
        "Reaver Bow", 20, 3, 3, 3, 0, 1));
      elvenPurebread.addRiderAbilityToRemove(WarScroll::Ability(
        "Enchanted Shield", 1));
      elvenPurebread.addAbility(WarScroll::Ability("Elven Purebred", 1));
      elvenPurebread.addWeapon(WarScroll::Weapon(
        "Purebreed's Ithilmar-shod Hooves", 1, 2, 4, 4, 0, 1));
      elvenPurebread.addWeapon(WarScroll::Weapon(
        "Star Lance", 2, 3, 3, 4, 1, 2));
      elvenPurebread.addAbility(WarScroll::Ability("Star Lance", 1));
      elvenPurebread.addAbility(WarScroll::Ability("Enchanted Shield", 1));
      ws.registerMountUpgrade(elvenPurebread);
    }

    {
      WarScroll::MountUpgrade elvenPurebread(
        "Elven Purebred with Lance and Reaver Bow");
      elvenPurebread.registerCharacteristicToIncrease("Move", 6);
      elvenPurebread.addRiderWeaponToReplace(WarScroll::Weapon(
        "Starblade", 1, 6, 3, 4, 0, 1));
      elvenPurebread.addRiderWeaponToReplace(WarScroll::Weapon(
        "Enchanted Polearm", 1, 3, 3, 3, 1, 3));
      elvenPurebread.addRiderWeaponToReplace(WarScroll::Weapon(
        "Reaver Bow", 20, 3, 3, 3, 0, 1));
      elvenPurebread.addRiderAbilityToRemove(WarScroll::Ability(
        "Enchanted Shield", 1));
      elvenPurebread.addAbility(WarScroll::Ability("Elven Purebred", 1));
      elvenPurebread.addWeapon(WarScroll::Weapon(
        "Purebreed's Ithilmar-shod Hooves", 1, 2, 4, 4, 0, 1));
      elvenPurebread.addWeapon(WarScroll::Weapon(
        "Star Lance", 2, 3, 3, 4, 1, 2));
      elvenPurebread.addAbility(WarScroll::Ability("Star Lance", 1));
      elvenPurebread.addWeapon(WarScroll::Weapon(
        "Reaver Bow", 20, 3, 3, 3, 0, 1));
      ws.registerMountUpgrade(elvenPurebread);
    }

    WarScroll::UnitUpgrade phoenixBanner("Phoenix Banner",
      WarScroll::UnitUpgrade::UnitUpgradeType::eBannerBearer, 1);
    phoenixBanner.addAbility(WarScroll::Ability("Phoenix Banner", 2));
    ws.registerUnitUpgrade(phoenixBanner);

    ws.addAbility(WarScroll::Ability("Might of the Asur", 1, true));

    ws.addKeyWords({"ORDER", "AELF", "HIGHBORN", "HERO", "HIGH ELF PRINCE"});

    return ws;
  }

  WarScroll High_Elf_Prince_on_Griffon(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(16, 10, 8, 4);

    ws.addWeapon(WarScroll::Weapon("Starwood Lance", 2, 2, 3, 4, 1, 2));
    ws.addWeapon(WarScroll::Weapon("Starblade", 1, 4, 3, 4, 0, 1));
    ws.addWeapon(WarScroll::Weapon("Griffon's Razor-sharp Beak",
      2, 1, 3, 3, 1, 6));
    ws.addWeapon(WarScroll::Weapon("Griffon's Wicked Talons",
      2, 6, 4, 3, 1, 1));

    ws.setCanFly(true);

    ws.addAbility(WarScroll::Ability("Predatory Leap", 2));
    ws.addAbility(WarScroll::Ability("Starwood Lance", 1));
    ws.addAbility(WarScroll::Ability("Glittering Charge", 1, true));

    ws.addKeyWords({"ORDER", "AELF", "GRIFFON", "HIGHBORN", "HERO", "MONSTER",
      "HIGH ELF PRINCE"});

    return ws;
  }

  WarScroll High_Elf_Prince_on_Dragon(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(14, 14, 8, 4);

    ws.addWeapon(WarScroll::Weapon("Dragon's Claws",
      2, 6, 4, 3, 1, 2));
    ws.addWeapon(WarScroll::Weapon("Dragon's Fearsome Jaws",
      3, 3, 4, 2, 2, 6));

    {
      WarScroll::WeaponUpgrade weaponUpgrade(
        WarScroll::Weapon("Dragon Blade", 2, 4, 3, 3, 1, 3),
        WarScroll::Ability("Enchanted Shield", 1));
      ws.addWeaponUpgrade(weaponUpgrade);
    }
    {
      WarScroll::WeaponUpgrade weaponUpgrade(
        WarScroll::Weapon("Dragon Lance", 2, 3, 3, 3, 1, 2),
        WarScroll::Ability("Enchanted Shield", 1));
      weaponUpgrade.addAbility(WarScroll::Ability("Dragon Lance", 1));
      ws.addWeaponUpgrade(weaponUpgrade);
    }
    {
      WarScroll::WeaponUpgrade weaponUpgrade(
        WarScroll::Weapon("Dragon Blade", 2, 4, 3, 3, 1, 3),
        WarScroll::Ability());
      weaponUpgrade.setSecondaryWeapon(WarScroll::Weapon(
        "Reaver Bow", 20, 3, 3, 3, 0, 1));
      ws.addWeaponUpgrade(weaponUpgrade);
    }
    {
      WarScroll::WeaponUpgrade weaponUpgrade(
        WarScroll::Weapon("Dragon Lance", 2, 3, 3, 3, 1, 2),
        WarScroll::Ability());
      weaponUpgrade.setSecondaryWeapon(WarScroll::Weapon(
        "Reaver Bow", 20, 3, 3, 3, 0, 1));
      weaponUpgrade.addAbility(WarScroll::Ability("Dragon Lance", 1));
      ws.addWeaponUpgrade(weaponUpgrade);
    }

    ws.setCanFly(true);

    ws.addAbility(WarScroll::Ability("Elven War Horn", 1));
    ws.addAbility(WarScroll::Ability("Dragonfire", 3));
    ws.addAbility(WarScroll::Ability("First Amongst Equals", 2, true));

    ws.addKeyWords({"ORDER", "AELF", "DRAGON", "HIGHBORN", "HERO", "MONSTER",
      "HIGH ELF PRINCE"});

    return ws;
  }

  WarScroll High_Elf_Archmage_on_Dragon(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(14, 14, 7, 5);

    ws.addWeapon(WarScroll::Weapon("Dragon's Claws", 2, 6, 4, 3, 1, 2));
    ws.addWeapon(WarScroll::Weapon("Dragon's Fearsome Jaws", 3, 3, 4, 2, 2, 6));

    {
      WarScroll::WeaponUpgrade weaponUpgrade(
        WarScroll::Weapon("Magestaff", 2, 1, 4, 3, 1, 3),
        WarScroll::Ability("Book of Hoeth", 0));
      ws.addWeaponUpgrade(weaponUpgrade);
    }

    {
      WarScroll::WeaponUpgrade weaponUpgrade(
        WarScroll::Weapon("Magestaff", 2, 1, 4, 3, 1, 3),
        WarScroll::Ability());
      weaponUpgrade.setSecondaryWeapon(WarScroll::Weapon("Sword of Saphery",
        1, 3, 4, 4, 0, 1));
      ws.addWeaponUpgrade(weaponUpgrade);
    }

    ws.setCanFly(true);

    ws.addAbility(WarScroll::Ability("Talisman of Arcane Power", 1));
    ws.addAbility(WarScroll::Ability("Dragonfire", 3));

    ws.addSpell(WarScroll::Spell("Drain Magic"), 4, 2);

    ws.addKeyWords({"ORDER", "AELF", "DRAGON", "HIGHBORN", "HERO", "WIZARD",
      "MONSTER", "HIGH ELF ARCHMAGE"});

    return ws;
  }

  WarScroll High_Elf_Mage(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(6, 5, 7, 6);

    ws.addWeapon(WarScroll::Weapon("Seerstaff", 2, 1, 4, 3, 1, 1));

    WarScroll::MountUpgrade steed("Elven Steed");
    steed.registerCharacteristicToIncrease("Move", 8);
    steed.addWeapon(WarScroll::Weapon("Elven Steed's Swift Hooves",
      1, 2, 4, 5, 0, 1));
    ws.registerMountUpgrade(steed);

    ws.addAbility(WarScroll::Ability("Talisman of Arcane Power", 1));
    ws.addSpell(WarScroll::Spell("Shield of Saphery"), 7, 3);

    ws.addKeyWords({"ORDER", "AELF", "HIGHBORN", "HERO", "WIZARD",
      "HIGH ELF MAGE"});

    return ws;
  }

  WarScroll Dragon_Mage(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(14, 14, 7, 5);

    ws.addWeapon(WarScroll::Weapon("Mage's Sunstaff", 2, 1, 4, 3, 1, 3));
    ws.addWeapon(WarScroll::Weapon("Dragon's Claws", 2, 6, 4, 3, 1, 2));
    ws.addWeapon(WarScroll::Weapon("Dragon's Fearsome Jaws", 3, 3, 4, 2, 2, 6));

    ws.setCanFly(true);

    ws.addAbility(WarScroll::Ability("Warrior Mage", 1));
    ws.addAbility(WarScroll::Ability("Dragonfire", 3));

    ws.addSpell(WarScroll::Spell("Flames of the Phoenix"), 7, 3);

    ws.addKeyWords({"ORDER", "AELF", "DRAGON", "HIGHBORN", "HERO", "WIZARD",
      "MONSTER", "DRAGON MAGE"});

    return ws;
  }

  WarScroll High_Elf_Spearmen(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(6, 1, 6, 5);

    ws.addWeapon(WarScroll::Weapon("Silverwood Spear", 2, 1, 4, 4, 0, 1));

    ws.setMinMaxUnitCount(10, IFaction::s_MaxUnitSize);

    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Sentinel",
      WarScroll::UnitUpgrade::UnitUpgradeType::eChampion, 1));
    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Standard Bearer",
      WarScroll::UnitUpgrade::UnitUpgradeType::eBannerBearer, 1));
    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Hornblower",
      WarScroll::UnitUpgrade::UnitUpgradeType::eMusician, 1));

    ws.addAbility(WarScroll::Ability("Elven Shield", 1));
    ws.addAbility(WarScroll::Ability("Militia", 1));
    ws.addAbility(WarScroll::Ability("Spear Phalanx", 1));

    ws.addKeyWords({"ORDER", "AELF", "HIGHBORN", "HIGH ELF SPEARMEN"});

    return ws;
  }

  WarScroll High_Elf_Archers(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(6, 1, 6, 6);

    ws.addWeapon(WarScroll::Weapon("Silverwood Longbow", 20, 1, 4, 4, 0, 1));
    ws.addWeapon(WarScroll::Weapon("Silverwood Longbow", 1, 1, 5, 5, 0, 1));

    ws.setMinMaxUnitCount(10, IFaction::s_MaxUnitSize);

    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Hawkeye",
      WarScroll::UnitUpgrade::UnitUpgradeType::eChampion, 1));
    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Standard Bearer",
      WarScroll::UnitUpgrade::UnitUpgradeType::eBannerBearer, 1));
    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Hornblower",
      WarScroll::UnitUpgrade::UnitUpgradeType::eMusician, 1));

    ws.addAbility(WarScroll::Ability("Elven Archery", 1));
    ws.addAbility(WarScroll::Ability("Storm of Arrows", 2));

    ws.addKeyWords({"ORDER", "AELF", "HIGHBORN", "HIGH ELF ARCHERS"});

    return ws;
  }

  WarScroll Silver_Helms(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(12 ,2, 7, 4);

    ws.addWeapon(WarScroll::Weapon("Ithilmar Lance and Sword",
      1, 1, 4, 4, 0, 1));
    ws.addWeapon(WarScroll::Weapon("Elven Purebreed's Swift Hooves",
      1, 2, 4, 5, 0, 1));

    ws.setMinMaxUnitCount(5, IFaction::s_MaxUnitSize);

    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("High Helm",
      WarScroll::UnitUpgrade::UnitUpgradeType::eChampion, 1));
    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Standard Bearer",
      WarScroll::UnitUpgrade::UnitUpgradeType::eBannerBearer, 1));
    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Hornblower",
      WarScroll::UnitUpgrade::UnitUpgradeType::eMusician, 1));

    ws.addAbility(WarScroll::Ability("Elven Shield", 1));
    ws.addAbility(WarScroll::Ability("Lance Charge", 1));
    ws.addAbility(WarScroll::Ability("Knights of Ulthuan", 1));

    ws.addKeyWords({"ORDER", "AELF", "HIGHBORN", "SILVER HELMS"});

    return ws;
  }

  WarScroll Ellyrian_Reavers(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(14, 2, 6, 5);

    ws.addWeapon(WarScroll::Weapon("Reaver Cavalry Bow", 16, 2, 4, 4, 0, 1));
    ws.addWeapon(WarScroll::Weapon("Starwood Spear", 1, 1, 4, 4, 0, 1));
    ws.addWeapon(WarScroll::Weapon("Ellyrian Purebreed's Swift Hooves",
      1, 2, 4, 5, 0, 1));

    ws.setMinMaxUnitCount(5, IFaction::s_MaxUnitSize);

    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Harbinger",
      WarScroll::UnitUpgrade::UnitUpgradeType::eChampion, 1));

    ws.addAbility(WarScroll::Ability("Ellyrian Purebreeds", 2));
    ws.addAbility(WarScroll::Ability("Swift Volleys", 2));

    ws.addKeyWords({"ORDER", "AELF", "HIGHBORN", "ELLYRIAN REAVERS"});

    return ws;
  }

  WarScroll Dragon_Princes_of_Caledor(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(12, 2, 7, 4);

    ws.addWeapon(WarScroll::Weapon("Drake Lance and Sword", 1, 2, 3, 4, 0, 1));
    ws.addWeapon(WarScroll::Weapon("Purebreed's Ithilmar-shod Hooves",
      1, 2, 4, 4, 0, 1));

    ws.setMinMaxUnitCount(5, IFaction::s_MaxUnitSize);

     ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Drakemaster",
      WarScroll::UnitUpgrade::UnitUpgradeType::eChampion, 1));
    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Standard Bearer",
      WarScroll::UnitUpgrade::UnitUpgradeType::eBannerBearer, 1));
    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Hornblower",
      WarScroll::UnitUpgrade::UnitUpgradeType::eMusician, 1));

    ws.addAbility(WarScroll::Ability("Lance Charge", 1));
    ws.addAbility(WarScroll::Ability("Drake Shield", 1));
    ws.addAbility(WarScroll::Ability("Arrogant Pride", 1));

    ws.addKeyWords({"ORDER", "AELF", "HIGHBORN", "DRAGON PRINCES OF CALEDOR"});

    return ws;
  }

  WarScroll Tiranoc_Chariots(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(12, 5, 6, 5);

    ws.addWeapon(WarScroll::Weapon("Charioteer's Bows", 18, 2, 4, 4, 0, 1));
    ws.addWeapon(WarScroll::Weapon("Tiranoc Spears", 2, 2, 4, 4, 0, 1));
    ws.addWeapon(WarScroll::Weapon("Ellyrian Purebreeds' Swift Hooves",
      1, 4, 4, 5, 0, 1));

    ws.addAbility(WarScroll::Ability("Graceful Charge", 1));
    ws.addAbility(WarScroll::Ability("Swift and Deadly", 2));

    ws.addKeyWords({"ORDER", "AELF", "HIGHBORN", "TIRANOC CHARIOTS"});

    return ws;
  }

  WarScroll High_Elf_Repeater_Bolt_Thrower(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(4, 4, 10, 5);

    ws.addWeapon(WarScroll::Weapon("Ithilmar Bolt", 36, 1, 3, 3, 2, 3));
    ws.addWeapon(WarScroll::Weapon("Repeating Bolts", 36, 6, 4, 3, 1, 1));
    ws.addWeapon(WarScroll::Weapon("Ithilmar Blade", 1, 2, 4, 4, 0, 1));

    ws.addAbility(WarScroll::Ability("Crewed War Machine", 1));
    ws.addAbility(WarScroll::Ability("Bolt Selection", 1));

    ws.addKeyWords({"ORDER", "WAR MACHINE", "REPEATER BOLT THROWER", "AELF",
      "HIGHBORN", "CREW"});

    return ws;
  }

  WarScroll Great_Eagles_in_High_Elves(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(16, 4, 6, 6);

    ws.addWeapon(WarScroll::Weapon("Beak and Talons", 2, 4, 3, 0, 1));

    ws.setMinMaxUnitCount(1, IFaction::s_MaxUnitSize);

    ws.setCanFly(true);

    ws.addAbility(WarScroll::Ability("Death fro the Skies", 2));
    ws.addAbility(WarScroll::Ability("Soar Away", 3));

    ws.addKeyWords({"ORDER", "GREAT EAGLES"});

    return ws;
  }

  WarScroll Alith_Anar_The_Shadow_King(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(6, 5, 8, 4);

    ws.addWeapon(WarScroll::Weapon("The Moonbow", 24, 3, 3, 3, 1, 3));
    ws.addWeapon(WarScroll::Weapon("Ithilmar Longsword", 1, 4, 3, 4, 0, 1));

    ws.addAbility(WarScroll::Ability("One With the Shadows", 2));
    ws.addAbility(WarScroll::Ability("The Shadow Crown", 1));
    ws.addAbility(WarScroll::Ability("The Stone of Midnight", 2));
    ws.addAbility(WarScroll::Ability("Vengeance From Afar", 1));

    ws.addKeyWords({"ORDER", "AELF", "HIGHBORN", "HERO", "ALITH"});

    return ws;
  }

  WarScroll Shadow_Warriors(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(6, 1, 6, 5);

    ws.addWeapon(WarScroll::Weapon("Nagarythe Bow", 1, 3, 4, 0, 1));
    ws.addWeapon(WarScroll::Weapon("Shadow Blade", 1, 2, 3, 4, 0, 1));

    ws.setMinMaxUnitCount(5, IFaction::s_MaxUnitSize);

    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Shadow Walker",
      WarScroll::UnitUpgrade::UnitUpgradeType::eChampion, 1));

    ws.addAbility(WarScroll::Ability("One With the Shadows", 2));
    ws.addAbility(WarScroll::Ability("Strke Unseen", 2));
    ws.addAbility(WarScroll::Ability("The Shadow King's Warriors", 2));

    ws.addKeyWords({"ORDER", "AELF", "HIGHBORN", "SHADOW", "WARRIORS"});

    return ws;
  }

  WarScroll Alarielle_the_Radiant(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(6, 5, 8, 5);

    ws.addWeapon(WarScroll::Weapon("The Stave of Avelorn", 2, 1, 4, 3, 0, 3));

    ws.addAbility(WarScroll::Ability("The Everqueen", 3));
    ws.addAbility(WarScroll::Ability("Bane of Chaos", 2));
    ws.addAbility(WarScroll::Ability("Star of Avelorn", 2));

    ws.addSpell(WarScroll::Spell("Boon of Life"), 6, 3);

    ws.addKeyWords({"ORDER", "AELF", "HIGHBORN", "HERO", "WIZARD",
      "ALARIELLE THE RADIANT"});

    return ws;
  }

  WarScroll Handmaiden_of_the_Everqueen(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(6, 5, 7, 5);

    ws.addWeapon(WarScroll::Weapon("Bow of Isha", 18, 2, 3, 3, 0, 1));
    ws.addWeapon(WarScroll::Weapon("Guardian Spear", 2, 4, 4, 4, 0, 1));

    ws.addAbility(WarScroll::Ability("Arrows of Isha", 2));
    ws.addAbility(WarScroll::Ability("Quicksilver Shot", 1));
    ws.addAbility(WarScroll::Ability("The Everqueen's Favour", 2));

    ws.addKeyWords({"ORDER", "AELF", "HIGHBORN", "HERO",
      "HANDMAIDEN OF THE EVERQUEEN"});

    return ws;
  }

  WarScroll Sisters_of_Avelorn(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(6, 1, 7, 5);

    ws.addWeapon(WarScroll::Weapon("Bow of Avelorn", 18, 1, 3, 3, 0, 1));
    ws.addWeapon(WarScroll::Weapon("Ithilmar Sword", 1, 1, 4, 4, 0, 1));

    ws.setMinMaxUnitCount(5, IFaction::s_MaxUnitSize);

    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("High Sister",
      WarScroll::UnitUpgrade::UnitUpgradeType::eChampion, 1));

    ws.addAbility(WarScroll::Ability("Arrows of Isha", 2));
    ws.addAbility(WarScroll::Ability("Quicksilver Shot", 1));
    ws.addAbility(WarScroll::Ability("Loose Until the Last", 2));
    ws.addAbility(WarScroll::Ability("Paragons of the Maiden Guard", 1));

    ws.addKeyWords({"ORDER", "AELF", "HIGHBORN", "SISTERS OF AVELORN"});

    return ws;
  }

  WarScroll Caradryan(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Anointed_of_Asuryan(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Phoenix_Guard(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Flamespyre_Phoenix(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Frostheart_Phoenix(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Loremaster_of_Hoeth(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll High_Elf_Swordmasters_of_Hoeth(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Korhil(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll White_Lions_of_Chrace(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll White_Lion_Chariots(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Lothern_Sea_Helm(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Lothern_Sea_Helm_on_Skycutter(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Lothern_Sea_Guard(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Lothern_Skycutters(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }
}

HighElvesFaction::HighElvesFaction() :
  IFaction(nullptr)
{
  m_Units.push_back("");
  m_Units.push_back("Tyrion");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Tyrion, m_Units.back())));
  m_Units.push_back("Teclis");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Teclis, m_Units.back())));
  m_Units.push_back("Eltharion on Stormwing");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Eltharion_on_Stormwing, m_Units.back())));
  m_Units.push_back("Prince Imrik, Dragonlord");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Prince_Imrik_Dragonlord, m_Units.back())));
  m_Units.push_back("Prince Althran");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Prince_Althran, m_Units.back())));
  m_Units.push_back("High Elf Prince");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::High_Elf_Prince, m_Units.back())));
  m_Units.push_back("High Elf Prince on Griffon");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::High_Elf_Prince_on_Griffon,
    m_Units.back())));
  m_Units.push_back("High Elf Prince on Dragon");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::High_Elf_Prince_on_Dragon,
    m_Units.back())));
  m_Units.push_back("High Elf Archmage on Dragon");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::High_Elf_Archmage_on_Dragon,
    m_Units.back())));
  m_Units.push_back("High Elf Mage");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::High_Elf_Mage, m_Units.back())));
  m_Units.push_back("Dragon Mage");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Dragon_Mage, m_Units.back())));
  m_Units.push_back("High Elf Spearmen");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::High_Elf_Spearmen, m_Units.back())));
  m_Units.push_back("High Elf Archers");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::High_Elf_Archers, m_Units.back())));
  m_Units.push_back("Silver Helms");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Silver_Helms, m_Units.back())));
  m_Units.push_back("Ellyrian Reavers");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Ellyrian_Reavers, m_Units.back())));
  m_Units.push_back("Dragon Princes of Caledor");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Dragon_Princes_of_Caledor,
    m_Units.back())));
  m_Units.push_back("Tiranoc Chariots");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Tiranoc_Chariots, m_Units.back())));
  m_Units.push_back("High Elf Repeater Bolt Thrower");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::High_Elf_Repeater_Bolt_Thrower,
    m_Units.back())));
  m_Units.push_back("Great Eagles");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Great_Eagles_in_High_Elves,
    m_Units.back())));
  m_Units.push_back("Alith Anar, The Shadow King");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Alith_Anar_The_Shadow_King,
    m_Units.back())));
  m_Units.push_back("Shadow Warriors");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Shadow_Warriors, m_Units.back())));
  m_Units.push_back("Alarielle the Radiant");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Alarielle_the_Radiant, m_Units.back())));
  m_Units.push_back("Handmaiden of the Everqueen");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Handmaiden_of_the_Everqueen,
    m_Units.back())));
  m_Units.push_back("Sisters of Avelorn");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Sisters_of_Avelorn, m_Units.back())));
  m_Units.push_back("Caradryan");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Caradryan, m_Units.back())));
  m_Units.push_back("Anointed of Asuryan");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Anointed_of_Asuryan, m_Units.back())));
  m_Units.push_back("Phoenix Guard");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Phoenix_Guard, m_Units.back())));
  m_Units.push_back("Flamespyre Phoenix");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Flamespyre_Phoenix, m_Units.back())));
  m_Units.push_back("Frostheart Phoenix");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Frostheart_Phoenix, m_Units.back())));
  m_Units.push_back("Loremaster of Hoeth");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Loremaster_of_Hoeth, m_Units.back())));
  m_Units.push_back("High Elf Swordmasters of Hoeth");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::High_Elf_Swordmasters_of_Hoeth,
    m_Units.back())));
  m_Units.push_back("Korhil");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Korhil, m_Units.back())));
  m_Units.push_back("White Lions of Chrace");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::White_Lions_of_Chrace, m_Units.back())));
  m_Units.push_back("White Lion Chariots");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::White_Lion_Chariots, m_Units.back())));
  m_Units.push_back("Lothern Sea Helm");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Lothern_Sea_Helm, m_Units.back())));
  m_Units.push_back("Lothern Sea Helm on Skycutter");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Lothern_Sea_Helm_on_Skycutter,
    m_Units.back())));
  m_Units.push_back("Lothern Sea Guard");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Lothern_Sea_Guard, m_Units.back())));
  m_Units.push_back("Lothern Skycutters");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Lothern_Skycutters, m_Units.back())));
}

const std::vector<std::string> &HighElvesFaction::getUnits() const
{
  return m_Units;
}

void HighElvesFaction::getWarScrolls(std::list<WarScroll>& warScrolls)
{
  for (const std::string &unit : m_Units) {
    if (unit.empty()) {
      continue;
    }
    WarScroll ws = m_NameToWarScroll[unit](unit);
    warScrolls.push_back(ws);
  }
}
