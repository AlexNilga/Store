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
    ProductCatalog(
            int id,
            string name,
            string description)
            : m_id(id),
              m_name(std::move(name)),
              m_description(std::move(description)) {};

    int getId() const { return m_id; }

    string getName() const { return m_name; }

    string getDescription() const { return m_description; }
};

#endif
