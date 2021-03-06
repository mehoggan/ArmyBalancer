﻿#ifndef ELLIPSE_H
#define ELLIPSE_H

#include "geometries/geometry.h"

#include "glshaderresourcemanager.h"
#include "gltextureresourcemanager.h"
#include "nametextureatlasmap.h"
#include "warscroll.h"

#include "mesh_types/interleaved_data.h"
#include "mesh_types/datums/interleaved_datum_2d.h"
#include "mesh_types/indices.h"
#include "primitives/points/type_point_3d.h"
#include "primitives/colors/type_color_rgba.h"
#include "primitives/texcoords/type_texcoord_2d.h"

#include <memory>

// The namespace Protection was used to prevent Ellipse as a global class not
// being detected by the compiler in Visual Studio 2013.
namespace Protection
{
  const float a = 1.0f;
  const float b = 0.5f;

  class Ellipse : public Geometry
  {
  public:
    Ellipse(float w = a, float h = b);
    ~Ellipse();

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

    virtual void draw();
    virtual void destroy();

    void create_bbox(opengl_math::axis_aligned_2d<float> *bbox = nullptr);

    const std::string &getName() const {return m_name;}
    void setName(const std::string &name) {m_name = name;}

    const WarScroll &getWarScroll() const {return m_warScroll;}
    void setWarScroll(const WarScroll &warScroll) {m_warScroll = warScroll;}

    auto getUniformColor() const -> const opengl_math::color_rgba<float>&
    {return m_uniform;}
    void setUnifromColor(const opengl_math::color_rgba<float> &color)
    {m_uniform = color;}
    void setTextureAtlas(const NameTextureAtlasMap &atlas)
    {m_tetxtureAtlas = &atlas;}

    bool collides(const Ellipse &other) const;
    opengl_math::point_3d<float> getCenter() const;
    bool contains(const opengl_math::point_3d<float> &point);

    bool insideFrustum(
      const opengl_math::matrix_4X4<float, opengl_math::column> &proj,
      const opengl_math::matrix_4X4<float, opengl_math::column> &view) const;

    friend bool operator==(const Ellipse &lhs, const Ellipse &rhs)
    {
      return (lhs.m_warScroll == rhs.m_warScroll);
    }

  private:
    virtual void create();

    std::shared_ptr<GLShaderResourceManager> m_shaderManager;

    GLuint m_vbo;
    GLuint m_ebo;

    GLShaderResourceManager::GLShaderHandle m_handle;
    std::vector<GLShaderResourceManager::GLShaderAttributes>
      m_shaderVertexAttrib;

    typedef opengl_graphics::interleaved_data<opengl_math::point_3d<float>,
      opengl_math::color_rgba<float>, opengl_math::texcoord_2d<float>> verts;
    verts m_vertexAttrib;
    typedef opengl_graphics::indices<uint32_t> indices;
    indices m_indices;

    opengl_math::matrix_4X4<float, opengl_math::column> m_mvp;
    opengl_math::matrix_4X4<float, opengl_math::column> m_transform;
    opengl_math::color_rgba<float> m_uniform;

    std::string m_name;
    WarScroll m_warScroll;

    const NameTextureAtlasMap *m_tetxtureAtlas;
    const opengl_math::axis_aligned_2d<float> *m_uvBbox;

    float m_a;
    float m_b;
  };
}

#endif // ELLIPSE_H
