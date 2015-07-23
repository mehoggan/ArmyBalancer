#include "darkelvesfaction.h"

namespace WarScrollGeneration
{
  WarScroll Malekith_the_Witch_King(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Malus_Darkblade(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Dreadlord(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Dreadlord_on_Black_Dragon(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Dreadlord_on_Cold_One(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Dark_Elf_Sorceress(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Sorceress_on_Black_Dragon(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Sorceress_on_Cold_One(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Cold_One_Knights(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Cold_One_Chariots(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Beastmaster_on_Manticore(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Black_Ark_Fleetmaster(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Lokhir_Fellheart(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Black_Ark_Corsairs(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Master_with_Battle_Standard(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Dreadspears(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Bleakswords(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Darkshards(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Dark_Riders(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Black_Guard_of_Naggarond(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Shades(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Reaper_Bolt_Thrower(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Harpies_in_DarkElves(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Scourgerunner_Chariots(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll War_Hydra(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Doomfire_Warlocks(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Kharibdyss(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Sisters_of_Slaughter(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Morathi(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Bloodwrack_Medusae(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Bloodwrack_Shrine(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Cauldron_of_Blood(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Witch_Elves(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Hellbron(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Shadowblade(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Death_Hag(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Dark_Elf_Assassin(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Har_Ganeth_Executioners(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }
}

DarkElvesFaction::DarkElvesFaction() :
  IFaction(nullptr)
{
  m_Units.push_back(tr(""));
  m_Units.push_back(tr("Malekith, the Witch King"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Malekith_the_Witch_King, m_Units.back()));
  m_Units.push_back(tr("Malus Darkblade"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Malus_Darkblade, m_Units.back()));
  m_Units.push_back(tr("Dreadlord"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Dreadlord, m_Units.back()));
  m_Units.push_back(tr("Dreadlord on Black Dragon"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Dreadlord_on_Black_Dragon, m_Units.back()));
  m_Units.push_back(tr("Dreadlord on Cold One"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Dreadlord_on_Cold_One, m_Units.back()));
  m_Units.push_back(tr("Dark Elf Sorceress"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Dark_Elf_Sorceress, m_Units.back()));
  m_Units.push_back(tr("Sorceress on Black Dragon"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Sorceress_on_Black_Dragon, m_Units.back()));
  m_Units.push_back(tr("Sorceress on Cold One"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Sorceress_on_Cold_One, m_Units.back()));
  m_Units.push_back(tr("Cold One Knights"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Cold_One_Knights, m_Units.back()));
  m_Units.push_back(tr("Cold One Chariots"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Cold_One_Chariots, m_Units.back()));
  m_Units.push_back(tr("Beastmaster on Manticore"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Beastmaster_on_Manticore, m_Units.back()));
  m_Units.push_back(tr("Black Ark Fleetmaster"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Black_Ark_Fleetmaster, m_Units.back()));
  m_Units.push_back(tr("Lokhir Fellheart"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Lokhir_Fellheart, m_Units.back()));
  m_Units.push_back(tr("Black Ark Corsairs"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Black_Ark_Corsairs, m_Units.back()));
  m_Units.push_back(tr("Master with Battle Standard"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Master_with_Battle_Standard,
    m_Units.back()));
  m_Units.push_back(tr("Dreadspears"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Dreadspears, m_Units.back()));
  m_Units.push_back(tr("Bleakswords"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Bleakswords, m_Units.back()));
  m_Units.push_back(tr("Darkshards"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Darkshards, m_Units.back()));
  m_Units.push_back(tr("Dark Riders"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Dark_Riders, m_Units.back()));
  m_Units.push_back(tr("Black Guard of Naggarond"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Black_Guard_of_Naggarond, m_Units.back()));
  m_Units.push_back(tr("Shades"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Shades, m_Units.back()));
  m_Units.push_back(tr("Reaper Bolt Thrower"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Reaper_Bolt_Thrower, m_Units.back()));
  m_Units.push_back(tr("Harpies"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Harpies_in_DarkElves, m_Units.back()));
  m_Units.push_back(tr("Scourgerunner Chariots"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Scourgerunner_Chariots, m_Units.back()));
  m_Units.push_back(tr("War Hydra"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::War_Hydra, m_Units.back()));
  m_Units.push_back(tr("Doomfire Warlocks"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Doomfire_Warlocks, m_Units.back()));
  m_Units.push_back(tr("Kharibdyss"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Kharibdyss, m_Units.back()));
  m_Units.push_back(tr("Sisters of Slaughter"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Sisters_of_Slaughter, m_Units.back()));
  m_Units.push_back(tr("Morathi"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Morathi, m_Units.back()));
  m_Units.push_back(tr("Bloodwrack Medusae"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Bloodwrack_Medusae, m_Units.back()));
  m_Units.push_back(tr("Bloodwrack Shrine"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Bloodwrack_Shrine, m_Units.back()));
  m_Units.push_back(tr("Cauldron of Blood"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Cauldron_of_Blood, m_Units.back()));
  m_Units.push_back(tr("Witch Elves"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Witch_Elves, m_Units.back()));
  m_Units.push_back(tr("Hellbron"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Hellbron, m_Units.back()));
  m_Units.push_back(tr("Shadowblade"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Shadowblade, m_Units.back()));
  m_Units.push_back(tr("Death Hag"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Death_Hag, m_Units.back()));
  m_Units.push_back(tr("Dark Elf Assassin"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Dark_Elf_Assassin, m_Units.back()));
  m_Units.push_back(tr("Har Ganeth Executioners"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Har_Ganeth_Executioners, m_Units.back()));
}

const QStringList &DarkElvesFaction::getUnits() const
{
  return m_Units;
}

QList<WarScroll> DarkElvesFaction::getWarScrolls() const
{
  QList<WarScroll> warScrolls;
  for (auto ws : m_NameToWarScroll.toStdMap()) {
    warScrolls.push_back(ws.second(ws.first));
  }
  return warScrolls;
}
