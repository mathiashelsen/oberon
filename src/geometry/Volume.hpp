#ifndef _VOLUME_HPP
#define _VOLUME_HPP

#include <vector>

#include "../material/Material.hpp"
#include "../particle/Particle.hpp"

class Volume{
  public:
    Material* _material;
    ~Volume         () { ; };
    virtual bool    isInside(double* x) = 0;
    virtual bool    isInside(Particle* p) = 0;
    virtual double  distance(Particle* p) = 0;
};

#endif
