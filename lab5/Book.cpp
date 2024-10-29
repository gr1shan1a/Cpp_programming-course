#include "book.h"
#include <iostream>
using namespace std;

Book::Book(const string& title, const string& author, int year, const string& annotation,
           const string& genre, int pages, double price)
        : title(title), author(author), year(year), annotation(annotation), genre(genre), pages(pages), price(price) {}

void Book::printInfo() const {
    cout << "Book: " << title << ", Author: " << author << ", Year: " << year
              << ", Genre: " << genre << ", Pages: " << pages << ", Price: $" << price
              << "\nAnnotation: " << annotation << endl;
}

void Book::saveToFile(ofstream& file) const {
    file << "book\n" << title << "\n" << author << "\n" << year << "\n" << annotation << "\n"
         << genre << "\n" << pages << "\n" << price << "\n";
}

void Book::loadFromFile(std::ifstream& file) {
    getline(file, title);
    getline(file, author);
    file >> year;
    file.ignore();
    getline(file, annotation);
    getline(file, genre);
    file >> pages >> price;
    file.ignore();
}

void Book::addElement() {
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

void Book::deleteElement() {
    title = "";
    author = "";
    year = 0;
    annotation = "";
    genre = "";
    pages = 0;
    price = 0.0;
    cout << "Книга удалена." << endl;
}

void Book::edit() {
    int choice;
    cout << "Изменение канцелярии:" << endl;
    cout << "1. Изменить названия" << endl;
    cout << "2. Изменить автора" << endl;
    cout << "3. Изменить год выпуска" << endl;
    cout << "4. Изменить аннотацию" << endl;
    cout << "5. Изменить жанр" << endl;
    cout << "6. Изменить объем страниц" << endl;
    cout << "7. Изменить стоимость" << endl;
    cout << "Выберите, что хотите изменить: ";
    cin >> choice;
    cin.ignore();

    switch (choice) {
        case 1:
            cout << "Введите новое название: ";
            getline(cin, title);
            break;
        case 2:
            cout << "Введите нового автора: ";
            getline(cin, author);
            break;
        case 3:
            cout << "Введите год: ";
            cin >> year;
            cin.ignore();
            break;
        case 4:
            cout << "Введите новую аннотацию: ";
            getline(cin, annotation);
            break;
        case 5:
            cout << "Введите жанр: ";
            getline(cin, genre);
            break;
        case 6:
            cout << "Введите год: ";
            cin >> pages;
            cin.ignore();
            break;
        case 7:
            cout << "Введите год: ";
            cin >> price;
            cin.ignore();
            break;

        default:
            cout << "Неверный выбор!" << endl;
            break;
    }
}