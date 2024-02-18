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

# Iterator invalidation
Read-only methods never invalidate iterators or references. Methods which modify the contents of a container may invalidate iterators and/or references, as summarized in this table.

| Category                     | Container                  | After insertion, are... | After erasure, are... | Conditionally |
|------------------------------|----------------------------|--------------------------|------------------------|---------------|
| Sequence containers          | array                      | N/A                      | N/A                    |               |
|                              | vector                     | No                       | N/A                    | Insertion changed capacity |
|                              |                            | Yes                      | Yes                    | Before modified element(s) (for insertion only if capacity didn't change) |
|                              |                            | No                       | No                     | At or after modified element(s) |
|                              | deque                      | No                       | Yes                    | Modified first or last element |
|                              |                            | Yes                      | Yes, except erased element(s) | Modified middle only |
|                              | list                       | Yes                      | Yes, except erased element(s) |               |
|                              | forward_list               | Yes                      | Yes, except erased element(s) |               |
| Associative containers       | set                        | Yes                      | Yes, except erased element(s) |               |
|                              | multiset                   | Yes                      | Yes, except erased element(s) |               |
|                              | map                        | Yes                      | Yes, except erased element(s) |               |
|                              | multimap                   | Yes                      | Yes, except erased element(s) |               |
| Unordered associative containers | unordered_set            | No                       | Yes                    | N/A           |
|                              | unordered_multiset          | No                       | Yes                    | N/A           |
|                              | unordered_map               | No                       | Yes                      | Insertion caused rehash |
|                              | unordered_multimap          | No                       | Yes                      | Insertion caused rehash |
|                              |                            | Yes                      | Yes, except erased element(s) | No rehash |
