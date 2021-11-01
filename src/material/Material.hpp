#ifndef _MATERIAL_HPP
#define _MATERIAL_HPP


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
    double      getSigma_T  (double E);
    t_reaction  getReaction (double rand);
};

#endif