#ifndef NYONLIB_HPP
#define NYONLIB_HPP

/**
 * \defgroup Nyonyix
 * @brief Nyonyix library for galaxy.
 */

/**
 * @brief Primary Nyonyix Namespace
 *
 * \ingroup Nyonyix
 */
namespace nyon
{

  /**
   * PI.
   * The PI Constant.
   */
  const double PI = 3.14159265359;
  /**
   * Solar Mass(kg).
   * Solar mass constant used to convert between solar units and smaller metric units.
   */
  const double SMASS = 1.98847e+30;
  /**
   * Solar Radius(m).
   * Solar radius constant used to convert between solar units and smaller metric units.
   */
  const double SRADIUS = 696340000;
  /**
   * Solar Luminosity(W).
   * Solar luminosity constant used to convert between solar units and smaller metric units.
   */
  const double SLUMINOSITY = 3.828e+26;
  /**
   * Solar Temperature(k).
   * Solar Temperature constant used to convert between solar units and smaller metric units.
   */
  const double STEMPERATURE = 5778;
  /**
   * Gravitational Constant.
   * Gravitational constant used to calculate the gravity is objects.
   * @see calcGravity()
   */
  const double GCONSTANT = 6.67408e-11;

  /**
   * Calculate Surface Gravity.
   * Calculates the surface gravity based on mass and radius of the target object.
   * @param mass is the mass of the target object.
   * @param radius is the radius of the target object.
   * @return The surface gravity as a double float in units 'g'.
   */
  double calcGravity(double mass, double radius);

  /**
   * Calculate Volume of target object (Currently Unused).
   * Calculates volume of target object based on it's radius.
   * @param radius is the radius of the target object.
   * @return The volume of the target object as a double float in units 'm^3'.
   */
  double calcVolume(double radius);

  /**
   * Calculate Hill Sphere.
   * Calculates the hill sphere of the target object.
   * @param semi_major_axis is the orbit of the object around it's parent object.
   * @param secondary_mass is the mass of the child object (eg. Star, Planet,Asteroid, etc.).
   * @param primary_mass is the mass of the larger parent object (eg. Star, Blackhole, Galaxy, etc.).
   * @return The hill sphere of the object as a double float in units 'm'.
   */
  double calcHillSphere(double semi_major_axis, double secondary_mass, double primary_mass);

  } // namespace nyon
#endif /* NYONLIB_HPP */
