#pragma once
#include "Publication.h"
#include "Publisher.h"

/**
 * @brief Класс Книга - конкретная реализация публикации
 */
class Book : public Publication
{
private:
    /** @brief Издательство */
    Publisher publisher;
    /** @brief Ответственный редактор */
    Person editor;

public:
    /**
     * @brief Конструктор по умолчанию
     */
    Book() = default;

    /**
     * @brief Конструктор с параметрами
     * @param authors - Список авторов
     * @param title - Заголовок книги
     * @param year - Год издания
     * @param publisher - Объект издательства
     * @param editor - Объект персоны (редактор)
     */
    Book(const std::vector& authors, const std::string& title, const int year,
    const Publisher& publisher, const Person& editor);

    /**
     * @brief Формирует строку по ГОСТу
     * @return Полная библиографическая запись
     */
    std::string ToString() const override;

    /**
     * @brief Статический метод для создания объекта через поток
     * @param is - Поток ввода
     * @return Сформированный объект Book
     */
    static Book read(std::istream& is);

    /**
     * @brief Оператор вывода книги
     * @param os - Поток вывода
     * @param book - Объект книги
     * @return Ссылка на поток
     */
    friend std::ostream& operator<<(std::ostream& os, const Book& book);

    /**
     * @brief Оператор ввода книги
     * @param is - Поток ввода
     * @param book - Объект книги для заполнения
     * @return Ссылка на поток
     */
    friend std::istream& operator>>(std::istream& is, Book& book);
};
