#include "Coordinate.h"
#include <iostream>

Coordinates::Coordinates(double x_val, double y_val, double z_val) : x(x_val), y(y_val), z(z_val) {}

Coordinates Coordinates::operator++(int) {
    Coordinates temp = *this;
    x += 1.5;
    y += 1.5;
    z += 1.5;
    return temp;
}

Coordinates Coordinates::operator--(int) {
    Coordinates temp = *this;
    x -= 5.9;
    y -= 5.9;
    z -= 5.9;
    return temp;
}

Coordinates& operator++(Coordinates& c) {
    c.x += 1.5;
    c.y += 1.5;
    c.z += 1.5;
    return c;
}

Coordinates& Coordinates::operator--() {
    x -= 5.9;
    y -= 5.9;
    z -= 5.9;
    return *this;
}

void Coordinates::display() {
    std::cout << "Coordinates: (" << x << ", " << y << ", " << z << ")" << std::endl;
}
