#ifndef _HEU_HPP
#define _HEU_HPP

#include "Material.hpp"

#include <iostream>

class HEU : public Material
{
  private:
  public:
    double            getSigma_T  (double E);
    t_reaction        getReaction (double rand);
    double            getFissionNeutrons(double E);
};

#endif
