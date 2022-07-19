#include <iostream>

#include "Managers/StoreManager.h"
#include "Repository/Repository.h"
#include "StoreException.h"

int main() {

    try {

        // Create repository and init database.
        Repository repository = Repository();
        repository.Init();

        StoreManager store = StoreManager(repository);
        store.Run();

        std::cout << "Bye!";

    }
    catch (const StoreException &exception) {
        cerr << exception.what();
        return -1;
    }

    return 0;
}
