#include "bankingmanager.h"

BankingManager::BankingManager(std::vector<Banking> pln)
    : plans(pln) {}

void BankingManager::showLoan(const Banking &ln) const {
    std::cout<<"Type : "<<ln.getType()
             <<", Monthly EMI : "<<ln.getMonthlyValue()
             <<", Current Deficit : "<<ln.getTotalValue()<<"\n" ;
}

void BankingManager::showDeposit(const Banking &dp) const {
    std::cout<<"Type : "<<dp.getType()
              <<", Monthly Return : "<<dp.getMonthlyValue()
              <<", Total Deposit : "<<dp.getTotalValue()<<"\n" ;
}

void BankingManager::showPlans() const {
    if (plans.empty()) {
        std::cout << "You have no ongoing plans.\n";
        return;
    }
    double netMonthly=0, netTotal=0;
    std::cout << "Current Plans:\n";
    size_t i=0;
    for (const auto& pln : plans) {
        std::cout << ++i << ". ";
        netMonthly+=pln.getMonthlyValue();
        netTotal+=pln.getTotalValue();
        if(pln.getType()=="Loan")
            showLoan(pln);
        else if(pln.getType()=="Deposit")
            showDeposit(pln);
    }
    std::cout <<"Net Monthly Transaction : "<<netMonthly<<"Total Value : "<<netTotal<<'\n' ;
}

void BankingManager::startLoan(PlayerStats &playerStats) {
    int c ;
    std::cout << "Available Loan Plans :\n"
              << "1. 1 year - 8.80% monthly payment.\n"
              << "2. 2 year - 4.61% monthly payment.\n"
              << "3. 5 year - 2.12% monthly payment.\n"
              << "4. Return to 'Start Plans'.\n"
              << "Enter your choice : ";
    std::cin>>c ;
    switch (c) {
    case 1:{
        double amount ;
        std::cout << "Enter amount: ";
        std::cin >> amount;
        if (amount <=0){
            std::cout << "Enter a positive number!\n";
            return ;
        }

        plans.emplace_back("Loan", -(amount*1.056), -(amount*0.088), (playerStats.getMonth()+12));
        playerStats.addBalance(amount);
        std::cout << "Started a 1 year Loan with a monthly EMI of : "<<amount*0.0880<<'\n' ;
        break;
    }
    case 2:{
        double amount ;
        std::cout << "Enter amount: ";
        std::cin >> amount;
        if (amount <=0){
            std::cout << "Enter a positive number!\n";
            return ;
        }

        plans.emplace_back("Loan", -(amount*1.1064), -(amount*0.0461), (playerStats.getMonth()+24));
        playerStats.addBalance(amount);
        std::cout << "Started a 2 year Loan with a monthly EMI of : "<<amount*0.0461<<'\n' ;
        break;
    }
    case 3:{
        double amount ;
        std::cout << "Enter amount: ";
        std::cin >> amount;
        if (amount <=0){
            std::cout << "Enter a positive number!\n";
            return ;
        }

        plans.emplace_back("Loan", -(amount*1.272), -(amount*0.0212), (playerStats.getMonth()+60));
        playerStats.addBalance(amount);
        std::cout << "Started a 5 year Loan with a monthly EMI of : "<<amount*0.0212<<'\n' ;
        break;
    }
    case 4:{
        std::cout << "Returning to Start Plans...\n";
        return;
    }
    default:{
        std::cout << "Enter a valid choice!\n";
        break;
    }
    }
}

void BankingManager::startDeposit(PlayerStats &playerStats) {
    double amount ;
    std::cout << "Enter amount: ";
    std::cin >> amount;

    if (amount <=0){
        std::cout << "Enter a positive number!\n";
        return ;
    }
    if (amount > playerStats.getBalance()) {
        std::cout << "Insufficient balance.\n";
        return ;
    }
    int m ;
    std::cout<<"Enter the duration(months)\n 0(Zero) to go back : ";
    std::cin>>m ;
    if(m<=0) return ;
    plans.emplace_back("Deposit", amount, amount*0.005, (playerStats.getMonth()+m));
    playerStats.addBalance(-amount);
    std::cout << "Deposited " << amount << " for "<<m<<" months.\n";
}

void BankingManager::startPlan(PlayerStats &playerStats) {
    int t ;
    std::cout << "Available Banking Plans :\n"
              << "1. Deposit - 6% annual return.\n"
              << "2. Loan    - 10% annual charge.\n"
              << "3. Return to Banking Panel.\n"
              << "Enter your choice : ";
    std::cin>>t ;
    std::cout << "\n";

    switch (t) {
    case 1:{
        startDeposit(playerStats);
        break;
    }
    case 2:{
        startLoan(playerStats);
        break;
    }
    case 3:{
        std::cout << "Returning to Banking Panel...\n";
        return;
    }
    default:{
        std::cout << "Enter a valid choice!\n";
        break;
    }
    }
}

void BankingManager::endLoan(PlayerStats &playerStats, int index) {
    double debited = plans[index].getTotalValue() ; //Negative Value
    if(debited < 0 && -debited > playerStats.getBalance()){
        std::cout << "Insufficient balance.\n";
        return ;
    }
    playerStats.addBalance(debited);
    plans.erase(plans.begin() + index);
    std::cout << "Paidoff Loan Plan ! " << -debited << " debited from your bank.\n";
}

void BankingManager::endDeposit(PlayerStats &playerStats, int index) {
    double credited = plans[index].getTotalValue();
    playerStats.addBalance(credited);
    plans.erase(plans.begin() + index);
    std::cout << "Ended Deposit Plan ! " << credited << " credited to your balance.\n";
}

void BankingManager::endPlan(PlayerStats &playerStats) {
    if(plans.empty()){
        std::cout << "No plan to end.\n";
        return ;
    }
    int idx;
    std::cout << "Enter the index of the plan to end : " ;
    std::cin >> idx;

    if (idx < 1 || idx > static_cast<int>(plans.size())) {
        std::cout << "Invalid index!\n";
        return ;
    }

    if (plans[idx-1].getType() == "Loan")
        endLoan(playerStats, idx-1);
    else if (plans[idx-1].getType() == "Deposit")
        endDeposit(playerStats, idx-1);
}

void BankingManager::monthlyBriefing(PlayerStats &playerStats){
    double balanceChange=0;
    int currentMonth = playerStats.getMonth();
    for (int i=0; i<plans.size(); i++){
        if(plans[i].getEndingMonth() >= currentMonth){
            balanceChange += plans[i].getMonthlyValue() ;
            if(plans[i].getType()=="Loan")
                plans[i].setTotalValue(plans[i].getTotalValue() - plans[i].getMonthlyValue());
        }
        else{
            if(plans[i].getType()=="Loan")
                endLoan(playerStats,i);
            else if(plans[i].getType()=="Deposit")
                endDeposit(playerStats,i);
        }
    }
    playerStats.addBalance(balanceChange);
}
