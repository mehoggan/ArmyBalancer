#include "bretonniafaction.h"

namespace WarScrollGeneration
{
  WarScroll King_Louen_Leoncoeur(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll The_Fay_Enchantress(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll The_Green_Knight(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Bretonnian_Lord(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Paladin(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Paladin_Standard_Bearer(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Damsel_of_the_Lady(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Knights_Errant(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    ws.setTitle(name);
    return ws;
  }

  WarScroll Knights_of_the_Realm(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Questing_Knights(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Grail_Knights(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Pegasus_Knights(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Battle_Pilgrims(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Men_at_Arms(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Peasant_Bowmen(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Mounted_Yeomen(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Field_Trebuchet(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }
}

BretonniaFaction::BretonniaFaction() :
  IFaction(nullptr)
{
  m_Units.push_back("");
  m_Units.push_back("King Louen Leoncoeur");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::King_Louen_Leoncoeur, m_Units.back())));
  m_Units.push_back("The Fay Enchantress");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::The_Fay_Enchantress, m_Units.back())));
  m_Units.push_back("The Green Knight");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::The_Green_Knight, m_Units.back())));
  m_Units.push_back("Bretonnian Lord");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Bretonnian_Lord, m_Units.back())));
  m_Units.push_back("Paladin");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Paladin, m_Units.back())));
  m_Units.push_back("Paladin Standard Bearer");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Paladin_Standard_Bearer, m_Units.back())));
  m_Units.push_back("Damsel of the Lady");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Damsel_of_the_Lady, m_Units.back())));
  m_Units.push_back("Knights Errant");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Knights_Errant, m_Units.back())));
  m_Units.push_back("Knights of the Realm");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Knights_of_the_Realm, m_Units.back())));
  m_Units.push_back("Questing Knights");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Questing_Knights, m_Units.back())));
  m_Units.push_back("Grail Knights");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Grail_Knights, m_Units.back())));
  m_Units.push_back("Pegasus Knights");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Pegasus_Knights, m_Units.back())));
  m_Units.push_back("Battle Pilgrims");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Battle_Pilgrims, m_Units.back())));
  m_Units.push_back("Men-at-Arms");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Men_at_Arms, m_Units.back())));
  m_Units.push_back("Peasant Bowmen");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Peasant_Bowmen, m_Units.back())));
  m_Units.push_back("Mounted Yeomen");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Mounted_Yeomen, m_Units.back())));
  m_Units.push_back("Field Trebuchet");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Field_Trebuchet, m_Units.back())));
}

const std::vector<std::string> &BretonniaFaction::getUnits() const
{
  return m_Units;
}

void BretonniaFaction::getWarScrolls(std::list<WarScroll>& warScrolls)
{
  for (const std::string &unit : m_Units) {
    if (unit.empty()) {
      continue;
    }
    WarScroll ws = m_NameToWarScroll[unit](unit);
    warScrolls.push_back(ws);
  }
}
