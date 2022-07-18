#include "StoreManager.h"

StoreManager::StoreManager(Repository &repository)
        : m_catalogManager(repository),
          m_reportManager(repository) {

}

void StoreManager::Run() {
    const int cCatalogCommands = 1;
    const int cReportCommands = 2;
    const int cExitCommand = 0;

    Menu menu = Menu("Operations");

    menu.AddItem(MenuItem("1. Product Catalog", cCatalogCommands));
    menu.AddItem(MenuItem("2. Reports", cReportCommands));
    menu.AddItem(MenuItem("0. Exit Application", cExitCommand));

    int command;

    do {
        command = menu.Execute();

        switch (command) { // NOLINT(hicpp-multiway-paths-covered)
            case cCatalogCommands:
                m_catalogManager.Run();
                break;

            case cReportCommands:
                m_reportManager.Run();
                break;
        }
    } while (command != cExitCommand);
}


