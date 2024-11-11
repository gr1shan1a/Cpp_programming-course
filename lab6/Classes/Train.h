#ifndef TRAIN_H
#define TRAIN_H

#include <iostream>
#include <string>

using namespace std;

class Train {
public:
    string dest;
    int number;
    string time;

    // Конструктор
    Train();
    Train(const string& dest, int number, const string& time);
    Train(const Train& other);

    ~Train();

    // Методы доступа
    string getDestination() const;
    int getTrainNumber() const;
    string getDepartureTime() const;

    // Перегрузка операторов
    friend istream& operator>>(istream& in, Train& train);
    friend ostream& operator<<(ostream& out, const Train& train);

    void setDest(const string &dest);

    void setNumber(int number);

    void setTime(const string &time);
};

#endif // TRAIN_H
