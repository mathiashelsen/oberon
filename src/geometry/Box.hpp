#ifndef _BOX_HPP
#define _BOX_HPP

#include <vector>
#include <cmath>

#include "Volume.hpp"

class Box: public Volume
{
  protected:
    double x, y, z;
    double w_x, w_y, w_z;
  public:
                    Box       (std::vector<double>* pos, 
                                std::vector<double>* width, 
                                Material* material);
    bool            isInside  (std::vector<double>* pos);
    vector<double>* getExtent ();
};

#endif
