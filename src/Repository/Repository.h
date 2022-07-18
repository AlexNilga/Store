#ifndef STORE_REPOSITORY_H
#define STORE_REPOSITORY_H

#include <vector>

#include "../SQLite/sqlite3.h"
#include "../Store/ProductCatalog.h"
#include "../Store/ProductOffer.h"

using namespace std;

class Repository {

private:
    sqlite3 *m_database;

public:
    Repository();

    ~Repository();

    void Init();

    vector<ProductCatalog> ListCatalogs();

    vector<ProductOffer> ListOffers(int catalogId);
};


#endif //STORE_REPOSITORY_H
