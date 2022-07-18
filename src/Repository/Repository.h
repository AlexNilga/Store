#ifndef STORE_REPOSITORY_H
#define STORE_REPOSITORY_H

#include <vector>
#include "../SQLite/sqlite3.h"
#include "../Store/ProductCatalog.h"

using namespace std;

class Repository {
private:
    sqlite3 *m_database;

public:
    Repository();

    ~Repository();

    vector<ProductCatalog *> ListCatalogs();
};


#endif //STORE_REPOSITORY_H
