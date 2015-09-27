#ifndef WARSCROLLFACTORY_H
#define WARSCROLLFACTORY_H

#include <QPair>
#include <string>

#include <map>
#include <memory>
#include <set>

#include "warscroll.h"

class WarScrollFactory
{
public:
  static WarScrollFactory& getSharedInstance();
  WarScroll getWarScroll(const std::string &factionName,
    const std::string &unitName);

private:
  typedef std::map<std::string, WarScroll> WarScrollDictionaryType;
  typedef std::map<std::string, WarScrollDictionaryType>
    FactionWarScrollDictionaryType;
  FactionWarScrollDictionaryType m_WarScrolls;

private:
  WarScrollFactory();
  WarScrollFactory &operator=(const WarScrollFactory &other) = delete;
  WarScrollFactory(const WarScrollFactory &other) = delete;
  WarScrollFactory(WarScrollFactory &&other) = delete;

  template <typename Faction>
  void getWarScrollsForFaction()
  {
    WarScrollDictionaryType dictionary;
    Faction faction;
    std::list<WarScroll> warScrolls;
    faction.getWarScrolls(warScrolls);
    for (const WarScroll &ws : warScrolls) {
      dictionary.insert(std::make_pair(ws.getTitle(), ws));
    }
    m_WarScrolls[faction.getName()] = dictionary;
  }
};

#endif // WARSCROLLFACTORY_H
