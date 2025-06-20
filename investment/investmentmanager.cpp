#include "investmentmanager.h"

InvestmentManager::InvestmentManager(std::vector<Investment> hld)
    :holdings(hld) {}

void InvestmentManager::showInvestment(const Investment &inv) const{
    std::cout<<"Type : "<<inv.getType()<<", Value : "<<inv.getValue()<<"\n" ;
}

void InvestmentManager::showHoldings() const {
    if (holdings.empty()) {
        std::cout << "You have not invested yet.\n";
        return ;
    }
    double currentBalance=0 ;
    std::cout << "Current holdings:\n";
    size_t i = 0;
    for (const auto& inv : holdings) {
        std::cout << ++i << ". ";
        showInvestment(inv);
        currentBalance += inv.getValue();
    }
    std::cout <<"Total Investment Balance : "<<currentBalance<<'\n' ;
}

void InvestmentManager::updateInvestment(Investment &inv) {
    std::string type = inv.getType();

    if (type == "Bonds") {
        // 6% annual interest → 0.5% per month
        inv.setValue(inv.getValue() * 1.005);  // Note: it should be multiplied by (1 + rate), not just rate
    }
    else if (type == "Gold") {
        double fluctuation = ((rand() % 5) - 2) / 100.0; // -2% to +2%
        inv.setValue(inv.getValue() * (1 + fluctuation));
    }
    else if (type == "Stocks") {
        double fluctuation = ((rand() % 23) - 10) / 100.0; // -10% to +12%
        inv.setValue(inv.getValue() * (1 + fluctuation));
    }
}

void InvestmentManager::monthlyBriefing(PlayerStats &playerStats) {
    double currentBalance=0 ;
    for (auto& inv : holdings) {
        updateInvestment(inv);
        currentBalance += inv.getValue() ;
    }
}

void InvestmentManager::buyHoldings(PlayerStats &playerStats) {
    std::vector<std::string> validTypes = {"Bonds","Gold","Stocks"} ;

    std::cout << "Available investment types:\n";
    std::cout << "1. Bonds   - Low risk, 6% annual (0.5% monthly) return.\n";
    std::cout << "2. Gold    - Stable, fluctuates around ±2% monthly.\n";
    std::cout << "3. Stocks  - Volatile, fluctuates between -10% to +12% monthly.\n";

    int t ;
    std::cout << "Enter investment type : ";
    std::cin>>t ;

    if (t < 1 || t > static_cast<int>(validTypes.size())) {
        std::cout << "Invalid investment type!\n";
        return ;
    }
    std::string type = validTypes[t-1];

    double amount;
    std::cout << "Enter amount: ";
    std::cin >> amount;
    if (amount <=0){
        std::cout << "Enter a positive number!\n";
        return ;
    }

    if (amount > playerStats.getBalance()) {
        std::cout << "Insufficient balance.\n";
        return;
    }

    playerStats.addBalance(-amount);
    holdings.emplace_back(type, amount);
    std::cout << "Bought " << type << " for " << amount << ".\n";
}

void InvestmentManager::sellHoldings(PlayerStats &playerStats) {
    if (holdings.empty()) {
        std::cout << "No holdings to sell.\n";
        return ;
    }

    int idx;
    std::cout << "Enter the index of the holding to sell : ";
    std::cin >> idx;

    if (idx < 1 || idx > static_cast<int>(holdings.size())) {
        std::cout << "Invalid index!\n";
        return ;
    }

    double credited = holdings[idx - 1].getValue();
    playerStats.addBalance(credited);
    holdings.erase(holdings.begin() + idx - 1);
    std::cout << "Sold! " << credited << " credited to your balance.\n";
}
