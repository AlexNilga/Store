#ifndef STORE_PRODUCTOFFER_H
#define STORE_PRODUCTOFFER_H

#include <string>

using namespace std;

class ProductOffer {
private:
    int m_catalogId;
    string m_name;
    string m_description;
public:
    int getCatalogId() const { return m_catalogId; }

    void setId(int catalogId) { m_catalogId = catalogId; }

    string getName() { return m_name; }

    void setName(const string &name) { m_name = name; }

    string getDescription() { return m_description; }

    void setDescription(const string &description) { m_description = description; }
};


#endif
