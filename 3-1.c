#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <stdbool.h>
#include <math.h>
#include <locale.h>


/**
 * @brief рассчитывает значение функции y по заданной формуле
 * @param x значение
 * @return
 */
double getY(const double x);

/**
 * @brief считывает значение,
 * введенное с клавиатуры с проверкой ввода
 * @return считанное значение
 */
double getValue();

/**
 * @brief проверяет,что переменная положительная
 * @param step значение проверяемой переменной
 */
void checkStep(const double step);

/**
 * @brief проверяет, принадлежит ли значение аргумента функции её области определения
 * @param x - аргумент функции
 * @return true, если аргумент принадлежит ООФ, иначе false
 */
bool defineOOF(const double x);

/**
* @brief точка входа в программу
* @return возврат 0 в случае если программа работает правиьлно
*/
int main() {
	setlocale(LC_ALL, "rus");
	printf("Введите начальное значение: ");
	double start = getValue();
	printf("Введите конечное значение: ");
	double end = getValue();
	printf("Введите шаг: ");
	double step = getValue();
	checkStep(step);
	double x = start;

	while(x < end + DBL_EPSILON)
	{
		if (defineOOF(x))
			printf("x = %.2f y = %.6f\n", x, getY(x));
		else
			printf("x=%.2f не принадлежит ООФ", x);
		x += step;
	}
}

double getY(const double x) {
	return tan(x) - (1.0 / 3) * pow(tan(x), 3) + (1.0 / 5) * pow(tan(x), 5) - (1.0 / 3);
}

bool defineOOF(const double x) {
	return fabs(cos(fabs(x))) > DBL_EPSILON;
}

double getValue()
{
	double value = 0;
	if (!scanf_s("%lf", &value))
	{
		printf("Error\n");
		abort();
	}
	return value;
}

void checkStep(const double step)
{
	if (step <= DBL_EPSILON)
	{
		printf("Ошибка, шаг должен быть положительным\n");
		abort();
	}
}
