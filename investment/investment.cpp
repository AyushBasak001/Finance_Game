#include "../investment/investment.h"

Investment::Investment(std::string t, double v)
    : type(t), value(v) {}

std::string Investment::getType() const{
    return type ;
}

double Investment::getValue() const{
    return value ;
}

void Investment::setValue(double v){
    value=v;
}
