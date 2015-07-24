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
  WarScrollFactory();
  WarScrollFactory &operator=(const WarScrollFactory &other) = delete;
  WarScrollFactory(const WarScrollFactory &other) = delete;
  WarScrollFactory(WarScrollFactory &&other) = delete;

private:
  typedef std::map<std::string, WarScroll> WarScrollDictionaryType;
  typedef std::map<std::string, WarScrollDictionaryType>
    FactionWarScrollDictionaryType;
  FactionWarScrollDictionaryType m_WarScrolls;
};

#endif // WARSCROLLFACTORY_H
