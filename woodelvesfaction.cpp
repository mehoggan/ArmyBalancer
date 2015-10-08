#include "woodelvesfaction.h"

namespace WarScrollGeneration
{
  WarScroll Araloth(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Glade_Captain_Battle_Standard_Bearer(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Glade_Lord(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Glade_Lord_on_Great_Eagle(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Glade_Lord_on_Great_Stag(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Glade_Lord_on_Forest_Dragon(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Mounted_Glade_Lord(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Orion_King_in_the_Woods(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Hunting_Hounds(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Wild_Riders(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll The_Sisters_of_Twilight_on_Forest_Dragon(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Spellweaver(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Shadowdancer(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Wardancers(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Waywatcher_Lord(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Waywatchrs(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Glade_Guard(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Glade_Riders(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Eternal_Guard(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Wildwood_Rangers(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Warhawk_Riders(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Sisters_of_the_Thorn(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Great_Eagles_in_Wood_Elves(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Branchwraith(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Dryads(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Tree_Kin(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Durthu(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Treeman(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Treeman_Ancient(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Sylvaneth_Wyldwood(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }
}

WoodElvesFaction::WoodElvesFaction() :
  IFaction()
{
  m_Units.push_back("");
  m_Units.push_back("Araloth");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Araloth, m_Units.back())));
  m_Units.push_back("Glade Captain Battle Standard Bearer");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Glade_Captain_Battle_Standard_Bearer,
    m_Units.back())));
  m_Units.push_back("Glade Lord");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Glade_Lord, m_Units.back())));
  m_Units.push_back("Glade Lord on Great Eagle");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Glade_Lord_on_Great_Eagle,
    m_Units.back())));
  m_Units.push_back("Glade Lord on Great Stag");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Glade_Lord_on_Great_Stag, m_Units.back())));
  m_Units.push_back("Glade Lord on Forest Dragon");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Glade_Lord_on_Forest_Dragon,
    m_Units.back())));
  m_Units.push_back("Mounted Glade Lord");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Mounted_Glade_Lord, m_Units.back())));
  m_Units.push_back("Orion, King in the Woods");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Orion_King_in_the_Woods, m_Units.back())));
  m_Units.push_back("Hunting Hounds");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Hunting_Hounds, m_Units.back())));
  m_Units.push_back("Wild Riders");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Wild_Riders, m_Units.back())));
  m_Units.push_back("The Sisters of Twilight on Forest Dragon");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::The_Sisters_of_Twilight_on_Forest_Dragon,
    m_Units.back())));
  m_Units.push_back("Spellweaver");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Spellweaver, m_Units.back())));
  m_Units.push_back("Shadowdancer");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Shadowdancer, m_Units.back())));
  m_Units.push_back("Wardancers");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Wardancers, m_Units.back())));
  m_Units.push_back("Waywatcher Lord");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Waywatcher_Lord, m_Units.back())));
  m_Units.push_back("Waywatchrs");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Waywatchrs, m_Units.back())));
  m_Units.push_back("Glade Guard");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Glade_Guard, m_Units.back())));
  m_Units.push_back("Glade Riders");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Glade_Riders, m_Units.back())));
  m_Units.push_back("Eternal Guard");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Eternal_Guard, m_Units.back())));
  m_Units.push_back("Wildwood Rangers");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Wildwood_Rangers, m_Units.back())));
  m_Units.push_back("Warhawk Riders");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Warhawk_Riders, m_Units.back())));
  m_Units.push_back("Sisters of the Thorn");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Sisters_of_the_Thorn, m_Units.back())));
  m_Units.push_back("Great Eagles");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Great_Eagles_in_Wood_Elves,
    m_Units.back())));
  m_Units.push_back("Branchwraith");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Branchwraith, m_Units.back())));
  m_Units.push_back("Dryads");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Dryads, m_Units.back())));
  m_Units.push_back("Tree Kin");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Tree_Kin, m_Units.back())));
  m_Units.push_back("Durthu");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Durthu, m_Units.back())));
  m_Units.push_back("Treeman");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Treeman, m_Units.back())));
  m_Units.push_back("Treeman Ancient");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Treeman_Ancient, m_Units.back())));
  m_Units.push_back("Sylvaneth Wyldwood");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Sylvaneth_Wyldwood, m_Units.back())));

  std::sort(m_Units.begin(), m_Units.end());
}

const std::vector<std::string> &WoodElvesFaction::getUnits() const
{
  return m_Units;
}

void WoodElvesFaction::getWarScrolls(std::list<WarScroll>& warScrolls)
{
  for (const std::string &unit : m_Units) {
    if (unit.empty()) {
      continue;
    }
    WarScroll ws = m_NameToWarScroll[unit](unit);
    warScrolls.push_back(ws);
  }
}
