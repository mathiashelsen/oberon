#include "Sphere.hpp"

Sphere::Sphere(double* pos, double r, Material *material)
{
  x = pos[0];
  y = pos[1];
  z = pos[2];
  r = r;

  _material = material;
}

bool Sphere::isInside(double* pos)
{
  double delta;

  delta = (pos[0] - x)*(pos[0] - x) + (pos[1] - y)*(pos[1] - y) + (pos[2] - z)*(pos[2] - z);

  if( delta < r*r )
    return true;
  else
    return false;
}


bool Sphere::isInside(Particle* p)
{
  double delta;

  delta = (p->x - x)*(p->x - x) + (p->y - y)*(p->y - y) + (p->z - z)*(p->z - z);

  if( delta < r*r )
    return true;
  else
    return false;
}

double Sphere::distance(Particle* p)
{
  double u, v, w;
  double x_0, y_0, z_0;
  double a, b, c;
  double t;
  double det;

  u    = p->u;
  v    = p->v;
  w    = p->w;
  x_0  = p->x;
  y_0  = p->y;
  z_0  = p->z;

  b    = 2.0*(u*(x_0 - x) + v*(y_0 - y) + w*(z_0 - z));
  c    = (x_0 - x)*(x_0 - x) + (y_0 - y)*(y_0 - y) + (z_0 - z)*(z_0 - z) - r*r;

  det  = b*b - 4.0*c;

  if(det < 0.0)
    return -1.0;


}
