#include <iostream>

#include "Menu.h"

Menu::Menu() {

}

void Menu::AddItem(const MenuItem &item) {
    this->m_items.push_back(item);
}

int Menu::Execute() {

    while (true) {
        cout << endl << "Select action: " << endl;

        for (int i = 0; i < m_items.size(); ++i) {
            cout << "  " << m_items[i].getTitle() << endl;
        }

        cout << endl << "You choice:> ";
        int command;

        std::cin >> command;

        for (std::vector<MenuItem>::iterator it = m_items.begin(); it != m_items.end(); ++it) {
            if (command == it->getCommand()) {
                return command;
            }
        }
    }
}