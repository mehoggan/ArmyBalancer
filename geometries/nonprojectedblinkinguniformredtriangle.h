#ifndef NONPROJECTEDBLINKINGUNIFORMREDTRIANGLE_H
#define NONPROJECTEDBLINKINGUNIFORMREDTRIANGLE_H

#include "geometries/geometry.h"

#include "mesh_types/batch_data.h"
#include "primitives/points/type_point_2d.h"

#include <chrono>
#include <ctime>

class NonProjectedBlinkingUniformRedTriangle : public Geometry
{
public:
  NonProjectedBlinkingUniformRedTriangle();
  ~NonProjectedBlinkingUniformRedTriangle();
  virtual void create();
  virtual void draw();
  virtual void destroy();

private:
  GLuint m_shaderProgram;
  GLuint m_vertexShader;
  GLuint m_fragmentShader;
  GLuint m_vbo;
  std::chrono::high_resolution_clock::time_point m_start;

  typedef opengl_graphics::batch_data<opengl_math::point_2d<float>> verts;
  verts m_vertexAttrib;
};

#endif // NONPROJECTEDBLINKINGUNIFORMREDTRIANGLE_H
