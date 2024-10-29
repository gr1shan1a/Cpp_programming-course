#ifndef BASECLASS_H
#define BASECLASS_H

#include <iostream>
#include <fstream>

class BaseClass {
public:
    virtual void printInfo() const = 0;
    virtual void saveToFile(std::ofstream& file) const = 0;
    virtual void loadFromFile(std::ifstream& file) = 0;

    virtual void addElement() = 0;
    virtual void deleteElement() = 0;
    virtual void edit() = 0;

    virtual ~BaseClass() = default;
};

#endif // BASECLASS_H
