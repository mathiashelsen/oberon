#include "HEU.hpp"

double      HEU::getSigma_T (double E)
{
  // sigma = 10 barns
  // rho = 19.1 g/cm^3
  return (10.0*1.0e-24 * 6.022e23 * 19.1 / 235.0);
}

t_reaction  HEU::getReaction (double rand)
{
  double sigma_T = 10.0;
  double sigma_F = 1.0;

  if(rand > (sigma_F / sigma_T))
    return Scattering;
  else
    return Fission;
}

double      HEU::getFissionNeutrons(double E)
{
  // Subtract 1 because the current neutron remains alive
  return (4.497 - 1.0);
}
