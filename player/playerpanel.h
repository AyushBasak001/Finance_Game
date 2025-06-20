#ifndef PLAYERPANEL_H
#define PLAYERPANEL_H

#include "../banking/bankingpanel.h"
#include "../cashflow/cashflowpanel.h"
#include "../investment/investmentpanel.h"

class PlayerPanel
{
public:
    PlayerPanel();
    static void run(Player& player);
};

#endif // PLAYERPANEL_H
