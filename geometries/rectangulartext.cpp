#include "rectangulartext.h"

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

const float RectangularText::gw = 1.0f;
const float RectangularText::gh = 0.5f;

RectangularText::RectangularText(float w, float h)
  : m_vbo(0)
  , m_ebo(0)
  , m_mvp(opengl_math::identity)
  , m_transform(opengl_math::identity)
  , m_uniform(1.0f, 1.0f, 1.0f, 1.0f)
  , m_tetxtureAtlas(nullptr)
  , m_w(w)
  , m_h(h)
{}

RectangularText::~RectangularText()
{}

void RectangularText::create_bbox(opengl_math::axis_aligned_2d<float> *bbox)
{
  if (!bbox || !bbox->is_valid()) {
    return;
  }

  m_uvBbox = bbox;
  create();
}

void RectangularText::create()
{
  Q_ASSERT(m_uvBbox);

  initializeOpenGLFunctions();

  if (!m_shaderManager) {
    m_shaderManager = GLShaderResourceManager::getSharedInstance();
  }

  destroy();

  const std::size_t totalPoints = 4u;
  const std::size_t totalIndice = 6u;

  verts::collection_type data(new verts::datum_type[totalPoints]);
  indices::collection_type indic(new uint32_t[totalIndice]);

  auto *bbox = const_cast<opengl_math::axis_aligned_2d<float>*>(m_uvBbox);
  float llU = bbox->r_ll().x();
  float llV = bbox->r_ll().y();
  float urU = bbox->r_ur().x();
  float urV = bbox->r_ur().y();

  // 3--2
  // | /|
  // |/ |
  // 0--1
  data[0] = verts::datum_type(
    opengl_math::point_3d<float>(-m_w / 2.0f, -m_h / 2.0f, 0.0f),
    opengl_math::color_rgba<float>(0.0f, 0.0f, 0.0f, 1.0f),
    opengl_math::texcoord_2d<float>(llU, llV));
  data[1] = verts::datum_type(
    opengl_math::point_3d<float>(+m_w / 2.0f, -m_h / 2.0f, 0.0f),
    opengl_math::color_rgba<float>(0.0f, 0.0f, 0.0f, 1.0f),
    opengl_math::texcoord_2d<float>(urU, llV));
  data[2] = verts::datum_type(
    opengl_math::point_3d<float>(+m_w / 2.0f, +m_h / 2.0f, 0.0f),
    opengl_math::color_rgba<float>(0.0f, 0.0f, 0.0f, 1.0f),
    opengl_math::texcoord_2d<float>(urU, urV));
  data[3] = verts::datum_type(
    opengl_math::point_3d<float>(-m_w / 2.0f, +m_h / 2.0f, 0.0f),
    opengl_math::color_rgba<float>(0.0f, 0.0f, 0.0f, 1.0f),
    opengl_math::texcoord_2d<float>(llU, urV));

  indic[0] = 0;
  indic[1] = 1;
  indic[2] = 2;
  indic[3] = 2;
  indic[4] = 3;
  indic[5] = 0;

  m_vertexAttrib = verts(data, totalPoints);
  std::size_t bytes = m_vertexAttrib.get_byte_count();
  glGenBuffers(1, &m_vbo); GL_CALL
  glBindBuffer(GL_ARRAY_BUFFER, m_vbo); GL_CALL
  glBufferData(GL_ARRAY_BUFFER, bytes, m_vertexAttrib.get_data().get(),
    GL_STATIC_DRAW); GL_CALL

  m_indices = indices(indic, totalIndice);
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

void RectangularText::draw()
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

void RectangularText::destroy()
{
  if (glIsBuffer(m_vbo)) {
    glDeleteBuffers(1, &m_vbo); GL_CALL
  }

  if (glIsBuffer(m_ebo)) {
    glDeleteBuffers(1, &m_ebo); GL_CALL
  }

  m_shaderManager->destroyProgram(m_handle);
}
