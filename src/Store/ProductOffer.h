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
    ProductOffer(int id,
                 const string &name,
                 const string &description,
                 int catalogId)
            : m_Id(id),
              m_name(name),
              m_description(description),
              m_catalogId(catalogId) {};

    int getCatalogId() const { return m_catalogId; }

    string getName() { return m_name; }

    string getDescription() { return m_description; }

    void setId(int id) { m_Id = id; }
};


#endif
