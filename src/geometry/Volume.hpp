#ifndef _VOLUME_HPP
#define _VOLUME_HPP

#include <vector>

#include "../material/Material.hpp"

class Volume{
  protected:
    Material* _material;
  public:
    ~Volume () { ; };
    virtual bool isInside(std::vector<double>* x) = 0;
};

#endif
