#include "highelvesfaction.h"

namespace WarScrollGeneration
{
  WarScroll Tyrion()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll Teclis()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll Eltharion_on_Stormwing()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll Prince_Imrik_Dragonlord()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll Prince_Althran()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll High_Elf_Prince()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll High_Elf_Prince_on_Griffon()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll High_Elf_Prince_on_Dragon()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll High_Elf_Archmage_on_Dragon()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll High_Elf_Mage()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll Dragon_Mage()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll High_Elf_Spearmen()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll High_Elf_Archers()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll Silver_Helms()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll Ellyrian_Reavers()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll Dragon_Princes_of_Caledor()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll Tiranoc_Chariots()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll High_Elf_Repeater_Bolt_Thrower()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll Great_Eagles()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll Alith_Anar_The_Shadow_King()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll Shadow_Warriors()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll Alarielle_the_Radiant()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll Handmaiden_of_the_Everqueen()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll Sisters_of_Avelorn()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll Caradryan()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll Anointed_of_Asuryan()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll Phoenix_Guard()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll Flamespyre_Phoenix()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll Frostheart_Phoenix()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll Loremaster_of_Hoeth()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll High_Elf_Swordmasters_of_Hoeth()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll Korhil()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll White_Lions_of_Chrace()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll White_Lion_Chariots()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll Lothern_Sea_Helm()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll Lothern_Sea_Helm_on_Skycutter()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll Lothern_Sea_Guard()
  {
    WarScroll ws;
    return ws;
  }

  WarScroll Lothern_Skycutters()
  {
    WarScroll ws;
    return ws;
  }
}

HighElvesFaction::HighElvesFaction() :
  IFaction(nullptr)
{
  m_Units.push_back(tr(""));
  m_Units.push_back(tr("Tyrion"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::Tyrion);
  m_Units.push_back(tr("Teclis"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::Teclis);
  m_Units.push_back(tr("Eltharion on Stormwing"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::Eltharion_on_Stormwing);
  m_Units.push_back(tr("Prince Imrik, Dragonlord"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::Prince_Imrik_Dragonlord);
  m_Units.push_back(tr("Prince Althran"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::Prince_Althran);
  m_Units.push_back(tr("High Elf Prince"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::High_Elf_Prince);
  m_Units.push_back(tr("High Elf Prince on Griffon"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::High_Elf_Prince_on_Griffon);
  m_Units.push_back(tr("High Elf Prince on Dragon"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::High_Elf_Prince_on_Dragon);
  m_Units.push_back(tr("High Elf Archmage on Dragon"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::High_Elf_Archmage_on_Dragon);
  m_Units.push_back(tr("High Elf Mage"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::High_Elf_Mage);
  m_Units.push_back(tr("Dragon Mage"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::Dragon_Mage);
  m_Units.push_back(tr("High Elf Spearmen"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::High_Elf_Spearmen);
  m_Units.push_back(tr("High Elf Archers"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::High_Elf_Archers);
  m_Units.push_back(tr("Silver Helms"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::Silver_Helms);
  m_Units.push_back(tr("Ellyrian Reavers"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::Ellyrian_Reavers);
  m_Units.push_back(tr("Dragon Princes of Caledor"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::Dragon_Princes_of_Caledor);
  m_Units.push_back(tr("Tiranoc Chariots"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::Tiranoc_Chariots);
  m_Units.push_back(tr("High Elf Repeater Bolt Thrower"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::High_Elf_Repeater_Bolt_Thrower);
  m_Units.push_back(tr("Great Eagles"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::Great_Eagles);
  m_Units.push_back(tr("Alith Anar, The Shadow King"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::Alith_Anar_The_Shadow_King);
  m_Units.push_back(tr("Shadow Warriors"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::Shadow_Warriors);
  m_Units.push_back(tr("Alarielle the Radiant"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::Alarielle_the_Radiant);
  m_Units.push_back(tr("Handmaiden of the Everqueen"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::Handmaiden_of_the_Everqueen);
  m_Units.push_back(tr("Sisters of Avelorn"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::Sisters_of_Avelorn);
  m_Units.push_back(tr("Caradryan"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::Caradryan);
  m_Units.push_back(tr("Anointed of Asuryan"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::Anointed_of_Asuryan);
  m_Units.push_back(tr("Phoenix Guard"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::Phoenix_Guard);
  m_Units.push_back(tr("Flamespyre Phoenix"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::Flamespyre_Phoenix);
  m_Units.push_back(tr("Frostheart Phoenix"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::Frostheart_Phoenix);
  m_Units.push_back(tr("Loremaster of Hoeth"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::Loremaster_of_Hoeth);
  m_Units.push_back(tr("High Elf Swordmasters of Hoeth"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::High_Elf_Swordmasters_of_Hoeth);
  m_Units.push_back(tr("Korhil"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::Korhil);
  m_Units.push_back(tr("White Lions of Chrace"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::White_Lions_of_Chrace);
  m_Units.push_back(tr("White Lion Chariots"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::White_Lion_Chariots);
  m_Units.push_back(tr("Lothern Sea Helm"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::Lothern_Sea_Helm);
  m_Units.push_back(tr("Lothern Sea Helm on Skycutter"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::Lothern_Sea_Helm_on_Skycutter);
  m_Units.push_back(tr("Lothern Sea Guard"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::Lothern_Sea_Guard);
  m_Units.push_back(tr("Lothern Skycutters"));
  m_NameToWarScroll.insert(m_Units.back(),
    &WarScrollGeneration::Lothern_Skycutters);
}

const QStringList &HighElvesFaction::getUnits() const
{
  return m_Units;
}

QList<WarScroll> HighElvesFaction::getWarScrolls() const
{
  QList<WarScroll> warScrolls;
  return warScrolls;
}
