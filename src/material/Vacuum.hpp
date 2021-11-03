#ifndef _VACUUM_HPP
#define _VACUUM_HPP

#include "Material.hpp"

class Vacuum: public Material
{
  public:
    double            getSigma_T  (double E)    { return 0; };
    t_reaction        getReaction (double rand) { return Scattering; };
};

#endif
