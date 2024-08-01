#include "Book.h"
#include <iostream>

using namespace std;

Book::Book(const string& name,
           int year,
           const string& publisher,
           int numPages,
           const string& annotation,
           const string& author)
        : PrintedEdition(name, year, publisher, numPages, annotation), m_author(author) {}

Book::Book(const Book& other)
        : PrintedEdition(other), m_author(other.m_author) {}

void Book::print() const {
    cout << "Name: " << m_name << endl;
    cout << "Year: " << m_year << endl;
    cout << "Publisher: " << m_publisher << endl;
    cout << "Number of pages: " << m_numPages << endl;
    cout << "Annotation: " << m_annotation << endl;
    cout << "Author: " << m_author << endl;
}

void Book::printToFile(ofstream& file) const {
    file << "Name: " << m_name << endl;
    file << "Year: " << m_year << endl;
    file << "Publisher: " << m_publisher << endl;
    file << "Number of pages: " << m_numPages << endl;
    file << "Annotation: " << m_annotation << endl;
    file << "Author: " << m_author << endl;
}
