#ifndef CASHFLOW_H
#define CASHFLOW_H

#include <string>
#include <vector>
#include <iostream>

class Cashflow
{
private:
    std::string type ;
    double value ;
    int healthChange;
    int happinessChange;
    bool compulsory ;
    bool active ;
public:
    Cashflow(std::string t, double v, bool c, bool a, int he, int ha) ;

    std::string getType() const ;
    double getValue() const ;
    int getHealthChange() const ;
    int getHappinessChange() const ;
    bool isCompulsory() const ;
    bool isActive() const ;

    void setValue(double v) ;
    void toggleActive() ;
};

#endif // CASHFLOW_H
