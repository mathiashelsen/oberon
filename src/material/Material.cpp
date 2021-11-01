#include "Material.hpp"

double      Material::getSigma_T  (double E)
 {
  return 0.0;
 }

t_reaction  Material::getReaction (double rand)
{
  return Scattering;
}

std::vector<Particle*> Material::getFissionNeutrons(double rand)
{
  std::vector<Particle*> retVal;
  Particle* p = new Particle();
  retVal.push_back(p);

  return retVal;
}
