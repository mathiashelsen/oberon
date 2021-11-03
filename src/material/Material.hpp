#ifndef _MATERIAL_HPP
#define _MATERIAL_HPP

#include "../particle/Particle.hpp"

#include <vector>

// The possible interaction a neutron can undergo with the material
typedef enum
{
  Scattering,
  Absorption,
  Fission
} t_reaction;


// Specific materials will extend this base class
class Material
{
  private:
    double nuclideDensity;
  public:
    virtual double      getSigma_T  (double E);
    virtual t_reaction  getReaction (double rand);
    virtual double      getFissionNeutrons(double E);
};

#endif
