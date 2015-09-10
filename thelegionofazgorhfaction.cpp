#include "thelegionofazgorhfaction.h"

namespace WarScrollGeneration
{
}

TheLegionOfAzgorhFaction::TheLegionOfAzgorhFaction() :
  IFaction()
{
  m_Units.push_back("");
}

const std::vector<std::string> &TheLegionOfAzgorhFaction::getUnits() const
{
  return m_Units;
}

void TheLegionOfAzgorhFaction::getWarScrolls(std::list<WarScroll>& warScrolls)
{
  for (const std::string &unit : m_Units) {
    if (unit.empty()) {
      continue;
    }
    WarScroll ws = m_NameToWarScroll[unit](unit);
    warScrolls.push_back(ws);
  }
}
