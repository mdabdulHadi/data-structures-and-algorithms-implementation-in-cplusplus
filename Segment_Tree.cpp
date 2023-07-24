#include <iostream>
#include <vector>
using namespace std;

class SegmentTree {
private:
    vector<int> st;
    vector<int> arr;
    int n;

    int build(int idx, int left, int right) {
        // Build the segment tree recursively
    }

    int query(int idx, int left, int right, int qLeft, int qRight) {
        // Perform a range query on the segment tree
    }

    void update(int idx, int left, int right, int updateIdx, int newVal) {
        // Update the segment tree with a new value at a specific index
    }

public:
    SegmentTree(const vector<int>& input) {
        arr = input;
        n = arr.size();
        st.resize(4 * n); // A common approach is to allocate 4 times the size of the input array
        build(1, 0, n - 1);
    }

    int query(int left, int right) {
        return query(1, 0, n - 1, left, right);
    }

    void update(int updateIdx, int newVal) {
        update(1, 0, n - 1, updateIdx, newVal);
    }
};
