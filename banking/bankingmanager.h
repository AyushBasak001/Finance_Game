#ifndef BANKINGMANAGER_H
#define BANKINGMANAGER_H

#include "banking.h"
#include "../player/playerstats.h"

class BankingManager
{
private:
    std::vector<Banking> plans ;
public:
    BankingManager(std::vector<Banking> pln={});

    void showLoan(const Banking& ln) const ;
    void showDeposit(const Banking& dp) const ;
    void showPlans() const ;

    void startLoan(PlayerStats& playerStats) ;
    void startDeposit(PlayerStats& playerStats) ;
    void startPlan(PlayerStats& playerStats) ;

    void endLoan(PlayerStats& playerStats, int index) ;
    void endDeposit(PlayerStats& playerStats, int index) ;
    void endPlan(PlayerStats& playerStats) ;

    void monthlyBriefing(PlayerStats& playerStats) ;
};

#endif // BANKINGMANAGER_H
