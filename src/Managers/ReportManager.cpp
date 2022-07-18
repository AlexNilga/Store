#include "ReportManager.h"
#include "../Menu/Menu.h"

void ReportManager::Run() {
    const int option1 = 1;
    const int option2 = 2;
    const int cExitCommand = 0;


    Menu reportsMenu = Menu("Reports");

    reportsMenu.AddItem(MenuItem("1.", option1));
    reportsMenu.AddItem(MenuItem("2.", option2));
    reportsMenu.AddItem(MenuItem("0. Exit", cExitCommand));

    int reportCommand;

    do {
        reportCommand = reportsMenu.Execute();

        switch (reportCommand) {
            case 1:
                break;
            case 2:
                break;

        }
    } while (reportCommand != cExitCommand);
}
