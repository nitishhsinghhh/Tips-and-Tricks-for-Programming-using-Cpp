# Containers library
The Containers library comprises class templates and algorithms that enable programmers to implement common data structures such as queues, lists, and stacks with ease. It consists of two classes of containers until C++11 and three classes since C++11, 
- sequence containers,
- associative containers, and
- unordered associative containers, (since C++11)

| Type                       | Container             | Description                                                       |
|----------------------------|-----------------------|-------------------------------------------------------------------|
| **Sequence Containers**        | array                 | Static contiguous array (C++11)                                    |
|                            | vector                | Dynamic contiguous array                                           |
|                            | deque                 | Double-ended queue                                                 |
|                            | forward_list          | Singly-linked list (C++11)                                         |
|                            | list                  | Doubly-linked list                                                 |
| **Associative Containers**     | set                   | Collection of unique keys, sorted by keys                         |
|                            | map                   | Collection of key-value pairs, sorted by keys, keys are unique     |
|                            | multiset              | Collection of keys, sorted by keys                                 |
|                            | multimap              | Collection of key-value pairs, sorted by keys                      |
| **Unordered Associative Containers** | unordered_set   | Collection of unique keys, hashed by keys (C++11)                  |
|                            | unordered_map         | Collection of key-value pairs, hashed by keys, keys are unique (C++11) |
|                            | unordered_multiset    | Collection of keys, hashed by keys (C++11)                         |
|                            | unordered_multimap    | Collection of key-value pairs, hashed by keys (C++11)              |
| **Container Adaptors**         | stack                 | Adapts a container to provide stack (LIFO data structure)          |
|                            | queue                 | Adapts a container to provide queue (FIFO data structure)          |
|                            | priority_queue        | Adapts a container to provide priority queue                       |
|                            | flat_set              | Adapts a container to provide a collection of unique keys, sorted by keys (C++23) |
|                            | flat_map              | Adapts two containers to provide a collection of key-value pairs, sorted by unique keys (C++23) |
|                            | flat_multiset         | Adapts a container to provide a collection of keys, sorted by keys (C++23) |
|                            | flat_multimap         | Adapts two containers to provide a collection of key-value pairs, sorted by keys (C++23) |
| **Views**                      | span                  | A non-owning view over a contiguous sequence of objects (C++20)    |
|                            | mdspan                | A multi-dimensional non-owning array view (C++23)                  |

# Iterator and Reference Invalidation in C++ Containers

## Read-Only Methods
Read-only methods, which do not modify the container's contents, never invalidate iterators or references.

## Modification Methods
Methods that modify the container's contents may invalidate iterators and references, depending on the specific container and the type of modification.

## Sequence Containers
### Array, Vector, Deque, List, and Forward List
- After insertion, iterators and references may be invalidated, with specific conditions for validity before or after the modification.
- After erasure, similar conditions apply for the validity of iterators and references.

## Associative Containers
### Set, Multiset, Map, and Multimap
- After insertion or erasure, iterators and references are typically still valid, except for erased elements.

## Unordered Associative Containers
### Unordered Set, Unordered Multiset, Unordered Map, and Unordered Multimap
- After insertion, iterators may be invalidated, especially if the insertion causes a rehash of the container. References, however, remain valid.
- After erasure, iterators and references are usually still valid, except for erased elements.

## Additional Information
- Insertion refers to any method that adds elements to the container, while erasure refers to any method that removes elements from the container.
- It provides examples of insertion and erasure methods for different containers.
- An exception is noted for erasure of the last element in a deque, which invalidates the past-the-end iterator.
