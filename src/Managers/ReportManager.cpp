#include "ReportManager.h"
#include "../Menu/Menu.h"

/// Initializes new instance of ReportManager.
/// \param repository
ReportManager::ReportManager(Repository &repository)
        : m_repository{repository} {

}

///
void ReportManager::Run() {
    const int option1 = 1;
    const int option2 = 2;
    const int cExitCommand = 0;


    Menu reportsMenu = Menu("Reports");

    reportsMenu.AddItem(MenuItem("1. List Offers (low stock first)", option1));
    reportsMenu.AddItem(MenuItem("2. List Offers (cheap to expensive)", option2));
    reportsMenu.AddItem(MenuItem("0. Go Back", cExitCommand));

    int reportCommand;

    do {
        reportCommand = reportsMenu.Execute();

        switch (reportCommand) { // NOLINT(hicpp-multiway-paths-covered)
            case option1:
                break;

            case option2:
                break;

        }
    } while (reportCommand != cExitCommand);
}
