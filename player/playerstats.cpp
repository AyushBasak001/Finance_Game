#include "playerstats.h"

PlayerStats::PlayerStats(int mo, int he, int ha, double ba)
    :month(mo), health(he), happiness(ha), balance(ba) {}

void PlayerStats::showStats() const {
    std::cout<<"Month     : "<<month
             <<"\nHealth    : "<<health
             <<"\nHappiness : "<<happiness
             <<"\nBalance   : "<<balance
             <<std::endl ;
}

int PlayerStats::getMonth() const {
    return month;
}

double PlayerStats::getBalance() const {
    return balance;
}

int PlayerStats::getHealth() const {
    return health;
}

int PlayerStats::getHappiness() const {
    return happiness;
}

void PlayerStats::addMonth(int m){
    if(m>0)
        month += m;
}

void PlayerStats::addHealth(int he){
    health += he;
    if(health>100) health=100;
}

void PlayerStats::addHappiness(int ha){
    happiness += ha;
    if(happiness>100) happiness=100;
}

void PlayerStats::addBalance(double amount){
    balance += amount;
}

void PlayerStats::monthlyBriefing() const {

    if(getBalance()<1000) std::cout<<"Low Balance!!\n";
    if(getHealth()<10) std::cout<<"Low Health!!\n";
    if(getHappiness()<10) std::cout<<"Low Happiness!!\n";
}
