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
  Vacuum  vac;
  HEU     heu;

  double  pos[3];
  double  width[3];

  pos[0]    = 0.0;
  pos[1]    = 0.0;
  pos[2]    = 0.0;

  width[0]  = 1.0;
  width[1]  = 1.0;
  width[2]  = 1.0;


  Box     simBox(pos, width, (Material *)&vac); 
  Sphere  criticalMass(pos, 0.25, (Material *)&heu);

  std::vector<Volume *> objects;
  objects.push_back(&criticalMass);

  Solver  simulator(&objects, &simBox);
  simulator.initParticles(100000);

  return EXIT_SUCCESS;
}
