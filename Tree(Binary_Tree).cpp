#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BinaryTree {
private:
    Node* root;

public:
    BinaryTree() : root(nullptr) {}

    Node* insert(Node* root, int val) {
        if (root == nullptr) {
            return new Node(val);
        }

        if (val < root->data) {
            root->left = insert(root->left, val);
        } else {
            root->right = insert(root->right, val);
        }

        return root;
    }

    void inOrderTraversal(Node* root) {
        if (root == nullptr) {
            return;
        }

        inOrderTraversal(root->left);
        cout << root->data << " ";
        inOrderTraversal(root->right);
    }

    void insert(int val) {
        root = insert(root, val);
    }

    void display() {
        inOrderTraversal(root);
        cout << endl;
    }
};
