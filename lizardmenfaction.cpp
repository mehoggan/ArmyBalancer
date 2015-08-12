#include "lizardmenfaction.h"

namespace WarScrollGeneration
{
  WarScroll Lord_Kroak(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(5, 10, 10, 4);
    ws.addWeapon(WarScroll::Weapon("Ancient Spirits' Spectral Claws",
      3, 12, 3, 3, 1, 1));

    ws.setCanFly(true);

    ws.addAbility(WarScroll::Ability("Dead for Innumerable Ages", 3));
    ws.addSpell(WarScroll::Spell("Celestial Deliverance"), 7, 2);
    ws.addSpell(WarScroll::Spell("Comet's Call"), 7, 2);

    ws.addAbility(WarScroll::Ability("Impeccable Foresight", 2));

    ws.addKeyWords({"ORDER", "CELESTIAL", "SERAPHON", "SLANN", "HERO",
      "WIZARD", "LORD KROAK"});

    return ws;
  }

  WarScroll Slann_Mage_Priest(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(5, 7, 10, 4);

    ws.addWeapon(WarScroll::Weapon("Azure Lightning", 3, 6, 4, 3, 1, 1));

    ws.setCanFly(true);

    ws.addAbility(WarScroll::Ability("Celestial Configuration", 3));
    ws.addAbility(WarScroll::Ability("Arcane Vassal", 2));

    ws.addSpell(WarScroll::Spell("Light of the Heavens"), 6, 1);

    ws.addAbility(WarScroll::Ability("Gift from the Heavens", 2, true));

    ws.addKeyWords({"ORDER", "CELESTIAL", "SERAPHON", "SLANN", "HERO",
      "WIZARD", "SLANN MAGE-PRIEST"});

    return ws;
  }

  WarScroll Kroq_Gar_on_Carnosaur(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(10, 12, 10, 4);

    ws.addWeapon(WarScroll::Weapon("Sunbolt Gauntlet", 18, 6, 3, 4, 1, 1));
    ws.addWeapon(WarScroll::Weapon("Sunstone Spear", 2, 3, 3, 3, 1, 3));
    ws.addWeapon(WarScroll::Weapon("Carnosaur's Clawed Forelimbs",
      2, 2, 3, 3, 0, 2));
    ws.addWeapon(WarScroll::Weapon("Carnosaur's Massive Jaws",
      2, 5, 4, 3, 1, 3));

    ws.addAbility(WarScroll::Ability("Pinned Down", 2));
    ws.addAbility(WarScroll::Ability("Blood Frenzy", 2));
    ws.addAbility(WarScroll::Ability("Bloodroar", 3));
    ws.addAbility(WarScroll::Ability("Blazing Sunbolts", 2));
    ws.addAbility(WarScroll::Ability("Ancient Warlord", 2));

    ws.addKeyWords({"ORDER", "DAEMON", "CELESTIAL", "SERAPHON", "CARNOSAUR",
      "SAURUS", "MONSTER", "HERO", "KROQ-GAR"});

    return ws;
  }

  WarScroll Saurus_Oldblood(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);

    ws.setCharacteristics(5, 7, 10, 4);

    ws.addWeapon(WarScroll::Weapon("Fearsome Jaws and Stardrake Shield",
      1, 1, 4, 3, 0, 1));

    ws.addWeaponUpgrade(WarScroll::WeaponUpgrade(
      WarScroll::Weapon("Suntooth Maul", 1, 2, 3, 4, 1, 3),
      WarScroll::Ability()));
    ws.addWeaponUpgrade(WarScroll::WeaponUpgrade(
      WarScroll::Weapon("Celestite Warblade", 1, 4, 3, 3, 0, 1),
      WarScroll::Ability()));
    ws.addWeaponUpgrade(WarScroll::WeaponUpgrade(
      WarScroll::Weapon("Celestite War-spear", 2, 4, 4, 3, 1, 1),
      WarScroll::Ability()));
    ws.addWeaponUpgrade(WarScroll::WeaponUpgrade(
      WarScroll::Weapon("Celestite Greatblade", 1, 2, 4, 3, 1, 2),
      WarScroll::Ability()));

    ws.addAbility(WarScroll::Ability("Stardrake Shields", 2));
    ws.addAbility(WarScroll::Ability("Wrath of the Seraphon", 1));
    ws.addAbility(WarScroll::Ability("Paragon of Order", 2, true));

    ws.addKeyWords({"ORDER", "DAEMON", "CELESTIAL", "SERAPHON", "SAURUS",
      "HERO", "SAURUS OLDBLOOD"});

    return ws;
  }

  WarScroll Saurus_Oldblood_on_Cold_One(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Chakax_the_Eternity_Warden(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Gor_Rok(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Scar_vetran_with_Battle_Standard(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Scar_vetran_on_Carnosaur(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Saurus_Warriors(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Temple_Guard(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Saurus_Cavalry(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Tehenhauin_Prophet_of_Sotek(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Tetto_eko(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Oxyotl(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Skink_Priest(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Skink_Chief(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Skinks(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Chameleon_Skinks(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Terradon_Riders(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Ripperdactyl_Riders(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Skink_Handlers(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Salamanders(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Razordons(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Kroxigor(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Stegadon(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Engine_of_the_Gods(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Bastiladon(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Troglodon(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }

  WarScroll Jungle_Swarms(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    return ws;
  }
}

LizardmenFaction::LizardmenFaction() :
  IFaction(nullptr)
{
  m_Units.push_back("");
  m_Units.push_back("Lord Kroak");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Lord_Kroak, m_Units.back())));
  m_Units.push_back("Slann Mage-Priest");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Slann_Mage_Priest, m_Units.back())));
  m_Units.push_back("Kroq-Gar on Carnosaur");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Kroq_Gar_on_Carnosaur, m_Units.back())));
  m_Units.push_back("Saurus Oldblood");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Saurus_Oldblood, m_Units.back())));
  m_Units.push_back("Saurus Oldblood on Cold One");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Saurus_Oldblood_on_Cold_One,
    m_Units.back())));
  m_Units.push_back("Chakax, the Eternity Warden");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Chakax_the_Eternity_Warden, m_Units.back())));
  m_Units.push_back("Gor-Rok");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Gor_Rok, m_Units.back())));
  m_Units.push_back("Scar-vetran with Battle Standard");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Scar_vetran_with_Battle_Standard,
    m_Units.back())));
  m_Units.push_back("Scar-vetran on Carnosaur");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Scar_vetran_on_Carnosaur, m_Units.back())));
  m_Units.push_back("Saurus Warriors");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Saurus_Warriors, m_Units.back())));
  m_Units.push_back("Temple Guard");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Temple_Guard, m_Units.back())));
  m_Units.push_back("Saurus Cavalry");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Saurus_Cavalry, m_Units.back())));
  m_Units.push_back("Tehenhauin, Prophet of Sotek");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Tehenhauin_Prophet_of_Sotek,
    m_Units.back())));
  m_Units.push_back("Tetto'eko");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Tetto_eko, m_Units.back())));
  m_Units.push_back("Oxyotl");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Oxyotl, m_Units.back())));
  m_Units.push_back("Skink Priest");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Skink_Priest, m_Units.back())));
  m_Units.push_back("Skink Chief");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Skink_Chief, m_Units.back())));
  m_Units.push_back("Skinks");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Skinks, m_Units.back())));
  m_Units.push_back("Chameleon Skinks");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Chameleon_Skinks, m_Units.back())));
  m_Units.push_back("Terradon Riders");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Terradon_Riders, m_Units.back())));
  m_Units.push_back("Ripperdactyl Riders");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Ripperdactyl_Riders, m_Units.back())));
  m_Units.push_back("Skink Handlers");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Skink_Handlers, m_Units.back())));
  m_Units.push_back("Salamanders");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Salamanders, m_Units.back())));
  m_Units.push_back("Razordons");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Razordons, m_Units.back())));
  m_Units.push_back("Kroxigor");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Kroxigor, m_Units.back())));
  m_Units.push_back("Stegadon");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Stegadon, m_Units.back())));
  m_Units.push_back("Engine of the Gods");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Engine_of_the_Gods, m_Units.back())));
  m_Units.push_back("Bastiladon");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Bastiladon, m_Units.back())));
  m_Units.push_back("Troglodon");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Troglodon, m_Units.back())));
  m_Units.push_back("Jungle Swarms");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Jungle_Swarms, m_Units.back())));
}

const std::vector<std::string> &LizardmenFaction::getUnits() const
{
  return m_Units;
}

void LizardmenFaction::getWarScrolls(std::list<WarScroll>& warScrolls)
{
  for (const std::string &unit : m_Units) {
    if (unit.empty()) {
      continue;
    }
    WarScroll ws = m_NameToWarScroll[unit](unit);
    warScrolls.push_back(ws);
  }
}
