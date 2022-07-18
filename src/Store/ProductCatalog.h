#ifndef STORE_PRODUCT_CATALOG_H
#define STORE_PRODUCT_CATALOG_H

#include <string>

using namespace std;

class ProductCatalog {
private:
    int m_id;
    string m_name;
    string m_description;

public:
    ProductCatalog(int id,
                   const string &name,
                   const string &description)
            : m_id(id),
              m_name(name),
              m_description(description) {};

    int getId() const { return m_id; }

    string getName() { return m_name; }

    string getDescription() { return m_description; }
};

#endif
