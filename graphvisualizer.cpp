#include "graphvisualizer.h"

#include "math/matrix.h"
#include "primitives/points/type_point_3d.h"
#include "primitives/vectors/type_vector_3d.h"

#include <algorithm>
#include <iostream>
#include <iterator>

#include <QDebug>
#include <QDebug>
#include <QFont>
#include <QFontMetricsF>
#include <QGLWidget>
#include <QPainter>
#include <QString>

void walkGraph(
  std::vector<std::shared_ptr<Protection::Ellipse>> &output1,
  std::vector<WarScrollSynergyGraph::Vertex> &output2,
  WarScrollSynergyGraph &graph, NameTextureAtlasMap *nameAtlas)
{
  std::copy(graph.begin(), graph.end(), std::back_inserter(output2));

  std::sort(output2.begin(), output2.end(),
    [&](const WarScrollSynergyGraph::Vertex &lhs,
      const WarScrollSynergyGraph::Vertex &rhs) {
      return lhs.connections() > rhs.connections();
    });

  std::for_each(output2.begin(), output2.end(),
    [&](const WarScrollSynergyGraph::Vertex& node)
    {
      auto ellipse = std::make_shared<Protection::Ellipse>();
      output1.push_back(ellipse);
      std::string wsName = node.getWarScroll()->getTitle().c_str();
      output1.back()->setName(wsName.c_str());
      output1.back()->setWarScroll(*(node.getWarScroll()));
      auto uvBbox = nameAtlas->getUVForName(wsName);
      Q_ASSERT(uvBbox.is_valid());
      output1.back()->create_bbox(&uvBbox);
      output1.back()->setTextureAtlas(*nameAtlas);
    });
}

std::vector<std::string> extractNamesFromGraph(WarScrollSynergyGraph *graph)
{
  std::vector<std::string> names;
  std::vector<WarScrollSynergyGraph::Vertex> vertices;
  std::copy(graph->begin(), graph->end(), std::back_inserter(vertices));
  std::sort(vertices.begin(), vertices.end(),
    [&](const WarScrollSynergyGraph::Vertex &lhs,
      const WarScrollSynergyGraph::Vertex &rhs) {
      return lhs.connections() > rhs.connections();
    });
  std::for_each(vertices.begin(), vertices.end(),
    [&](const WarScrollSynergyGraph::Vertex& node)
    {
      names.push_back(node.getWarScroll()->getTitle());
    });
  return names;
}

void generateEllipses(
  std::vector<std::shared_ptr<Protection::Ellipse>>& output1,
  std::vector<WarScrollSynergyGraph::Vertex>& output2,
  WarScrollSynergyGraph *graph, NameTextureAtlasMap *nameAtlas)
{
  if (!graph) {
    return;
  }

  std::vector<std::shared_ptr<Protection::Ellipse>> ellipses;
  std::vector<WarScrollSynergyGraph::Vertex> nodes;
  walkGraph(output1, output2, *graph, nameAtlas);
  assert(ellipses.size() == nodes.size());
}

void generateSplines(std::vector<std::shared_ptr<Spline>> &output1,
  const std::vector<Protection::Ellipse> &ellipses)
{
  // We assume that the center ellipse is the first ellipse in the vector
  opengl_math::point_3d<float> center = ellipses.front().getCenter();

  for (auto it = ellipses.begin() + 1; it != ellipses.end(); ++it) {
    opengl_math::point_3d<float> ccenter = it->getCenter();
    const std::string currName = it->getName();
    opengl_math::point_3d<float> mid = opengl_math::lerp<float>(0.5f,
      center, ccenter);
    output1.push_back(Spline::createBezier(center, mid, mid, ccenter));
    output1.back()->create();
  }
}
