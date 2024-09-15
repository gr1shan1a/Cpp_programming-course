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
    StudentsBook(const std::string& title = "", const std::string& author = "", int year = 0,
                 const std::string& institution = "", int studyYear = 0, int pages = 0, double price = 0.0);

    void printInfo() const override;
    void saveToFile(std::ofstream& file) const override;
    void loadFromFile(std::ifstream& file) override;
};

#endif // STUDENTSBOOK_H