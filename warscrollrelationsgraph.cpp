#include "warscrollrelationsgraph.h"

#include <iostream>

WarScrollRelationsGraph::WarScrollRelationsGraph() :
  m_draw(false),
  m_t(0),
  m_program(0)
{}

WarScrollRelationsGraph::~WarScrollRelationsGraph()
{
  delete m_program;
}

void WarScrollRelationsGraph::paint()
{
  if (!m_program) {
    initializeOpenGLFunctions();

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

  if (m_draw) {
    m_program->bind();

    m_program->enableAttributeArray(0);

    float values[] = {
      -1, -1,
      1, -1,
      -1, 1,
      1, 1
    };
    m_program->setAttributeArray(0, GL_FLOAT, values, 2);
    m_program->setUniformValue("t", (float) m_t);

    qreal width = m_viewportSize.width();
    qreal height = m_viewportSize.height();

    glViewport(0, 0.10 * height, width, height);

    glDisable(GL_DEPTH_TEST);

    glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

    m_program->disableAttributeArray(0);
    m_program->release();
  }
}

