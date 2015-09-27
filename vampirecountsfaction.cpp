#include "vampirecountsfaction.h"

namespace WarScrollGeneration
{
  WarScroll Nagash_Supreme_Lord_of_the_Undead(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Arkhan_the_Black(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Mannfred_Mortarch_of_Night(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Neferata_Mortarch_of_Blood(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Morghast_Harbingers(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Morghast_Archai(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Vlad_von_Carstein(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Count_Mannfred(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Konrad_von_Carstein(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Isabella_von_Carstein(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Vampire_Lord(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Vampire_Lord_on_Abyssal_Terror(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Coven_Throne(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Vargheists(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Blood_Knights(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Fell_Bats(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Bat_Swarms(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Heinrich_Kemmler_the_Lichemaster(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Necromancer(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Zombies(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Dire_Wolves(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Corpse_Cart(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Mortis_Engine(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Krell_Lord_of_Undeath(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Wight_King(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Skeleton_Warriors_in_Vampire_Counts(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Grave_Guard(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Black_Knights(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Strigoi_Ghoul_King(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Crypt_Ghouls(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Crypt_Horrors(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Varghulf(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Cairn_Wraith(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Tomb_Banshee(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Spirit_Hosts(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Hexwraiths(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Black_Coach(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Terrorgheist(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Zombie_Dragon(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }
}

VampireCountsFaction::VampireCountsFaction() :
  IFaction()
{
  m_Units.push_back("");
  m_Units.push_back("Nagash, Supreme Lord of the Undead");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Nagash_Supreme_Lord_of_the_Undead,
    m_Units.back())));
  m_Units.push_back("Arkhan the Black");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Arkhan_the_Black, m_Units.back())));
  m_Units.push_back("Mannfred, Mortarch of Night");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Mannfred_Mortarch_of_Night,
    m_Units.back())));
  m_Units.push_back("Neferata, Mortarch of Blood");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Neferata_Mortarch_of_Blood,
    m_Units.back())));
  m_Units.push_back("Morghast Harbingers");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Morghast_Harbingers, m_Units.back())));
  m_Units.push_back("Morghast Archai");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Morghast_Archai, m_Units.back())));
  m_Units.push_back("Vlad von Carstein");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Vlad_von_Carstein, m_Units.back())));
  m_Units.push_back("Count Mannfred");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Count_Mannfred, m_Units.back())));
  m_Units.push_back("Konrad von Carstein");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Konrad_von_Carstein, m_Units.back())));
  m_Units.push_back("Isabella von Carstein");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Isabella_von_Carstein, m_Units.back())));
  m_Units.push_back("Vampire Lord");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Vampire_Lord, m_Units.back())));
  m_Units.push_back("Vampire Lord on Abyssal Terror");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Vampire_Lord_on_Abyssal_Terror,
    m_Units.back())));
  m_Units.push_back("Coven Throne");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Coven_Throne, m_Units.back())));
  m_Units.push_back("Vargheists");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Vargheists, m_Units.back())));
  m_Units.push_back("Blood Knights");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Blood_Knights, m_Units.back())));
  m_Units.push_back("Fell Bats");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Fell_Bats, m_Units.back())));
  m_Units.push_back("Bat Swarms");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Bat_Swarms, m_Units.back())));
  m_Units.push_back("Heinrich Kemmler, the Lichemaster");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Heinrich_Kemmler_the_Lichemaster,
    m_Units.back())));
  m_Units.push_back("Necromancer");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Necromancer, m_Units.back())));
  m_Units.push_back("Zombies");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Zombies, m_Units.back())));
  m_Units.push_back("Dire Wolves");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Dire_Wolves, m_Units.back())));
  m_Units.push_back("Corpse Cart");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Corpse_Cart, m_Units.back())));
  m_Units.push_back("Mortis Engine");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Mortis_Engine, m_Units.back())));
  m_Units.push_back("Krell, Lord of Undeath");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Krell_Lord_of_Undeath, m_Units.back())));
  m_Units.push_back("Wight King");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Wight_King, m_Units.back())));
  m_Units.push_back("Skeleton Warriors");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Skeleton_Warriors_in_Vampire_Counts,
    m_Units.back())));
  m_Units.push_back("Grave Guard");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Grave_Guard, m_Units.back())));
  m_Units.push_back("Black Knights");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Black_Knights, m_Units.back())));
  m_Units.push_back("Strigoi Ghoul King");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Strigoi_Ghoul_King, m_Units.back())));
  m_Units.push_back("Crypt Ghouls");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Crypt_Ghouls, m_Units.back())));
  m_Units.push_back("Crypt Horrors");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Crypt_Horrors, m_Units.back())));
  m_Units.push_back("Varghulf");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Varghulf, m_Units.back())));
  m_Units.push_back("Cairn Wraith");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Cairn_Wraith, m_Units.back())));
  m_Units.push_back("Tomb Banshee");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Tomb_Banshee, m_Units.back())));
  m_Units.push_back("Spirit Hosts");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Spirit_Hosts, m_Units.back())));
  m_Units.push_back("Hexwraiths");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Hexwraiths, m_Units.back())));
  m_Units.push_back("Black Coach");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Black_Coach, m_Units.back())));
  m_Units.push_back("Terrorgheist");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Terrorgheist, m_Units.back())));
  m_Units.push_back("Zombie Dragon");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Zombie_Dragon, m_Units.back())));

  std::sort(m_Units.begin(), m_Units.end());
}

const std::vector<std::string> &VampireCountsFaction::getUnits() const
{
  return m_Units;
}

void VampireCountsFaction::getWarScrolls(std::list<WarScroll>& warScrolls)
{
  for (const std::string &unit : m_Units) {
    if (unit.empty()) {
      continue;
    }
    WarScroll ws = m_NameToWarScroll[unit](unit);
    warScrolls.push_back(ws);
  }
}
