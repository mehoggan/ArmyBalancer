#ifndef PROJECTEDRAINBOW2TEXTUREDSQUARE_H
#define PROJECTEDRAINBOW2TEXTUREDSQUARE_H

#include "geometries/geometry.h"

#include "glshaderresourcemanager.h"

#include "mesh_types/interleaved_data.h"
#include "mesh_types/datums/interleaved_datum_2d.h"
#include "mesh_types/indices.h"
#include "primitives/points/type_point_3d.h"
#include "primitives/colors/type_color_rgba.h"
#include "primitives/texcoords/type_texcoord_2d.h"

#include <chrono>
#include <memory>

class ProjectedRainbow2TexturedSquare : public Geometry
{
public:
  ProjectedRainbow2TexturedSquare();
  ~ProjectedRainbow2TexturedSquare();
  virtual void setProjection(
    const opengl_math::matrix_4X4<float, opengl_math::column> &projection);
  virtual void create();
  virtual void draw();
  virtual void destroy();

private:
  GLShaderResourceManager::GLShaderHandle m_handle;
  std::vector<GLShaderResourceManager::GLShaderAttributes> m_shaderVertexAttrib;
  std::shared_ptr<GLShaderResourceManager> m_shaderManager;

  GLuint m_vbo;
  GLuint m_ebo;
  GLuint m_tex[2];

  typedef opengl_graphics::interleaved_data<opengl_math::point_3d<float>,
    opengl_math::color_rgba<float>, opengl_math::texcoord_2d<float>> verts;
  verts m_vertexAttrib;
  opengl_graphics::indices<uint32_t> m_indices;
  opengl_math::matrix_4X4<float, opengl_math::column> m_projection;

  std::chrono::high_resolution_clock::time_point m_start;
};

#endif // PROJECTEDRAINBOWTEXTUREDSQUARE_H
