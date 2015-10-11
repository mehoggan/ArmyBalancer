#include "geometries/nonprojectedrainbowsquare.h"

#include <QFile>
#include <QTextStream>

#include <iostream>

NonProjectedRainbowSquare::NonProjectedRainbowSquare() :
  m_shaderProgram(0),
  m_vertexShader(0),
  m_fragmentShader(0),
  m_vbo(0),
  m_ebo(0)
{}

NonProjectedRainbowSquare::~NonProjectedRainbowSquare()
{
  destroy();
}

void NonProjectedRainbowSquare::create()
{
  initializeOpenGLFunctions();

  QFile vshaderFile(
    ":/shaders/nonprojectedrainbowsquare_vshader.glsl");
  if (!vshaderFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
    throw (std::string("Could not open ") +
      vshaderFile.fileName().toStdString()).c_str();
  }
  QTextStream vshaderStream(&vshaderFile);
  std::string vshaderSrc = vshaderStream.readAll().toStdString();

  QFile fshaderFile(
    ":/shaders/nonprojectedrainbowsquare_fshader.glsl");
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
    opengl_math::color_rgb<float>(+1.0f, +0.0f, +0.0f));
  data[1] = verts::datum_type(
    opengl_math::point_2d<float>(+0.5f, +0.5f),
    opengl_math::color_rgb<float>(+0.0f, +1.0f, +0.0f));
  data[2] = verts::datum_type(
    opengl_math::point_2d<float>(+0.5f, -0.5f),
    opengl_math::color_rgb<float>(+0.0f, +0.0f, +1.0f));
  data[3] = verts::datum_type(
    opengl_math::point_2d<float>(-0.5f, -0.5f),
    opengl_math::color_rgb<float>(+1.0f, +1.0f, +1.0f));
  m_vertexAttrib = verts(data, 4);

  std::size_t bytes = m_vertexAttrib.get_byte_count();

  glBindBuffer(GL_ARRAY_BUFFER, m_vbo); GL_CALL
  glBufferData(GL_ARRAY_BUFFER, bytes, m_vertexAttrib.get_data().get(),
    GL_STATIC_DRAW); GL_CALL

  glGenBuffers(1, &m_ebo);
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
  m_fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
  const GLchar *fshaderRaw = fshaderSrc.c_str();
  glShaderSource(m_fragmentShader, 1, &(fshaderRaw), NULL); GL_CALL
  glCompileShader(m_fragmentShader); GL_CALL

  // Link the vertex and fragment shader into a shader program
  m_shaderProgram = glCreateProgram(); GL_CALL
  glAttachShader(m_shaderProgram, m_vertexShader); GL_CALL
  glAttachShader(m_shaderProgram, m_fragmentShader); GL_CALL
  glLinkProgram(m_shaderProgram); GL_CALL
}

void NonProjectedRainbowSquare::draw()
{
  glUseProgram(m_shaderProgram); GL_CALL

  GLint posAttrib = glGetAttribLocation(m_shaderProgram, "position"); GL_CALL
  GLint colAttrib = glGetAttribLocation(m_shaderProgram, "color"); GL_CALL

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

  glDrawElements(GL_TRIANGLES, m_indices.get_indices_count(),
    GL_UNSIGNED_INT, 0); GL_CALL
}

void NonProjectedRainbowSquare::destroy()
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
}
