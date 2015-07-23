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
  QSet<QString> m_Keywords;
  QMap<QString, QMap<QString, int>> m_Weapons;
  QMap<QString, int> m_Upgrades;
  QMap<QString, int> m_Spells;
  QMap<QString, int> m_CommandAbility;

  bool m_ContainsDamageTable;
  bool m_IsWarMachine;

public:
  WarScroll();

  bool isValid() const {return m_IsValid;}

  const QString& getTitle() const {return m_Title;}
  void setTitle(const QString& title) {m_Title = title;}

  int getCharacteristic(const QString &characteristic) const;
  void incrementCharacteristic(const QString &characteristic);
  void decrementCharacteristic(const QString &characteristic);

  void addKeyWord(const QString &keyWord);
  bool keyWordExists(const QString &keyWord);
};

#endif // WARSCROLL_H
