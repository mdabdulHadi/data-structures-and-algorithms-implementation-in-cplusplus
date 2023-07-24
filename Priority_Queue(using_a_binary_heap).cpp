#include <iostream>
#include <vector>
using namespace std;

class PriorityQueue {
private:
    vector<int> heap;
    int size;

    void heapifyUp(int idx) {
        // Fix the heap property by moving the element up
    }

    void heapifyDown(int idx) {
        // Fix the heap property by moving the element down
    }

public:
    PriorityQueue() : size(0) {
        heap.push_back(0); // The 0th index is not used to simplify calculations
    }

    void insert(int val) {
        heap.push_back(val);
        ++size;
        heapifyUp(size);
    }

    int extractMin() {
        if (size == 0) {
            return -1; // Assuming -1 represents an empty heap
        }
        int minVal = heap[1];
        heap[1] = heap[size];
        heap.pop_back();
        --size;
        heapifyDown(1);
        return minVal;
    }

    bool isEmpty() {
        return size == 0;
    }
};
