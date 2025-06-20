#include "playerpanel.h"

#include <fstream>

PlayerPanel::PlayerPanel() {}

void PlayerPanel::run(Player &player) {
    int choice;

    while (true) {
        std::cout << "\n== Main Menu ==\n"
                  << "1. Show Current Status\n"
                  << "2. Go to Investments\n"
                  << "3. Go to Cash Flow\n"
                  << "4. Go to Bank\n"
                  << "5. Next Month\n"
                  << "6. Exit\n"
                  << "Enter your choice: ";
        std::cin >> choice;
        std::cout << "\n";

        switch (choice) {
        case 1:{
            PlayerStats(player.getPlayerStats()).showStats();
            break;
        }
        case 2:{
            InvestmentPanel::run(player);
            break;
        }
        case 3:{
            CashflowPanel::run(player);
            break;
        }
        case 4:{
            BankingPanel::run(player);
            break;
        }
        case 5:{
            if(player.goodToGo())
                player.advanceMonth();
            else{
                std::cout<<"You Lost!!\n";
                player.getPlayerStats().showStats();
                return;
            }
            break;
        }
        case 6:{
            std::cout << "Exiting game. Goodbye!\n";
            return;
        }
        default:
            std::cout << "Enter a valid choice!\n";
            break;
        }
    }
}
