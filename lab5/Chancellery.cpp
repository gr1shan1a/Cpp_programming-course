#include "Chancellery.h"
#include <iostream>

Chancellery::Chancellery(const std::string& type, const std::string& color, const std::string& purpose, double price)
        : type(type), color(color), purpose(purpose), price(price) {}

void Chancellery::printInfo() const {
    std::cout << "Chancellery: " << type << ", Color: " << color << ", Purpose: " << purpose
              << ", Price: $" << price << std::endl;
}

void Chancellery::saveToFile(std::ofstream& file) const {
    file << "Chancellery\n" << type << "\n" << color << "\n" << purpose << "\n" << price << "\n";
}

void Chancellery::loadFromFile(std::ifstream& file) {
    std::getline(file, type);
    std::getline(file, color);
    std::getline(file, purpose);
    file >> price;
    file.ignore();
}