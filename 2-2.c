#include <stdio.h>
#include <math.h>

/**
* @brief проверяет является ли ввод числом
* @return ввеленное с клавиатуры зачение
*/
double getValue();
/**
* @brief находит y
* @param x введенная переменная
*/
double getY(const double x);
int main() {
	printf("Введите x:\n");
	const double x = getValue();
    printf("y=%.6f", getY(x));
}
getY(const double x) {
    const double a = 20.3;
    if (x > 1)
    {
        return log10(x);
    }
    else
    {
        return sin(2) * sqrt(abs(a * x));
    }
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
