#include <iostream>
#include <iomanip>
#include "CatalogManager.h"
#include "../Menu/Menu.h"

using namespace std;

const int cExitCommand = 0;

CatalogManager::CatalogManager(Repository &repository)
        : m_repository(repository) {
}

void CatalogManager::Run() {
    const int cListCatalogsCommand = 1;
    const int cListOffersCommand = 2;
    const int cDeleteOffersCommand = 3;
    const int cAddOffersCommand = 4;
    const int cChangeOffersCommand = 5;

    Menu catalogMenu = Menu("Operation");

    catalogMenu.AddItem(MenuItem("1. List Catalogs", cListCatalogsCommand));
    catalogMenu.AddItem(MenuItem("2. List Offers", cListOffersCommand));
    catalogMenu.AddItem(MenuItem("3. Delete Offer", cDeleteOffersCommand));
    catalogMenu.AddItem(MenuItem("4. Add Offer", cAddOffersCommand));
    catalogMenu.AddItem(MenuItem("5. Change Offer", cChangeOffersCommand));
    catalogMenu.AddItem(MenuItem("0. Go Back", cExitCommand));

    int catalogCommand;

    do {
        catalogCommand = catalogMenu.Execute();

        switch (catalogCommand) { // NOLINT(hicpp-multiway-paths-covered)
            case cListCatalogsCommand:
                PrintCatalogs();
                break;
            case cListOffersCommand:
                ListOffers();
                break;
            case cDeleteOffersCommand:
                DeleteOffer();
                break;
            case cAddOffersCommand:
                AddOffer();
                break;
            case cChangeOffersCommand:
                ChangeOffer();
                break;
        }

    } while (catalogCommand != cExitCommand);
}

void CatalogManager::ListOffers() {
    int catalogId = GetCatalog();
    if (catalogId != 0) {
        PrintOffers(catalogId);
    }
}

void CatalogManager::DeleteOffer() {

    int catalogId = GetCatalog();
    if (catalogId == cExitCommand) {
        return;
    }

    int offerId = GetOffer(catalogId);
    if (offerId == cExitCommand) {
        return;
    }

    m_repository.DeleteOffer(offerId);
    PrintOffers(catalogId);
}

void CatalogManager::AddOffer() {

    int catalogId = GetCatalog();
    if (catalogId == cExitCommand) {
        return;
    }

    string name;
    string description;
    float price;
    int quantity;

    cin.ignore();

    cout << "Enter offer name: ";
    getline(cin, name);
    cout << "Enter description: ";
    getline(cin, description);
    cout << "Enter offer price: ";
    cin >> price;
    cout << "Enter stock quantity: ";
    cin >> quantity;

    ProductOffer offer = ProductOffer(0, name, description, catalogId, price, quantity);
    m_repository.AddOffer(offer);

    PrintOffers(catalogId);
}

void CatalogManager::ChangeOffer() {

    int catalogId = GetCatalog();
    if (catalogId == cExitCommand) {
        return;
    }

    int offerId = GetOffer(catalogId);
    if (offerId == cExitCommand) {
        return;
    }

    vector<ProductOffer> offers = m_repository.ListOffers(catalogId);

    string name;
    string description;

    cin.ignore();

    cout << "Enter name: (" << offers[offerId - 1].getName() << ") Enter";
    getline(cin, name);
    if(name != ""){

    }

    cout << "Enter description: ";
    getline(cin, description);
    if(description != ""){

    }
}

/// Prints catalogs to the console.
/// \param catalogs
void CatalogManager::PrintCatalogs() {
    vector<ProductCatalog> catalogs = m_repository.ListCatalogs();

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

/// Prints product offers from a catalog to the console.
/// \param catalogId
void CatalogManager::PrintOffers(int catalogId) {

    vector<ProductOffer> offers = m_repository.ListOffers(catalogId);

    if (offers.empty()) {
        cout << "NO OFFERS IN THE CATALOG" << endl;
        return;
    }

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

int CatalogManager::GetCatalog() {
    vector<ProductCatalog> catalogs = m_repository.ListCatalogs();

    Menu menu = Menu("Choose Catalog: ");

    for (auto &catalog: catalogs) {
        menu.AddItem(MenuItem(
                to_string(catalog.getId())
                + ". " + catalog.getName(),
                catalog.getId()));
    }

    menu.AddItem(MenuItem("0. Go Back", cExitCommand));

    return menu.Execute();
}

int CatalogManager::GetOffer(int catalogId) {

    vector<ProductOffer> offers = m_repository.ListOffers(catalogId);

    Menu menu = Menu("Choose Offer: ");

    for (auto &offer: offers) {
        menu.AddItem(MenuItem(
                to_string(offer.getId())
                + ". " + offer.getName(),
                offer.getId()));
    }

    menu.AddItem(MenuItem("0. Go Back", cExitCommand));

    return menu.Execute();
}