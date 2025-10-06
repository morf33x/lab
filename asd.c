#include <stdio.h>

/**
* @brief Рассчитывает функцию A по данной формуле
* @param x - значение параметра x
* @param y - значение параметра y
* @param z - значение параметра z
* @return рассчитанное значение
*/
double getA(const double x, const double y, const double z);
/**
* @brief Рассчитывает функцию B по данной формуле
* @param x - значение параметра x
* @param y - значение параметра y
* @param z - значение параметра z
* @return рассчитанное значение
*/
double getB(const double x, const double y, const double z);

/**
* @brief точка входа в программу
* @return возврат 0 если нет ошибок
*/
int main() {
	const double x = 0.2;
	const double y = 0.004;
	const double z = 1.1;

	const double a = getA(x, y, z);
	const double b = getB(x, y, z);

	printf("x = %.1f\n", x);
	printf("y = %.3f\n", y);
	printf("z = %.1f\n\n", z);
	printf("A = %.6f\n", a);
	printf("B = %.6f\n", b);

	return 0;
}

double getA(const double x, const double y, const double z) {
	return pow(sin((x * x + z) * (x * x + z)), 3) - sqrt(x / y);
}
double getB(const double x, const double y, const double z) {
	return (x * x) / z + cos(pow(x + y, 3));
}
