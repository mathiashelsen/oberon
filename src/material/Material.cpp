#include "Material.hpp"

 virtual double      getSigma_T  (double E)
 {
  return 0.0;
 }

virtual t_reaction  getReaction (double rand)
{
  return Scattering;
}
