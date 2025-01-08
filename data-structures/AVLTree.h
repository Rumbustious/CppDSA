#ifndef AVLTREE_H
#define AVLTREE_H

#include <iostream>

using namespace std;

template <typename T>
class AVLTree {
private:
    struct Node {
        T data;
        Node* left;
        Node* right;
        int height;
        Node(T val);
    };

    Node* root;

    int height(Node* node) ;
    int getBalance(Node* node) ;
    Node* rotateRight(Node* y);
    Node* rotateLeft(Node* x);
    Node* insert(Node* node, T val);
    Node* remove(Node* node, T val);
    Node* findMin(Node* node) ;
    Node* findMax(Node* node) ;
    bool search(Node* node, T val) ;
    void inorder(Node* node) ;
    void preorder(Node* node) ;
    void postorder(Node* node) ;
    void clear(Node* node);

public:
    AVLTree();
    ~AVLTree();

    void insert(T val);
    void remove(T val);
    bool search(T val) ;
    void inorder() ;
    void preorder() ;
    void postorder() ;
    T findMin() ;
    T findMax() ;
    void clear();
};

template <typename T>
AVLTree<T>::Node::Node(T val) : data(val), left(nullptr), right(nullptr), height(1) {}

template <typename T>
AVLTree<T>::AVLTree() : root(nullptr) {}

template <typename T>
AVLTree<T>::~AVLTree() {
    clear(root);
}

template <typename T>
int AVLTree<T>::height(Node* node)  {
    return node ? node->height : 0;
}

template <typename T>
int AVLTree<T>::getBalance(Node* node)  {
    return node ? height(node->left) - height(node->right) : 0;
}

template <typename T>
typename AVLTree<T>::Node* AVLTree<T>::rotateRight(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

template <typename T>
typename AVLTree<T>::Node* AVLTree<T>::rotateLeft(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

template <typename T>
typename AVLTree<T>::Node* AVLTree<T>::insert(Node* node, T val) {
    if (node == nullptr) {
        return new Node(val);
    }

    if (val < node->data) {
        node->left = insert(node->left, val);
    } else if (val > node->data) {
        node->right = insert(node->right, val);
    } else {
        return node;
    }

    node->height = 1 + max(height(node->left), height(node->right));

    int balance = getBalance(node);

    if (balance > 1 && val < node->left->data) {
        return rotateRight(node);
    }

    if (balance < -1 && val > node->right->data) {
        return rotateLeft(node);
    }

    if (balance > 1 && val > node->left->data) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }

    if (balance < -1 && val < node->right->data) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    return node;
}

template <typename T>
typename AVLTree<T>::Node* AVLTree<T>::remove(Node* node, T val) {
    if (node == nullptr) {
        return node;
    }

    if (val < node->data) {
        node->left = remove(node->left, val);
    } else if (val > node->data) {
        node->right = remove(node->right, val);
    } else {
        if (node->left == nullptr || node->right == nullptr) {
            Node* temp = node->left ? node->left : node->right;

            if (temp == nullptr) {
                temp = node;
                node = nullptr;
            } else {
                *node = *temp;
            }

            delete temp;
        } else {
            Node* temp = findMin(node->right);
            node->data = temp->data;
            node->right = remove(node->right, temp->data);
        }
    }

    if (node == nullptr) {
        return node;
    }

    node->height = 1 + max(height(node->left), height(node->right));

    int balance = getBalance(node);

    if (balance > 1 && getBalance(node->left) >= 0) {
        return rotateRight(node);
    }

    if (balance > 1 && getBalance(node->left) < 0) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }

    if (balance < -1 && getBalance(node->right) <= 0) {
        return rotateLeft(node);
    }

    if (balance < -1 && getBalance(node->right) > 0) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    return node;
}

template <typename T>
typename AVLTree<T>::Node* AVLTree<T>::findMin(Node* node)  {
    while (node->left != nullptr) {
        node = node->left;
    }
    return node;
}

template <typename T>
typename AVLTree<T>::Node* AVLTree<T>::findMax(Node* node)  {
    while (node->right != nullptr) {
        node = node->right;
    }
    return node;
}

template <typename T>
bool AVLTree<T>::search(Node* node, T val)  {
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
void AVLTree<T>::inorder(Node* node)  {
    if (node != nullptr) {
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }
}

template <typename T>
void AVLTree<T>::preorder(Node* node)  {
    if (node != nullptr) {
        cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }
}

template <typename T>
void AVLTree<T>::postorder(Node* node)  {
    if (node != nullptr) {
        postorder(node->left);
        postorder(node->right);
        cout << node->data << " ";
    }
}

template <typename T>
void AVLTree<T>::clear(Node* node) {
    if (node != nullptr) {
        clear(node->left);
        clear(node->right);
        delete node;
    }
}

template <typename T>
void AVLTree<T>::insert(T val) {
    root = insert(root, val);
}

template <typename T>
void AVLTree<T>::remove(T val) {
    root = remove(root, val);
}

template <typename T>
bool AVLTree<T>::search(T val)  {
    return search(root, val);
}

template <typename T>
void AVLTree<T>::inorder()  {
    inorder(root);
    cout << endl;
}

template <typename T>
void AVLTree<T>::preorder()  {
    preorder(root);
    cout << endl;
}

template <typename T>
void AVLTree<T>::postorder()  {
    postorder(root);
    cout << endl;
}

template <typename T>
T AVLTree<T>::findMin()  {
    if (root == nullptr) {
        throw std::out_of_range("Tree is empty");
    }
    return findMin(root)->data;
}

template <typename T>
T AVLTree<T>::findMax()  {
    if (root == nullptr) {
        throw std::out_of_range("Tree is empty");
    }
    return findMax(root)->data;
}

template <typename T>
void AVLTree<T>::clear() {
    clear(root);
    root = nullptr;
}

#endif // AVLTREE_H