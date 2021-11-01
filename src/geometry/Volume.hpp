#ifndef _VOLUME_HPP
#define _VOLUME_HPP

#include <vector>

class Volume{
  public:
    ~Volume () { ; };
    virtual bool isInside(std::vector<double>* x) = 0;
};

#endif
