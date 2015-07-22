#ifndef WARSCROLL_H
#define WARSCROLL_H

#include <QQuickItem>

class WarScrollFactory;

class WarScroll
{
private:
  friend class WarScrollFactory;
  bool m_IsValid;

  QString m_Title;
  QMap<QString, int> m_Characteristics;
  QMap<QString, QMap<QString, int>> m_Weapons;
  QSet<QString> m_Keywords;
  QMap<QString, int> m_Upgrades;
  QMap<QString, int> m_Spells;
  QMap<QString, int> m_CommandAbility;

  bool m_ContainsDamageTable;
  bool m_IsWarMachine;

public:
  WarScroll();

  bool isValid() const {return m_IsValid;}
};

#endif // WARSCROLL_H
