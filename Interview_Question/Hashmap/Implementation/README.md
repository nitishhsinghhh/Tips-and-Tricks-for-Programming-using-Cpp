# Designing a HashMap without Built-in Libraries

In computer science, a Hash Map (or Hash Table) is an associative array that maps keys to values. While high-level languages provide built-in implementations, understanding the low-level mechanics—specifically memory management and collision handling—is essential for any systems engineer.

---

## 1. The Core Architecture: Separate Chaining

Our implementation uses Separate Chaining. When two different keys result in the same hash index (a collision), we don't overwrite the data. Instead, we store multiple elements in a linked list at that specific bucket.

### The Node Anatomy

The ListNode is the atom of our structure. Unlike a standard linked list node, it carries a "payload" of two integers.

#### Memory Safety

We explicitly disable copy constructors (= delete). This ensures that nodes aren't accidentally shallow-copied, which would lead to "double-free" memory corruption errors when the destructor is called.

---

## The Hash Function: The Entry Point

The hash function is the "brain" of the map. It transforms a large integer space into a small, manageable index.

```cpp
int hash(int key) {
    return static_cast<unsigned int>(key) % size;
}
```

- Logic: By casting to unsigned int, we gracefully handle negative keys. The modulo operator % ensures the index always falls within our [0, 9999] bucket range.

---

## 3. Operation Breakdown

### put(key, value) — Insert or Update

This method performs a "UPSERT" (Update or Insert) logic:

- Direct Access: Jump to data[hash(key)].

- The Search: Traverse the list. If the key already exists, we simply update the value. This maintains the "unique key" property of maps.

- Tail Attachment: If we reach the end of the list without finding the key, we append a new ListNode.

### get(key) — Retrieval

The efficiency of get() depends on the "load factor" (ratio of elements to buckets).

- In a well-distributed map, this is O(1).

- In the worst case (all keys hash to one bucket), it degrades to O(N).

- Return Convention: We return -1 to signify the absence of a key, a common pattern in C-style APIs.

### remove(key) — Memory Deallocation

Removing a node is the most complex operation because we must re-link the chain to prevent breaking the list.

- Head Case: If the first node in the bucket is the target, we update the bucket pointer to the second node.

- Middle/Tail Case: We look one step ahead (node->next). If the next node is the target, we "jump" over it: node->next = node->next->next.

- Crucial Step: We must call delete on the target node to return memory to the heap.

---

## 4. Resource Management (The Destructor)

In C++, manual memory management is a primary responsibility. Our destructor ensures that every node allocated via new is cleaned up when the HashMap object goes out of scope.

```cpp
~HashMap() {
    for (auto node : data) {
        while (node) {
            ListNode* temp = node;
            node = node->next;
            delete temp; // Prevent memory leaks
        }
    }
}
```

---

## 5. Performance Constraints & Trade-offs

| Feature | Complexity (Average) | Complexity (Worst) |
|---------|----------------------|--------------------|
| Space   | O(N+M)               | O(N+M)             |
| Search  | O(1)                 | O(N)               |
| Insert  | O(1)                 | O(N)               |

- Fixed Size: Using 10,000 buckets is a trade-off. It provides great performance for up to ~7,000 elements. Beyond that, the linked lists grow long, and performance drops.

- A production-grade map would implement Dynamic Resizing, where the number of buckets doubles once the map is 75% full.
