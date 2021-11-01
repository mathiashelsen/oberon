#ifndef _SPHERE_HPP
#define _SPHERE_HPP

#include "Volume.hpp"
#include "Vector.hpp"

class Sphere : public Volume
{
  private:
    double _x;
    double _y;
    double _z;
    double _r;
  public:
    Sphere(Vector* x, double r);
    bool isInside(Vector* x);
};

#endif
