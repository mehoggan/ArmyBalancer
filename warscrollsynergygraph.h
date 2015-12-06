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
    const Vertex *m_node;
    const WarScroll::KeyWordConnection * const m_meta;

  public:
    Edge() :
      m_node(nullptr),
      m_meta(nullptr)
    {}

    Edge(const Vertex &v, const WarScroll::KeyWordConnection &d) :
      m_node(&v),
      m_meta(&d)
    {}

    const Vertex &adjacent() const {return (*m_node);}
  };

  struct Vertex
  {
  private:
    friend class WarScrollSynergyGraph;
    const WarScroll *m_data;
    mutable std::vector<Edge> m_adjacents;
    bool m_visited;

  public:
    Vertex()
      : m_data(nullptr)
      , m_visited(false)
    {}

    explicit Vertex(const WarScroll &d)
      : m_data(&d)
      , m_visited(false)
    {}

    Vertex(const Vertex &other)
      : m_data(other.m_data)
      , m_adjacents(other.m_adjacents)
      , m_visited(other.m_visited)
    {}

    Vertex &operator=(Vertex rhs)
    {
      std::swap(m_data, rhs.m_data);
      std::swap(m_adjacents, rhs.m_adjacents);
      std::swap(m_visited, rhs.m_visited);

      return (*this);
    }

    const WarScroll *getWarScroll() const {return m_data;}

    bool visited() const {return m_visited;}
    void visited(bool visited) {m_visited = visited;}

    std::size_t connections() const {return m_adjacents.size();}

    void connect(const Vertex &other,
      const WarScroll::KeyWordConnection &d) const;

    const std::vector<Edge> &adjacents() const {return m_adjacents;}

    friend bool operator<(const Vertex &lhs, const Vertex &rhs)
    {
      return lhs.m_data->getGuid() < rhs.m_data->getGuid();
    }

    friend bool operator==(const Vertex &lhs, const Vertex &rhs)
    {
      return lhs.m_data->getGuid() == rhs.m_data->getGuid();
    }

    friend std::ostream &operator<<(std::ostream &out, Vertex vert)
    {
      out << (vert.m_data->getTitle()) <<  " " <<
        vert.m_data->getGuid().toString().toStdString() << " (" <<
        vert.connections() << ")" << std::endl;
      return out;
    }
  };

public:
  WarScrollSynergyGraph();

  void clear();

  void connect(const WarScroll &from, const WarScroll &to,
    const WarScroll::KeyWordConnection &connection) const;
  void connect(const WarScroll &loner, void *) const;

  std::set<Vertex>::iterator begin() {return m_Vertices.begin();}
  std::set<Vertex>::iterator end() {return m_Vertices.end();}

  void print();

private:
  mutable std::set<Vertex> m_Vertices;
};

#endif // WARSCROLLSYNERGYGRAPH_H
