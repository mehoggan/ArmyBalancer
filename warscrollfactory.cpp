#include "factions.h"
#include "warscrollfactory.h"

#include <QDebug>

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
  {
    WarScrollDictionaryType beastmenDictionary;
    BeastmenFaction beastmen;
    std::list<WarScroll> beastmenWarScrolls;
    beastmen.getWarScrolls(beastmenWarScrolls);
    for (WarScroll ws : beastmenWarScrolls) {
      std::string key = ws.getTitle();
      key = key = key;
      beastmenDictionary.insert(std::make_pair(key, ws));
    }
    m_WarScrolls[beastmen.getName()] = beastmenDictionary;
  }

  {
    WarScrollDictionaryType bretonniaDictionary;
    BretonniaFaction bretonnia;
    std::list<WarScroll> bretonniaWarScrolls;
    bretonnia.getWarScrolls(bretonniaWarScrolls);
    for (const WarScroll &ws : bretonniaWarScrolls) {
      bretonniaDictionary.insert(std::make_pair(ws.getTitle(), ws));
    }
    m_WarScrolls[bretonnia.getName()] = bretonniaDictionary;
  }

  {
    WarScrollDictionaryType daemonsOfChaosKhorneDictionary;
    DaemonsOfChaosKhorneFaction daemonsOfChaosKhorne;
    std::list<WarScroll> daemonsOfChaosKhorneWarScrolls;
    daemonsOfChaosKhorne.getWarScrolls(daemonsOfChaosKhorneWarScrolls);
    for (const WarScroll &ws : daemonsOfChaosKhorneWarScrolls) {
      daemonsOfChaosKhorneDictionary.insert(std::make_pair(ws.getTitle(), ws));
    }
    m_WarScrolls[daemonsOfChaosKhorne.getName()] =
      daemonsOfChaosKhorneDictionary;
  }

  {
    WarScrollDictionaryType daemonsOfChaosNurgleDictionary;
    DaemonsOfChaosNurgleFaction daemonsOfChaosNurgle;
    std::list<WarScroll> daemonsOfChaosNurgleWarScrolls;
    daemonsOfChaosNurgle.getWarScrolls(daemonsOfChaosNurgleWarScrolls);
    for (const WarScroll &ws : daemonsOfChaosNurgleWarScrolls) {
      daemonsOfChaosNurgleDictionary.insert(std::make_pair(ws.getTitle(), ws));
    }
    m_WarScrolls[daemonsOfChaosNurgle.getName()] =
      daemonsOfChaosNurgleDictionary;
  }

  {
    WarScrollDictionaryType daemonsOfChaosSlaaneshDictionary;
    DaemonsOfChaosSlaaneshFaction daemonsOfChaosSlaanesh;
    std::list<WarScroll> daemonsOfChaosSlaaneshWarScrolls;
    daemonsOfChaosSlaanesh.getWarScrolls(daemonsOfChaosSlaaneshWarScrolls);
    for (const WarScroll &ws : daemonsOfChaosSlaaneshWarScrolls) {
      daemonsOfChaosSlaaneshDictionary.insert(std::make_pair(ws.getTitle(),
      ws));
    }
    m_WarScrolls[daemonsOfChaosSlaanesh.getName()] =
      daemonsOfChaosSlaaneshDictionary;
  }

  {
    WarScrollDictionaryType daemonsOfChaosTzeentchDictionary;
    DaemonsOfChaosTzeentchFaction daemonsOfChaosTzeentch;
    std::list<WarScroll> daemonsOfChaosTzeentchWarScrolls;
    daemonsOfChaosTzeentch.getWarScrolls(daemonsOfChaosTzeentchWarScrolls);
    for (const WarScroll &ws : daemonsOfChaosTzeentchWarScrolls) {
      daemonsOfChaosTzeentchDictionary.insert(std::make_pair(ws.getTitle(),
      ws));
    }
    m_WarScrolls[daemonsOfChaosTzeentch.getName()] =
      daemonsOfChaosTzeentchDictionary;
  }

  {
    WarScrollDictionaryType darkelvesDictionary;
    DarkElvesFaction darkelves;
    std::list<WarScroll> darkelvesWarScrolls;
    darkelves.getWarScrolls(darkelvesWarScrolls);
    for (const WarScroll &ws : darkelvesWarScrolls) {
      darkelvesDictionary.insert(std::make_pair(ws.getTitle(), ws));
    }
    m_WarScrolls[darkelves.getName()] = darkelvesDictionary;
  }

  {
    WarScrollDictionaryType dwarfsDictionary;
    DwarfsFaction dwarfs;
    std::list<WarScroll> dwarfsWarScrolls;
    dwarfs.getWarScrolls(dwarfsWarScrolls);
    for (const WarScroll &ws : dwarfsWarScrolls) {
      dwarfsDictionary.insert(std::make_pair(ws.getTitle(), ws));
    }
    m_WarScrolls[dwarfs.getName()] = dwarfsDictionary;
  }

  {
    WarScrollDictionaryType highElvesDictionary;
    HighElvesFaction highElves;
    std::list<WarScroll> highElvesWarScrolls;
    highElves.getWarScrolls(highElvesWarScrolls);
    for (const WarScroll &ws : highElvesWarScrolls) {
      highElvesDictionary.insert(std::make_pair(ws.getTitle(), ws));
    }
    m_WarScrolls[highElves.getName()] = highElvesDictionary;
  }

  {
    WarScrollDictionaryType lizardmenDictionary;
    LizardmenFaction lizardmen;
    std::list<WarScroll> lizardmenWarScrolls;
    lizardmen.getWarScrolls(lizardmenWarScrolls);
    for (const WarScroll &ws : lizardmenWarScrolls) {
      lizardmenDictionary.insert(std::make_pair(ws.getTitle(), ws));
    }
    m_WarScrolls[lizardmen.getName()] = lizardmenDictionary;
  }

  {
    WarScrollDictionaryType ogreKingdomsDictionary;
    OgreKingdomsFaction ogreKingdoms;
    std::list<WarScroll> ogreKingdomsWarScrolls;
    ogreKingdoms.getWarScrolls(ogreKingdomsWarScrolls);
    for (const WarScroll &ws : ogreKingdomsWarScrolls) {
      ogreKingdomsDictionary.insert(std::make_pair(ws.getTitle(), ws));
    }
    m_WarScrolls[ogreKingdoms.getName()] = ogreKingdomsDictionary;
  }

  {
    WarScrollDictionaryType orcsAndGoblinsDictionary;
    OrcsAndGoblinsFaction orcsAndGoblins;
    std::list<WarScroll> orcsAndGoblinsWarScrolls;
    orcsAndGoblins.getWarScrolls(orcsAndGoblinsWarScrolls);
    for (const WarScroll &ws : orcsAndGoblinsWarScrolls) {
      orcsAndGoblinsDictionary.insert(std::make_pair(ws.getTitle(), ws));
    }
    m_WarScrolls[orcsAndGoblins.getName()] = orcsAndGoblinsDictionary;
  }

  {
    WarScrollDictionaryType skavenDictionary;
    SkavenFaction skaven;
    std::list<WarScroll> skavenWarScrolls;
    skaven.getWarScrolls(skavenWarScrolls);
    for (const WarScroll &ws : skavenWarScrolls) {
      skavenDictionary.insert(std::make_pair(ws.getTitle(), ws));
    }
    m_WarScrolls[skaven.getName()] = skavenDictionary;
  }

  {
    WarScrollDictionaryType theEmpireDictionary;
    TheEmpireFaction theEmpire;
    std::list<WarScroll> theEmpireWarScrolls;
    theEmpire.getWarScrolls(theEmpireWarScrolls);
    for (const WarScroll &ws : theEmpireWarScrolls) {
      theEmpireDictionary.insert(std::make_pair(ws.getTitle(), ws));
    }
    m_WarScrolls[theEmpire.getName()] = theEmpireDictionary;
  }

  {
    WarScrollDictionaryType tombKingsDictionary;
    TombKingsFaction tombKings;
    std::list<WarScroll> tombKingsWarScrolls;
    tombKings.getWarScrolls(tombKingsWarScrolls);
    for (const WarScroll &ws : tombKingsWarScrolls) {
      tombKingsDictionary.insert(std::make_pair(ws.getTitle(), ws));
    }
    m_WarScrolls[tombKings.getName()] = tombKingsDictionary;
  }

  {
    WarScrollDictionaryType vampireCountsDictionary;
    VampireCountsFaction vampireCounts;
    std::list<WarScroll> vampireCountsWarScrolls;
    vampireCounts.getWarScrolls(vampireCountsWarScrolls);
    for (const WarScroll &ws : vampireCountsWarScrolls) {
      vampireCountsDictionary.insert(std::make_pair(ws.getTitle(), ws));
    }
    m_WarScrolls[vampireCounts.getName()] = vampireCountsDictionary;
  }

  {
    WarScrollDictionaryType warriorsOfChaosDictionary;
    WarriorsOfChaosFaction warriorsOfChaos;
    std::list<WarScroll> warriorsOfChaosWarScrolls;
    warriorsOfChaos.getWarScrolls(warriorsOfChaosWarScrolls);
    for (const WarScroll &ws : warriorsOfChaosWarScrolls) {
      warriorsOfChaosDictionary.insert(std::make_pair(ws.getTitle(), ws));
    }
    m_WarScrolls[warriorsOfChaos.getName()] = warriorsOfChaosDictionary;
  }

  {
    WarScrollDictionaryType woodElvesDictionary;
    WoodElvesFaction woodElves;
    std::list<WarScroll> woodElvesWarScrolls;
    woodElves.getWarScrolls(woodElvesWarScrolls);
    for (const WarScroll &ws : woodElvesWarScrolls) {
      woodElvesDictionary.insert(std::make_pair(ws.getTitle(), ws));
    }
    m_WarScrolls[woodElves.getName()] = woodElvesDictionary;
  }
}

