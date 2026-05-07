#pragma once
#include <iostream>
#include <string>

/**
 * @brief Класс Персона - автор или редактор
 */
class Person
{
private:
    /** @brief Имя */
    std::string firstName;
    /** @brief Фамилия */
    std::string lastName;
    /** @brief Отчество */
    std::string patronymic;
    /** @brief Префикс (например, "д-р") */
    std::string prefix;
    /** @brief Постфикс (например, "Ph.D.") */
    std::string postfix;

public:
    /**
     * @brief Конструктор по умолчанию
     */
    Person();

    /**
     * @brief Конструктор с параметрами
     * @param firstName - Имя
     * @param lastName - Фамилия
     * @param patronymic - Отчество (необязательно)
     * @param prefix - Префикс перед именем (необязательно)
     * @param postfix - Регалии после имени (необязательно)
     */
    Person(const std::string& firstName, const std::string& lastName,
        const std::string& patronymic = "", const std::string& prefix = "", const std::string& postfix = "");

    /**
     * @brief Оператор вывода данных персоны в поток
     * @param os - Поток вывода
     * @param person - Объект персоны для вывода
     * @return Ссылка на поток вывода
     */
    friend std::ostream& operator<<(std::ostream& os, const Person& person);

    /**
     * @brief Оператор ввода данных персоны из потока
     * @param is - Поток ввода
     * @param person - Объект персоны для заполнения
     * @return Ссылка на поток ввода
     */
    friend std::istream& operator>>(std::istream& is, Person& person);
};