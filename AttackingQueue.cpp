#include <iostream>
#include "AttackingQueue.h"
#include "UnitedStates.h"

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
        State *toReturn = queue[front];
        currentSize--;
        if (front != capacity - 1) {
            front++;
        } else {
            front = 0;
        }
        return toReturn;
    }
}

bool AttackingQueue::isEmpty() {
    return (currentSize == 0);
}

bool AttackingQueue::isFull() {
    return (currentSize == capacity);
}

void AttackingQueue::printQueue() {
    cout << "States Planning Attacks on You (Soonest First):" << endl;
    for (int i = front; i < currentSize + front; i++) {
        if (i < capacity) {
            cout << queue[i]->name << " is planning on attacking with an army size of " << queue[i]->armySize << "!" << endl;
        } else {
            cout << queue[i - capacity]->name << " is planning on attacking with an army size of " << queue[i - capacity]->armySize << "!" << endl;
        }
    }
}
// ==============
// Private Methods
// ==============