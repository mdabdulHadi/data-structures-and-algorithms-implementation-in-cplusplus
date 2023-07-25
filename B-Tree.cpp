#include <iostream>
#include <vector>
using namespace std;

const int M = 3; // B-Tree order

class BTreeNode {
public:
    bool leaf;
    vector<int> keys;
    vector<BTreeNode*> children;

    BTreeNode(bool isLeaf = true) : leaf(isLeaf), keys(0), children(0) {}
};

class BTree {
private:
    BTreeNode* root;

    void splitChild(BTreeNode* parent, int childIdx) {
        // Split the child node into two child nodes of the parent node
    }

    void insertNonFull(BTreeNode* node, int key) {
        // Insert a key into a non-full node
    }

    void traverse(BTreeNode* node) {
        // Perform an in-order traversal of the B-Tree
    }

public:
    BTree() : root(nullptr) {}

    void insert(int key) {
        // Insert a key into the B-Tree
    }

    void display() {
        traverse(root);
        cout << endl;
    }
};
