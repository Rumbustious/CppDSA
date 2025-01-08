#ifndef QUEUE_H
#define QUEUE_H

#include "LinkedList.h"

template <typename T>
class Queue {
private:
    LinkedList<T> list;

public:
    Queue();
    ~Queue();

    void enqueue(T val);
    T dequeue();
    T front();
    bool isEmpty();
    size_t getSize();

    void print();
};

template <typename T>
Queue<T>::Queue() {}

template <typename T>
Queue<T>::~Queue() {}

template <typename T>
void Queue<T>::enqueue(T val) {
    list.push(val);
}

template <typename T>
T Queue<T>::dequeue() {
    return list.shift();
}

template <typename T>
T Queue<T>::front() {
    return list.getHeadData();
}

template <typename T>
bool Queue<T>::isEmpty() {
    return list.getSize() == 0;
}

template <typename T>
size_t Queue<T>::getSize() {
    return list.getSize();
}

template <typename T>
void Queue<T>::print() {
    list.print();
}

#endif 