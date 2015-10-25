#ifndef SPLINES_H
#define SPLINES_H

#include "geometries/geometry.h"

#include "glshaderresourcemanager.h"

#include "mesh_types/interleaved_data.h"
#include "mesh_types/datums/interleaved_datum_2d.h"
#include "curves/cubic_curve.h"
#include "curves/curve_sample_3d.h"
#include "primitives/colors/type_color_rgba.h"
#include "primitives/points/type_point_3d.h"
#include "primitives/vectors/type_vector_3d.h"

#include <memory>
#include <vector>

class Spline : public Geometry
{
public:
  Spline(const Spline &);
  Spline &operator=(const Spline &);
  ~Spline();

  virtual void setProjection(
    const opengl_math::matrix_4X4<float, opengl_math::column> &projection);
  virtual void create();
  virtual void draw();
  virtual void destroy();

  void setLineWidth(GLfloat lineWidth) {m_lineWidth = lineWidth;}
  GLfloat getLineWidth() const {return m_lineWidth;}
  void setPointSize(GLfloat pointSize) {m_pointSize = pointSize;}
  GLfloat getPointSize() const {return m_pointSize;}
  void setDisplayPoints(bool display) {m_displayPoints = display;}
  bool getDisplayPoints() const {return m_displayPoints;}
  void setDisplayTangents(bool display) {m_displayTangents = display;}
  bool getDisplayTangents() const {return m_displayTangents;}
  void setDisplayColor(opengl_math::color_rgba<float> color) {m_color = color;}
  opengl_math::color_rgba<float> getDisplayColor() const {return m_color;}

  static std::shared_ptr<Spline> createBezier(
    const opengl_math::point_3d<float> &p0,
    const opengl_math::point_3d<float> &p1,
    const opengl_math::point_3d<float> &p2,
    const opengl_math::point_3d<float> &p3);

  static std::shared_ptr<Spline> createHermite(
      const opengl_math::point_3d<float> &p0,
      const opengl_math::point_3d<float> &p1,
      const opengl_math::vector_3d<float> &t0,
      const opengl_math::vector_3d<float> &t1);

private:
  Spline();

  GLShaderResourceManager::GLShaderHandle m_handle;
  std::vector<GLShaderResourceManager::GLShaderAttributes> m_shaderVertexAttrib;
  std::shared_ptr<GLShaderResourceManager> m_shaderManager;

  GLuint m_vbo;
  GLfloat m_lineWidth;
  GLfloat m_pointSize;
  bool m_displayPoints;
  bool m_displayTangents;

  typedef opengl_graphics::interleaved_data<opengl_math::point_3d<float>,
    opengl_math::color_rgba<float>> verts;
  verts m_vertexAttrib;
  opengl_math::matrix_4X4<float, opengl_math::column> m_projection;
  opengl_math::cubic_curve<float, opengl_math::column> m_cubic;
  opengl_math::color_rgba<float> m_color;
};

#endif // SPLINES_H
