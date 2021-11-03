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
