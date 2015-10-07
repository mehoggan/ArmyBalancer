#include "nonprojectedblinkinguniformredtriangle.h"

#include <QFile>
#include <QTextStream>

NonProjectedBlinkingUniformRedTriangle::
NonProjectedBlinkingUniformRedTriangle() :
  m_shaderProgram(0),
  m_vertexShader(0),
  m_fragmentShader(0),
  m_vbo(0),
  m_start(std::chrono::high_resolution_clock::now())
{}

NonProjectedBlinkingUniformRedTriangle::
~NonProjectedBlinkingUniformRedTriangle()
{
  destroy();
}

void NonProjectedBlinkingUniformRedTriangle::create()
{
  initializeOpenGLFunctions();

  QFile vshaderFile(":/nonprojectedblinkinguniformredtriangle_vshader.glsl");
  if (!vshaderFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
    throw (std::string("Could not open ") +
      vshaderFile.fileName().toStdString()).c_str();
  }
  QTextStream vshaderStream(&vshaderFile);
  std::string vshaderSrc = vshaderStream.readAll().toStdString();

  QFile fshaderFile(":/nonprojectedblinkinguniformredtriangle_fshader.glsl");
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

void NonProjectedBlinkingUniformRedTriangle::draw()
{
  glUseProgram(m_shaderProgram);

  GLint uniColor = glGetUniformLocation(m_shaderProgram, "triangleColor");
  auto t_now = std::chrono::high_resolution_clock::now();
  float time = std::chrono::duration_cast<std::chrono::duration<float>>(
    t_now - m_start).count();
  float alpha = (sin(time * 4.0f) + 1.0f) / 2.0f;
  glUniform4f(uniColor, 1.0f, 0.0f, 0.0f, alpha);
  GLint posAttrib = glGetAttribLocation(m_shaderProgram, "position");

  glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
  glEnableVertexAttribArray(posAttrib);
  glVertexAttribPointer(posAttrib, 2, GL_FLOAT, GL_FALSE, 0, 0);

  glDrawArrays(GL_TRIANGLES, 0, m_vertexAttrib.get_attribute_count());
}

void NonProjectedBlinkingUniformRedTriangle::destroy()
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


