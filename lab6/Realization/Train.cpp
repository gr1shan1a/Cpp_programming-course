#include "../Classes/Train.h"

Train::Train() : dest("Unknown"), number(0), time("Unknown") {
    std::cout << ":Default constructor called for Train" << std::endl;
}

Train::Train(const std::string& dest, int number, const std::string& time)
        : dest(dest), number(number), time(time) {
    std::cout << ":Parameterized constructor called for Train" << std::endl;
}

Train::Train(const Train& other)
        : dest(other.dest), number(other.number), time(other.time) {
    std::cout << ":Copy constructor called for Train" << std::endl;
}

Train::~Train() {
    std::cout << ":Destructor called for Train" << std::endl;
}

std::string Train::getDestination() const { return dest; }
int Train::getTrainNumber() const { return number; }
std::string Train::getDepartureTime() const { return time; }

void Train::setDest(const std::string& dest) {
    if (dest.empty()) {
        throw std::invalid_argument("Err:Destination cannot be empty");
    }
    this->dest = dest;
}

void Train::setNumber(int number) {
    if (number <= 0) {
        throw std::invalid_argument("Err:Train number must be positive");
    }
    this->number = number;
}

void Train::setTime(const std::string& time) {
    if (time.empty()) {
        throw std::invalid_argument("Err:Departure time cannot be empty");
    }
    this->time = time;
}

// Перегрузка >>
std::istream& operator>>(std::istream& in, Train& train) {
    in >> train.dest >> train.number >> train.time;
    return in;
}

std::ostream& operator<<(std::ostream& out, const Train& train) {
    out << "Destination: " << train.dest
        << ", Train Number: " << train.number
        << ", Departure Time: " << train.time << std::endl;
    return out;
}

// Оператор присваивания
Train& Train::operator=(const Train& other) {
    if (this != &other) {
        dest = other.dest;
        number = other.number;
        time = other.time;
    }
    std::cout << "Assignment operator called for Train" << std::endl;
    return *this;
}
