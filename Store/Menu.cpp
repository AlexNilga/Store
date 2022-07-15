//
// Created by MykolaN on 7/15/2022.
//

#include <iostream>

#include "Menu.h"

Menu::Menu() {

}

void Menu::AddItem(const MenuItem &item) {
    this->items.push_back(item);
}

int Menu::Execute() {

    cout << endl << "Select action: " << endl;

    for (int i = 0; i < this->items.size(); ++i) {
        cout << '\t' << items[i].getTitle() << endl;
    }

    cout << endl << "You choice:> ";
    int command;

    std::cin >> command;

    return command;
}