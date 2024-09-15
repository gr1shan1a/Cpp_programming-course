#ifndef CHANCELLERY_H
#define CHANCELLERY_H

#include "BaseClass.h"
#include <string>

class Chancellery : public BaseClass {
private:
    std::string type;
    std::string color;
    std::string purpose;
    double price;

public:
    Chancellery(const std::string& type = "", const std::string& color = "", const std::string& purpose = "", double price = 0.0);

    void printInfo() const override;
    void saveToFile(std::ofstream& file) const override;
    void loadFromFile(std::ifstream& file) override;
};

#endif // CHANCELLERY_H