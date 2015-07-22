#include "daemonsofchaoskhornefaction.h"

namespace WarScrollGeneration
{
  WarScroll Bloodthirster_of_Insensate_Rage()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll Bloodthirster_of_Unfettered_Fury()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll Wrath_of_Khorne_Bloodthirster()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll Skulltaker()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll Herald_of_Khorne()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll Herald_of_Khorne_on_Juggernaut()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll Blood_Throne_of_Khorne()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll Bloodletters_of_Khorne()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll Bloodcrushers_of_Khorne()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll Karanak()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll Flesh_Hounds_of_Khorne()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll Skull_Cannons_of_Khorne()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll Daemon_Prince_in_Khorne()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll Furies_in_Khorne()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll Soul_Grinder_in_Khorne()
  {
    WarScroll ws;
    return ws;
  }
}

DaemonsOfChaosKhorneFaction::DaemonsOfChaosKhorneFaction() :
  IFaction(nullptr)
{
  m_Units.push_back(tr(""));
  m_Units.push_back(tr("Bloodthirster of Insensate Rage"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::Bloodthirster_of_Insensate_Rage);
  m_Units.push_back(tr("Bloodthirster of Unfettered Fury"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::Bloodthirster_of_Unfettered_Fury);
  m_Units.push_back(tr("Wrath of Khorne Bloodthirster"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::Wrath_of_Khorne_Bloodthirster);
  m_Units.push_back(tr("Skulltaker"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::Skulltaker);
  m_Units.push_back(tr("Herald of Khorne"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::Herald_of_Khorne);
  m_Units.push_back(tr("Herald of Khorne on Juggernaut"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::Herald_of_Khorne_on_Juggernaut);
  m_Units.push_back(tr("Blood Throne of Khorne"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::Blood_Throne_of_Khorne);
  m_Units.push_back(tr("Bloodletters of Khorne"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::Bloodletters_of_Khorne);
  m_Units.push_back(tr("Bloodcrushers of Khorne"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::Bloodcrushers_of_Khorne);
  m_Units.push_back(tr("Karanak"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::Karanak);
  m_Units.push_back(tr("Flesh Hounds of Khorne"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::Flesh_Hounds_of_Khorne);
  m_Units.push_back(tr("Skull Cannons of Khorne"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::Skull_Cannons_of_Khorne);
  m_Units.push_back(tr("Daemon Prince"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::Daemon_Prince_in_Khorne);
  m_Units.push_back(tr("Furies"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::Furies_in_Khorne);
  m_Units.push_back(tr("Soul Grinder"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::Soul_Grinder_in_Khorne);
}

const QStringList &DaemonsOfChaosKhorneFaction::getUnits() const
{
  return m_Units;
}

QList<WarScroll> DaemonsOfChaosKhorneFaction::getWarScrolls() const
{
  QList<WarScroll> warScrolls;
  return warScrolls;
}
