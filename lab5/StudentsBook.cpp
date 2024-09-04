#include "StudentsBook.h"
StudentsBook::StudentsBook(const std::string& title, const std::string& author, int year, const std::string& institution,
                   int studyYear, int pages, double price)
        : title(title), author(author), year(year), institution(institution), studyYear(studyYear), pages(pages), price(price) {}

void StudentsBook::printInfo() const {
    std::cout << "Textbook: " << title << ", Author: " << author << ", Year: " << year
              << ", Institution: " << institution << ", Study Year: " << studyYear
              << ", Pages: " << pages << ", Price: $" << price << std::endl;
}

void StudentsBook::saveToFile(std::ofstream& file) const {
    file << "Textbook\n" << title << "\n" << author << "\n" << year << "\n" << institution << "\n"
         << studyYear << "\n" << pages << "\n" << price << "\n";
}

void StudentsBook::loadFromFile(std::ifstream& file) {
    std::getline(file, title);
    std::getline(file, author);
    file >> year;
    file.ignore();
    std::getline(file, institution);
    file >> studyYear >> pages >> price;
    file.ignore();
}