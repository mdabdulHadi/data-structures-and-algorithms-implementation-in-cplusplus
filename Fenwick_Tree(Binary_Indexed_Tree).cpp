#include <iostream>
#include <vector>
using namespace std;

class FenwickTree {
private:
    vector<int> bit;
    int size;

    int getSum(int idx) {
        int sum = 0;
        while (idx > 0) {
            sum += bit[idx];
            idx -= idx & -idx;
        }
        return sum;
    }

public:
    FenwickTree(int n) : size(n) {
        bit.resize(n + 1, 0);
    }

    void update(int idx, int val) {
        while (idx <= size) {
            bit[idx] += val;
            idx += idx & -idx;
        }
    }

    int query(int left, int right) {
        return getSum(right) - getSum(left - 1);
    }
};
