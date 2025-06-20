#ifndef BANKING_H
#define BANKING_H

#include <string>
#include <vector>
#include <iostream>

class Banking
{
private:
    std::string type ;
    double totalValue;
    double monthlyValue ;
    int endingMonth ;

public:
    Banking(std::string t, double tv, double mv,int em);

    std::string getType() const ;
    double getTotalValue() const ;
    double getMonthlyValue() const ;
    int getEndingMonth() const ;

    void setTotalValue(double tv) ;
};

#endif // BANKING_H
