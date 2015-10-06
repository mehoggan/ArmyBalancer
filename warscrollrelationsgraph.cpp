#include "warscrollrelationsgraph.h"

#include <QDebug>

#include <iostream>

#include "core/platform.h"
#include "mesh_types/batch_data.h"
#include "primitives/points/type_point_2d.h"

#if __OPENGL_CORE_WINDOWS__
const std::atomic_bool t{true};
const std::atomic_bool f{false};
#else
const bool t = true;
const bool f = false;
#endif

struct VertexData
{
  QVector3D position;
  QVector2D texCoord;
};

WarScrollRelationsGraph::WarScrollRelationsGraph() :
  m_shaderProgram(0),
  m_vbo(0)
{
  m_draw = f;
  m_create = f;
  m_initialize = t;
}

WarScrollRelationsGraph::~WarScrollRelationsGraph()
{
  m_initialize = f;
  m_draw = f;
  m_create = f;

  if (glIsBuffer(m_vbo)) {
    glDeleteBuffers(1, &m_vbo);
  }
}

void WarScrollRelationsGraph::setViewportSize(const QSize &size)
{
  m_viewportSize = size;
}

void WarScrollRelationsGraph::creatStaticData()
{
  initializeOpenGLFunctions();
  QFile vshaderFile(":/colorsquare_vshader.glsl");
  if (!vshaderFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
    throw (std::string("Could not open ") +
      vshaderFile.fileName().toStdString()).c_str();
  }
  QTextStream vshaderStream(&vshaderFile);
  std::string vshaderSrc = vshaderStream.readAll().toStdString();

  QFile fshaderFile(":/colorsquare_fshader.glsl");
  if (!fshaderFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
    throw (std::string("Could not open ") +
      fshaderFile.fileName().toStdString()).c_str();
  }
  QTextStream fshaderStream(&fshaderFile);
  std::string fshaderSrc = fshaderStream.readAll().toStdString();

  glGenBuffers(1, &m_vbo);

  typedef opengl_graphics::batch_data<opengl_math::point_2d<float>> verts;
  verts::collection1_type data(new opengl_math::point_2d<float>[3]);
  data[0] = opengl_math::point_2d<float>(+0.0, +0.5);
  data[1] = opengl_math::point_2d<float>(+0.5, -0.5);
  data[2] = opengl_math::point_2d<float>(-0.5, -0.5);

  verts vertices(data, 3);
  std::size_t bytes = vertices.get_bytecount_1();

  glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
  glBufferData(GL_ARRAY_BUFFER, bytes, vertices.get_data1().get(),
    GL_STATIC_DRAW);

  // Create and compile the vertex shader
  GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
  const GLchar *vshaderRaw = vshaderSrc.c_str();
  glShaderSource(vertexShader, 1, &(vshaderRaw), NULL);
  glCompileShader(vertexShader);

  // Create and compile the fragment shader
  GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
  const GLchar *fshaderRaw = fshaderSrc.c_str();
  glShaderSource(fragmentShader, 1, &(fshaderRaw), NULL);
  glCompileShader(fragmentShader);

  // Link the vertex and fragment shader into a shader program
  m_shaderProgram = glCreateProgram();
  glAttachShader(m_shaderProgram, vertexShader);
  glAttachShader(m_shaderProgram, fragmentShader);
  glLinkProgram(m_shaderProgram);
}

void WarScrollRelationsGraph::createGraph()
{
}

void WarScrollRelationsGraph::setGraph(WarScrollSynergyGraph &graph)
{
  std::lock_guard<std::mutex> lock(m_graphMutex);
  m_graph = &graph;
  m_create = t;
}

void WarScrollRelationsGraph::paint()
{
  if (m_initialize) {
    creatStaticData();
    m_initialize = f;
  } else {
    int x = 0; x = x;
  }

  if (m_create) {
    createGraph();
    m_create = f;
  }

  if (m_draw) {
    renderGraph();
  }
}

void WarScrollRelationsGraph::renderGraph()
{
  qreal width = m_viewportSize.width();
  qreal height = m_viewportSize.height();
  glViewport(0, 0.1125 * height, width, height);
  glDisable(GL_DEPTH_TEST);

  glBindBuffer(GL_ARRAY_BUFFER, m_vbo);

  glUseProgram(m_shaderProgram);
  GLint posAttrib = glGetAttribLocation(m_shaderProgram, "position");
  glEnableVertexAttribArray(posAttrib);
  glVertexAttribPointer(posAttrib, 2, GL_FLOAT, GL_FALSE, 0, 0);

  glDrawArrays(GL_TRIANGLES, 0, 3);
}
