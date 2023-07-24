#include <iostream>
#include <queue>
using namespace std;

class Queue {
private:
    queue<int> q;

public:
    void enqueue(int val) {
        q.push(val);
    }

    void dequeue() {
        if (!q.empty()) {
            q.pop();
        }
    }

    int front() {
        return q.front();
    }

    bool isEmpty() {
        return q.empty();
    }
};
