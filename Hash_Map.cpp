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

int main() {
    HashMap<string, int> map;

    map.insert("apple", 5);
    map.insert("banana", 3);
    map.insert("orange", 7);

    cout << "Apple: " << map.get("apple") << endl;     // Output: Apple: 5
    cout << "Banana: " << map.get("banana") << endl;   // Output: Banana: 3
    cout << "Orange: " << map.get("orange") << endl;   // Output: Orange: 7
    cout << "Grapes: " << map.get("grapes") << endl;   // Output: Grapes: 0 (default-constructed int)

    cout << "Contains Banana: " << map.contains("banana") << endl;   // Output: Contains Banana: 1 (true)

    map.remove("banana");
    cout << "Contains Banana: " << map.contains("banana") << endl;   // Output: Contains Banana: 0 (false)

    return 0;
}
