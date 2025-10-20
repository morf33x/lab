#include <stdio.h>
#include <locale.h>

enum { WEEK = 1, MONTH = 2,WEN,THU,FRI, SAT, SUN,AUG,SEP,OCT,NOV,DEC };

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
    setlocale(LC_ALL, "rus");
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
        }
        break;
    case MONTH:
        printf("введите номер месяца:");
        const int mth = getValue();
        checkValueM(mth);
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
