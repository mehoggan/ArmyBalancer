#include "daemonsofchaoskhornefaction.h"

namespace WarScrollGeneration
{
  WarScroll Bloodthirster_of_Insensate_Rage(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Bloodthirster_of_Unfettered_Fury(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Wrath_of_Khorne_Bloodthirster(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Skulltaker(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Herald_of_Khorne(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Herald_of_Khorne_on_Juggernaut(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Blood_Throne_of_Khorne(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Bloodletters_of_Khorne(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Bloodcrushers_of_Khorne(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Karanak(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Flesh_Hounds_of_Khorne(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Skull_Cannons_of_Khorne(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Daemon_Prince_in_Khorne(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Furies_in_Khorne(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Soul_Grinder_in_Khorne(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }
}

DaemonsOfChaosKhorneFaction::DaemonsOfChaosKhorneFaction() :
  IFaction(nullptr)
{
  m_Units.push_back(tr(""));
  m_Units.push_back(tr("Bloodthirster of Insensate Rage"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Bloodthirster_of_Insensate_Rage,
    m_Units.back()));
  m_Units.push_back(tr("Bloodthirster of Unfettered Fury"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Bloodthirster_of_Unfettered_Fury,
    m_Units.back()));
  m_Units.push_back(tr("Wrath of Khorne Bloodthirster"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Wrath_of_Khorne_Bloodthirster,
    m_Units.back()));
  m_Units.push_back(tr("Skulltaker"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Skulltaker, m_Units.back()));
  m_Units.push_back(tr("Herald of Khorne"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Herald_of_Khorne, m_Units.back()));
  m_Units.push_back(tr("Herald of Khorne on Juggernaut"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Herald_of_Khorne_on_Juggernaut,
    m_Units.back()));
  m_Units.push_back(tr("Blood Throne of Khorne"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Blood_Throne_of_Khorne, m_Units.back()));
  m_Units.push_back(tr("Bloodletters of Khorne"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Bloodletters_of_Khorne, m_Units.back()));
  m_Units.push_back(tr("Bloodcrushers of Khorne"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Bloodcrushers_of_Khorne, m_Units.back()));
  m_Units.push_back(tr("Karanak"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Karanak, m_Units.back()));
  m_Units.push_back(tr("Flesh Hounds of Khorne"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Flesh_Hounds_of_Khorne, m_Units.back()));
  m_Units.push_back(tr("Skull Cannons of Khorne"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Skull_Cannons_of_Khorne, m_Units.back()));
  m_Units.push_back(tr("Daemon Prince"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Daemon_Prince_in_Khorne, m_Units.back()));
  m_Units.push_back(tr("Furies"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Furies_in_Khorne, m_Units.back()));
  m_Units.push_back(tr("Soul Grinder"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Soul_Grinder_in_Khorne, m_Units.back()));
}

const QStringList &DaemonsOfChaosKhorneFaction::getUnits() const
{
  return m_Units;
}

QList<WarScroll> DaemonsOfChaosKhorneFaction::getWarScrolls() const
{
  QList<WarScroll> warScrolls;
  for (auto ws : m_NameToWarScroll.toStdMap()) {
    warScrolls.push_back(ws.second(ws.first));
  }
  return warScrolls;
}
