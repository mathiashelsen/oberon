#include "Sphere.hpp"

Sphere::Sphere(double* pos, double r, Material *material)
{
  _x = pos[0];
  _y = pos[1];
  _z = pos[2];
  _r = r;

  _material = material;
}

bool Sphere::isInside(double* pos)
{
  double delta;

  delta = (pos[0] - _x)*(pos[0] - _x) + (pos[1] - _y)*(pos[1] - _y) + (pos[2] - _z)*(pos[2] - _z);

  if( delta < _r*_r )
    return true;
  else
    return false;
}


bool Sphere::isInside(Particle* p)
{
  double delta;

  delta = (p->_x - _x)*(p->_x - _x) + (p->_y - _y)*(p->_y - _y) + (p->_z - _z)*(p->_z - _z);

  if( delta < _r*_r )
    return true;
  else
    return false;
}
