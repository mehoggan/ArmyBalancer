#ifndef NONPROJECTEDRAINBOWTRIANGLE_H
#define NONPROJECTEDRAINBOWTRIANGLE_H

#include <geometries/geometry.h>

#include "mesh_types/interleaved_data.h"
#include "mesh_types/datums/interleaved_datum_2d.h"
#include "primitives/points/type_point_2d.h"
#include "primitives/colors/type_color_rgb.h"

class NonProjectedRainbowTriangle : public Geometry
{
public:
  NonProjectedRainbowTriangle();
  ~NonProjectedRainbowTriangle();
  virtual void create();
  virtual void draw();
  virtual void destroy();

private:
  GLuint m_shaderProgram;
  GLuint m_vertexShader;
  GLuint m_fragmentShader;
  GLuint m_vbo;

  typedef opengl_graphics::interleaved_data<
    opengl_graphics::interleaved_datum_2d<
      opengl_math::point_2d<float>,
      opengl_math::color_rgb<float>
    >
  > verts;
  verts m_vertexAttrib;
};

#endif // NONPROJECTEDRAINBOWTRIANGLE_H
