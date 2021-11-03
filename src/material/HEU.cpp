#include "HEU.hpp"

            HEU::HEU()
{
  sigma_F = 1.0;
  sigma_T = 10.0;
}

double      HEU::getSigma_T (double E)
{
  // sigma = 10 barns
  // rho = 19.1 g/cm^3
  return (sigma_T*1.0e-24 * 6.022e23 * 19.1 / 235.0);
}

t_reaction  HEU::getReaction (double rand)
{

  if(rand > (sigma_F / sigma_T))
    return Scattering;
  else
    return Fission;
}

double      HEU::getFissionNeutrons(double E)
{
  // Subtract 1 because the current neutron remains alive
  return (2.497 - 1.0);
}
