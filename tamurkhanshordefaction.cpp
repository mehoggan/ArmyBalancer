#include "tamurkhanshordefaction.h"

namespace WarScrollGeneration
{
}

TamurkhansHordeFaction::TamurkhansHordeFaction() :
  IFaction()
{
  m_Units.push_back("");
}

const std::vector<std::string> &TamurkhansHordeFaction::getUnits() const
{
  return m_Units;
}

void TamurkhansHordeFaction::getWarScrolls(std::list<WarScroll>& warScrolls)
{
  for (const std::string &unit : m_Units) {
    if (unit.empty()) {
      continue;
    }
    WarScroll ws = m_NameToWarScroll[unit](unit);
    warScrolls.push_back(ws);
  }
}
