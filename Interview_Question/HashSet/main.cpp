#include <iostream>
#include <list>
#include <functional>

template <typename T>
class HashSet {
private:
    static const int size = 1000;
    std::list<T> table[size];

    int hash(T key) {
        return std::hash<T>{}(key) % size;
    }

public:
    void insert(T key) {
        int index = hash(key);
        table[index].push_back(key);
    }

    void remove(T key) {
        int index = hash(key);
        table[index].remove(key);
    }

    bool contains(T key) {
        int index = hash(key);
        for (const T& val : table[index]) {
            if (val == key) {
                return true;
            }
        }
        return false;
    }
};
int main() {
    HashSet<int> intSet;
    intSet.insert(42);
    intSet.insert(10);
    std::cout << "Contains 10: " << intSet.contains(10) << "\n";

    HashSet<std::string> strSet;
    strSet.insert("apple");
    strSet.insert("banana");
    std::cout << "Contains 'banana': " << strSet.contains("banana") << "\n";
}