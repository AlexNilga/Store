
#include "Store.h"

Store::Store()
        : mMenu() {
    mMenu.AddItem(MenuItem("1. Stock operations", cStockOperationsCommand));
    mMenu.AddItem(MenuItem("2. Reports", cReportsCommand));
    mMenu.AddItem(MenuItem("3. Exit", cExitCommand));
}

void Store::Run() {
    int command;

    do{
        command = mMenu.Execute();
    }
    while(command != cExitCommand);
}


