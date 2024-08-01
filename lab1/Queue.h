//
// Created by Grigory Kuranov on 05.04.2024.
//

#ifndef __1_QUEUE_H
#define __1_QUEUE_H

class Queue {
public:
    Queue();
    virtual void push(int k);
    virtual void pop();
    virtual void print();
    virtual void findElement();
    virtual void copy();
    virtual void mergeWithCopy();
    virtual double findAvgGorm();
//    virtual int getCopyArr();
    virtual ~Queue();

protected:
    int *arr;
    int size;
    int capacity;
    int * copy_arr;
    int size_of_copy;

    void resize();
};
#endif //__1_QUEUE_H
