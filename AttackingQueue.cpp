#include <iostream>
#include "AttackingQueue.h"

// ==============
// Public Methods
// ==============

AttackingQueue::AttackingQueue(int size) {
    capacity = size;
    queue = new State*[capacity];
}

void AttackingQueue::enqueue(State *toQueue) {
    if (isFull()) {
        return;
    } else {
        currentSize++;
        if (back != capacity - 1) {
            back++;
        } else {
            back = 0;
        }
        queue[back] = toQueue;
    }
}

State* AttackingQueue::dequeue() {
    if (isEmpty()) {
        return nullptr;
    } else {
        currentSize--;
        if (front != capacity - 1) {
            front++;
        } else {
            front = 0;
        }
    }
}

// ==============
// Private Methods
// ==============

bool AttackingQueue::isEmpty() {
    return (currentSize == 0);
}

bool AttackingQueue::isFull() {
    return (currentSize == capacity);
}