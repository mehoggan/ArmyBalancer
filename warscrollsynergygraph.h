#ifndef WARSCROLLSYNERGYGRAPH_H
#define WARSCROLLSYNERGYGRAPH_H

#include <vector>

#include "warscroll.h"

class WarScrollSynergyGraph
{
private:
  struct Vertex;

  struct Edge
  {
    const Vertex *m_Node;
    const WarScroll::KeyWordConnection * const m_Meta;

    Edge() :
      m_Node(nullptr),
      m_Meta(nullptr)
    {}

    Edge(const Vertex &v, const WarScroll::KeyWordConnection &d) :
      m_Node(&v),
      m_Meta(&d)
    {}
  };

  struct Vertex
  {
    const WarScroll *m_Data;
    mutable std::vector<Edge> m_Adjacents;

    friend bool operator<(const Vertex &lhs, const Vertex &rhs)
    {
      return lhs.m_Data->getGuid() < rhs.m_Data->getGuid();
    }

    friend bool operator==(const Vertex &lhs, const Vertex &rhs)
    {
      return lhs.m_Data->getGuid() == rhs.m_Data->getGuid();
    }

    Vertex() :
      m_Data(nullptr)
    {}

    explicit Vertex(const WarScroll &d) :
      m_Data(&d)
    {}

    Vertex(const Vertex &other) :
      m_Data(other.m_Data),
      m_Adjacents(other.m_Adjacents)
    {}

    Vertex &operator=(Vertex rhs)
    {
      std::swap(m_Data, rhs.m_Data);
      std::swap(m_Adjacents, rhs.m_Adjacents);

      return (*this);
    }

    void connect(const Vertex &other,
      const WarScroll::KeyWordConnection &d) const;
  };

private:
  mutable std::set<Vertex> m_Vertices;

public:
  WarScrollSynergyGraph();

  void clear();

  void connect(const WarScroll &from, const WarScroll &to,
    const WarScroll::KeyWordConnection &connection) const;

  void print();
};

#endif // WARSCROLLSYNERGYGRAPH_H
