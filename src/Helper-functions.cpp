#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <sstream>
#include "Helper-functions.h"


std::string get_file_contents(std::string filename){
    std::ifstream in(filename, std::ios::in | std::ios::binary);
    if (!in)
    {
        std::cerr << "could not open " << filename << std::endl;
        exit(1);
    }
    std::ostringstream contents;
    contents << in.rdbuf();
    return contents.str();
}

