
#include ".\Store\Menu.h"

int main() {

    Menu menu = Menu();
    menu.AddItem(MenuItem("Choice 1", 1));
    menu.AddItem(MenuItem("Choice 2", 2));
    menu.AddItem(MenuItem("Choice 3", 3));
    menu.AddItem(MenuItem("Choice 3", 4));

    menu.Execute();
}
