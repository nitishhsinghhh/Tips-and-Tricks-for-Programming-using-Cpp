#include <iostream>
#include <vector>
#include <cassert>

struct ListNode {
    int key;     // Key of the key-value pair
    int value;  //  Value associated with the key
    ListNode* next;     // Pointer to the next node in the linked list
    ListNode() : key(0), value(0), next(nullptr) {}             // Default constructor
    ListNode(int key) : key(key), value(0), next(nullptr) {}    // Constructor with key only
    ListNode(int key, int value) : key(key), value(value), next(nullptr) {}     // Constructor with key and value
    ListNode(int key, int value, ListNode* next) : key(key), value(value), next(next) {} // Constructor with key, value and next pointer
    ListNode(const ListNode& other) =delete; // Copy constructor disabled to prevent copying of nodes
    ListNode& operator=(const ListNode& other) = delete; // Copy assignment operator disabled to prevent copying of nodes
    ListNode(ListNode&& other) = delete; // Move constructor disabled to prevent moving of nodes
    ListNode& operator=(ListNode&& other) = delete; // Move assignment operator disabled to prevent moving of nodes
};

class HashMap {
public:
    HashMap();
    virtual void put(int key, int value);
    virtual int get(int key);
    virtual void remove(int key);

    virtual ~HashMap();

private:
    int size;
    std::vector<ListNode*> data;
    
    // Simple hash function
    int hash(int key) {
        return static_cast<unsigned int>(key) % size;
    }
};

HashMap::HashMap() : size(10000), data(10000, nullptr) {}

HashMap::~HashMap() {
    // Free allocated memory
    for (auto node : data) {
        while (node) {
            ListNode* temp = node;
            node = node->next;
            delete temp;
        }
    }
}

void HashMap::put(int key, int value) {
    int h = hash(key);
    if (!data[h]) {
        data[h] = new ListNode(key, value);
        return;
    }
    ListNode* node = data[h];
    while (node) {
        if (node->key == key) {
            node->value = value; 
            return;
        }
        if (!node->next) {
            node->next = new ListNode(key, value); 
            return;
        }
        node = node->next;
    }
}

int HashMap::get(int key) {
    int h = hash(key);
    ListNode* node = data[h];
    while (node) {
        if (node->key == key) 
            return node->value; 
        node = node->next;
    }
    return -1; 
}

void HashMap::remove(int key) {
    int h = hash(key);
    ListNode* node = data[h];
    if (!node) {
        return; 
    }
    if (node->key == key) {
        data[h] = node->next; 
        delete node;
        return;
    }
    while (node->next) {
        if (node->next->key == key) {
            ListNode* del = node->next;
            node->next = del->next; 
            delete del;
            return;
        }
        node = node->next;
    }
}

int main() {
    HashMap myHashMap;

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

    std::cout << "All test cases passed!" << std::endl;
    return 0;
}