#ifndef STORE_CATALOG_MANAGER_H
#define STORE_CATALOG_MANAGER_H

#include <vector>
#include "../Store/ProductCatalog.h"
#include "../Repository/Repository.h"

using namespace std;

class CatalogManager {

private:
    std::vector<ProductCatalog> m_catalog;
    Repository &m_repository;

    void ListCatalogs();
    void ListOffers();

    static void PrintCatalogs(vector<ProductCatalog> catalogs);
    static void PrintOffers(vector<ProductOffer> offers);

public:
    explicit CatalogManager(Repository &repository);

    void Run();

};

#endif
