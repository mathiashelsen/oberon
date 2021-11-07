#ifndef _HEU_HPP
#define _HEU_HPP

#include "Material.hpp"

#include <iostream>

class HEU : public Material
{
  private:
    double sigma_F;
    double sigma_T;
  public:
                      HEU         ();
    double            getSigma_T  (double E);
    double            getSigma_F  (double E);
    t_reaction        getReaction (double rand);
    double            getFissionNeutrons(double E);
};

#endif
