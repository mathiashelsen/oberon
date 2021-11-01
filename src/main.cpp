#include <iostream>

#include <vector>
#include "geometry/Sphere.hpp"
#include "geometry/Volume.hpp"

int main(int argc, char** argv)
{
  std::vector<double> x = {0.0, 0.0, 0.0};
  Sphere* s = new Sphere(&x, 1.0);

  if(s->isInside(&x))
    std::cout << "The point was INSIDE" << std::endl;
  else
    std::cout << "The point was OUTSIDE" << std::endl;
   
  x[2] = 1.01;
  if(s->isInside(&x))
    std::cout << "The point was INSIDE" << std::endl;
  else
    std::cout << "The point was OUTSIDE" << std::endl;

  delete s;
  return EXIT_SUCCESS;
}
