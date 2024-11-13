#ifndef TRAIN_H
#define TRAIN_H

#include <string>
#include <iostream>

class Train {
public:
    Train(const std::string& dest, int number, const std::string& time);
    ~Train();

    std::string getDestination() const;
    int getTrainNumber() const;
    std::string getDepartureTime() const;

    void setDest(const std::string& dest);
    void setNumber(int number);
    void setTime(const std::string& time);

    friend std::istream& operator>>(std::istream& in, Train& train);
    friend std::ostream& operator<<(std::ostream& out, const Train& train);

private:
    std::string dest;
    int number;
    std::string time;
};

#endif // TRAIN_H
