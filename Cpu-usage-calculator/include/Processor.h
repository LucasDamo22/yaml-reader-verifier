/// @brief Simulates utilization of 1 processor.
#ifndef CPU_USAGE_CALCULATOR_INCLUDE_PROCESSOR_H_
#define CPU_USAGE_CALCULATOR_INCLUDE_PROCESSOR_H_
class Processor {
    double coef;

 public:
    Processor();
    void add_process(double process);
    double get_coef();
};
#endif  // CPU_USAGE_CALCULATOR_INCLUDE_PROCESSOR_H_
