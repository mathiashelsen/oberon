#include <iostream>

#include <vector>
#include "geometry/Sphere.hpp"
#include "geometry/Box.hpp"
#include "geometry/Volume.hpp"
#include "material/Material.hpp"
#include "material/Vacuum.hpp"
#include "material/HEU.hpp"
#include "Solver.hpp"

int main(int argc, char** argv)
{
  double r = 8.0;
  Vacuum  vac;
  HEU     heu;

  double  pos[3];
  double  width[3];

  pos[0]    = 0.0;
  pos[1]    = 0.0;
  pos[2]    = 0.0;

  width[0]  = 3.0*r;
  width[1]  = 3.0*r;
  width[2]  = 3.0*r;


  Box     simBox(pos, width, (Material *)&vac); 
  Sphere  criticalMass(pos, r, (Material *)&heu);

  std::vector<Volume *> objects;
  objects.push_back(&criticalMass);

  Solver  simulator(&objects, &simBox);
  simulator.initParticles(10000);

  std::cout << r << "\t" << (4.0*M_PI/3.0*r*r*r*19.1)/1000.0 << "\t";
  simulator.runSimulation(100);

  return EXIT_SUCCESS;
}
