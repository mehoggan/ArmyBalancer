#include "geometries/projectedrainbow2texturedsquare.h"

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

ProjectedRainbow2TexturedSquare::ProjectedRainbow2TexturedSquare()
  : m_vbo(0)
  , m_ebo(0)
  , m_mvp(opengl_math::identity)
  , m_transform(opengl_math::identity)
{}

ProjectedRainbow2TexturedSquare::~ProjectedRainbow2TexturedSquare()
{
  destroy();
}

void ProjectedRainbow2TexturedSquare::create()
{
  initializeOpenGLFunctions();

  if (!m_shaderManager) {
    m_shaderManager = GLShaderResourceManager::getSharedInstance();
  }

  if (!m_textureManager) {
    m_textureManager = GLTextureResourceManager::getSharedInstance();
  }

  destroy();

  glGenBuffers(1, &m_vbo); GL_CALL
  verts::collection_type data(new verts::datum_type[4]);
  data[0] = verts::datum_type(
    opengl_math::point_3d<float>(-1.0f, +1.0f, -1.0f),
    opengl_math::color_rgba<float>(+1.0f, +0.0f, +0.0f, +1.0f),
    opengl_math::texcoord_2d<float>(0.0f, 0.0f));
  data[1] = verts::datum_type(
    opengl_math::point_3d<float>(+1.0f, +1.0f, -1.0f),
    opengl_math::color_rgba<float>(+0.0f, +1.0f, +0.0f, +1.0f),
    opengl_math::texcoord_2d<float>(1.0f, 0.0f));
  data[2] = verts::datum_type(
    opengl_math::point_3d<float>(+1.0f, -1.0f, -1.0f),
    opengl_math::color_rgba<float>(+0.0f, +0.0f, +1.0f, +1.0f),
    opengl_math::texcoord_2d<float>(1.0f, 1.0f));
  data[3] = verts::datum_type(
    opengl_math::point_3d<float>(-1.0f, -1.0f, -1.0f),
    opengl_math::color_rgba<float>(+1.0f, +1.0f, +1.0f, +1.0f),
    opengl_math::texcoord_2d<float>(0.0f, 1.0f));
  m_vertexAttrib = verts(data, 4);
  std::size_t bytes = m_vertexAttrib.get_byte_count();
  glBindBuffer(GL_ARRAY_BUFFER, m_vbo); GL_CALL
  glBufferData(GL_ARRAY_BUFFER, bytes, m_vertexAttrib.get_data().get(),
    GL_STATIC_DRAW); GL_CALL

  glGenBuffers(1, &m_ebo); GL_CALL
  opengl_graphics::indices<uint32_t>::collection_type indices(
    new uint32_t[6]);
  indices[0] = 0u; indices[1] = 1u; indices[2] = 2u;
  indices[3] = 2u; indices[4] = 3u; indices[5] = 0u;
  m_indices = opengl_graphics::indices<uint32_t>(indices, 6);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ebo); GL_CALL
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, m_indices.get_byte_count(),
    m_indices.get_data().get(), GL_STATIC_DRAW); GL_CALL

  std::shared_ptr<GLSLVersionSelector> versionSelector =
    GLSLVersionSelector::getSharedInstance();
  std::shared_ptr<QResource> vshaderRes = versionSelector->getResourcePath(
    "projectedcoloredtextured_vshader.glsl");
  std::shared_ptr<QResource> fshaderRes = versionSelector->getResourcePath(
    "projectedcolored2samplermixed_fshader.glsl");
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

  QImage img0(":/images/die1.png", "PNG");
  m_texHandles[0] = m_textureManager->createTextureResource();
  m_textureManager->uploadTexture(img0, m_texHandles[0]);
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

  QImage img1(":/images/die2.png", "PNG");
  m_texHandles[1] = m_textureManager->createTextureResource();
  m_textureManager->uploadTexture(img1, m_texHandles[1]);
  m_textureManager->setTextureParameters(
    m_texHandles[1],
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

void ProjectedRainbow2TexturedSquare::draw()
{
#if !defined(__ANDROID__)
  glPushAttrib(GL_ALL_ATTRIB_BITS);
#endif
  m_shaderManager->useProgram(m_handle);
  glBindBuffer(GL_ARRAY_BUFFER, m_vbo); GL_CALL
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ebo); GL_CALL
  m_textureManager->activateTexture(m_texHandles[0]);
  m_shaderManager->configureSampler(m_handle, m_texHandles[0], "uSampler1");
  m_textureManager->activateTexture(m_texHandles[1]);
  m_shaderManager->configureSampler(m_handle, m_texHandles[1], "uSampler2");
  m_shaderManager->enableVertexAttribArrays(m_handle, m_shaderVertexAttrib);
  m_shaderManager->setUniformMatrix4X4(m_handle, m_mvp.to_gl_matrix(), "uMVP");
  glDrawElements(GL_TRIANGLES, (GLsizei)m_indices.get_indices_count(),
    GL_UNSIGNED_INT, 0); GL_CALL
  m_textureManager->deactivateTexture(m_texHandles[0]);
  m_textureManager->deactivateTexture(m_texHandles[1]);
#if !defined(__ANDROID__)
  glPopAttrib();
#endif
}

void ProjectedRainbow2TexturedSquare::destroy()
{
  if (glIsBuffer(m_vbo)) {
    glDeleteBuffers(1, &m_vbo); GL_CALL
  }

  if (glIsBuffer(m_ebo)) {
    glDeleteBuffers(1, &m_ebo); GL_CALL
  }

  m_shaderManager->destroyProgram(m_handle);
  m_textureManager->destroyTextures({m_texHandles[0], m_texHandles[1]});
}
