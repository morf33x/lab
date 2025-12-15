#include <stdio.h>
#include <math.h>
#include <locale.h>
/**
* @brief запись числа в нужном формате
*/
double getDouble();
/**
* @brief проверка знака введенного числа
* @param value введенное число
*/
void checkPositive(const double value);
/**
* @brief сумма первых n чисел последовательности больших по модулю e
* @param n количество чисел последовательности начиная с 1
* @brief e точность с которой считают сумму
* @param y точное значение функции
*/
double getSum(const double x, const double e, const double y);
/**
* @brief проверяет что начальное значение меньше конечного
* @param start начальное значение
* @param end конечное значение
*/
void checkInterval(const double start, const double end);
/**
* @brief Ищет значение y
* @param значение x
* @return значение y
*/
double getY(const double x);
/**
* @brief точка входа в программу
* @return возврат 0 если программа закончилась успешно
*/
int main() {
	setlocale(LC_ALL, "rus");
	printf("Введите левую границу интервала ");
	const double start = getDouble();
	printf("Введите правую границу интервала ");
	const double end = getDouble();
	checkInterval(start, end);
	printf("Введите шаг ");
	const double h = getDouble();
	checkPositive(h);
	printf("Введите точность ");
	const double e = getDouble();
	checkPositive(e);
	printf("x        y        S\n");
	for (double x = start; !(x > end); x += h) {
		printf("%f %f %f\n", x, getY(x), getSum(x, e, getY(x)));
	}
	return 0;
}

double getY(const double x) {
	return (exp(x) + exp(-x)) / 2.0;
}
double getDouble() {
	double value = 0;
	if (!scanf_s("%lf", &value)) {
		printf("Error");
		exit(1);
	}
	return value;
}
void checkPositive(const double value) {
	if (!value > 0) {
		printf("Error");
		exit(1);
	}
}
void checkInterval(const double start, const double end) {
	if (end < start) {
		printf("Error");
		abort();
	}
}
double getSum(const double x, const double e,const double y) {
	double current = 1;
	double n_current = 1;
	for (int k = 0;y - current > e; k++) {
		n_current *= (x * x) / ((2.0 * k + 1.0) * (2.0 * k + 2.0));
		current += n_current;
	}
	return current;
}
