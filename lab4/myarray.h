#ifndef ARRAYTEMPLATE_H
#define ARRAYTEMPLATE_H

#include <iostream>
using namespace std;

template <typename T>
class Array
{
private:
    T* arr;
    int size;
public:
    Array(int s);
    ~Array();
    T sum();
    T average();
    void input();
    void display();
    friend ostream &operator<<(ostream &out, const Array<T> &a)
    {
        for (int i = 0; i < a.size; i++)
        {
            out << a.arr[i] << " ";
        }
        return out;
    }
    friend istream &operator>>(istream &in, Array<T> &a)
    {
        for (int i = 0; i < a.size; i++)
        {
            in >> a.arr[i];
        }
        return in;
    }
    Array<T> operator+(const Array<T> &a);
    Array<T> operator-(const Array<T> &a);
    bool operator!=(const Array<T> &a);
    bool operator<(const Array<T> &a);
};

#endif // ARRAYTEMPLATE_H
