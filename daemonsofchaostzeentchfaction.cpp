#include "daemonsofchaostzeentchfaction.h"

namespace WarScrollGeneration
{
  WarScroll Kairos_Fateweaver(const QString &name)
  {
    qDebug() << "Generating WarScroll for " << name;
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Lord_of_Change(const QString &name)
  {
    qDebug() << "Generating WarScroll for " << name;
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll The_Changeling(const QString &name)
  {
    qDebug() << "Generating WarScroll for " << name;
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Herald_of_Tzeentch(const QString &name)
  {
    qDebug() << "Generating WarScroll for " << name;
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Herald_of_Tzeentch_on_Disc_of_Tzeentch(const QString &name)
  {
    qDebug() << "Generating WarScroll for " << name;
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Herald_of_Tzeentch_on_Burning_Chariot(const QString &name)
  {
    qDebug() << "Generating WarScroll for " << name;
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll The_Blue_Scribes(const QString &name)
  {
    qDebug() << "Generating WarScroll for " << name;
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Pink_Horrors_of_Tzeentch(const QString &name)
  {
    qDebug() << "Generating WarScroll for " << name;
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Exalted_Flamers(const QString &name)
  {
    qDebug() << "Generating WarScroll for " << name;
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Flamers_of_Tzeentch(const QString &name)
  {
    qDebug() << "Generating WarScroll for " << name;
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Screamers_of_Tzeentch(const QString &name)
  {
    qDebug() << "Generating WarScroll for " << name;
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Burning_Chariots_of_Tzeeentch(const QString &name)
  {
    qDebug() << "Generating WarScroll for " << name;
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Daemon_Prince_in_Tzeentch(const QString &name)
  {
    qDebug() << "Generating WarScroll for " << name;
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Furies_in_Tzeentch(const QString &name)
  {
    qDebug() << "Generating WarScroll for " << name;
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Soul_Grinder_in_Tzeentch(const QString &name)
  {
    qDebug() << "Generating WarScroll for " << name;
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }
}

DaemonsOfChaosTzeentchFaction::DaemonsOfChaosTzeentchFaction() :
  IFaction(nullptr)
{
  m_Units.push_back(tr(""));
  m_Units.push_back(tr("Kairos Fateweaver"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Kairos_Fateweaver, m_Units.back()));
  m_Units.push_back(tr("Lord of Change"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Lord_of_Change, m_Units.back()));
  m_Units.push_back(tr("The Changeling"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::The_Changeling, m_Units.back()));
  m_Units.push_back(tr("Herald of Tzeentch"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Herald_of_Tzeentch, m_Units.back()));
  m_Units.push_back(tr("Herald of Tzeentch on Disc of Tzeentch"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Herald_of_Tzeentch_on_Disc_of_Tzeentch, m_Units.back()));
  m_Units.push_back(tr("Herald of Tzeentch on Burning Chariot"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Herald_of_Tzeentch_on_Burning_Chariot, m_Units.back()));
  m_Units.push_back(tr("The Blue Scribes"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::The_Blue_Scribes, m_Units.back()));
  m_Units.push_back(tr("Pink Horrors of Tzeentch"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Pink_Horrors_of_Tzeentch, m_Units.back()));
  m_Units.push_back(tr("Exalted Flamers"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Exalted_Flamers, m_Units.back()));
  m_Units.push_back(tr("Flamers of Tzeentch"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Flamers_of_Tzeentch, m_Units.back()));
  m_Units.push_back(tr("Screamers of Tzeentch"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Screamers_of_Tzeentch, m_Units.back()));
  m_Units.push_back(tr("Burning Chariots of Tzeeentch"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Burning_Chariots_of_Tzeeentch, m_Units.back()));
  m_Units.push_back(tr("Daemon Prince"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Daemon_Prince_in_Tzeentch, m_Units.back()));
  m_Units.push_back(tr("Furies"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Furies_in_Tzeentch, m_Units.back()));
  m_Units.push_back(tr("Soul Grinder"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Soul_Grinder_in_Tzeentch, m_Units.back()));
}

const QStringList &DaemonsOfChaosTzeentchFaction::getUnits() const
{
  return m_Units;
}

QList<WarScroll> DaemonsOfChaosTzeentchFaction::getWarScrolls() const
{
  QList<WarScroll> warScrolls;
  for (auto ws : m_NameToWarScroll.toStdMap()) {
    warScrolls.push_back(ws.second(ws.first));
  }
  return warScrolls;
}
