#ifndef _SOLVER_HPP
#define _SOLVER_HPP

#include <vector>
#include <random>

#include "geometry/Volume.hpp"

class Solver
{
  protected:
    vector<Volume *>    objects;
    vector<Particle *>  particles;
};

#endif
