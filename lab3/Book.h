#ifndef TP_3_BOOK_H
#define TP_3_BOOK_H

#include "PrintedEdition.h"

using namespace std;

class Book : public PrintedEdition {
public:
    Book() : PrintedEdition(), m_author() {}

    Book(const string& name,
         int year,
         const string& publisher,
         int numPages,
         const string& annotation,
         const string& author);

    Book(const Book& other);
    void print() const override;
    void printToFile(ofstream& file) const override;
private:
    std::string m_author;
};

#endif // TP_3_BOOK_H
