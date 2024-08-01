#include "Textbook.h"
#include <iostream>

using namespace std;

Textbook::Textbook(const string& name,
                   int year,
                   const string& publisher,
                   int numPages,
                   const string& annotation,
                   const string& subject,
                   int grade)
        : PrintedEdition(name, year, publisher, numPages, annotation), m_subject(subject), m_grade(grade) {}

Textbook::Textbook(const Textbook& other)
        : PrintedEdition(other), m_subject(other.m_subject), m_grade(other.m_grade) {}

Textbook::~Textbook() {}

void Textbook::print() const {
    cout << "Name: " << m_name << endl;
    cout << "Year: " << m_year << endl;
    cout << "Publisher: " << m_publisher << endl;
    cout << "Number of pages: " << m_numPages << endl;
    cout << "Annotation: " << m_annotation << endl;
    cout << "Subject: " << m_subject << endl;
    cout << "Grade: " << m_grade << endl;
}

void Textbook::printToFile(ofstream& file) const {
    file << "Name: " << m_name << endl;
    file << "Year: " << m_year << endl;
    file << "Publisher: " << m_publisher << endl;
    file << "Number of pages: " << m_numPages << endl;
    file << "Annotation: " << m_annotation << endl;
    file << "Subject: " << m_subject << endl;
    file << "Grade: " << m_grade << endl;
}
