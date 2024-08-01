#include <iostream>
#include <cstdlib>
#include "Coordinate.h"
#include "Stack.h"



void stackOperations() {
    int size;
    std::cin >> size;
    Stack stack1(size);
    Stack stack2(size);

    std::cout << "\nStack 1 elements:\n";
    for (int i = 0; i < stack1.size(); ++i) {
        std::cout << stack1.getElementAt(i) << " ";
    }
    std::cout << "\nStack 2 elements:\n";
    for (int i = 0; i < stack2.size(); ++i) {
        std::cout << stack2.getElementAt(i) << " ";
    }
    std::cout << std::endl;

    if (stack1 == stack2) {
        std::cout << "Stack 1 is equal to Stack 2\n";
    } else {
        std::cout << "Stack 1 is not equal to Stack 2\n";
    }

    int start, end;
    std::cout << "Enter start and end index for sub-stack: ";
    std::cin >> start >> end;

    if (start >= 0 && end < stack1.size() && start <= end) {
        std::cout << "Sub-stack elements of Stack 1 (index " << start << " to " << end << "):\n";
        for (int i = start; i <= end; ++i) {
            std::cout << stack1.getElementAt(i) << " ";
        }
        std::cout << std::endl;
    } else {
        std::cout << "Invalid index range\n";
    }
}

int main() {
    char choice;
    do {
        std::cout << "Choose a task:\n";
        std::cout << "1. Coordinate operations\n";
        std::cout << "2. Stack operations\n";
        std::cout << "3. Exit\n";
        std::cin >> choice;

        switch(choice) {
            case '1': {
                Coordinates coord(1, 2, 3);

                std::cout << "Initial coordinates: ";
                coord.display();

                char op;
                do {
                    std::cout << "Choose an operation:\n";
                    std::cout << "1. Postfix ++\n";
                    std::cout << "2. Postfix --\n";
                    std::cout << "3. Prefix ++\n";
                    std::cout << "4. Prefix --\n";
                    std::cout << "5. Exit \n";
                    std::cin >> op;

                    switch (op) {
                        case '1':
                            coord++;
                            std::cout << "After postfix ++: ";
                            coord.display();
                            break;
                        case '2':
                            coord--;
                            std::cout << "After postfix --: ";
                            coord.display();
                            break;
                        case '3':
                            ++coord;
                            std::cout << "After prefix ++: ";
                            coord.display();
                            break;
                        case '4':
                            --coord;
                            std::cout << "After prefix --: ";
                            coord.display();
                            break;
                        case '5':
                            std::cout << "Exiting...\n";
                            break;
                        default:
                            std::cout << "Invalid choice\n";
                            break;
                    }
                } while (op != '5');

                break;
            }

            case '2':
                stackOperations();
                break;
            case '3':
                std::cout << "Exiting program\n";
                break;
            default:
                std::cout << "Invalid choice\n";
                break;
        }
    } while(choice != '3');

    return 0;
}
