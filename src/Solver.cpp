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

void  Solver::runSimulation(int N_generations)
{
  int n_begin = particles->size();
  int n_end   = n_begin;
  double k;
  std::vector<Particle*> *nextGenParticles;

  // Loop for N_generations
  for(int i = 0; i < N_generations; i++)
  {
     nextGenParticles = new std::vector<Particle *>;

    // Loop over all particles
    for(std::vector<Particle*>::iterator it = particles->begin(); it != particles->end(); ++it)
    {
      // Do random walk until particle is absorbed or outside of simulation
      // free particle if it's finished
      while( *it )
      {
        //Diffuse...
        //
        //Fission...
        //
        // ...
       
        // When done...
        delete *it;
        *it = NULL;
       }
    }

    delete particles;

    particles = nextGenParticles;

    n_end     = particles->size();
    k       = n_end / n_begin;
    n_begin = n_end;
    std::cout << "Generation " << i << ", k = " << k << std::endl;
  }
}
