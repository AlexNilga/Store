#ifndef STORE_PRODUCTCATALOG_H
#define STORE_PRODUCTCATALOG_H

#include <string>

using namespace std;

class ProductCatalog {
private:
    int m_id;
    string m_name;
    string m_description;

public:
    int getId() const { return m_id; }

    void setId(int id) { m_id = id; }

    string getName() { return m_name; }

    void setName(const string &name) { m_name = name; }

    string getDescription() { return m_description; }

    void setDescription(const string &description) { m_description = description; }
};

#endif
