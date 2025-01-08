#ifndef STACK_H
#define STACK_H

#include "LinkedList.h"

template <typename T>
class Stack {
private:
    LinkedList<T> list;

public:
    Stack();
    ~Stack();

    void push(T val);
    T pop();
    T peek();
    bool isEmpty();
    size_t getSize();

    void print();
};

template <typename T>
Stack<T>::Stack() {}

template <typename T>
Stack<T>::~Stack() {}

template <typename T>
void Stack<T>::push(T val) {
    list.push(val);
}

template <typename T>
T Stack<T>::pop() {
    return list.pop();
}

template <typename T>
T Stack<T>::peek() {
    return list.getTailData();
}

template <typename T>
bool Stack<T>::isEmpty() {
    return list.getSize() == 0;
}

template <typename T>
size_t Stack<T>::getSize() {
    return list.getSize();
}

template <typename T>
void Stack<T>::print() {
    list.print();
}

#endif // STACK_H