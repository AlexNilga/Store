#ifndef STORE_CATALOG_MANAGER_H
#define STORE_CATALOG_MANAGER_H

#include <vector>
#include "../Store/ProductCatalog.h"
#include "../Repository/Repository.h"

class CatalogManager {

private:
    std::vector<ProductCatalog> m_catalog;
    Repository m_repository;

public:
    CatalogManager(Repository repository);

    std::vector<ProductCatalog> getCatalog() { return m_catalog; };

    void setCatalog(const std::vector<ProductCatalog> &catalog) { m_catalog = catalog; }

    void Run();

    void PrintCatalogs();
};

#endif
