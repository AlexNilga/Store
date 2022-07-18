#ifndef STORE_STORE_H
#define STORE_STORE_H

#include "../Menu/Menu.h"
#include "CatalogManager.h"
#include "ReportManager.h"

class StoreManager {
private:
CatalogManager m_catalogManager;
ReportManager m_reportManager;

public:

    explicit StoreManager(Repository &repository);

    void Run();
};


#endif //STORE_STORE_H
