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
      name});
    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eChaos);
    return ws;
  }

  WarScroll Beastlord(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    ws.setCharacteristics(6, 5, 7, 4);
    ws.addWeapon(WarScroll::Weapon("Man-ripper Axe", 1, 6, 3, 3, 1, 1));
    ws.addAbility(WarScroll::Ability("Dual-axes", 1));
    ws.addAbility(WarScroll::Ability("Hatred of Heros", 1));
    ws.addAbility(WarScroll::Ability("Grisly Trophy", 2, true));
    ws.addKeyWords({"CHAOS", "BEASTMEN", "BRAYHERD", "HERO", "BEASTLORD"});
    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eChaos);

    WarScroll::WeaponUpgrade shieldUpgrade(
      WarScroll::Weapon(),
      WarScroll::Ability("Brayshield", 2));
    shieldUpgrade.registerAbilityToReplace(WarScroll::Ability("Dual-axes"));
    ws.addWeaponUpgrade(shieldUpgrade);
    WarScroll::WeaponUpgrade greatWeaponUpgrade(
      WarScroll::Weapon("Man-render Great Axe", 1, 3, 3, 3, 2, 2),
      WarScroll::Ability());
    greatWeaponUpgrade.registerAbilityToReplace(
      WarScroll::Ability("Dual-axes"));

    return ws;
  }

  WarScroll Wargor_Standard_Bearer(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eChaos);
    return ws;
  }

  WarScroll Malagor_The_Dark_Omen(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eChaos);
    return ws;
  }

  WarScroll Great_Bray_shaman(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eChaos);
    return ws;
  }

  WarScroll Morghur_Master_of_Skulls(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eChaos);
    return ws;
  }

  WarScroll Gors(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eChaos);
    return ws;
  }

  WarScroll Bestigors(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eChaos);
    return ws;
  }

  WarScroll Tuskgor_Chariots(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eChaos);
    return ws;
  }

  WarScroll Ungors(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eChaos);
    return ws;
  }

  WarScroll Ungor_Raiders(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

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
