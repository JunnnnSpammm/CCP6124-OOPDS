#ifndef DYNQUEUE_H
#define DYNQUEUE_H

#include <iostream>
#include <stdexcept>

template <typename T>
class DynQueue {
private:
    // Structure for the queue nodes
    struct QueueNode {
        T value;
        QueueNode* next;
        QueueNode(T val) : value(val), next(nullptr) {}
    };

    QueueNode* front; // Points to the front of the queue
    QueueNode* rear;  // Points to the rear of the queue
    int numItems;     // Tracks the number of items in the queue

public:
    // Constructor
    DynQueue();

    // Destructor
    ~DynQueue();

    // Queue operations
    void enqueue(T);
    void dequeue(T &);
    bool isEmpty() const;
    void clear();
    int size() const;
};

// Constructor
template <typename T>
DynQueue<T>::DynQueue() {
    front = nullptr;
    rear = nullptr;
    numItems = 0;
}

// Destructor
template <typename T>
DynQueue<T>::~DynQueue() {
    clear();
}

// enqueue inserts a value at the rear of the queue.
template <typename T>
void DynQueue<T>::enqueue(T item) {
    QueueNode* newNode = new QueueNode(item);

    if (isEmpty()) {
        front = newNode;
        rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    numItems++;
}

// dequeue removes the value at the front of the queue and copies it into item.
template <typename T>
void DynQueue<T>::dequeue(T &item) {
    if (isEmpty()) {
        throw std::underflow_error("The queue is empty.");
    } else {
        item = front->value;
        QueueNode* temp = front;
        front = front->next;
        delete temp;
        numItems--;
        
        // If the queue is now empty, reset rear to nullptr
        if (front == nullptr) {
            rear = nullptr;
        }
    }
}

// isEmpty returns true if the queue is empty, otherwise false.
template <typename T>
bool DynQueue<T>::isEmpty() const {
    return numItems == 0;
}

// size returns the number of items currently in the queue.
template <typename T>
int DynQueue<T>::size() const {
    return numItems;
}

// clear deallocates all nodes currently in the queue.
template <typename T>
void DynQueue<T>::clear() {
    T dummy;
    while (!isEmpty()) {
        dequeue(dummy);
    }
}

#endif