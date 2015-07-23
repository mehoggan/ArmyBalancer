#include "factions.h"
#include "warscrollfactory.h"

#include <QDebug>

WarScrollFactory &WarScrollFactory::getSharedInstance()
{
  static WarScrollFactory s_WarScrollFactory;
  return s_WarScrollFactory;
}

WarScroll WarScrollFactory::getWarScroll(const QString &factionName,
  const QString &unitName)
{
  FactionWarScrollDictionaryType::const_iterator it =
    m_WarScrolls.find(factionName);
  if (it != m_WarScrolls.end()) {
    WarScrollDictionaryType::const_iterator wsit = it->find(unitName);
    if (wsit != it->end()) {
      return *wsit;
    } else {
      qWarning() << (QString("Failed to Find War Scroll for ") + factionName);
      return WarScroll();
    }
  } else {
    qWarning() << (QString("Failed to Find War Scroll for ") + unitName);
    Q_ASSERT(false);
  }
  return WarScroll();
}

WarScrollFactory::WarScrollFactory()
{
  {
    WarScrollDictionaryType beastmenDictionary;
    BeastmenFaction beastmen;
    QList<WarScroll> beastmenWarScrolls = beastmen.getWarScrolls();
    foreach(const WarScroll &ws, beastmenWarScrolls) {
      beastmenDictionary[ws.getTitle()] = ws;
    }
    m_WarScrolls[beastmen.getName()] = beastmenDictionary;
  }

  {
    WarScrollDictionaryType bretonniaDictionary;
    BretonniaFaction bretonnia;
    QList<WarScroll> bretonniaWarScrolls = bretonnia.getWarScrolls();
    foreach(const WarScroll &ws, bretonniaWarScrolls) {
      bretonniaDictionary[ws.getTitle()] = ws;
    }
    m_WarScrolls[bretonnia.getName()] = bretonniaDictionary;
  }

  {
    WarScrollDictionaryType daemonsOfChaosKhorneDictionary;
    DaemonsOfChaosKhorneFaction daemonsOfChaosKhorne;
    QList<WarScroll> daemonsOfChaosKhorneWarScrolls =
      daemonsOfChaosKhorne.getWarScrolls();
    foreach(const WarScroll &ws, daemonsOfChaosKhorneWarScrolls) {
      daemonsOfChaosKhorneDictionary[ws.getTitle()] = ws;
    }
    m_WarScrolls[daemonsOfChaosKhorne.getName()] =
      daemonsOfChaosKhorneDictionary;
  }

  {
    WarScrollDictionaryType daemonsOfChaosNurgleDictionary;
    DaemonsOfChaosNurgleFaction daemonsOfChaosNurgle;
    QList<WarScroll> daemonsOfChaosNurgleWarScrolls =
      daemonsOfChaosNurgle.getWarScrolls();
    foreach(const WarScroll &ws, daemonsOfChaosNurgleWarScrolls) {
      daemonsOfChaosNurgleDictionary[ws.getTitle()] = ws;
    }
    m_WarScrolls[daemonsOfChaosNurgle.getName()] =
      daemonsOfChaosNurgleDictionary;
  }

  {
    WarScrollDictionaryType daemonsOfChaosSlaaneshDictionary;
    DaemonsOfChaosSlaaneshFaction daemonsOfChaosSlaanesh;
    QList<WarScroll> daemonsOfChaosSlaaneshWarScrolls =
      daemonsOfChaosSlaanesh.getWarScrolls();
    foreach(const WarScroll &ws, daemonsOfChaosSlaaneshWarScrolls) {
      daemonsOfChaosSlaaneshDictionary[ws.getTitle()] = ws;
    }
    m_WarScrolls[daemonsOfChaosSlaanesh.getName()] =
      daemonsOfChaosSlaaneshDictionary;
  }

  {
    WarScrollDictionaryType daemonsOfChaosTzeentchDictionary;
    DaemonsOfChaosTzeentchFaction daemonsOfChaosTzeentch;
    QList<WarScroll> daemonsOfChaosTzeentchWarScrolls =
      daemonsOfChaosTzeentch.getWarScrolls();
    foreach(const WarScroll &ws, daemonsOfChaosTzeentchWarScrolls) {
      daemonsOfChaosTzeentchDictionary[ws.getTitle()] = ws;
    }
    m_WarScrolls[daemonsOfChaosTzeentch.getName()] =
      daemonsOfChaosTzeentchDictionary;
  }

  {
    WarScrollDictionaryType darkelvesDictionary;
    DarkElvesFaction darkelves;
    QList<WarScroll> darkelvesWarScrolls = darkelves.getWarScrolls();
    foreach(const WarScroll &ws, darkelvesWarScrolls) {
      darkelvesDictionary[ws.getTitle()] = ws;
    }
    m_WarScrolls[darkelves.getName()] = darkelvesDictionary;
  }

  {
    WarScrollDictionaryType dwarfsDictionary;
    DwarfsFaction dwarfs;
    QList<WarScroll> dwarfsWarScrolls = dwarfs.getWarScrolls();
    foreach(const WarScroll &ws, dwarfsWarScrolls) {
      dwarfsDictionary[ws.getTitle()] = ws;
    }
    m_WarScrolls[dwarfs.getName()] = dwarfsDictionary;
  }

  {
    WarScrollDictionaryType highElvesDictionary;
    HighElvesFaction highElves;
    QList<WarScroll> highElvesWarScrolls = highElves.getWarScrolls();
    foreach(const WarScroll &ws, highElvesWarScrolls) {
      highElvesDictionary[ws.getTitle()] = ws;
    }
    m_WarScrolls[highElves.getName()] = highElvesDictionary;
  }

  {
    WarScrollDictionaryType lizardmenDictionary;
    LizardmenFaction lizardmen;
    QList<WarScroll> lizardmenWarScrolls = lizardmen.getWarScrolls();
    foreach(const WarScroll &ws, lizardmenWarScrolls) {
      lizardmenDictionary[ws.getTitle()] = ws;
    }
    m_WarScrolls[lizardmen.getName()] = lizardmenDictionary;
  }

  {
    WarScrollDictionaryType ogreKingdomsDictionary;
    OgreKingdomsFaction ogreKingdoms;
    QList<WarScroll> ogreKingdomsWarScrolls = ogreKingdoms.getWarScrolls();
    foreach(const WarScroll &ws, ogreKingdomsWarScrolls) {
      ogreKingdomsDictionary[ws.getTitle()] = ws;
    }
    m_WarScrolls[ogreKingdoms.getName()] = ogreKingdomsDictionary;
  }

  {
    WarScrollDictionaryType orcsAndGoblinsDictionary;
    OrcsAndGoblinsFaction orcsAndGoblins;
    QList<WarScroll> orcsAndGoblinsWarScrolls = orcsAndGoblins.getWarScrolls();
    foreach(const WarScroll &ws, orcsAndGoblinsWarScrolls) {
      orcsAndGoblinsDictionary[ws.getTitle()] = ws;
    }
    m_WarScrolls[orcsAndGoblins.getName()] = orcsAndGoblinsDictionary;
  }

  {
    WarScrollDictionaryType skavenDictionary;
    SkavenFaction skaven;
    QList<WarScroll> skavenWarScrolls = skaven.getWarScrolls();
    foreach(const WarScroll &ws, skavenWarScrolls) {
      skavenDictionary[ws.getTitle()] = ws;
    }
    m_WarScrolls[skaven.getName()] = skavenDictionary;
  }

  {
    WarScrollDictionaryType theEmpireDictionary;
    TheEmpireFaction theEmpire;
    QList<WarScroll> theEmpireWarScrolls = theEmpire.getWarScrolls();
    foreach(const WarScroll &ws, theEmpireWarScrolls) {
      theEmpireDictionary[ws.getTitle()] = ws;
    }
    m_WarScrolls[theEmpire.getName()] = theEmpireDictionary;
  }

  {
    WarScrollDictionaryType tombKingsDictionary;
    TombKingsFaction tombKings;
    QList<WarScroll> tombKingsWarScrolls = tombKings.getWarScrolls();
    foreach(const WarScroll &ws, tombKingsWarScrolls) {
      tombKingsDictionary[ws.getTitle()] = ws;
    }
    m_WarScrolls[tombKings.getName()] = tombKingsDictionary;
  }

  {
    WarScrollDictionaryType vampireCountsDictionary;
    VampireCountsFaction vampireCounts;
    QList<WarScroll> vampireCountsWarScrolls = vampireCounts.getWarScrolls();
    foreach(const WarScroll &ws, vampireCountsWarScrolls) {
      vampireCountsDictionary[ws.getTitle()] = ws;
    }
    m_WarScrolls[vampireCounts.getName()] = vampireCountsDictionary;
  }

  {
    WarScrollDictionaryType warriorsOfChaosDictionary;
    WarriorsOfChaosFaction warriorsOfChaos;
    QList<WarScroll> warriorsOfChaosWarScrolls =
      warriorsOfChaos.getWarScrolls();
    foreach(const WarScroll &ws, warriorsOfChaosWarScrolls) {
      warriorsOfChaosDictionary[ws.getTitle()] = ws;
    }
    m_WarScrolls[warriorsOfChaos.getName()] = warriorsOfChaosDictionary;
  }

  {
    WarScrollDictionaryType woodElvesDictionary;
    WoodElvesFaction woodElves;
    QList<WarScroll> woodElvesWarScrolls = woodElves.getWarScrolls();
    foreach(const WarScroll &ws, woodElvesWarScrolls) {
      woodElvesDictionary[ws.getTitle()] = ws;
    }
    m_WarScrolls[woodElves.getName()] = woodElvesDictionary;
  }
}

