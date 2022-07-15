//
// Created by MykolaN on 7/15/2022.
//

#ifndef FINAL_MENU_H
#define FINAL_MENU_H

#include <vector>
#include "MenuItem.h"


class Menu {

private:
    std::vector<MenuItem> items;

public:
    Menu();

    void AddItem(const MenuItem &item);

    int Execute();
};


#endif //FINAL_MENU_H
