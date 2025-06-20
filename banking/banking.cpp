#include "../banking/banking.h"

Banking::Banking(std::string t, double tv, double mv, int em)
    : type(t), totalValue(tv), monthlyValue(mv), endingMonth(em) {}

std::string Banking::getType() const{
    return type ;
}

double Banking::getMonthlyValue() const{
    return monthlyValue ;
}

double Banking::getTotalValue() const{
    return totalValue ;
}

int Banking::getEndingMonth() const{
    return endingMonth;
}

void Banking::setTotalValue(double tv) {
    totalValue=tv;
}
