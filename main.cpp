
#include ".\Store\Menu.h"

int main() {

    Menu menu = Menu();
    menu.AddItem(MenuItem("1. Choice 1", 1));
    menu.AddItem(MenuItem("2. Choice 2", 2));
    menu.AddItem(MenuItem("3. Choice 3", 3));
    menu.AddItem(MenuItem("4. Choice 4", 4));

    menu.Execute();
}
