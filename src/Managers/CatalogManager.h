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

    void ListOffers();
    void DeleteOffer();
    void AddOffer();

    void ChangeOffer();

    int GetCatalog();
    int GetOffer(int catalogId);

    void PrintCatalogs();
    void PrintOffers(int catalogId);

public:
    explicit CatalogManager(Repository &repository);

    void Run();

};

#endif
