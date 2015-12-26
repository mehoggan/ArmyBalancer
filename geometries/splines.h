#ifndef SPLINES_H
#define SPLINES_H

#include "geometries/geometry.h"

#include "glshaderresourcemanager.h"

#include "mesh_types/interleaved_data.h"
#include "mesh_types/datums/interleaved_datum_2d.h"
#include "curves/cubic_curve.h"
#include "curves/curve_sample_3d.h"
#include "matrices/type_matrix_4X4.h"
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

  virtual void setTransform(
    const opengl_math::matrix_4X4<float, opengl_math::column> &transform)
  {
    m_transform = transform;
  }

  virtual const opengl_math::matrix_4X4<float, opengl_math::column> &
  getTransform() const {return m_transform;}

  virtual void setMVPMatrix(
    const opengl_math::matrix_4X4<float, opengl_math::column> &mvp)
  {
    m_mvp = mvp;
  }

  virtual void create();
  virtual void draw();
  virtual void destroy();

  auto computeCenter() -> opengl_math::point_3d<float>;

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

   void debug() const;

private:
  Spline();

  GLShaderResourceManager::GLShaderHandle m_handle;
  std::vector<GLShaderResourceManager::GLShaderAttributes> m_shaderVertexAttrib;
  std::shared_ptr<GLShaderResourceManager> m_shaderManager;

  GLuint m_vbo;

  typedef opengl_graphics::interleaved_data<opengl_math::point_3d<float>,
    opengl_math::color_rgba<float>> verts;
  verts m_vertexAttrib;
  opengl_math::cubic_curve<float, opengl_math::column> m_cubic;

  opengl_math::matrix_4X4<float, opengl_math::column> m_mvp;
  opengl_math::matrix_4X4<float, opengl_math::column> m_transform;
};

#endif // SPLINES_H
