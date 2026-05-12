#include <iostream>
#include <vector>
#include <cassert>

/**
 * @struct ListNode
 * @brief A node representing a key-value pair in a linked list.
 * 
 * Used primarily for handling collisions within the HashMap via separate chaining.
 */
struct ListNode {
    int key;         /**< The unique identifier for the entry. */
    int value;       /**< The data associated with the key. */
    ListNode* next;  /**< Pointer to the next node in the chain. */

    /** @brief Default constructor. */
    ListNode() : key(0), value(0), next(nullptr) {}
    
    /** @brief Constructor initializing key only. */
    ListNode(int key) : key(key), value(0), next(nullptr) {}
    
    /** @brief Constructor initializing key and value. */
    ListNode(int key, int value) : key(key), value(value), next(nullptr) {}
    
    /** @brief Full constructor initializing key, value, and next pointer. */
    ListNode(int key, int value, ListNode* next) : key(key), value(value), next(next) {}

    /** @name Memory Safety
     *  Disabled copy and move operations to prevent accidental shallow copies and double-frees.
     *  @{ */
    ListNode(const ListNode& other) = delete;
    ListNode& operator=(const ListNode& other) = delete;
    ListNode(ListNode&& other) = delete;
    ListNode& operator=(ListNode&& other) = delete;
    /** @} */
};

/**
 * @class HashMap
 * @brief A fixed-size integer-based hash map using separate chaining.
 * 
 * This class provides basic associative array functionality including insertion,
 * retrieval, and deletion of key-value pairs.
 */
class HashMap {
public:
    /**
     * @brief Construct a new HashMap object.
     * 
     * Initializes the bucket array with a default size of 10,000.
     */
    HashMap();

    /**
     * @brief Inserts a key-value pair into the map.
     * 
     * If the key already exists, its value is updated. Otherwise, a new node is added.
     * @param key The integer key to map.
     * @param value The integer value to store.
     */
    virtual void put(int key, int value);

    /**
     * @brief Retrieves the value associated with a key.
     * 
     * @param key The key to look up.
     * @return The associated value, or -1 if the key is not found.
     */
    virtual int get(int key);

    /**
     * @brief Removes a key and its associated value from the map.
     * 
     * Frees the memory associated with the node if found.
     * @param key The key to remove.
     */
    virtual void remove(int key);

    /**
     * @brief Destroy the HashMap object and free all allocated nodes.
     */
    virtual ~HashMap();

private:
    int size;                      /**< Fixed number of buckets in the hash table. */
    std::vector<ListNode*> data;   /**< Internal storage for bucket heads. */

    /**
     * @brief Internal hash function to map keys to bucket indices.
     * 
     * Uses an unsigned cast to safely handle negative keys.
     * @param key The input key.
     * @return A bucket index in the range [0, size - 1].
     */
    int hash(int key) {
        return static_cast<unsigned int>(key) % size;
    }
};

// --- Implementation ---

HashMap::HashMap() : size(10000), data(10000, nullptr) {}

HashMap::~HashMap() {
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
    if (!node) return; 

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

/**
 * @brief Entry point for the HashMap demonstration and unit testing.
 * 
 * This function executes a series of stress tests to validate:
 * - Basic CRUD (Create, Read, Update, Delete) operations.
 * - Collision resolution via separate chaining.
 * - Robustness against negative integer keys.
 * - Integrity of linked list re-linking during node removal.
 * - Large-scale data consistency.
 * 
 * @return int Returns 0 upon successful completion of all assertions.
 */
int main() {
    HashMap map;

    /** 
     * @test Test 1: Basic Put/Get 
     * Verifies that standard key-value pairs are stored and retrieved correctly.
     */
    map.put(1, 10);
    map.put(2, 20);
    assert(map.get(1) == 10);
    assert(map.get(2) == 20);

    /** 
     * @test Test 2: Update existing key 
     * Ensures that 'put' updates the value of an existing key rather than creating a duplicate.
     */
    map.put(1, 100);
    assert(map.get(1) == 100);

    /** 
     * @test Test 3: Handling Collisions 
     * Forces a collision (1 and 10001 both hash to index 1) to verify separate chaining logic.
     */
    map.put(1, 5);
    map.put(10001, 50);
    assert(map.get(1) == 5);      // Verify head of chain
    assert(map.get(10001) == 50); // Verify tail of chain

    /** 
     * @test Test 4: Negative Keys 
     * Validates that the hash function safely handles negative integers using unsigned casting.
     */
    map.put(-1, 99);
    map.put(-10001, 88);
    assert(map.get(-1) == 99);
    assert(map.get(-10001) == 88);

    /** 
     * @test Test 5: Boundary Values 
     * Ensures the map can handle the mathematical edge case of zero.
     */
    map.put(0, 0);
    assert(map.get(0) == 0);

    /** 
     * @test Test 6: Removal Logic 
     * Validates that removing a node (especially from the head of a chain) correctly 
     * re-links subsequent nodes to prevent data loss.
     */
    map.remove(1);
    assert(map.get(1) == -1);
    assert(map.get(10001) == 50); // Ensure the rest of the chain is intact

    /** 
     * @test Test 7: Non-existent Key Removal 
     * Ensures removing a key that doesn't exist does not cause crashes or errors.
     */
    map.remove(999); 
    assert(map.get(999) == -1);

    /** 
     * @test Test 8: Large Scale Consistency 
     * Stress tests the map with 5000 entries to check for memory stability and retrieval accuracy.
     */
    for(int i = 0; i < 5000; ++i) {
        map.put(i, i * 2);
    }
    bool consistent = true;
    for(int i = 0; i < 5000; ++i) {
        if(map.get(i) != i * 2) consistent = false;
    }
    assert(consistent);

    std::cout << "All Test Cases Passed!" << std::endl;
    return 0;
}