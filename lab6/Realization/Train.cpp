#include "../Classes/Train.h"

// Конструктор
Train::Train(const std::string& dest, int number, const std::string& time)
        : dest(dest), number(number), time(time) {}

Train::~Train() {
    std::cout << "TRAIN destructor called" << std::endl;
}

// Методы доступа
std::string Train::getDestination() const { return dest; }
int Train::getTrainNumber() const { return number; }
std::string Train::getDepartureTime() const { return time; }

void Train::setDest(const std::string& dest) {
    Train::dest = dest;
}

void Train::setNumber(int number) {
    Train::number = number;
}

void Train::setTime(const std::string& time) {
    Train::time = time;
}

// Перегрузка оператора >>
std::istream& operator>>(std::istream& in, Train& train) {
    in >> train.dest >> train.number >> train.time;
    return in;
}

// Перегрузка оператора <<
std::ostream& operator<<(std::ostream& out, const Train& train) {
    out << "Destination: " << train.dest
        << ", Train Number: " << train.number
        << ", Departure Time: " << train.time << std::endl;
    return out;
}
