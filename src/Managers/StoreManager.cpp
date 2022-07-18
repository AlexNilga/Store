#include "StoreManager.h"

StoreManager::StoreManager(Repository &repository)
        : m_catalogManager(repository) {

}

void StoreManager::Run() {
    const int cListCatalogsCommand = 1;
    const int cListOffersCommand = 2;
    const int cExitCommand = 0;

    Menu menu = Menu("Operations");

    menu.AddItem(MenuItem("1. Stock operations", cListCatalogsCommand));
    menu.AddItem(MenuItem("2. Reports", cListOffersCommand));
    menu.AddItem(MenuItem("0. Exit", cExitCommand));

    int command;

    do {
        command = menu.Execute();

        switch (command) {
            case 1:
                m_catalogManager.Run();
                break;

            case 2:
                m_reportManager.Run();

                break;
        }
    } while (command != cExitCommand);
}


