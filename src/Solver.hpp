#ifndef _SOLVER_HPP
#define _SOLVER_HPP

#include <vector>
#include <random>

#include "geometry/Volume.hpp"
#include "particle/Particle.hpp"

class Solver
{
  protected:
    std::vector<Volume *>*    objects;
    Volume*                   simBox;
    std::vector<Particle *>*  particles;
    int N_max;
  public:
          Solver        (std::vector<Volume *>* _objects, Volume* simBox);
          ~Solver       ();
    void  initParticles (int N_init);
    void  runSimulation (int N_generations);
};

#endif
