#ifndef DoublyLinkedList_H
#define DoublyLinkedList_H

#include <iostream>

using namespace std;

template <typename T>
class DoublyLinkedList {
    private:
        struct Node{
            T data;
            Node* next;
            Node* prev;
            Node(T val) {
                this->data = val;
                this->next = nullptr;
                this->prev = nullptr;
            }
        }
    
    public:
        Node* head;
        Node* tail;
        size_t size;

        DoublyLinkedList();
        DoublyLinkedList(T val);
        ~DoublyLinkedList();

        void push(T val);
        void unshift(T val);
        void insert(T val, size_t index);

        T pop();
        T shift();
        T remove(size_t index);

        size_t find(T value, bool firstOccurrence = true);

        size_t getSize();
        void print();

        
};

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList() {
    head = nullptr;
    tail = nullptr;
    size = 0;
}

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList(T val) {
    head = new Node(val);
    tail = head;
    size++;
}

template <typename T>
void DoublyLinkedList<T>::push(T val) {
    Node* newNode = new Node(val);
    if (size == 0) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    size++;
}

template <typename T>
void DoublyLinkedList<T>::unshift(T val) {
    Node* newNode = new Node(val);
    if (size == 0) {
        head = tail = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    size++;
}

template <typename T>
void DoublyLinkedList<T>::insert(T val, size_t index) {
    if (index > size) {
        return;
    }

    if (index == 0) {
        unshift(val);
        return;
    }

    if (index == size) {
        push(val);
        return;
    }

    Node* newNode = new Node(val);
    Node* current = head;
    size_t i = 0;
    while (i < index - 1) {
        current = current->next;
        i++;
    }
    newNode->next = current->next;
    newNode->prev = current;
    current->next->prev = newNode;
    current->next = newNode;
    size++;
}

template <typename T>
T DoublyLinkedList<T>::pop() {
    if (size == 0) {
        throw std::out_of_range("List is empty");
    }

    if (size == 1) {
        Node* temp = head;
        head = nullptr;
        tail = nullptr;
        T tempData = temp->data;
        delete temp;
        size--;
        return tempData;
    }

    Node* temp = tail;
    tail = tail->prev;
    tail->next = nullptr;
    T tempData = temp->data;
    delete temp;
    size--;
    return tempData;
}

template <typename T>
T DoublyLinkedList<T>::shift() {
    if (size == 0) {
        throw std::out_of_range("List is empty");
    }

    Node* temp = head;
    head = head->next;
    head->prev = nullptr;
    T tempData = temp->data;
    delete temp;
    size--;
    return tempData;
}

template <typename T>
T DoublyLinkedList<T>::remove(size_t index) {
    if (size == 0) {
        throw std::out_of_range("List is empty");
    }

    if (index >= size) {
        throw std::out_of_range("Index out of bounds");
    }

    if (index == 0) {
        return shift();
    }

    if (index == size - 1) {
        return pop();
    }

    Node* current = head;
    size_t i = 0;
    while (i < index) {
        current = current->next;
        i++;
    }
    current->prev->next = current->next;
    current->next->prev = current->prev;
    T tempData = current->data;
    delete current;
    size--;
    return tempData;
}


template <typename T>
size_t DoublyLinkedList<T>::find(T value, bool firstOccurrence) {
    Node* current = head;
    size_t index = 0;
    while (current != nullptr) {
        if (current->data == value) {
            return index;
        }
        current = current->next;
        index++;
    }
    return -1;
}

template <typename T>
size_t DoublyLinkedList<T>::getSize() {
    return size;
}

template <typename T>
void DoublyLinkedList<T>::print() {
    if (size == 0) {
        cout << "List is empty" << endl;
        return;
    }
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList() {
    Node* current = head;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
}


#endif