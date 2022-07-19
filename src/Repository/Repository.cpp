
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


/// Creates missing database tables, indexes, etc.
void Repository::Init() {

    string sql = "CREATE TABLE IF NOT EXISTS Catalog("  \
         "ID INTEGER PRIMARY KEY," \
         "NAME TEXT NOT NULL," \
         "DESCRIPTION TEXT NOT NULL);";

    if (sqlite3_exec(m_database, sql.c_str(), nullptr, nullptr, nullptr) != SQLITE_OK) {
        throw StoreException(
                string("Can't create table [Catalog]: ") + sqlite3_errmsg(m_database));
    }

    sql = "CREATE TABLE IF NOT EXISTS Offer("  \
         "ID INTEGER PRIMARY KEY," \
         "NAME TEXT NOT NULL," \
         "DESCRIPTION TEXT NOT NULL," \
         "CATALOG_ID INT NOT NULL," \
         "PRICE REAL NOT NULL,"\
         "QUANTITY INT NOT NULL);";

    if (sqlite3_exec(m_database, sql.c_str(), nullptr, nullptr, nullptr) != SQLITE_OK) {
        throw StoreException(string("Can't create table [Offer]: ") + sqlite3_errmsg(m_database));
    }
}

/// Called by SQLite for each row in the catalogs dataset.
/// \param data Pointer to a vector of catalogs.
/// \param argc Holds the number of results.
/// \param argv Single row values.
/// \param azColName Column names.
/// \return Zero if case of success.
static int ReadCatalogsCallback(
        void *data,
        __attribute__((unused)) int argc,
        char **argv,
        __attribute__((unused)) char **azColName) {

    ((vector<ProductCatalog> *) data)->push_back(
            ProductCatalog(stoi(argv[0]), argv[1], argv[2]));

    return SQLITE_OK;
}

/// Called by SQLite for each row in the product offers dataset.
/// \param data Pointer to a vector of product offers.
/// \param argc Holds the number of results.
/// \param argv Single row values.
/// \param azColName Column names.
/// \return Zero if case of success.
static int ReadOffersCallback(
        void *data,
        __attribute__((unused)) int argc,
        char **argv,
        __attribute__((unused)) char **azColName) {

    ((vector<ProductOffer> *) data)->push_back(
            ProductOffer(
                    stoi(argv[0]),
                    argv[1],
                    argv[2],
                    stoi(argv[3]),
                    stof(argv[4]),
                    stoi(argv[5])));

    return SQLITE_OK;
}

/// Called by SQLite for each row in the product offers dataset.
/// \param data Pointer to product offer.
/// \param argc Holds the number of results.
/// \param argv Single row values.
/// \param azColName Column names.
/// \return Zero if case of success.
static int ReadSingleOfferCallback(
        void *data,
        __attribute__((unused)) int argc,
        char **argv,
        __attribute__((unused)) char **azColName) {

    *((ProductOffer*) data) = ProductOffer(
            stoi(argv[0]),
            argv[1],
            argv[2],
            stoi(argv[3]),
            stof(argv[4]),
            stoi(argv[5]));

    return SQLITE_ABORT;
}

/// Lists available product catalogs.
/// \return collection of catalogs.
vector<ProductCatalog> Repository::ListCatalogs() {

    vector<ProductCatalog> catalogs;

    int rc = sqlite3_exec(
            m_database,
            "SELECT ID, NAME, DESCRIPTION FROM Catalog;",
            ReadCatalogsCallback,
            &catalogs,
            nullptr);

    if (rc != SQLITE_OK) {
        throw StoreException(string("Cannot retrieve catalogs: ") + sqlite3_errmsg(m_database));
    }

    return catalogs;
}

/// Lists product offers from a catalog.
/// \param catalogId Catalog ID.
/// \return Collection of product offers.
vector<ProductOffer> Repository::ListOffers(int catalogId) {

    vector<ProductOffer> offers;

    string sql = "SELECT ID, NAME, DESCRIPTION, CATALOG_ID, PRICE, QUANTITY FROM Offer WHERE CATALOG_ID="
                 + to_string(catalogId)
                 + ";";

    int rc = sqlite3_exec(
            m_database,
            sql.c_str(),
            ReadOffersCallback,
            &offers,
            nullptr);

    if (rc != SQLITE_OK) {
        throw StoreException(string("Cannot retrieve product offers: ") + sqlite3_errmsg(m_database));
    }

    return offers;
}

/// Gets offer by ID.
/// \param offerId offer ID
/// \return
ProductOffer Repository::GetOffer(int offerId) {

    ProductOffer offer = ProductOffer(0, "", "", 0, 0, 0);

    string sql = "SELECT ID, NAME, DESCRIPTION, CATALOG_ID, PRICE, QUANTITY FROM Offer WHERE ID="
                 + to_string(offerId)
                 + ";";

    int rc = sqlite3_exec(
            m_database,
            sql.c_str(),
            ReadSingleOfferCallback,
            &offer,
            nullptr);

    if (rc != SQLITE_OK && rc!=SQLITE_ABORT) {
        throw StoreException(string("Cannot retrieve product offer: ") + sqlite3_errmsg(m_database));
    }

    return offer;
}

/// Adds product offer to the database
/// \param offer
void Repository::AddOffer(const ProductOffer &offer) {

    string sql = "INSERT INTO Offer(NAME,DESCRIPTION,CATALOG_ID,PRICE,QUANTITY) VALUES(\""
                 + offer.getName() + "\",\""
                 + offer.getDescription() + "\","
                 + to_string(offer.getCatalogId()) + ","
                 + to_string(offer.getPrice()) + ","
                 + to_string(offer.getQuantity())
                 + ");";

    int rc = sqlite3_exec(
            m_database,
            sql.c_str(),
            nullptr,
            nullptr,
            nullptr);

    if (rc != SQLITE_OK) {
        throw StoreException(string("Cannot insert offer into the database: ") + sqlite3_errmsg(m_database));
    }
}

/// Deletes offer from the database.
/// \param offerId
void Repository::DeleteOffer(int offerId) {

    string sql = "DELETE FROM Offer WHERE ID = " + to_string(offerId) + ";";
    int rc = sqlite3_exec(
            m_database,
            sql.c_str(),
            nullptr,
            nullptr,
            nullptr);

    if (rc != SQLITE_OK) {
        throw StoreException(
                string("Cannot delete offer [") + to_string(offerId) + "] from the database: "
                + sqlite3_errmsg(m_database));
    }
}

/// Update offer in the database.
/// \param offer
void Repository::UpdateOffer(const ProductOffer &offer) {

    string sql = string("UPDATE Offer SET ")
                 + "NAME=\"" + offer.getName() + "\", "
                 + "DESCRIPTION=\"" + offer.getDescription() + "\", "
                 + "CATALOG_ID=" + to_string(offer.getCatalogId()) + ", "
                 + "PRICE=" + to_string(offer.getPrice()) + ", "
                 + "QUANTITY=" + to_string(offer.getQuantity())
                 + " WHERE ID=" + to_string(offer.getId()) + ";";

    int rc = sqlite3_exec(
            m_database,
            sql.c_str(),
            nullptr,
            nullptr,
            nullptr);

    if (rc != SQLITE_OK) {
        throw StoreException(string("Cannot update offer in the database: ") + sqlite3_errmsg(m_database));
    }
}
