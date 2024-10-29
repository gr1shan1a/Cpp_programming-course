#ifndef STUDENTSBOOK_H
#define STUDENTSBOOK_H

#include "BaseClass.h"
#include <string>

class StudentsBook : public BaseClass {
private:
    std::string title;
    std::string author;
    int year;
    std::string institution;
    int studyYear;
    int pages;
    double price;

public:
    StudentsBook() = default;
    StudentsBook(const std::string& title, const std::string& author, int year, const std::string& institution,
                 int studyYear, int pages, double price);

    void printInfo() const override;
    void saveToFile(std::ofstream& file) const override;
    void loadFromFile(std::ifstream& file) override;
    void addElement() override;
    void deleteElement() override;
    void edit() override;
};

#endif // STUDENTSBOOK_H
