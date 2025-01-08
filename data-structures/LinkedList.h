#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

using namespace std;

template <typename T>
class LinkedList {
   private:
    struct Node {
        T data;
        Node* next;
        Node(T val) {
            this->data = val;
            this->next = nullptr;
        }
    };

   public:
    Node* head;
    Node* tail;
    size_t size;

    LinkedList();
    LinkedList(T val);
    ~LinkedList();

    void push(T val);
    void unshift(T val);
    void insert(T val, size_t index);

    T pop();
    T shift();
    T remove(size_t index);

    size_t find(T value, bool firstOccurrence = true);

    // TODO: add sorting to linked list
    
    // void sort();
    // void sort(size_t start, size_t end);

    size_t getSize();

    void print();
};

template <typename T>
LinkedList<T>::LinkedList() {
    head = nullptr;
    tail = nullptr;
    size = 0;
}

template <typename T>
LinkedList<T>::LinkedList(T val) {
    head = new Node(val);
    tail = head;
    size++;
}

template <typename T>
void LinkedList<T>::push(T val) {
    Node* newNode = new Node(val);
    if (!head) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
    size++;
}

template <typename T>
void LinkedList<T>::unshift(T val) {
    Node* newNode = new Node(val);
    if (!head) {
        head = tail = newNode;
    } else {
        newNode->next = head;
        head = newNode;
    }
    size++;
}

template <typename T>
T LinkedList<T>::shift() {
    if (size == 0) {
        throw std::out_of_range("List is empty");
    }

    Node* temp = head;
    head = head->next;
    T tempData = temp->data;
    delete temp;
    size--;
    return tempData;
}

template <typename T>
void LinkedList<T>::insert(T val, size_t index) {
    // check boundries
    if (index > size) {
        return;
    }

    // check if we push to head
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
    current->next = newNode;
    size++;
}

template <typename T>
T LinkedList<T>::pop() {
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

    Node* current = head;
    while (current->next != tail) {
        current = current->next;
    }

    Node* temp = tail;
    tail = current;
    tail->next = nullptr;
    T tempData = temp->data;
    delete temp;
    size--;
    return tempData;
}

template <typename T>
T LinkedList<T>::remove(size_t index) {
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
    while (i < index - 1) {
        current = current->next;
        i++;
    }

    Node* temp = current->next;
    current->next = temp->next;
    T tempData = temp->data;
    delete temp;
    size--;
    return tempData;
}

template <typename T>
void LinkedList<T>::print() {
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
LinkedList<T>::~LinkedList() {
    while (head != nullptr) {
        size--;

        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

#endif
