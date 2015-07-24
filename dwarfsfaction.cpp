#include "dwarfsfaction.h"

namespace WarScrollGeneration
{
  WarScroll High_King_Thorgrim_Grudgebearer(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Thorek_Ironbrow(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Kraggi(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Belgar_Ironhammer(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Ungrim_Ironfist_the_Slayer_King(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Josef_Bugman(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Grimm_Burloksson(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Dwarf_Lord(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Runelord(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Dragon_Slayer(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Dwarf_Engineer(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Thane_with_Battle_Standard(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Hammerers(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Ironbreakers(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Irondrakes(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Longbeards(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Dwarf_Warriors(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Miners(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Quarrellers(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Slayers(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Thunderers(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Gyrocopters(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Gyrobombers(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Dwarf_Bolt_Thrower(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Dwarf_Cannon(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Flame_Cannon(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Organ_Gun(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Grudge_Thrower(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }
}

DwarfsFaction::DwarfsFaction() :
  IFaction(nullptr)
{
  m_Units.push_back("");
  m_Units.push_back("High King Thorgrim Grudgebearer");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::High_King_Thorgrim_Grudgebearer,
    m_Units.back())));
  m_Units.push_back("Thorek Ironbrow");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Thorek_Ironbrow, m_Units.back())));
  m_Units.push_back("Kraggi");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Kraggi, m_Units.back())));
  m_Units.push_back("Belgar Ironhammer");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Belgar_Ironhammer, m_Units.back())));
  m_Units.push_back("Ungrim Ironfist the Slayer King");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Ungrim_Ironfist_the_Slayer_King,
    m_Units.back())));
  m_Units.push_back("Josef Bugman");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Josef_Bugman, m_Units.back())));
  m_Units.push_back("Grimm Burloksson");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Grimm_Burloksson, m_Units.back())));
  m_Units.push_back("Dwarf Lord");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Dwarf_Lord, m_Units.back())));
  m_Units.push_back("Runelord");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Runelord, m_Units.back())));
  m_Units.push_back("Dragon Slayer");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Dragon_Slayer, m_Units.back())));
  m_Units.push_back("Dwarf Engineer");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Dwarf_Engineer, m_Units.back())));
  m_Units.push_back("Thane with Battle Standard");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Thane_with_Battle_Standard,
    m_Units.back())));
  m_Units.push_back("Hammerers");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Hammerers, m_Units.back())));
  m_Units.push_back("Ironbreakers");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Ironbreakers, m_Units.back())));
  m_Units.push_back("Irondrakes");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Irondrakes, m_Units.back())));
  m_Units.push_back("Longbeards");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Longbeards, m_Units.back())));
  m_Units.push_back("Dwarf Warriors");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Dwarf_Warriors, m_Units.back())));
  m_Units.push_back("Miners");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Miners, m_Units.back())));
  m_Units.push_back("Quarrellers");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Quarrellers, m_Units.back())));
  m_Units.push_back("Slayers");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Slayers, m_Units.back())));
  m_Units.push_back("Thunderers");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Thunderers, m_Units.back())));
  m_Units.push_back("Gyrocopters");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Gyrocopters, m_Units.back())));
  m_Units.push_back("Gyrobombers");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Gyrobombers, m_Units.back())));
  m_Units.push_back("Dwarf Bolt Thrower");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Dwarf_Bolt_Thrower, m_Units.back())));
  m_Units.push_back("Dwarf Cannon");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Dwarf_Cannon, m_Units.back())));
  m_Units.push_back("Flame Cannon");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Flame_Cannon, m_Units.back())));
  m_Units.push_back("Organ Gun");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Organ_Gun, m_Units.back())));
  m_Units.push_back("Grudge Thrower");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Grudge_Thrower, m_Units.back())));
}

const std::vector<std::string> &DwarfsFaction::getUnits() const
{
  return m_Units;
}

void DwarfsFaction::getWarScrolls(std::list<WarScroll>& warScrolls)
{
  for (const std::string &unit : m_Units) {
    if (unit.empty()) {
      continue;
    }
    WarScroll ws = m_NameToWarScroll[unit](unit);
    warScrolls.push_back(ws);
  }
}
