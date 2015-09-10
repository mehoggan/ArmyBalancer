#include "skavenpestilensfaction.h"

namespace WarScrollGeneration
{
}

SkavenPestilensFaction::SkavenPestilensFaction() :
  IFaction()
{
  m_Units.push_back("");
}

const std::vector<std::string> &SkavenPestilensFaction::getUnits() const
{
  return m_Units;
}

void SkavenPestilensFaction::getWarScrolls(std::list<WarScroll>& warScrolls)
{
  for (const std::string &unit : m_Units) {
    if (unit.empty()) {
      continue;
    }
    WarScroll ws = m_NameToWarScroll[unit](unit);
    warScrolls.push_back(ws);
  }
}
