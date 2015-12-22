﻿#ifndef GRAPHVISUALIZER_H
#define GRAPHVISUALIZER_H

#include "geometries/ellipse.h"
#include "geometries/splines.h"
#include "nametextureatlasmap.h"
#include "warscrollsynergygraph.h"

#include "matrices/type_matrix_4X4.h"

#include <memory>

std::vector<std::string> extractNamesFromGraph(WarScrollSynergyGraph *graph);

void generateEllipses(
  std::vector<std::shared_ptr<Protection::Ellipse>> &output1,
  std::vector<WarScrollSynergyGraph::Vertex> &output2,
  WarScrollSynergyGraph *graph, NameTextureAtlasMap *nameAtlas);

void generateSplines(
  std::vector<std::shared_ptr<Spline>> &output1,
  const std::vector<Protection::Ellipse> &ellipses);

#endif // GRAPHVISUALIZER_H
