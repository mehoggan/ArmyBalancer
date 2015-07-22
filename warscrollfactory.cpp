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
      return **wsit;
    } else {
      qWarning() << (QString("Failed to Find Warscroll for ") + factionName);
      return WarScroll();
    }
  } else {
    qWarning() << (QString("Failed to Find Warscroll for ") + unitName);
    Q_ASSERT(false);
  }
  return WarScroll();
}

// ADD FACTORY CREATE FUNCTIONS HERE
// END OF FACTORY CREATE FUNCTIONS

WarScrollFactory::WarScrollFactory()
{
}

