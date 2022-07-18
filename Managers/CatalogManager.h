#ifndef STORE_CATALOGMANAGER_H
#define STORE_CATALOGMANAGER_H

#include <vector>
#include "../Store/ProductCatalog.h"

class CatalogManager {
private:
    std::vector<ProductCatalog> m_catalog;
public:
    std::vector<ProductCatalog> getCatalog(){return m_catalog;};

    void setCatalog(const std::vector<ProductCatalog> &catalog){m_catalog = catalog;}
};


#endif
