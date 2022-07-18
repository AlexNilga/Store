#ifndef FINAL_MENU_H
#define FINAL_MENU_H

#include <vector>
#include "MenuItem.h"

using namespace std;

class Menu {

private:
    vector<MenuItem> m_items;

public:
    Menu();

    void AddItem(const MenuItem &item);

    int Execute();
};


#endif //FINAL_MENU_H
