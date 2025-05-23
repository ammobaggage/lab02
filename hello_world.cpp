#include <iostream>

int
main()
{
  // Добавил небольшой комментарий
  std::cout << "Введите имя пользователя: ";
  std::string name;
  std::getline(std::cin, name);
  std::cout << "Hello world from " << name << std::endl;
  return 0;

}
