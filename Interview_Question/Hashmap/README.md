# 🧠 Mastering Hashmap in C++: Quick Guide to Efficient Mapping

## 🚀 Introduction

Hashmaps in C++ are data structures that allow you to store key-value pairs with fast retrieval using hash functions. In this guide, you'll learn the fundamentals of hashmaps and how to leverage them for high-performance applications.

---

## 📌 What Is a Hashmap?

A **hashmap** implements an associative array—mapping unique keys to values with efficient lookup. 

### ⚡ Efficiency

- Average-case time complexity for lookup, insert, delete: **O(1)**
- Compared to arrays and linked lists: **Much faster**

```cpp
#include <iostream>
#include <unordered_map>

int main() {
    std::unordered_map<std::string, int> hashmap;
    hashmap["apple"] = 1;
    hashmap["banana"] = 2;
    
    std::cout << "Value of banana: " << hashmap["banana"] << std::endl;
    return 0;
}
```

## Key Concepts in Hashing

| Term         | Meaning                                       |
|--------------|-----------------------------------------------|
| Key & Value  | Every value is associated with a unique key   |
| Hash Function| Converts key into an index for storage        |
| Collision    | Two keys hashing to the same index            |
| Load Factor  | Ratio of elements to buckets                  |
| Rehashing    | Resizing and reorganizing to reduce load      |

## Comparison to Other Structures

| Structure           | Access Time | Ordered | Notes                         |
|---------------------|-------------|---------|-------------------------------|
| std::unordered_map  | O(1) avg    | No      | Fast, uses hashing            |
| std::map            | O(log n)    | Yes     | Red-black tree                |
| vector              | O(n)        | Yes     | Fast iteration, slow lookup   |
| set                 | O(log n)    | Yes     | Unique elements only          |

