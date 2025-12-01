#include <stdio.h>
#include <locale.h>
/**
* @param WEEK выбор дня недели
* @param MONTH выбор месяца
*/
enum { WEEK = 1, MONTH = 2 };
/**
* @param MON понедельник
* @param TUE вторник
* @param WEN среда
* @param THU четверг
* @param FRI пятница
* @param SAT суббота
* @param SUN воскресенье
*/
enum { MON = 1, TUE = 2, WEN, THU, FRI, SAT, SUN };
/**
* @param JAN январь
* @param FEB февраль
* @param MAR март
* @param APR апрель
* @param MAY май
* @param JUN июнь
* @param JUL июль
* @param AUG август
* @param SEP сентябрь
* @param OCT октябрь
* @param NOV ноябрь
* @param DEC декабрь
*/
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
        case MON:
            printf("Понедельник");
            break;
        case TUE:
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
        case JAN:
            printf("Январь");
            break;
        case FEB:
            printf("Февраль");
            break;
        case MAR:
            printf("Март");
            break;
        case APR:
            printf("Апрель");
            break;
        case MAY:
            printf("Май");
            break;
        case JUN:
            printf("Июнь");
            break;
        case JUL:
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
