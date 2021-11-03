#include "Box.hpp"


                Box::Box       (std::vector<double>* pos, 
                                std::vector<double>* width, 
                                Material* material)
{

}


bool            Box::isInside  (std::vector<double>* pos)
{
  if( fabs((*pos)[0] - x) < w_x/2.0 &&
      fabs((*pos)[1] - y) < w_y/2.0 &&
      fabs((*pos)[2] - z) < w_z/2.0 )
  {
    return true;
  }
  else
  {
    return false;
  }
}

vector<double>* Box::getExtent ()
{
  vector<double>* extent = new vector<double>;
  extent.reserve(6);
  extent[0] = x - w_x/2;
  extent[1] = x + w_x/2;
  extent[2] = y - w_y/2;
  extent[3] = y + w_y/2;
  extent[4] = z - w_z/2;
  extent[5] = z + w_z/2;

  return extent;

}
