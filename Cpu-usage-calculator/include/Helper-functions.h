#ifndef CPU_USAGE_CALCULATOR_INCLUDE_HELPER_FUNCTIONS_H_
#define CPU_USAGE_CALCULATOR_INCLUDE_HELPER_FUNCTIONS_H_

std::string get_file_contents(std::string filename);
std::vector<std::string> get_file_paths();
bool mycomp(std::string a, std::string b);
std::vector<std::string> alphabatically_sort(std::vector<std::string> files);

#endif  // CPU_USAGE_CALCULATOR_INCLUDE_HELPER_FUNCTIONS_H_
