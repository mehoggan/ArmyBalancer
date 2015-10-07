#ifndef NONPROJECTEDWHITETRIANGLE_H
#define NONPROJECTEDWHITETRIANGLE_H

#include <geometries/geometry.h>

#include "mesh_types/batch_data.h"
#include "primitives/points/type_point_2d.h"

class NonProjectedWhiteTriangle : public Geometry
{
public:
  NonProjectedWhiteTriangle();
  ~NonProjectedWhiteTriangle();
  virtual void create();
  virtual void draw();
  virtual void destroy();

private:
  GLuint m_shaderProgram;
  GLuint m_vertexShader;
  GLuint m_fragmentShader;
  GLuint m_vbo;

  typedef opengl_graphics::batch_data<opengl_math::point_2d<float>> verts;
  verts m_vertexAttrib;
};

#endif // NONPROJECTEDWHITETRIANGLE_H
