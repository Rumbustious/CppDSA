#ifndef NODE_H
#define NODE_H

#include <iostream>

using namespace std;

template <typename T>
class Node {
   public:
    T data;
    Node* next;

    Node(T data);
    Node(T data, Node* next);
    // ~Node();
};


#endif