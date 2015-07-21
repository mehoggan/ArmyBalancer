#ifndef WARSCROLLFACTORY_H
#define WARSCROLLFACTORY_H

#include <QMap>
#include <QPair>
#include <QSet>
#include <QString>

#include <memory>

class WarScrollFactory;

class WarScroll
{
private:
  friend class WarScroll;
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

class WarScrollFactory
{
public:
  static WarScrollFactory& getSharedInstance();
  WarScroll getWarScroll(const QString &factionName, const QString &unitName);

private:
  WarScrollFactory();
  WarScrollFactory &operator=(const WarScrollFactory &other) = delete;
  WarScrollFactory(const WarScrollFactory &other) = delete;
  WarScrollFactory(WarScrollFactory &&other) = delete;

private:
  typedef QMap<QString, std::shared_ptr<WarScroll>> WarScrollDictionaryType;
  typedef QMap<QString, WarScrollDictionaryType> FactionWarScrollDictionaryType;
  FactionWarScrollDictionaryType m_WarScrolls;
};

#endif // WARSCROLLFACTORY_H
