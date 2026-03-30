#include <iostream>
#include "point.h"
#include "rect.h"
/**
* @brief точка входа в программу
* @return 0, если программа выполнена правильно
*/
int main() {
	setlocale(LC_ALL, "rus");
	point a(0, 0);
	point b(0, 3);
	point c(3, 0);
	
	rect rectangle(a, b, c);
	std::cout << "Радиус описанной окружности:" << rectangle.getRad() << std::endl;
	std::cout << "Площадь описанной окружности:" << rectangle.getSq() << std::endl;
	return 0;

}
