#include <stdio.h>

enum { WEEK = 1, MONTH = 2 };

/**
 * @brief считывает значение,
 * введенное с клавиатуры с проверкой ввода
 * @return считанное значение
 */
int getValue();


/**
 * @brief проверяет,что переменная является одним из вариантов
 * @param value значение проверяемой переменной
 */
void checkValue(const double value);

/**
 * @brief проверяет,что переменная является днем недели
 * @param value значение проверяемой переменной
 */
void checkValueW(const double value);
/**
 * @brief проверяет,что переменная является номеров месяца
 * @param value значение проверяемой переменной
 */
void checkValueM(const double value);
/**
* @brief точка входа вв  программу
* @return 
*/
int main() 
{
    printf("Выберите:\n %d - день недели\n %d - месяц\n", WEEK, MONTH);
    const int chs = getValue();
    checkValue(chs);
    switch (chs) 
    {
    case WEEK:
        printf("введите день недели:");
        const int day = getValue();
        checkValueW(day);
        switch (day)
        {
        case 1:
            printf("Понедельник");
            break;
        case 2:
            printf("Вторник");
            break;
        case 3:
            printf("Среда");
            break;
        case 4:
            printf("Четверг");
            break;
        case 5:
            printf("Пятница");
            break;
        case 6:
            printf("Суббота");
            break;
        case 7:
            printf("Воскресенье");
            break;
        }
        break;
    case MONTH:
        printf("введите номер месяца:");
        const int mth = getValue();
        checkValueM(mth);
        switch (mth)
        {
        case(1):
            printf("Январь");
            break;
        case(2):
            printf("Февраль");
            break;
        case(3):
            printf("Март");
            break;
        case(4):
            printf("Апрель");
            break;
        case(5):
            printf("Май");
            break;
        case(6):
            printf("Июнь");
            break;
        case(7):
            printf("Июль");
            break;
        case(8):
            printf("Август");
            break;
        case(9):
            printf("Сентябрь");
            break;
        case(10):
            printf("Октябрь");
            break;
        case(11):
            printf("Ноябрь");
            break;
        case(12):
            printf("Декабрь");
            break;
        }
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

void checkValue(const double value)
{
    if (value <= 0 || value > 2)
    {
        printf("Неправильный выбор\n");
        abort();
    }
}
void checkValueW(const double value)
{
    if (value <= 0 || value > 7)
    {
        printf("Значение должно быть номером дня недели\n");
        abort();
    }
}
void checkValueM(const double value)
{
    if (value <= 0 || value > 12)
    {
        printf("Значение должно быть номером месяца\n");
        abort();
    }
}
