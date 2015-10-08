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
  for (const Edge &edge : m_Adjacents) {
    if ((*edge.m_Meta) == d && (*edge.m_Node) == other) {
      contains = true;
    }
  }

  if (!contains) {
    Edge edge(other, d);
    m_Adjacents.push_back(edge);
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

void WarScrollSynergyGraph::print()
{
  for (auto it = m_Vertices.begin(); it != m_Vertices.end(); ++it) {
    std::cout << it->m_Data->getTitle() << "==>";
    for (const auto &edge : it->m_Adjacents) {
      std::cout << edge.m_Node->m_Data->getTitle() << "(";
      if (!edge.m_Meta->getAbility().getName().empty()) {
        std::cout << edge.m_Meta->getAbility().getName();
      } else if (!edge.m_Meta->getSpell().getName().empty()) {
        std::cout << edge.m_Meta->getSpell().getName();
      } else {
        std::cout << edge.m_Meta->getName();
      }
      std::cout << ") ==>";
    }
    std::cout << std::endl;
  }
}
