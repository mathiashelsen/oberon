#include "Material.hpp"

double      Material::getSigma_T  (double E)
 {
  return 0.0;
 }

double      Material::getSigma_F  (double E)
 {
  return 0.0;
 }

t_reaction  Material::getReaction (double rand)
{
  return Scattering;
}

double      Material::getFissionNeutrons(double E)
{
  return 0.0;
}
