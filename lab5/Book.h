#ifndef BOOK_H
#define BOOK_H

#include "BaseClass.h"
#include <string>

class book : public BaseClass {
private:
    std::string title;
    std::string author;
    int year;
    std::string annotation;
    std::string genre;
    int pages;
    double price;

public:
    book(const std::string& title = "", const std::string& author = "", int year = 0,
         const std::string& annotation = "", const std::string& genre = "",
         int pages = 0, double price = 0.0);

    void printInfo() const override;
    void saveToFile(std::ofstream& file) const override;
    void loadFromFile(std::ifstream& file) override;
};

#endif // BOOK_H