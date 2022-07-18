#include <iostream>

#include "Store/Store.h"
#include "Repository/Repository.h"
#include "StoreException.h"

int main() {

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
