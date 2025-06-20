#include "player/playerpanel.h"

#include <cstdlib>
#include <ctime>

int main()
{
    srand(static_cast<unsigned int>(time(0)));

    Player P1("Ayush") ;
    PlayerPanel::run(P1) ;
    return 0;
}
