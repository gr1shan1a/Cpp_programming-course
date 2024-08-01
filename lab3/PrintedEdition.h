#ifndef TP_3_PRINTEDEDITION_H
#define TP_3_PRINTEDEDITION_H

#include <string>
#include <fstream>

using namespace std;

class PrintedEdition {
public:
    PrintedEdition() : m_name(), m_year(0), m_publisher(), m_numPages(0), m_annotation() {}
    PrintedEdition(const string& name,
                   int year,
                   const string& publisher,
                   int numPages,
                   const string& annotation);

    PrintedEdition(const PrintedEdition& other);
    virtual ~PrintedEdition();
    virtual void print() const = 0;
    virtual void printToFile(std::ofstream& file) const = 0;

protected:
    string m_name;
    int m_year;
    string m_publisher;
    int m_numPages;
    string m_annotation;
};

#endif // TP_3_PRINTEDEDITION_H
