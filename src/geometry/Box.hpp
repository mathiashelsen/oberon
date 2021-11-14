#ifndef _BOX_HPP
#define _BOX_HPP

#include <vector>
#include <cmath>

#include "Volume.hpp"

#include "../material/Material.hpp"
#include "../particle/Particle.hpp"

class Box: public Volume
{
  protected:
    double x, y, z;
    double w_x, w_y, w_z;
  public:
                    Box       (double* pos, 
                               double* width, 
                                Material* material);
    bool            isInside  (double* pos);
    bool            isInside  (Particle* p);
    double          distance  (Particle* p);
    double*         getExtent ();
};

#endif
