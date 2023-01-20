#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>
#include <sstream>

#include "Processor.h"
#include "Helper-functions.h"
#define RYML_SINGLE_HDR_DEFINE_NOW
#include "ryml_all.hpp"

/// @brief The main function is responsible for the math behind the use of CPU, according to the tasks details, provided from a YAML file in the "./data" folder of the project.
int main(int argc, char** argv) {
        // Aquiring all the "*.yaml" files path in the "./data" folder
    std::vector<std::string> files = get_file_paths();

    for (int z = 0; z < files.size(); z++) {
        Processor cpu1 = Processor();
        Processor cpu2 = Processor();
        std::string contents = get_file_contents(files[z]);

            // Using a third-party library to gather the information written on a yaml pattern.
            //
            // The "contents" variable has one yaml file copied in a string.Then, the "processos" tree
            // of the tasks file gets parsed to the "processos" variable.

        ryml::Tree tree = ryml::parse_in_place(ryml::to_substr(contents));
        ryml::NodeRef processos = tree["Processos"];

            // Using the third-party library to get the minimal response time, and maximal response time,
            // respectively, child[0] and child[1], needed for the amount of processing power for this task.

        for (ryml::NodeRef const &child : processos.children()) {
                // Using sstream to convert from csubstr to double
            double aux, min, max;
            std::stringstream ss;
            ss << child[0].val();
            ss >> min;
            ss.clear();
            ss << child[1].val();
            ss >> max;
            ss.clear();

                // Calculating the amount of processing each task requires.
            aux = min / max;

                // balances the use on two CPUs
            if (cpu2.get_coef() > cpu1.get_coef()) {
                cpu1.add_process(aux);
            } else {
                cpu2.add_process(aux);
            }
        }
            // Printing the amount of processing power used by the cpu, for each tasks file.
        std::cout << "------------" << std::endl;
        std::cout << files[z] << std::endl;
        std::cout << "cpu1 coef = " << cpu1.get_coef() << std::endl;
        std::cout << "cpu2 coef = " << cpu2.get_coef() << std::endl;
        std::cout << "coef total = " << cpu1.get_coef() + cpu2.get_coef() << std::endl;
    }
    return 0;
}
