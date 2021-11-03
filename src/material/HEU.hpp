#ifndef _HEU_HPP
#define _HEU_HPP

#include "Material.hpp"

class HEU : public Material
{
  public:
    double            getSigma_T  (double E)    { return 0; };
    t_reaction        getReaction (double rand) { return Scattering; };
};

#endif
