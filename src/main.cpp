#include <iostream>

#include "Repository/Repository.h"
#include "StoreException.h"
#include "Managers/CatalogManager.h"

int main() {

    try {

        // Create repository and init database.
        Repository repository = Repository();
        repository.Init();

        CatalogManager catalogManager = CatalogManager(repository);
        catalogManager.Run();

        std::cout << "Bye!";

    }
    catch (const StoreException &exception) {
        cerr << exception.what();
        return -1;
    }

    return 0;
}
