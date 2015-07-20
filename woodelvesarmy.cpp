#include "woodelvesarmy.h"

WoodElvesArmy::WoodElvesArmy() :
  IArmy(nullptr)
{
  m_Units.push_back(tr("Araloth"));
  m_Units.push_back(tr("Glade Captain Battle Standard Bearer"));
  m_Units.push_back(tr("Glade Lord"));
  m_Units.push_back(tr("Glade Lord on Great Eagle"));
  m_Units.push_back(tr("Glade Lord on Great Stag"));
  m_Units.push_back(tr("Glade Lord on Forest Dragon"));
  m_Units.push_back(tr("Mounted Glade Lord"));
  m_Units.push_back(tr("Orion, King in the Woods"));
  m_Units.push_back(tr("Hunting Hounds"));
  m_Units.push_back(tr("Wild Riders"));
  m_Units.push_back(tr("The Sisters of Twilight on Forest Dragon"));
  m_Units.push_back(tr("Spellweaver"));
  m_Units.push_back(tr("Shadowdancer"));
  m_Units.push_back(tr("Wardancers"));
  m_Units.push_back(tr("Waywatcher Lord"));
  m_Units.push_back(tr("Waywatchrs"));
  m_Units.push_back(tr("Glade Guard"));
  m_Units.push_back(tr("Glade Riders"));
  m_Units.push_back(tr("Eternal Guard"));
  m_Units.push_back(tr("Wildwood Rangers"));
  m_Units.push_back(tr("Warhawk Riders"));
  m_Units.push_back(tr("Sisters of the Thorn"));
  m_Units.push_back(tr("Great Eagles"));
  m_Units.push_back(tr("Branchwraith"));
  m_Units.push_back(tr("Dryads"));
  m_Units.push_back(tr("Tree Kin"));
  m_Units.push_back(tr("Durthu"));
  m_Units.push_back(tr("Treeman"));
  m_Units.push_back(tr("Treeman Ancient"));
  m_Units.push_back(tr("Sylvaneth Wyldwood"));
}

const QStringList &WoodElvesArmy::getUnits()
{
  return m_Units;
}

void WoodElvesArmy::buildUiForBattleScroll(QQuickView *ui, int scrollIndex)
{

}
