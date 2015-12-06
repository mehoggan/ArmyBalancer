#include "ellipse.h"

#include "glslversionselector.h"

#include "math/matrix.h"
#include "matrices/type_matrix_4X4.h"
#include "primitives/points/type_point_3d.h"
#include "primitives/vectors/type_vector_3d.h"

#include <QFile>
#include <QImage>
#include <QTextStream>
#include <QGLWidget>

#include <iostream>

#include <string.h>

const float a = 1.0f;
const float b = 0.5f;

Ellipse::Ellipse()
  : m_vbo(0)
  , m_ebo(0)
  , m_mvp(opengl_math::identity)
  , m_transform(opengl_math::identity)
{}

Ellipse::~Ellipse()
{}

void Ellipse::create()
{
  initializeOpenGLFunctions();

  if (!m_shaderManager) {
    m_shaderManager = GLShaderResourceManager::getSharedInstance();
  }

  if (!m_textureManager) {
    m_textureManager = GLTextureResourceManager::getSharedInstance();
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

  std::vector<std::pair<float, float>> texs;
  data[attrib++] = verts::datum_type(
    opengl_math::point_3d<float>(0.0f, 0.0f, 0.0f),
    opengl_math::color_rgba<float>(1.0f, 1.0f, 1.0f, 1.0f),
    opengl_math::texcoord_2d<float>(0.5f, 0.5f));
  texs.push_back(std::make_pair(0.5f, 0.5f));

  float t = 0.0f;
  while (index < totalIndice) {
    t += step;
    indic[index++] = 0u;

    float rad = (t * 360.0f) * (opengl_math::pi<float>() / 180.0f);

    float x0 = a * std::cos(rad);
    float y0 = b * std::sin(rad);
    float u = (x0 + 1.0f) / (2);
    float v = (y0 + 1.0f) / (2);
    data[attrib++] = verts::datum_type(
      opengl_math::point_3d<float>(x0, y0, 0.0f),
      opengl_math::color_rgba<float>(1.0f, 1.0f, 1.0f, 1.0f),
      opengl_math::texcoord_2d<float>(u, v));

    texs.push_back(std::make_pair(u, v));

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
    throw std::runtime_error("Failed to generate program for textured square");
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

  m_texHandles[0] = m_textureManager->createTextureResource();
  m_textureManager->uploadTexture(m_nameTexture, m_texHandles[0]);
  m_textureManager->setTextureParameters(
    m_texHandles[0],
    {
      GLTextureResourceManager::GLTextureParameteri(
        GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE),
      GLTextureResourceManager::GLTextureParameteri(
        GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE),
      GLTextureResourceManager::GLTextureParameteri(
        GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR),
      GLTextureResourceManager::GLTextureParameteri(
        GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR),
    });
}

void Ellipse::draw()
{
  glPushAttrib(GL_ALL_ATTRIB_BITS);
  m_shaderManager->useProgram(m_handle);
  glBindBuffer(GL_ARRAY_BUFFER, m_vbo); GL_CALL
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ebo); GL_CALL
  m_textureManager->activateTexture(m_texHandles[0]);
  m_shaderManager->configureSampler(m_handle, m_texHandles[0], "uSampler1");
  m_shaderManager->enableVertexAttribArrays(m_handle, m_shaderVertexAttrib);
  m_shaderManager->setUniformMatrix4X4(m_handle, m_mvp.to_gl_matrix(), "uMVP");
  glDrawElements(GL_TRIANGLES, m_indices.get_indices_count(), GL_UNSIGNED_INT,
    0); GL_CALL
  m_textureManager->deactivateTexture(m_texHandles[0]);
  glPopAttrib();
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

void Ellipse::setNameTexture(const QImage &image)
{
  m_nameTexture = image;
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
    xpart /= (a * a);

    float ypart = (op.y() - mc.y());
    ypart *= ypart;
    ypart /= (b * b);

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
