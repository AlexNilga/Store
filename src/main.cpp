#include <iostream>

#include "Managers/StoreManager.h"
#include "Repository/Repository.h"
#include "StoreException.h"

int main() {
    Repository repository = Repository();
    StoreManager store = StoreManager(repository);

    store.Run();

    try {
        // Initialize database.
        Repository::Init();

        Store store = Store();
        store.Run();

        std::cout << "Bye!";

    }
    catch (StoreException exception) {
        cerr << exception.GetMessage();
        return -1;
    }

    return 0;
}
