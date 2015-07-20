#ifndef ARMYBALANCER_H
#define ARMYBALANCER_H

#include <QQuickItem>

#include <QMap>
#include <QQmlContext>
#include <QQuickView>
#include <QStringList>

#include <memory>

#include "armies.h"
#include "warscrollfactory.h"

class ArmyBalancer : public QQuickItem
{
  Q_OBJECT

  Q_PROPERTY(QStringList armyList READ getArmyList WRITE setArmyList
    NOTIFY armyListChanged)
  Q_PROPERTY(QStringList warScrolls READ getWarScrolls WRITE setWarScrolls
    NOTIFY warScrollsChanged)

public:
  explicit ArmyBalancer(QQuickItem *parent = 0);

  void setRootView(QQuickView *root);

  const QStringList &getArmyList() const {return m_ArmyList;}
  void setArmyList(const QStringList &armyList);

  const QStringList &getWarScrolls() const {return m_CurrentWarScrolls;}
  void setWarScrolls(const QStringList &warScrolls);

signals:
  void armyListChanged();
  void warScrollsChanged();

public slots:
  void armySelectionChanged(int index);
  void warScrollSelectionChanged(int);

private:
  void getNextWarScrolls(QStringList &output, const QString &armyName);

private:
  int m_CurrentArmyIndex;
  QQuickView *m_Root;
  QStringList m_ArmyList;
  QStringList m_CurrentWarScrolls;

  QMap<QString, std::shared_ptr<IArmy>> m_ArmyNameToArmyMap;
  WarScrollFactory &m_WarScrollFactory;
};

#endif // ARMYBALANCER_H
