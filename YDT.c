#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>

/**
* @brief расчет площади полной поверхности конуса
* @param r радиус основания конуса
* @param a угол при вершине в осевом сечении
* @return площадь поверхности
*/
double area(const double r, const double a);
/**
* @brief расчет объема конуса
* @param r радиус основания конуса
* @param a угол при вершине в осевом сечении
* @return объем
*/
double volume(const double r, const double a);
/**
* @brief точка входа в программу
* @return возврат 0 если нет ошибок
*/
int main(void) {
	double R;
	double a;
	printf("Введите радиус основания:");
	scanf_s("%lf", &R);
	printf("Ввелите угол при вершине в градусах:");
	scanf_s("%lf", &a);
	
	printf("Площадь поверхности конуса: %.6f\n", area(R, a));
	printf("Объем конуса: %.6f\n", volume(R, a));
	return 0;
}

double area(const double r, const double a) {
	const double l = r / sin(a / 180*M_PI);
	return M_PI * r * (r + l);
}

double volume(const double r, const double a) {
	const double h = r / tan(a / 180 * M_PI);
	return M_PI * r * r * h / 3;
}
