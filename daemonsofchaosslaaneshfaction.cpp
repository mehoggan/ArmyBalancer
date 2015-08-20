#include "daemonsofchaosslaaneshfaction.h"

namespace WarScrollGeneration
{
  WarScroll Keeper_of_Secrets(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    ws.setCharacteristics(14, 10, 10, 4);

    ws.addWeapon(WarScroll::Weapon("Razor-sharp Claws", 2, 6, 3, 3, 1, 2));
    ws.addWeapon(WarScroll::Weapon("Elegant Greatblade", 2, 2, 3, 2, 2, 3));

    ws.addAbility(WarScroll::Ability("Dark Temptations", 2));
    ws.addAbility(WarScroll::Ability("Delicate Precision", 1));
    ws.addAbility(WarScroll::Ability("Excess of Violence", 2, true));

    ws.addSpell(WarScroll::Spell("Summon Daemons"), 7, 3);
    ws.addSpell(WarScroll::Spell("Cacophonic Choir"), 6, 2);

    ws.addKeyWords({"CHAOS", "DAEMON", "SLAANESH", "MONSTER", "HERO", "WIZARD",
      "KEEPER OF SECRETS"});

    return ws;
  }

  WarScroll The_Masque_of_Slaanesh(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    ws.setCharacteristics(10, 5, 10, 4);

    ws.addWeapon(WarScroll::Weapon("Serrated Claws", 1, 6, 3, 4, 1, 1));
    ws.addWeapon(WarScroll::Weapon("Staff of Masks", 1, 1, 3, 5, 0, 1));

    ws.addAbility(WarScroll::Ability("Unnatural Reflexes", 2));
    ws.addAbility(WarScroll::Ability("The Endless Dance", 1));
    ws.addAbility(WarScroll::Ability("Infernal Choreographer", 1));

    ws.addKeyWords({"CHAOS", "DAEMON", "DAEMONETTE", "SLAANESH", "HERO",
      "THE MASQUE"});

    return ws;
  }

  WarScroll Herald_of_Slaanesh(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    ws.setCharacteristics(6, 5, 10, 5);

    ws.addWeapon(WarScroll::Weapon("Ravaging Claws", 1, 6, 3, 4, 1, 1));

    WarScroll::UnitUpgrade steedUpgrade("Steed of Slaanesh",
      WarScroll::UnitUpgrade::UnitUpgradeType::eMount, 1);
    steedUpgrade.registerCharacteristicToIncrease("Move", 6);
    steedUpgrade.addWeapon(WarScroll::Weapon("Steed's Poisoned Tongue",
      1, 2, 4, 4, 0, 1));
    ws.registerUnitUpgrade(steedUpgrade);

    ws.addAbility(WarScroll::Ability("Deadly Grace", 1));
    ws.addAbility(WarScroll::Ability("Quicksilver Dodge", 1));

    ws.addKeyWords({"CHAOS", "DAEMON", "DAEMONETTE", "SLAANESH", "HERO",
      "HERALD OF SLAANESH"});

    return ws;
  }

  WarScroll Herald_of_Slaanesh_on_Seeker_Chariot(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(12, 5, 10, 5);

    ws.addWeapon(WarScroll::Weapon("Herald's Flensing Whips",
      2, 6, 3, 4, 0, 1));
    ws.addWeapon(WarScroll::Weapon("Daemonette's Piercing Claws",
      1, 2, 4, 4, 1, 1));
    ws.addWeapon(WarScroll::Weapon("Steeds' Poisoned Tongues",
      1, 4, 4, 4, 0, 1));

    ws.addAbility(WarScroll::Ability("Deadly Grace", 1));
    ws.addAbility(WarScroll::Ability("Impossibly Quick", 2));
    ws.addAbility(WarScroll::Ability("Excess of Blades", 1));
    ws.addAbility(WarScroll::Ability("Disturbing Beauty", 1));

    ws.addKeyWords({"CHAOS", "DAEMON", "DAEMONETTE", "SLAANESH", "HERO",
      "SEEKER", "CHARIOT"});

    return ws;
  }

  WarScroll Herald_of_Slaanesh_on_Exalted_Seeker_Chariot(
    const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(12, 9, 10, 5);

    ws.addWeapon(WarScroll::Weapon("Herald's Flensing Whips",
      2, 6, 3, 4, 0, 1));
    ws.addWeapon(WarScroll::Weapon("Daemonettes' Piercing Claws",
      1, 6, 4, 4, 1, 1));
    ws.addWeapon(WarScroll::Weapon("Steeds' Poisoned Tongues",
      1, 8, 4, 4, 0, 1));

    ws.addAbility(WarScroll::Ability("Swirling Shapes and Unholy Hues", 1));
    ws.addAbility(WarScroll::Ability("Exalted Excess of Blades", 1));
    ws.addAbility(WarScroll::Ability("Deadly Grace", 1));
    ws.addAbility(WarScroll::Ability("Disturbing Beauty", 1));

    ws.addKeyWords({"CHAOS", "DAEMON", "DAEMONETTE", "SLAANESH", "HERO",
      "EXALTED SEEKER CHARIOT"});

    return ws;
  }

  WarScroll Daemonettes_of_Slaanesh(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    ws.setCharacteristics(6, 1, 10, 5);

    ws.addWeapon(WarScroll::Weapon("Piercing Claws", 1, 2, 4, 4, 1, 1));

    ws.setMinMaxUnitCount(10, IFaction::s_MaxUnitSize);

    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Alluress",
      WarScroll::UnitUpgrade::UnitUpgradeType::eChampion, 1));
    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Icon Bearer",
      WarScroll::UnitUpgrade::UnitUpgradeType::eBannerBearer, 2));
    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Hornblower",
      WarScroll::UnitUpgrade::UnitUpgradeType::eMusician, 1));

    ws.addAbility(WarScroll::Ability("Lith and Swift", 2));
    ws.addAbility(WarScroll::Ability("Graceful Killers", 1));
    ws.addAbility(WarScroll::Ability("Locus of Beguilement", 1));

    ws.addKeyWords({"CHAOS", "DAEMON", "SLAANESH", "DAEMONETTES"});

    return ws;
  }

  WarScroll Seekers_of_Slaanesh(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(14, 2, 10, 5);

    ws.addWeapon(WarScroll::Weapon("Piercing Claws", 1, 2, 4, 4, 1, 1));
    ws.addWeapon(WarScroll::Weapon("Poisoned Tongue", 1, 2, 4, 4, 0, 1));

    ws.setMinMaxUnitCount(5, IFaction::s_MaxUnitSize);

    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Heartseeker",
      WarScroll::UnitUpgrade::UnitUpgradeType::eChampion, 1));
    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Icon Bearer",
      WarScroll::UnitUpgrade::UnitUpgradeType::eBannerBearer, 2));
    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Hornblower",
      WarScroll::UnitUpgrade::UnitUpgradeType::eMusician, 1));

    ws.addAbility(WarScroll::Ability("Graceful Killers", 1));
    ws.addAbility(WarScroll::Ability("Quicksilver Speed", 2));
    ws.addAbility(WarScroll::Ability("Locus of Swiftness", 1));

    ws.addKeyWords({"CHAOS", "DAEMON", "DAEMONETTE", "SLAANESH", "SEEKERS"});

    return ws;
  }

  WarScroll Fiends_of_Slaanesh(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(12, 4, 10, 5);

    ws.addWeapon(WarScroll::Weapon("Deadly Pincers", 1, 4, 4, 4, 0, 1));
    ws.addWeapon(WarScroll::Weapon("Barbed Stinger", 2, 1, 4, 3, 1, 3));

    ws.setMinMaxUnitCount(1, IFaction::s_MaxUnitSize);

    ws.addAbility(WarScroll::Ability("Vicious Pincers", 1));
    ws.addAbility(WarScroll::Ability("Soporific Musk", 1));
    ws.addAbility(WarScroll::Ability("Locus of Grace", 1));

    ws.addKeyWords({"CHAOS", "DAEMON", "SLAANESH", "FIENDS"});

    return ws;
  }

  WarScroll Seeker_Chariots_of_Slaanesh(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(12, 6, 10, 5);

    ws.addWeapon(WarScroll::Weapon("Alluress' Flensing Whips",
      2, 3, 4, 4, 0, 1));
    ws.addWeapon(WarScroll::Weapon("Daemonette's Piercing Claws",
      1, 2, 4, 4, 1, 1));
    ws.addWeapon(WarScroll::Weapon("Steeds' Poisoned Tongues",
      1, 4, 4, 4, 0, 1));

    ws.setMinMaxUnitCount(1, IFaction::s_MaxUnitSize);

    ws.addAbility(WarScroll::Ability("Impossibly Quick", 3));
    ws.addAbility(WarScroll::Ability("Exenterating Blades", 1));
    ws.addAbility(WarScroll::Ability("Deadly Grace", 1));

    ws.addKeyWords({"CHAOS", "DAEMON", "DAEMONETTE", "SLAANESH",
      "SEEKER CHARIOTS"});

    return ws;
  }

  WarScroll Exalted_Seeker_Chariots_of_Slaanesh(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(12, 9, 10, 5);

    ws.addWeapon(WarScroll::Weapon("Alluress' Flensing Whips",
      2, 3, 4, 4, 0, 1));
    ws.addWeapon(WarScroll::Weapon("Daemonettes' Piercing Claws",
      1, 6, 4, 4, 1, 1));
    ws.addWeapon(WarScroll::Weapon("Steeds' Poisoned Tongues",
      1, 8, 4, 4, 0, 1));

    ws.setMinMaxUnitCount(1, IFaction::s_MaxUnitSize);

    ws.addAbility(WarScroll::Ability("Swirling Shapes and Unholy Hues", 1));
    ws.addAbility(WarScroll::Ability("Exalted Excess of Blades", 1));
    ws.addAbility(WarScroll::Ability("Deadly Grace", 1));

    ws.addKeyWords({"CHAOS", "DAEMON", "DAEMONETTE", "SLAANESH",
      "EXALTED SEEKER CHARIOTS"});

    return ws;
  }

  WarScroll Hellflayers_of_Slaanesh(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(12, 6, 10, 5);

    ws.addWeapon(WarScroll::Weapon("Alluress' Piercing Claws",
      1, 3, 4, 4, 1, 1));
    ws.addWeapon(WarScroll::Weapon("Daemonettes' Flensing Whips",
      2, 4, 4, 4, 0, 1));
    ws.addWeapon(WarScroll::Weapon("Steeds' Poisoned Tongues",
      1, 4, 4, 4, 0, 1));

    ws.setMinMaxUnitCount(1, IFaction::s_MaxUnitSize);

    ws.addAbility(WarScroll::Ability("Deadly Grace", 1));
    ws.addAbility(WarScroll::Ability("Soulscent", 1));

    ws.addKeyWords({"CHAOS", "DAEMON", "DAEMONETTE", "SLAANESH",
      "HELLFLAYERS"});

    return ws;
  }

  WarScroll Daemon_Prince_in_Slaanesh(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    ws.setCharacteristics(8, 8, 10, 4);

    ws.addWeapon(WarScroll::Weapon("Malefic Talons", 1, 3, 4, 3, 0, 2));

    ws.addAbility(WarScroll::Ability("Immortal Champion", 1));
    ws.addAbility(WarScroll::Ability("Nurgle", 2));

    ws.addWeaponUpgrade(WarScroll::WeaponUpgrade(
      WarScroll::Weapon("Daemonic Axe", 2, 4, 4, 3, 2, 3),
      WarScroll::Ability()));
    ws.addWeaponUpgrade(WarScroll::WeaponUpgrade(
      WarScroll::Weapon("Hellforged Sword", 2, 4, 3, 3, 1, 3),
      WarScroll::Ability()));

    WarScroll::MountUpgrade wingsUpgrade("Wings", true);
    wingsUpgrade.registerCharacteristicToIncrease("Move", 4);
    ws.registerMountUpgrade(wingsUpgrade);

    ws.addKeyWords({"CHAOS", "DAEMON", "SLAANESH", "MONSTER", "HERO",
      "DAEMON PRINCE"});

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eChaos);

    return ws;
  }

  WarScroll Furies_in_Slaanesh(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    ws.setCharacteristics(12, 1, 10, 5);
    ws.setMinMaxUnitCount(1, IFaction::s_MaxUnitSize);
    ws.setCanFly(true);

    ws.addWeapon(WarScroll::Weapon("Hooked Claws", 1, 2, 4, 4, 0, 1));

    ws.addAbility(WarScroll::Ability("Shadows of the Dark Gods", 1));
    ws.addAbility(WarScroll::Ability("Prey Upon Terror", 1));

    ws.addKeyWords({"CHAOS", "DAEMON", "FURIES", "SLAANESH"});

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eChaos);
    return ws;
  }

  WarScroll Soul_Grinder_in_Slaanesh(const std::string &name)
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

    ws.addKeyWords({"CHAOS", "DAEMON", "MONSTER", "SOUL GRINDER", "SLAANESH"});

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eChaos);
    return ws;
  }
}

DaemonsOfChaosSlaaneshFaction::DaemonsOfChaosSlaaneshFaction() :
  IFaction()
{
  m_Units.push_back("");
  m_Units.push_back("Keeper of Secrets");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Keeper_of_Secrets, m_Units.back())));
  m_Units.push_back("The Masque of Slaanesh");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::The_Masque_of_Slaanesh, m_Units.back())));
  m_Units.push_back("Herald of Slaanesh");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Herald_of_Slaanesh, m_Units.back())));
  m_Units.push_back("Herald of Slaanesh on Seeker Chariot");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Herald_of_Slaanesh_on_Seeker_Chariot,
    m_Units.back())));
  m_Units.push_back("Herald of Slaanesh on Exalted Seeker Chariot");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(
      &WarScrollGeneration::Herald_of_Slaanesh_on_Exalted_Seeker_Chariot,
      m_Units.back())));
  m_Units.push_back("Daemonettes of Slaanesh");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Daemonettes_of_Slaanesh, m_Units.back())));
  m_Units.push_back("Seekers of Slaanesh");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Seekers_of_Slaanesh, m_Units.back())));
  m_Units.push_back("Fiends of Slaanesh");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Fiends_of_Slaanesh, m_Units.back())));
  m_Units.push_back("Seeker Chariots of Slaanesh");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Seeker_Chariots_of_Slaanesh,
    m_Units.back())));
  m_Units.push_back("Exalted Seeker Chariots of Slaanesh");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Exalted_Seeker_Chariots_of_Slaanesh,
    m_Units.back())));
  m_Units.push_back("Hellflayers of Slaanesh");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Hellflayers_of_Slaanesh, m_Units.back())));
  m_Units.push_back("Daemon Prince");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Daemon_Prince_in_Slaanesh,
    m_Units.back())));
  m_Units.push_back("Furies");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Furies_in_Slaanesh, m_Units.back())));
  m_Units.push_back("Soul Grinder");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Soul_Grinder_in_Slaanesh, m_Units.back())));
}

const std::vector<std::string> &DaemonsOfChaosSlaaneshFaction::getUnits() const
{
  return m_Units;
}

void DaemonsOfChaosSlaaneshFaction::getWarScrolls(
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
