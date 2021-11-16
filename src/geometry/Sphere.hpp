#ifndef _SPHERE_HPP
#define _SPHERE_HPP

#include "Volume.hpp"
#include "../material/Material.hpp"
#include "../particle/Particle.hpp"

#include <vector>

class Sphere : public Volume
{
  private:
    double x;
    double y;
    double z;
    double r;
  public:
    Sphere(double* pos , double r, Material *material);
    bool isInside(double* pos);
    bool isInside(Particle* p);
    double distance(Particle* p);
};

#endif
