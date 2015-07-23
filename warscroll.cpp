#include "warscroll.h"

WarScroll::WarScroll()
  : m_IsValid(false)
  , m_ContainsDamageTable(false)
  , m_IsWarMachine(false)
{}

int WarScroll::getCharacteristic(const QString &characteristic) const
{
  QMap<QString, int>::const_iterator it =
    m_Characteristics.find(characteristic);
  if (it != m_Characteristics.constEnd()) {
    return *it;
  }
  return -1;
}

void WarScroll::incrementCharacteristic(const QString &characteristic)
{
  ++m_Characteristics[characteristic];
}

void WarScroll::decrementCharacteristic(const QString &characteristic)
{
  --m_Characteristics[characteristic];
}

void WarScroll::addKeyWord(const QString &keyWord)
{
  m_Keywords.insert(keyWord);
}

bool WarScroll::keyWordExists(const QString &keyWord)
{
  QSet<QString>::const_iterator it = m_Keywords.find(keyWord);
  return (it == m_Keywords.constEnd());
}

