#ifndef _SOLVER_HPP
#define _SOLVER_HPP

#include <vector>
#include <random>
#include <iostream>

#include "geometry/Volume.hpp"
#include "geometry/Box.hpp"
#include "particle/Particle.hpp"

class Solver
{
  protected:
    std::vector<Volume *>*    _objects;
    Box*                      _simBox;
    std::vector<Particle *>*  particles;
    std::mt19937              RNG;
    int N_max;
  public:
          Solver          (std::vector<Volume *>* objects, Box* simBox);
          ~Solver         ();
    void  initParticles   (int N_init);
    void  runSimulation   (int N_generations);
    void  scatter         (Particle* p, double Sigma_T);
    void  fission         (Particle* p, double nu, std::vector<Particle *>* nextGen);
};

#endif
