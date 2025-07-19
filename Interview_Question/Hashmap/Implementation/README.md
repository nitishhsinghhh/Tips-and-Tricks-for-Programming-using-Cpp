# Designing a HashMap without Built-in Libraries

Hash maps are powerful data structures that enable efficient data retrieval by associating keys with corresponding values. In this article, we'll explore the implementation of a basic hash map in C++.

---

## HashMap Overview

Hash maps are commonly used to store key-value pairs. They provide:

- **Fast lookups**
- **Efficient updates**
- **Reliable deletions**

We'll explore the `put()`, `get()`, and `remove()` methods, each of which utilizes a hash function to compute the index where data should be stored or retrieved.

---

## Structuring the Hash Map

The hash map uses a **linked list** structure for handling collisions. Each node (defined in a `ListNode` struct) stores:

- A `key`
- A `value`
- A `next` pointer (to link to the next node in case of collision)

### MyHashMap Class

The `MyHashMap` class includes:

- A `vector<ListNode*>` to represent hash buckets
- A private `hash()` function
- Public methods: `put()`, `get()`, and `remove()`

---

## Initialization

The constructor initializes:

- A fixed-size array of buckets (10,000 slots)
- Each slot initially holds `nullptr`

---

## Inserting Elements

The `put()` method:

- Computes the hash of the key
- Traverses the linked list at the computed index
- Updates value if key exists, or adds a new node if key is new

---

## Retrieving Values

The `get()` method:

- Computes the hash of the key
- Traverses the bucket list to find the matching key
- Returns the value, or `-1` if the key isn’t found

---

## Removing Elements

The `remove()` method:

- Computes the hash of the key
- Searches for and deletes the node containing the key
- Updates the linked list pointers to unlink the deleted node

---

## C++ Implementation

```cpp
#include <iostream>
#include <vector>
#include <cassert>

using std::cout;
using std::endl;
using std::vector;

class MyHashMap {
    struct ListNode {
        int key;
        int value;
        ListNode* next;
        ListNode(int key, int value) : key(key), value(value), next(nullptr) {}
    };

private:
    int size; // Declare size before data
    vector<ListNode*> data;

    int hash(int key) {
        return key % size;
    }

public:
    MyHashMap() : size(10000), data(10000, nullptr) {} // Initialization order matches declaration order

    ~MyHashMap() {
        // Free allocated memory
        for (auto node : data) {
            while (node) {
                ListNode* temp = node;
                node = node->next;
                delete temp;
            }
        }
    }

    void put(int key, int value) {
        int h = hash(key);
        if (!data[h]) {
            data[h] = new ListNode(key, value);
            return;
        }
        ListNode* node = data[h];
        while (node) {
            if (node->key == key) {
                node->value = value; // Update value if key exists
                return;
            }
            if (!node->next) {
                node->next = new ListNode(key, value); // Add new node at the end
                return;
            }
            node = node->next;
        }
    }

    int get(int key) {
        int h = hash(key);
        ListNode* node = data[h];
        while (node) {
            if (node->key == key) 
                return node->value; // Return value if key is found
            node = node->next;
        }
        return -1; // Return -1 if key is not found
    }

    void remove(int key) {
        int h = hash(key);
        ListNode* node = data[h];
        if (!node) {
            return; // Key does not exist
        }
        if (node->key == key) {
            data[h] = node->next; // Remove head of the list
            delete node;
            return;
        }
        while (node->next) {
            if (node->next->key == key) {
                ListNode* del = node->next;
                node->next = del->next; // Unlink the node
                delete del;
                return;
            }
            node = node->next;
        }
    }
};

int main() {
    MyHashMap myHashMap;

    // Test cases using assert
    myHashMap.put(1, 1);
    myHashMap.put(2, 2);
    assert(myHashMap.get(1) == 1);
    assert(myHashMap.get(2) == 2);
    assert(myHashMap.get(3) == -1);

    myHashMap.put(2, 1); 
    assert(myHashMap.get(2) == 1);

    myHashMap.remove(2);
    assert(myHashMap.get(2) == -1);

    myHashMap.put(10001, 10);
    myHashMap.put(1, 5);
    assert(myHashMap.get(10001) == 10);
    assert(myHashMap.get(1) == 5);

    myHashMap.remove(3);
    assert(myHashMap.get(3) == -1);

    cout << "All test cases passed!" << endl;
    return 0;
}

```
