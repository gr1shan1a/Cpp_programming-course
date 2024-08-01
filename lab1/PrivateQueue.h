//
// Created by Grigory Kuranov on 05.04.2024.
//

#ifndef __1_PRIVATEQUEUE_H
#define __1_PRIVATEQUEUE_H

#include "ProtectedQueue.h"

class PrivateQueue : private Queue {
private:
    Queue* queue_privat;
public:
    PrivateQueue(Queue* queue);

    void push(int k);
    void pop();
    void print();
    void findElement();
    void copy();
    void mergeWithCopy();
    double findAvgGorm();

};

#endif //__1_PRIVATEQUEUE_H
