#include <iostream>

#include "geometry/Vector.hpp"
#include "geometry/Sphere.hpp"
#include "geometry/Volume.hpp"

int main(int argc, char** argv)
{
  Vector* x = new Vector(0.0, 0.0, 0.0);
  Sphere* s = new Sphere(x, 1.0);

  if(s->isInside(x))
    std::cout << "The point was INSIDE" << std::endl;
  else
    std::cout << "The point was OUTSIDE" << std::endl;
   
  x->_z = 1.01;
  if(s->isInside(x))
    std::cout << "The point was INSIDE" << std::endl;
  else
    std::cout << "The point was OUTSIDE" << std::endl;

  delete x;
  return EXIT_SUCCESS;
}
