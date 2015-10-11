#include "geometries/nonprojectedwhitetriangle.h"
#include "mesh_types/batch_traits.h"

#include <QFile>
#include <QTextStream>

NonProjectedWhiteTriangle::NonProjectedWhiteTriangle() :
  m_shaderProgram(0),
  m_vertexShader(0),
  m_fragmentShader(0),
  m_vbo(0)
{}

NonProjectedWhiteTriangle::~NonProjectedWhiteTriangle()
{
  destroy();
}

void NonProjectedWhiteTriangle::create()
{
  initializeOpenGLFunctions();

  QFile vshaderFile(
    ":/shaders/nonprojectedwhitetriangle_vshader.glsl");
  if (!vshaderFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
    throw (std::string("Could not open ") +
      vshaderFile.fileName().toStdString()).c_str();
  }
  QTextStream vshaderStream(&vshaderFile);
  std::string vshaderSrc = vshaderStream.readAll().toStdString();

  QFile fshaderFile(
    ":/shaders/nonprojectedwhitetriangle_fshader.glsl");
  if (!fshaderFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
    throw (std::string("Could not open ") +
      fshaderFile.fileName().toStdString()).c_str();
  }
  QTextStream fshaderStream(&fshaderFile);
  std::string fshaderSrc = fshaderStream.readAll().toStdString();

  glGenBuffers(1, &m_vbo); GL_CALL

  verts::collection1_type data(new opengl_math::point_2d<float>[3]);
  data[0] = opengl_math::point_2d<float>(+0.0, +0.5);
  data[1] = opengl_math::point_2d<float>(+0.5, -0.5);
  data[2] = opengl_math::point_2d<float>(-0.5, -0.5);

  m_vertexAttrib = verts(data, 3);
  std::size_t bytes = m_vertexAttrib.get_bytecount_1();

  glBindBuffer(GL_ARRAY_BUFFER, m_vbo); GL_CALL
  glBufferData(GL_ARRAY_BUFFER, bytes, m_vertexAttrib.get_data1().get(),
    GL_STATIC_DRAW); GL_CALL

  // Create and compile the vertex shader
  m_vertexShader = glCreateShader(GL_VERTEX_SHADER);
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
}

void NonProjectedWhiteTriangle::draw()
{
  glUseProgram(m_shaderProgram); GL_CALL
  GLint posAttrib = glGetAttribLocation(m_shaderProgram, "position"); GL_CALL

  glBindBuffer(GL_ARRAY_BUFFER, m_vbo); GL_CALL
  glEnableVertexAttribArray(posAttrib); GL_CALL
  glVertexAttribPointer(posAttrib, verts::type1::dimension, GL_FLOAT,
    GL_FALSE, verts::batch_traits_t::stride, 0); GL_CALL

  glDrawArrays(GL_TRIANGLES, 0, m_vertexAttrib.get_attribute_count()); GL_CALL
}

void NonProjectedWhiteTriangle::destroy()
{
  if (glIsBuffer(m_vbo)) {
    glDeleteBuffers(1, &m_vbo); GL_CALL
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
