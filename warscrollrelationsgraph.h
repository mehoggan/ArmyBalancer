#ifndef WARSCROLLRELATIONSGRAPH_H
#define WARSCROLLRELATIONSGRAPH_H

#include <QObject>
#include <QtGui/QOpenGLFunctions>

#include "rootview.h"
#include "warscrollsynergygraph.h"

#include "bounds/axis_aligned_2d.h"
#include "core/platform.h"
#include "geometries/geometry.h"
#include "geometries/ellipse.h"
#include "geometries/rectangulartext.h"
#include "geometries/splines.h"
#include "nametextureatlasmap.h"
#include "primitives/points/type_point_3d.h"

#include <QQuickView>
#include <QTimer>

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
  opengl_math::axis_aligned_2d<float> m_viewport;

  std::mutex m_graphMutex;
  WarScrollSynergyGraph *m_graph;

  std::vector<std::shared_ptr<Protection::Ellipse>> m_ellipses;
  std::vector<Protection::Ellipse> m_currEllipses;
  std::vector<WarScrollSynergyGraph::Vertex> m_vertices;
  std::vector<std::shared_ptr<Spline>> m_currSplines;
  std::vector<std::shared_ptr<RectangularText>> m_currEdgeLabels;

  opengl_math::matrix_4X4<float, opengl_math::column> m_projection;
  opengl_math::matrix_4X4<float, opengl_math::column> m_view;

  opengl_math::vector_3d<float> m_pickVector;

  std::atomic<qreal> m_z;
  std::atomic<Zoom> m_zoom;
  std::atomic<qreal> m_y;
  std::atomic<qreal> m_x;
  std::atomic_bool m_scrollChanged;
  std::atomic<int> m_currScrollIndex;
  std::atomic<int> m_prevScrollIndex;
  std::atomic<Protection::Ellipse*> m_doubleClickedEllipse;
  QTimer m_doubleClickedTimer;

  NameTextureAtlasMap m_atlasNameMap;
  NameTextureAtlasMap m_atlasKeywordMap;

private:
  void renderBackground();
  void renderGraph();
  void creatStaticData();
  void initGraphData();
  void updateGraph();
  bool ellipseOutsideFrustum() const;

public:
  WarScrollRelationsGraph();
  ~WarScrollRelationsGraph();

  void setViewport(const QPointF &lowerLeft, const QSize &size);
  void setGraph(WarScrollSynergyGraph *graph);
  void warScrollSelected(int index);
  void resetIndices();

public slots:
  void paint();
  void drawChanged(bool);
  void zChanged(qreal);
  void focalPointChanged(const QVector2D &);
  void doubleClickChanged(const QVector2D &);
};

#endif // WARSCROLLRELATIONSGRAPH_H
