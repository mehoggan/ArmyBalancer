#ifndef GEOMETRY_H
#define GEOMETRY_H

#include "matrices/type_matrix_4X4.h"

#include <QtGui/QOpenGLFunctions>

#include <iostream>

#define GL_CALL do { \
    GLint error; \
    while ((error = glGetError()) != 0) { \
      std::cout << __LINE__ << " " << __FUNCTION__ << " " << error << \
        std::endl; \
    } \
  } while(false);

class Geometry : public QOpenGLFunctions
{
public:
  virtual ~Geometry() {}
  virtual void setProjection(
    const opengl_math::matrix_4X4<float, opengl_math::column> &projection) = 0;
  virtual void create() = 0;
  virtual void draw() = 0;
  virtual void destroy() = 0;
};

#endif // GEOMETRY_H
