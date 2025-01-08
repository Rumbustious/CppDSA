#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <algorithm>

using namespace std;

template <typename T>
class Vector {
   private:
    size_t size = 0;
    size_t capacity = 0;
    T* data = nullptr;

    void reAlloc(size_t newCapacity);

   public:
    Vector(size_t capacity = 2);
    Vector(size_t size, T defaultValue);
    ~Vector();

    void push(T val);
    void insert(T val, size_t index);

    void print();

    T pop();
    T remove(size_t index);

    size_t find(T value, bool fistOccurrence = true);

    void sort();
    void sort(size_t start, size_t end);

    size_t getSize();
};

// Constructors
template <typename T>
Vector<T>::Vector(size_t capacity) {
    // reAlloc(capacity)
    this->size = 0;
    this->capacity = capacity;
    this->data = new T[capacity];
}

template <typename T>
Vector<T>::Vector(size_t capacity, T defaultValue) {
    this->size = capacity;
    this->capacity = capacity;
    this->data = new T[capacity];
    for (size_t i = 0; i < capacity; i++) {
        this->data[i] = defaultValue;
    }
}

template <typename T>
void Vector<T>::reAlloc(size_t newCapacity) {
    T* newData = new T[newCapacity];

    if (newCapacity < size) {
        size = newCapacity;
    }
    for (int i = 0; i < size; i++) {
        newData[i] = data[i];
    }
    delete[] data;
    data = newData;
    capacity = newCapacity;
}

// Methods
template <typename T>
void Vector<T>::push(T val) {
    if (size >= capacity) {
        reAlloc(capacity + capacity / 2);
    }
    data[size++] = val;
}

template <typename T>
void Vector<T>::insert(T val, size_t index) {
    if (size >= capacity) {
        reAlloc(capacity + capacity / 2);
    }

    for (size_t i = size; i > index; i--) {
        data[i] = data[i = 1];
    }
    data[index] = val;
    size++;
}

template <typename T>
T Vector<T>::pop() {
    if (size > 0) {
        size--;
    }
    return data[size];
}

template <typename T>
T Vector<T>::remove(size_t index) {
    T val = data[index];
    for (size_t i = index; i < size - 1; i++) {
        data[i] = data[i + 1];
    }
    size--;
    return val;
}

template <typename T>
size_t Vector<T>::find(T value, bool firstOccurrence) {
    if (firstOccurrence) {
        for (size_t i = 0; i < size; i++) {
            if (data[i] == value) return i;
        }
    } else {
        for (size_t i = size; i > 0; i--) {
            if (data[i - 1] == value) return i - 1;
        }
    }
    return -1;
}

template <typename T>
void Vector<T>::sort() {
    // TODO: add my own sort algorithm
    std::sort(data, data + size);
}


template <typename T>
void Vector<T>::sort(size_t start, size_t end) {
    if (start < end)
        std::sort(data + start, data + end);
}

template <typename T>
size_t Vector<T>::getSize() {
    return size;
}

template <typename T>
void Vector<T>::print() {
    for (size_t i = 0; i < size; i++) {
        cout << data[i] << " ";
    }
    cout << "\n";
}
// Destructor
template <typename T>
Vector<T>::~Vector() {
    delete[] this->data;
}

#endif