#include "beastmenfaction.h"

namespace WarScrollGeneration
{
  WarScroll Gorthor_the_Beastlord(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Khazrak_the_One_Eye(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Beastlord(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Wargor_Standard_Bearer(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Malagor_The_Dark_Omen(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Great_Bray_shaman(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Morghur_Master_of_Skulls(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Gors(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Bestigors(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Tuskgor_Chariots(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Ungors(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Ungor_Raiders(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Doombull(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Minotaurs(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Cygor(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Ghorgon(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Centigors(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Ghorros_Warhoof(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Razorgors(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Chaos_Warhounds_in_Beastmen(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Harpies_in_Beastmen(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Chaos_Spawn_in_Beastmen(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Giant_in_Beastmen(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Jabberslythe(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }
}

BeastmenFaction::BeastmenFaction() :
  IFaction(nullptr)
{
  m_Units.push_back(tr(""));
  m_Units.push_back(tr("Gorthor the Beastlord"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Gorthor_the_Beastlord, m_Units.back()));
  m_Units.push_back(tr("Khazrak the One-Eye"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Khazrak_the_One_Eye, m_Units.back()));
  m_Units.push_back(tr("Beastlord"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Beastlord, m_Units.back()));
  m_Units.push_back(tr("Wargor Standard Bearer"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Wargor_Standard_Bearer, m_Units.back()));
  m_Units.push_back(tr("Malagor, The Dark Omen"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Malagor_The_Dark_Omen, m_Units.back()));
  m_Units.push_back(tr("Great Bray-shaman"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Great_Bray_shaman, m_Units.back()));
  m_Units.push_back(tr("Morghur, Master of Skulls"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Morghur_Master_of_Skulls, m_Units.back()));
  m_Units.push_back(tr("Gors"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Gors, m_Units.back()));
  m_Units.push_back(tr("Bestigors"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Bestigors, m_Units.back()));
  m_Units.push_back(tr("Tuskgor Chariots"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Tuskgor_Chariots, m_Units.back()));
  m_Units.push_back(tr("Ungors"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Ungors, m_Units.back()));
  m_Units.push_back(tr("Ungor Raiders"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Ungor_Raiders, m_Units.back()));
  m_Units.push_back(tr("Doombull"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Doombull, m_Units.back()));
  m_Units.push_back(tr("Minotaurs"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Minotaurs, m_Units.back()));
  m_Units.push_back(tr("Cygor"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Cygor, m_Units.back()));
  m_Units.push_back(tr("Ghorgon"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Ghorgon, m_Units.back()));
  m_Units.push_back(tr("Centigors"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Centigors, m_Units.back()));
  m_Units.push_back(tr("Ghorros Warhoof"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Ghorros_Warhoof, m_Units.back()));
  m_Units.push_back(tr("Razorgors"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Razorgors, m_Units.back()));
  m_Units.push_back(tr("Chaos Warhounds"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Chaos_Warhounds_in_Beastmen,
    m_Units.back()));
  m_Units.push_back(tr("Harpies"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Harpies_in_Beastmen, m_Units.back()));
  m_Units.push_back(tr("Chaos Spawn"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Chaos_Spawn_in_Beastmen, m_Units.back()));
  m_Units.push_back(tr("Giant"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Giant_in_Beastmen, m_Units.back()));
  m_Units.push_back(tr("Jabberslythe"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Jabberslythe, m_Units.back()));
}

const QStringList &BeastmenFaction::getUnits() const
{
  return m_Units;
}

QList<WarScroll> BeastmenFaction::getWarScrolls() const
{
  QList<WarScroll> warScrolls;
  for (auto ws : m_NameToWarScroll.toStdMap()) {
    warScrolls.push_back(ws.second(ws.first));
  }
  return warScrolls;
}
