#ifndef _VOLUME_HPP
#define _VOLUME_HPP

#include <vector>

#include "../material/Material.hpp"

class Volume{
  protected:
    Material* _material;
  public:
    ~Volume () { ; };
    virtual bool isInside(double* x) = 0;
};

#endif
