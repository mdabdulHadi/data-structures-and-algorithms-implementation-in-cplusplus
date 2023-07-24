#include <iostream>
#include <deque>
using namespace std;

class Deque {
private:
    deque<int> dq;

public:
    void pushFront(int val) {
        dq.push_front(val);
    }

    void pushBack(int val) {
        dq.push_back(val);
    }

    void popFront() {
        if (!dq.empty()) {
            dq.pop_front();
        }
    }

    void popBack() {
        if (!dq.empty()) {
            dq.pop_back();
        }
    }

    int front() {
        return dq.front();
    }

    int back() {
        return dq.back();
    }

    bool isEmpty() {
        return dq.empty();
    }
};
