#ifndef PLAYERSTATS_H
#define PLAYERSTATS_H

#include <string>
#include <vector>
#include <iostream>

class PlayerStats
{
private:
    int month ;
    int health ;
    int happiness ;
    double balance ;
public:
    PlayerStats(int mo=0, int he=100, int ha=100, double ba=10000);

    void showStats() const;

    int getMonth() const;
    double getBalance() const;
    int getHealth() const;
    int getHappiness() const;

    void addMonth (int m) ;
    void addHealth (int he) ;
    void addHappiness (int ha) ;
    void addBalance(double amount) ;

    void monthlyBriefing() const ;
};

#endif // PLAYERSTATS_H
