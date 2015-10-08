#include "tombkingsfaction.h"

namespace WarScrollGeneration
{
  WarScroll Settra_the_Imperishable(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll High_Queen_Khalida(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Tomb_King(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Tomb_King_in_Royal_Chariot(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Prince_Apophas(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Tomb_Herald(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Liche_Priest(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Casket_of_Souls(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Skeleton_Warriors_in_Tomb_Kings(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Skeleton_Archers(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Skeleton_Horsemen(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Skeleton_Horse_Archers(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Skeleton_Chariots(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Tomb_Guard(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Necrotect(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Necropolis_Knights(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Tomb_Scorpions(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Ushabti(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Khemrian_Warsphinx(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Royal_Warsphinx(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Necrosphinx(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Sepulchral_Stalkers(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Bone_Giant(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Screaming_Skull_Catapult(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Carrion(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Tomb_Swarm(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }
}

TombKingsFaction::TombKingsFaction() :
  IFaction()
{
  m_Units.push_back("");
  m_Units.push_back("Settra the Imperishable");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Settra_the_Imperishable, m_Units.back())));
  m_Units.push_back("High Queen Khalida");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::High_Queen_Khalida, m_Units.back())));
  m_Units.push_back("Tomb King");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Tomb_King, m_Units.back())));
  m_Units.push_back("Tomb King in Royal Chariot");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Tomb_King_in_Royal_Chariot,
    m_Units.back())));
  m_Units.push_back("Prince Apophas");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Prince_Apophas, m_Units.back())));
  m_Units.push_back("Tomb Herald");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Tomb_Herald, m_Units.back())));
  m_Units.push_back("Liche Priest");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Liche_Priest, m_Units.back())));
  m_Units.push_back("Casket of Souls");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Casket_of_Souls, m_Units.back())));
  m_Units.push_back("Skeleton Warriors");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Skeleton_Warriors_in_Tomb_Kings,
    m_Units.back())));
  m_Units.push_back("Skeleton Archers");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Skeleton_Archers, m_Units.back())));
  m_Units.push_back("Skeleton Horsemen");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Skeleton_Horsemen, m_Units.back())));
  m_Units.push_back("Skeleton Horse Archers");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Skeleton_Horse_Archers, m_Units.back())));
  m_Units.push_back("Skeleton Chariots");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Skeleton_Chariots, m_Units.back())));
  m_Units.push_back("Tomb Guard");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Tomb_Guard, m_Units.back())));
  m_Units.push_back("Necrotect");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Necrotect, m_Units.back())));
  m_Units.push_back("Necropolis Knights");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Necropolis_Knights, m_Units.back())));
  m_Units.push_back("Tomb Scorpions");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Tomb_Scorpions, m_Units.back())));
  m_Units.push_back("Ushabti");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Ushabti, m_Units.back())));
  m_Units.push_back("Khemrian Warsphinx");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Khemrian_Warsphinx, m_Units.back())));
  m_Units.push_back("Royal Warsphinx");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Royal_Warsphinx, m_Units.back())));
  m_Units.push_back("Necrosphinx");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Necrosphinx, m_Units.back())));
  m_Units.push_back("Sepulchral Stalkers");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Sepulchral_Stalkers, m_Units.back())));
  m_Units.push_back("Bone Giant");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Bone_Giant, m_Units.back())));
  m_Units.push_back("Screaming Skull Catapult");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Screaming_Skull_Catapult, m_Units.back())));
  m_Units.push_back("Carrion");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Carrion, m_Units.back())));
  m_Units.push_back("Tomb Swarm");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Tomb_Swarm, m_Units.back())));

  std::sort(m_Units.begin(), m_Units.end());
}

const std::vector<std::string> &TombKingsFaction::getUnits() const
{
  return m_Units;
}

void TombKingsFaction::getWarScrolls(std::list<WarScroll>& warScrolls)
{
  for (const std::string &unit : m_Units) {
    if (unit.empty()) {
      continue;
    }
    WarScroll ws = m_NameToWarScroll[unit](unit);
    warScrolls.push_back(ws);
  }
}
