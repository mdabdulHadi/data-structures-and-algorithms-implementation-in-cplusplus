#include <iostream>
#include <stack>
using namespace std;

class Stack {
private:
    stack<int> s;

public:
    void push(int val) {
        s.push(val);
    }

    void pop() {
        if (!s.empty()) {
            s.pop();
        }
    }

    int top() {
        return s.top();
    }

    bool isEmpty() {
        return s.empty();
    }
};
