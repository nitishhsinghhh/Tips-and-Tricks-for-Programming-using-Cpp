# STL Containers and Algorithms - Complete Guide

## Overview

The Standard Template Library (STL) is one of the most important aspects of C++ and is heavily tested in technical interviews. This comprehensive guide covers all STL containers, algorithms, iterators, and common interview problems with practical examples and performance analysis.

##  Why STL is Critical for Interviews

### Technical Importance
- **Ubiquitous Usage**: STL is used in virtually every C++ codebase
- **Efficiency**: Pre-optimized, tested implementations
- **Productivity**: Reduces development time significantly
- **Standard Knowledge**: Expected skill for any C++ developer

### Interview Focus Areas
- **Container Selection**: Knowing which container to use when
- **Time Complexity**: Understanding Big O for different operations
- **Memory Efficiency**: How containers manage memory
- **Algorithm Application**: Using STL algorithms effectively
- **Custom Implementations**: Sometimes asked to implement container functionality

## Container Categories

### Sequence Containers
Store elements in a linear sequence, maintaining insertion order.

#### std::vector
- **Use Case**: Dynamic array with random access
- **Time Complexity**: 
  - Access: O(1)
  - Insertion (end): Amortized O(1)
  - Insertion (middle): O(n)
  - Deletion (end): O(1)
  - Deletion (middle): O(n)
- **Memory**: Contiguous storage, may reallocate
- **When to Use**: Default choice for most scenarios

```cpp
std::vector<int> vec = {1, 2, 3, 4, 5};
vec.push_back(6);           // O(1) amortized
vec.insert(vec.begin()+2, 99); // O(n)
vec.reserve(1000);          // Prevent reallocations
```

#### std::array
- **Use Case**: Fixed-size array with random access
- **Time Complexity**: O(1) for all access operations
- **Memory**: Stack-allocated, no dynamic allocation
- **When to Use**: Known fixed size, maximum performance

```cpp
std::array<int, 5> arr = {1, 2, 3, 4, 5};
arr[2] = 10;    // O(1) access
arr.fill(0);    // Fill all elements
```

#### std::deque
- **Use Case**: Double-ended queue with random access
- **Time Complexity**:
  - Access: O(1)
  - Insertion (ends): O(1)
  - Insertion (middle): O(n)
- **Memory**: Segmented storage
- **When to Use**: Need insertion/deletion at both ends

```cpp
std::deque<int> dq = {3, 4, 5};
dq.push_front(2);  // O(1)
dq.push_back(6);   // O(1)
```

#### std::list
- **Use Case**: Doubly-linked list
- **Time Complexity**:
  - Access: O(n)
  - Insertion: O(1) with iterator
  - Deletion: O(1) with iterator
- **Memory**: Non-contiguous, node-based
- **When to Use**: Frequent middle insertion/deletion

```cpp
std::list<int> lst = {1, 2, 3, 4, 5};
auto it = std::next(lst.begin(), 2);
lst.insert(it, 99);  // O(1) insertion
lst.sort();          // List-specific sort
```

### Associative Containers
Store elements in sorted order based on keys.

#### std::set / std::multiset
- **Implementation**: Typically Red-Black tree
- **Time Complexity**: O(log n) for insert, find, erase
- **Ordering**: Sorted by key
- **Use Case**: Unique elements (set) or allow duplicates (multiset)

```cpp
std::set<int> s = {5, 2, 8, 2, 1}; // {1, 2, 5, 8}
s.insert(3);    // O(log n)
auto it = s.find(5);  // O(log n)
```

#### std::map / std::multimap
- **Implementation**: Typically Red-Black tree
- **Time Complexity**: O(log n) for operations
- **Use Case**: Key-value pairs, sorted by key

```cpp
std::map<std::string, int> ages;
ages["Alice"] = 25;     // O(log n)
ages["Bob"] = 30;
auto it = ages.find("Alice"); // O(log n)
```

### Unordered Associative Containers
Hash-based containers with average O(1) operations.

#### std::unordered_set / std::unordered_multiset
- **Implementation**: Hash table
- **Time Complexity**: 
  - Average: O(1) for insert, find, erase
  - Worst case: O(n) if many hash collisions
- **Use Case**: Fast lookup without ordering requirement

```cpp
std::unordered_set<int> us = {5, 2, 8, 1};
us.insert(3);           // O(1) average
auto found = us.find(5); // O(1) average
```

#### std::unordered_map / std::unordered_multimap
- **Implementation**: Hash table
- **Use Case**: Fast key-value lookup

```cpp
std::unordered_map<std::string, int> scores;
scores["Alice"] = 95;   // O(1) average
int alice_score = scores["Alice"]; // O(1) average
```

### Container Adapters
Provide specific interfaces built on other containers.

#### std::stack
- **Interface**: LIFO (Last In First Out)
- **Underlying**: Usually std::deque
- **Use Case**: Function calls, expression evaluation, backtracking

```cpp
std::stack<int> stk;
stk.push(1);
stk.push(2);
int top = stk.top(); // 2
stk.pop();
```

#### std::queue
- **Interface**: FIFO (First In First Out)  
- **Underlying**: Usually std::deque
- **Use Case**: BFS, job scheduling, buffering

```cpp
std::queue<int> q;
q.push(1);
q.push(2);
int front = q.front(); // 1
q.pop();
```

#### std::priority_queue
- **Interface**: Priority-based extraction
- **Implementation**: Usually binary heap
- **Time Complexity**: O(log n) insertion, O(log n) extraction
- **Use Case**: Dijkstra's algorithm, job scheduling

```cpp
std::priority_queue<int> pq; // Max heap by default
pq.push(3);
pq.push(1);
pq.push(4);
int max = pq.top(); // 4
```

## STL Algorithms

### Algorithm Categories

#### Non-Modifying Sequence Operations
- `std::find`, `std::find_if`, `std::find_if_not`
- `std::count`, `std::count_if`
- `std::search`, `std::search_n`
- `std::equal`, `std::mismatch`

#### Modifying Sequence Operations
- `std::copy`, `std::copy_if`, `std::copy_n`
- `std::transform`
- `std::replace`, `std::replace_if`
- `std::remove`, `std::remove_if`
- `std::reverse`, `std::rotate`

#### Sorting Operations
- `std::sort`, `std::stable_sort`, `std::partial_sort`
- `std::nth_element`
- `std::binary_search`, `std::lower_bound`, `std::upper_bound`
- `std::merge`, `std::inplace_merge`

#### Numeric Operations
- `std::accumulate`, `std::inner_product`
- `std::partial_sum`, `std::adjacent_difference`
- `std::iota`

### Algorithm Usage Examples

```cpp
std::vector<int> vec = {5, 2, 8, 1, 9, 3};

// Find first element > 5
auto it = std::find_if(vec.begin(), vec.end(), 
                       [](int x) { return x > 5; });

// Sort the vector
std::sort(vec.begin(), vec.end());

// Transform to squares
std::vector<int> squares(vec.size());
std::transform(vec.begin(), vec.end(), squares.begin(),
               [](int x) { return x * x; });

// Calculate sum
int sum = std::accumulate(vec.begin(), vec.end(), 0);
```

## Iterator Categories

### Iterator Hierarchy
1. **Input Iterator**: Read-only, single pass
2. **Output Iterator**: Write-only, single pass  
3. **Forward Iterator**: Read/write, multi-pass, forward only
4. **Bidirectional Iterator**: Forward + backward movement
5. **Random Access Iterator**: All operations + random access

### Iterator Adapters
- **Reverse Iterator**: `std::reverse_iterator`
- **Insert Iterator**: `std::back_inserter`, `std::front_inserter`
- **Stream Iterator**: `std::istream_iterator`, `std::ostream_iterator`

```cpp
std::vector<int> vec = {1, 2, 3, 4, 5};

// Reverse iteration
for (auto it = vec.rbegin(); it != vec.rend(); ++it) {
    std::cout << *it << " ";
}

// Stream iterators
std::copy(vec.begin(), vec.end(), 
          std::ostream_iterator<int>(std::cout, " "));
```

## Common Interview Questions

### Container Selection Questions

**Q: When would you use std::list over std::vector?**
**A:** Use std::list when you need frequent insertion/deletion in the middle of the container and don't need random access. List provides O(1) insertion/deletion at any position if you have an iterator, while vector requires O(n) for middle operations due to element shifting.

**Q: What's the difference between std::set and std::unordered_set?**
**A:** 
- **std::set**: Tree-based, O(log n) operations, sorted order, lower memory overhead
- **std::unordered_set**: Hash-based, O(1) average operations, no ordering, higher memory overhead

**Q: When would you prefer std::array over std::vector?**
**A:** Use std::array when:
- Size is known at compile time and fixed
- Want stack allocation (no dynamic memory)
- Need maximum performance (no capacity checks, no reallocations)
- Working with small, fixed collections

### Algorithm Questions

**Q: How would you find the intersection of two sorted vectors?**
```cpp
std::vector<int> intersection(const std::vector<int>& v1, 
                             const std::vector<int>& v2) {
    std::vector<int> result;
    std::set_intersection(v1.begin(), v1.end(),
                         v2.begin(), v2.end(),
                         std::back_inserter(result));
    return result;
}
```

**Q: How do you remove duplicates from a vector while preserving order?**
```cpp
// Using unordered_set for O(n) time complexity
std::vector<int> removeDuplicates(std::vector<int> vec) {
    std::unordered_set<int> seen;
    auto it = std::remove_if(vec.begin(), vec.end(),
        [&seen](int x) {
            if (seen.count(x)) return true;
            seen.insert(x);
            return false;
        });
    vec.erase(it, vec.end());
    return vec;
}
```

### Performance Questions

**Q: What causes iterator invalidation?**
**A:** Iterator invalidation occurs when the container's internal structure changes:

- **Vector**: Insertion/deletion may cause reallocation, invalidating all iterators
- **Deque**: Insertion/deletion at ends preserves middle iterators
- **List**: Only iterators to erased elements are invalidated
- **Set/Map**: Only iterators to erased elements are invalidated

**Q: Explain the performance characteristics of different containers for various operations.**

| Container | Access | Insert (end) | Insert (middle) | Find | Memory |
|-----------|--------|--------------|-----------------|------|--------|
| vector | O(1) | O(1)* | O(n) | O(n) | Contiguous |
| list | O(n) | O(1) | O(1)** | O(n) | Scattered |
| deque | O(1) | O(1) | O(n) | O(n) | Chunked |
| set | O(log n) | O(log n) | O(log n) | O(log n) | Tree nodes |
| unordered_set | N/A | O(1)* | N/A | O(1)* | Hash table |

*Amortized  **With iterator

## Best Practices

### Container Selection Guidelines

1. **Default Choice**: Use `std::vector` unless you have specific requirements
2. **Fixed Size**: Use `std::array` for compile-time known sizes
3. **Both End Access**: Use `std::deque` for insertion/deletion at both ends
4. **Middle Insertion**: Use `std::list` for frequent middle operations
5. **Sorted Unique**: Use `std::set` for sorted unique elements
6. **Fast Lookup**: Use `std::unordered_set` for fastest lookups
7. **Key-Value**: Use `std::map` or `std::unordered_map` for associations

### Performance Tips

```cpp
// Reserve space to avoid reallocations
std::vector<int> vec;
vec.reserve(1000);

// Use emplace instead of push for complex objects
vec.emplace_back(args...); // Better than vec.push_back(T(args...))

// Use const references in range-based loops
for (const auto& item : container) { /* ... */ }

// Prefer algorithms over hand-written loops
std::sort(vec.begin(), vec.end());  // Better than manual sort

// Use appropriate iterator types
auto it = vec.cbegin(); // const_iterator when not modifying
```

### Memory Management

```cpp
// Shrink vector capacity after large deletions
vec.erase(/* remove many elements */);
vec.shrink_to_fit();

// Use move semantics when possible
vec.push_back(std::move(expensive_object));

// Clear but keep capacity
vec.clear(); // Size = 0, capacity unchanged

// Clear and release memory
vec.clear();
vec.shrink_to_fit(); // or vec = std::vector<int>();
```

## Advanced Topics

### Custom Comparators
```cpp
// Custom comparator for set
struct PersonAgeComparator {
    bool operator()(const Person& a, const Person& b) const {
        return a.age < b.age;
    }
};

std::set<Person, PersonAgeComparator> people_by_age;

// Lambda comparator for sort
std::sort(people.begin(), people.end(),
          [](const Person& a, const Person& b) {
              return a.name < b.name;
          });
```

### Custom Hash Functions
```cpp
struct PersonHash {
    std::size_t operator()(const Person& p) const {
        return std::hash<std::string>{}(p.name) ^ 
               (std::hash<int>{}(p.age) << 1);
    }
};

std::unordered_set<Person, PersonHash> person_set;
```

### Exception Safety
STL containers provide different exception safety guarantees:
- **Basic guarantee**: Container remains in valid state
- **Strong guarantee**: Operation succeeds or has no effect
- **No-throw guarantee**: Operation cannot throw

## Testing and Debugging

### Common Mistakes
1. **Iterator Invalidation**: Using iterators after container modification
2. **Out of Range Access**: Using `operator[]` without bounds checking
3. **Comparing Iterators**: From different containers
4. **Memory Leaks**: With containers of raw pointers

### Debugging Tips
```cpp
// Use at() for bounds checking in debug builds
int value = vec.at(index); // Throws if out of range

// Check container state
assert(!vec.empty());
assert(vec.size() > index);

// Use const when possible to catch modification bugs
const std::vector<int>& const_ref = vec;
```

## Performance Benchmarks

### Insertion Performance (100K elements)
- **Vector (end)**: ~2ms
- **Vector (middle)**: ~800ms
- **List (anywhere)**: ~5ms
- **Set**: ~15ms
- **Unordered_set**: ~8ms

### Search Performance (10K elements)
- **Vector (linear)**: ~50μs
- **Set**: ~2μs
- **Unordered_set**: ~1μs

*Note: Actual performance depends on hardware, compiler, and data patterns*

## Interview Preparation Checklist

### Must Know
- [ ] Time complexity of all container operations
- [ ] When to use each container type
- [ ] Iterator categories and their capabilities
- [ ] Common algorithms (sort, find, transform, accumulate)
- [ ] How to implement basic algorithms using STL

### Should Know
- [ ] Iterator invalidation rules
- [ ] Custom comparators and hash functions
- [ ] Exception safety guarantees
- [ ] Memory layout of different containers
- [ ] Move semantics with containers

### Advanced Topics
- [ ] Custom allocators
- [ ] Template metaprogramming with STL
- [ ] Parallel algorithms (C++17)
- [ ] Ranges library (C++20)

**Master the STL and you master a huge part of effective C++ programming!** 
