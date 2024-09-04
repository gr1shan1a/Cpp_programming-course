#include "Book.h"

Book::Book(const std::string &title, const std::string &author, int year, const std::string &annotation,
           const std::string &genre, int pages, double price) :
           title(title), author(author),
           year(year), annotation(annotation),
           genre(genre), pages(pages),
           price(price) {}

void Book::printInfo() const {
    std::cout << "Book: " << title << ", Author: " << author << ", Year: " << year
              << ", Genre: " << genre << ", Pages: " << pages << ", Price: $" << price
              << "\nAnnotation: " << annotation << std::endl;
}

void Book::saveToFile(std::ofstream& file) const {
    file << "Book\n" << title << "\n" << author << "\n" << year << "\n" << annotation << "\n"
         << genre << "\n" << pages << "\n" << price << "\n";
}

void Book::loadFromFile(std::ifstream& file) {
    std::getline(file, title);
    std::getline(file, author);
    file >> year;
    file.ignore();
    std::getline(file, annotation);
    std::getline(file, genre);
    file >> pages >> price;
    file.ignore();
}