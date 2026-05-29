#pragma once

/**
 * @brief Класс Node - узел циклического односвязного списка
 */
class Node {
private:
    int value;
    Node* nextNode;

public:
    /**
     * @brief Конструктор, создающий узел списка
     * @param val - значение узла
     * @param next - указатель на следующий узел
     */
    explicit Node(const int val = 0, Node* const next = nullptr);

    /**
     * @brief Возвращает значение узла
     * @return Значение узла
     */
    int getValue() const;

    /**
     * @brief Устанавливает значение узла
     * @param val - новое значение узла
     */
    void setValue(const int val);

    /**
     * @brief Возвращает указатель на следующий узел
     * @return Указатель на следующий узел
     */
    Node* getNext() const;

    /**
     * @brief Устанавливает указатель на следующий узел
     * @param next - указатель на следующий узел
     */
    void setNext(Node* const next);
};
