#ifndef GEOMETRY_H
#define GEOMETRY_H

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
  virtual void create() = 0;
  virtual void draw() = 0;
  virtual void destroy() = 0;
};

#endif // GEOMETRY_H
