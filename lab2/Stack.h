#ifndef STACK_H
#define STACK_H

#include <vector>

class Stack {
private:
    std::vector<int> elements;
public:
    // Constructors
    explicit Stack(int size = 10);
    Stack(const Stack& other);

    // Destructor
    ~Stack();

    // Assignment operator
    Stack& operator=(const Stack& other);

    // Comparison operators
    bool operator!=(const Stack& other) const;
    bool operator<(const Stack& other) const;
    bool operator>(const Stack& other) const;
    bool operator<=(const Stack& other) const;
    bool operator>=(const Stack& other) const;
    bool operator==(const Stack& other) const;

    // Sub-stack operator
    Stack operator()(int start, int end) const;

    // Method to access elements by index
    int getElementAt(int index) const;
    int size() const; // Method to get the size of the stack
};

#endif //STACK_H
