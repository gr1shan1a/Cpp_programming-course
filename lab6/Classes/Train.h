#ifndef TRAIN_H
#define TRAIN_H

#include <string>
#include <iostream>
#include <stdexcept>

class Train {
public:
    // Конструкторы
    Train();
    Train(const std::string& dest, int number, const std::string& time);
    Train(const Train& other);
    ~Train();

    // Методы доступа
    std::string getDestination() const;
    int getTrainNumber() const;
    std::string getDepartureTime() const;

    void setDest(const std::string& dest);
    void setNumber(int number);
    void setTime(const std::string& time);

    // Перегрузка операторов
    friend std::istream& operator>>(std::istream& in, Train& train);
    friend std::ostream& operator<<(std::ostream& out, const Train& train);

    // Оператор присваивания
    Train& operator=(const Train& other);

private:
    std::string dest;
    int number;
    std::string time;
};

#endif // TRAIN_H
