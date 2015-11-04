#ifndef WARSCROLLSYNERGYGRAPH_H
#define WARSCROLLSYNERGYGRAPH_H

#include <vector>

#include "warscroll.h"

class WarScrollSynergyGraph
{
public:
  struct Vertex;

  struct Edge
  {
  private:
    friend class WarScrollSynergyGraph;
    const Vertex *m_Node;
    const WarScroll::KeyWordConnection * const m_Meta;

  public:
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
  private:
    friend class WarScrollSynergyGraph;
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

  public:
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

    const WarScroll *getWarScroll() const {return m_Data;}

    void connect(const Vertex &other,
      const WarScroll::KeyWordConnection &d) const;
  };

public:
  WarScrollSynergyGraph();

  void clear();

  void connect(const WarScroll &from, const WarScroll &to,
    const WarScroll::KeyWordConnection &connection) const;

  std::set<Vertex>::iterator begin() {return m_Vertices.begin();}
  std::set<Vertex>::iterator end() {return m_Vertices.end();}

  void print();

private:
  mutable std::set<Vertex> m_Vertices;
};

#endif // WARSCROLLSYNERGYGRAPH_H
