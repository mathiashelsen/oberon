#include "Sphere.hpp"

Sphere::Sphere(std::vector<double>* pos, double r)
{
  _x = (*pos)[0];
  _y = (*pos)[1];
  _z = (*pos)[2];
  _r = r;
}

bool Sphere::isInside(std::vector<double>* pos)
{
  double delta;

  delta = ((*pos)[0] - _x)*((*pos)[0] - _x) + ((*pos)[1] - _y)*((*pos)[1] - _y) + ((*pos)[2] - _z)*((*pos)[2] - _z);

  if( delta < _r*_r )
    return true;
  else
    return false;
}
