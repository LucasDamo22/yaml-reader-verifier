
#include "Processor.h"
/// @brief Constructor for the Processor class.
/// Initializes the CPU usage as 0%.
Processor::Processor() { 
    coef = 0; }
/// @brief Adds the amount of processing power for such task.
/// @param process The amount of processing required for such task.
void Processor::add_process(double process) { 
    coef += process; }
/// @brief Returns the total amount of current processing on the cpu.
double Processor::get_coef() { 
    return coef; }
