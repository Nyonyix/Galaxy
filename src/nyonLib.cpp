#include <iostream>
#include "../include/nyonLib.hpp"
#include <cmath>

namespace nyon
{
  double calcGravity(double mass, double radius)
  {
    return ((nyon::GCONSTANT * mass) / (pow(radius, 2)) / 9.81);
  }

  double calcVolume(double radius)
  {
    return (4/3) * nyon::PI * pow(radius, 3);
  }

  double calcHillSphere(double semi_major_axis, double secondary_mass, double primary_mass)
  {
    return (semi_major_axis * std::cbrt(secondary_mass / (3 * primary_mass)));
  }
}
