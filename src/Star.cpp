#include <iostream>
#include <map>
#include <random>
#include <iterator>
#include <fstream>
#include <string>
#include <vector>
#include <utility>
#include "../include/Star.hpp"
#include "../include/json.hpp"

using json = nlohmann::json;

namespace nyon
{

  json Star::star_json;
  std::vector<double> Star::star_weight;
  double Star::star_data_master[99][3][2];
  std::string Star::star_name_arr[99];

  Star::Star(json definition)
    {
      star_json = starLoadFromFile(definition);
    }

  std::string  *Star::getStarNameStringArr() {return star_name_arr; }

  json Star::starLoadFromFile(json definition)
  {
    json star_j = definition["Star"];

    for(json::iterator i = star_j.begin(); i != star_j.end(); i++)
      {
        star_weight.push_back(star_j[i.key()]["weight"]);
      }

    int data_i = 0;
    for(json::iterator j = star_j.begin() ; j != star_j.end(); j++)
      {
        star_data_master[data_i][0][0] = star_j[j.key()]["mass"][0];
        star_data_master[data_i][0][1] = star_j[j.key()]["mass"][1];
        star_data_master[data_i][1][0] = star_j[j.key()]["radius"][0];
        star_data_master[data_i][1][1] = star_j[j.key()]["radius"][1];
        star_data_master[data_i][2][0] = star_j[j.key()]["temperature"][0];
        star_data_master[data_i][2][1] = star_j[j.key()]["temperature"][1];

        data_i++;
      }

    int name_i = 0;
    for(json::iterator j = star_j.begin(); j != star_j.end(); j++)
      {
        star_name_arr[name_i] = star_j[j.key()]["name_string"];

        name_i++;
      }
    return  star_j;
  }

  double Star::getMass() { return mass; }

  void Star::setMass(double a) { mass = a; }

  double Star::getRadius() { return radius; }

  void Star::setRadius(double a) { radius = a; }

  int Star::getTemperature() { return temperature; }

  void Star::setTemperature(int a) { temperature = a; }

  int Star::getSpecClass() { return spec_class; }

  void Star::setSpecClass(int a) { spec_class = a; }

  std::string Star::getSpecClassName() { return spec_class_name;}

  void Star::setSpecClassName(std::string a) {spec_class_name = a;}

  double Star::calcLuminosity(double radius, double temp) { return pow(radius, 2) * pow((temp / STEMPERATURE), 4); }

  double Star::getLuminosity() { return luminosity; }

  void Star::setLuminosity(double a) { luminosity = a; }

  double Star::getGravity() { return gravity; }

  void Star::setGravity(double a) { gravity = a; }

  int Star::generate()
  {
    std::random_device rd;
    std::mt19937 mt(rd());
    std::discrete_distribution<int> StarWeightDist (star_weight.begin(), star_weight.end()); //{0.6, 5.5, 1.0, 0.4, 0.2, 0.1, 0.06, 0.02, 0.005};

    int rand_star = StarWeightDist(mt);
    double star_data[3][2];

      for (int i = 0; i < 3; i++)
        {
          for (int u = 0; u < 2; u++)
            {
              star_data[i][u] = star_data_master[rand_star][i][u];
            }
        }

    double out_data[3];
    for (int i = 0; i < 3; i++)
      {
        std::uniform_real_distribution<double> DoubleDist(star_data[i][0], star_data[i][1]);
        out_data[i] = DoubleDist(mt);
      }
    mass = out_data[0];
    radius = out_data[1];
    temperature = out_data[2];
    luminosity = calcLuminosity(radius, temperature);
    gravity = calcGravity(mass * nyon::SMASS, radius * nyon::SRADIUS);
    spec_class_name = star_name_arr[rand_star];

    return rand_star;
  }
} // namespace nyon
