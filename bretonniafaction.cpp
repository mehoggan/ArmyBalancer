#include "bretonniafaction.h"

namespace WarScrollGeneration
{
  WarScroll King_Louen_Leoncoeur()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll The_Fay_Enchantress()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll The_Green_Knight()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll Bretonnian_Lord()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll Paladin()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll Paladin_Standard_Bearer()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll Damsel_of_the_Lady()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll Knights_Errant()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll Knights_of_the_Realm()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll Questing_Knights()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll Grail_Knights()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll Pegasus_Knights()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll Battle_Pilgrims()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll Men_at_Arms()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll Peasant_Bowmen()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll Mounted_Yeomen()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll Field_Trebuchet()
  {
    WarScroll ws;
    return ws;
  }
}

BretonniaFaction::BretonniaFaction() :
  IFaction(nullptr)
{
  m_Units.push_back(tr(""));
  m_Units.push_back(tr("King Louen Leoncoeur"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::King_Louen_Leoncoeur);
  m_Units.push_back(tr("The Fay Enchantress"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::The_Fay_Enchantress);
  m_Units.push_back(tr("The Green Knight"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::The_Green_Knight);
  m_Units.push_back(tr("Bretonnian Lord"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::Bretonnian_Lord);
  m_Units.push_back(tr("Paladin"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::Paladin);
  m_Units.push_back(tr("Paladin Standard Bearer"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::Paladin_Standard_Bearer);
  m_Units.push_back(tr("Damsel of the Lady"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::Damsel_of_the_Lady);
  m_Units.push_back(tr("Knights Errant"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::Knights_Errant);
  m_Units.push_back(tr("Knights of the Realm"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::Knights_of_the_Realm);
  m_Units.push_back(tr("Questing Knights"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::Questing_Knights);
  m_Units.push_back(tr("Grail Knights"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::Grail_Knights);
  m_Units.push_back(tr("Pegasus Knights"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::Pegasus_Knights);
  m_Units.push_back(tr("Battle Pilgrims"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::Battle_Pilgrims);
  m_Units.push_back(tr("Men-at-Arms"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::Men_at_Arms);
  m_Units.push_back(tr("Peasant Bowmen"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::Peasant_Bowmen);
  m_Units.push_back(tr("Mounted Yeomen"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::Mounted_Yeomen);
  m_Units.push_back(tr("Field Trebuchet"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::Field_Trebuchet);
}

const QStringList &BretonniaFaction::getUnits() const
{
  return m_Units;
}

QList<WarScroll> BretonniaFaction::getWarScrolls() const
{
  QList<WarScroll> warScrolls;
  return warScrolls;
}
