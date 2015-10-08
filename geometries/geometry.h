#ifndef GEOMETRY_H
#define GEOMETRY_H

#include <QtGui/QOpenGLFunctions>

class Geometry : public QOpenGLFunctions
{
public:
  virtual ~Geometry() {}
  virtual void create() = 0;
  virtual void draw() = 0;
  virtual void destroy() = 0;
};

#endif // GEOMETRY_H
