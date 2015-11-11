#include "geometries/collision.h"

#include "matrices/type_matrix_4X4.h"

#include <iostream>

bool Collision::collide(const Ellipse &ellipse1, const Ellipse &ellipse2)
{
  opengl_math::matrix_4X4<float, opengl_math::column> e1Trans =
    ellipse1.getTransform();
  std::cout << e1Trans << std::endl;

  opengl_math::matrix_4X4<float, opengl_math::column> e2Trans =
    ellipse2.getTransform();
  std::cout << e2Trans << std::endl;
}
