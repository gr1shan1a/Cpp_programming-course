#include "../Classes/Train.h"

using namespace std;

// Конструктор
Train::Train(const string& dest, int number, const string& time)
        : dest(dest), number(number), time(time) {}


Train::~Train() {
    cout << "TRAIN destructor called" << endl;
}

// Методы доступа
string Train::getDestination() const { return dest; }
int Train::getTrainNumber() const { return number; }
string Train::getDepartureTime() const { return time; }

void Train::setDest(const string &dest) {
    Train::dest = dest;
}

void Train::setNumber(int number) {
    Train::number = number;
}

void Train::setTime(const string &time) {
    Train::time = time;
}

// Перегрузка оператора >>
istream& operator>>(istream& in, Train& train) {
    in >> train.dest >> train.number >> train.time;
    return in;
}

// Перегрузка оператора <<
ostream& operator<<(ostream& out, const Train& train) {
    out << "Destination: " << train.dest
        << ", Train Number: " << train.number
        << ", Departure Time: " << train.time << endl;
    return out;
}
