#include "CircularList.h"
#include <stdexcept>

void CircularList::throwError(const std::string& msg) const {
    throw std::out_of_range(msg);
}

Node* CircularList::fetchNode(const size_t index) const {
    if (index >= elementsCount) {
        throwError("Index is out of bounds!");
    }
    Node* iter = firstNode;
    for (size_t i = 0; i < index; ++i) {
        iter = iter->getNext();
    }
    return iter;
}

Node* CircularList::fetchTail() const {
    if (empty()) return nullptr;

    Node* iter = firstNode;
    while (iter->getNext() != firstNode) {
        iter = iter->getNext();
    }
    return iter;
}

void CircularList::cloneFrom(const CircularList& source) {
    if (source.empty()) return;

    Node* iter = source.firstNode;
    for (size_t i = 0; i < source.elementsCount; ++i) {
        append(iter->getValue());
        iter = iter->getNext();
    }
}

CircularList::CircularList() : firstNode(nullptr), elementsCount(0) {}

CircularList::CircularList(const std::initializer_list<int> items) : CircularList() {
    for (const int item : items) {
        append(item);
    }
}

CircularList::CircularList(const CircularList& source) : CircularList() {
    cloneFrom(source);
}

CircularList::CircularList(CircularList&& source) noexcept
    : firstNode(source.firstNode), elementsCount(source.elementsCount) {
    source.firstNode = nullptr;
    source.elementsCount = 0;
}

CircularList::~CircularList() {
    clearAll();
}

CircularList& CircularList::operator=(const CircularList& source) {
    if (this != &source) {
        clearAll();
        cloneFrom(source);
    }
    return *this;
}

CircularList& CircularList::operator=(CircularList&& source) noexcept {
    if (this != &source) {
        clearAll();
        firstNode = source.firstNode;
        elementsCount = source.elementsCount;
        source.firstNode = nullptr;
        source.elementsCount = 0;
    }
    return *this;
}

CircularList& CircularList::operator<<=(const size_t shifts) {
    if (elementsCount > 1) {
        const size_t actualShifts = shifts % elementsCount;
        for (size_t i = 0; i < actualShifts; ++i) {
            firstNode = firstNode->getNext();
        }
    }
    return *this;
}

CircularList& CircularList::operator>>=(const size_t shifts) {
    if (elementsCount > 1) {
        const size_t actualShifts = shifts % elementsCount;
        *this <<= (elementsCount - actualShifts);
    }
    return *this;
}

CircularList CircularList::operator<<(const size_t shifts) const {
    CircularList res(*this);
    res <<= shifts;
    return res;
}

CircularList CircularList::operator>>(const size_t shifts) const {
    CircularList res(*this);
    res >>= shifts;
    return res;
}

void CircularList::prepend(const int val) {
    Node* newNode = new Node(val);
    if (empty()) {
        newNode->setNext(newNode);
        firstNode = newNode;
    }
    else {
        Node* tail = fetchTail();
        newNode->setNext(firstNode);
        tail->setNext(newNode);
        firstNode = newNode;
    }
    elementsCount++;
}

void CircularList::append(const int val) {
    Node* newNode = new Node(val);
    if (empty()) {
        newNode->setNext(newNode);
        firstNode = newNode;
    }
    else {
        Node* tail = fetchTail();
        newNode->setNext(firstNode);
        tail->setNext(newNode);
    }
    elementsCount++;
}

void CircularList::insert(const size_t pos, const int val) {
    if (pos > elementsCount) throwError("Invalid insertion index");
    if (pos == 0) return prepend(val);
    if (pos == elementsCount) return append(val);

    Node* prev = fetchNode(pos - 1);
    Node* newNode = new Node(val, prev->getNext());
    prev->setNext(newNode);
    elementsCount++;
}

void CircularList::eraseAt(const size_t pos) {
    if (pos >= elementsCount) throwError("Invalid remove index");

    if (elementsCount == 1) {
        delete firstNode;
        firstNode = nullptr;
        elementsCount = 0;
        return;
    }

    Node* toDelete = nullptr;
    if (pos == 0) {
        Node* tail = fetchTail();
        toDelete = firstNode;
        firstNode = firstNode->getNext();
        tail->setNext(firstNode);
    }
    else {
        Node* prev = fetchNode(pos - 1);
        toDelete = prev->getNext();
        prev->setNext(toDelete->getNext());
    }

    delete toDelete;
    elementsCount--;
}

bool CircularList::eraseValue(const int val) {
    const int idx = indexOf(val);
    if (idx == -1) return false;
    eraseAt(static_cast<size_t>(idx));
    return true;
}

int CircularList::indexOf(const int val) const {
    Node* iter = firstNode;
    for (size_t i = 0; i < elementsCount; ++i) {
        if (iter->getValue() == val) return static_cast<int>(i);
        iter = iter->getNext();
    }
    return -1;
}

bool CircularList::replace(const int oldVal, const int newVal) {
    const int idx = indexOf(oldVal);
    if (idx == -1) return false;
    set(static_cast<size_t>(idx), newVal);
    return true;
}

int CircularList::get(const size_t pos) const {
    return fetchNode(pos)->getValue();
}

void CircularList::set(const size_t pos, const int val) {
    fetchNode(pos)->setValue(val);
}

size_t CircularList::length() const {
    return elementsCount;
}

bool CircularList::empty() const {
    return elementsCount == 0;
}

void CircularList::clearAll() {
    if (empty()) return;

    Node* current = firstNode->getNext();
    while (current != firstNode) {
        Node* nextTemp = current->getNext();
        delete current;
        current = nextTemp;
    }
    delete firstNode;

    firstNode = nullptr;
    elementsCount = 0;
}

std::string CircularList::asString() const {
    if (empty()) return "[]";

    std::string res = "[";
    Node* iter = firstNode;
    for (size_t i = 0; i < elementsCount; ++i) {
        res += std::to_string(iter->getValue());
        if (i < elementsCount - 1) res += ", ";
        iter = iter->getNext();
    }
    res += "]";
    return res;
}