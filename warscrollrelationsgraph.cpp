﻿#include "warscrollrelationsgraph.h"

#include <iostream>

WarScrollRelationsGraph::WarScrollRelationsGraph() :
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
      "  lowp float i = 1. - (pow(abs(coords.x), 4.) + pow(abs(coords.y), 4.));"
      "  i = smoothstep(t - 0.8, t + 0.8, i);"
      "  i = floor(i * 20.) / 20.;"
      "  gl_FragColor = vec4(coords * .5 + .5, i, i);"
      "}");

    m_program->bindAttributeLocation("vertices", 0);
    m_program->link();
  }

/*
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
*/
  qreal width = m_viewportSize.width();
  qreal height = m_viewportSize.height();

  glViewport(0, 0, width, height);

  glDisable(GL_DEPTH_TEST);

  glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT);
/*
  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE);

  glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

  m_program->disableAttributeArray(0);
  m_program->release();
*/
}
