#ifndef CASHFLOWMANAGER_H
#define CASHFLOWMANAGER_H

#include "cashflow.h"
#include "../player/playerstats.h"

class CashflowManager
{
private:
    std::vector<Cashflow> transactions ;
public:
    CashflowManager(std::vector<Cashflow> trs={});

    void showCashflow(const Cashflow& cf) const ;
    void showTransactions() const ;

    void toggleTransaction() ;

    void updateCashflow(Cashflow& cf) ;
    void updateTransactions() ;

    void monthlyBriefing(PlayerStats& playerStats) ;
};

#endif // CASHFLOWMANAGER_H
