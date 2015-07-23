#include "bretonniafaction.h"

namespace WarScrollGeneration
{
  WarScroll King_Louen_Leoncoeur(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll The_Fay_Enchantress(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll The_Green_Knight(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Bretonnian_Lord(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Paladin(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Paladin_Standard_Bearer(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Damsel_of_the_Lady(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Knights_Errant(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    ws.setTitle(name);
    return ws;
  }

  WarScroll Knights_of_the_Realm(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Questing_Knights(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Grail_Knights(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Pegasus_Knights(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Battle_Pilgrims(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Men_at_Arms(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Peasant_Bowmen(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Mounted_Yeomen(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Field_Trebuchet(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }
}

BretonniaFaction::BretonniaFaction() :
  IFaction(nullptr)
{
  m_Units.push_back(tr(""));
  m_Units.push_back(tr("King Louen Leoncoeur"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::King_Louen_Leoncoeur, m_Units.back()));
  m_Units.push_back(tr("The Fay Enchantress"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::The_Fay_Enchantress, m_Units.back()));
  m_Units.push_back(tr("The Green Knight"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::The_Green_Knight, m_Units.back()));
  m_Units.push_back(tr("Bretonnian Lord"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Bretonnian_Lord, m_Units.back()));
  m_Units.push_back(tr("Paladin"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Paladin, m_Units.back()));
  m_Units.push_back(tr("Paladin Standard Bearer"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Paladin_Standard_Bearer, m_Units.back()));
  m_Units.push_back(tr("Damsel of the Lady"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Damsel_of_the_Lady, m_Units.back()));
  m_Units.push_back(tr("Knights Errant"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Knights_Errant, m_Units.back()));
  m_Units.push_back(tr("Knights of the Realm"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Knights_of_the_Realm, m_Units.back()));
  m_Units.push_back(tr("Questing Knights"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Questing_Knights, m_Units.back()));
  m_Units.push_back(tr("Grail Knights"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Grail_Knights, m_Units.back()));
  m_Units.push_back(tr("Pegasus Knights"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Pegasus_Knights, m_Units.back()));
  m_Units.push_back(tr("Battle Pilgrims"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Battle_Pilgrims, m_Units.back()));
  m_Units.push_back(tr("Men-at-Arms"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Men_at_Arms, m_Units.back()));
  m_Units.push_back(tr("Peasant Bowmen"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Peasant_Bowmen, m_Units.back()));
  m_Units.push_back(tr("Mounted Yeomen"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Mounted_Yeomen, m_Units.back()));
  m_Units.push_back(tr("Field Trebuchet"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Field_Trebuchet, m_Units.back()));
}

const QStringList &BretonniaFaction::getUnits() const
{
  return m_Units;
}

QList<WarScroll> BretonniaFaction::getWarScrolls() const
{
  QList<WarScroll> warScrolls;
  for (auto ws : m_NameToWarScroll.toStdMap()) {
    warScrolls.push_back(ws.second(ws.first));
  }
  return warScrolls;
}
