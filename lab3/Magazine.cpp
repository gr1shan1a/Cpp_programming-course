#include "Magazine.h"
#include <iostream>

using namespace std;

Magazine::Magazine(const string& name,
                   int year,
                   const string& publisher,
                   int numPages,
                   const string& annotation,
                   int issueNumber)
        : PrintedEdition(name, year, publisher, numPages, annotation), m_Nomer_pechati(issueNumber) {}

Magazine::Magazine(const Magazine& other)
        : PrintedEdition(other), m_Nomer_pechati(other.m_Nomer_pechati) {}

void Magazine::print() const {
    cout << "Name: " << m_name << endl;
    cout << "Year: " << m_year << endl;
    cout << "Publisher: " << m_publisher << endl;
    cout << "Number of pages: " << m_numPages << endl;
    cout << "Annotation: " << m_annotation << endl;
    cout << "Nomer pechati: " << m_Nomer_pechati << endl;
}

void Magazine::printToFile(ofstream& file) const {
    file << "Name: " << m_name << endl;
    file << "Year: " << m_year << endl;
    file << "Publisher: " << m_publisher << endl;
    file << "Number of pages: " << m_numPages << endl;
    file << "Annotation: " << m_annotation << endl;
    file << "Nomer pechati: " << m_Nomer_pechati << endl;
}
