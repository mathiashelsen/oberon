#ifndef _VOLUME_HPP
#define _VOLUME_HPP

#include "Vector.hpp"

class Volume{
  public:
    virtual bool isInside(Vector *x) = 0;
};

#endif
