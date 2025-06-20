#ifndef INVESTMENT_H
#define INVESTMENT_H

#include <string>
#include <vector>
#include <iostream>

class Investment
{
private:
    std::string type ;
    double value ;

public:
    Investment(std::string t,double v);

    std::string getType() const ;
    double getValue() const ;

    void setValue(double v) ;
};

#endif // INVESTMENT_H
