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
                ListCatalogs();
                break;
            case 2:
                ListOffers();
                break;
        }

    } while (catalogCommand != cExitCommand);
}

void CatalogManager::ListCatalogs() {

    vector<ProductCatalog> catalogs = m_repository.ListCatalogs();
    PrintCatalogs(catalogs);
}

void CatalogManager::ListOffers() {
    vector<ProductCatalog> catalogs = m_repository.ListCatalogs();

    int chooseCommand;
    const int cExitCommand = 0;

    Menu chooseMenu = Menu("Catalogs");

    for (auto &catalog: catalogs) {
        chooseMenu.AddItem(MenuItem(
                to_string(catalog.getId())
                + ". " + catalog.getName(),
                catalog.getId()));
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
                PrintOffers(offers);

                return;
            }
        }

    } while (true);
}


void CatalogManager::PrintCatalogs(vector<ProductCatalog> catalogs) {

    cout << endl << left
         << setw(5) << "ID"
         << setw(20) << "NAME"
         << setw(50) << "DESCRIPTION"
         << endl;

    for (auto &catalog: catalogs) {
        cout << left
             << setw(5) << catalog.getId()
             << setw(20) << catalog.getName()
             << setw(50) << catalog.getDescription()
             << endl;
    }
}

void CatalogManager::PrintOffers(vector<ProductOffer> offers) {
    cout << endl << left;
    cout << left
         << setw(5) << "ID"
         << setw(20) << "NAME"
         << setw(50) << "DESCRIPTION"
         << setw(8) << "PRICE"
         << setw(5) << " QTY"
         << endl;

    for (auto &offer: offers) {
        cout << left
             << setw(5) << offer.getId()
             << setw(20) << offer.getName()
             << setw(50) << offer.getDescription()
             << "$" << setw(8) << offer.getPrice()
             << setw(5) << offer.getQuantity()
             << endl;
    }
}



