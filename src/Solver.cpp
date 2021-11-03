#include "Solver.hpp"

      Solver::Solver        (std::vector<Volume *>* objects, Box* simBox)
{
  _objects  = objects;
  _simBox   = simBox;
}

      Solver::~Solver       ()
{

}

void  Solver::initParticles (int N_init)
{
  int i;
  double pos[3];
  double *extent = _simBox->getExtent();
  bool    invalid;

  std::uniform_real_distribution<double> pdf_x(extent[0], extent[1]);
  std::uniform_real_distribution<double> pdf_y(extent[2], extent[3]);
  std::uniform_real_distribution<double> pdf_z(extent[4], extent[5]);

  for(i = 0; i < N_init; i++)
  {
    invalid = true;
    while(invalid)
    {
      pos[0] = pdf_x(RNG);
      pos[1] = pdf_y(RNG);
      pos[2] = pdf_z(RNG);
      
      std::vector<Volume *>::iterator it = _objects->begin();
      while(invalid && it != _objects->end())
      {
        invalid = !((*it)->isInside(pos));
        ++it;
      }
    }
    std::cout << pos[0] << "\t" << pos[1] << "\t" << pos[2] <<  std::endl;
  }

  delete extent;
}
