#pragma once
#include <string>
#include <iostream>

struct Date { //Структура для хранения даты
    int day;
    int month;
    int year;
};

class Object {  //Класс для создания объекта
public:
    std::string _name;
    Date _expiryDate{};
    int _amount{};

    Object(std::string name, Date expiryDate, int amount);

    void Print() const;

    Object makeNewObject(Object object);
};
