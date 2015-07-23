#include "tombkingsfaction.h"

namespace WarScrollGeneration
{
  WarScroll Settra_the_Imperishable(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll High_Queen_Khalida(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Tomb_King(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Tomb_King_in_Royal_Chariot(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Prince_Apophas(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Tomb_Herald(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Liche_Priest(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Casket_of_Souls(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Skeleton_Warriors_in_Tomb_Kings(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Skeleton_Archers(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Skeleton_Horsemen(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Skeleton_Horse_Archers(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Skeleton_Chariots(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Tomb_Guard(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Necrotect(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Necropolis_Knights(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Tomb_Scorpions(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Ushabti(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Khemrian_Warsphinx(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Royal_Warsphinx(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Necrosphinx(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Sepulchral_Stalkers(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Bone_Giant(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Screaming_Skull_Catapult(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Carrion(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Tomb_Swarm(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }
}

TombKingsFaction::TombKingsFaction() :
  IFaction(nullptr)
{
  m_Units.push_back(tr(""));
  m_Units.push_back(tr("Settra the Imperishable"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Settra_the_Imperishable, m_Units.back()));
  m_Units.push_back(tr("High Queen Khalida"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::High_Queen_Khalida, m_Units.back()));
  m_Units.push_back(tr("Tomb King"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Tomb_King, m_Units.back()));
  m_Units.push_back(tr("Tomb King in Royal Chariot"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Tomb_King_in_Royal_Chariot,
    m_Units.back()));
  m_Units.push_back(tr("Prince Apophas"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Prince_Apophas, m_Units.back()));
  m_Units.push_back(tr("Tomb Herald"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Tomb_Herald, m_Units.back()));
  m_Units.push_back(tr("Liche Priest"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Liche_Priest, m_Units.back()));
  m_Units.push_back(tr("Casket of Souls"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Casket_of_Souls, m_Units.back()));
  m_Units.push_back(tr("Skeleton Warriors"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Skeleton_Warriors_in_Tomb_Kings,
    m_Units.back()));
  m_Units.push_back(tr("Skeleton Archers"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Skeleton_Archers, m_Units.back()));
  m_Units.push_back(tr("Skeleton Horsemen"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Skeleton_Horsemen, m_Units.back()));
  m_Units.push_back(tr("Skeleton Horse Archers"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Skeleton_Horse_Archers, m_Units.back()));
  m_Units.push_back(tr("Skeleton Chariots"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Skeleton_Chariots, m_Units.back()));
  m_Units.push_back(tr("Tomb Guard"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Tomb_Guard, m_Units.back()));
  m_Units.push_back(tr("Necrotect"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Necrotect, m_Units.back()));
  m_Units.push_back(tr("Necropolis Knights"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Necropolis_Knights, m_Units.back()));
  m_Units.push_back(tr("Tomb Scorpions"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Tomb_Scorpions, m_Units.back()));
  m_Units.push_back(tr("Ushabti"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Ushabti, m_Units.back()));
  m_Units.push_back(tr("Khemrian Warsphinx"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Khemrian_Warsphinx, m_Units.back()));
  m_Units.push_back(tr("Royal Warsphinx"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Royal_Warsphinx, m_Units.back()));
  m_Units.push_back(tr("Necrosphinx"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Necrosphinx, m_Units.back()));
  m_Units.push_back(tr("Sepulchral Stalkers"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Sepulchral_Stalkers, m_Units.back()));
  m_Units.push_back(tr("Bone Giant"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Bone_Giant, m_Units.back()));
  m_Units.push_back(tr("Screaming Skull Catapult"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Screaming_Skull_Catapult, m_Units.back()));
  m_Units.push_back(tr("Carrion"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Carrion, m_Units.back()));
  m_Units.push_back(tr("Tomb Swarm"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Tomb_Swarm, m_Units.back()));
}

const QStringList &TombKingsFaction::getUnits() const
{
  return m_Units;
}

QList<WarScroll> TombKingsFaction::getWarScrolls() const
{
  QList<WarScroll> warScrolls;
  for (auto ws : m_NameToWarScroll.toStdMap()) {
    warScrolls.push_back(ws.second(ws.first));
  }
  return warScrolls;
}
