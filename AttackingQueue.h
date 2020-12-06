#include <iostream>
#include "UnitedStates.h"

#ifndef ATTACKING_QUEUE_H
#define ATTACKING_QUEUE_H

class AttackingQueue {
    public:
        AttackingQueue(){};
        AttackingQueue(int size);
        void enqueue(State *toQueue);
        State* dequeue();
    private:
        int capacity = 3;
        State* *queue;
        int front = 0;
        int back = 0;
        int currentSize = 0;
        bool isEmpty();
        bool isFull();
};

#endif