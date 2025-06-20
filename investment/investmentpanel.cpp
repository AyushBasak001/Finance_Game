#include "investmentpanel.h"

InvestmentPanel::InvestmentPanel() {}

void InvestmentPanel::run(Player &player){

    InvestmentManager &manager(player.getPlayerInvestments());

    int choice;
    while (true) {
        std::cout << "\n== Investment Panel ==\n"
                  << "1. Show Current Holdings\n"
                  << "2. Buy Holdings\n"
                  << "3. Sell Holdings\n"
                  << "4. Exit to Main Menu\n"
                  << "Enter your choice: ";
        std::cin >> choice;
        std::cout << "\n";

        switch (choice) {
        case 1: {
            manager.showHoldings();
            break;
        }
        case 2: {
            manager.buyHoldings(player.getPlayerStats());
            break;
        }
        case 3: {
            manager.sellHoldings(player.getPlayerStats());
            break;
        }
        case 4: {
            std::cout << "Exiting Investment Panel...\n";
            return;
        }
        default: {
            std::cout << "Enter a valid choice!\n";
            break;
        }
        }
    }
}
