#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class SuffixArray {
private:
    vector<int> sa;
    string str;

public:
    SuffixArray(const string& input) : str(input) {
        int n = str.length();
        sa.resize(n);

        for (int i = 0; i < n; ++i) {
            sa[i] = i;
        }

        sort(sa.begin(), sa.end(), [this](int a, int b) {
            return str.compare(a, str.length(), str, b, str.length()) < 0;
        });
    }

    void display() {
        for (int index : sa) {
            cout << str.substr(index) << endl;
        }
    }
};
