#ifndef TP_3_TEXTBOOK_H
#define TP_3_TEXTBOOK_H

#include "PrintedEdition.h"

using namespace std;

class Textbook : public PrintedEdition {
public:
    Textbook() : PrintedEdition(), m_subject(), m_grade(0) {}
    Textbook(const string& name,
             int year,
             const string& publisher,
             int numPages,
             const string& annotation,
             const string& subject,
             int grade);

    Textbook(const Textbook& other);

    virtual ~Textbook();
    void print() const override;
    void printToFile(ofstream& file) const override;

private:
    string m_subject;
    int m_grade;
};

#endif // TEXTBOOK_H
