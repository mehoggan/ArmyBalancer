#include "geometries/nonprojectedwhitetriangle.h"

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

  QFile vshaderFile(":/nonprojectedwhitetriangle_vshader.glsl");
  if (!vshaderFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
    throw (std::string("Could not open ") +
      vshaderFile.fileName().toStdString()).c_str();
  }
  QTextStream vshaderStream(&vshaderFile);
  std::string vshaderSrc = vshaderStream.readAll().toStdString();

  QFile fshaderFile(":/nonprojectedwhitetriangle_fshader.glsl");
  if (!fshaderFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
    throw (std::string("Could not open ") +
      fshaderFile.fileName().toStdString()).c_str();
  }
  QTextStream fshaderStream(&fshaderFile);
  std::string fshaderSrc = fshaderStream.readAll().toStdString();

  glGenBuffers(1, &m_vbo);

  verts::collection1_type data(new opengl_math::point_2d<float>[3]);
  data[0] = opengl_math::point_2d<float>(+0.0, +0.5);
  data[1] = opengl_math::point_2d<float>(+0.5, -0.5);
  data[2] = opengl_math::point_2d<float>(-0.5, -0.5);

  m_vertexAttrib = verts(data, 3);
  std::size_t bytes = m_vertexAttrib.get_bytecount_1();

  glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
  glBufferData(GL_ARRAY_BUFFER, bytes, m_vertexAttrib.get_data1().get(),
    GL_STATIC_DRAW);

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
}

void NonProjectedWhiteTriangle::draw()
{
  glBindBuffer(GL_ARRAY_BUFFER, m_vbo);

  glUseProgram(m_shaderProgram);
  GLint posAttrib = glGetAttribLocation(m_shaderProgram, "position");
  glEnableVertexAttribArray(posAttrib);
  glVertexAttribPointer(posAttrib, 2, GL_FLOAT, GL_FALSE, 0, 0);

  glDrawArrays(GL_TRIANGLES, 0, 3);
}

void NonProjectedWhiteTriangle::destroy()
{
  if (glIsBuffer(m_vbo)) {
    glDeleteBuffers(1, &m_vbo);
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
}
