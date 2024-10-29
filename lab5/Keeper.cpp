#include "Keeper.h"
#include "book.h"
#include "StudentsBook.h"
#include "Chancellery.h"
#include <iostream>
#include <fstream>

using namespace std;

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
        cout << endl;
    }
}

void Keeper::saveToFile(const string& filename) const {
    ofstream file(filename);
    if (!file) {
        cerr << "Error opening file for writing!" << endl;
        return;
    }

    file << size << "\n";
    for (int i = 0; i < size; ++i) {
        items[i]->saveToFile(file);
    }
}

void Keeper::loadFromFile(const std::string& filename) {
    ifstream file(filename);
    if (!file) {
        cerr << "Error opening file for reading!" << endl;
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
        string type;
        getline(file, type);

        BaseClass *item = nullptr;
        if (type == "Book") {
            item = new Book();
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

void Keeper::edit(int index) {
    if (index >= 0 && index < size) {
        BaseClass* item = items[index];
        item->edit();
    } else {
        std::cout << "Такого индекса нет" << std::endl;
    }
}