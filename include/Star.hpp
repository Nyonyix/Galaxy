#ifndef STAR_HPP
#define STAR_HPP

#include "../include/json.hpp"
#include "../include/nyonLib.hpp"
#include <string>
#include <vector>

using json = nlohmann::json;

/**
 * \ingroup Nyonyix 
 */
namespace nyon {

  /**
   *
   *
   *
   */

  /**
   * Star Object. Star object class that generates and stores a star's attributes.
   */
  class Star {

  public:

    /**
     * Star constructor.
     * This constructor take in the json file with with the base numbers to generate from.
     * @param definition is the json file containing each objects base attributes.
     * @see starLoadFromFile()
     */
    Star(json definition);

    /**
     * A member function to return the list of 'star_name' strings pulled from definition file.
     * @return star_name strings as array.
     */
    std::string *getStarNameStringArr();

    /**
     * A member function that pulls the necessary data from the definition file and leads it into the star object to be used for generation.
     * @param definition is the json file object containing data.
     * @return a slimmed json object with only star related data for future use.
     */
    static json starLoadFromFile(json definition);

    /**
     * Simple function to return member variable mass.
     * @return object mass as double.
     */
    double getMass();

    void setMass(double a);

    /**
     * Simple function to return member variable radius.
     * @return object radius as double.
     */
    double getRadius();

    void setRadius(double a);

    /**
     * Simple function to return member variable temperature.
     * @return object temperature as int.
     */
    int getTemperature();

    void setTemperature(int a);

    /**
     * Simple function to return member variable spectral class (Deprecated).
     * @return object spectral class as int.
     */
    int getSpecClass();

    void setSpecClass(int a);

    /**
     * Simple function to return the objects star_name string.
     * @return object spectral class name as double.
     */
    std::string getSpecClassName();

    void setSpecClassName(std::string a);

    static std::string fromSpecClass(int a);

    double calcLuminosity(double radius, double temp);

    double getLuminosity();

    void setLuminosity(double a);

    double getGravity();

    void setGravity(double a);

    int generate();

    static json star_json;
    static std::vector<double> star_weight;
    static double star_data_master[99][3][2];
    static std::string star_name_arr[99];

  private:
    //enum specClass { T, M, K, G, B, A, W, N, X };

    double mass;
    double radius;
    double temperature;
    double luminosity;
    double gravity;
    int spec_class;
    std::string spec_class_name;
  };
} // namespace nyon
#endif /* STAR_HPP */
