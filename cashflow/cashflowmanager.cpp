#include "cashflowmanager.h"

CashflowManager::CashflowManager(std::vector<Cashflow> trs): transactions(trs) {
    if (transactions.empty()){
        transactions = {
            Cashflow("personal expense", -2000, true, true, 0, 0),
            Cashflow("job",              25000, false, true, -2, -3),   // Work stress
            Cashflow("vehicle",          -3000, false, false, 0, 1),    // Comfort = slight happiness
            Cashflow("house",            -8000, false, false, 2, 2),    // Good housing = better health + mood
            Cashflow("health/food",      -5000, false, false, 5, 0),    // Improves health
        } ;
    }
}

void CashflowManager::showCashflow(const Cashflow &cf) const {
    std::cout<<"Type : "<<cf.getType()
             <<", Value : "<<cf.getValue()
             <<", Effect on Health : "<<cf.getHealthChange()
             <<", Effect on Happiness : "<<cf.getHappinessChange()
             <<", Cumpulsory : "<<(cf.isCompulsory() ? "Yes" : "No")
             <<", Active : "<<(cf.isActive() ? "Yes\n" : "No\n") ;
}

void CashflowManager::showTransactions() const{
    double balanceChange=0;
    int happinessChange=0;
    int healthChange=0;

    std::cout << "Cash Flow Status :\n";
    size_t i = 0;
    for (const auto& cf : transactions) {
        std::cout << ++i << ". ";
        showCashflow(cf);
        if(cf.isActive()){
            balanceChange += cf.getValue();
            happinessChange += cf.getHappinessChange();
            healthChange += cf.getHealthChange();
        }
    }
    std::cout <<"Net Cash-Flow : "<<balanceChange
              <<", Net Happiness Change : "<<happinessChange
              <<", Net Health Change : "<<healthChange<<'\n' ;
}

void CashflowManager::toggleTransaction() {
    int idx;
    std::cout << "Enter the index of the Cash Flow to change : ";
    std::cin >> idx;

    if (idx < 1 || idx > static_cast<int>(transactions.size())) {
        std::cout << "Invalid index!\n";
    } else if(transactions[idx-1].isCompulsory()) {
        std::cout<<"Can not toggle cashflow of the given index!\n" ;
    }else{
        transactions[idx-1].toggleActive();
        std::cout<<transactions[idx-1].getType()<<" is now "<<(transactions[idx-1].isActive() ? "Active\n" : "Inactive\n") ;
    }
}

void CashflowManager::updateCashflow(Cashflow &cf) {
    if (cf.getValue() > 0)
        cf.setValue(cf.getValue()*1.06);
    else
        cf.setValue(cf.getValue()*1.1);
}

void CashflowManager::updateTransactions() {
    for(auto& cf : transactions){
        updateCashflow(cf);
    }
}

void CashflowManager::monthlyBriefing(PlayerStats &playerStats) {
    if(playerStats.getMonth()!=1 && (playerStats.getMonth()-1)%12==0)
        updateTransactions();

    double balanceChange=0;
    int happinessChange=0;
    int healthChange=0;

    for (const auto& cf : transactions){
        if(cf.isActive()){
            balanceChange += cf.getValue();
            happinessChange += cf.getHappinessChange();
            healthChange += cf.getHealthChange();
        }
    }

    playerStats.addBalance(balanceChange);
    playerStats.addHappiness(happinessChange);
    playerStats.addHealth(healthChange);
}
