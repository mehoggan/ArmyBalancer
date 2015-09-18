#include <QDebug>

#include <iostream>

#include "factions.h"
#include "warscrollfactory.h"

WarScrollFactory &WarScrollFactory::getSharedInstance()
{
  static WarScrollFactory s_WarScrollFactory;
  return s_WarScrollFactory;
}

WarScroll WarScrollFactory::getWarScroll(const std::string &factionName,
  const std::string &unitName)
{
  FactionWarScrollDictionaryType::const_iterator it =
    m_WarScrolls.find(factionName);
  if (it != m_WarScrolls.end()) {
    WarScrollDictionaryType::const_iterator wsit = it->second.find(unitName);
    if (wsit != it->second.end()) {
      return wsit->second;
    } else {
      qWarning() << (QString("Failed to Find War Scroll for ") +
        factionName.c_str());
      return WarScroll();
    }
  } else {
    qWarning() << (QString("Failed to Find War Scroll for ") +
      unitName.c_str());
    Q_ASSERT(false);
  }
  return WarScroll();
}

WarScrollFactory::WarScrollFactory()
{
  getWarScrollsForFaction<BretonniaFaction>();
  getWarScrollsForFaction<BeastmenFaction>();
  getWarScrollsForFaction<BretonniaFaction>();
  getWarScrollsForFaction<DaemonsOfChaosKhorneFaction>();
  getWarScrollsForFaction<DaemonsOfChaosNurgleFaction>();
  getWarScrollsForFaction<DaemonsOfChaosSlaaneshFaction>();
  getWarScrollsForFaction<DaemonsOfChaosTzeentchFaction>();
  getWarScrollsForFaction<DarkElvesFaction>();
  getWarScrollsForFaction<DwarfsFaction>();
  getWarScrollsForFaction<HighElvesFaction>();
  getWarScrollsForFaction<KhorneBloodboundFaction>();
  getWarScrollsForFaction<LizardmenFaction>();
  getWarScrollsForFaction<NurgleRotbringersFaction>();
  getWarScrollsForFaction<OgreKingdomsFaction>();
  getWarScrollsForFaction<OrcsAndGoblinsFaction>();
  getWarScrollsForFaction<SkavenFaction>();
  getWarScrollsForFaction<SkavenPestilensFaction>();
  getWarScrollsForFaction<StormCastEternalsFaction>();
  getWarScrollsForFaction<SylvanethFaction>();
  getWarScrollsForFaction<TamurkhansHordeFaction>();
  getWarScrollsForFaction<TheEmpireFaction>();
  getWarScrollsForFaction<TheLegionOfAzgorhFaction>();
  getWarScrollsForFaction<TombKingsFaction>();
  getWarScrollsForFaction<VampireCountsFaction>();
  getWarScrollsForFaction<WarriorsOfChaosFaction>();
  getWarScrollsForFaction<WoodElvesFaction>();
}
