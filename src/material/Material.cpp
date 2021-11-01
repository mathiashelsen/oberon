#include "Material.hpp"

double      Material::getSigma_T  (double E)
 {
  return 0.0;
 }

t_reaction  Material::getReaction (double rand)
{
  return Scattering;
}
