#ifndef WARSCROLLRELATIONSGRAPH_H
#define WARSCROLLRELATIONSGRAPH_H

#include <QObject>
#include <QtGui/QOpenGLFunctions>

#include "rootview.h"
#include "warscrollsynergygraph.h"

#include "core/platform.h"
#include "geometries/geometry.h"
#include "geometries/ellipse.h"
#include "geometries/splines.h"
#include "primitives/points/type_point_3d.h"

#include <QQuickView>

#include <atomic>
#include <memory>
#include <mutex>
#include <vector>

class WarScrollRelationsGraph :
  public QObject, public QOpenGLFunctions
{
  Q_OBJECT

private:
  enum class Zoom
  {
    In,
    Out,
    None
  };

private:
  const QObject *m_parent;
  std::atomic_bool m_draw;
  std::atomic_bool m_create;
  std::atomic_bool m_initialize;
  QSize m_viewportSize;

  std::mutex m_graphMutex;
  WarScrollSynergyGraph *m_graph;

  std::vector<std::shared_ptr<Ellipse>> m_ellipses;
  std::vector<Ellipse> m_currEllipses;
  std::vector<WarScrollSynergyGraph::Vertex> m_vertices;
  std::vector<std::shared_ptr<Spline>> m_currSplines;

  opengl_math::matrix_4X4<float, opengl_math::column> m_projection;
  opengl_math::matrix_4X4<float, opengl_math::column> m_view;

  std::atomic<qreal> m_z;
  std::atomic<Zoom> m_zoom;
  std::atomic<qreal> m_y;
  std::atomic<qreal> m_x;
  std::atomic_bool m_scrollChanged;
  std::atomic<int> m_currScrollIndex;
  std::atomic<int> m_prevScrollIndex;

private:
  void renderBackground();
  void renderGraph();
  void creatStaticData();
  void initGraphData();
  void updateGraph();

public:
  WarScrollRelationsGraph();
  ~WarScrollRelationsGraph();

  void setViewportSize(const QSize &size);
  void setGraph(WarScrollSynergyGraph *graph);
  void warScrollSelected(int index);

public slots:
  void paint();
  void drawChanged(bool);
  void zChanged(qreal);
  void focalPointChanged(const QVector2D &);
};

#endif // WARSCROLLRELATIONSGRAPH_H
