#ifndef PROJECTEDRAINBOW2TEXTUREDSQUARE_H
#define PROJECTEDRAINBOW2TEXTUREDSQUARE_H

#include "geometries/geometry.h"

#include "glshaderresourcemanager.h"
#include "gltextureresourcemanager.h"

#include "mesh_types/interleaved_data.h"
#include "mesh_types/datums/interleaved_datum_2d.h"
#include "mesh_types/indices.h"
#include "primitives/points/type_point_3d.h"
#include "primitives/colors/type_color_rgba.h"
#include "primitives/texcoords/type_texcoord_2d.h"

#include <memory>

class ProjectedRainbow2TexturedSquare : public Geometry
{
public:
  ProjectedRainbow2TexturedSquare();
  ~ProjectedRainbow2TexturedSquare();

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

private:
  std::shared_ptr<GLShaderResourceManager> m_shaderManager;
  std::shared_ptr<GLTextureResourceManager> m_textureManager;

  GLuint m_vbo;
  GLuint m_ebo;

  GLShaderResourceManager::GLShaderHandle m_handle;
  std::vector<GLShaderResourceManager::GLShaderAttributes> m_shaderVertexAttrib;
  GLTextureResourceManager::GLTextureHandle m_texHandles[2];

  typedef opengl_graphics::interleaved_data<opengl_math::point_3d<float>,
    opengl_math::color_rgba<float>, opengl_math::texcoord_2d<float>> verts;
  verts m_vertexAttrib;
  opengl_graphics::indices<uint32_t> m_indices;

  opengl_math::matrix_4X4<float, opengl_math::column> m_mvp;
  opengl_math::matrix_4X4<float, opengl_math::column> m_transform;
};

#endif // PROJECTEDRAINBOWTEXTUREDSQUARE_H
