# Custom HashSet in C++
A simple, template-based HashSet implementation in C++ using separate chaining (linked lists) to resolve hash collisions. This class mimics the behavior of HashSet<T> from C# (.NET) — a collection that contains no duplicate elements and supports fast insert, delete, and search operations.

## Features
- Templated for generic use
- Handles collisions via separate chaining
- Supports:
  - insert(key)
  - remove(key)
  - contains(key)
 
```cpp
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
```
## Example Usage
```cpp
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
```

## Class Diagram (UML)
Represents the structure of the class, its attributes, and methods.

```
+------------------+
|   HashSet<T>     |
+------------------+
| - table: list<T>[] |
| - size: const int |
+------------------+
| +insert(key: T)   |
| +remove(key: T)   |
| +contains(key: T) |
| -hash(key: T): int|
+------------------+
```

## STL Equivalent
```cpp
#include <unordered_set>
#include <iostream>

int main() {
    std::unordered_set<int> intSet;
    intSet.insert(42);
    intSet.insert(10);
    std::cout << "Contains 10: " << (intSet.count(10) > 0) << "\n";

    std::unordered_set<std::string> strSet = {"apple", "banana"};
    std::cout << "Contains 'banana': " << (strSet.count("banana") > 0) << "\n";
}
```
