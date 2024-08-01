#include "Stack.h"
#include <cstdlib>

// Constructors
Stack::Stack(int size) {
    elements.reserve(size);
    for (int i = 0; i < size; ++i) {
        elements.push_back(rand() % 100); // Fill stack with random numbers
    }
}

Stack::Stack(const Stack& other) : elements(other.elements) {}

// Destructor
Stack::~Stack() {}

// Assignment operator
Stack& Stack::operator=(const Stack& other) {
    if (this != &other) {
        elements = other.elements;
    }
    return *this;
}

// Comparison operators
bool Stack::operator!=(const Stack& other) const {
    return elements != other.elements;
}

bool Stack::operator<(const Stack& other) const {
    return elements < other.elements;
}

bool Stack::operator>(const Stack& other) const {
    return elements > other.elements;
}

bool Stack::operator<=(const Stack& other) const {
    return elements <= other.elements;
}

bool Stack::operator>=(const Stack& other) const {
    return elements >= other.elements;
}

bool Stack::operator==(const Stack& other) const {
    return elements == other.elements;
}

// Sub-stack operator
Stack Stack::operator()(int start, int end) const {
    Stack subStack;
    for (int i = start; i <= end; ++i) {
        subStack.elements.push_back(elements[i]);
    }
    return subStack;
}

// Method to access elements by index
int Stack::getElementAt(int index) const {
    return elements[index];
}

int Stack::size() const {
    return elements.size();
}
