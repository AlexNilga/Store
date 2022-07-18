#include "Repository.h"

const char *DATABASE_NAME = "../Database/store.db";

Repository::Repository() {

    int rc = sqlite3_open(DATABASE_NAME, &m_database);
}

Repository::~Repository() {
    sqlite3_close(m_database);
}

vector<ProductCatalog*> Repository::ListCatalogs() {
    return vector<ProductCatalog*>();
}
