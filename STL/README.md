# C++ Standard Template Library
The C++ STL (Standard Template Library) is a generic collection of class templates and
algorithms that allow programmers to easily implement standard data structures like
queues, lists, and stacks.

## Containers library
The Containers library is a generic collection of class templates and algorithms that allow programmers to easily implement common data structures like queues, lists and stacks. There are two(until C++11) three (since C++11) classes of containers:
- sequence containers,
- associative containers, and
- unordered associative containers, (since C++11)

each of which is designed to support a different set of operations.

The container manages the storage space that is allocated for its elements and provides member functions to access them, either directly or through iterators (objects with properties similar to pointers).

Most containers have at least several member functions in common, and share functionalities. Which container is the best for the particular application depends not only on the offered functionality, but also on its efficiency for different workloads.

### Sequence containers
Sequence containers implement data structures which can be accessed sequentially.

| Sequence Container      | Description              |  
|-------------------------|--------------------------|  
| array (C++11)           | Static contiguous array  |  
| vector                 | Dynamic contiguous array |  
| deque                  | Double-ended queue       |  
| forward_list (C++11)   | Singly-linked list       |  
| list                   | Doubly-linked list       |  

### Associative containers
Associative containers implement sorted data structures that can be quickly searched (O(log n) complexity).
| Associative Container   | Description                                         |  
|-------------------------|-----------------------------------------------------|  
| set                     | Collection of unique keys, sorted by keys          |  
| map                     | Collection of key-value pairs, sorted by keys       |  
| multiset                | Collection of keys, sorted by keys                  |  
| multimap                | Collection of key-value pairs, sorted by keys       |  

### Unordered associative containers (since C++11)
Unordered associative containers implement unsorted (hashed) data structures that can be quickly searched (O(1) average, O(n) worst-case complexity).
| Unordered Associative Container | Description                                       |  
|---------------------------------|---------------------------------------------------|  
| unordered_set (C++11)           | Collection of unique keys, hashed by keys         |  
| unordered_map (C++11)           | Collection of key-value pairs, hashed by keys     |  
| unordered_multiset (C++11)      | Collection of keys, hashed by keys                |  
| unordered_multimap (C++11)      | Collection of key-value pairs, hashed by keys     |  

### Container adaptors
Container adaptors provide a different interface for sequential containers.
| Container Adaptor  | Description                                                 |  
|--------------------|-------------------------------------------------------------|  
| stack              | Adapts a container to provide a stack (LIFO data structure) |  
| queue              | Adapts a container to provide a queue (FIFO data structure) |  
| priority_queue     | Adapts a container to provide a priority queue             |  
| flat_set (C++23)   | Adapts a container to provide a collection of unique keys, sorted by keys |  
| flat_map (C++23)   | Adapts two containers to provide a collection of key-value pairs, sorted by unique keys |  
| flat_multiset (C++23) | Adapts a container to provide a collection of keys, sorted by keys |  
| flat_multimap (C++23) | Adapts two containers to provide a collection of key-value pairs, sorted by keys |  

### Views
Views provide flexible facilities for interacting with one- or multi-dimensional views over a non-owning array of elements.
| View    | Description                                                        |  
|---------|--------------------------------------------------------------------|  
| span    | A non-owning view over a contiguous sequence of objects (C++20)     |  
| mdspan  | A multi-dimensional non-owning array view (C++23)                   |  



