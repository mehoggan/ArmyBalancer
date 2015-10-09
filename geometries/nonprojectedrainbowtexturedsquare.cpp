#include "geometries/nonprojectedrainbowtexturedsquare.h"

#include <QFile>
#include <QImage>
#include <QTextStream>
#include <QGLWidget>

#include <iostream>

NonProjectedRainbowTexturedSquare::NonProjectedRainbowTexturedSquare() :
  m_shaderProgram(0),
  m_vertexShader(0),
  m_fragmentShader(0),
  m_vbo(0),
  m_ebo(0),
  m_tex(0)
{}

NonProjectedRainbowTexturedSquare::~NonProjectedRainbowTexturedSquare()
{
  destroy();
}

void NonProjectedRainbowTexturedSquare::create()
{
  initializeOpenGLFunctions();

  QFile vshaderFile(":/nonprojectedrainbowtexturedsquare_vshader.glsl");
  if (!vshaderFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
    throw (std::string("Could not open ") +
      vshaderFile.fileName().toStdString()).c_str();
  }
  QTextStream vshaderStream(&vshaderFile);
  std::string vshaderSrc = vshaderStream.readAll().toStdString();

  QFile fshaderFile(":/nonprojectedrainbowtexturedsquare_fshader.glsl");
  if (!fshaderFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
    throw (std::string("Could not open ") +
      fshaderFile.fileName().toStdString()).c_str();
  }
  QTextStream fshaderStream(&fshaderFile);
  std::string fshaderSrc = fshaderStream.readAll().toStdString();

  glGenBuffers(1, &m_vbo);

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

  glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
  glBufferData(GL_ARRAY_BUFFER, bytes, m_vertexAttrib.get_data().get(),
    GL_STATIC_DRAW);

  glGenBuffers(1, &m_ebo);
  // Create indices
  opengl_graphics::indices<uint32_t>::collection_type indices(new uint32_t[6]);
  indices[0] = 0u; indices[1] = 1u; indices[2] = 2u;
  indices[3] = 2u; indices[4] = 3u; indices[5] = 0u;
  m_indices = opengl_graphics::indices<uint32_t>(indices, 6);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ebo);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, m_indices.get_byte_count(),
    m_indices.get_data().get(), GL_STATIC_DRAW);

  // Create and compile the vertex shader
  m_vertexShader = glCreateShader(GL_VERTEX_SHADER);
  const GLchar *vshaderRaw = vshaderSrc.c_str();
  glShaderSource(m_vertexShader, 1, &(vshaderRaw), NULL);
  glCompileShader(m_vertexShader);

  // Create and compile the fragment shader
  m_fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
  const GLchar *fshaderRaw = fshaderSrc.c_str();
  glShaderSource(m_fragmentShader, 1, &(fshaderRaw), NULL);
  glCompileShader(m_fragmentShader);

  // Link the vertex and fragment shader into a shader program
  m_shaderProgram = glCreateProgram();
  glAttachShader(m_shaderProgram, m_vertexShader);
  glAttachShader(m_shaderProgram, m_fragmentShader);
  glLinkProgram(m_shaderProgram);

  glGenTextures(1, &m_tex);
  glBindTexture(GL_TEXTURE_2D, m_tex);

  QImage img(":/die1.png", "PNG");
  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, img.width(), img.height(), 0, GL_RGBA,
    GL_UNSIGNED_BYTE, img.bits());

  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
}

void NonProjectedRainbowTexturedSquare::draw()
{
  glUseProgram(m_shaderProgram);

  GLint posAttrib = glGetAttribLocation(m_shaderProgram, "position");
  GLint colAttrib = glGetAttribLocation(m_shaderProgram, "color");
  GLint texAttrib = glGetAttribLocation(m_shaderProgram, "texcoord");

  glBindTexture(GL_TEXTURE_2D, m_tex);
  glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ebo);
  std::size_t stride = verts::traits::stride;

  std::size_t dimension1 = verts::datum_type::internal_type1::dimension;
  std::size_t byte_offset1 = verts::traits::type1_byte_offset;
  glEnableVertexAttribArray(posAttrib);
  glVertexAttribPointer(posAttrib, dimension1, GL_FLOAT, GL_FALSE,
    stride, (void*)byte_offset1);

  std::size_t dimension2 = verts::datum_type::internal_type2::dimension;
  std::size_t byte_offset2 = verts::traits::type2_byte_offset;
  glEnableVertexAttribArray(colAttrib);
  glVertexAttribPointer(colAttrib, dimension2, GL_FLOAT, GL_FALSE,
    stride, (void*)byte_offset2);

  std::size_t dimension3 = verts::datum_type::internal_type3::dimension;
  std::size_t byte_offset3 = verts::traits::type3_byte_offset;
  glEnableVertexAttribArray(texAttrib);
  glVertexAttribPointer(texAttrib, dimension3, GL_FLOAT, GL_FALSE,
    stride, (void*)byte_offset3);

  glDrawElements(GL_TRIANGLES, m_indices.get_indices_count(),
    GL_UNSIGNED_INT, 0);
  GLuint e;
  while ((e = glGetError()) != 0) {
    std::cout << e << std::endl;
  }
}

void NonProjectedRainbowTexturedSquare::destroy()
{
  if (glIsBuffer(m_vbo)) {
    glDeleteBuffers(1, &m_vbo);
  }

  if (glIsBuffer(m_ebo)) {
    glDeleteBuffers(1, &m_ebo);
  }

  if (glIsProgram(m_shaderProgram)) {
    glDeleteProgram(m_shaderProgram);
  }

  if (glIsShader(m_vertexShader)) {
    glDeleteShader(m_vertexShader);
  }

  if (glIsShader(m_fragmentShader)) {
    glDeleteShader(m_fragmentShader);
  }

  if (glIsTexture(m_tex)) {
    glDeleteTextures(1, &m_tex);
  }
}
