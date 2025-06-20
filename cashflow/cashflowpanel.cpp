#include "cashflowpanel.h"

CashflowPanel::CashflowPanel() {}

void CashflowPanel::run(Player &player){

    CashflowManager &manager(player.getPlayerCashflows());

    int choice;
    while (true) {
        std::cout << "\n== Cash Flow Panel ==\n"
                  << "1. Show Current Status\n"
                  << "2. Toggle Cash Flow\n"
                  << "3. Exit to Main Menu\n"
                  << "Enter your choice: ";
        std::cin >> choice;
        std::cout << "\n";

        switch (choice) {
        case 1: {
            manager.showTransactions();
            break;
        }
        case 2: {
            manager.toggleTransaction();
            break;
        }
        case 3: {
            std::cout << "Exiting Cash Flow Panel...\n";
            return;
        }
        default: {
            std::cout << "Enter a valid choice!\n";
            break;
        }
        }
    }
}
