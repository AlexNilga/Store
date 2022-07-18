#include "ReportManager.h"
#include "../Menu/Menu.h"

const int cListCatalogsCommand = 1;
const int cListOffersCommand = 2;
const int cExitCommand = 3;

void ReportManager::Run() {
    Menu reportsMenu = Menu();

    reportsMenu.AddItem(MenuItem("1.", cListCatalogsCommand));
    reportsMenu.AddItem(MenuItem("2.", cListOffersCommand));
    reportsMenu.AddItem(MenuItem("3. Exit", cExitCommand));

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
