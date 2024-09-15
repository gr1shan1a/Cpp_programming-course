#include "Chancellery.h"
#include <iostream>

using namespace std;

Chancellery::Chancellery(const string& Type, const string& color, const string& purpose, double price)
        : Type(Type), color(color), purpose(purpose), price(price) {}

void Chancellery::printInfo() const {
    cout << "Chancellery: " << Type << ", Color: " << color << ", Purpose: " << purpose
              << ", Price: $" << price << endl;
}

void Chancellery::saveToFile(ofstream& file) const {
    file << "Chancellery\n" << Type << "\n" << color << "\n" << purpose << "\n" << price << "\n";
}

void Chancellery::loadFromFile(std::ifstream& file) {
    getline(file, Type);
    getline(file, color);
    getline(file, purpose);
    file >> price;
    file.ignore();
}

void Chancellery::addElement() {
    cout << "Введите тип канцелярии: ";
    getline(cin, Type);
    printf("Введите цвет %s: ", Type.c_str());
    getline(cin, color);
    cout << "Введите название книги: ";
    getline(cin, purpose);
    cout << "Введите назначение: ";
    cin >> price;
    cin.ignore();
}

void Chancellery::deleteElement() {
    Type = "";
    color = "";
    purpose = "";
    price = 0.0;
    cout << "Канцелярка удалена." << endl;
}