#pragma once
#include <iostream>
#include <string>

/**
 * @brief Класс Издательство
 */
class Publisher
{
private:
    /** @brief Название издательства */
    std::string name;
    /** @brief Город расположения */
    std::string city;

public:
    /**
     * @brief Конструктор по умолчанию
     */
    Publisher();

    /**
     * @brief Конструктор с параметрами
     * @param name - Название издательства
     * @param city - Город издания
     */
    Publisher(const std::string& name, const std::string& city);

    /**
     * @brief Оператор вывода издательства в поток
     * @param os - Поток вывода
     * @param pub - Объект издательства
     * @return Ссылка на поток вывода
     */
    friend std::ostream& operator<<(std::ostream& os, const Publisher& pub);

    /**
     * @brief Оператор ввода издательства из потока
     * @param is - Поток ввода
     * @param pub - Объект издательства для заполнения
     * @return Ссылка на поток ввода
     */
    friend std::istream& operator>>(std::istream& is, Publisher& pub);
};