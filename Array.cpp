#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

class Array {
private:
    int arr[MAX_SIZE];
    int size;

public:
    Array() : size(0) {}

    void insert(int val) {
        if (size < MAX_SIZE) {
            arr[size++] = val;
        }
    }

    void display() {
        for (int i = 0; i < size; ++i) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
