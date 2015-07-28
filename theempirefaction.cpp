﻿#include "theempirefaction.h"

namespace WarScrollGeneration
{
  WarScroll Karl_Franz_on_Deathclaw(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Kurt_Helborg(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Balthasar_Gelt_the_Supreme_Patriarch(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Valten(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Marius_Leitdorf(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Empire_General(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll General_of_the_Empire_on_Imperial_Griffon(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Ludwig_Schwarzhelm(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Markus_Wulfhart(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Grand_Master(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Demigryph_Knights(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Empire_Knights(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Reiksguard_Knights(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Empire_Crossbowmen(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Empire_Handgunners(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Empire_Archers(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Empire_Greatswords(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Empire_Pistoliers(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Empire_Outriders(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Empire_State_Troops(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Empire_Free_Company_Militia(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Empire_Master_Engineer(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Master_Engineer_on_Mechanical_Steed(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Empire_Cannon(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Empire_Mortor(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Hellblaster_Volley_Gun(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Hellstorm_Rocket_Battery(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Empire_Steam_Tank(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Volkmar_the_Grim(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll The_War_Alter_of_Sigmar(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Luthor_Huss_Prophet_of_Sigmar(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Warrior_Priest(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Witch_Hunter(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Empire_Flagellants_Warband(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Celestial_Hurricanum(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Empire_Battle_Wizard(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Amber_Battle_Wizard_on_Imperial_Griffon(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Luminark_of_Hysh(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }
}

TheEmpireFaction::TheEmpireFaction() :
  IFaction(nullptr)
{
  m_Units.push_back("");
  m_Units.push_back("Karl Franz on Deathclaw");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Karl_Franz_on_Deathclaw, m_Units.back())));
  m_Units.push_back("Kurt Helborg");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Kurt_Helborg, m_Units.back())));
  m_Units.push_back("Balthasar Gelt, the Supreme Patriarch");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Balthasar_Gelt_the_Supreme_Patriarch,
    m_Units.back())));
  m_Units.push_back("Valten");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Valten, m_Units.back())));
  m_Units.push_back("Marius Leitdorf");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Marius_Leitdorf, m_Units.back())));
  m_Units.push_back("Empire General");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Empire_General, m_Units.back())));
  m_Units.push_back("General of the Empire on Imperial Griffon");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::General_of_the_Empire_on_Imperial_Griffon,
    m_Units.back())));
  m_Units.push_back("Ludwig Schwarzhelm");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Ludwig_Schwarzhelm, m_Units.back())));
  m_Units.push_back("Markus Wulfhart");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Markus_Wulfhart, m_Units.back())));
  m_Units.push_back("Grand Master");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Grand_Master, m_Units.back())));
  m_Units.push_back("Demigryph Knights");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Demigryph_Knights, m_Units.back())));
  m_Units.push_back("Empire Knights");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Empire_Knights, m_Units.back())));
  m_Units.push_back("Reiksguard Knights");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Reiksguard_Knights, m_Units.back())));
  m_Units.push_back("Empire Crossbowmen");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Empire_Crossbowmen, m_Units.back())));
  m_Units.push_back("Empire Handgunners");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Empire_Handgunners, m_Units.back())));
  m_Units.push_back("Empire Archers");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Empire_Archers, m_Units.back())));
  m_Units.push_back("Empire Greatswords");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Empire_Greatswords, m_Units.back())));
  m_Units.push_back("Empire Pistoliers");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Empire_Pistoliers, m_Units.back())));
  m_Units.push_back("Empire Outriders");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Empire_Outriders, m_Units.back())));
  m_Units.push_back("Empire State Troops");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Empire_State_Troops, m_Units.back())));
  m_Units.push_back("Empire Free Company Militia");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Empire_Free_Company_Militia,
    m_Units.back())));
  m_Units.push_back("Empire Master Engineer");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Empire_Master_Engineer, m_Units.back())));
  m_Units.push_back("Master Engineer on Mechanical Steed");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Master_Engineer_on_Mechanical_Steed,
    m_Units.back())));
  m_Units.push_back("Empire Cannon");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Empire_Cannon, m_Units.back())));
  m_Units.push_back("Empire Mortor");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Empire_Mortor, m_Units.back())));
  m_Units.push_back("Hellblaster Volley Gun");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Hellblaster_Volley_Gun, m_Units.back())));
  m_Units.push_back("Hellstorm Rocket Battery");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Hellstorm_Rocket_Battery, m_Units.back())));
  m_Units.push_back("Empire Steam Tank");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Empire_Steam_Tank, m_Units.back())));
  m_Units.push_back("Volkmar the Grim");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Volkmar_the_Grim, m_Units.back())));
  m_Units.push_back("The War Alter of Sigmar");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::The_War_Alter_of_Sigmar, m_Units.back())));
  m_Units.push_back("Luthor Huss, Prophet of Sigmar");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Luthor_Huss_Prophet_of_Sigmar,
    m_Units.back())));
  m_Units.push_back("Warrior Priest");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Warrior_Priest, m_Units.back())));
  m_Units.push_back("Witch Hunter");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Witch_Hunter, m_Units.back())));
  m_Units.push_back("Empire Flagellants Warband");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Empire_Flagellants_Warband,
    m_Units.back())));
  m_Units.push_back("Celestial Hurricanum");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Celestial_Hurricanum, m_Units.back())));
  m_Units.push_back("Empire Battle Wizard");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Empire_Battle_Wizard, m_Units.back())));
  m_Units.push_back("Amber Battle Wizard on Imperial Griffon");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Amber_Battle_Wizard_on_Imperial_Griffon,
    m_Units.back())));
  m_Units.push_back("Luminark of Hysh");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Luminark_of_Hysh, m_Units.back())));
}

const std::vector<std::string> &TheEmpireFaction::getUnits() const
{
  return m_Units;
}

void TheEmpireFaction::getWarScrolls(std::list<WarScroll>& warScrolls)
{
  for (const std::string &unit : m_Units) {
    if (unit.empty()) {
      continue;
    }
    WarScroll ws = m_NameToWarScroll[unit](unit);
    warScrolls.push_back(ws);
  }
}