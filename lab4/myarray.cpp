#include "myarray.h"

template <typename T>
Array<T>::Array(int s)
{
    size = s;
    arr = new T[size];
}

template <typename T>
Array<T>::~Array()
{
    delete[] arr;
}

template <typename T>
T Array<T>::sum()
{
    T total = 0;
    for (int i = 0; i < size; i++)
    {
        total += arr[i];
    }
    return total;
}

template <typename T>
T Array<T>::average()
{
    return sum() / size;
}

template <typename T>
void Array<T>::input()
{
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
}

template <typename T>
void Array<T>::display()
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

template <typename T>
Array<T> Array<T>::operator+(const Array<T> &a)
{
    Array<T> temp(size);
    for (int i = 0; i < size; i++)
    {
        temp.arr[i] = arr[i] + a.arr[i];
    }
    return temp;
}

template <typename T>
Array<T> Array<T>::operator-(const Array<T> &a)
{
    Array<T> temp(size);
    for (int i = 0; i < size; i++)
    {
        temp.arr[i] = arr[i] - a.arr[i];
    }
    return temp;
}

template <typename T>
bool Array<T>::operator!=(const Array<T> &a)
{
    if (size != a.size)
    {
        return true;
    }
    for (int i = 0; i < size; i++)
    {
        if (arr[i] != a.arr[i])
        {
            return true;
        }
    }
    return false;
}

template <typename T>
bool Array<T>::operator<(const Array<T> &a)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] >= a.arr[i])
        {
            return false;
        }
    }
    return true;
}

// Explicit template instantiation
template class Array<int>;
template class Array<float>;
template class Array<double>;
