#include "Keeper.h"
#include "book.h"
#include "StudentsBook.h"
#include "Chancellery.h"
#include <iostream>
#include <fstream>

Keeper::Keeper() : items(nullptr), size(0) {}

Keeper::~Keeper() {
    for (int i = 0; i < size; ++i) {
        delete items[i];
    }
    delete[] items;
}

void Keeper::add(BaseClass* item) {
    BaseClass** temp = new BaseClass*[size + 1];
    for (int i = 0; i < size; ++i) {
        temp[i] = items[i];
    }
    temp[size] = item;
    delete[] items;
    items = temp;
    ++size;
}

void Keeper::remove(int index) {
    if (index < 0 || index >= size) return;

    delete items[index];
    for (int i = index; i < size - 1; ++i) {
        items[i] = items[i + 1];
    }

    BaseClass** temp = new BaseClass*[size - 1];
    for (int i = 0; i < size - 1; ++i) {
        temp[i] = items[i];
    }

    delete[] items;
    items = temp;
    --size;
}

void Keeper::printAll() const {
    for (int i = 0; i < size; ++i) {
        items[i]->printInfo();
        std::cout << std::endl;
    }
}

void Keeper::saveToFile(const std::string& filename) const {
    std::ofstream file(filename);
    if (!file) {
        std::cerr << "Error opening file for writing!" << std::endl;
        return;
    }

    file << size << "\n";
    for (int i = 0; i < size; ++i) {
        items[i]->saveToFile(file);
    }
}

void Keeper::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Error opening file for reading!" << std::endl;
        return;
    }

    for (int i = 0; i < size; ++i) {
        delete items[i];
    }
    delete[] items;
    int newSize;
    file >> newSize;
    file.ignore();

    items = new BaseClass *[newSize];
    size = 0;

    for (int i = 0; i < newSize; ++i) {
        std::string type;
        std::getline(file, type);

        BaseClass *item = nullptr;
        if (type == "book") {
            item = new book();
        } else if (type == "StudentsBook") {
            item = new StudentsBook();
        } else if (type == "Chancellery") {
            item = new Chancellery();
        }

        if (item) {
            item->loadFromFile(file);
            add(item);
        }
    }
}