#ifndef BST_H
#define BST_H

#include <iostream>

using namespace std;

template <typename T>
class BST {
private:
    struct Node {
        T data;
        Node* left;
        Node* right;
        Node(T val);
    };

    Node* root;

    void insert(Node*& node, T val);
    bool search(Node* node, T val);
    void traverse(Node* node, int order);
    Node* remove(Node* node, T val);
    Node* findMin(Node* node);
    Node* findMax(Node* node);
    void clear(Node* node);

public:
    BST();
    ~BST();

    void insert(T val);
    bool search(T val);
    void traverse(int order = 0); // 0: inorder, 1: preorder, 2: postorder
    void remove(T val);
    void clear();
    T findMin();
    T findMax();
};

template <typename T>
BST<T>::Node::Node(T val) {
    this->data = val;
    this->left = nullptr;
    this->right = nullptr;
}

template <typename T>
BST<T>::BST() : root(nullptr) {}

template <typename T>
BST<T>::~BST() {
    clear(root);
}

template <typename T>
void BST<T>::insert(T val) {
    insert(root, val);
}

template <typename T>
void BST<T>::insert(Node*& node, T val) {
    if (node == nullptr) {
        node = new Node(val);
    } else if (val < node->data) {
        insert(node->left, val);
    } else {
        insert(node->right, val);
    }
}

template <typename T>
bool BST<T>::search(T val) {
    return search(root, val);
}

template <typename T>
bool BST<T>::search(Node* node, T val) {
    if (node == nullptr) {
        return false;
    } else if (val == node->data) {
        return true;
    } else if (val < node->data) {
        return search(node->left, val);
    } else {
        return search(node->right, val);
    }
}

template <typename T>
void BST<T>::traverse(int order) {
    traverse(root, order);
    cout << endl;
}

template <typename T>
void BST<T>::traverse(Node* node, int order) {
    if (node != nullptr) {
        if (order == 1) { // preorder
            cout << node->data << " ";
            traverse(node->left, order);
            traverse(node->right, order);
        } else if (order == 2) { // postorder
            traverse(node->left, order);
            traverse(node->right, order);
            cout << node->data << " ";
        } else { // inorder
            traverse(node->left, order);
            cout << node->data << " ";
            traverse(node->right, order);
        }
    }
}

template <typename T>
void BST<T>::remove(T val) {
    root = remove(root, val);
}

template <typename T>
typename BST<T>::Node* BST<T>::remove(Node* node, T val) {
    if (node == nullptr) {
        return node;
    } else if (val < node->data) {
        node->left = remove(node->left, val);
    } else if (val > node->data) {
        node->right = remove(node->right, val);
    } else {
        if (node->left == nullptr) {
            Node* temp = node->right;
            delete node;
            return temp;
        } else if (node->right == nullptr) {
            Node* temp = node->left;
            delete node;
            return temp;
        } else {
            Node* temp = findMin(node->right);
            node->data = temp->data;
            node->right = remove(node->right, temp->data);
        }
    }
    return node;
}

template <typename T>
typename BST<T>::Node* BST<T>::findMin(Node* node) {
    while (node->left != nullptr) {
        node = node->left;
    }
    return node;
}

template <typename T>
typename BST<T>::Node* BST<T>::findMax(Node* node) {
    while (node->right != nullptr) {
        node = node->right;
    }
    return node;
}

template <typename T>
T BST<T>::findMin() {
    if (root == nullptr) {
        throw std::out_of_range("Tree is empty");
    }
    return findMin(root)->data;
}

template <typename T>
T BST<T>::findMax() {
    if (root == nullptr) {
        throw std::out_of_range("Tree is empty");
    }
    return findMax(root)->data;
}

template <typename T>
void BST<T>::clear() {
    clear(root);
    root = nullptr;
}

template <typename T>
void BST<T>::clear(Node* node) {
    if (node != nullptr) {
        clear(node->left);
        clear(node->right);
        delete node;
    }
}

#endif // BST_H