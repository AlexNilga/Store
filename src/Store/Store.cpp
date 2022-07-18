
#include "Store.h"

const int cStockOperationsCommand = 1;
const int cReportsCommand = 2;
const int cExitCommand = 3;

Store::Store() : mMenu() {
    mMenu.AddItem(MenuItem("1. Stock operations", cStockOperationsCommand));
    mMenu.AddItem(MenuItem("2. Reports", cReportsCommand));
    mMenu.AddItem(MenuItem("3. Exit", cExitCommand));
}

void Store::Run() {

    int command;

    do {
        command = mMenu.Execute();
    } while (command != cExitCommand);
}


