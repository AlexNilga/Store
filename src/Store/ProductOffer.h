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
    float m_price;
    int m_quantity;

public:
    ProductOffer(
            int id,
            string name,
            string description,
            int catalogId,
            float price,
            int quantity)
            : m_Id(id),
              m_name(std::move(name)),
              m_description(std::move(description)),
              m_catalogId(catalogId),
              m_price(price),
              m_quantity(quantity) {};

    int getId() const { return m_Id; }

    int getCatalogId() const { return m_catalogId; }

    string getName() { return m_name; }

    string getDescription() { return m_description; }

    float getPrice() { return m_price; }

    int getQuantity() { return m_quantity; }
};


#endif
