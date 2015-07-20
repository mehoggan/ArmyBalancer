#include "theempirearmy.h"

TheEmpireArmy::TheEmpireArmy() :
  IArmy(nullptr)

{
  m_Units.push_back(tr("Karl Fravz on Deathclaw"));
  m_Units.push_back(tr("Kurt Helborg"));
  m_Units.push_back(tr("Balthasar Gelt, the Supreme Patriarch"));
  m_Units.push_back(tr("Valten"));
  m_Units.push_back(tr("Marius Leitdorf"));
  m_Units.push_back(tr("Empire General"));
  m_Units.push_back(tr("General of the Empire on Imperial Griffon"));
  m_Units.push_back(tr("Ludwig Schwarzhelm"));
  m_Units.push_back(tr("Markus Wulfhart"));
  m_Units.push_back(tr("Grand Master"));
  m_Units.push_back(tr("Demigryph Knights"));
  m_Units.push_back(tr("Empire Knights"));
  m_Units.push_back(tr("Reiksguard Knights"));
  m_Units.push_back(tr("Empire Crossbowmen"));
  m_Units.push_back(tr("Empire Handgunners"));
  m_Units.push_back(tr("Empire Archers"));
  m_Units.push_back(tr("Empire Greatswords"));
  m_Units.push_back(tr("Empire Pistoliers"));
  m_Units.push_back(tr("Empire Outriders"));
  m_Units.push_back(tr("Empire State Troops"));
  m_Units.push_back(tr("Empire Free Company Militia"));
  m_Units.push_back(tr("Empire Master Engineer"));
  m_Units.push_back(tr("Master Engineer on Mechanical Steed"));
  m_Units.push_back(tr("Empire Cannon"));
  m_Units.push_back(tr("Empire Mortor"));
  m_Units.push_back(tr("Hellblaster Volley Gun"));
  m_Units.push_back(tr("Hellstorm Rocket Battery"));
  m_Units.push_back(tr("Empire Steam Tank"));
  m_Units.push_back(tr("Volkmar the Grim"));
  m_Units.push_back(tr("The War Alter of Sigmar"));
  m_Units.push_back(tr("Luthor Huss, Prophet of Sigmar"));
  m_Units.push_back(tr("Warrior Priest"));
  m_Units.push_back(tr("Witch Hunter"));
  m_Units.push_back(tr("Empire Flagellants Warband"));
  m_Units.push_back(tr("Celestial Hurricanum"));
  m_Units.push_back(tr("Empire Battle Wizard"));
  m_Units.push_back(tr("Amber Battle Wizard on Imperial Griffon"));
  m_Units.push_back(tr("Luminark of Hysh"));
}

const QStringList &TheEmpireArmy::getUnits()
{
  return m_Units;
}

void TheEmpireArmy::buildUiForBattleScroll(QQuickView *ui, int scrollIndex)
{

}
