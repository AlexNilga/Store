#include "Object.h"

Object::Object(std::string name, Date expiryDate, int amount) { //Конструктор класса
    _name = name;
    _expiryDate = expiryDate;
    _amount = amount;
}

void Object::Print() const { //Метод для вывода объекта класса на консоль
    std::cout << _name << '\n';
    std::cout << _expiryDate.day << '.'
        << _expiryDate.month << '.'
        << _expiryDate.year << "\n";
    std::cout << _amount << '\n';
}


Object makeNewObject(Object object) //Создание нового объекта 
{

    return object;
}
