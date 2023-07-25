#include <iostream>
#include <vector>
#include <list>
using namespace std;

template <typename KeyType, typename ValueType>
class HashMap {
private:
    const int TABLE_SIZE = 100; // You can adjust the table size based on your needs
    vector<list<pair<KeyType, ValueType>>> table;

    int hashFunction(const KeyType& key) {
        return hash<KeyType>{}(key) % TABLE_SIZE;
    }

public:
    HashMap() : table(TABLE_SIZE) {}

    void insert(const KeyType& key, const ValueType& value) {
        int index = hashFunction(key);
        for (auto& entry : table[index]) {
            if (entry.first == key) {
                entry.second = value; // Update existing key-value pair
                return;
            }
        }
        table[index].push_back(make_pair(key, value)); // Insert new key-value pair
    }

    bool contains(const KeyType& key) {
        int index = hashFunction(key);
        for (const auto& entry : table[index]) {
            if (entry.first == key) {
                return true;
            }
        }
        return false;
    }

    ValueType get(const KeyType& key) {
        int index = hashFunction(key);
        for (const auto& entry : table[index]) {
            if (entry.first == key) {
                return entry.second;
            }
        }
        // You can choose to handle key not found scenario differently, e.g., throw an exception
        // For simplicity, we return a default-constructed ValueType in this implementation.
        return ValueType{};
    }

    void remove(const KeyType& key) {
        int index = hashFunction(key);
        table[index].remove_if([key](const pair<KeyType, ValueType>& entry) {
            return entry.first == key;
        });
    }
};
