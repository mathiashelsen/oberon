#include "Sphere.hpp"

Sphere::Sphere(Vector* x, double r)
{
  _x = x->_x;
  _y = x->_y;
  _z = x->_z;
  _r = r;
}

bool Sphere::isInside(Vector* x)
{
  double delta;

  delta = (x->_x - _x)*(x->_x - _x) + (x->_y - _y)*(x->_y - _y) + (x->_z - _z)*(x->_z - _z);

  if( delta < _r*_r )
    return true;
  else
    return false;
}
