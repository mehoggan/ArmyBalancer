#include "dwarfsfaction.h"

namespace WarScrollGeneration
{
  WarScroll High_King_Thorgrim_Grudgebearer()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll Thorek_Ironbrow()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll Kraggi()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll Belgar_Ironhammer()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll Ungrim_Ironfist_the_Slayer_King()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll Josef_Bugman()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll Grimm_Burloksson()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll Dwarf_Lord()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll Runelord()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll Dragon_Slayer()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll Dwarf_Engineer()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll Thane_with_Battle_Standard()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll Hammerers()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll Ironbreakers()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll Irondrakes()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll Longbeards()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll Dwarf_Warriors()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll Miners()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll Quarrellers()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll Slayers()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll Thunderers()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll Gyrocopters()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll Gyrobombers()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll Dwarf_Bolt_Thrower()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll Dwarf_Cannon()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll Flame_Cannon()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll Organ_Gun()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll Grudge_Thrower()
  {
    WarScroll ws;
    return ws;
  }

}

DwarfsFaction::DwarfsFaction() :
  IFaction(nullptr)
{
  m_Units.push_back(tr(""));
  m_Units.push_back(tr("High King Thorgrim Grudgebearer"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::High_King_Thorgrim_Grudgebearer);
  m_Units.push_back(tr("Thorek Ironbrow"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::Thorek_Ironbrow);
  m_Units.push_back(tr("Kraggi"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::Kraggi);
  m_Units.push_back(tr("Belgar Ironhammer"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::Belgar_Ironhammer);
  m_Units.push_back(tr("Ungrim Ironfist the Slayer King"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::Ungrim_Ironfist_the_Slayer_King);
  m_Units.push_back(tr("Josef Bugman"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::Josef_Bugman);
  m_Units.push_back(tr("Grimm Burloksson"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::Grimm_Burloksson);
  m_Units.push_back(tr("Dwarf Lord"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::Dwarf_Lord);
  m_Units.push_back(tr("Runelord"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::Runelord);
  m_Units.push_back(tr("Dragon Slayer"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::Dragon_Slayer);
  m_Units.push_back(tr("Dwarf Engineer"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::Dwarf_Engineer);
  m_Units.push_back(tr("Thane with Battle Standard"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::Thane_with_Battle_Standard);
  m_Units.push_back(tr("Hammerers"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::Hammerers);
  m_Units.push_back(tr("Ironbreakers"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::Ironbreakers);
  m_Units.push_back(tr("Irondrakes"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::Irondrakes);
  m_Units.push_back(tr("Longbeards"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::Longbeards);
  m_Units.push_back(tr("Dwarf Warriors"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::Dwarf_Warriors);
  m_Units.push_back(tr("Miners"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::Miners);
  m_Units.push_back(tr("Quarrellers"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::Quarrellers);
  m_Units.push_back(tr("Slayers"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::Slayers);
  m_Units.push_back(tr("Thunderers"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::Thunderers);
  m_Units.push_back(tr("Gyrocopters"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::Gyrocopters);
  m_Units.push_back(tr("Gyrobombers"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::Gyrobombers);
  m_Units.push_back(tr("Dwarf Bolt Thrower"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::Dwarf_Bolt_Thrower);
  m_Units.push_back(tr("Dwarf Cannon"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::Dwarf_Cannon);
  m_Units.push_back(tr("Flame Cannon"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::Flame_Cannon);
  m_Units.push_back(tr("Organ Gun"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::Organ_Gun);
  m_Units.push_back(tr("Grudge Thrower"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::Grudge_Thrower);
}

const QStringList &DwarfsFaction::getUnits() const
{
  return m_Units;
}

QList<WarScroll> DwarfsFaction::getWarScrolls() const
{
  QList<WarScroll> warScrolls;
  return warScrolls;
}
