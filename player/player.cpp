#include "../player/player.h"

Player::Player(std::string n, PlayerStats ps, InvestmentManager pi, CashflowManager pc, BankingManager pb)
    : name(n), playerStats(ps), playerInvestments(pi), playerCashflows(pc), playerBankings(pb) {}

std::string Player::getName() const {
    return name;
}

PlayerStats& Player::getPlayerStats() {
    return playerStats;
}

InvestmentManager& Player::getPlayerInvestments() {
    return playerInvestments;
}

CashflowManager& Player::getPlayerCashflows() {
    return playerCashflows;
}

BankingManager& Player::getPlayerBankings() {
    return playerBankings;
}

bool Player::goodToGo() const{
    return (playerStats.getHappiness()>0 && playerStats.getHealth()>0 && playerStats.getBalance() >=0) ;
}

void Player::advanceMonth(){
    playerStats.addMonth(1);

    playerBankings.monthlyBriefing(playerStats);
    playerCashflows.monthlyBriefing(playerStats);
    playerInvestments.monthlyBriefing(playerStats);

    playerStats.monthlyBriefing();
}
