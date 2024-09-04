#ifndef LAB5_BASECLASS_H
#define LAB5_BASECLASS_H

#include <iostream>
#include <fstream>
#include <string>

class BaseClass {
    virtual void printInfo() const = 0;
    virtual void saveToFile(std::ofstream& file) const = 0;
    virtual void loadFromFile(std::ifstream& file) = 0;
    virtual ~BaseClass() = default;
};


#endif //LAB5_BASECLASS_H
