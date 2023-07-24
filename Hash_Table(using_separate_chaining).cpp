#include <iostream>
#include <vector>
using namespace std;

class HashTable {
private:
    static const int TABLE_SIZE = 100;
    vector<vector<pair<int, int>>> table;

    int hashFunction(int key) {
        return key % TABLE_SIZE;
    }

public:
    HashTable() : table(TABLE_SIZE) {}

    void insert(int key, int value) {
        int hash = hashFunction(key);
        table[hash].push_back(make_pair(key, value));
    }

    int get(int key) {
        int hash = hashFunction(key);
        for (const auto& entry : table[hash]) {
            if (entry.first == key) {
                return entry.second;
            }
        }
        return -1; // Assuming -1 represents a key not found
    }
};
