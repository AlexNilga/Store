#include <iostream>

#include "Menu.h"

Menu::Menu(string title)
        : m_items(),
          m_title(std::move(title)) {

}

void Menu::AddItem(const MenuItem &item) {
    this->m_items.push_back(item);
}

int Menu::Execute() {
    cout << endl << m_title << endl;

    for (auto &item: m_items) {
        cout << "  " << item.getTitle() << endl;
    }

    while (true) {
        cout << endl << "You choice:> ";
        int command;

        cin >> command;

        for (auto &m_item: m_items) {
            if (command == m_item.getCommand()) {
                return command;
            }
        }

        cout << "Undefined action " << command;
    }
}