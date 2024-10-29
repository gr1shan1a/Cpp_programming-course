#include "Chancellery.h"
#include <iostream>

using namespace std;

Chancellery::Chancellery(const string& Type, const string& color, const string& purpose, double price)
        : type(type), color(color), purpose(purpose), price(price) {}

void Chancellery::printInfo() const {
    cout << "Chancellery: " << type << ", Color: " << color << ", Purpose: " << purpose
              << ", Price: $" << price << endl;
}

void Chancellery::saveToFile(ofstream& file) const {
    file << "\nChancellery\n" << type << "\n" << color << "\n" << purpose << "\n" << price << "\n";
}

void Chancellery::loadFromFile(std::ifstream& file) {
    getline(file, type);
    getline(file, color);
    getline(file, purpose);
    file >> price;
    file.ignore();
}

void Chancellery::addElement() {
    cout << "Введите тип канцелярии: ";
    getline(cin, type);
    printf("Введите цвет %s: ", type.c_str());
    getline(cin, color);
    cout << "Введите название книги: ";
    getline(cin, purpose);
    cout << "Введите цена: ";
    cin >> price;
    cin.ignore();
}

void Chancellery::deleteElement() {
    type = "";
    color = "";
    purpose = "";
    price = 0.0;
    cout << "Канцелярка удалена." << endl;
}

void Chancellery::edit() {
    int choice;
    cout << "Изменение канцелярии:" << endl;
    cout << "1. Изменить тип" << endl;
    cout << "2. Изменить цвет" << endl;
    cout << "3. Изменить назначение" << endl;
    cout << "4. Изменить стоимость" << endl;
    cout << "Выберите, что хотите изменить: ";
    cin >> choice;
    cin.ignore();

    switch (choice) {
        case 1:
            cout << "Введите новый тип: ";
            getline(cin, type);
            break;
        case 2:
            cout << "Введите новый цвет: ";
            getline(cin, color);
            break;
        case 3:
            cout << "Введите новое назначение: ";
            getline(cin, purpose);
            break;
        case 4:
            cout << "Введите новую стоимость: ";
            cin >> price;
            cin.ignore();
            break;
        default:
            cout << "Неверный выбор!" << endl;
            break;
    }
}
