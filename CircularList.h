#pragma once

#include <cstddef>
#include <initializer_list>
#include <string>
#include "Node.h"

/**
 * @brief Класс CircularList - циклический односвязный список целых чисел
 */
class CircularList {
private:
    Node* firstNode;
    size_t elementsCount;

    /**
     * @brief Выбрасывает исключение с заданным текстом
     * @param msg - текст ошибки
     */
    void throwError(const std::string& msg) const;

    /**
     * @brief Возвращает узел по индексу
     * @param index - индекс элемента
     * @return Указатель на узел
     */
    Node* fetchNode(const size_t index) const;

    /**
     * @brief Возвращает последний узел списка
     * @return Указатель на последний узел
     */
    Node* fetchTail() const;

    /**
     * @brief Копирует элементы из другого списка
     * @param source - список-источник для копирования
     */
    void cloneFrom(const CircularList& source);

public:
    /**
     * @brief Конструктор, создающий пустой список
     */
    CircularList();

    /**
     * @brief Конструктор, создающий список из набора значений
     * @param items - набор значений для инициализации
     */
    CircularList(const std::initializer_list<int> items);

    /**
     * @brief Конструктор копирования
     * @param source - список, из которого копируются элементы
     */
    CircularList(const CircularList& source);

    /**
     * @brief Конструктор перемещения
     * @param source - список, из которого перемещаются элементы
     */
    CircularList(CircularList&& source) noexcept;

    /**
     * @brief Деструктор списка
     */
    ~CircularList();

    /**
     * @brief Оператор присваивания
     * @param source - список для копирования
     * @return Ссылка на текущий список
     */
    CircularList& operator=(const CircularList& source);

    /**
     * @brief Оператор перемещающего присваивания
     * @param source - список для перемещения
     * @return Ссылка на текущий список
     */
    CircularList& operator=(CircularList&& source) noexcept;

    /**
     * @brief Выполняет циклический сдвиг влево
     * @param shifts - количество сдвигов
     * @return Ссылка на текущий список
     */
    CircularList& operator<<=(const size_t shifts);

    /**
     * @brief Выполняет циклический сдвиг вправо
     * @param shifts - количество сдвигов
     * @return Ссылка на текущий список
     */
    CircularList& operator>>=(const size_t shifts);

    /**
     * @brief Возвращает список со сдвигом влево
     * @param shifts - количество сдвигов
     * @return Новый список
     */
    CircularList operator<<(const size_t shifts) const;

    /**
     * @brief Возвращает список со сдвигом вправо
     * @param shifts - количество сдвигов
     * @return Новый список
     */
    CircularList operator>>(const size_t shifts) const;

    /**
     * @brief Добавляет элемент в начало списка
     * @param val - значение элемента
     */
    void prepend(const int val);

    /**
     * @brief Добавляет элемент в конец списка
     * @param val - значение элемента
     */
    void append(const int val);

    /**
     * @brief Вставляет элемент по индексу
     * @param pos - индекс вставки
     * @param val - значение элемента
     */
    void insert(const size_t pos, const int val);

    /**
     * @brief Удаляет элемент по индексу
     * @param pos - индекс удаляемого элемента
     */
    void eraseAt(const size_t pos);

    /**
     * @brief Удаляет первый элемент с заданным значением
     * @param val - значение для удаления
     * @return true если элемент удален, иначе false
     */
    bool eraseValue(const int val);

    /**
     * @brief Ищет элемент по значению
     * @param val - значение для поиска
     * @return Индекс элемента или -1, если не найден
     */
    int indexOf(const int val) const;

    /**
     * @brief Изменяет первый элемент с заданным значением
     * @param oldVal - старое значение
     * @param newVal - новое значение
     * @return true если элемент изменен, иначе false
     */
    bool replace(const int oldVal, const int newVal);

    /**
     * @brief Возвращает значение элемента по индексу
     * @param pos - индекс элемента
     * @return Значение элемента
     */
    int get(const size_t pos) const;

    /**
     * @brief Устанавливает значение элемента по индексу
     * @param pos - индекс элемента
     * @param val - новое значение элемента
     */
    void set(const size_t pos, const int val);

    /**
     * @brief Возвращает количество элементов в списке
     * @return Количество элементов
     */
    size_t length() const;

    /**
     * @brief Проверяет список на пустоту
     * @return true если список пуст, иначе false
     */
    bool empty() const;

    /**
     * @brief Очищает список от всех элементов
     */
    void clearAll();

    /**
     * @brief Возвращает список в виде строкового представления
     * @return Строка со значениями списка
     */
    std::string asString() const;
};