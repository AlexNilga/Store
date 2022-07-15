#include <iostream>

#include ".\Store\Store.h"

int main() {

    Store store = Store();

    store.Run();

    std::cout << "Bye!";

    return 0;
}
