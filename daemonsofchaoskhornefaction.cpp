#include "daemonsofchaoskhornefaction.h"

namespace WarScrollGeneration
{
  WarScroll Bloodthirster_of_Insensate_Rage(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    ws.setCharacteristics(10, 14, 10, 4);
    ws.setCanFly(true);

    ws.addWeapon(WarScroll::Weapon("Great Axe of Khorne", 2, 4, 4, 2, 2, 6));

    ws.addAbility(WarScroll::Ability("Rage Unbound", 1));
    ws.addAbility(WarScroll::Ability("Outrageous Carnage", 2));
    ws.addAbility(WarScroll::Ability("Bloodthirsty Charge", 2, true));

    ws.addKeyWords({"CHAOS", "DAEMON", "KHORNE", "MONSTER", "HERO",
      "BLOODTHIRSTER OF INSENSATE RAGE"});

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eChaos);
    return ws;
  }

  WarScroll Bloodthirster_of_Unfettered_Fury(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    ws.setCharacteristics(10, 14, 10, 4);
    ws.setCanFly(true);

    ws.addWeapon(WarScroll::Weapon("Lash of Khorne", 8, 4, 4, 3, 1, 3));
    ws.addWeapon(WarScroll::Weapon("Mighty Axe of Khorne", 2, 6, 3, 2, 3));

    ws.addAbility(WarScroll::Ability("Drawn In for the Kill", 1));
    ws.addAbility(WarScroll::Ability("The Land Rebels", 2));
    ws.addAbility(WarScroll::Ability("Rejoice in the Slaughter", 2, true));

    ws.addKeyWords({"CHAOS, DAEMON", "KHORNE", "MONSTER", "HERO",
      "BLOODTHIRSTER OF UNFETTERED FURY"});

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eChaos);
    return ws;
  }

  WarScroll Wrath_of_Khorne_Bloodthirster(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    ws.setCharacteristics(10, 14, 10, 4);
    ws.setCanFly(true);

    ws.addWeapon(WarScroll::Weapon("Hellfire Breath", 8, 1, 1, 1, 0, 3));
    ws.addWeapon(WarScroll::Weapon("Bloodflail", 12, 1, 3, 3, 1, 6));
    ws.addWeapon(WarScroll::Weapon("Mighty Axe of Khorne", 2, 6, 3, 2, 2, 3));

    ws.addAbility(WarScroll::Ability("Hellfire Breath", 2));
    ws.addAbility(WarScroll::Ability("Relentless Hunter", 1));
    ws.addAbility(WarScroll::Ability("Rune-crown of Khorne", 2));
    ws.addAbility(WarScroll::Ability("Lord of the Blood Hunt", 2, true));

    ws.addKeyWords({"CHAOS", "DAEMON", "KHORNE", "MONSTER", "HERO"
      "WRATH OF KHORNE BLOODTHIRSTER"});

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eChaos);
    return ws;
  }

  WarScroll Skulltaker(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    ws.setCharacteristics(5, 5, 10, 4);

    ws.addWeapon(WarScroll::Weapon("The Slayer Sword", 1, 3, 3, 3, 1, 3));

    ws.addAbility(WarScroll::Ability("Cloak of Skulls", 2));
    ws.addAbility(WarScroll::Ability("Decapitatin Strike", 3));
    ws.addAbility(WarScroll::Ability("Skulls for Khorne", 1));

    ws.addKeyWords({"CHAOS", "DAEMON", "BLOODLETTER", "KHORNE", "HERO",
      "SKULLTAKER"});

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eChaos);
    return ws;
  }

  WarScroll Herald_of_Khorne(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    ws.setCharacteristics(5, 5, 10, 4);

    ws.addWeapon(WarScroll::Weapon("Blade of Blood", 1, 4, 3, 3, 1, 1));

    ws.addAbility(WarScroll::Ability("Decapitating Blow", 1));
    ws.addAbility(WarScroll::Ability("The Blood Must Flow", 2));

    ws.addKeyWords({"CHAOS", "DAEMON", "BLOODLETTER", "KHORNE", "HERO",
      "HERALD OF KHORNE"});

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eChaos);
    return ws;
  }

  WarScroll Herald_of_Khorne_on_Juggernaut(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    ws.setCharacteristics(8, 6, 10, 4);

    ws.addWeapon(WarScroll::Weapon("Blade of Blood", 1, 4, 3, 3, 1, 1));
    ws.addWeapon(WarScroll::Weapon("Juggernaut's Brazen Hooves",
      1, 3, 3, 3, 0, 1));

    ws.addAbility(WarScroll::Ability("Murderous Charge", 2));
    ws.addAbility(WarScroll::Ability("Slaughter and Ruin", 1));

    ws.addKeyWords({"CHAOS", "DAEMON", "BLOODLETTER", "KHORNE", "HERO",
      "HERALD ON JUGGERNAUT"});

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eChaos);
    return ws;
  }

  WarScroll Blood_Throne_of_Khorne(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    ws.setCharacteristics(8, 7, 10, 4);

    ws.addWeapon(WarScroll::Weapon("Blade of Blood", 1, 4, 3, 3, 1, 1));
    ws.addWeapon(WarScroll::Weapon("Hellblades", 1, 2, 4, 3, 1, 1));
    ws.addWeapon(WarScroll::Weapon("Gnashing Maw", 1, 1, 4, 3, 1, 3));

    ws.addAbility(WarScroll::Ability("Gorefeast", 2));
    ws.addAbility(WarScroll::Ability("Decapitating Blow", 1));

    ws.addKeyWords({"CHAOS", "DAEMON", "BLOODLETTER", "KHORNE", "HERO",
      "BLOOD THRONE"});

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eChaos);
    return ws;
  }

  WarScroll Bloodletters_of_Khorne(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    ws.setCharacteristics(5, 1, 10, 5);
    ws.setMinMaxUnitCount(10, IFaction::s_MaxUnitSize);

    ws.addWeapon(WarScroll::Weapon("Hellblade", 1, 1, 4, 3, 1, 1));

    ws.addAbility(WarScroll::Ability("Decapitating Blow", 1));
    ws.addAbility(WarScroll::Ability("Murderous Tide", 1));                     // Conditional on Unit Size > 20
    ws.addAbility(WarScroll::Ability("Locus of Fury", 1));

    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Bloodhunter",
      WarScroll::UnitUpgrade::UnitUpgradeType::eChampion, 1));

    WarScroll::UnitUpgrade iconGoreBearer("Icon Bearer/Gore-drenched",
      WarScroll::UnitUpgrade::UnitUpgradeType::eBannerBearer, 2);
    iconGoreBearer.addAbility(WarScroll::Ability("Gore-drenched Icon", 3));
    ws.registerUnitUpgrade(iconGoreBearer);

    WarScroll::UnitUpgrade iconBloodBearer("Icon Bearer/Bloodsoaked",
      WarScroll::UnitUpgrade::UnitUpgradeType::eBannerBearer, 2);
    iconBloodBearer.addAbility(WarScroll::Ability("Bloodsoaked Banner", 1));
    ws.registerUnitUpgrade(iconBloodBearer);

    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Hornblower",
      WarScroll::UnitUpgrade::UnitUpgradeType::eMusician, 2));

    ws.addKeyWords({"CHAOS", "DAEMON", "KHORNE", "BLOODLETTERS"});

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eChaos);

    return ws;
  }

  WarScroll Bloodcrushers_of_Khorne(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    ws.setCharacteristics(8, 4, 10, 4);
    ws.setMinMaxUnitCount(3, IFaction::s_MaxUnitSize);

    ws.addWeapon(WarScroll::Weapon("Hellblade", 1, 1, 4, 3, 1, 1));
    ws.addWeapon(WarScroll::Weapon("Juggernaut's Brazen Hooves",
      1, 3, 3, 3, 0, 1));

    ws.addAbility(WarScroll::Ability("Decapitating Blow", 1));
    ws.addAbility(WarScroll::Ability("Murderous Charge", 1));
    ws.addAbility(WarScroll::Ability("Locus of Wrath", 1));

    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Bloodhunter",
      WarScroll::UnitUpgrade::UnitUpgradeType::eChampion, 1));
    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Icon Bearer",
      WarScroll::UnitUpgrade::UnitUpgradeType::eBannerBearer, 2));
    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Hornblower",
      WarScroll::UnitUpgrade::UnitUpgradeType::eMusician, 1));

    ws.addKeyWords({"CHAOS", "DAEMON", "BLOODLETTER", "KHORNE",
      "BLOODCRUSHERS"});

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eChaos);
    return ws;
  }

  WarScroll Karanak(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    ws.setCharacteristics(8, 5, 10, 4);

    ws.addWeapon(WarScroll::Weapon("Gore-slick Claws", 1, 4, 3, 4, 0, 1));
    ws.addWeapon(WarScroll::Weapon("Savage Maws", 1, 2, 4, 3, 1, 3));

    ws.addAbility(WarScroll::Ability("Brass Collar of Bloody Vengeance", 3));
    ws.addAbility(WarScroll::Ability("Prey of the Blood God", 1));
    ws.addAbility(WarScroll::Ability("Call of the Hunt", 2));

    ws.addKeyWords({"CHAOS", "DAEMONS", "KHORNE", "FLESH HOUND", "KARANAK"});

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eChaos);
    return ws;
  }

  WarScroll Flesh_Hounds_of_Khorne(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    ws.setCharacteristics(8, 2, 10, 5);
    ws.setMinMaxUnitCount(5, IFaction::s_MaxUnitSize);

    ws.addWeapon(WarScroll::Weapon("Blood-dark Claws", 1, 4, 3, 4, 0, 1));

    ws.addAbility(WarScroll::Ability("Collars of Khorne", 1));                  // Conditional on Unit Size > 20
    ws.addAbility(WarScroll::Ability("Tireless Hunters", 1));
    ws.addAbility(WarScroll::Ability("Locus of Abjuration", 1));

    ws.addKeyWords({"CHAOS", "DAEMON", "KHORNE", "FLESH HOUNDS"});

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eChaos);
    return ws;
  }

  WarScroll Skull_Cannons_of_Khorne(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    ws.setCharacteristics(8, 7, 10, 4);
    ws.setMinMaxUnitCount(1, IFaction::s_MaxUnitSize);

    ws.addWeapon(WarScroll::Weapon("Burning Skull", 30, 1, 3, 3, 2 , 6));
    ws.addWeapon(WarScroll::Weapon("Hellblades", 1, 2, 4, 3, 1, 1));
    ws.addWeapon(WarScroll::Weapon("Gnashing Maw", 1, 1, 4, 3, 1, 3));

    ws.addAbility(WarScroll::Ability(WarScroll::Ability("Skull Cannon", 1)));
    ws.addAbility(WarScroll::Ability(WarScroll::Ability(
      "Grind their Bones, Seize their Skulls", 2)));
    ws.addAbility(WarScroll::Ability(WarScroll::Ability("Decapitating Blow",
      1)));

    ws.addKeyWords({"CHAOS", "DAEMON", "BLOODLETTER", "KHORNE",
      "SKULL CANNONS"});

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eChaos);
    return ws;
  }

  WarScroll Daemon_Prince_in_Khorne(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    ws.setCharacteristics(8, 8, 10, 4);

    ws.addWeapon(WarScroll::Weapon("Malefic Talons", 1, 3, 3, 3, 0, 2));

    ws.addAbility(WarScroll::Ability("Immortal Champion", 1));
    ws.addAbility(WarScroll::Ability("Khorne", 2));

    ws.addWeaponUpgrade(WarScroll::WeaponUpgrade(
      WarScroll::Weapon("Daemonic Axe", 2, 4, 4, 3, 2, 3),
      WarScroll::Ability()));
    ws.addWeaponUpgrade(WarScroll::WeaponUpgrade(
      WarScroll::Weapon("Hellforged Sword", 2, 4, 3, 3, 1, 3),
      WarScroll::Ability()));

    WarScroll::MountUpgrade wingsUpgrade("Wings", true);
    wingsUpgrade.registerCharacteristicToIncrease("Move", 4);
    ws.registerMountUpgrade(wingsUpgrade);

    ws.addKeyWords({"CHAOS", "DAEMON", "KHORNE", "MONSTER", "HERO",
      "DAEMON PRINCE"});

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eChaos);

    return ws;
  }

  WarScroll Furies_in_Khorne(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    ws.setCharacteristics(12, 1, 10, 5);
    ws.setMinMaxUnitCount(1, IFaction::s_MaxUnitSize);
    ws.setCanFly(true);

    ws.addWeapon(WarScroll::Weapon("Hooked Claws", 1, 2, 4, 4, 0, 1));

    ws.addAbility(WarScroll::Ability("Shadows of the Dark Gods", 1));
    ws.addAbility(WarScroll::Ability("Prey Upon Terror", 1));

    ws.addKeyWords({"CHAOS", "DAEMON", "FURIES", "KHORNE"});

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eChaos);
    return ws;
  }

  WarScroll Soul_Grinder_in_Khorne(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    ws.setCharacteristics(12, 16, 10, 4);

    ws.addWeapon(WarScroll::Weapon("Harvester Cannon", 16, 6, 4, 3, 1, 1));
    ws.addWeapon(WarScroll::Weapon("Phlegm Bombardment", 20, 1, 4, 3, 2, 3));
    ws.addWeapon(WarScroll::Weapon("Piston-driven Legs", 1, 6, 4, 3, 1, 1));
    ws.addWeapon(WarScroll::Weapon("Hellforged Claw", 2, 1, 4, 3, 2, 6));

    ws.addAbility(WarScroll::Ability("Daemon Engine of the Dark God", 1));
    ws.addAbility(WarScroll::Ability("Implacable Advance", 3));
    ws.addAbility(WarScroll::Ability("Caught by the Claw", 2));

    ws.addWeaponUpgrade(WarScroll::WeaponUpgrade(
      WarScroll::Weapon("No Additional Weapon", 0, 0, 7, 7, 0, 0),
      WarScroll::Ability()));
    ws.addWeaponUpgrade(WarScroll::WeaponUpgrade(
      WarScroll::Weapon("Warpmetal Blade", 2, 2, 4, 3, 2, 3),
      WarScroll::Ability()));
    ws.addWeaponUpgrade(WarScroll::WeaponUpgrade(
      WarScroll::Weapon("Daemonbone Talon", 2, 4, 3, 3, 1, 3),
      WarScroll::Ability()));

    ws.addKeyWords({"CHAOS", "DAEMON", "MONSTER", "SOUL GRINDER", "KHORNE"});

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eChaos);
    return ws;
  }
}

DaemonsOfChaosKhorneFaction::DaemonsOfChaosKhorneFaction() :
  IFaction(nullptr)
{
  m_Units.push_back("");
  m_Units.push_back("Bloodthirster of Insensate Rage");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Bloodthirster_of_Insensate_Rage,
    m_Units.back())));
  m_Units.push_back("Bloodthirster of Unfettered Fury");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Bloodthirster_of_Unfettered_Fury,
    m_Units.back())));
  m_Units.push_back("Wrath of Khorne Bloodthirster");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Wrath_of_Khorne_Bloodthirster,
    m_Units.back())));
  m_Units.push_back("Skulltaker");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Skulltaker, m_Units.back())));
  m_Units.push_back("Herald of Khorne");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Herald_of_Khorne, m_Units.back())));
  m_Units.push_back("Herald of Khorne on Juggernaut");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Herald_of_Khorne_on_Juggernaut,
    m_Units.back())));
  m_Units.push_back("Blood Throne of Khorne");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Blood_Throne_of_Khorne, m_Units.back())));
  m_Units.push_back("Bloodletters of Khorne");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Bloodletters_of_Khorne, m_Units.back())));
  m_Units.push_back("Bloodcrushers of Khorne");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Bloodcrushers_of_Khorne, m_Units.back())));
  m_Units.push_back("Karanak");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Karanak, m_Units.back())));
  m_Units.push_back("Flesh Hounds of Khorne");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Flesh_Hounds_of_Khorne, m_Units.back())));
  m_Units.push_back("Skull Cannons of Khorne");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Skull_Cannons_of_Khorne, m_Units.back())));
  m_Units.push_back("Daemon Prince");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Daemon_Prince_in_Khorne, m_Units.back())));
  m_Units.push_back("Furies");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Furies_in_Khorne, m_Units.back())));
  m_Units.push_back("Soul Grinder");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Soul_Grinder_in_Khorne, m_Units.back())));
}

const std::vector<std::string> &DaemonsOfChaosKhorneFaction::getUnits() const
{
  return m_Units;
}

void DaemonsOfChaosKhorneFaction::getWarScrolls(
  std::list<WarScroll>& warScrolls)
{
  for (const std::string &unit : m_Units) {
    if (unit.empty()) {
      continue;
    }
    WarScroll ws = m_NameToWarScroll[unit](unit);
    warScrolls.push_back(ws);
  }
}
