#include "ogrekingdomsfaction.h"

namespace WarScrollGeneration
{
  WarScroll Greasus_Goldtooth(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Skrag_the_Slaughterer(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Tyrant(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Bragg_the_Gutsman(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Bruiser_Standard_Bearer(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Butcher(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Ogres(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Ironguts(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Leadbelchers(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Gorgers(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Ironblaster(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Gnoblar_Scraplauncher(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Gnoblar_Fighters(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Firebelly(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Hunter(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Sabertusks(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Mournfang_Cavalry(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Stonehorn(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Thundertusk(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Golgfag_Maneater(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Maneaters(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Yhetees(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Giant_in_Ogre_Kingdoms(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }
}

OgreKingdomsFaction::OgreKingdomsFaction() :
  IFaction(nullptr)
{
  m_Units.push_back("");
  m_Units.push_back("Greasus Goldtooth");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Greasus_Goldtooth, m_Units.back())));
  m_Units.push_back("Skrag the Slaughterer");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Skrag_the_Slaughterer, m_Units.back())));
  m_Units.push_back("Tyrant");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Tyrant, m_Units.back())));
  m_Units.push_back("Bragg the Gutsman");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Bragg_the_Gutsman, m_Units.back())));
  m_Units.push_back("Bruiser Standard Bearer");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Bruiser_Standard_Bearer, m_Units.back())));
  m_Units.push_back("Butcher");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Butcher, m_Units.back())));
  m_Units.push_back("Ogres");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Ogres, m_Units.back())));
  m_Units.push_back("Ironguts");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Ironguts, m_Units.back())));
  m_Units.push_back("Leadbelchers");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Leadbelchers, m_Units.back())));
  m_Units.push_back("Gorgers");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Gorgers, m_Units.back())));
  m_Units.push_back("Ironblaster");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Ironblaster, m_Units.back())));
  m_Units.push_back("Gnoblar Scraplauncher");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Gnoblar_Scraplauncher, m_Units.back())));
  m_Units.push_back("Gnoblar Fighters");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Gnoblar_Fighters, m_Units.back())));
  m_Units.push_back("Firebelly");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Firebelly, m_Units.back())));
  m_Units.push_back("Hunter");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Hunter, m_Units.back())));
  m_Units.push_back("Sabertusks");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Sabertusks, m_Units.back())));
  m_Units.push_back("Mournfang Cavalry");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Mournfang_Cavalry, m_Units.back())));
  m_Units.push_back("Stonehorn");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Stonehorn, m_Units.back())));
  m_Units.push_back("Thundertusk");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Thundertusk, m_Units.back())));
  m_Units.push_back("Golgfag Maneater");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Golgfag_Maneater, m_Units.back())));
  m_Units.push_back("Maneaters");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Maneaters, m_Units.back())));
  m_Units.push_back("Yhetees");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Yhetees, m_Units.back())));
  m_Units.push_back("Giant");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Giant_in_Ogre_Kingdoms, m_Units.back())));
}

const std::vector<std::string> &OgreKingdomsFaction::getUnits() const
{
  return m_Units;
}

void OgreKingdomsFaction::getWarScrolls(std::list<WarScroll>& warScrolls)
{
  for (const std::string &unit : m_Units) {
    if (unit.empty()) {
      continue;
    }
    WarScroll ws = m_NameToWarScroll[unit](unit);
    warScrolls.push_back(ws);
  }
}
