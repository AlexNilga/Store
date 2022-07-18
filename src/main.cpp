#include <iostream>

#include "Managers/StoreManager.h"

int main() {
    Repository repository = Repository();
    StoreManager store = StoreManager(repository);

    store.Run();

    std::cout << "Bye!";

    return 0;
}
