#ifndef STORE_CATALOG_MANAGER_H
#define STORE_CATALOG_MANAGER_H

#include <vector>
#include "../Store/ProductCatalog.h"
#include "../Repository/Repository.h"

using namespace std;

class CatalogManager {

private:
    enum SortDirection {
        None, Name, Quantity, Price
    };

    std::vector<ProductCatalog> m_catalog;
    Repository &m_repository;

    int GetCatalog();

    void ListOffers(SortDirection sortDirection);

    void DeleteOffer();

    void AddOffer();

    void ChangeOffer();

    void Search();

    int GetOffer(int catalogId);

    void PrintCatalogs();

    void PrintOffers(int catalogId, SortDirection sortDirection = None);

    static void PrintOffers(const vector<ProductOffer> &offers);

public:
    explicit CatalogManager(Repository &repository);

    void Run();
};

#endif
