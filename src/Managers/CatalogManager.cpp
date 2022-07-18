#include <iostream>
#include <iomanip>
#include "CatalogManager.h"
#include "../Menu/Menu.h"
#include "../Store/ProductOffer.h"

using namespace std;

CatalogManager::CatalogManager(Repository &repository)
        : m_repository(repository) {
}

void CatalogManager::Run() {
    const int cListCatalogsCommand = 1;
    const int cListOffersCommand = 2;
    const int cExitCommand = 0;

    Menu catalogMenu = Menu("Operation");

    catalogMenu.AddItem(MenuItem("1. List Catalogs", cListCatalogsCommand));
    catalogMenu.AddItem(MenuItem("2. List Offers", cListOffersCommand));
    catalogMenu.AddItem(MenuItem("0. Exit", cExitCommand));

    int catalogCommand;

    do {
        catalogCommand = catalogMenu.Execute();

        switch (catalogCommand) { // NOLINT(hicpp-multiway-paths-covered)
            case 1:
                PrintCatalogs();
                break;
            case 2:
                PrintOffers();
                break;
        }

    } while (catalogCommand != cExitCommand);
}

void CatalogManager::PrintCatalogs() {
    vector<ProductCatalog> catalogs = m_repository.ListCatalogs();

    cout << "Select catalog: " << '\n' << left;

    for (auto &catalog: catalogs) {
        cout << setw(3) << catalog.getId()
             << setw(20) << catalog.getName()
             << catalog.getDescription() << '\n';
    }
}

void CatalogManager::PrintOffers() {
    vector<ProductCatalog> catalogs = m_repository.ListCatalogs();

    int chooseCommand;
    const int cExitCommand = 0;

    Menu chooseMenu = Menu("Catalogs");

    for (auto &catalog: catalogs) {
        chooseMenu.AddItem(MenuItem(to_string(catalog.getId()) + ". " + catalog.getName(), catalog.getId()));
    }

    chooseMenu.AddItem(MenuItem("0. Exit", cExitCommand));

    do {
        chooseCommand = chooseMenu.Execute();

        if (chooseCommand == cExitCommand) {
            return;
        }

        for (auto &catalog: catalogs) {
            if (chooseCommand == catalog.getId()) {
                vector<ProductOffer> offers = m_repository.ListOffers(chooseCommand);
                //Print offers
                return;
            }
        }

    } while (true);
}



