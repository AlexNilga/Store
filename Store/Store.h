#ifndef STORE_STORE_H
#define STORE_STORE_H

#include "Menu.h"

class Store {
private:
    const int cStockOperationsCommand = 1;
    const int cReportsCommand = 2;
    const int cExitCommand = 3;

    Menu mMenu;
public:

    Store();

    void Run();
};


#endif //STORE_STORE_H
