#include <iostream>
using namespace std;

class Node {
public:
    int data;
    int height;
    Node* left;
    Node* right;

    Node(int val) : data(val), height(1), left(nullptr), right(nullptr) {}
};

class AVLTree {
private:
    Node* root;

    int getHeight(Node* node) {
        if (node == nullptr) {
            return 0;
        }
        return node->height;
    }

    int getBalanceFactor(Node* node) {
        if (node == nullptr) {
            return 0;
        }
        return getHeight(node->left) - getHeight(node->right);
    }

    Node* rotateRight(Node* y) {
        Node* x = y->left;
        Node* t2 = x->right;

        x->right = y;
        y->left = t2;

        y->height = 1 + max(getHeight(y->left), getHeight(y->right));
        x->height = 1 + max(getHeight(x->left), getHeight(x->right));

        return x;
    }

    Node* rotateLeft(Node* x) {
        Node* y = x->right;
        Node* t2 = y->left;

        y->left = x;
        x->right = t2;

        x->height = 1 + max(getHeight(x->left), getHeight(x->right));
        y->height = 1 + max(getHeight(y->left), getHeight(y->right));

        return y;
    }

    Node* insert(Node* node, int val) {
        if (node == nullptr) {
            return new Node(val);
        }

        if (val < node->data) {
            node->left = insert(node->left, val);
        } else if (val > node->data) {
            node->right = insert(node->right, val);
        } else {
            return node; // Duplicates not allowed
        }

        node->height = 1 + max(getHeight(node->left), getHeight(node->right));
        int balance = getBalanceFactor(node);

        // Left-Left Case
        if (balance > 1 && val < node->left->data) {
            return rotateRight(node);
        }

        // Right-Right Case
        if (balance < -1 && val > node->right->data) {
            return rotateLeft(node);
        }

        // Left-Right Case
        if (balance > 1 && val > node->left->data) {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }

        // Right-Left Case
        if (balance < -1 && val < node->right->data) {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }

        return node;
    }

    void inOrderTraversal(Node* node) {
        if (node == nullptr) {
            return;
        }

        inOrderTraversal(node->left);
        cout << node->data << " ";
        inOrderTraversal(node->right);
    }

public:
    AVLTree() : root(nullptr) {}

    void insert(int val) {
        root = insert(root, val);
    }

    void display() {
        inOrderTraversal(root);
        cout << endl;
    }
};
