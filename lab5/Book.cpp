#include "book.h"
#include <iostream>
using namespace std;

book::book(const string& title, const string& author, int year, const string& annotation,
           const string& genre, int pages, double price)
        : title(title), author(author), year(year), annotation(annotation), genre(genre), pages(pages), price(price) {}

void book::printInfo() const {
    cout << "Book: " << title << ", Author: " << author << ", Year: " << year
              << ", Genre: " << genre << ", Pages: " << pages << ", Price: $" << price
              << "\nAnnotation: " << annotation << endl;
}

void book::saveToFile(ofstream& file) const {
    file << "book\n" << title << "\n" << author << "\n" << year << "\n" << annotation << "\n"
         << genre << "\n" << pages << "\n" << price << "\n";
}

void book::loadFromFile(std::ifstream& file) {
    getline(file, title);
    getline(file, author);
    file >> year;
    file.ignore();
    getline(file, annotation);
    getline(file, genre);
    file >> pages >> price;
    file.ignore();
}

void book::addElement() {
    cout << "Введите название книги: ";
    getline(cin, title);
    cout << "Введите автора: ";
    getline(cin, author);
    cout << "Введите год выпуска: ";
    cin >> year;
    cin.ignore();
    cout << "Введите аннотацию: ";
    getline(cin, annotation);
    cout << "Введите жанр: ";
    getline(cin, genre);
    cout << "Введите объем страниц: ";
    cin >> pages;
    cout << "Введите стоимость: ";
    cin >> price;
    cin.ignore();
}

void book::deleteElement() {
    title = "";
    author = "";
    year = 0;
    annotation = "";
    genre = "";
    pages = 0;
    price = 0.0;
    cout << "Книга удалена." << endl;
}