#include "../include/Star.hpp"
#include <cstdio>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

int main(int argc, char *argv[]) {

  std::ifstream json_file_in("../files/definitions.json");
  //json definition;
  //json_file_in >> definition;

  std::stringstream ss;
  ss << json_file_in.rdbuf();
  std::string j_string = ss.str();
  json definition = json::parse(j_string);

  std::string hi;

  int spec_class_count[definition["Star"].size()];
  for(int i = 0; i < definition["Star"].size(); i++)
    {
      spec_class_count[i] = 0;
    }

  nyon::Star Star = nyon::Star(definition);
  std::vector<nyon::Star> test;
  std::stringstream stest;

  for (int i = 0; i < 10000; i++)
    {

      int count = Star.generate();

      std::cout << Star.getSpecClassName() << ": \n"
                << Star.getMass() << " "
                << Star.getMass() * nyon::SMASS <<  '\n'
                << Star.getRadius() << " "
                << Star.getRadius() * nyon::SRADIUS << '\n'
                << Star.getTemperature() << '\n'
                << Star.getGravity() << '\n'
                << Star.getLuminosity() << '\n' 
                << nyon::calcHillSphere(4.26E+20, Star.getMass() * nyon::SMASS, 1.5752E+34) << '\n'
                << std::endl;

      test.push_back(Star);

      //test[count]++;

      spec_class_count[count]++;
    }

  for(int i = 0; i < definition["Star"].size(); i++)
    {
      std::cout << Star.getStarNameStringArr()[i] << ": "
                << spec_class_count[i] << std::endl;
    }

  //std::cout << definition["Star"].size() << std::endl;

  std::cin >> hi;

    return 0;
}
