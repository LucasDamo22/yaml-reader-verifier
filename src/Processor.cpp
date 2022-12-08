
#include "Processor.h"


Processor::Processor(){
    coef = 0;
}

void Processor::add_process(double process){
    coef += process;
}
double Processor::get_coef(){
    return coef;
}

