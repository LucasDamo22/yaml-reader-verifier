#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

#include "Helper-functions.h"
#include "Processor.h"
#define RYML_SINGLE_HDR_DEFINE_NOW
#include "ryml_all.hpp"

int reader(int utilizacao) {
  std::string filename;
  filename = "./data/" + std::to_string(utilizacao) + ".yaml";
  Processor cpu1 = Processor();
  Processor cpu2 = Processor();
  std::string contents = get_file_contents(filename);
  ryml::Tree tree = ryml::parse_in_place(ryml::to_substr(contents));

  ryml::NodeRef processos = tree["Processos"];
  for (ryml::NodeRef const &child : processos.children()) {
    double aux, min, max;
    std::stringstream ss;  // using sstream to convert from csubstr to double
    ss << child[0].val();
    ss >> min;
    ss.clear();
    ss << child[1].val();
    ss >> max;
    ss.clear();

    aux = min / max;

    if (cpu2.get_coef() > cpu1.get_coef()) {
      cpu1.add_process(aux);
    } else {
      cpu2.add_process(aux);
    }
  }
  std::stringstream ss;
  ss << cpu1.get_coef() << std::endl;
  ss << cpu2.get_coef() << std::endl;
  std::cout << "------------" << std::endl;
  std::cout << "cpu1 coef: " << cpu1.get_coef() << std::endl;
  std::cout << "cpu2 coef: " << cpu2.get_coef() << std::endl;
  std::cout << "coef total = " << cpu1.get_coef() + cpu2.get_coef()
            << std::endl;

  return 0;
}