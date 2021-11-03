#ifndef _SPHERE_HPP
#define _SPHERE_HPP

#include "Volume.hpp"
#include "../material/Material.hpp"
#include "../particle/Particle.hpp"

#include <vector>

class Sphere : public Volume
{
  private:
    double _x;
    double _y;
    double _z;
    double _r;
  public:
    Sphere(double* pos , double r, Material *material);
    bool isInside(double* pos);
    bool isInside(Particle* p);
};

#endif
