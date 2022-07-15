#ifndef FINAL_MENUITEM_H
#define FINAL_MENUITEM_H

#include <string>

using namespace std;

class MenuItem {
private:
    string title;
    int command;

public:
    MenuItem(const string &title, int command);

    string getTitle() { return this->title; }

    int getCommand() { return this->command; }

};


#endif //FINAL_MENUITEM_H
