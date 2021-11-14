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
      pos[0] = 0.0; //pdf_x(RNG);
      pos[1] = 0.0; //pdf_y(RNG);
      pos[2] = 0.0; //pdf_z(RNG);
      
      std::vector<Volume *>::iterator it = _objects->begin();
      while(invalid && it != _objects->end())
      {
        invalid = !((*it)->isInside(pos));
        ++it;
      }
    }
    Particle* p = new Particle;
    p->x = pos[0];
    p->y = pos[1];
    p->z = pos[2];
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
  double k = 1.0;
  std::vector<Particle*> *nextGenParticles;
  std::uniform_real_distribution<double> xi(0.0, 1.0);
  double sTotal = 0.0;
  int    cTotal = 0;

  // Loop for N_generations
  for(int i = 0; i < N_generations; i++)
  {
     nextGenParticles = new std::vector<Particle *>;
     ctr = 0;
     sTotal = 0.0;
     cTotal = 0;

    // Loop over all particles
    for(std::vector<Particle*>::iterator it = particles->begin(); it != particles->end(); ++it)
    {
      Particle* p = *it;
      // Do random walk until particle is absorbed or outside of simulation
      // free particle if it's finished
      bool particleAlive = true;
      while(particleAlive)
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
          particleAlive = false;
        }
        else
        {
          //std::cout << "Could determine medium." << std::endl;
          // Get the material
          mat = vol->_material;

          // Maybe move this to the end of the routine so we only have to
          // check once were the particle is
          Sigma_T = mat->getSigma_T(p->E);
          double d = this->scatter(p, Sigma_T);
          sTotal += d;
          // All pathlength tallies go here

          // Basically, we have to check were the particle is again... boring
          if(vol->isInside(p))
          {
            t_reaction reaction = mat->getReaction( xi(RNG) );
            // All collision tallies go here

            cTotal++;

            switch(reaction)
            {
              case Scattering:
                break;
              case Fission:
                this->fission(p, mat->getFissionNeutrons(p->E), nextGenParticles);
                //particleAlive = false;
                break;
              case Absorption:
                particleAlive = false;
                break;
            }
          }
          else
          {
            //Scattered the particle outside
            particleAlive = false;
          }
        }
      }
      delete p;
    }

    n_begin   = particles->size();

    delete particles;

    particles = nextGenParticles;

    n_end     = particles->size();

    k       = (double) n_end / (double) n_begin;


    //std::cout << std::endl << "k = \t" << k << "\t" << k_hat << "\t" << k_hat2 << "\t" << n_end << std::endl;
    //std::cout << n_end << "\t" << k << std::endl;
  }

  k       = (double) n_end / (double) n_begin;
    double k_hat = (sTotal * 2.42 * 0.06422619315744) / (double) n_begin;

    double k_hat2 = 2.42 * 0.1927571778 * (double)cTotal / (double) n_begin;

    std::cout << std::endl << "k = \t" << k << "\t" << k_hat << "\t" << k_hat2 << "\t" << n_end << std::endl;

  n_begin = n_end;

}

double  Solver::scatter(Particle* p, double Sigma_T)
{
  std::uniform_real_distribution<double> xi(0.0, 1.0);

  double d    = -log(xi(RNG))/Sigma_T;
  double u    = 2.0*xi(RNG) - 1.0;
  double xi2  = xi(RNG);
  double v    = sqrt(1.0-u*u)*cos(2.0*M_PI*xi2);
  double w    = sqrt(1.0-u*u)*sin(2.0*M_PI*xi2);

  p->u = u;
  p->v = v;
  p->w = w;

  p->x = p->x + d*u;
  p->y = p->y + d*v;
  p->z = p->z + d*w;

  return d;
}

int     Solver::fission(Particle* p, double nu, std::vector<Particle *>* nextGen)
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
    p_prime->x = p->x;
    p_prime->y = p->y;
    p_prime->z = p->z;

    // Watts spectrum normally
    p_prime->E = 7.0e6;
    nextGen->push_back(p_prime);
  }

  return nNewNeutrons;
}
