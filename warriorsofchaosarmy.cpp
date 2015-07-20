#include "warriorsofchaosarmy.h"

WarriorsOfChaosArmy::WarriorsOfChaosArmy() :
  IArmy(nullptr)
{
  m_Units.push_back(tr("Archaon, the Everchosen"));
  m_Units.push_back(tr("Be'lakor, Chaos Daemon Prince"));
  m_Units.push_back(tr("Daemon Prince"));
  m_Units.push_back(tr("Crom the Conquerer"));
  m_Units.push_back(tr("Chaos Lord"));
  m_Units.push_back(tr("Chaos Lord on Daemonic Mount"));
  m_Units.push_back(tr("Chaos Lord on Manticore"));
  m_Units.push_back(tr("Chaos Sorcerer Lord"));
  m_Units.push_back(tr("Chaos Sorcerer Lord on Manticore"));
  m_Units.push_back(tr("Wulfrik the Wanderer"));
  m_Units.push_back(tr("Exalted Hero with Battle Standard"));
  m_Units.push_back(tr("Warriors of Chaos"));
  m_Units.push_back(tr("Marauders of Chaos"));
  m_Units.push_back(tr("Forsaken"));
  m_Units.push_back(tr("Chaos Chariots"));
  m_Units.push_back(tr("Marauder Horsemen"));
  m_Units.push_back(tr("Chosen"));
  m_Units.push_back(tr("Chaos Knights"));
  m_Units.push_back(tr("Gorebeast Chariots"));
  m_Units.push_back(tr("Chaos Warshrine"));
  m_Units.push_back(tr("Hellcannon"));
  m_Units.push_back(tr("Chaos Spawn"));
  m_Units.push_back(tr("Valkia the Bloody"));
  m_Units.push_back(tr("Skarr Bloodwrath"));
  m_Units.push_back(tr("Scyla Anfingrimm"));
  m_Units.push_back(tr("Khorne Lord on Juggernaught"));
  m_Units.push_back(tr("Khorne Exalted Hero"));
  m_Units.push_back(tr("Wrathmongers"));
  m_Units.push_back(tr("Skullreapers"));
  m_Units.push_back(tr("Skullcrushers of Khorne"));
  m_Units.push_back(tr("The Glottkin"));
  m_Units.push_back(tr("Bloab Rotspawned"));
  m_Units.push_back(tr("Morbidex Twiceborn"));
  m_Units.push_back(tr("Orghotts Daemonspew"));
  m_Units.push_back(tr("Gutrot Spume"));
  m_Units.push_back(tr("Festus the Leechlord"));
  m_Units.push_back(tr("Nurgle Chaos Lord"));
  m_Units.push_back(tr("Nurgle Lord on Daemonic Mount"));
  m_Units.push_back(tr("Nurgle Chaos Sorcerer"));
  m_Units.push_back(tr("Putrid Blightkings"));
  m_Units.push_back(tr("Sigvald the Magnificient"));
  m_Units.push_back(tr("Chaos Lord of Slaanesh"));
  m_Units.push_back(tr("Lord of Slaanesh on Daemonic Mount"));
  m_Units.push_back(tr("Hellstriders of Slaanesh"));
  m_Units.push_back(tr("Galrauch"));
  m_Units.push_back(tr("Vilitch the Curseling"));
  m_Units.push_back(tr("Tzeentch Chaos Lord on Disc of Tzeentch"));
  m_Units.push_back(tr("Tzeentch Sorcerer Lord"));
  m_Units.push_back(tr("Chaos Warhounds"));
  m_Units.push_back(tr("Chaos Ogres"));
  m_Units.push_back(tr("Throgg"));
  m_Units.push_back(tr("Chaos Trolls"));
  m_Units.push_back(tr("Giant"));
  m_Units.push_back(tr("Chimera"));
  m_Units.push_back(tr("Drogon Ogre of Shaggoth"));
  m_Units.push_back(tr("Dragon Ogres"));
  m_Units.push_back(tr("Mutalith Vortex Beast"));
  m_Units.push_back(tr("Slaughterbrute"));
  m_Units.push_back(tr("Cockatrice"));
  m_Units.push_back(tr("Chaos Familiars"));
  m_Units.push_back(tr("Great Taurus"));
  m_Units.push_back(tr("Lammasu"));
}

const QStringList &WarriorsOfChaosArmy::getUnits()
{
  return m_Units;
}

void WarriorsOfChaosArmy::buildUiForBattleScroll(QQuickView *ui,
  int scrollIndex)
{

}
