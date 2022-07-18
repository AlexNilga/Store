#include <iostream>
#include <iomanip>
#include "CatalogManager.h"
#include "../Menu/Menu.h"

using namespace std;

CatalogManager::CatalogManager(Repository &repository)
        : m_repository(repository) {
}

void CatalogManager::Run() {
    const int cListCatalogsCommand = 1;
    const int cListOffersCommand = 2;
    const int cExitCommand = 3;

    Menu catalogMenu = Menu();

    catalogMenu.AddItem(MenuItem("1. List Catalogs", cListCatalogsCommand));
    catalogMenu.AddItem(MenuItem("2. List Offers", cListOffersCommand));
    catalogMenu.AddItem(MenuItem("3. Exit", cExitCommand));

    int catalogCommand;

    do {
        catalogCommand = catalogMenu.Execute();

        switch (catalogCommand) { // NOLINT(hicpp-multiway-paths-covered)
            case 1:
                PrintCatalogs();
                break;
            case 2:
                break;
        }

    } while (catalogCommand != cExitCommand);
}

void CatalogManager::PrintCatalogs() {
    vector<ProductCatalog> catalogs = m_repository.ListCatalogs();

    cout << "Your catalog: " << '\n' << left;

    for (auto &catalog: catalogs) {
        cout << setw(3) << catalog.getId()
             << setw(20) << catalog.getName()
             << catalog.getDescription() << '\n';
    }
}

