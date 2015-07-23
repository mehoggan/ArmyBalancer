#include "woodelvesfaction.h"

namespace WarScrollGeneration
{
  WarScroll Araloth(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Glade_Captain_Battle_Standard_Bearer(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Glade_Lord(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Glade_Lord_on_Great_Eagle(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Glade_Lord_on_Great_Stag(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Glade_Lord_on_Forest_Dragon(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Mounted_Glade_Lord(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Orion_King_in_the_Woods(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Hunting_Hounds(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Wild_Riders(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll The_Sisters_of_Twilight_on_Forest_Dragon(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Spellweaver(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Shadowdancer(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Wardancers(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Waywatcher_Lord(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Waywatchrs(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Glade_Guard(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Glade_Riders(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Eternal_Guard(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Wildwood_Rangers(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Warhawk_Riders(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Sisters_of_the_Thorn(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Great_Eagles_in_Wood_Elves(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Branchwraith(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Dryads(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Tree_Kin(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Durthu(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Treeman(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Treeman_Ancient(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Sylvaneth_Wyldwood(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }
}

WoodElvesFaction::WoodElvesFaction() :
  IFaction(nullptr)
{
  m_Units.push_back(tr(""));
  m_Units.push_back(tr("Araloth"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Araloth, m_Units.back()));
  m_Units.push_back(tr("Glade Captain Battle Standard Bearer"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Glade_Captain_Battle_Standard_Bearer,
    m_Units.back()));
  m_Units.push_back(tr("Glade Lord"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Glade_Lord, m_Units.back()));
  m_Units.push_back(tr("Glade Lord on Great Eagle"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Glade_Lord_on_Great_Eagle, m_Units.back()));
  m_Units.push_back(tr("Glade Lord on Great Stag"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Glade_Lord_on_Great_Stag, m_Units.back()));
  m_Units.push_back(tr("Glade Lord on Forest Dragon"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Glade_Lord_on_Forest_Dragon,
    m_Units.back()));
  m_Units.push_back(tr("Mounted Glade Lord"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Mounted_Glade_Lord, m_Units.back()));
  m_Units.push_back(tr("Orion, King in the Woods"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Orion_King_in_the_Woods, m_Units.back()));
  m_Units.push_back(tr("Hunting Hounds"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Hunting_Hounds, m_Units.back()));
  m_Units.push_back(tr("Wild Riders"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Wild_Riders, m_Units.back()));
  m_Units.push_back(tr("The Sisters of Twilight on Forest Dragon"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::The_Sisters_of_Twilight_on_Forest_Dragon,
    m_Units.back()));
  m_Units.push_back(tr("Spellweaver"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Spellweaver, m_Units.back()));
  m_Units.push_back(tr("Shadowdancer"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Shadowdancer, m_Units.back()));
  m_Units.push_back(tr("Wardancers"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Wardancers, m_Units.back()));
  m_Units.push_back(tr("Waywatcher Lord"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Waywatcher_Lord, m_Units.back()));
  m_Units.push_back(tr("Waywatchrs"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Waywatchrs, m_Units.back()));
  m_Units.push_back(tr("Glade Guard"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Glade_Guard, m_Units.back()));
  m_Units.push_back(tr("Glade Riders"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Glade_Riders, m_Units.back()));
  m_Units.push_back(tr("Eternal Guard"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Eternal_Guard, m_Units.back()));
  m_Units.push_back(tr("Wildwood Rangers"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Wildwood_Rangers, m_Units.back()));
  m_Units.push_back(tr("Warhawk Riders"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Warhawk_Riders, m_Units.back()));
  m_Units.push_back(tr("Sisters of the Thorn"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Sisters_of_the_Thorn, m_Units.back()));
  m_Units.push_back(tr("Great Eagles"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Great_Eagles_in_Wood_Elves,
    m_Units.back()));
  m_Units.push_back(tr("Branchwraith"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Branchwraith, m_Units.back()));
  m_Units.push_back(tr("Dryads"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Dryads, m_Units.back()));
  m_Units.push_back(tr("Tree Kin"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Tree_Kin, m_Units.back()));
  m_Units.push_back(tr("Durthu"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Durthu, m_Units.back()));
  m_Units.push_back(tr("Treeman"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Treeman, m_Units.back()));
  m_Units.push_back(tr("Treeman Ancient"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Treeman_Ancient, m_Units.back()));
  m_Units.push_back(tr("Sylvaneth Wyldwood"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Sylvaneth_Wyldwood, m_Units.back()));
}

const QStringList &WoodElvesFaction::getUnits() const
{
  return m_Units;
}

QList<WarScroll> WoodElvesFaction::getWarScrolls() const
{
  QList<WarScroll> warScrolls;
  for (auto ws : m_NameToWarScroll.toStdMap()) {
    warScrolls.push_back(ws.second(ws.first));
  }
  return warScrolls;
}
