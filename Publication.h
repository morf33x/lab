#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Person.h"

/**
 * @brief Абстрактный базовый класс Публикация
 */
class Publication
{
protected:
    /** @brief Список авторов */
    std::vector<Person> authors;
    /** @brief Заголовок */
    std::string title;
    /** @brief Год издания */
    int year;

public:
    /**
     * @brief Конструктор по умолчанию
     */
    Publication();

    /**
     * @brief Конструктор с параметрами
     * @param authors - Вектор объектов Person (авторы)
     * @param title - Название публикации
     * @param year - Год выпуска
     */
    Publication(const std::vector<Person>& authors, const std::string& title, const int year);

    /**
     * @brief Виртуальный деструктор
     */
    virtual ~Publication() = default;

    /**
     * @brief Сериализация объекта в строку
     * @return Строковое библиографическое представление
     */
    virtual std::string ToString() const = 0;
};
