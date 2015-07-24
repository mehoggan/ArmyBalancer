#include "darkelvesfaction.h"

namespace WarScrollGeneration
{
  WarScroll Malekith_the_Witch_King(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Malus_Darkblade(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Dreadlord(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Dreadlord_on_Black_Dragon(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Dreadlord_on_Cold_One(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Dark_Elf_Sorceress(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Sorceress_on_Black_Dragon(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Sorceress_on_Cold_One(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Cold_One_Knights(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Cold_One_Chariots(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Beastmaster_on_Manticore(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Black_Ark_Fleetmaster(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Lokhir_Fellheart(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Black_Ark_Corsairs(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Master_with_Battle_Standard(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Dreadspears(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Bleakswords(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Darkshards(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Dark_Riders(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Black_Guard_of_Naggarond(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Shades(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Reaper_Bolt_Thrower(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Harpies_in_DarkElves(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Scourgerunner_Chariots(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll War_Hydra(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Doomfire_Warlocks(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Kharibdyss(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Sisters_of_Slaughter(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Morathi(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Bloodwrack_Medusae(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Bloodwrack_Shrine(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Cauldron_of_Blood(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Witch_Elves(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Hellbron(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Shadowblade(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Death_Hag(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Dark_Elf_Assassin(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Har_Ganeth_Executioners(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
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
  m_Units.push_back("Hellbron");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Hellbron, m_Units.back())));
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
