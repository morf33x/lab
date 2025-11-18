#include <stdio.h>
#include <locale.h>

enum { WEEK = 1, MONTH = 2 };
enum { MON = 1, TUE = 2, WEN, THU, FRI, SAT, SUN };
enum { JAN = 1, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC };

/**
 * @brief считывает значение,
 * введенное с клавиатуры с проверкой ввода
 * @return считанное значение
 */
int getValue();

/**
* @brief точка входа вв  программу
* @return 
*/
int main() 
{
    setlocale(LC_ALL, "rus");
    printf("Выберите:\n %d - день недели\n %d - месяц\n", WEEK, MONTH);
    const int chs = getValue();
    switch (chs) 
    {
    case WEEK:
        printf("введите день недели:");
        const int day = getValue();
        switch (day)
        {
        case WEEK:
            printf("Понедельник");
            break;
        case MONTH:
            printf("Вторник");
            break;
        case WEN:
            printf("Среда");
            break;
        case THU:
            printf("Четверг");
            break;
        case FRI:
            printf("Пятница");
            break;
        case SAT:
            printf("Суббота");
            break;
        case SUN:
            printf("Воскресенье");
            break;
        default:
            printf("Значение должно быть номером дня недели\n");
            abort();
        }
        break;
    case MONTH:
        printf("введите номер месяца:");
        const int mth = getValue();
        switch (mth)
        {
        case WEEK:
            printf("Январь");
            break;
        case MONTH:
            printf("Февраль");
            break;
        case WEN:
            printf("Март");
            break;
        case THU:
            printf("Апрель");
            break;
        case FRI:
            printf("Май");
            break;
        case SAT:
            printf("Июнь");
            break;
        case SUN:
            printf("Июль");
            break;
        case AUG:
            printf("Август");
            break;
        case SEP:
            printf("Сентябрь");
            break;
        case OCT:
            printf("Октябрь");
            break;
        case NOV:
            printf("Ноябрь");
            break;
        case DEC:
            printf("Декабрь");
            break;
        default:
            printf("Значение должно быть номером месяца\n");
            abort();
            break;
        }
    default:
        printf("Неправильный выбор\n");
        abort();
    }
}

int getValue()
{
    int value = 0;
    if (!scanf_s("%ld", &value))
    {
        printf("Error\n");
        abort();
    }
    return value;
}
