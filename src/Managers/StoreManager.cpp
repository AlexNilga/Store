#include "StoreManager.h"

const int cListCatalogsCommand = 1;
const int cListOffersCommand = 2;
const int cExitCommand = 3;

StoreManager::StoreManager(Repository repository)
        : m_catalogManager(repository) {

}

void StoreManager::Run() {
    Menu menu = Menu();

    menu.AddItem(MenuItem("1. Stock operations", cListCatalogsCommand));
    menu.AddItem(MenuItem("2. Reports", cListOffersCommand));
    menu.AddItem(MenuItem("3. Exit", cExitCommand));


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


