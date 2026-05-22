#include "Node.h"

Node::Node(const int val, Node* const next) : value(val), nextNode(next) {
}

int Node::getValue() const {
    return value;
}

void Node::setValue(const int val) {
    value = val;
}

Node* Node::getNext() const {
    return nextNode;
}

void Node::setNext(Node* const next) {
    nextNode = next;
}