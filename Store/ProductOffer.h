#ifndef Store_ProductOffer_H
#define Store_ProductOffer_H

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
