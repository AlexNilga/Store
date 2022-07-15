#include <iostream>
#include <windows.h>
#include "Object.h"
#include <list>

int main() {
	setlocale(LC_ALL, "Russian"); //Русский язык
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	std::cout << "Выберите опцию:" << '\n'
		<< "1) Посмотреть товары в наличии" << '\n'
		<< "2) Добавить товар\n"
		<< "3) Изменить товар\n"
		<< "4) Удалить товар\n"
		<< "5) Отсортировать товары\n"
		<< "6) Выход\n";

	int choice;
	while (true) {
		std::cout << "Введите число: ";
		std::cin >> choice;

		switch (choice) {
		case(1):
			break;
		case(2):
			break;
		case(3):
			break;
		case(4):
			break;
		case(5):
			break;
		case(6):
			return 0;

		default:
			std::cout << "Неверный выбор\n";
		}
	}
	return 0;
}

