#include <filesystem>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include<algorithm>
#include "Helper-functions.h"

/// @brief Opens the specified file and converts its content to a string.
/// @param filename 
/// @return The file contents as a string.
std::string get_file_contents(std::string filename) {
  std::ifstream in(filename, std::ios::in | std::ios::binary);
  if (!in) {
    std::cerr << "could not open here" << filename << std::endl;
    exit(1);
  }
  std::ostringstream contents;
  contents << in.rdbuf();
  return contents.str();
}
/// @brief Iterates through the data folder collecting the tasks files paths.
/// @details Using the <filesystem> standard library to gather all the needed files, then using de alphabatically_sort() function, for a clearer view.
/// @return A sorted string vector with all the files to be analyzed.
std::vector<std::string> get_file_paths() {
  std::string path = "./Cpu-usage-calculator/data/";
  std::vector<std::string> data_files;
  for (const auto& entry : std::filesystem::directory_iterator(path)) {
    std::string aux = entry.path();
    if (aux.find(".yaml") != std::string::npos) {
      data_files.push_back(entry.path());
    } else {
      continue;
    }
  }
  data_files = alphabatically_sort(data_files);
  return data_files;
}
/// @brief Compares strings alphabatically
/// @param a string a.
/// @param b string b.
/// @return returns TRUE if "a" comes first than "b" in alphabatical order, false if it's not.
bool mycomp(std::string a, std::string b) {
  // returns 1 if string a is alphabetically 
  // less than string b
  // quite similar to strcmp operation
  return a < b;
}
/// @brief Goes through every file stored in the "files" vector to sort it.
/// @param files The vector to be sorted.
/// @return The sorted vector
std::vector<std::string> alphabatically_sort(std::vector<std::string> files) {
    int n = files.size();
    sort(files.begin(), files.end(), mycomp);

    return files;
}
