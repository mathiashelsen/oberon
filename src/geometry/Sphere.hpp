#ifndef _SPHERE_HPP
#define _SPHERE_HPP

#include "Volume.hpp"
#include <vector>

class Sphere : public Volume
{
  private:
    double _x;
    double _y;
    double _z;
    double _r;
  public:
    Sphere(std::vector<double>*pos , double r);
    bool isInside(std::vector<double>* pos);
};

#endif
