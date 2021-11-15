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
  //double r = 8.0;
  Vacuum  vac;
  //HEU     heu;

  double  pos[3];
  double  width[3];

  pos[0]    = 0.0;
  pos[1]    = 0.0;
  pos[2]    = 0.0;

  width[0]  = 2.0;
  width[1]  = 2.0;
  width[2]  = 2.0;

  Particle p;
  p.x = 0.0;
  p.y = 0.0;
  p.z = 0.0;

  p.u = 0.0;
  p.v = 0.0;
  p.w = 1.0;


  Box     simBox(pos, width, (Material *)&vac); 

  std::cout << "d_0 = " << simBox.distance(&p) << std::endl;
  p.v = 0.7;
  p.w = 0.7;
  std::cout << "d_1 = " << simBox.distance(&p) << std::endl;
  p.v = 0.8;
  std::cout << "d_2 = " << simBox.distance(&p) << std::endl;

  p.v = 0.0;
  p.x = 2.2;
  std::cout << "d_3 = " << simBox.distance(&p) << std::endl;

  p.x = 0.0;
  p.z = -2.0;
  std::cout << "d_4 = " << simBox.distance(&p) << std::endl;

  p.v = 0.7;
  std::cout << "d_5 = " << simBox.distance(&p) << std::endl;

  p.v = 0.72;
  std::cout << "d_6 = " << simBox.distance(&p) << std::endl;
  //Sphere  criticalMass(pos, r, (Material *)&heu);

  //std::vector<Volume *> objects;
  //objects.push_back(&criticalMass);

  //Solver  simulator(&objects, &simBox);
  //simulator.initParticles(10000);

  //std::cout << r << "\t" << (4.0*M_PI/3.0*r*r*r*19.1)/1000.0 << "\t";
  //simulator.runSimulation(100);

  return EXIT_SUCCESS;
}
