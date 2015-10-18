#include "geometries/projectedrainbow2texturedsquare.h"

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

ProjectedRainbow2TexturedSquare::ProjectedRainbow2TexturedSquare() :
  m_shaderProgram(0),
  m_vertexShader(0),
  m_fragmentShader(0),
  m_vbo(0),
  m_ebo(0),
  m_start(std::chrono::high_resolution_clock::now())
{
  m_tex[0] = 0;
  m_tex[1] = 0;
}

ProjectedRainbow2TexturedSquare::~ProjectedRainbow2TexturedSquare()
{
  destroy();
}

void ProjectedRainbow2TexturedSquare::setProjection(
  const opengl_math::matrix_4X4<float, opengl_math::column> &projection)
{
  m_projection = projection;
}

void ProjectedRainbow2TexturedSquare::create()
{
  initializeOpenGLFunctions();

  QFile vshaderFile(
    ":/shaders/projectedrainbow2texturedsquare_vshader.glsl");
  if (!vshaderFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
    throw (std::string("Could not open ") +
      vshaderFile.fileName().toStdString()).c_str();
  }
  QTextStream vshaderStream(&vshaderFile);
  std::string vshaderSrc = vshaderStream.readAll().toStdString();

  QFile fshaderFile(
    ":/shaders/projectedrainbow2texturedsquare_fshader.glsl");
  if (!fshaderFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
    throw (std::string("Could not open ") +
      fshaderFile.fileName().toStdString()).c_str();
  }
  QTextStream fshaderStream(&fshaderFile);
  std::string fshaderSrc = fshaderStream.readAll().toStdString();

  glGenBuffers(1, &m_vbo); GL_CALL

  verts::collection_type data(new verts::datum_type[4]);
  data[0] = verts::datum_type(
    opengl_math::point_2d<float>(-0.5f, +0.5f),
    opengl_math::color_rgb<float>(+1.0f, +0.0f, +0.0f),
    opengl_math::texcoord_2d<float>(0.0f, 0.0f));
  data[1] = verts::datum_type(
    opengl_math::point_2d<float>(+0.5f, +0.5f),
    opengl_math::color_rgb<float>(+0.0f, +1.0f, +0.0f),
    opengl_math::texcoord_2d<float>(1.0f, 0.0f));
  data[2] = verts::datum_type(
    opengl_math::point_2d<float>(+0.5f, -0.5f),
    opengl_math::color_rgb<float>(+0.0f, +0.0f, +1.0f),
    opengl_math::texcoord_2d<float>(1.0f, 1.0f));
  data[3] = verts::datum_type(
    opengl_math::point_2d<float>(-0.5f, -0.5f),
    opengl_math::color_rgb<float>(+1.0f, +1.0f, +1.0f),
    opengl_math::texcoord_2d<float>(0.0f, 1.0f));
  m_vertexAttrib = verts(data, 4);

  std::size_t bytes = m_vertexAttrib.get_byte_count();

  glBindBuffer(GL_ARRAY_BUFFER, m_vbo); GL_CALL
  glBufferData(GL_ARRAY_BUFFER, bytes, m_vertexAttrib.get_data().get(),
    GL_STATIC_DRAW); GL_CALL

  glGenBuffers(1, &m_ebo); GL_CALL
  // Create indices
  opengl_graphics::indices<uint32_t>::collection_type indices(
    new uint32_t[6]);
  indices[0] = 0u; indices[1] = 1u; indices[2] = 2u;
  indices[3] = 2u; indices[4] = 3u; indices[5] = 0u;
  m_indices = opengl_graphics::indices<uint32_t>(indices, 6);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ebo); GL_CALL
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, m_indices.get_byte_count(),
    m_indices.get_data().get(), GL_STATIC_DRAW); GL_CALL

  // Create and compile the vertex shader
  m_vertexShader = glCreateShader(GL_VERTEX_SHADER); GL_CALL
  const GLchar *vshaderRaw = vshaderSrc.c_str();
  glShaderSource(m_vertexShader, 1, &(vshaderRaw), NULL); GL_CALL
  glCompileShader(m_vertexShader); GL_CALL

  // Create and compile the fragment shader
  m_fragmentShader = glCreateShader(GL_FRAGMENT_SHADER); GL_CALL
  const GLchar *fshaderRaw = fshaderSrc.c_str();
  glShaderSource(m_fragmentShader, 1, &(fshaderRaw), NULL); GL_CALL
  glCompileShader(m_fragmentShader); GL_CALL

  // Link the vertex and fragment shader into a shader program
  m_shaderProgram = glCreateProgram(); GL_CALL
  glAttachShader(m_shaderProgram, m_vertexShader); GL_CALL
  glAttachShader(m_shaderProgram, m_fragmentShader); GL_CALL
  glLinkProgram(m_shaderProgram); GL_CALL

  glGenTextures(2, m_tex); GL_CALL

  QImage img0(":/images/die1.png", "PNG");
  glBindTexture(GL_TEXTURE_2D, m_tex[0]); GL_CALL
  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, img0.width(), img0.height(), 0,
    GL_RGBA, GL_UNSIGNED_BYTE, img0.bits()); GL_CALL
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE); GL_CALL
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE); GL_CALL
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); GL_CALL
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); GL_CALL

  QImage img1(":/images/die2.png", "PNG");
  glBindTexture(GL_TEXTURE_2D, m_tex[1]); GL_CALL
  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, img1.width(), img1.height(), 0,
    GL_RGBA, GL_UNSIGNED_BYTE, img1.bits()); GL_CALL
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE); GL_CALL
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE); GL_CALL
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); GL_CALL
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); GL_CALL
}

void ProjectedRainbow2TexturedSquare::draw()
{
  glUseProgram(m_shaderProgram); GL_CALL
  glBindTexture(GL_TEXTURE_2D, 0); GL_CALL

  GLint posAttrib = glGetAttribLocation(m_shaderProgram, "position"); GL_CALL
  GLint colAttrib = glGetAttribLocation(m_shaderProgram, "color"); GL_CALL
  GLint texAttrib = glGetAttribLocation(m_shaderProgram, "texcoord"); GL_CALL

  glActiveTexture(GL_TEXTURE0); GL_CALL
  glBindTexture(GL_TEXTURE_2D, m_tex[0]); GL_CALL
  glUniform1i(glGetUniformLocation(m_shaderProgram, "die1"), 0);
  GL_CALL

  glActiveTexture(GL_TEXTURE1); GL_CALL
  glBindTexture(GL_TEXTURE_2D, m_tex[1]); GL_CALL
  glUniform1i(glGetUniformLocation(m_shaderProgram, "die2"), 1);
  GL_CALL

  glBindBuffer(GL_ARRAY_BUFFER, m_vbo); GL_CALL
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ebo); GL_CALL
  std::size_t stride = verts::traits::stride;

  std::size_t dimension1 = verts::datum_type::internal_type1::dimension;
  std::size_t byte_offset1 = verts::traits::type1_byte_offset;
  glEnableVertexAttribArray(posAttrib); GL_CALL
  glVertexAttribPointer(posAttrib, dimension1, GL_FLOAT, GL_FALSE,
    stride, (void*)byte_offset1); GL_CALL

  std::size_t dimension2 = verts::datum_type::internal_type2::dimension;
  std::size_t byte_offset2 = verts::traits::type2_byte_offset;
  glEnableVertexAttribArray(colAttrib); GL_CALL
  glVertexAttribPointer(colAttrib, dimension2, GL_FLOAT, GL_FALSE,
    stride, (void*)byte_offset2); GL_CALL

  std::size_t dimension3 = verts::datum_type::internal_type3::dimension;
  std::size_t byte_offset3 = verts::traits::type3_byte_offset;
  glEnableVertexAttribArray(texAttrib); GL_CALL
  glVertexAttribPointer(texAttrib, dimension3, GL_FLOAT, GL_FALSE,
    stride, (void*)byte_offset3); GL_CALL

  auto t_now = std::chrono::high_resolution_clock::now();
  float time = std::chrono::duration_cast<std::chrono::duration<float>>(
    t_now - m_start).count();
  opengl_math::matrix_4X4<float, opengl_math::column> model(
    opengl_math::identity);
  model = opengl_math::rotate_to<float, opengl_math::column>(model,
    (time * opengl_math::degrees_to_radians(180.0)),
    opengl_math::vector_3d<float>(0.0f, 0.0f, 1.0f), opengl_math::radians);
  opengl_math::matrix_4X4<float, opengl_math::column> view =
    opengl_math::look_at<float, opengl_math::column>(
      opengl_math::point_3d<float>(1.2f, 1.2f, 1.2f),
      opengl_math::point_3d<float>(0.0f, 0.0f, 0.0f),
      opengl_math::vector_3d<float>(0.0f, 0.0f, 1.0f));

  GLint uniMVP = glGetUniformLocation(m_shaderProgram, "mvp"); GL_CALL
  glUniformMatrix4fv(uniMVP, 1, GL_FALSE,
    (m_projection * view * model).to_gl_matrix()); GL_CALL

  glDrawElements(GL_TRIANGLES, m_indices.get_indices_count(),
    GL_UNSIGNED_INT, 0); GL_CALL

  glActiveTexture(GL_TEXTURE1); GL_CALL
  glBindTexture(GL_TEXTURE_2D, 0); GL_CALL
  glActiveTexture(GL_TEXTURE0); GL_CALL
  glBindTexture(GL_TEXTURE_2D, 0); GL_CALL
}

void ProjectedRainbow2TexturedSquare::destroy()
{
  if (glIsBuffer(m_vbo)) {
    glDeleteBuffers(1, &m_vbo); GL_CALL
  }

  if (glIsBuffer(m_ebo)) {
    glDeleteBuffers(1, &m_ebo); GL_CALL
  }

  if (glIsProgram(m_shaderProgram)) {
    glDeleteProgram(m_shaderProgram); GL_CALL
  }

  if (glIsShader(m_vertexShader)) {
    glDeleteShader(m_vertexShader); GL_CALL
  }

  if (glIsShader(m_fragmentShader)) {
    glDeleteShader(m_fragmentShader); GL_CALL
  }

  if (glIsTexture(m_tex[0])) {
    glDeleteTextures(1, &m_tex[0]); GL_CALL
  }

  if (glIsTexture(m_tex[1])) {
    glDeleteTextures(1, &m_tex[1]); GL_CALL
  }
}
