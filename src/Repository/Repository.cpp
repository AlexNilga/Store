
#include "Repository.h"
#include "../StoreException.h"

const char *DATABASE_NAME = "../Database/store.db";

Repository::Repository() : m_database(nullptr) {

    int rc = sqlite3_open(DATABASE_NAME, &m_database);
    if (rc != SQLITE_OK) {
        throw StoreException(
                string("Can't open database: ") + sqlite3_errmsg(m_database));
    }
}

Repository::~Repository() {
    sqlite3_close(m_database);
}

void Repository::Init() {
    Repository repository = Repository();
    repository.InitDatabase();
}

void Repository::InitDatabase() {
    string sql = "CREATE TABLE IF NOT EXISTS Catalog("  \
         "ID INT PRIMARY KEY NOT NULL," \
         "NAME TEXT NOT NULL," \
         "DESCRIPTION TEXT NOT NULL);";

    if (sqlite3_exec(m_database, sql.c_str(), NULL, NULL, NULL) != SQLITE_OK) {
        throw new StoreException(
                string("Can't create table [Catalog]: ") + sqlite3_errmsg(m_database));
    }

    sql = "CREATE TABLE IF NOT EXISTS Offer("  \
         "ID INT PRIMARY KEY NOT NULL," \
         "NAME TEXT NOT NULL," \
         "DESCRIPTION TEXT NOT NULL," \
         "CATALOG_ID INT NOT NULL," \
         "PRICE REAL NOT NULL,"\
         "QUANTITY INT NOT NULL);";

    if (sqlite3_exec(m_database, sql.c_str(), NULL, NULL, NULL) != SQLITE_OK) {
        throw new StoreException(
                string("Can't create table [Offer]: ") + sqlite3_errmsg(m_database));
    }

}

/// Called by SQLite for each row in the catalogs dataset.
/// \param data Pointer to a vector of catalogs.
/// \param argc Holds the number of results.
/// \param argv Single row values.
/// \param azColName Column names.
/// \return Zero if case of success.
static int ReadCatalogsCallback(void *data, int argc, char **argv, char **azColName) {

    ((vector<ProductCatalog> *) data)->push_back(
            ProductCatalog(stoi(argv[0]), argv[1], argv[2]));

    return SQLITE_OK;
}


vector<ProductCatalog> Repository::ListCatalogs() {

    vector<ProductCatalog> catalogs;
    char *zErrMsg = 0;

    int rc = sqlite3_exec(
            m_database,
            "SELECT ID, NAME, DESCRIPTION FROM Catalog;",
            ReadCatalogsCallback,
            &catalogs,
            &zErrMsg);

    if (rc != SQLITE_OK) {
        throw new StoreException(
                string("Can't create table [Catalog]: ") + zErrMsg);
    }

    return catalogs;
}