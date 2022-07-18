#include <iostream>

#include "Menu.h"

Menu::Menu() : m_items() {

}

void Menu::AddItem(const MenuItem &item) {
    this->m_items.push_back(item);
}

int Menu::Execute() {

    while (true) {
        cout << endl << "Select action: " << endl;

        for (auto & item : m_items) {
            cout << "  " << item.getTitle() << endl;
        }

        cout << endl << "You choice:> ";
        int command;

        cin >> command;

        for (auto & m_item : m_items) {
            if (command == m_item.getCommand()) {
                return command;
            }
        }
    }
}