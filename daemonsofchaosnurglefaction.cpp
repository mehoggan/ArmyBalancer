#include "daemonsofchaosnurglefaction.h"

namespace WarScrollGeneration
{
  WarScroll Great_Unclean_One(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    ws.setCharacteristics(5, 10, 10, 4);

    ws.addWeapon(WarScroll::Weapon("Noxious Bile", 7, 6, 3, 2, 2, 1));
    ws.addWeapon(WarScroll::Weapon("Plague Flail", 2, 3, 3, 2, 1, 2));
    ws.addWeapon(WarScroll::Weapon("Massive Bilesword", 2, 3, 4, 3, 2, 3));

    ws.addAbility(WarScroll::Ability("Blubber and Bile", 2));
    ws.addAbility(WarScroll::Ability("Corpulent Mass", 3));
    ws.addAbility(WarScroll::Ability("Gradfather's Joy", 2, true));

    WarScroll::Spell spell("Plague Wind");
    spell.setToCast(7);
    spell.setPointCost(3);
    ws.addSpell(spell);
    ws.addSpell(WarScroll::Spell("Summon Daemons"), 7, 3);

    ws.addKeyWords({"CHAOS", "DAEMON", "NURGLE", "MONSTER", "HERO", "WIZARD",
      "GREAT UNCLEAN ONE"});

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eChaos);

    ws.addKeyWordConnection(WarScroll::KeyWordConnection("NURGLE + DAEMON",
      WarScroll::s_MaxDistance,
      WarScroll::Ability("Gradfather's Joy", 2, true), 1,
      WarScroll::KeyWordConnection::ConnectionAffectType::eFriendly,
      WarScroll::Spell()));
    ws.addKeyWordConnection(WarScroll::KeyWordConnection("NURGLE",
      14, WarScroll::Ability(), 1,
      WarScroll::KeyWordConnection::ConnectionAffectType::eFriendly,
      spell));

    WarScroll::addSummonable(ws, name, 9, 3, 14, 1, {"CHAOS", "WIZARD"});

    return ws;
  }

  WarScroll Epidemius(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    ws.setCharacteristics(4, 7, 10, 4);

    ws.addWeapon(WarScroll::Weapon("Balesword", 1, 3, 4, 3, 1, 3));
    ws.addWeapon(WarScroll::Weapon("Tine Razor-sharp Teeth", 1, 5, 5, 5, 0, 1));

    ws.addAbility(WarScroll::Ability("Disgustingly Resilient", 2));
    ws.addAbility(WarScroll::Ability("Nurgle's Tallyman", 1));

    ws.addKeyWords({"CHAOS", "DAEMON", "PLAGUEBEARER", "NURGLE", "HERO",
      "EPIDEMIUS"});

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eChaos);

    ws.addKeyWordConnection(WarScroll::KeyWordConnection("NURGLE",
      WarScroll::s_MaxDistance, WarScroll::Ability("Nurgle's Tallyman", 1), 1,
      WarScroll::KeyWordConnection::ConnectionAffectType::eFriendly,
      WarScroll::Spell()));

    return ws;
  }

  WarScroll Herald_of_Nurgle(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    ws.setCharacteristics(4, 5, 10, 4);

    ws.addWeapon(WarScroll::Weapon("Balesword", 1, 3, 4, 3, 1, 3));

    ws.addAbility(WarScroll::Ability("Disgustingly Resilient", 2));
    ws.addAbility(WarScroll::Ability("In Death There is Life", 2));

    ws.addKeyWords({"CHAOS", "DAEMON", "PLAGUEBEARER", "NURGLE", "HERO",
      "HERALD OF NURGLE"});

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eChaos);

    WarScroll::addSummonable(ws, name, 5, 3, 14, 1, {"CHAOS", "WIZARD"});

    return ws;
  }

  WarScroll Plaguebearers_of_Nurgle(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    ws.setCharacteristics(4, 1, 10, 5);

    ws.addWeapon(WarScroll::Weapon("Plaguesword", 1, 1, 4, 3, 0, 1));

    ws.setMinMaxUnitCount(10, IFaction::s_MaxUnitSize);

    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Plagueridden",
      WarScroll::UnitUpgrade::UnitUpgradeType::eChampion, 1));
    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Icon Bearers",
      WarScroll::UnitUpgrade::UnitUpgradeType::eBannerBearer, 2));
    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Pipers",
      WarScroll::UnitUpgrade::UnitUpgradeType::eMusician, 1));

    ws.addAbility(WarScroll::Ability("Cloud of Flies", 1));
    ws.addAbility(WarScroll::Ability("Disgustingly Resilient", 2));
    ws.addAbility(WarScroll::Ability("Locus of Fecundity", 1));

    ws.addKeyWords({"CHAOS", "DAEMON", "NURGLE", "PLAGUEBEARERS"});

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eChaos);

    ws.addKeyWordConnection(WarScroll::KeyWordConnection(
      "PLAGUEBEARER + HERO", 7, WarScroll::Ability("Locus of Fecundity", 1), 1,
      WarScroll::KeyWordConnection::ConnectionAffectType::eFriendly,
      WarScroll::Spell()));
    WarScroll::addSummonable(ws, name, 6, 3, 14, 10, {"CHAOS", "WIZARD"});

    return ws;
  }

  WarScroll Plague_Drones_of_Nurgle(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    ws.setCharacteristics(8, 5, 10, 5);

    ws.addWeapon(WarScroll::Weapon("Death's Head", 14, 1, 4, 3, 0, 1));
    ws.addWeapon(WarScroll::Weapon("Plaguesword", 1, 1, 4, 3, 0, 1));
    ws.addWeapon(WarScroll::Weapon("Prehensile Proboscis", 1, 3, 3, 4, 0, 1));
    ws.addWeapon(WarScroll::Weapon("Venomous String", 1, 1, 4, 3, 1, 3));

    ws.setMinMaxUnitCount(3, IFaction::s_MaxUnitSize);

    ws.setCanFly(true);

    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Plaguebringer",
      WarScroll::UnitUpgrade::UnitUpgradeType::eChampion, 1));
    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Icon Bearer",
      WarScroll::UnitUpgrade::UnitUpgradeType::eBannerBearer, 1));
    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Bell Tollers",
      WarScroll::UnitUpgrade::UnitUpgradeType::eMusician, 1));

    ws.addAbility(WarScroll::Ability("Disgustingly Resilient", 2));
    WarScroll::Ability ability("Locus of Contagion", 1);
    ability.setOverNModels(6);
    ws.addAbility(ability);

    ws.addKeyWords({"CHAOS", "DAEMON", "PLAGUEBEARER", "NURGLE",
      "PLAGUE DRONES"});

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eChaos);

    ws.addKeyWordConnection(WarScroll::KeyWordConnection("PLAGUEBEARER + HERO",
      7, WarScroll::Ability("Locus of Contagion", 1), 6,
      WarScroll::KeyWordConnection::ConnectionAffectType::eFriendly,
      WarScroll::Spell()));
    WarScroll::addSummonable(ws, name, 6, 3, 14, 3, {"CHAOS", "WIZARD"});

    return ws;
  }

  WarScroll Nurglings(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    ws.setCharacteristics(5, 4, 10, 7);

    ws.addWeapon(WarScroll::Weapon("Tiny Razor-sharp Teeth", 1, 5, 5, 5, 0, 1));

    ws.setMinMaxUnitCount(3, IFaction::s_MaxUnitSize);

    ws.addAbility(WarScroll::Ability("Disease-ridden Demise", 2));
    ws.addAbility(WarScroll::Ability("Endless Swarm", 3));

    ws.addKeyWords({"CHAOS", "DAEMON", "NURGLE", "NURGLINGS"});

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eChaos);

    return ws;
  }

  WarScroll Beasts_of_Nurgle(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    ws.setCharacteristics(5, 6, 10, 5);

    ws.addWeapon(WarScroll::Weapon("Claws and Tentacles", 1, 6, 4, 3, 0, 1));
    ws.addWeapon(WarScroll::Weapon("Slobbering Tongue", 2, 1, 4, 3, 0, 3));

    ws.setMinMaxUnitCount(1, IFaction::s_MaxUnitSize);

    ws.addAbility(WarScroll::Ability("Attention Seekers", 1));
    ws.addAbility(WarScroll::Ability("Slime Trail", 2));
    ws.addAbility(WarScroll::Ability("Locus of Virulence", 1));

    ws.addKeyWords({"CHAOS", "DAEMON", "NURGLE", "BEASTS OF NURGLE"});

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eChaos);

    return ws;
  }

  WarScroll Daemon_Prince_in_Nurgle(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    ws.setCharacteristics(8, 8, 10, 3);

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

    ws.addKeyWords({"CHAOS", "DAEMON", "NURGLE", "MONSTER", "HERO",
      "DAEMON PRINCE"});

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eChaos);

    return ws;
  }

  WarScroll Furies_in_Nurgle(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    ws.setCharacteristics(12, 1, 10, 5);
    ws.setMinMaxUnitCount(1, IFaction::s_MaxUnitSize);
    ws.setCanFly(true);

    ws.addWeapon(WarScroll::Weapon("Hooked Claws", 1, 2, 4, 4, 0, 1));

    ws.addAbility(WarScroll::Ability("Shadows of the Dark Gods", 1));
    ws.addAbility(WarScroll::Ability("Prey Upon Terror", 1));

    ws.addKeyWords({"CHAOS", "DAEMON", "FURIES", "NURGLE"});

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eChaos);
    return ws;
  }

  WarScroll Soul_Grinder_in_Nurgle(const std::string &name)
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

    ws.addKeyWords({"CHAOS", "DAEMON", "MONSTER", "SOUL GRINDER", "NURGLE"});

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eChaos);
    return ws;
  }
}

DaemonsOfChaosNurgleFaction::DaemonsOfChaosNurgleFaction() :
  IFaction()
{
  m_Units.push_back("");
  m_Units.push_back("Great Unclean One");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Great_Unclean_One, m_Units.back())));
  m_Units.push_back("Epidemius");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Epidemius, m_Units.back())));
  m_Units.push_back("Herald of Nurgle");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Herald_of_Nurgle, m_Units.back())));
  m_Units.push_back("Plaguebearers of Nurgle");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Plaguebearers_of_Nurgle, m_Units.back())));
  m_Units.push_back("Plague Drones of Nurgle");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Plague_Drones_of_Nurgle, m_Units.back())));
  m_Units.push_back("Nurglings");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Nurglings, m_Units.back())));
  m_Units.push_back("Beasts of Nurgle");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Beasts_of_Nurgle, m_Units.back())));
  m_Units.push_back("Daemon Prince");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Daemon_Prince_in_Nurgle, m_Units.back())));
  m_Units.push_back("Furies");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Furies_in_Nurgle, m_Units.back())));
  m_Units.push_back("Soul Grinder");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Soul_Grinder_in_Nurgle, m_Units.back())));
}

const std::vector<std::string> &DaemonsOfChaosNurgleFaction::getUnits() const
{
  return m_Units;
}

void DaemonsOfChaosNurgleFaction::getWarScrolls(
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
