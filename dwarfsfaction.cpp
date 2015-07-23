#include "dwarfsfaction.h"

namespace WarScrollGeneration
{
  WarScroll High_King_Thorgrim_Grudgebearer(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Thorek_Ironbrow(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Kraggi(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Belgar_Ironhammer(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Ungrim_Ironfist_the_Slayer_King(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Josef_Bugman(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Grimm_Burloksson(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Dwarf_Lord(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Runelord(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Dragon_Slayer(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Dwarf_Engineer(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Thane_with_Battle_Standard(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Hammerers(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Ironbreakers(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Irondrakes(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Longbeards(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Dwarf_Warriors(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Miners(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Quarrellers(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Slayers(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Thunderers(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Gyrocopters(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Gyrobombers(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Dwarf_Bolt_Thrower(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Dwarf_Cannon(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Flame_Cannon(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Organ_Gun(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Grudge_Thrower(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }
}

DwarfsFaction::DwarfsFaction() :
  IFaction(nullptr)
{
  m_Units.push_back(tr(""));
  m_Units.push_back(tr("High King Thorgrim Grudgebearer"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::High_King_Thorgrim_Grudgebearer,
    m_Units.back()));
  m_Units.push_back(tr("Thorek Ironbrow"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Thorek_Ironbrow, m_Units.back()));
  m_Units.push_back(tr("Kraggi"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Kraggi, m_Units.back()));
  m_Units.push_back(tr("Belgar Ironhammer"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Belgar_Ironhammer, m_Units.back()));
  m_Units.push_back(tr("Ungrim Ironfist the Slayer King"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Ungrim_Ironfist_the_Slayer_King,
    m_Units.back()));
  m_Units.push_back(tr("Josef Bugman"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Josef_Bugman, m_Units.back()));
  m_Units.push_back(tr("Grimm Burloksson"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Grimm_Burloksson, m_Units.back()));
  m_Units.push_back(tr("Dwarf Lord"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Dwarf_Lord, m_Units.back()));
  m_Units.push_back(tr("Runelord"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Runelord, m_Units.back()));
  m_Units.push_back(tr("Dragon Slayer"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Dragon_Slayer, m_Units.back()));
  m_Units.push_back(tr("Dwarf Engineer"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Dwarf_Engineer, m_Units.back()));
  m_Units.push_back(tr("Thane with Battle Standard"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Thane_with_Battle_Standard,
    m_Units.back()));
  m_Units.push_back(tr("Hammerers"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Hammerers, m_Units.back()));
  m_Units.push_back(tr("Ironbreakers"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Ironbreakers, m_Units.back()));
  m_Units.push_back(tr("Irondrakes"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Irondrakes, m_Units.back()));
  m_Units.push_back(tr("Longbeards"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Longbeards, m_Units.back()));
  m_Units.push_back(tr("Dwarf Warriors"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Dwarf_Warriors, m_Units.back()));
  m_Units.push_back(tr("Miners"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Miners, m_Units.back()));
  m_Units.push_back(tr("Quarrellers"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Quarrellers, m_Units.back()));
  m_Units.push_back(tr("Slayers"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Slayers, m_Units.back()));
  m_Units.push_back(tr("Thunderers"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Thunderers, m_Units.back()));
  m_Units.push_back(tr("Gyrocopters"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Gyrocopters, m_Units.back()));
  m_Units.push_back(tr("Gyrobombers"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Gyrobombers, m_Units.back()));
  m_Units.push_back(tr("Dwarf Bolt Thrower"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Dwarf_Bolt_Thrower, m_Units.back()));
  m_Units.push_back(tr("Dwarf Cannon"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Dwarf_Cannon, m_Units.back()));
  m_Units.push_back(tr("Flame Cannon"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Flame_Cannon, m_Units.back()));
  m_Units.push_back(tr("Organ Gun"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Organ_Gun, m_Units.back()));
  m_Units.push_back(tr("Grudge Thrower"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Grudge_Thrower, m_Units.back()));
}

const QStringList &DwarfsFaction::getUnits() const
{
  return m_Units;
}

QList<WarScroll> DwarfsFaction::getWarScrolls() const
{
  QList<WarScroll> warScrolls;
  for (auto ws : m_NameToWarScroll.toStdMap()) {
    warScrolls.push_back(ws.second(ws.first));
  }
  return warScrolls;
}
