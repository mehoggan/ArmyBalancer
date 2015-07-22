#include "beastmenfaction.h"

namespace WarScrollGeneration
{
  WarScroll Gorthor_the_Beastlord()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll Khazrak_the_One_Eye()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll Beastlord()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll Wargor_Standard_Bearer()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll Malagor_The_Dark_Omen()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll Great_Bray_shaman()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll Morghur_Master_of_Skulls()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll Gors()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll Bestigors()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll Tuskgor_Chariots()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll Ungors()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll Ungor_Raiders()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll Doombull()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll Minotaurs()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll Cygor()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll Ghorgon()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll Centigors()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll Ghorros_Warhoof()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll Razorgors()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll Chaos_Warhounds_in_Beastmen()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll Harpies_in_Beastmen()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll Chaos_Spawn_in_Beastmen()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll Giant_in_Beastmen()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll Jabberslythe()
  {
    WarScroll ws;
    return ws;
  }
}

BeastmenFaction::BeastmenFaction() :
  IFaction(nullptr)
{
  m_Units.push_back(tr(""));
  m_Units.push_back(tr("Gorthor the Beastlord"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::Gorthor_the_Beastlord);
  m_Units.push_back(tr("Khazrak the One-Eye"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::Khazrak_the_One_Eye);
  m_Units.push_back(tr("Beastlord"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::Beastlord);
  m_Units.push_back(tr("Wargor Standard Bearer"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::Wargor_Standard_Bearer);
  m_Units.push_back(tr("Malagor, The Dark Omen"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::Malagor_The_Dark_Omen);
  m_Units.push_back(tr("Great Bray-shaman"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::Great_Bray_shaman);
  m_Units.push_back(tr("Morghur, Master of Skulls"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::Morghur_Master_of_Skulls);
  m_Units.push_back(tr("Gors"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::Gors);
  m_Units.push_back(tr("Bestigors"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::Bestigors);
  m_Units.push_back(tr("Tuskgor Chariots"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::Tuskgor_Chariots);
  m_Units.push_back(tr("Ungors"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::Ungors);
  m_Units.push_back(tr("Ungor Raiders"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::Ungor_Raiders);
  m_Units.push_back(tr("Doombull"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::Doombull);
  m_Units.push_back(tr("Minotaurs"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::Minotaurs);
  m_Units.push_back(tr("Cygor"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::Cygor);
  m_Units.push_back(tr("Ghorgon"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::Ghorgon);
  m_Units.push_back(tr("Centigors"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::Centigors);
  m_Units.push_back(tr("Ghorros Warhoof"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::Ghorros_Warhoof);
  m_Units.push_back(tr("Razorgors"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::Razorgors);
  m_Units.push_back(tr("Chaos Warhounds"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::Chaos_Warhounds_in_Beastmen);
  m_Units.push_back(tr("Harpies"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::Harpies_in_Beastmen);
  m_Units.push_back(tr("Chaos Spawn"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::Chaos_Spawn_in_Beastmen);
  m_Units.push_back(tr("Giant"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::Giant_in_Beastmen);
  m_Units.push_back(tr("Jabberslythe"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::Jabberslythe);
}

const QStringList &BeastmenFaction::getUnits() const
{
  return m_Units;
}

QList<WarScroll> BeastmenFaction::getWarScrolls() const
{
  QList<WarScroll> warScrolls;
  return warScrolls;
}
