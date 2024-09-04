#ifndef LAB5_BOOK_H
#define LAB5_BOOK_H

#include "BaseClass.h"
#include <iostream>

class Book : public BaseClass {
private:
    std::string title;
    std::string author;
    int year;
    std::string annotation;
    std::string genre;
    int pages;
    double price;

public:
    Book(const std::string& title = "",
         const std::string& author = "",
         int year = 0,
         const std::string& annotation = "",
         const std::string& genre = "",
         int pages = 0,
         double price = 0.0);

    void printInfo() const;

    void saveToFile(std::ofstream &file) const;

    void loadFromFile(std::ifstream &file);
};


#endif //LAB5_BOOK_H
