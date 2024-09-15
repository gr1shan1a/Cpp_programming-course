#include "book.h"
#include <iostream>

book::book(const std::string& title, const std::string& author, int year, const std::string& annotation,
           const std::string& genre, int pages, double price)
        : title(title), author(author), year(year), annotation(annotation), genre(genre), pages(pages), price(price) {}

void book::printInfo() const {
    std::cout << "Book: " << title << ", Author: " << author << ", Year: " << year
              << ", Genre: " << genre << ", Pages: " << pages << ", Price: $" << price
              << "\nAnnotation: " << annotation << std::endl;
}

void book::saveToFile(std::ofstream& file) const {
    file << "book\n" << title << "\n" << author << "\n" << year << "\n" << annotation << "\n"
         << genre << "\n" << pages << "\n" << price << "\n";
}

void book::loadFromFile(std::ifstream& file) {
    std::getline(file, title);
    std::getline(file, author);
    file >> year;
    file.ignore();
    std::getline(file, annotation);
    std::getline(file, genre);
    file >> pages >> price;
    file.ignore();
}