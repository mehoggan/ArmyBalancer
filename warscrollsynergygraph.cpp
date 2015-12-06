#include "warscrollsynergygraph.h"

#include <iostream>

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
  bool contains = false;
  for (const Edge &edge : m_adjacents) {
    if ((*edge.m_meta) == d && (*edge.m_node) == other) {
      contains = true;
    }
  }

  if (!contains) {
    Edge edge(other, d);
    m_adjacents.push_back(edge);
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
      if (!edge.m_meta->getAbility().getName().empty()) {
        std::cout << edge.m_meta->getAbility().getName();
      } else if (!edge.m_meta->getSpell().getName().empty()) {
        std::cout << edge.m_meta->getSpell().getName();
      } else {
        std::cout << edge.m_meta->getName();
      }
      std::cout << ") ==>";
    }
    std::cout << std::endl;
  }
}
