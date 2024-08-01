#include "ProtectedQueue.h"
#include <iostream>

using namespace std;

ProtectedQueue::ProtectedQueue(Queue *queue1) : queue_prot(queue1){}

void ProtectedQueue::push(int k) {
    if (size == capacity) {
        capacity *= 2;
        int *temp = new int[capacity];
        for (int i = 0; i < size; ++i) {
            temp[i] = arr[i];
        }
    }
    arr[size++] = k;

}

void ProtectedQueue::setQueueProt(Queue *queueProt) {
    queue_prot = queueProt;
}

Queue *ProtectedQueue::getQueueProt() const {
    return queue_prot;
}

void ProtectedQueue::pop() {
    if (size > 0) {
        cout << arr[0] << endl;
        for (int i = 0; i < size-1; ++i) {
            arr[i] = arr[i+1];
        }
        size--;
    } else {
        cout << "Queue is empty" << endl;
    }
}

void ProtectedQueue::print() {
    if (size == 0)
        cout << "Empty" << endl;
    else cout << "\nMy Queue: ";
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void ProtectedQueue::findElement() {
    bool flag = false;
    for (int i = size-1; i > 0; i--) {
        if (arr[i] < findAvgGorm()) {
            cout << arr[i] << endl;
            flag = true;
            break;
        }
    }
    if (!flag) cout << "All numbers are qual" << endl;
}

void ProtectedQueue::copy() {
    size_of_copy = size;
    if (size_of_copy > 0) {
        copy_arr = new int[size_of_copy];
        for (int i = 0; i < size_of_copy; ++i) {
            copy_arr[i] = arr[i];
        }
    } else {
        copy_arr = nullptr;
    }
}


void ProtectedQueue::mergeWithCopy() {
    int size_c = size_of_copy;
    int *arr_all = new int[size + size_c];

    for (int i = 0; i < size; ++i) {
        arr_all[i] = arr[i];
        cout << arr_all[i] << " ";
    }
    for (int i = size; i < size + size_c; ++i) {
        arr_all[i] = copy_arr[i - size];
        cout << arr_all[i] << " ";
    }
    cout << "\n";

}

double ProtectedQueue::findAvgGorm() {
    double g;
    double summ = 0.0;
    for (int i = 0; i < size; ++i) {
        summ += (1.0 / arr[i]);
    }
    g = size / summ;
    return g;
}