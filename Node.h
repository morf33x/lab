#pragma once

/**
 * @brief  ласс Node - узел циклического односв€зного списка
 */
class Node {
private:
    int value;
    Node* nextNode;

public:
    /**
     * @brief  онструктор, создающий узел списка
     * @param val - значение узла
     * @param next - указатель на следующий узел
     */
    explicit Node(const int val = 0, Node* const next = nullptr);

    /**
     * @brief ¬озвращает значение узла
     * @return «начение узла
     */
    int getValue() const;

    /**
     * @brief ”станавливает значение узла
     * @param val - новое значение узла
     */
    void setValue(const int val);

    /**
     * @brief ¬озвращает указатель на следующий узел
     * @return ”казатель на следующий узел
     */
    Node* getNext() const;

    /**
     * @brief ”станавливает указатель на следующий узел
     * @param next - указатель на следующий узел
     */
    void setNext(Node* const next);
};