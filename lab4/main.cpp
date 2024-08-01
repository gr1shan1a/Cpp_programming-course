#include <iostream>
#include "square.h"
#include "myarray.h"

using namespace std;

int main()
{
    int choice;
    do {
        cout << "Menu:" << endl;
        cout << "1. Square Array Elements" << endl;
        cout << "2. Array Template Operations" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

            case 1: {
                int size;
                cout << "Enter the size of the array: ";
                cin >> size;
                int* array = new int[size];
                cout << "Enter array elements: ";
                for (int i = 0; i < size; i++) {
                    cin >> array[i];
                }
                squareArrayElements(array, size);
                cout << "Squared array elements: ";
                for (int i = 0; i < size; i++) {
                    cout << array[i] << " ";
                }
                cout << endl;
                delete[] array;
                break;
            }
            case 2: {
                int size;
                cout << "Enter the size of the array: ";
                cin >> size;
                Array<int> array1(size);
                cout << "Enter elements of array 1: ";
                cin >> array1;
                Array<int> array2(size);
                cout << "Enter elements of array 2: ";
                cin >> array2;
                cout << "Array 1: " << array1 << endl;
                cout << "Array 2: " << array2 << endl;
                Array<int> arraySum = array1 + array2;
                cout << "Sum of arrays: " << arraySum << endl;
                Array<int> arrayDiff = array1 - array2;
                cout << "Difference of arrays: " << arrayDiff << endl;
                cout << "Array 1 sum: " << array1.sum() << ", average: " << array1.average() << endl;
                cout << "Array 2 sum: " << array2.sum() << ", average: " << array2.average() << endl;
                if (array1 != array2) {
                    cout << "Arrays are not equal." << endl;
                } else {
                    cout << "Arrays are equal." << endl;
                }
                if (array1 < array2) {
                    cout << "Array 1 is less than Array 2." << endl;
                } else {
                    cout << "Array 1 is not less than Array 2." << endl;
                }
                break;
            }
            case 0:
                cout << "Exit суксесфул" << endl;
                break;
            default:
                cout << "Invalid choice. Try again." << endl;
        }
    } while (choice != 0);

    return 0;
}
