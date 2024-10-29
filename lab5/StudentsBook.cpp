#include "StudentsBook.h"
#include <iostream>

using namespace std;

StudentsBook::StudentsBook(const string& title, const string& author, int year, const string& institution,
                           int studyYear, int pages, double price)
        : title(title),
        author(author),
        year(year),
        institution(institution),
        studyYear(studyYear),
        pages(pages),
        price(price) {}

void StudentsBook::printInfo() const {
    cout << "StudentsBook: " << title << ", Author: " << author << ", Year: " << year
              << ", Institution: " << institution << ", Study Year: " << studyYear
              << ", Pages: " << pages << ", Price: $" << price << endl;
}

void StudentsBook::saveToFile(ofstream& file) const {
    file << "StudentsBook\n" << title << "\n" << author << "\n" << year << "\n" << institution << "\n"
         << studyYear << "\n" << pages << "\n" << price << "\n";
}

void StudentsBook::loadFromFile(ifstream& file) {
    getline(file, title);
    getline(file, author);
    file >> year;
    file.ignore();
    getline(file, institution);
    file >> studyYear >> pages >> price;
    file.ignore();
}

void StudentsBook::addElement() {
    cout << "Введите название учебника: ";
    getline(cin, title);
    cout << "Введите автора: ";
    getline(cin, author);
    cout << "Введите год выпуска: ";
    cin >> year;
    cin.ignore();
    cout << "Введите для какого учебного заведения предназначено: ";
    getline(cin, institution);
    cout << "Введите год обучения: ";
    cin >> studyYear;
    cout << "Введите объем страниц: ";
    cin >> pages;
    cout << "Введите стоимость: ";
    cin >> price;
    cin.ignore();
}

void StudentsBook::deleteElement() {
    title = "";
    author = "";
    year = 0;
    institution = "";
    studyYear = 0;
    pages = 0;
    price = 0.0;
    cout << "Учебник удален." << endl;
}

void StudentsBook::edit() {
    int choice;
    cout << "Изменение канцелярии:" << endl;
    cout << "1. Изменить названия" << endl;
    cout << "2. Изменить автора" << endl;
    cout << "3. Изменить год выпуска" << endl;
    cout << "4. Изменить для какого учебного заведения предназначено" << endl;
    cout << "5. Изменить год обучения" << endl;
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
            cout << "Введите новое предназначение: ";
            getline(cin, institution);
            break;
        case 5:
            cout << "Введите новый учебный год: ";
            cin >> studyYear;
            cin.ignore();
            break;
        case 6:
            cout << "Введите новое кол-во страниц: ";
            cin >> pages;
            cin.ignore();
            break;
        case 7:
            cout << "Введите новую цену: ";
            cin >> price;
            cin.ignore();
            break;

        default:
            cout << "Неверный выбор!" << endl;
            break;
    }
}