#include "warscrollrelationsgraph.h"

#include <iostream>

const std::atomic_bool t{true};
const std::atomic_bool f{false};

WarScrollRelationsGraph::WarScrollRelationsGraph() :
  m_t(0),
  m_program(nullptr)
{
  m_draw = f;
  m_create = f;
  m_initialize = t;
}

WarScrollRelationsGraph::~WarScrollRelationsGraph()
{
  delete m_program;
  m_program = nullptr;
  m_initialize = t;

  m_draw = f;
  m_create = f;
}

void WarScrollRelationsGraph::renderBackground()
{
  m_program->bind();

  m_program->enableAttributeArray(0);

  float values[] = {-1, -1, 1, -1, -1, 1, 1, 1};
  m_program->setAttributeArray(0, GL_FLOAT, values, 2);
  m_program->setUniformValue("t", (float) m_t);
  qreal width = m_viewportSize.width();
  qreal height = m_viewportSize.height();
  glViewport(0, 0.1125 * height, width, height);
  glDisable(GL_DEPTH_TEST);
  glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
  m_program->disableAttributeArray(0);
  m_program->release();
}

void WarScrollRelationsGraph::renderGraph()
{
}

void WarScrollRelationsGraph::creatStaticData()
{
  initializeOpenGLFunctions();

  if (m_program) {
    delete m_program;
    m_program = nullptr;
  }

  m_program = new QOpenGLShaderProgram();
  m_program->addShaderFromSourceCode(QOpenGLShader::Vertex,
    "attribute highp vec4 vertices;"
    "varying highp vec2 coords;"
    "void main() {"
    "    gl_Position = vertices;"
    "    coords = vertices.xy;"
    "}");

  m_program->addShaderFromSourceCode(QOpenGLShader::Fragment,
    "uniform lowp float t;"
    "varying highp vec2 coords;"
    "void main() {"
    "  gl_FragColor = vec4(0.0, 0.0, 0.0, 0.4);"
    "}");

  m_program->bindAttributeLocation("vertices", 0);
  m_program->link();
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
  }

  if (m_create) {
    createGraph();
    m_create = f;
  }

  if (m_draw) {
    renderBackground();
    renderGraph();
  }
}

