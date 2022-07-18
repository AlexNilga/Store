#include <iostream>

#include "Managers/StoreManager.h"
#include "Repository/Repository.h"
#include "StoreException.h"

int main() {

    try {

        Repository repository = Repository();

        // Initialize database.
        repository.Init();

        StoreManager store = StoreManager(repository);

        store.Run();

        std::cout << "Bye!";

    }
    catch (const StoreException &exception) {
        cerr << exception.GetMessage();
        return -1;
    }

    return 0;
}
