#ifndef INVESTMENTMANAGER_H
#define INVESTMENTMANAGER_H

#include "investment.h"
#include "../player/playerstats.h"

class InvestmentManager
{
private:
    std::vector<Investment> holdings ;
public:
    InvestmentManager(std::vector<Investment> hld={});

    void showInvestment(const Investment& inv) const ;
    void showHoldings() const ;

    void updateInvestment(Investment& inv) ;
    void monthlyBriefing(PlayerStats& playerStats) ;

    void buyHoldings(PlayerStats& playerStats) ;
    void sellHoldings(PlayerStats& playerStats) ;
};

#endif // INVESTMENTMANAGER_H
