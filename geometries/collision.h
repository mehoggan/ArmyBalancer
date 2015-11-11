#ifndef COLLISION_H
#define COLLISION_H

#include "geometries/ellipse.h"

#include <cstdint>

class Collision
{
public:
  static bool collide(const Ellipse &ellipse1, const Ellipse &ellipse2);
};
#endif // COLLISION_H
