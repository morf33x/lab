#include <stdio.h>
#include <locale.h>

/**
@brief TRIANGLE - треугольник
@brief SQUARE - квадрат
@brief RHOMBUS - ромб
@brief RECT - прямоугольник
*/
enum { TRIANGLE = 1, SQUARE, RHOMBUS, RECT };

/**
 * @brief считывает значение, введенное с клавиатуры с проверкой ввода
 */
int getInt();

/**
 * @brief Точка входа в программу
 * @return возвращает 0, если программма выполнена корректно
 */
int main(void) {
    setlocale(LC_ALL, "Rus");
    printf("Выберите номер фигуры:\n%d-треугольник\n%d-квадрат\n%d-ромб\n%d-прямоугольник\n", TRIANGLE, SQUARE, RHOMBUS, RECT);
    int choice = getInt();
    switch (choice)
    {
    case SQUARE:
        printf("a^2, a - сторона квадрата ");
        break;
    case RECT:
        printf("a*b, a и b - стороны прямоугольника");
        break;
    case RHOMBUS:
        printf("(d1 * d2) / 2, d1 и d2 - диагонали ромба");
        break;
    case TRIANGLE:
        printf("a*h/2,a - сторона треугольника h - высота треугольника, опущенная на эту сторону");
        break;
    default:
        printf("Неправильный выбор");
        exit(1);
    }

    return 0;
}


int getInt()
{
    int value = 0;
    if (!scanf_s("%ld", &value))
    {
        printf("Error\n");
        abort();
    }
    return value;
}
