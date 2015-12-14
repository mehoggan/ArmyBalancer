#ifndef ELLIPSE_H
#define ELLIPSE_H

#include "geometries/geometry.h"

#include "glshaderresourcemanager.h"
#include "gltextureresourcemanager.h"
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
  class Ellipse : public Geometry
  {
  public:
    Ellipse();
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

    virtual void create();
    virtual void draw();
    virtual void destroy();

    const std::string &getName() const {return m_name;}
    void setName(const std::string &name) {m_name = name;}

    const WarScroll &getWarScroll() const {return m_warScroll;}
    void setWarScroll(const WarScroll &warScroll) {m_warScroll = warScroll;}

    void setNameTexture(const QImage &image);
    bool collides(const Ellipse &other) const;
    opengl_math::point_3d<float> getCenter() const;

    bool insideFrustum(
      const opengl_math::matrix_4X4<float, opengl_math::column> &proj,
      const opengl_math::matrix_4X4<float, opengl_math::column> &view) const;

    friend bool operator==(const Ellipse &lhs, const Ellipse &rhs)
    {
      return (lhs.m_warScroll == rhs.m_warScroll);
    }

  private:
    std::shared_ptr<GLShaderResourceManager> m_shaderManager;
    std::shared_ptr<GLTextureResourceManager> m_textureManager;

    GLuint m_vbo;
    GLuint m_ebo;

    GLShaderResourceManager::GLShaderHandle m_handle;
    std::vector<GLShaderResourceManager::GLShaderAttributes> m_shaderVertexAttrib;
    GLTextureResourceManager::GLTextureHandle m_texHandles[1];

    typedef opengl_graphics::interleaved_data<opengl_math::point_3d<float>,
      opengl_math::color_rgba<float>, opengl_math::texcoord_2d<float>> verts;
    verts m_vertexAttrib;
    typedef opengl_graphics::indices<uint32_t> indices;
    indices m_indices;

    opengl_math::matrix_4X4<float, opengl_math::column> m_mvp;
    opengl_math::matrix_4X4<float, opengl_math::column> m_transform;

    QImage m_nameTexture;
    std::string m_name;
    WarScroll m_warScroll;
  };
}

#endif // ELLIPSE_H
