#include "highelvesfaction.h"

namespace WarScrollGeneration
{
  WarScroll Tyrion(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Teclis(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Eltharion_on_Stormwing(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Prince_Imrik_Dragonlord(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Prince_Althran(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll High_Elf_Prince(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll High_Elf_Prince_on_Griffon(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll High_Elf_Prince_on_Dragon(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll High_Elf_Archmage_on_Dragon(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll High_Elf_Mage(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Dragon_Mage(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll High_Elf_Spearmen(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll High_Elf_Archers(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Silver_Helms(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Ellyrian_Reavers(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Dragon_Princes_of_Caledor(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Tiranoc_Chariots(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll High_Elf_Repeater_Bolt_Thrower(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Great_Eagles_in_High_Elves(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Alith_Anar_The_Shadow_King(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Shadow_Warriors(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Alarielle_the_Radiant(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Handmaiden_of_the_Everqueen(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Sisters_of_Avelorn(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Caradryan(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Anointed_of_Asuryan(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Phoenix_Guard(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Flamespyre_Phoenix(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Frostheart_Phoenix(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Loremaster_of_Hoeth(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll High_Elf_Swordmasters_of_Hoeth(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Korhil(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll White_Lions_of_Chrace(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll White_Lion_Chariots(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Lothern_Sea_Helm(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Lothern_Sea_Helm_on_Skycutter(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Lothern_Sea_Guard(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Lothern_Skycutters(const QString &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }
}

HighElvesFaction::HighElvesFaction() :
  IFaction(nullptr)
{
  m_Units.push_back(tr(""));
  m_Units.push_back(tr("Tyrion"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Tyrion, m_Units.back()));
  m_Units.push_back(tr("Teclis"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Teclis, m_Units.back()));
  m_Units.push_back(tr("Eltharion on Stormwing"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Eltharion_on_Stormwing, m_Units.back()));
  m_Units.push_back(tr("Prince Imrik, Dragonlord"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Prince_Imrik_Dragonlord, m_Units.back()));
  m_Units.push_back(tr("Prince Althran"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Prince_Althran, m_Units.back()));
  m_Units.push_back(tr("High Elf Prince"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::High_Elf_Prince, m_Units.back()));
  m_Units.push_back(tr("High Elf Prince on Griffon"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::High_Elf_Prince_on_Griffon,
    m_Units.back()));
  m_Units.push_back(tr("High Elf Prince on Dragon"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::High_Elf_Prince_on_Dragon,
    m_Units.back()));
  m_Units.push_back(tr("High Elf Archmage on Dragon"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::High_Elf_Archmage_on_Dragon,
    m_Units.back()));
  m_Units.push_back(tr("High Elf Mage"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::High_Elf_Mage, m_Units.back()));
  m_Units.push_back(tr("Dragon Mage"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Dragon_Mage, m_Units.back()));
  m_Units.push_back(tr("High Elf Spearmen"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::High_Elf_Spearmen, m_Units.back()));
  m_Units.push_back(tr("High Elf Archers"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::High_Elf_Archers, m_Units.back()));
  m_Units.push_back(tr("Silver Helms"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Silver_Helms, m_Units.back()));
  m_Units.push_back(tr("Ellyrian Reavers"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Ellyrian_Reavers, m_Units.back()));
  m_Units.push_back(tr("Dragon Princes of Caledor"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Dragon_Princes_of_Caledor, m_Units.back()));
  m_Units.push_back(tr("Tiranoc Chariots"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Tiranoc_Chariots, m_Units.back()));
  m_Units.push_back(tr("High Elf Repeater Bolt Thrower"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::High_Elf_Repeater_Bolt_Thrower,
    m_Units.back()));
  m_Units.push_back(tr("Great Eagles"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Great_Eagles_in_High_Elves,
    m_Units.back()));
  m_Units.push_back(tr("Alith Anar, The Shadow King"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Alith_Anar_The_Shadow_King,
    m_Units.back()));
  m_Units.push_back(tr("Shadow Warriors"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Shadow_Warriors, m_Units.back()));
  m_Units.push_back(tr("Alarielle the Radiant"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Alarielle_the_Radiant, m_Units.back()));
  m_Units.push_back(tr("Handmaiden of the Everqueen"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Handmaiden_of_the_Everqueen,
    m_Units.back()));
  m_Units.push_back(tr("Sisters of Avelorn"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Sisters_of_Avelorn, m_Units.back()));
  m_Units.push_back(tr("Caradryan"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Caradryan, m_Units.back()));
  m_Units.push_back(tr("Anointed of Asuryan"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Anointed_of_Asuryan, m_Units.back()));
  m_Units.push_back(tr("Phoenix Guard"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Phoenix_Guard, m_Units.back()));
  m_Units.push_back(tr("Flamespyre Phoenix"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Flamespyre_Phoenix, m_Units.back()));
  m_Units.push_back(tr("Frostheart Phoenix"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Frostheart_Phoenix, m_Units.back()));
  m_Units.push_back(tr("Loremaster of Hoeth"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Loremaster_of_Hoeth, m_Units.back()));
  m_Units.push_back(tr("High Elf Swordmasters of Hoeth"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::High_Elf_Swordmasters_of_Hoeth,
    m_Units.back()));
  m_Units.push_back(tr("Korhil"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Korhil, m_Units.back()));
  m_Units.push_back(tr("White Lions of Chrace"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::White_Lions_of_Chrace, m_Units.back()));
  m_Units.push_back(tr("White Lion Chariots"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::White_Lion_Chariots, m_Units.back()));
  m_Units.push_back(tr("Lothern Sea Helm"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Lothern_Sea_Helm, m_Units.back()));
  m_Units.push_back(tr("Lothern Sea Helm on Skycutter"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Lothern_Sea_Helm_on_Skycutter,
    m_Units.back()));
  m_Units.push_back(tr("Lothern Sea Guard"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Lothern_Sea_Guard, m_Units.back()));
  m_Units.push_back(tr("Lothern Skycutters"));
  m_NameToWarScroll.insert(m_Units.back(),
    std::bind(&WarScrollGeneration::Lothern_Skycutters, m_Units.back()));
}

const QStringList &HighElvesFaction::getUnits() const
{
  return m_Units;
}

QList<WarScroll> HighElvesFaction::getWarScrolls() const
{
  QList<WarScroll> warScrolls;
  for (auto ws : m_NameToWarScroll.toStdMap()) {
    warScrolls.push_back(ws.second(ws.first));
  }
  return warScrolls;
}
