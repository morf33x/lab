#include <stdio.h>
#include <math.h>
#include <locale.h>

/**
* @brief Рассчитывает время по заданной формуле
* param A значение работы
* param F значение силы
* return рассчитанный путь
*/
double getS(const double F, const double A);
/**
* @brief Точка входа в программу
* @return Возвращает 0, если программа выполнена корректно
*/
int main() {
	setlocale(LC_ALL, "Rus");
	double A = 0;
	double F = 0;
	printf("Работа,МДж -");
	scanf_s("\n%lf", &A);
	printf("Сила,кН -");
	scanf_s("\n%lf", &F);
	printf("Пройденный путь - %f", getS(F, A));
	return 0;
}
double getS(const double F, const double A) {
	return A * 1e6 / (F * 1e3);
}
