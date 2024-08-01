#ifndef __1_PROTECTEDQUEUE_H
#define __1_PROTECTEDQUEUE_H

#include "Queue.h"

class ProtectedQueue : protected Queue {
private:
    Queue* queue_prot;
public:
    ProtectedQueue(Queue* queue1);
    void push(int k) { Queue::push(k); }
    void pop() { Queue::pop(); }
    void print() { Queue::print(); }
    void findElement() { Queue::findElement(); }
    void copy() { Queue::copy(); }
    void mergeWithCopy() { Queue::mergeWithCopy(); }
    double findAvgGorm() { return Queue::findAvgGorm(); }

    Queue *getQueueProt() const;

    void setQueueProt(Queue *queueProt);
};


#endif //__1_PROTECTEDQUEUE_H
