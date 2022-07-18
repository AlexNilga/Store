#ifndef STORE_REPOSITORY_H
#define STORE_REPOSITORY_H

#include "../SQLite/sqlite3.h"

class Repository {
private:
    sqlite3 *m_database;

public:
    Repository();

    ~Repository();
};


#endif //STORE_REPOSITORY_H
