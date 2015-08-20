#include "daemonsofchaostzeentchfaction.h"

namespace WarScrollGeneration
{
  WarScroll Kairos_Fateweaver(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    ws.setCharacteristics(10, 10, 10, 4);

    ws.addWeapon(WarScroll::Weapon("Staff of Tomorrow", 3, 6, 4, 2, 1, 2));
    ws.addWeapon(WarScroll::Weapon("Beaks and Claws", 1, 5, 4, 3, 1, 1));

    ws.setCanFly(true);

    ws.addAbility(WarScroll::Ability("Mastery of Magic", 3));
    ws.addAbility(WarScroll::Ability("Secrets and Ciphers", 1));
    ws.addAbility(WarScroll::Ability("Oracle of Eternity", 1));

    ws.addSpell(WarScroll::Spell("Gift of Change"), 8, 3);

    ws.addKeyWords({"CHAOS", "DAEMON", "TZEENTCH", "MONSTER", "HERO",
      "WIZARD", "LORD OF CHANGE", "KAIROS FATEWEAVER"});

    return ws;
  }

  WarScroll Lord_of_Change(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(10, 10, 10, 4);

    ws.addWeapon(WarScroll::Weapon("Staff of Tzeentch", 3, 2, 4, 2, 0, 2));
    ws.addWeapon(WarScroll::Weapon("Curved Beak and Wicked Talons",
      1, 4, 4, 3, 1, 1));

    ws.setCanFly(true);

    ws.addAbility(WarScroll::Ability("Mastery of Magic", 3));
    ws.addAbility(WarScroll::Ability("Spell-thief", 3));
    ws.addAbility(WarScroll::Ability("Beacon of Sorcery", 3, true));

    ws.addSpell(WarScroll::Spell("Summon Daemons"), 7, 3);
    ws.addSpell(WarScroll::Spell("Infernal Gateway"), 7, 3);

    ws.addKeyWords({"CHAOS", "DAEMON", "TZEENTCH", "MONSTER", "HERO", "WIZARD",
      "LORD OF CHANGE"});

    return ws;
  }

  WarScroll The_Changeling(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(5, 5, 10, 5);

    ws.addWeapon(WarScroll::Weapon("The Trickster's Staff", 2, 1, 4, 3, 1, 3));

    ws.addAbility(WarScroll::Ability("Arch Deceiver", 3));
    ws.addAbility(WarScroll::Ability("Puckish Misdirection", 3));
    ws.addAbility(WarScroll::Ability("Formless Horror", 3));

    ws.addKeyWords({"CHAOS", "DAEMON", "HORROR", "TZEENTCH", "HERO", "WIZARD",
      "THE CHANGELING"});

    return ws;
  }

  WarScroll Herald_of_Tzeentch(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    ws.setCharacteristics(5, 5, 10, 5);

    ws.addWeapon(WarScroll::Weapon("Magical Flames", 18, 2, 4, 4, 0, 1));
    ws.addWeapon(WarScroll::Weapon("Staff of Change", 2, 1, 4, 3, 1, 3));
    ws.addWeapon(WarScroll::Weapon("Ritual Dagger", 1, 2, 4, 4, 0, 1));

    ws.addAbility(WarScroll::Ability("Arcane Tome", 2));
    ws.addAbility(WarScroll::Ability("Fortune and Fate", 2));

    ws.addSpell(WarScroll::Spell("Summon Daemons"), 7, 3);
    ws.addSpell(WarScroll::Spell("Pink Fire of Tzeentch"), 9, 3);

    ws.addKeyWords({"CHAOS", "DAEMON", "HORROR", "TZEENTCH", "HERO", "WIZARD",
      "HERALD OF TZEENTCH"});

    return ws;
  }

  WarScroll Herald_of_Tzeentch_on_Disc_of_Tzeentch(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    ws.setCharacteristics(16, 5, 10, 5);

    ws.addWeapon(WarScroll::Weapon("Magical Flames", 18, 2, 4, 4, 0, 1));
    ws.addWeapon(WarScroll::Weapon("Staff of Change", 2, 1, 4, 3, 1, 3));
    ws.addWeapon(WarScroll::Weapon("Ritual Dagger", 1, 2, 4, 4, 0, 1));
    ws.addWeapon(WarScroll::Weapon("Disc of Tzeentch's Teeth and Horns",
      1, 3, 4, 3, 1, 3));

    ws.setCanFly(true);

    ws.addAbility(WarScroll::Ability("Arcane Tome", 1));

    ws.addSpell(WarScroll::Spell("Summon Daemons"), 7, 3);
    ws.addSpell(WarScroll::Spell("Blue Fire of Tzeentch"), 4, 2);

    ws.addKeyWords({"CHAOS", "DAEMON", "HORROR", "TZEENTCH", "HERO", "WIZARD",
      "HERALD ON DISC"});

    return ws;
  }

  WarScroll Herald_of_Tzeentch_on_Burning_Chariot(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    ws.setCharacteristics(14, 8, 10, 5);

    ws.addWeapon(WarScroll::Weapon("Staff of Change", 2, 1, 4, 3, 1, 3));
    ws.addWeapon(WarScroll::Weapon("Ritual Dagger", 1, 2, 4, 4, 0, 1));
    ws.addWeapon(WarScroll::Weapon("Screamers' Lamprey Bites",
      1, 6, 4, 3, 0, 1));

    ws.setCanFly(true);

    ws.addAbility(WarScroll::Ability("Arcane Tome", 3));
    ws.addAbility(WarScroll::Ability("Sky-sharks", 2));
    ws.addAbility(WarScroll::Ability("Wake of Fire", 1));

    ws.addSpell(WarScroll::Spell("Summon Daemons"), 7, 3);
    ws.addSpell(WarScroll::Spell("Tzeentch's Firestorm"), 9, 2);

    ws.addKeyWords({"CHAOS", "DAEMON", "HORROR", "TZEENTCH", "HERO", "WIZARD",
      "HERALD ON BURNING CHARIOT"});

    return ws;
  }

  WarScroll The_Blue_Scribes(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    ws.setCharacteristics(16, 5, 10, 5);

    ws.addWeapon(WarScroll::Weapon("Sharpened Quills", 1, 2, 5, 5, 0, 1));
    ws.addWeapon(WarScroll::Weapon("Disc's Many-fanged Mouths",
      1, 3, 4, 4, 0, 1));

    ws.setCanFly(true);

    ws.addAbility(WarScroll::Ability("Frantic Scribbling", 2));
    ws.addAbility(WarScroll::Ability("Scrolls of Sorcery", 2));

    ws.addSpell(WarScroll::Spell("Boon of Tzeentch"), 4, 2);

    ws.addKeyWords({"CHAOS", "DAEMON", "HORROR", "TZEENTCH", "HERO", "WIZARD",
      "THE BLUE SCRIBES"});

    return ws;
  }

  WarScroll Pink_Horrors_of_Tzeentch(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    ws.setCharacteristics(5, 1, 10, 5);

    ws.addWeapon(WarScroll::Weapon("Magical Flames", 18, 1, 4, 4, 0, 1));
    ws.addWeapon(WarScroll::Weapon("Grasping Hands", 1, 1, 5, 4, 0, 1));

    ws.setMinMaxUnitCount(10, IFaction::s_MaxUnitSize);

    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Iridescen Horror",
      WarScroll::UnitUpgrade::UnitUpgradeType::eChampion, 1));
    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Icon Bearer",
      WarScroll::UnitUpgrade::UnitUpgradeType::eBannerBearer, 2));
    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Hornblower",
      WarScroll::UnitUpgrade::UnitUpgradeType::eMusician, 1));

    ws.addAbility(WarScroll::Ability("Flickering Flames", 2));
    ws.addAbility(WarScroll::Ability("Locus of Conjuration", 2));

    ws.addSpell(WarScroll::Spell("Summon Daemons"), 7, 3);

    ws.addKeyWords({"CHAOS", "DAEMON" "TZEENTCH", "WIZARD", "PINK HORRORS"});

    return ws;
  }

  WarScroll Exalted_Flamers(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    ws.setCharacteristics(9, 4, 10, 5);

    ws.addWeapon(WarScroll::Weapon("Billowing Warpflame", 18, 6, 4, 3, 0, 3));
    ws.addWeapon(WarScroll::Weapon("Flaming Maw", 2, 4, 5, 3, 0, 1));

    ws.setMinMaxUnitCount(1, IFaction::s_MaxUnitSize);

    ws.setCanFly(true);

    ws.addAbility(WarScroll::Ability("Capricious Warpflame", 1));

    ws.addKeyWords({"CHAOS", "DAEMON", "FLAMER", "TZEENTCH",
      "EXALTED FLAMERS"});

    return ws;
  }

  WarScroll Flamers_of_Tzeentch(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    ws.setCharacteristics(9, 2, 10, 5);

    ws.addWeapon(WarScroll::Weapon("Warpflame", 18, 3, 4, 3, 0, 3));
    ws.addWeapon(WarScroll::Weapon("Flaming Maw", 1, 2, 5, 3, 0, 1));

    ws.setMinMaxUnitCount(3, IFaction::s_MaxUnitSize);

    ws.setCanFly(true);

    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Pyrocaster",
      WarScroll::UnitUpgrade::UnitUpgradeType::eChampion, 1));

    ws.addAbility(WarScroll::Ability("Capricious Warpflame", 2));
    ws.addAbility(WarScroll::Ability("Locus of Transmogrification", 3));

    ws.addKeyWords({"CHAOS", "DAEMONS", "TZEENTCH", "FLAMERS"});

    return ws;
  }

  WarScroll Screamers_of_Tzeentch(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    ws.setCharacteristics(16, 3, 10, 5);

    ws.addWeapon(WarScroll::Weapon("Lamprey Bite", 1, 3, 4, 3, 0, 1));

    ws.setMinMaxUnitCount(3, IFaction::s_MaxUnitSize);

    ws.setCanFly(true);

    ws.addAbility(WarScroll::Ability("Sky-sharks", 1));
    ws.addAbility(WarScroll::Ability("Slashing Fins", 1));
    ws.addAbility(WarScroll::Ability("Locus of Change", 1));

    ws.addKeyWords({"CHAOS", "DAEMON", "TZEENTCH", "SCREAMERS"});

    return ws;
  }

  WarScroll Burning_Chariots_of_Tzeeentch(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    ws.setCharacteristics(14, 6, 10, 5);

    ws.addWeapon(WarScroll::Weapon("Billowing Warpflame", 18, 6, 4, 3, 0, 3));
    ws.addWeapon(WarScroll::Weapon("Flaming Maw", 2, 4, 5, 3, 0, 1));
    ws.addWeapon(WarScroll::Weapon("Blue Horrors' Jabs", 1, 3, 5, 5, 0, 1));
    ws.addWeapon(WarScroll::Weapon("Screamers' Lamprey Bites",
      1, 6, 4, 3, 0, 1));

    ws.setMinMaxUnitCount(1, IFaction::s_MaxUnitSize);

    ws.setCanFly(true);

    ws.addAbility(WarScroll::Ability("Capricious Warpflame", 2));
    ws.addAbility(WarScroll::Ability("Sky-sharks", 1));
    ws.addAbility(WarScroll::Ability("Wake of Fire", 2));

    ws.addKeyWords({"CHAOS", "DAEMON", "FLAMER", "HORROR", "TZEENTCH",
      "BURNING CHARIOTS"});

    return ws;
  }

  WarScroll Daemon_Prince_in_Tzeentch(const std::string &name)
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

    ws.addKeyWords({"CHAOS", "DAEMON", "TZEENTCH", "MONSTER", "HERO",
      "DAEMON PRINCE"});

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eChaos);

    return ws;
  }

  WarScroll Furies_in_Tzeentch(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    ws.setCharacteristics(12, 1, 10, 5);
    ws.setMinMaxUnitCount(1, IFaction::s_MaxUnitSize);
    ws.setCanFly(true);

    ws.addWeapon(WarScroll::Weapon("Hooked Claws", 1, 2, 4, 4, 0, 1));

    ws.addAbility(WarScroll::Ability("Shadows of the Dark Gods", 1));
    ws.addAbility(WarScroll::Ability("Prey Upon Terror", 1));

    ws.addKeyWords({"CHAOS", "DAEMON", "FURIES", "TZEENTCH"});

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eChaos);
    return ws;
  }

  WarScroll Soul_Grinder_in_Tzeentch(const std::string &name)
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

    ws.addKeyWords({"CHAOS", "DAEMON", "MONSTER", "SOUL GRINDER", "TZEENTCH"});

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eChaos);
    return ws;
  }
}

DaemonsOfChaosTzeentchFaction::DaemonsOfChaosTzeentchFaction() :
  IFaction()
{
  m_Units.push_back("");
  m_Units.push_back("Kairos Fateweaver");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Kairos_Fateweaver, m_Units.back())));
  m_Units.push_back("Lord of Change");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Lord_of_Change, m_Units.back())));
  m_Units.push_back("The Changeling");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::The_Changeling, m_Units.back())));
  m_Units.push_back("Herald of Tzeentch");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Herald_of_Tzeentch, m_Units.back())));
  m_Units.push_back("Herald of Tzeentch on Disc of Tzeentch");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Herald_of_Tzeentch_on_Disc_of_Tzeentch,
    m_Units.back())));
  m_Units.push_back("Herald of Tzeentch on Burning Chariot");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Herald_of_Tzeentch_on_Burning_Chariot,
    m_Units.back())));
  m_Units.push_back("The Blue Scribes");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::The_Blue_Scribes, m_Units.back())));
  m_Units.push_back("Pink Horrors of Tzeentch");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Pink_Horrors_of_Tzeentch, m_Units.back())));
  m_Units.push_back("Exalted Flamers");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Exalted_Flamers, m_Units.back())));
  m_Units.push_back("Flamers of Tzeentch");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Flamers_of_Tzeentch, m_Units.back())));
  m_Units.push_back("Screamers of Tzeentch");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Screamers_of_Tzeentch, m_Units.back())));
  m_Units.push_back("Burning Chariots of Tzeeentch");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Burning_Chariots_of_Tzeeentch,
    m_Units.back())));
  m_Units.push_back("Daemon Prince");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Daemon_Prince_in_Tzeentch,
    m_Units.back())));
  m_Units.push_back("Furies");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Furies_in_Tzeentch, m_Units.back())));
  m_Units.push_back("Soul Grinder");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Soul_Grinder_in_Tzeentch, m_Units.back())));
}

const std::vector<std::string> &DaemonsOfChaosTzeentchFaction::getUnits() const
{
  return m_Units;
}

void DaemonsOfChaosTzeentchFaction::getWarScrolls(
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
