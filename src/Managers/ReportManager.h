#ifndef SRC_STORE_REPORT_MANAGER_H
#define SRC_STORE_REPORT_MANAGER_H

#include "../Repository/Repository.h"

class ReportManager {

private:
    Repository &m_repository;

public:
    explicit ReportManager(Repository &repository);

    void Run();
};

#endif
