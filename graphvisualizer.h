﻿#ifndef GRAPHVISUALIZER_H
#define GRAPHVISUALIZER_H

#include "geometries/ellipse.h"
#include "geometries/splines.h"
#include "warscrollsynergygraph.h"

#include "matrices/type_matrix_4X4.h"

void generateEllipses(
  std::vector<std::shared_ptr<Ellipse>> &output1,
  std::vector<WarScrollSynergyGraph::Vertex> &output2,
  WarScrollSynergyGraph *graph);

void generateSplines(
  std::vector<std::shared_ptr<Spline>> &output1,
  const std::vector<Ellipse> &ellipses);

#endif // GRAPHVISUALIZER_H
