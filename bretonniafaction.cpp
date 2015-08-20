#include "bretonniafaction.h"

namespace WarScrollGeneration
{
  WarScroll King_Louen_Leoncoeur(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    ws.setCharacteristics(14, 10, 9, 3);
    ws.setCanFly(true);

    ws.addWeapon(WarScroll::Weapon("The Sword of Couronne", 2, 6, 3, 3, 1, 3));
    ws.addWeapon(WarScroll::Weapon("Beaquis' Talaons", 2, 5, 4, 3, 1, 1));
    ws.addWeapon(WarScroll::Weapon("Beaquis' Razor-sharp Beak",
      2, 1, 3, 3, 2, 6));

    ws.addAbility(WarScroll::Ability("Regal Crown", 3));
    ws.addAbility(WarScroll::Ability("The Lion's Shield", 3));
    ws.addAbility(WarScroll::Ability("The Puissant Virtue", 1));
    ws.addAbility(WarScroll::Ability("The Lady's Champion", 3));
    ws.addAbility(WarScroll::Ability("King of the Realm", 2, true));

    ws.addKeyWords({"ORDER", "HUMAN", "FREE PEOPLE", "NOBILITY", "HERO",
      "KING LOUEN LEONCOEUR"});

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eOrder);

    return ws;
  }

  WarScroll The_Fay_Enchantress(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    ws.setCharacteristics(14, 5, 8, 4);

    ws.addWeapon(WarScroll::Weapon("Fay Enchantress' Blessed Blade",
      1, 3, 4, 4, 1, 1));
    ws.addWeapon(WarScroll::Weapon("Silvaron's Enchanted Horn",
      1, 1, 4, 3, 1, 2));
    ws.addWeapon(WarScroll::Weapon("Silvaron's Silvershod Hooves",
      1, 3, 4, 4, 0, 1));

    ws.addAbility(WarScroll::Ability("Chalice of Potions", 3));
    ws.addAbility(WarScroll::Ability("Grail Guardians", 1));
    ws.addAbility(WarScroll::Ability("Spiteful Glance", 2));
    ws.addAbility(WarScroll::Ability("Supreme Aura of the Lady", 2));

    ws.addSpell(WarScroll::Spell("Favour of the Fay"), 6, 3);

    ws.addKeyWords({"ORDER", "HUMAN", "FREE PEOPLE", "NOBILITY", "HERO",
      "WIZARD", "DAMSEL OF THE LADY", "FAY ENCHANTRESS"});

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eOrder);
    return ws;
  }

  WarScroll The_Green_Knight(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    ws.setCharacteristics(12, 5, 9, 3);
    ws.setCanFly(true);

    ws.addWeapon(WarScroll::Weapon("The Dolorous Blade", 1, 4, 3, 3, 1, 2));
    ws.addWeapon(WarScroll::Weapon("Shadow Steed", 1, 2, 4, 3, 0, 1));

    ws.addAbility(WarScroll::Ability("Ethereal", 2));
    ws.addAbility(WarScroll::Ability("The Foliate Shield", 1));
    ws.addAbility((WarScroll::Ability("Summoned from the Mists", 2)));

    ws.addKeyWords({"ORDER", "HUMAN", "FREE PEOPLE", "NOBILITY",
      "GREEN KNIGHT"});

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eOrder);
    return ws;
  }

  WarScroll Bretonnian_Lord(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    ws.setCharacteristics(12, 5, 9, 3);

    ws.addWeapon(WarScroll::Weapon("Ducal Sword and Dragonbane Lance",
      2, 5, 3, 4, 1, 3));
    ws.addWeapon(WarScroll::Weapon("Steed's Hooves", 1, 2, 4, 4, 0, 1));
    ws.addAbility(WarScroll::Ability("Courage of the Bretonni", 3));
    ws.addAbility(WarScroll::Ability("Dragonbane Lance", 1));
    ws.addAbility(WarScroll::Ability("Ducal Shield", 1));
    ws.addAbility(WarScroll::Ability("Lord of the Realm", 2, true));

    WarScroll::UnitUpgrade pegasusUpgrade("Pegasus",
      WarScroll::UnitUpgrade::UnitUpgradeType::eMount, 3);
    pegasusUpgrade.setProvidesFly(true);
    pegasusUpgrade.registerCharacteristicToIncrease("Move", 4);
    ws.registerUnitUpgrade(pegasusUpgrade);

    ws.addKeyWords({"ORDER", "HUMAN", "FREE PEOPLE", "NOBILITY", "HERO",
      "BRETONNIAN LORD"});

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eOrder);
    return ws;
  }

  WarScroll Paladin(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    ws.setCharacteristics(5, 5, 7, 4);

    ws.addWeapon(WarScroll::Weapon("Relic Weapon", 1, 4, 3, 3, 1, 3));

    ws.addAbility(WarScroll::Ability("Paladin's Shield", 1));
    ws.addAbility(WarScroll::Ability("Heroic Blow", 2));

    ws.addKeyWords({"ORDER", "HUMAN", "FREE PEOPLE", "NOBILITY", "HERO",
      "PALADIN"});

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eOrder);
    return ws;
  }

  WarScroll Paladin_Standard_Bearer(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    ws.setCharacteristics(10, 5, 7, 3);

    ws.addWeapon(WarScroll::Weapon("Master-forged Sword", 1, 5, 3, 3, 1, 1));
    ws.addWeapon(WarScroll::Weapon("Dietrier's Iron-shod Hooves",
      1, 2, 4, 4, 0, 1));

    ws.addAbility(WarScroll::Ability("The Grail Banner", 3));
    ws.addAbility(WarScroll::Ability("Follow Me to Glory", 2));

    ws.addKeyWords({"ORDER", "HUMAN", "FREE PEOPLE", "NOBILITY", "HERO",
      "TOTEM", "PALADIN", "PALADIN STANDARD BEARER"});
    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eOrder);
    return ws;
  }

  WarScroll Damsel_of_the_Lady(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    ws.setCharacteristics(5, 5, 6, 6);

    ws.addWeapon(WarScroll::Weapon("Staff of Purity", 1, 1, 4, 3, 1, 3));

    ws.addAbility(WarScroll::Ability("Aura of the Lady", 1));

    ws.addSpell(WarScroll::Spell("Blessing of the Lady"), 5, 2);

    WarScroll::MountUpgrade pegasusUpgrade("Pegasus", true);
    pegasusUpgrade.registerCharacteristicToIncrease("Move", 11);
    pegasusUpgrade.addWeapon(WarScroll::Weapon("Steed's Hooves",
      1, 2, 4, 4, 0, 1));
    ws.registerMountUpgrade(pegasusUpgrade);

    WarScroll::MountUpgrade purebreadUpgrade("Purebred Horse");
    purebreadUpgrade.registerCharacteristicToIncrease("Move", 7);
    purebreadUpgrade.addWeapon(WarScroll::Weapon("Steed's Hooves",
      1, 2, 4, 4, 0, 1));
    ws.registerMountUpgrade(purebreadUpgrade);

    ws.addKeyWords({"ORDER", "HUMAN", "FREE PEOPLE", "NOBILITY", "HERO",
      "WIZARD", "DAMSEL OF THE LADY"});

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eOrder);
    return ws;
  }

  WarScroll Knights_Errant(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    ws.setCharacteristics(10, 2, 5, 4);
    ws.setMinMaxUnitCount(5, IFaction::s_MaxUnitSize);

    ws.addWeapon(WarScroll::Weapon("Pendant Lance and Blade",
      2, 1, 4, 4, 0, 1));
    ws.addWeapon(WarScroll::Weapon("Charger's Hooves", 1, 2, 4, 4, 0, 1));

    ws.addAbility(WarScroll::Ability("Eager to Impress", 1));
    ws.addAbility(WarScroll::Ability("Lances", 1));
    ws.addAbility(WarScroll::Ability("Heraldic Shields", 1));

    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Cavalier",
      WarScroll::UnitUpgrade::UnitUpgradeType::eChampion, 1));
    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Banner Bearer",
      WarScroll::UnitUpgrade::UnitUpgradeType::eBannerBearer, 2));
    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Trumpeter",
      WarScroll::UnitUpgrade::UnitUpgradeType::eMusician, 2));

    ws.addKeyWords({"ORDER", "HUMAN", "FREE PEOPLE", "NOBILITY",
      "KNIGHTS ERRANT"});

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eOrder);
    return ws;
  }

  WarScroll Knights_of_the_Realm(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    ws.setCharacteristics(10, 2, 6, 4);
    ws.setMinMaxUnitCount(5, IFaction::s_MaxUnitSize);

    ws.addWeapon(WarScroll::Weapon("Pendant Lance and Blade",
      2, 1, 3, 4, 0, 1));
    ws.addWeapon(WarScroll::Weapon("Charger's Hooves", 1, 2, 4, 4, 0, 1));

    ws.addAbility(WarScroll::Ability("Virtue of Knightly Temper", 1));
    ws.addAbility(WarScroll::Ability("Massed Cavalry", 1));                     // Conditional on Unit Size > 10
    ws.addAbility(WarScroll::Ability("Lances", 1));
    ws.addAbility(WarScroll::Ability("Heraldic Shields", 1));

    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Gallant",
      WarScroll::UnitUpgrade::UnitUpgradeType::eChampion, 1));
    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Banner Bearer",
      WarScroll::UnitUpgrade::UnitUpgradeType::eBannerBearer, 2));
    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Trumpeter",
      WarScroll::UnitUpgrade::UnitUpgradeType::eMusician, 2));

    ws.addKeyWords({"ORDER", "HUMAN", "FREE PEOPLE", "NOBILITY",
      "KNIGHTS OF THE REALM"});

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eOrder);
    return ws;
  }

  WarScroll Questing_Knights(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    ws.setCharacteristics(10, 2, 7, 4);
    ws.setMinMaxUnitCount(5, IFaction::s_MaxUnitSize);

    ws.addWeapon(WarScroll::Weapon("Knightly Greatblade", 1, 2, 3, 3, 1, 1));
    ws.addWeapon(WarScroll::Weapon("Charger's Hooves", 1, 2, 4, 4, 1, 1));

    ws.addAbility(WarScroll::Ability("The Questing Vow", 1));
    ws.addAbility(WarScroll::Ability("Heraldic Shields", 1));

    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Paragon",
      WarScroll::UnitUpgrade::UnitUpgradeType::eChampion, 1));
    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Banner Bearer",
      WarScroll::UnitUpgrade::UnitUpgradeType::eBannerBearer, 2));
    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Lutist",
      WarScroll::UnitUpgrade::UnitUpgradeType::eMusician, 2));

    ws.addKeyWords({"ORDER", "HUMAN", "FREE PEOPLE", "NOBILITY",
      "QUESTING KNIGHTS"});

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eOrder);
    return ws;
  }

  WarScroll Grail_Knights(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    ws.setCharacteristics(10, 2, 7, 4);
    ws.setMinMaxUnitCount(5, IFaction::s_MaxUnitSize);

    ws.addWeapon(WarScroll::Weapon("Sword and Sacred Lance", 1, 2, 3, 4, 1, 1));
    ws.addWeapon(WarScroll::Weapon("Destrier's Iron-shod Hooves",
      1, 2, 4, 4, 0, 1));

    ws.addAbility(WarScroll::Ability("Grail Shields", 1));
    ws.addAbility(WarScroll::Ability("Lances", 1));
    ws.addAbility(WarScroll::Ability("The Grail Vow", 1));

    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Grail Banner Bearer",
      WarScroll::UnitUpgrade::UnitUpgradeType::eBannerBearer, 2));
    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Trumpeter",
      WarScroll::UnitUpgrade::UnitUpgradeType::eMusician, 2));

    ws.addKeyWords({"ORDER", "HUMAN", "FREE PEOPLE", "NOBILITY",
      "GRAIL KNIGHTS"});

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eOrder);
    return ws;
  }

  WarScroll Pegasus_Knights(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    ws.setCharacteristics(16, 4, 6, 4);
    ws.setMinMaxUnitCount(3, IFaction::s_MaxUnitSize);
    ws.setCanFly(true);

    ws.addWeapon(WarScroll::Weapon("Lance and Blade", 2, 2, 3, 4, 0, 1));
    ws.addWeapon(WarScroll::Weapon("Pegasus' Hooves", 1, 2, 4, 4, 0, 1));

    ws.addAbility(WarScroll::Ability("Lances", 1));
    ws.addAbility(WarScroll::Ability("Heraldic Shields", 1));
    ws.addAbility(WarScroll::Ability("Swooping Charge", 1));

    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Gallant",
      WarScroll::UnitUpgrade::UnitUpgradeType::eChampion, 1));
    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Banner Bearer",
      WarScroll::UnitUpgrade::UnitUpgradeType::eBannerBearer, 2));
    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Trumpeter",
      WarScroll::UnitUpgrade::UnitUpgradeType::eMusician, 2));

    ws.addKeyWords({"ORDER", "HUMAN", "FREE PEOPLE", "NOBILITY",
      "PEGASUS KNIGHTS"});

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eOrder);
    return ws;
  }

  WarScroll Battle_Pilgrims(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    ws.setCharacteristics(5, 1, 6, 5);
    ws.setMinMaxUnitCount(6, IFaction::s_MaxUnitSize);

    ws.addWeapon(WarScroll::Weapon("Reliquary Sword", 1, 1, 5, 4, 0, 1));

    WarScroll::UnitUpgrade grailReliquaeUpgrade("Grail Reliquae",
      WarScroll::UnitUpgrade::UnitUpgradeType::eOther, 3);
    grailReliquaeUpgrade.addAbility(WarScroll::Ability("Inspired Fervour", 2));
    grailReliquaeUpgrade.addAbility(WarScroll::Ability("Pilgrim Shields", 2));
    ws.registerUnitUpgrade(grailReliquaeUpgrade);

    ws.addKeyWords({"ORDER", "HUMAN", "FREE PEOPLE", "PEASANTRY",
      "BATTLE PILGRIMS"});

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eOrder);
    return ws;
  }

  WarScroll Men_at_Arms(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    ws.setCharacteristics(5, 1, 4, 6);
    ws.setMinMaxUnitCount(10, IFaction::s_MaxUnitSize);

    ws.addWeapon(WarScroll::Weapon("Polearm", 2, 1, 5, 4, 0, 1));

    ws.addAbility(WarScroll::Ability("Rowdy Mob", 1));                          // Conditional on Unit Size > 10
    ws.addAbility(WarScroll::Ability("Tower Shields", 1));
    ws.addAbility(WarScroll::Ability("Virtue of Empathy, 1"));

    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Warden",
      WarScroll::UnitUpgrade::UnitUpgradeType::eChampion, 1));
    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Drummer",
      WarScroll::UnitUpgrade::UnitUpgradeType::eMusician, 2));
    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Trumpeter",
      WarScroll::UnitUpgrade::UnitUpgradeType::eMusician, 2));
    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Standard Bearer",
      WarScroll::UnitUpgrade::UnitUpgradeType::eBannerBearer, 2));
    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Relic Bearer",
      WarScroll::UnitUpgrade::UnitUpgradeType::eBannerBearer, 2));

    ws.addKeyWords({"ORDER", "HUMAN", "FREE PEOPLE", "PEASANTRY",
      "MEN-AT-ARMS"});

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eOrder);
    return ws;
  }

  WarScroll Peasant_Bowmen(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    ws.setCharacteristics(5, 1, 4, 6);
    ws.setMinMaxUnitCount(10, IFaction::s_MaxUnitSize);

    ws.addWeapon(WarScroll::Weapon("Longbow", 20, 1, 5, 4, 0, 1));
    ws.addWeapon(WarScroll::Weapon("Skinning Knife", 1, 1, 5, 5, 0, 1));

    ws.addAbility(WarScroll::Ability("Arrowstorm", 2));                         // Conditional on Unit Size > 20
    ws.addAbility(WarScroll::Ability("Virtue of Empathy", 1));

    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Villein",
      WarScroll::UnitUpgrade::UnitUpgradeType::eChampion, 1));
    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Drummer",
      WarScroll::UnitUpgrade::UnitUpgradeType::eMusician, 2));
    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Trumpeter",
      WarScroll::UnitUpgrade::UnitUpgradeType::eMusician, 2));
    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Standard Bearer",
      WarScroll::UnitUpgrade::UnitUpgradeType::eBannerBearer, 2));
    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Relic Bearer",
      WarScroll::UnitUpgrade::UnitUpgradeType::eBannerBearer, 2));

    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Stakes",
      WarScroll::UnitUpgrade::UnitUpgradeType::eOther, 1));
    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Burning Braziers",
      WarScroll::UnitUpgrade::UnitUpgradeType::eOther, 1));

    ws.addKeyWords({"ORDER", "HUMAN", "FREE PEOPLE", "PEASANTRY",
      "PEASANT BOWMEN"});

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eOrder);
    return ws;
  }

  WarScroll Mounted_Yeomen(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    ws.setCharacteristics(12, 2, 4, 6);
    ws.setMinMaxUnitCount(1, IFaction::s_MaxUnitSize);

    ws.addWeapon(WarScroll::Weapon("Yeoman's Bow", 18, 1, 4, 4, 0, 1));
    ws.addWeapon(WarScroll::Weapon("Hunting Spear", 2, 1, 4, 4, 0, 1));
    ws.addWeapon(WarScroll::Weapon("Palfrey's Sharp Teeth", 1, 2, 4, 5, 0, 1));

    ws.addAbility(WarScroll::Ability("Scouts", 2));
    ws.addAbility(WarScroll::Ability("Virtue of Empathy", 1));

    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Warden",
      WarScroll::UnitUpgrade::UnitUpgradeType::eChampion, 1));
    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Trumpeter",
      WarScroll::UnitUpgrade::UnitUpgradeType::eMusician, 2));
    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Standard Bearer",
      WarScroll::UnitUpgrade::UnitUpgradeType::eBannerBearer, 2));

    ws.registerUnitUpgrade(WarScroll::UnitUpgrade("Wooden Shields",
      WarScroll::UnitUpgrade::UnitUpgradeType::eShield, 1));

    ws.addKeyWords({"ORDER", "HUMAN", "FREE PEOPLE", "PEASANTRY",
      "MOUNTED YEOMEN"});

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eOrder);
    return ws;
  }

  WarScroll Field_Trebuchet(const std::string &name)
  {
    WarScroll ws;
    ws.setTitle(name);
    ws.setCharacteristics(4, 5, 10, 4);

    ws.addWeapon(WarScroll::Weapon("Rocks and Masonry", 48, 2, 4, 3, 2, 6));
    ws.addWeapon(WarScroll::Weapon("Crew's Tools", 1, 5, 5, 5, 0, 1));

    ws.addAbility(WarScroll::Ability("Siege Artillery", 1));
    ws.addAbility(WarScroll::Ability("Virtue of Courage", 1));
    ws.addAbility(WarScroll::Ability("Hard to Miss", 3));
    ws.addAbility(WarScroll::Ability("Arcing Shot", 3));

    ws.addKeyWords({"ORDER", "WARMACHINE", "FIELD TREBUCHET", "FREE PEOPLE",
      "PEASANTRY", "CREW"});

    ws.setGrandAllianceType(WarScroll::GrandAllianceType::eOrder);
    return ws;
  }
}

BretonniaFaction::BretonniaFaction() :
  IFaction()
{
  m_Units.push_back("");
  m_Units.push_back("King Louen Leoncoeur");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::King_Louen_Leoncoeur, m_Units.back())));
  m_Units.push_back("The Fay Enchantress");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::The_Fay_Enchantress, m_Units.back())));
  m_Units.push_back("The Green Knight");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::The_Green_Knight, m_Units.back())));
  m_Units.push_back("Bretonnian Lord");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Bretonnian_Lord, m_Units.back())));
  m_Units.push_back("Paladin");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Paladin, m_Units.back())));
  m_Units.push_back("Paladin Standard Bearer");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Paladin_Standard_Bearer, m_Units.back())));
  m_Units.push_back("Damsel of the Lady");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Damsel_of_the_Lady, m_Units.back())));
  m_Units.push_back("Knights Errant");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Knights_Errant, m_Units.back())));
  m_Units.push_back("Knights of the Realm");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Knights_of_the_Realm, m_Units.back())));
  m_Units.push_back("Questing Knights");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Questing_Knights, m_Units.back())));
  m_Units.push_back("Grail Knights");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Grail_Knights, m_Units.back())));
  m_Units.push_back("Pegasus Knights");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Pegasus_Knights, m_Units.back())));
  m_Units.push_back("Battle Pilgrims");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Battle_Pilgrims, m_Units.back())));
  m_Units.push_back("Men-at-Arms");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Men_at_Arms, m_Units.back())));
  m_Units.push_back("Peasant Bowmen");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Peasant_Bowmen, m_Units.back())));
  m_Units.push_back("Mounted Yeomen");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Mounted_Yeomen, m_Units.back())));
  m_Units.push_back("Field Trebuchet");
  m_NameToWarScroll.insert(std::make_pair(m_Units.back(),
    std::bind(&WarScrollGeneration::Field_Trebuchet, m_Units.back())));
}

const std::vector<std::string> &BretonniaFaction::getUnits() const
{
  return m_Units;
}

void BretonniaFaction::getWarScrolls(std::list<WarScroll>& warScrolls)
{
  for (const std::string &unit : m_Units) {
    if (unit.empty()) {
      continue;
    }
    WarScroll ws = m_NameToWarScroll[unit](unit);
    warScrolls.push_back(ws);
  }
}
