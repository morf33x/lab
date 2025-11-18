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
* @brief считает факториал
* @return число от которого нужно найти факториал
*/
int fact(const int k);
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
	const int n = getInt();
	const double e = getDouble();
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

double getSumN(const int n) {
	double current = 0;
	for (int k = 0; k < n; k++) {
		current += pow(-1, k) / fact(2 * k);
	}
	return current;
}

double getSumE(const double e,const int n) {
	double current = 0;
	double n_current = 0;
	for (int k = 0; k < n; k++) {
		n_current= pow(-1, k) / fact(2 * k);
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

int fact(const int k) {
	if (k > 1)return k * fact(k - 1);
	else return 1;
}
