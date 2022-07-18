#ifndef STORE_PRODUCT_OFFER_H
#define STORE_PRODUCT_OFFER_H

#include <string>

using namespace std;

class ProductOffer {

private:
    int m_Id;
    string m_name;
    string m_description;
    int m_catalogId;

public:
    ProductOffer(int id, string name, string description, int catalogId)
            : m_Id(id),
              m_name(std::move(name)),
              m_description(std::move(description)),
              m_catalogId(catalogId) {};

    int getCatalogId() const { return m_catalogId; }

    string getName() { return m_name; }

    string getDescription() { return m_description; }
};


#endif
