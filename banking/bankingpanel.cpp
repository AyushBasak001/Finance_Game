#include "bankingpanel.h"

BankingPanel::BankingPanel() {}

void BankingPanel::run(Player &player){

    BankingManager &manager (player.getPlayerBankings());

    int choice;
    while (true) {
        std::cout << "\n== Banking Panel ==\n"
                  << "1. Show Ongoing Plans\n"
                  << "2. Start Plan\n"
                  << "3. End Plan\n"
                  << "4. Exit to Main Menu\n"
                  << "Enter your choice: ";
        std::cin >> choice;
        std::cout << "\n";

        switch (choice) {
        case 1: {
            manager.showPlans();
            break;
        }
        case 2: {
            manager.startPlan(player.getPlayerStats());
            break;
        }
        case 3: {
            manager.endPlan(player.getPlayerStats());
            break;
        }
        case 4: {
            std::cout << "Exiting Banking Panel...\n";
            return;
        }
        default: {
            std::cout << "Enter a valid choice!\n";
            break;
        }
        }
    }
}
