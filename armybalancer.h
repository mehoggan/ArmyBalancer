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

private:
  void getNextWarScrolls(std::vector<std::string> &output,
    const std::string &factionName);

private:
  int m_CurrentFactionIndex;
  int m_CurrentWarScrollIndex;
  QQuickView *m_Root;
  QStringList m_FactionList;
  QStringList m_CurrentWarScrolls;

  typedef std::map<std::string, std::shared_ptr<IFaction>> FactionMapType;
  FactionMapType m_NameToFactionMap;
  WarScrollFactory &m_WarScrollFactory;
  WarScroll m_CurrentWarScroll;
  std::map<std::string, WarScroll> m_CurrentWarScrollsAdded;
};

#endif // FACTIONBALANCER_H
