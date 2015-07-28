#include "beastmenfaction.h"

namespace WarScrollGeneration
{
  WarScroll Gorthor_the_Beastlord(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    ws.setCharacteristics(10, 8, 8, 4);
    ws.addWeapon(WarScroll::Weapon("The Impaler", 1, 6, 3, 3, 1, 1));
    ws.addWeapon(WarScroll::Weapon("Tuskgors' Tusks and Hooves",
      1, 4, 4, 3, 0, 1));
    ws.addWeapon(WarScroll::Weapon("Bagrar the Tamer's Beastspear",
      1, 2, 4, 4, 0, 1));
    ws.setMinMaxUnitCount(1, 1);
    ws.addAbility(WarScroll::Ability("Skull of Magrar", 2));
    ws.addAbility(WarScroll::Ability("The Impaler", 1));
    ws.addAbility(WarScroll::Ability("Tuskgor Charge", 1));
    ws.addAbility(WarScroll::Ability("Hatred of Heros", 1));
    ws.addAbility(WarScroll::Ability("Gore-soaked Champion", 3, true));
    ws.addKeyWords({"CHAOS", "BEASTMAN", "BRAYHERD", "HERO", "BEASTLORD",
      "GORTHOR"});
    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eChaos);
    return ws;
  }

  WarScroll Khazrak_the_One_Eye(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    ws.setCharacteristics(6, 5, 7, 3);
    ws.addWeapon(WarScroll::Weapon("Scourge", 3, 5, 3, 4, 0, 1));
    ws.addWeapon(WarScroll::Weapon("Gor Blade", 1, 6, 3, 3, 1));
    ws.addAbility(WarScroll::Ability("The Dark Mail", 2));
    ws.addAbility(WarScroll::Ability("The Scourge", 0));
    ws.addAbility(WarScroll::Ability("Hatred of Heros", 1));
    ws.addAbility(WarScroll::Ability("Bestial Cunning", 3, true));
    ws.addKeyWords({"CHAOS", "BEASTMEN", "BRAYHERD", "HERO", "BEASTLORD",
      "KHAZRAK THE ONE-EYE"});
    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eChaos);
    return ws;
  }

  WarScroll Beastlord(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    ws.setCharacteristics(6, 5, 7, 4);
    ws.addAbility(WarScroll::Ability("Hatred of Heros", 1));
    ws.addAbility(WarScroll::Ability("Grisly Trophy", 2, true));
    ws.addKeyWords({"CHAOS", "BEASTMEN", "BRAYHERD", "HERO", "BEASTLORD"});
    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eChaos);

    WarScroll::WeaponUpgrade dualAxesUpgrade(
      WarScroll::Weapon("Man-ripper Axe", 1, 6, 3, 3, 1, 1),
      WarScroll::Ability("Dual-axes", 1));
    ws.addWeaponUpgrade(dualAxesUpgrade);
    WarScroll::WeaponUpgrade shieldUpgrade(
      WarScroll::Weapon("Man-ripper Axe", 1, 6, 3, 3, 1, 1),
      WarScroll::Ability("Brayshield", 2));
    shieldUpgrade.registerCharacteristicToIncrease("Save", -1);
    ws.addWeaponUpgrade(shieldUpgrade);
    WarScroll::WeaponUpgrade greatWeaponUpgrade(
      WarScroll::Weapon("Man-render Great Axe", 1, 3, 3, 3, 2, 2),
      WarScroll::Ability());
    ws.addWeaponUpgrade(greatWeaponUpgrade);

    return ws;
  }

  WarScroll Wargor_Standard_Bearer(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    ws.setCharacteristics(6, 5, 6, 5);
    ws.addWeapon(WarScroll::Weapon("Gor Axe", 1, 4, 3, 3, 1, 1));
    ws.addAbility(WarScroll::Ability("Braying Warcry", 1));
    ws.addAbility(WarScroll::Ability("Beast Standard", 2));
    ws.addKeyWords({"CHAOS", "BEASTMEN", "BRAYHERD", "HERO", "TOTEM",
      "WARGOR STANDARD BEARER"});
    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eChaos);
    return ws;
  }

  WarScroll Malagor_The_Dark_Omen(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    ws.setCharacteristics(12, 5, 6, 6);
    ws.addWeapon(WarScroll::Weapon("Crowfather's Staff", 2, 2, 4, 4, 1, 3));
    ws.setCanFly(true);
    ws.addAbility(WarScroll::Ability("Unholy Power", 1));
    ws.addAbility(WarScroll::Ability("Harbinger of Disaster", 3));
    ws.addSpell(WarScroll::Spell("Carrion Wiletide", 24, 24, 2, 5, 0, 1));
    ws.addKeyWords({"CHAOS", "BEASTMEN", "BRAYHERD", "HERO", "WIZARD",
      "GREAT BRAY-SHAMAN", "MALAGOR"});
    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eChaos);
    return ws;
  }

  WarScroll Great_Bray_shaman(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    ws.setCharacteristics(6, 5, 6, 6);
    ws.addWeapon(WarScroll::Weapon("Fetish Staff", 2, 1, 4, 4, 1, 3));
    ws.addAbility(WarScroll::Ability("Infuse with Bestial Vigour", 1));
    ws.addSpell(WarScroll::Spell("Savage Dominion"), 3);
    ws.addKeyWords({"CHAOS", "BEASTMEN", "BRAYHERD", "HERO", "WIZARD",
      "GREAT BRAY-SHAMAN"});
    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eChaos);
    return ws;
  }

  WarScroll Morghur_Master_of_Skulls(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    ws.setCharacteristics(6, 5, 10, 5);
    ws.addWeapon(WarScroll::Weapon("Twisted Staff", 2, 2, 4, 4, 1, 3));
    ws.addAbility(WarScroll::Ability("Spirit-essence of Chaos", 2));
    ws.addAbility(WarScroll::Ability("Aura of Transmutation", 3));
    ws.addSpell(WarScroll::Spell("Devolve"), 3);
    ws.addKeyWords({"CHAOS", "BEASTMAN", "BRAYHERD", "HERO", "WIZARD",
      "MORGHUR"});
    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eChaos);
    return ws;
  }

  WarScroll Gors(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    ws.setCharacteristics(6, 1, 5, 5);
    ws.setMinMaxUnitCount(5, 500);
    ws.addAbility(WarScroll::Ability("Anarchy and Mayhem", 2));                 // Conditional on Unit Size > 20
    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Foe-Render",
      WarScroll::UnitUpgrade::UnitUpgradeType::eChampion, 1));
    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Brayhorn",
      WarScroll::UnitUpgrade::UnitUpgradeType::eMusician, 1));
    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Banner Bearer",
      WarScroll::UnitUpgrade::UnitUpgradeType::eBannerBearer, 1));
    WarScroll::WeaponUpgrade dualAxeUpgrade(
      WarScroll::Weapon("Gor Blade", 1, 1, 4, 4, 0, 1),
      WarScroll::Ability("Rend and Tear", 1));
    ws.addWeaponUpgrade(dualAxeUpgrade);
    WarScroll::WeaponUpgrade shieldUpgrade(
      WarScroll::Weapon("Gor Blade", 1, 1, 4, 4, 0, 1),
      WarScroll::Ability("Beastshields", 1));
    shieldUpgrade.registerAbilityToReplace(WarScroll::Ability("Rend and Tear"));
    shieldUpgrade.registerCharacteristicToIncrease("Save", -1);
    ws.addWeaponUpgrade(shieldUpgrade);
    ws.addKeyWords({"CHAOS", "BEASTMEN", "BRAYHERD", "GORS"});
    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eChaos);
    return ws;
  }

  WarScroll Bestigors(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    ws.setCharacteristics(6, 1, 6, 4);
    ws.addWeapon(WarScroll::Weapon("Bestigor Great Axe", 1, 2, 4, 3, 1, 1));
    ws.setMinMaxUnitCount(5, 500);
    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Gouge Horn",
      WarScroll::UnitUpgrade::UnitUpgradeType::eChampion, 1));
    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Banner Bearer",
      WarScroll::UnitUpgrade::UnitUpgradeType::eBannerBearer, 1));
    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Brayhorn",
      WarScroll::UnitUpgrade::UnitUpgradeType::eMusician, 1));
    ws.addAbility(WarScroll::Ability("Despoilers", 1));
    ws.addKeyWords({"CHAOS", "BEASTMEN", "BRAYHERD", "BESTIGORS"});
    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eChaos);
    return ws;
  }

  WarScroll Tuskgor_Chariots(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    ws.setCharacteristics(10, 6, 6, 4);
    ws.addWeapon(WarScroll::Weapon("Bestigor Crew Great Axe", 1, 2, 4, 3, 1,
      1));
    ws.addWeapon(WarScroll::Weapon("Ungor Crew Shortspear", 2, 1, 5, 4, 0, 1));
    ws.addWeapon(WarScroll::Weapon("Tuskgors' Tusks and Hooves", 1, 4, 4, 3, 0,
      1));
    ws.setMinMaxUnitCount(1, 500);
    ws.addAbility(WarScroll::Ability("Tuskgor Charge", 1));
    ws.addKeyWords({"CHAOS", "BEASTMEN", "BRAYHERD", "TUSKGOR CHARIOTS"});
    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eChaos);
    return ws;
  }

  WarScroll Ungors(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    ws.setCharacteristics(6, 1, 4, 6);
    ws.setMinMaxUnitCount(10, 500);

    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Halfhorn",
      WarScroll::UnitUpgrade::UnitUpgradeType::eChampion, 1));
    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Banner Bearer",
      WarScroll::UnitUpgrade::UnitUpgradeType::eBannerBearer, 1));
    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Brayhorn",
      WarScroll::UnitUpgrade::UnitUpgradeType::eMusician, 1));
    WarScroll::UnitUpgrade shieldUpgrade("Half-shields",
      WarScroll::UnitUpgrade::UnitUpgradeType::eShield, 1);
    shieldUpgrade.registerCharacteristicToIncrease("Save", -1);
    ws.registerUnitUpgrade(shieldUpgrade);

    ws.addAbility(WarScroll::Ability("Baying Hatred", 2));                      // Dependent on unit size >= 20

    WarScroll::WeaponUpgrade maulUpgrade(
      WarScroll::Weapon("Ungor Maul", 1, 1, 4, 4, 0, 1),
      WarScroll::Ability());
    ws.addWeaponUpgrade(maulUpgrade);
    WarScroll::WeaponUpgrade spearUpgrade(
      WarScroll::Weapon("Ungor Shortspear", 2, 1, 5, 4, 0, 1),
      WarScroll::Ability());
    ws.addWeaponUpgrade(spearUpgrade);

    ws.addKeyWords({"CHAOS", "BEASTMEN", "BRAYHERD", "UNGOR"});

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eChaos);
    return ws;
  }

  WarScroll Ungor_Raiders(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    ws.setCharacteristics(6, 1, 4, 6);
    ws.setMinMaxUnitCount(10, 500);

    ws.addWeapon(WarScroll::Weapon("Raider Bow", 18, 1, 4, 4, 0, 1));
    ws.addWeapon(WarScroll::Weapon("Ungor Dagger", 1, 1, 5, 5, 0, 1));

    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Halfhorn",
      WarScroll::UnitUpgrade::UnitUpgradeType::eChampion, 1));
    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Banner Bearer",
      WarScroll::UnitUpgrade::UnitUpgradeType::eBannerBearer, 1));
    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Brayhorn",
      WarScroll::UnitUpgrade::UnitUpgradeType::eMusician, 1));

    ws.addAbility(WarScroll::Ability("Vile Invaders", 1));
    ws.addAbility(WarScroll::Ability("Baying Hatred", 2));                      // Dependent on unit size >= 20

    ws.addKeyWords({"CHAOS", "BEASTMEN", "BRAYHERD", "UNGOR RAIDERS"});

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eChaos);
    return ws;
  }

  WarScroll Doombull(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eChaos);
    return ws;
  }

  WarScroll Minotaurs(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eChaos);
    return ws;
  }

  WarScroll Cygor(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eChaos);
    return ws;
  }

  WarScroll Ghorgon(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eChaos);
    return ws;
  }

  WarScroll Centigors(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eChaos);
    return ws;
  }

  WarScroll Ghorros_Warhoof(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eChaos);
    return ws;
  }

  WarScroll Razorgors(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eChaos);
    return ws;
  }

  WarScroll Chaos_Warhounds_in_Beastmen(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eChaos);
    return ws;
  }

  WarScroll Harpies_in_Beastmen(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eChaos);
    return ws;
  }

  WarScroll Chaos_Spawn_in_Beastmen(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eChaos);
    return ws;
  }

  WarScroll Giant_in_Beastmen(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eChaos);
    return ws;
  }

  WarScroll Jabberslythe(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eChaos);
    return ws;
  }
}

BeastmenFaction::BeastmenFaction() :
  IFaction(nullptr)
{
  m_Units.push_back("");
  m_Units.push_back("Gorthor the Beastlord");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Gorthor_the_Beastlord, m_Units.back())));
  m_Units.push_back("Khazrak the One-Eye");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Khazrak_the_One_Eye, m_Units.back())));
  m_Units.push_back("Beastlord");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Beastlord, m_Units.back())));
  m_Units.push_back("Wargor Standard Bearer");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Wargor_Standard_Bearer, m_Units.back())));
  m_Units.push_back("Malagor, The Dark Omen");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Malagor_The_Dark_Omen, m_Units.back())));
  m_Units.push_back("Great Bray-shaman");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Great_Bray_shaman, m_Units.back())));
  m_Units.push_back("Morghur, Master of Skulls");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Morghur_Master_of_Skulls, m_Units.back())));
  m_Units.push_back("Gors");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Gors, m_Units.back())));
  m_Units.push_back("Bestigors");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Bestigors, m_Units.back())));
  m_Units.push_back("Tuskgor Chariots");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Tuskgor_Chariots, m_Units.back())));
  m_Units.push_back("Ungors");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Ungors, m_Units.back())));
  m_Units.push_back("Ungor Raiders");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Ungor_Raiders, m_Units.back())));
  m_Units.push_back("Doombull");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Doombull, m_Units.back())));
  m_Units.push_back("Minotaurs");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Minotaurs, m_Units.back())));
  m_Units.push_back("Cygor");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Cygor, m_Units.back())));
  m_Units.push_back("Ghorgon");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Ghorgon, m_Units.back())));
  m_Units.push_back("Centigors");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Centigors, m_Units.back())));
  m_Units.push_back("Ghorros Warhoof");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Ghorros_Warhoof, m_Units.back())));
  m_Units.push_back("Razorgors");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Razorgors, m_Units.back())));
  m_Units.push_back("Chaos Warhounds");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Chaos_Warhounds_in_Beastmen,
    m_Units.back())));
  m_Units.push_back("Harpies");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Harpies_in_Beastmen, m_Units.back())));
  m_Units.push_back("Chaos Spawn");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Chaos_Spawn_in_Beastmen, m_Units.back())));
  m_Units.push_back("Giant");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Giant_in_Beastmen, m_Units.back())));
  m_Units.push_back("Jabberslythe");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Jabberslythe, m_Units.back())));
}

const std::vector<std::string> &BeastmenFaction::getUnits() const
{
  return m_Units;
}

void BeastmenFaction::getWarScrolls(std::list<WarScroll>& warScrolls)
{
  for(const std::string &unit : m_Units) {
    if (unit.empty()) {
      continue;
    }
    WarScroll ws = m_NameToWarScroll[unit](unit);
    warScrolls.push_back(ws);
  }
}
