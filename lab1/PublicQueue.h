//
// Created by Grigory Kuranov on 05.04.2024.
//

#ifndef __1_PUBLICQUEUE_H
#define __1_PUBLICQUEUE_H

#include "Queue.h"

class PublicQueue : public Queue {
private:
    Queue* queue_pub;
public:
    PublicQueue(Queue* queue);
    void push(int k);
    void pop();
    void print();
    void findElement();
    void copy();
    void mergeWithCopy();
    double findAvgGorm();
};


#endif //__1_PUBLICQUEUE_H
