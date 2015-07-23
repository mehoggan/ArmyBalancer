#include "vampirecountsfaction.h"

namespace WarScrollGeneration
{
  WarScroll Nagash_Supreme_Lord_of_the_Undead(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Arkhan_the_Black(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Mannfred_Mortarch_of_Night(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Neferata_Mortarch_of_Blood(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Morghast_Harbingers(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Morghast_Archai(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Vlad_von_Carstein(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Count_Mannfred(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Konrad_von_Carstein(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Isabella_von_Carstein(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Vampire_Lord(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Vampire_Lord_on_Abyssal_Terror(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Coven_Throne(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Vargheists(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Blood_Knights(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Fell_Bats(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Bat_Swarms(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Heinrich_Kemmler_the_Lichemaster(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Necromancer(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Zombies(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Dire_Wolves(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Corpse_Cart(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Mortis_Engine(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Krell_Lord_of_Undeath(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Wight_King(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Skeleton_Warriors_in_Vampire_Counts(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Grave_Guard(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Black_Knights(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Strigoi_Ghoul_King(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Crypt_Ghouls(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Crypt_Horrors(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Varghulf(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Cairn_Wraith(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Tomb_Banshee(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Spirit_Hosts(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Hexwraiths(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Black_Coach(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Terrorgheist(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Zombie_Dragon(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }
}

VampireCountsFaction::VampireCountsFaction() :
  IFaction(nullptr)
{
  m_Units.push_back(tr(""));
  m_Units.push_back(tr("Nagash, Supreme Lord of the Undead"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Nagash_Supreme_Lord_of_the_Undead,
    m_Units.back()));
  m_Units.push_back(tr("Arkhan the Black"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Arkhan_the_Black, m_Units.back()));
  m_Units.push_back(tr("Mannfred, Mortarch of Night"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Mannfred_Mortarch_of_Night,
    m_Units.back()));
  m_Units.push_back(tr("Neferata, Mortarch of Blood"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Neferata_Mortarch_of_Blood,
    m_Units.back()));
  m_Units.push_back(tr("Morghast Harbingers"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Morghast_Harbingers, m_Units.back()));
  m_Units.push_back(tr("Morghast Archai"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Morghast_Archai, m_Units.back()));
  m_Units.push_back(tr("Vlad von Carstein"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Vlad_von_Carstein, m_Units.back()));
  m_Units.push_back(tr("Count Mannfred"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Count_Mannfred, m_Units.back()));
  m_Units.push_back(tr("Konrad von Carstein"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Konrad_von_Carstein, m_Units.back()));
  m_Units.push_back(tr("Isabella von Carstein"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Isabella_von_Carstein, m_Units.back()));
  m_Units.push_back(tr("Vampire Lord"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Vampire_Lord, m_Units.back()));
  m_Units.push_back(tr("Vampire Lord on Abyssal Terror"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Vampire_Lord_on_Abyssal_Terror,
    m_Units.back()));
  m_Units.push_back(tr("Coven Throne"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Coven_Throne, m_Units.back()));
  m_Units.push_back(tr("Vargheists"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Vargheists, m_Units.back()));
  m_Units.push_back(tr("Blood Knights"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Blood_Knights, m_Units.back()));
  m_Units.push_back(tr("Fell Bats"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Fell_Bats, m_Units.back()));
  m_Units.push_back(tr("Bat Swarms"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Bat_Swarms, m_Units.back()));
  m_Units.push_back(tr("Heinrich Kemmler, the Lichemaster"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Heinrich_Kemmler_the_Lichemaster,
    m_Units.back()));
  m_Units.push_back(tr("Necromancer"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Necromancer, m_Units.back()));
  m_Units.push_back(tr("Zombies"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Zombies, m_Units.back()));
  m_Units.push_back(tr("Dire Wolves"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Dire_Wolves, m_Units.back()));
  m_Units.push_back(tr("Corpse Cart"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Corpse_Cart, m_Units.back()));
  m_Units.push_back(tr("Mortis Engine"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Mortis_Engine, m_Units.back()));
  m_Units.push_back(tr("Krell, Lord of Undeath"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Krell_Lord_of_Undeath, m_Units.back()));
  m_Units.push_back(tr("Wight King"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Wight_King, m_Units.back()));
  m_Units.push_back(tr("Skeleton Warriors"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Skeleton_Warriors_in_Vampire_Counts,
    m_Units.back()));
  m_Units.push_back(tr("Grave Guard"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Grave_Guard, m_Units.back()));
  m_Units.push_back(tr("Black Knights"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Black_Knights, m_Units.back()));
  m_Units.push_back(tr("Strigoi Ghoul King"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Strigoi_Ghoul_King, m_Units.back()));
  m_Units.push_back(tr("Crypt Ghouls"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Crypt_Ghouls, m_Units.back()));
  m_Units.push_back(tr("Crypt Horrors"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Crypt_Horrors, m_Units.back()));
  m_Units.push_back(tr("Varghulf"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Varghulf, m_Units.back()));
  m_Units.push_back(tr("Cairn Wraith"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Cairn_Wraith, m_Units.back()));
  m_Units.push_back(tr("Tomb Banshee"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Tomb_Banshee, m_Units.back()));
  m_Units.push_back(tr("Spirit Hosts"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Spirit_Hosts, m_Units.back()));
  m_Units.push_back(tr("Hexwraiths"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Hexwraiths, m_Units.back()));
  m_Units.push_back(tr("Black Coach"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Black_Coach, m_Units.back()));
  m_Units.push_back(tr("Terrorgheist"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Terrorgheist, m_Units.back()));
  m_Units.push_back(tr("Zombie Dragon"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Zombie_Dragon, m_Units.back()));
}

const QStringList &VampireCountsFaction::getUnits() const
{
  return m_Units;
}

QList<WarScroll> VampireCountsFaction::getWarScrolls() const
{
  QList<WarScroll> warScrolls;
  for (auto ws : m_NameToWarScroll.toStdMap()) {
    warScrolls.push_back(ws.second(ws.first));
  }
  return warScrolls;
}
