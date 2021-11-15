#include "Box.hpp"


                Box::Box       (double* pos, 
                                double* width, 
                                Material* material)
{
  x = pos[0];
  y = pos[1];
  z = pos[2];

  w_x = width[0];
  w_y = width[1];
  w_z = width[2];

  _material = material;
}


bool            Box::isInside  (double* pos)
{
  if( fabs(pos[0] - x) < w_x/2.0 &&
      fabs(pos[1] - y) < w_y/2.0 &&
      fabs(pos[2] - z) < w_z/2.0 )
  {
    return true;
  }
  else
  {
    return false;
  }
}

bool            Box::isInside  (Particle* p)
{
  if( fabs(p->x - x) < w_x/2.0 &&
      fabs(p->y - y) < w_y/2.0 &&
      fabs(p->z - z) < w_z/2.0 )
  {
    return true;
  }
  else
  {
    return false;
  }
}

double          Box::distance   (Particle* p)
{
  double d = -1.0;
  double x_0, y_0, z_0;
  double u, v, w;
  double t;
  double _x, _y, _z;

  x_0 = p->x;
  y_0 = p->y;
  z_0 = p->z;

  u   = p->u;
  v   = p->v;
  w   = p->w;

  // Distance to TOP OF THE BOX
  _z  = z + w_z/2.0;

  t   = (_z - z_0)/w;

  _x  = x_0 + t*u;
  _y  = y_0 + t*v;

  if(  _x >= (x-w_x/2.0) && _x <= (x + w_x/2.0)
    && _y >= (y-w_y/2.0) && _y <= (y + w_y/2.0)
    )
  {
    if(d == -1.0 || fabs(t) < d)
    {
      d = fabs(t);
    }
  }

  // Distance to BOTTOM OF THE BOX
  _z  = z - w_z/2.0;

  t   = (_z - z_0)/w;

  _x  = x_0 + t*u;
  _y  = y_0 + t*v;

  if(  _x >= (x-w_x/2.0) && _x <= (x + w_x/2.0)
    && _y >= (y-w_y/2.0) && _y <= (y + w_y/2.0)
    )
  {
    if(d == -1.0 || fabs(t) < d)
    {
      d = fabs(t);
    }
  }

  // Distance to RIGHT OF THE BOX
  _x  = x + w_x/2.0;

  t   = (_x - x_0)/u;

  _y  = y_0 + t*v;
  _z  = z_0 + t*w;

  if(  _y >= (y-w_y/2.0) && _y <= (y + w_y/2.0)
    && _z >= (z-w_z/2.0) && _z <= (z + w_z/2.0)
    )
  {
    if(d == -1.0 || fabs(t) < d)
    {
      d = fabs(t);
    }
  }

  // Distance to LEFT OF THE BOX
  _x  = x - w_x/2.0;

  t   = (_x - x_0)/u;

  _y  = y_0 + t*v;
  _z  = z_0 + t*w;

  if(  _y >= (y-w_y/2.0) && _y <= (y + w_y/2.0)
    && _z >= (z-w_z/2.0) && _z <= (z + w_z/2.0)
    )
  {
    if(d == -1.0 || fabs(t) < d)
    {
      d = fabs(t);
    }
  }

  // Distance to FRONT OF THE BOX
  _y  = y + w_y/2.0;

  t   = (_y - y_0)/v;

  _x  = x_0 + t*u;
  _z  = z_0 + t*w;

  if(  _x >= (x-w_x/2.0) && _x <= (x + w_x/2.0)
    && _z >= (z-w_z/2.0) && _z <= (z + w_z/2.0)
    )
  {
    if(d == -1.0 || fabs(t) < d)
    {
      d = fabs(t);
    }
  }

  // Distance to BACK OF THE BOX
  _y  = y - w_y/2.0;

  t   = (_y - y_0)/v;

  _x  = x_0 + t*u;
  _z  = z_0 + t*w;

  if(  _x >= (x-w_x/2.0) && _x <= (x + w_x/2.0)
    && _z >= (z-w_z/2.0) && _z <= (z + w_z/2.0)
    )
  {
    if(d == -1.0 || fabs(t) < d)
    {
      d = fabs(t);
    }
  }

  return d;
}

double*         Box::getExtent ()
{
  double* extent = new double[6];

  extent[0] = x - w_x/2;
  extent[1] = x + w_x/2;
  extent[2] = y - w_y/2;
  extent[3] = y + w_y/2;
  extent[4] = z - w_z/2;
  extent[5] = z + w_z/2;

  return extent;

}
