#ifndef FACTIONBALANCER_H
#define FACTIONBALANCER_H

#include <QQuickItem>

#include <QMap>
#include <QQmlContext>
#include <QQuickView>
#include <QStringList>

#include <memory>

#include "factions.h"
#include "warscrollfactory.h"

class ArmyBalancer : public QQuickItem
{
  Q_OBJECT

  Q_PROPERTY(QStringList factionList READ getFactionList WRITE setFactionList
    NOTIFY factionListChanged)
  Q_PROPERTY(QStringList warScrolls READ getWarScrolls WRITE setWarScrolls
    NOTIFY warScrollsChanged)
  Q_PROPERTY(QString name READ getName WRITE setName)

public:
  explicit ArmyBalancer(QQuickItem *parent = 0);

  void setRootView(QQuickView *root);

  const QStringList &getFactionList() const {return m_FactionList;}
  void setFactionList(const QStringList &factionList);

  const QStringList &getWarScrolls() const {return m_CurrentWarScrolls;}
  void setWarScrolls(const QStringList &warScrolls);

  QString getName() const {return "armyBalancer";}
  void setName(const QString &) const {}

signals:
  void factionListChanged();
  void warScrollsChanged();

public slots:
  void factionSelectionChanged(int index);
  void warScrollSelectionChanged(int);

private:
  void getNextWarScrolls(QStringList &output, const QString &factionName);

private:
  QString m_Name;
  int m_CurrentFactionIndex;
  QQuickView *m_Root;
  QStringList m_FactionList;
  QStringList m_CurrentWarScrolls;

  typedef QMap<QString, std::shared_ptr<IFaction>> FactionMapType;
  FactionMapType m_NameToFactionMap;
  WarScrollFactory &m_WarScrollFactory;
};

#endif // FACTIONBALANCER_H
