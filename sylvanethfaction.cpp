#include "sylvanethfaction.h"

namespace WarScrollGeneration
{
}

SylvanethFaction::SylvanethFaction() :
  IFaction()
{
  m_Units.push_back("");
}

const std::vector<std::string> &SylvanethFaction::getUnits() const
{
  return m_Units;
}

void SylvanethFaction::getWarScrolls(std::list<WarScroll>& warScrolls)
{
  for (const std::string &unit : m_Units) {
    if (unit.empty()) {
      continue;
    }
    WarScroll ws = m_NameToWarScroll[unit](unit);
    warScrolls.push_back(ws);
  }
}
