#ifndef NONPROJECTEDRAINBOW2TEXTUREDSQUARE_H
#define NONPROJECTEDRAINBOW2TEXTUREDSQUARE_H

#include "geometries/geometry.h"

#include "mesh_types/interleaved_data.h"
#include "mesh_types/datums/interleaved_datum_2d.h"
#include "mesh_types/indices.h"
#include "primitives/points/type_point_2d.h"
#include "primitives/colors/type_color_rgb.h"
#include "primitives/texcoords/type_texcoord_2d.h"

class NonProjectedRainbow2TexturedSquare : public Geometry
{
public:
  NonProjectedRainbow2TexturedSquare();
  ~NonProjectedRainbow2TexturedSquare();
  virtual void create();
  virtual void draw();
  virtual void destroy();

private:
  GLuint m_shaderProgram;
  GLuint m_vertexShader;
  GLuint m_fragmentShader;
  GLuint m_vbo;
  GLuint m_ebo;
  GLuint m_tex[2];

  typedef opengl_graphics::interleaved_data<opengl_math::point_2d<float>,
    opengl_math::color_rgb<float>, opengl_math::texcoord_2d<float>> verts;
  verts m_vertexAttrib;
  opengl_graphics::indices<uint32_t> m_indices;
};

#endif // NONPROJECTEDRAINBOWTEXTUREDSQUARE_H
