#include "square.h"

void squareArrayElements(int* array, int size)
{
    for (int i = 0; i < size; i++)
    {
        array[i] = array[i] * array[i];
    }
}
