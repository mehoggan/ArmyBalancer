#include "ogrekingdomsfaction.h"

namespace WarScrollGeneration
{
  WarScroll Greasus_Goldtooth(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Skrag_the_Slaughterer(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Tyrant(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Bragg_the_Gutsman(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Bruiser_Standard_Bearer(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Butcher(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Ogres(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Ironguts(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Leadbelchers(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Gorgers(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Ironblaster(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Gnoblar_Scraplauncher(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Gnoblar_Fighters(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Firebelly(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Hunter(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Sabertusks(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Mournfang_Cavalry(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Stonehorn(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Thundertusk(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Golgfag_Maneater(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Maneaters(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Yhetees(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Giant_in_Ogre_Kingdoms(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }
}

OgreKingdomsFaction::OgreKingdomsFaction() :
  IFaction(nullptr)
{
  m_Units.push_back(tr(""));
  m_Units.push_back(tr("Greasus Goldtooth"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Greasus_Goldtooth, m_Units.back()));
  m_Units.push_back(tr("Skrag the Slaughterer"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Skrag_the_Slaughterer, m_Units.back()));
  m_Units.push_back(tr("Tyrant"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Tyrant, m_Units.back()));
  m_Units.push_back(tr("Bragg the Gutsman"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Bragg_the_Gutsman, m_Units.back()));
  m_Units.push_back(tr("Bruiser Standard Bearer"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Bruiser_Standard_Bearer, m_Units.back()));
  m_Units.push_back(tr("Butcher"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Butcher, m_Units.back()));
  m_Units.push_back(tr("Ogres"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Ogres, m_Units.back()));
  m_Units.push_back(tr("Ironguts"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Ironguts, m_Units.back()));
  m_Units.push_back(tr("Leadbelchers"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Leadbelchers, m_Units.back()));
  m_Units.push_back(tr("Gorgers"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Gorgers, m_Units.back()));
  m_Units.push_back(tr("Ironblaster"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Ironblaster, m_Units.back()));
  m_Units.push_back(tr("Gnoblar Scraplauncher"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Gnoblar_Scraplauncher, m_Units.back()));
  m_Units.push_back(tr("Gnoblar Fighters"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Gnoblar_Fighters, m_Units.back()));
  m_Units.push_back(tr("Firebelly"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Firebelly, m_Units.back()));
  m_Units.push_back(tr("Hunter"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Hunter, m_Units.back()));
  m_Units.push_back(tr("Sabertusks"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Sabertusks, m_Units.back()));
  m_Units.push_back(tr("Mournfang Cavalry"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Mournfang_Cavalry, m_Units.back()));
  m_Units.push_back(tr("Stonehorn"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Stonehorn, m_Units.back()));
  m_Units.push_back(tr("Thundertusk"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Thundertusk, m_Units.back()));
  m_Units.push_back(tr("Golgfag Maneater"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Golgfag_Maneater, m_Units.back()));
  m_Units.push_back(tr("Maneaters"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Maneaters, m_Units.back()));
  m_Units.push_back(tr("Yhetees"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Yhetees, m_Units.back()));
  m_Units.push_back(tr("Giant"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Giant_in_Ogre_Kingdoms, m_Units.back()));
}

const QStringList &OgreKingdomsFaction::getUnits() const
{
  return m_Units;
}

QList<WarScroll> OgreKingdomsFaction::getWarScrolls() const
{
  QList<WarScroll> warScrolls;
  for (auto ws : m_NameToWarScroll.toStdMap()) {
    warScrolls.push_back(ws.second(ws.first));
  }
  return warScrolls;
}
