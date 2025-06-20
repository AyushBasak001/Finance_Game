#ifndef PLAYER_H
#define PLAYER_H

#include "../cashflow/cashflowmanager.h"
#include "../investment/investmentmanager.h"
#include "../banking/bankingmanager.h"

class Player
{
private:
    std::string name ;
    PlayerStats playerStats ;
    InvestmentManager playerInvestments ;
    CashflowManager playerCashflows ;
    BankingManager playerBankings ;

public:
    Player(std::string n, PlayerStats ps = PlayerStats(), InvestmentManager pi = InvestmentManager(), CashflowManager pc = CashflowManager(), BankingManager pb = BankingManager());

    std::string getName() const ;
    PlayerStats& getPlayerStats() ;
    InvestmentManager& getPlayerInvestments() ;
    CashflowManager& getPlayerCashflows() ;
    BankingManager& getPlayerBankings() ;

    bool goodToGo() const ;
    void advanceMonth() ;
};

#endif // PLAYER_H
