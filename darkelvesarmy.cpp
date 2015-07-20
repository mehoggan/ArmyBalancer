#include "darkelvesarmy.h"

DarkElvesArmy::DarkElvesArmy() :
  IArmy(nullptr)
{
  m_Units.push_back(tr("Malekith, the Witch King"));
  m_Units.push_back(tr("Malus Darkblade"));
  m_Units.push_back(tr("Dreadlord"));
  m_Units.push_back(tr("Dreadlord on Black Dragon"));
  m_Units.push_back(tr("Dreadlord on Cold One"));
  m_Units.push_back(tr("Dark Elf Sorceress"));
  m_Units.push_back(tr("Sorceress on Black Dragon"));
  m_Units.push_back(tr("Sorceress on Cold One"));
  m_Units.push_back(tr("Cold One Knights"));
  m_Units.push_back(tr("Cold One Chariots"));
  m_Units.push_back(tr("Beastmaster on Manticore"));
  m_Units.push_back(tr("Black Ark Fleetmaster"));
  m_Units.push_back(tr("Lokhir Fellheart"));
  m_Units.push_back(tr("Black Ark Corsairs"));
  m_Units.push_back(tr("Master with Battle Standard"));
  m_Units.push_back(tr("Dreadspears"));
  m_Units.push_back(tr("Bleakswords"));
  m_Units.push_back(tr("Darkshards"));
  m_Units.push_back(tr("Dark Riders"));
  m_Units.push_back(tr("Black Guard of Naggarond"));
  m_Units.push_back(tr("Shades"));
  m_Units.push_back(tr("Reaper Bolt Thrower"));
  m_Units.push_back(tr("Harpies"));
  m_Units.push_back(tr("Scourgerunner Chariots"));
  m_Units.push_back(tr("War Hydra"));
  m_Units.push_back(tr("Doomfire Warlocks"));
  m_Units.push_back(tr("Kharibdyss"));
  m_Units.push_back(tr("Sisters of Slaughter"));
  m_Units.push_back(tr("Morathi"));
  m_Units.push_back(tr("Bloodwrack Medusae"));
  m_Units.push_back(tr("Bloodwrack Shrine"));
  m_Units.push_back(tr("Cauldron of Blood"));
  m_Units.push_back(tr("Witch Elves"));
  m_Units.push_back(tr("Hellbron"));
  m_Units.push_back(tr("Shadowblade"));
  m_Units.push_back(tr("Death Hag"));
  m_Units.push_back(tr("Dark Elf Assassin"));
  m_Units.push_back(tr("Har Ganeth Executioners"));
}

const QStringList &DarkElvesArmy::getUnits()
{
  return m_Units;
}

void DarkElvesArmy::buildUiForBattleScroll(QQuickView *ui, int scrollIndex)
{

}
