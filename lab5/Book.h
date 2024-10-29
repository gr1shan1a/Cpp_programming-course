#ifndef BOOK_H
#define BOOK_H

#include "BaseClass.h"
#include <string>

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
    Book() = default;
    Book(const std::string& title, const std::string& author, int year, const std::string& annotation,
         const std::string& genre, int pages, double price);

    void printInfo() const override;
    void saveToFile(std::ofstream& file) const override;
    void loadFromFile(std::ifstream& file) override;
    void addElement() override;
    void deleteElement() override;
    void edit() override;
};

#endif // BOOK_H
