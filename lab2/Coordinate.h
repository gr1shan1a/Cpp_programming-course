#ifndef COORDINATES_H
#define COORDINATES_H

class Coordinates {
private:
    double x, y, z;

public:
    Coordinates(double x_val, double y_val, double z_val);

    Coordinates operator++(int);
    Coordinates operator--(int);
    friend Coordinates& operator++(Coordinates& c);
    Coordinates& operator--();
    void display();
};

#endif // COORDINATES_H
