#include "darkelvesfaction.h"

namespace WarScrollGeneration
{
  WarScroll Malekith_the_Witch_King()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll Malus_Darkblade()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll Dreadlord()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll Dreadlord_on_Black_Dragon()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll Dreadlord_on_Cold_One()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll Dark_Elf_Sorceress()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll Sorceress_on_Black_Dragon()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll Sorceress_on_Cold_One()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll Cold_One_Knights()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll Cold_One_Chariots()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll Beastmaster_on_Manticore()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll Black_Ark_Fleetmaster()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll Lokhir_Fellheart()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll Black_Ark_Corsairs()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll Master_with_Battle_Standard()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll Dreadspears()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll Bleakswords()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll Darkshards()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll Dark_Riders()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll Black_Guard_of_Naggarond()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll Shades()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll Reaper_Bolt_Thrower()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll Harpies_in_DarkElves()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll Scourgerunner_Chariots()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll War_Hydra()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll Doomfire_Warlocks()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll Kharibdyss()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll Sisters_of_Slaughter()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll Morathi()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll Bloodwrack_Medusae()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll Bloodwrack_Shrine()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll Cauldron_of_Blood()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll Witch_Elves()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll Hellbron()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll Shadowblade()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll Death_Hag()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll Dark_Elf_Assassin()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll Har_Ganeth_Executioners()
  {
    WarScroll ws;
    return ws;
  }
}

DarkElvesFaction::DarkElvesFaction() :
  IFaction(nullptr)
{
  m_Units.push_back(tr(""));
  m_Units.push_back(tr("Malekith, the Witch King"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::Malekith_the_Witch_King);
  m_Units.push_back(tr("Malus Darkblade"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::Malus_Darkblade);
  m_Units.push_back(tr("Dreadlord"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::Dreadlord);
  m_Units.push_back(tr("Dreadlord on Black Dragon"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::Dreadlord_on_Black_Dragon);
  m_Units.push_back(tr("Dreadlord on Cold One"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::Dreadlord_on_Cold_One);
  m_Units.push_back(tr("Dark Elf Sorceress"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::Dark_Elf_Sorceress);
  m_Units.push_back(tr("Sorceress on Black Dragon"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::Sorceress_on_Black_Dragon);
  m_Units.push_back(tr("Sorceress on Cold One"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::Sorceress_on_Cold_One);
  m_Units.push_back(tr("Cold One Knights"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::Cold_One_Knights);
  m_Units.push_back(tr("Cold One Chariots"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::Cold_One_Chariots);
  m_Units.push_back(tr("Beastmaster on Manticore"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::Beastmaster_on_Manticore);
  m_Units.push_back(tr("Black Ark Fleetmaster"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::Black_Ark_Fleetmaster);
  m_Units.push_back(tr("Lokhir Fellheart"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::Lokhir_Fellheart);
  m_Units.push_back(tr("Black Ark Corsairs"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::Black_Ark_Corsairs);
  m_Units.push_back(tr("Master with Battle Standard"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::Master_with_Battle_Standard);
  m_Units.push_back(tr("Dreadspears"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::Dreadspears);
  m_Units.push_back(tr("Bleakswords"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::Bleakswords);
  m_Units.push_back(tr("Darkshards"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::Darkshards);
  m_Units.push_back(tr("Dark Riders"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::Dark_Riders);
  m_Units.push_back(tr("Black Guard of Naggarond"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::Black_Guard_of_Naggarond);
  m_Units.push_back(tr("Shades"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::Shades);
  m_Units.push_back(tr("Reaper Bolt Thrower"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::Reaper_Bolt_Thrower);
  m_Units.push_back(tr("Harpies"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::Harpies_in_DarkElves);
  m_Units.push_back(tr("Scourgerunner Chariots"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::Scourgerunner_Chariots);
  m_Units.push_back(tr("War Hydra"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::War_Hydra);
  m_Units.push_back(tr("Doomfire Warlocks"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::Doomfire_Warlocks);
  m_Units.push_back(tr("Kharibdyss"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::Kharibdyss);
  m_Units.push_back(tr("Sisters of Slaughter"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::Sisters_of_Slaughter);
  m_Units.push_back(tr("Morathi"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::Morathi);
  m_Units.push_back(tr("Bloodwrack Medusae"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::Bloodwrack_Medusae);
  m_Units.push_back(tr("Bloodwrack Shrine"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::Bloodwrack_Shrine);
  m_Units.push_back(tr("Cauldron of Blood"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::Cauldron_of_Blood);
  m_Units.push_back(tr("Witch Elves"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::Witch_Elves);
  m_Units.push_back(tr("Hellbron"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::Hellbron);
  m_Units.push_back(tr("Shadowblade"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::Shadowblade);
  m_Units.push_back(tr("Death Hag"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::Death_Hag);
  m_Units.push_back(tr("Dark Elf Assassin"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::Dark_Elf_Assassin);
  m_Units.push_back(tr("Har Ganeth Executioners"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::Har_Ganeth_Executioners);
}

const QStringList &DarkElvesFaction::getUnits() const
{
  return m_Units;
}

QList<WarScroll> DarkElvesFaction::getWarScrolls() const
{
  QList<WarScroll> warScrolls;
  return warScrolls;
}
