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
  WarScrollSynergyGraph &graph)
{
  std::copy(graph.begin(), graph.end(), std::back_inserter(output2));

  std::sort(output2.begin(), output2.end(),
    [&](const WarScrollSynergyGraph::Vertex &lhs,
      const WarScrollSynergyGraph::Vertex &rhs) {
      return lhs.connections() > rhs.connections();
    });

  std::copy(output2.begin(), output2.end(),
    std::ostream_iterator<WarScrollSynergyGraph::Vertex>(std::cout, ""));

  std::for_each(output2.begin(), output2.end(),
    [&](const WarScrollSynergyGraph::Vertex& node)
    {
      std::shared_ptr<Protection::Ellipse> ellipse(new Protection::Ellipse());
      output1.push_back(ellipse);
      output1.back()->setName(node.getWarScroll()->getTitle().c_str());
      output1.back()->setWarScroll(*(node.getWarScroll()));
      QImage img(512, 512, QImage::Format_RGBA8888);
      img.fill(Qt::white);
      QPainter painter(&img);
      painter.setRenderHints(QPainter::Antialiasing |
        QPainter::TextAntialiasing | QPainter::SmoothPixmapTransform);

      QRectF rect(QPointF(0.0, 0.0), QSizeF(512.0, 512.0));
      QImage image(":/images/wasteland.png");
      painter.drawImage(rect, image, image.rect());

      QFont font = painter.font() ;
      font.setPointSize(36.0);
      font.setBold(true);
      while (QFontMetricsF(font).boundingRect(
        node.getWarScroll()->getTitle().c_str()).width() > 502.0) {
        font.setPointSize(font.pointSize() - 1.0);
      }
      painter.setFont(font);
      painter.setPen(Qt::red);
      auto flags = Qt::AlignHCenter | Qt::AlignVCenter;
      painter.drawText(rect, flags, node.getWarScroll()->getTitle().c_str(),
        nullptr);

      QImage tex = QGLWidget::convertToGLFormat(img);
      output1.back()->setNameTexture(tex);
      output1.back()->create();
    });
}

void generateEllipses(
  std::vector<std::shared_ptr<Protection::Ellipse>>& output1,
  std::vector<WarScrollSynergyGraph::Vertex>& output2,
  WarScrollSynergyGraph *graph)
{
  if (!graph) {
    return;
  }

  std::vector<std::shared_ptr<Protection::Ellipse>> ellipses;
  std::vector<WarScrollSynergyGraph::Vertex> nodes;
  walkGraph(output1, output2, *graph);
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
