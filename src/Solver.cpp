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

  particles = new std::vector<Particle *>;

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
    Particle* p = new Particle;
    p->_x = pos[0];
    p->_y = pos[1];
    p->_z = pos[2];
    p->E  = 7.0e6;

    //std::cout << p->_x << "\t" << p->_y << "\t" << p->_z << std::endl;


    particles->push_back(p);
  }

  delete extent;
}

void  Solver::runSimulation(int N_generations)
{
  int n_begin = particles->size();
  int n_end   = n_begin;
  double k;
  std::vector<Particle*> *nextGenParticles;
  std::uniform_real_distribution<double> xi(0.0, 1.0);

  // Loop for N_generations
  for(int i = 0; i < N_generations; i++)
  {
     nextGenParticles = new std::vector<Particle *>;

    // Loop over all particles
    for(std::vector<Particle*>::iterator it = particles->begin(); it != particles->end(); ++it)
    {
      Particle* p = *it;
      // Do random walk until particle is absorbed or outside of simulation
      // free particle if it's finished
      bool active = true;
      while( active && _simBox->isInside(p) )
      {
        Material* mat;
        Volume* vol = NULL;

        // Find where is the particle
        for(std::vector<Volume *>::iterator itt = _objects->begin(); itt != _objects->end(); ++itt)
        {
          if( (*itt)->isInside(p) )
            vol = *itt;
          
        }

        double Sigma_T = 0.0;
        if(!vol)
        {
          //std::cout << "Could not determine medium!" << std::endl;
          //std::cout << "(" << p->_x << ", " << p->_y << ", " << p->_z << ")" << std::endl;
          active = false;
        }
        else
        {
          //std::cout << "Could determine medium." << std::endl;
          // Get the material
          mat = vol->_material;
          Sigma_T = mat->getSigma_T(p->E);
        }
           

        if(Sigma_T == 0)
        {
          //Entered a material where we dont scatter anymore, so the 
          //particle is lost. Technically you will want to check if it will
          //still interact with another object later
          active = false;
        }
        else
        {
          t_reaction reaction = mat->getReaction( xi(RNG) );

          switch(reaction)
          {
            case Scattering:
              this->scatter(p, Sigma_T);
              break;
            case Fission:
              this->fission(p, mat->getFissionNeutrons(p->E), nextGenParticles);
              break;
            case Absorption:
              active = false;
              break;
          }

        }
       }

      delete *it;
    }

    delete particles;

    particles = nextGenParticles;

    n_end     = particles->size();
    k       = (double) n_end / (double) n_begin;
    n_begin = n_end;
    std::cout << k << "\t" << n_end << std::endl;
  }
}

void    Solver::scatter(Particle* p, double Sigma_T)
{
  std::uniform_real_distribution<double> xi(0.0, 1.0);

  double d    = -log(xi(RNG))/Sigma_T;
  double u    = 2.0*xi(RNG) - 1.0;
  double xi2  = xi(RNG);
  double v    = sqrt(1.0-u*u)*cos(2.0*M_PI*xi2);
  double w    = sqrt(1.0-u*u)*sin(2.0*M_PI*xi2);

  p->_x = p->_x + d*u;
  p->_y = p->_y + d*v;
  p->_z = p->_z + d*w;
}

void    Solver::fission(Particle* p, double nu, std::vector<Particle *>* nextGen)
{
  double  nu_prime = floor(nu);
  int     nNewNeutrons = 0;
  std::uniform_real_distribution<double> xi(0.0, 1.0);

  if( xi(RNG) < (nu - nu_prime) )
    nNewNeutrons = (int) nu_prime + 1;
  else
    nNewNeutrons = (int) nu_prime;

  for(int i = 0; i < nNewNeutrons; i++)
  {
    Particle* p_prime = new Particle;
    p_prime->_x = p->_x;
    p_prime->_y = p->_y;
    p_prime->_z = p->_z;

    // Watts spectrum normally
    p_prime->E = 7.0e6;

    nextGen->push_back(p_prime);
  }
}
