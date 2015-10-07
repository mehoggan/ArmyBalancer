#include "geometries/nonprojectedrainbowtriangle.h"

#include <QFile>
#include <QTextStream>

NonProjectedRainbowTriangle::NonProjectedRainbowTriangle() :
  m_shaderProgram(0),
  m_vertexShader(0),
  m_fragmentShader(0),
  m_vbo(0)
{}

NonProjectedRainbowTriangle::~NonProjectedRainbowTriangle()
{
  destroy();
}

void NonProjectedRainbowTriangle::create()
{
  initializeOpenGLFunctions();

  QFile vshaderFile(":/nonprojectedrainbowtriangle_vshader.glsl");
  if (!vshaderFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
    throw (std::string("Could not open ") +
      vshaderFile.fileName().toStdString()).c_str();
  }
  QTextStream vshaderStream(&vshaderFile);
  std::string vshaderSrc = vshaderStream.readAll().toStdString();

  QFile fshaderFile(":/nonprojectedrainbowtriangle_fshader.glsl");
  if (!fshaderFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
    throw (std::string("Could not open ") +
      fshaderFile.fileName().toStdString()).c_str();
  }
  QTextStream fshaderStream(&fshaderFile);
  std::string fshaderSrc = fshaderStream.readAll().toStdString();

  glGenBuffers(1, &m_vbo);

  GLfloat vertices[] = {
    +0.0f, +0.5f, +1.0f, +0.0f, +0.0f,
    +0.5f, -0.5f, +0.0f, +1.0f, +0.0f,
    -0.5f, -0.5f, +0.0f, +0.0f, +1.0f
  };

  glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

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

void NonProjectedRainbowTriangle::draw()
{
  glUseProgram(m_shaderProgram);

  GLint posAttrib = glGetAttribLocation(m_shaderProgram, "position");
  GLint colAttrib = glGetAttribLocation(m_shaderProgram, "color");

  glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
  glEnableVertexAttribArray(posAttrib);
  glVertexAttribPointer(posAttrib, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat),
    0);
  glEnableVertexAttribArray(colAttrib);
  glVertexAttribPointer(colAttrib, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat),
    (void*)(2 * sizeof(GLfloat)));

  glDrawArrays(GL_TRIANGLES, 0, 3);
}

void NonProjectedRainbowTriangle::destroy()
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
