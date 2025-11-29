#include <stdio.h>
#include <math.h>
/**
* @brief запись числа в нужном формате
*/
double getDouble();
/**
* @brief запись числа в нужном формате
*/
int getInt();
/**
* @brief проверка знака введенного числа
* @param value введенное число
*/
void checkPositive(const int value);
/**
* @brief сумма первых n чисел последовательности
* @param n количество чисел последовательности начиная с 1
*/
double getSumN(const int n);
/**
* @brief сумма первых n чисел последовательности больших по модулю e
* @param n количество чисел последовательности начиная с 1
* @brief e 
*/
double getSumE(const double e,const int n);
/**
* @brief точка входа в программу
* @return возврат 0 если программа закончилась успешно
*/
int main() {
	printf("Введите количество членов последовательности ");
	const int n = getInt();
	checkPositive(n)
	printf("Введите точность с котой будет рассчитана сумма членов последовательности ");
	const double e = getDouble();
	checkPositive(n)
	printf("%f\n%f", getSumN(n),getSumE(e,n));
	return 0;
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
double getSumN(const int n) {
	double current = 1;
	double n_current = 1;
	for (int k = 0; k < n; k++) {
		n_current *= -1.0 / ((2 * k + 1) * (2 * k + 2));
		current += n_current;
	}
	return current;
}

double getSumE(const double e,const int n) {
	double current = 1;
	double n_current = 1;
	for (int k = 0; k < n; k++) {
		n_current*= -1.0 / ((2 * k + 1) * (2 * k + 2));
		if (fabs(n_current) > e)current += n_current;
	}
	return current;
}

int getInt() {
	int value = 0;
	if (!scanf_s("%ld", &value)) {
		printf("Error");
		exit(1);
	}
	return value;
}
