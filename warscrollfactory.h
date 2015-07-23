#ifndef WARSCROLLFACTORY_H
#define WARSCROLLFACTORY_H

#include <QMap>
#include <QPair>
#include <QSet>
#include <QString>

#include <memory>

#include "warscroll.h"

class WarScrollFactory
{
public:
  static WarScrollFactory& getSharedInstance();
  WarScroll getWarScroll(const QString &factionName, const QString &unitName);

private:
  WarScrollFactory();
  WarScrollFactory &operator=(const WarScrollFactory &other) = delete;
  WarScrollFactory(const WarScrollFactory &other) = delete;
  WarScrollFactory(WarScrollFactory &&other) = delete;

private:
  typedef QMap<QString, WarScroll> WarScrollDictionaryType;
  typedef QMap<QString, WarScrollDictionaryType> FactionWarScrollDictionaryType;
  FactionWarScrollDictionaryType m_WarScrolls;
};

#endif // WARSCROLLFACTORY_H
