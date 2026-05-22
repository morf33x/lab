#include <iostream>
#include <stdexcept>
#include "CircularList.h"

/**
 * @brief Точка входа в демонстрационную программу
 * @return 0 при успешном выполнении, 1 при ошибке
 */
int main() {
    system("chcp 1251");

    try {
        std::cout << "--- Демонстрация работы циклического односвязного списка ---" << std::endl;


        CircularList list{ 1, 2, 3 };
        std::cout << "Исходный список: " << list.asString() << std::endl;

        list.append(4);
        std::cout << "После добавления 4 в конец: " << list.asString() << std::endl;

        list.insert(0, 99);
        std::cout << "После вставки 99 в начало: " << list.asString() << std::endl;

        list.eraseValue(2);
        std::cout << "После удаления элемента 2: " << list.asString() << std::endl;

        list.replace(3, 30);
        std::cout << "После замены 3 на 30: " << list.asString() << std::endl;

        list <<= 2;
        std::cout << "После циклического сдвига влево на 2: " << list.asString() << std::endl;

        list.clearAll();
        std::cout << "После полной очистки: " << list.asString() << std::endl;

    }
    catch (const std::exception& error) {
        std::cerr << "Произошла ошибка: " << error.what() << std::endl;
        return 1;
    }

    return 0;
}