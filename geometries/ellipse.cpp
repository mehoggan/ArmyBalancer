#include "ellipse.h"

#include "glslversionselector.h"

#include "math/matrix.h"
#include "math/vector.h"
#include "matrices/type_matrix_4X4.h"
#include "planes/plane_3d.h"
#include "primitives/conversions.h"
#include "primitives/points/type_point_3d.h"
#include "primitives/vectors/type_vector_3d.h"
#include "primitives/vectors/type_vector_4d.h"

#include <QFile>
#include <QImage>
#include <QTextStream>
#include <QGLWidget>

#include <array>
#include <iostream>

#include <string.h>

namespace Protection
{
  Ellipse::Ellipse(float w, float h)
    : m_vbo(0)
    , m_ebo(0)
    , m_mvp(opengl_math::identity)
    , m_transform(opengl_math::identity)
    , m_uniform(1.0f, 1.0f, 1.0f, 1.0f)
    , m_tetxtureAtlas(nullptr)
    , m_a(w)
    , m_b(h)
  {}

  Ellipse::~Ellipse()
  {}

  void Ellipse::create_bbox(opengl_math::axis_aligned_2d<float> *bbox)
  {
    if (!bbox || !bbox->is_valid()) {
      return;
    }

    m_uvBbox = bbox;
    create();
  }

  void Ellipse::create()
  {
    Q_ASSERT(m_uvBbox);

    initializeOpenGLFunctions();

    if (!m_shaderManager) {
      m_shaderManager = GLShaderResourceManager::getSharedInstance();
    }

    destroy();

    const float step = 0.001f;
    const std::size_t totalPoints = (float)(1.0f / step) + 1;
    const std::size_t totalTriang = (float)(1.0f / step);
    const std::size_t totalIndice = totalTriang * 3;

    verts::collection_type data(new verts::datum_type[totalPoints]);
    indices::collection_type indic(new uint32_t[totalIndice]);

    std::size_t attrib = 0u;
    std::size_t index = 0u;
    std::uint32_t indexVal = 1u;

    auto center = m_uvBbox->center();
    data[attrib++] = verts::datum_type(
      opengl_math::point_3d<float>(0.0f, 0.0f, 0.0f),
      opengl_math::color_rgba<float>(1.0f, 1.0f, 1.0f, 1.0f),
      opengl_math::texcoord_2d<float>(center.x(), center.y()));

    auto *bbox = const_cast<opengl_math::axis_aligned_2d<float>*>(m_uvBbox);

    float minX = bbox->r_ll().x();
    float minY = bbox->r_ll().y();
    float maxX = bbox->r_ur().x();
    float maxY = bbox->r_ur().y();

    float xDiff = maxX - minX;
    float yDiff = maxY - minY;

    float t = 0.0f;
    while (index < totalIndice) {
      t += step;
      indic[index++] = 0u;

      float rad = (t * 360.0f) * (opengl_math::pi<float>() / 180.0f);

      float x0 = m_a * std::cos(rad);
      float y0 = m_b * std::sin(rad);
      float u = minX + (x0 + 1.0f) / (2) * (xDiff);
      float v = minY + (y0 + 1.0f) / (2) * (yDiff);

      data[attrib++] = verts::datum_type(
        opengl_math::point_3d<float>(x0, y0, 0.0f),
        opengl_math::color_rgba<float>(1.0f, 1.0f, 1.0f, 1.0f),
        opengl_math::texcoord_2d<float>(u, v));

      indic[index++] = (indexVal++);
      if (index < totalIndice - 1) {
        indic[index++] = (indexVal);
      } else {
        indic[index++] = (1u);
      }
    }

    m_vertexAttrib = verts(data, attrib);
    std::size_t bytes = m_vertexAttrib.get_byte_count();
    glGenBuffers(1, &m_vbo); GL_CALL
    glBindBuffer(GL_ARRAY_BUFFER, m_vbo); GL_CALL
    glBufferData(GL_ARRAY_BUFFER, bytes, m_vertexAttrib.get_data().get(),
      GL_STATIC_DRAW); GL_CALL

    m_indices = indices(indic, index);
    glGenBuffers(1, &m_ebo); GL_CALL
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ebo); GL_CALL
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, m_indices.get_byte_count(),
      m_indices.get_data().get(), GL_STATIC_DRAW); GL_CALL

    std::shared_ptr<GLSLVersionSelector> versionSelector =
      GLSLVersionSelector::getSharedInstance();
    std::shared_ptr<QResource> vshaderRes = versionSelector->getResourcePath(
      "projectedcoloredtextured_vshader.glsl");
    std::shared_ptr<QResource> fshaderRes = versionSelector->getResourcePath(
      "projectedcolored1sampler_fshader.glsl");
    bool success = true;
    m_handle = m_shaderManager->generateProgram({vshaderRes}, {fshaderRes},
      &success);
    if (!success) {
      qFatal((QString("Failed to generate shader program in !!!") +
        __FILE__).toStdString().c_str());
    }

    m_shaderVertexAttrib.resize(3);
    m_shaderVertexAttrib[0] = GLShaderResourceManager::GLShaderAttributes(
      verts::datum_type::internal_type1::dimension,
      verts::traits::stride,
      verts::traits::type1_byte_offset,
      "iPosition");
    m_shaderVertexAttrib[1] = GLShaderResourceManager::GLShaderAttributes(
      verts::datum_type::internal_type2::dimension,
      verts::traits::stride,
      verts::traits::type2_byte_offset,
      "iColor");
    m_shaderVertexAttrib[2] = GLShaderResourceManager::GLShaderAttributes(
      verts::datum_type::internal_type3::dimension,
      verts::traits::stride,
      verts::traits::type3_byte_offset,
      "iTexcoord");
  }

  void Ellipse::draw()
  {
    auto textureHandle = m_tetxtureAtlas->textureHandle();
    auto textureManager = GLTextureResourceManager::getSharedInstance();

    m_shaderManager->useProgram(m_handle);
    glBindBuffer(GL_ARRAY_BUFFER, m_vbo); GL_CALL
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ebo); GL_CALL
    textureManager->activateTexture(textureHandle);
    m_shaderManager->configureSampler(m_handle, textureHandle, "uSampler1");
    m_shaderManager->setUniformRGBA(m_handle, m_uniform, "uColor");
    m_shaderManager->enableVertexAttribArrays(m_handle, m_shaderVertexAttrib);
    m_shaderManager->setUniformMatrix4X4(m_handle, m_mvp.to_gl_matrix(),
      "uMVP");
    glDrawElements(GL_TRIANGLES, (GLsizei)m_indices.get_indices_count(),
      GL_UNSIGNED_INT, 0); GL_CALL
  }

  void Ellipse::destroy()
  {
    if (glIsBuffer(m_vbo)) {
      glDeleteBuffers(1, &m_vbo); GL_CALL
    }

    if (glIsBuffer(m_ebo)) {
      glDeleteBuffers(1, &m_ebo); GL_CALL
    }

    m_shaderManager->destroyProgram(m_handle);
  }

  bool Ellipse::collides(const Ellipse &other) const
  {
    bool collision = false;

    // This is the center point inside (*this)'s ellipse
    verts::datum_type mattrib = m_vertexAttrib.get_data()[0];
    opengl_math::point_3d<float> mc = mattrib._datum1;
    opengl_math::vector_4d<float> mcv(mc.x(), mc.y(), mc.z(), 1.0f);
    opengl_math::matrix_4X4<float, opengl_math::column> mtrans = getTransform();
    mcv = mtrans * mcv;
    mc = opengl_math::point_3d<float>(mcv.x(), mcv.y(), mcv.z());

    opengl_math::matrix_4X4<float, opengl_math::column> trans =
      other.getTransform();

    // i == 0 is the center of the ellipse
    for (std::size_t i = 1;
      i < other.m_vertexAttrib.get_attribute_count(); ++i) {

      verts::datum_type attrib = other.m_vertexAttrib.get_data()[i];
      // This is a point on the edge of the other ellipse.
      opengl_math::point_3d<float> op = attrib._datum1;
      // We need to transform this point to world coordinates.
      opengl_math::vector_4d<float> opv(op.x(), op.y(), op.z(), 1.0f);
      opv = (trans * opv);
      op = opengl_math::point_3d<float>(opv[0], opv[1], opv[2]);

      float xpart = (op.x() - mc.x());
      xpart *= xpart;
      xpart /= (m_a * m_a);

      float ypart = (op.y() - mc.y());
      ypart *= ypart;
      ypart /= (m_b * m_b);

      // Solving for; is op is within (*this)
      float solve = xpart + ypart;
      collision = (solve <= 1.0f);

      if (collision) {
        break;
      }
    }

    return collision;
  }

  opengl_math::point_3d<float> Ellipse::getCenter() const
  {
    verts::datum_type mattrib = m_vertexAttrib.get_data()[0];
    opengl_math::point_3d<float> mc = mattrib._datum1;
    opengl_math::vector_4d<float> mcv(mc.x(), mc.y(), mc.z(), 1.0f);
    opengl_math::matrix_4X4<float, opengl_math::column> mtrans = getTransform();
    mcv = mtrans * mcv;
    return opengl_math::point_3d<float>(mcv.x(), mcv.y(), mcv.z());
  }

  bool Ellipse::contains(const opengl_math::point_3d<float> &point)
  {
    const opengl_math::point_3d<float> center = getCenter();

    float x = (point.x() - center.x());
    x *= x;
    x /= (m_a * m_a);

    float y = (point.y() - center.y());
    y *= y;
    y /= (m_b * m_b);

    float final = x + y;
    return (final <= 1.0f);
  }

  bool Ellipse::insideFrustum(
    const opengl_math::matrix_4X4<float, opengl_math::column> &proj,
    const opengl_math::matrix_4X4<float, opengl_math::column> &view) const
  {
    bool inside = true;

    auto mvp = (proj * view * m_transform);

    // i == 0 is the center of the ellipse
    for (std::size_t i = 1; i < m_vertexAttrib.get_attribute_count(); ++i) {
      opengl_math::point_3d<float> mc = m_vertexAttrib.get_data()[i]._datum1;
      // Note mCR ==> m[column][row]
      //                  ---   -------------------------------------   --------
      //                   x'   m00 * x + m10 * y + m20 * z + m30 * w   row0 * v
      //                   y'   m01 * x + m11 * y + m21 * z + m31 * w   row1 * v
      // (M)[v] = [v'] ==> z' = m02 * x + m12 * y + m22 * z + m32 * w = row2 * v
      //                   w'   m03 * x + m13 * y + m23 * z + m33 * w   row3 * v
      //                  ---  --------------------------------------   --------
      // This places [v'] in homogeneous clipping space which is an axis-aligned
      // bounding box. This implies if [v'] is within this space, then [v] is
      // within the view frustum.
      auto v = opengl_math::vector4d_from_point3d(mc, 1.0f);
      auto vprime = mvp * v;

      // See http://gamedevs.org/uploads/fast-extraction-viewing-frustum-
      // planes-from-world-view-projection-matrix.pdf
      float x = vprime.x();
      float y = vprime.y();
      float z = vprime.z();
      float w = vprime.w();

      inside = (-w < x) && (x < w) && (-w < y) && (y < w) && (-w < z) &&
        (z < w);
      if (!inside) {
        break;
      }
    }

    return inside;
  }
}
