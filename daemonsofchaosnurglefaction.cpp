#include "daemonsofchaosnurglefaction.h"

namespace WarScrollGeneration
{
  WarScroll Great_Unclean_One(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Epidemius(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Herald_of_Nurgle(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Plaguebearers_of_Nurgle(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Plague_Drones_of_Nurgle(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Nurglings(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Beasts_of_Nurgle(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Daemon_Prince_in_Nurgle(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Furies_in_Nurgle(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Soul_Grinder_in_Nurgle(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }
}

DaemonsOfChaosNurgleFaction::DaemonsOfChaosNurgleFaction() :
  IFaction(nullptr)
{
  m_Units.push_back(tr(""));
  m_Units.push_back(tr("Great Unclean One"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Great_Unclean_One, m_Units.back()));
  m_Units.push_back(tr("Epidemius"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Epidemius, m_Units.back()));
  m_Units.push_back(tr("Herald of Nurgle"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Herald_of_Nurgle, m_Units.back()));
  m_Units.push_back(tr("Plaguebearers of Nurgle"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Plaguebearers_of_Nurgle, m_Units.back()));
  m_Units.push_back(tr("Plague Drones of Nurgle"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Plague_Drones_of_Nurgle, m_Units.back()));
  m_Units.push_back(tr("Nurglings"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Nurglings, m_Units.back()));
  m_Units.push_back(tr("Beasts of Nurgle"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Beasts_of_Nurgle, m_Units.back()));
  m_Units.push_back(tr("Daemon Prince"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Daemon_Prince_in_Nurgle, m_Units.back()));
  m_Units.push_back(tr("Furies"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Furies_in_Nurgle, m_Units.back()));
  m_Units.push_back(tr("Soul Grinder"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Soul_Grinder_in_Nurgle, m_Units.back()));
}

const QStringList &DaemonsOfChaosNurgleFaction::getUnits() const
{
  return m_Units;
}

QList<WarScroll> DaemonsOfChaosNurgleFaction::getWarScrolls() const
{
  QList<WarScroll> warScrolls;
  for (auto ws : m_NameToWarScroll.toStdMap()) {
    warScrolls.push_back(ws.second(ws.first));
  }
  return warScrolls;
}
