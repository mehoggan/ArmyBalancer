#include "warscrollsynergygraph.h"

#include <algorithm>
#include <iostream>
#include <string>

void WarScrollSynergyGraph::Edge::addKeyWord(
  const WarScroll::KeyWordConnection &connection)
{
  if (std::find(m_connections.begin(), m_connections.end(), connection) ==
    m_connections.end()) {
      m_connections.push_back(connection);
  }
}

WarScrollSynergyGraph::WarScrollSynergyGraph()
{
}

void WarScrollSynergyGraph::clear()
{
  m_Vertices.clear();
}

void WarScrollSynergyGraph::Vertex::connect(const Vertex &other,
  const WarScroll::KeyWordConnection &d) const
{
  const Edge *found = nullptr;

  for (const Edge &edge : m_adjacents) {
    if (*edge.m_node == other) {
        found = &edge;
    }
  }

  if (!found) {
    Edge edge(other, d);
    m_adjacents.push_back(edge);
  } else {
    const auto &connections = found->m_connections;
    if (std::find(connections.cbegin(), connections.cend(), d) ==
      connections.cend()) {
      const_cast<Edge *>(found)->addKeyWord(d);
    }
  }
}

void WarScrollSynergyGraph::connect(const WarScroll &from, const WarScroll &to,
  const WarScroll::KeyWordConnection &connection) const
{
  Vertex vfrom(from);
  Vertex vto(to);

  std::set<Vertex>::const_iterator fit =
    std::find(m_Vertices.begin(), m_Vertices.end(), vfrom);
  std::set<Vertex>::const_iterator tit =
    std::find(m_Vertices.begin(), m_Vertices.end(), vto);

  if (fit == m_Vertices.end()) {
    auto tmp = m_Vertices.insert(vfrom);
    fit = tmp.first;
  }

  if (tit == m_Vertices.end()) {
    auto tmp = m_Vertices.insert(vto);
    tit = tmp.first;
  }

  fit->connect(const_cast<Vertex &>(*tit),
    const_cast<WarScroll::KeyWordConnection &>(connection));
}

void WarScrollSynergyGraph::connect(const WarScroll &loner, void *) const
{
  Vertex lonerV(loner);
  m_Vertices.insert(lonerV);
}

void WarScrollSynergyGraph::print()
{
  for (auto it = m_Vertices.begin(); it != m_Vertices.end(); ++it) {
    std::cout << it->m_data->getTitle() << "==>";
    for (const auto &edge : it->m_adjacents) {
      std::cout << edge.m_node->m_data->getTitle() << "(";
      for (auto connection : edge.m_connections) {
        if (!connection.getAbility().getName().empty()) {
          std::cout << connection.getAbility().getName();
        } else if (!connection.getSpell().getName().empty()) {
          std::cout << connection.getSpell().getName();
        } else {
          std::cout << connection.getName();
        }
        std::cout << ") ==>";
      }
    }
    std::cout << std::endl;
  }
}
