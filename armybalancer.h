#ifndef FACTIONBALANCER_H
#define FACTIONBALANCER_H

#include <QQuickItem>

#include <QQmlContext>
#include <QQuickView>

#include <map>
#include <memory>
#include <string>
#include <vector>

#include "factions.h"
#include "warscrollsynergygraph.h"
#include "warscrollfactory.h"

class ArmyBalancer : public QQuickItem
{
  Q_OBJECT

  Q_PROPERTY(QStringList factionList READ getFactionList WRITE setFactionList
    NOTIFY factionListChanged)
  Q_PROPERTY(QStringList warScrolls READ getWarScrolls WRITE setWarScrolls
    NOTIFY warScrollsChanged)

public:
  explicit ArmyBalancer(QQuickItem *parent = 0);

  void setRootView(QQuickView *root);

  const QStringList &getFactionList() const;
  void setFactionList(const QStringList &factionList);

  const QStringList &getWarScrolls() const;
  void setWarScrolls(const QStringList &warScrolls);

signals:
  void factionListChanged();
  void warScrollsChanged();

public slots:
  void factionSelectionChanged(int index);
  void warScrollSelectionChanged(int index);
  void warScrollSeleted();
  void warScrollAccepted(QVariantMap data);
  void clearCurrentWarScroll();
  void clearCurrentWarScrolls();
  void removeCurrentWarScroll(QVariant guid);
  QVariant getCurrentScrollText(QVariant guid);
  Q_INVOKABLE void buildAndPublishSynergyGraph();
  Q_INVOKABLE bool hasWarScrolls() const
  {return m_CurrentWarScrollsAdded.size() > 0;}

private:
  int m_CurrentFactionIndex;
  int m_CurrentWarScrollIndex;
  QQuickView *m_Root;
  QStringList m_FactionList;
  QStringList m_CurrentWarScrolls;
  WarScrollSynergyGraph m_WarScrollSynergyGraph;

  typedef std::map<std::string, std::shared_ptr<IFaction>> FactionMapType;
  FactionMapType m_NameToFactionMap;
  WarScrollFactory &m_WarScrollFactory;
  WarScroll m_CurrentWarScroll;
  std::map<std::string, WarScroll> m_CurrentWarScrollsAdded;
  typedef std::map<std::string, WarScroll>::value_type WarScrollAddedType;

private:
  void getNextWarScrolls(std::vector<std::string> &output,
    const std::string &factionName);
  // The bool signifies if a connection was made
  bool buildGraphFromConnectionString(
    const WarScroll::KeyWordConnection &keyWordConnection,
    const WarScroll &from);

  template <typename Faction>
  void insertFaction()
  {
    std::pair<FactionMapType::const_iterator, bool> insert;

    insert = m_NameToFactionMap.insert(std::make_pair(
      Faction().getName(),
      std::make_shared<Faction>()));
    m_FactionList.push_back(insert.first->second->getName().c_str());
  }
};

#endif // FACTIONBALANCER_H
