#include <iostream>

int main() {
//Добавил небольшой комментарий
//Добавил еще один комментарий для создания конфликта в pull request
	cout << "Введите имя пользователя: ";
	string name;
	getline(cin, name);
	cout << "Hello world from " << name <<  endl;
	std::cout << "Введите имя пользователя: ";
	std::string name;
	std::getline(std::cin, name);
	std::cout << "Hello world from " << name <<  std::endl;
	return 0;
}
