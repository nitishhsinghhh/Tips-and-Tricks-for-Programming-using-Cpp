#include "../include/STL_Containers.h"        // Relative path	
#include <algorithm>
#include <numeric>
#include <iterator>
#include <chrono>
#include <random>

using std::cout;
using std::endl;

// Container types
using std::vector;
using std::array;
using std::deque;
using std::list;
using std::forward_list;
using std::stack;
using std::queue;
using std::priority_queue;
using std::set;
using std::multiset;
using std::map;
using std::multimap;
using std::unordered_set;
using std::unordered_map;
using std::string;
using std::pair;

// Algorithm functions
using std::find;
using std::find_if;
using std::count;
using std::count_if;
using std::binary_search;
using std::lower_bound;
using std::upper_bound;
using std::copy;
using std::copy_if;
using std::transform;
using std::replace;
using std::remove;
using std::reverse;
using std::rotate;
using std::shuffle;
using std::partition;
using std::sort;
using std::stable_sort;
using std::advance;
using std::back_inserter;
using std::merge;
using std::make_heap;
using std::push_heap;
using std::pop_heap;
using std::min_element;
using std::max_element;
using std::minmax_element;
using std::accumulate;
using std::partial_sum;
using std::iota;
using std::set_union;
using std::set_intersection;
using std::distance;
using std::ostream_iterator;

// Function objects and other utilities
using std::greater;
using std::negate;
using std::multiplies;
using std::random_device;
using std::mt19937;

namespace CppBasics {

// =============================================================================
// STL CONTAINERS DEMONSTRATIONS
// =============================================================================

void STLContainersDemo::demonstrateVector() {
    cout << "\n=== std::vector Demonstration ===\n";
    
    vector<int> vec = {1, 2, 3, 4, 5}; // Initialize with values - most common container
    printContainer(vec, "Initial vector");
    cout << "Size: " << vec.size() << ", Capacity: " << vec.capacity() << "\n"; // Size = elements, Capacity = allocated space
    
    vec.push_back(6); // Add element to end - O(1) amortized (sometimes O(n) when reallocation needed)
    vec.push_back(7);
    printContainer(vec, "After push_back(6,7)");
    cout << "Size: " << vec.size() << ", Capacity: " << vec.capacity() << "\n"; // Notice capacity may grow exponentially
    
    vec.reserve(20); // Pre-allocate capacity to avoid future reallocations - O(n) one-time cost
    cout << "After reserve(20) - Capacity: " << vec.capacity() << "\n"; // Capacity now >= 20
    
    if (vec.size() > 2) { // Safety check before insert
        vec.insert(vec.begin() + 2, 99); // Insert at specific position - O(n) due to shifting elements
        printContainer(vec, "After insert(begin+2, 99)");
    }
    
    if (vec.size() > 2) { // Safety check before erase
        vec.erase(vec.begin() + 2); // Remove element at position - O(n) due to shifting elements left
        printContainer(vec, "After erase(begin+2)");
    }
    
    if (!vec.empty()) { // Safety check before accessing front/back
        cout << "Front: " << vec.front() << ", Back: " << vec.back() << "\n"; // Access first/last - O(1), no bounds checking
    }
    
    if (vec.size() > 2) { // Safety check before accessing index 2
        cout << "At index 2: " << vec.at(2) << ", operator[2]: " << vec[2] << "\n"; // at() throws exception if out of bounds, [] doesn't
    }
    
    vec.shrink_to_fit(); // Release unused capacity - O(n) but saves memory
    cout << "After shrink_to_fit() - Capacity: " << vec.capacity() << "\n"; // Capacity now matches size
}

void STLContainersDemo::demonstrateArray() {
    cout << "\n=== std::array Demonstration ===\n";
    
    array<int, 5> arr = {10, 20, 30, 40, 50}; // Fixed-size array, size known at compile-time - stack allocated
    printContainer(arr, "Array");
    cout << "Size: " << arr.size() << ", Max size: " << arr.max_size() << "\n"; // Size is always fixed
    
    if (!arr.empty()) { // Safety check (though array is never empty if size > 0)
        cout << "Front: " << arr.front() << ", Back: " << arr.back() << "\n"; // Safe access to first/last - O(1)
    }
    
    if (arr.size() > 2) { // Safety check before accessing index 2
        cout << "At index 2: " << arr.at(2) << "\n"; // Bounds-checked access - throws if invalid
    }
    
    array<int, 5> arr2; // Uninitialized array - contains garbage values
    printContainer(arr2, "Before fill(42) - uninitialized"); // Shows garbage values - educational!
    arr2.fill(42); // Fill all elements with same value - O(n)
    printContainer(arr2, "After fill(42)");
    
    arr.swap(arr2); // Efficient swap - O(n) but no memory allocation
    printContainer(arr, "After swap");
}

void STLContainersDemo::demonstrateDeque() {
    cout << "\n=== std::deque Demonstration ===\n";
    
    deque<int> dq = {3, 4, 5}; // Double-ended queue - efficient front/back operations
    printContainer(dq, "Initial deque");
    
    // Note: std::deque doesn't expose capacity() or shrink_to_fit() like vector
    // Deque uses a different internal structure (typically segmented arrays)
    cout << "Size: " << dq.size() << " (no capacity concept for deque)\n";
    
    dq.push_front(2); // Add to front - O(1), unlike vector which doesn't have this
    dq.push_front(1);
    dq.push_back(6); // Add to back - O(1), same as vector
    dq.push_back(7);
    printContainer(dq, "After push operations");
    
    if (!dq.empty()) { // Safety check before pop operations
        dq.pop_front(); // Remove from front - O(1), unique advantage over vector
    }
    if (!dq.empty()) {
        dq.pop_back(); // Remove from back - O(1)
    }
    printContainer(dq, "After pop operations");
    
    if (dq.size() > 2) { // Safety check before accessing index 2
        cout << "Element at index 2: " << dq[2] << "\n"; // Random access - O(1), slightly slower than vector
    }
    
    if (dq.size() > 1) { // Safety check before insert
        dq.insert(dq.begin() + 1, 99); // Insert in middle - O(n), but potentially faster than vector
        printContainer(dq, "After insert");
    }
}

void STLContainersDemo::demonstrateList() {
    cout << "\n=== std::list Demonstration ===\n";
    
    list<int> lst = {5, 2, 8, 1, 9}; // Doubly-linked list - efficient insertion/deletion anywhere
    printContainer(lst, "Initial list");
    
    lst.sort(); // Efficient merge sort for lists - O(n log n), doesn't invalidate iterators
    printContainer(lst, "After sort()");
    
    lst.reverse(); // Reverse order by relinking nodes - O(n), just pointer manipulation
    printContainer(lst, "After reverse()");
    
    list<int> other = {100, 200};
    if (lst.size() >= 2) { // Safety check before advance
        auto splice_pos = lst.begin();
        advance(splice_pos, 2); // Move iterator 2 positions - O(n) for list iterators
        lst.splice(splice_pos, other); // Move elements from other list - O(1), just relink pointers!
        printContainer(lst, "After splice");
    }
    
    lst.remove(100); // Removes ALL elements equal to 100 (not just first occurrence) - O(n)
    printContainer(lst, "After remove all 100s");
    
    lst.push_back(9); // Add to end - O(1), maintains pointer to tail
    lst.push_back(8);
    printContainer(lst, "After adding duplicates");
    
    lst.unique(); // Removes consecutive duplicate elements - O(n), only adjacent duplicates
    printContainer(lst, "After unique() - removes consecutive duplicates");
}

void STLContainersDemo::demonstrateForwardList() {
    cout << "\n=== std::forward_list Demonstration ===\n";
    
    forward_list<int> fl = {1, 2, 3, 4, 5}; // Singly-linked list - memory efficient, forward-only
    cout << "Initial forward_list: ";
    for (const auto& elem : fl) cout << elem << " "; // Can only iterate forward
    cout << "\n";
    
    fl.insert_after(fl.begin(), 99); // Insert after given position - O(1), no insert_before
    cout << "After insert_after(begin(), 99): ";
    for (const auto& elem : fl) cout << elem << " ";
    cout << "\n";
    
    fl.erase_after(fl.before_begin()); // Erase element after given position - O(1)
    cout << "After erase_after(before_begin()): "; // before_begin() points before first element
    for (const auto& elem : fl) cout << elem << " ";
    cout << "\n";
    
    fl.sort(); // Merge sort - O(n log n), optimized for forward iteration
    cout << "After sort(): ";
    for (const auto& elem : fl) cout << elem << " ";
    cout << "\n";
}

// Helper function to check balanced parentheses - reusable and testable
bool isBalanced(const string& expr) {
    stack<char> stk;
    for (char c : expr) {
        if (c == '(') {
            stk.push(c);
        } else if (c == ')') {
            if (stk.empty()) return false; // No matching opening bracket
            stk.pop();
        }
    }
    return stk.empty(); // Must have no unmatched opening brackets
}

void STLContainersDemo::demonstrateStack() {
    cout << "\n=== std::stack Demonstration ===\n";
    
    stack<int> stk; // LIFO container adapter - Last In, First Out
    for (int i = 1; i <= 5; ++i) {
        stk.push(i * 10); // Add to top - O(1)
    }
    
    cout << "Stack size: " << stk.size() << "\n"; // Number of elements
    
    // Show stack contents visually (top to bottom) using temporary copy
    // Note: std::stack is an adapter; direct iteration is not supported
    // Cannot use: for (auto x : stk) - this would cause compilation error!
    cout << "Initial stack (top to bottom): ";
    stack<int> temp = stk; // Copy constructor - doesn't affect original
    while (!temp.empty()) {
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << "\n";
    
    cout << "Popping elements (LIFO order): ";
    while (!stk.empty()) { // Always check empty() before accessing - CRITICAL for stack safety
        cout << stk.top() << " "; // Access top element - O(1), doesn't remove
        stk.pop(); // Remove top element - O(1), doesn't return value
    }
    cout << "\n";
    
    // Practical example: balanced parentheses using reusable function
    string expr1 = "((()))"; // Well-balanced expression
    string expr2 = "((())"; // Unbalanced expression
    
    cout << "Expression \"" << expr1 << "\" is " << (isBalanced(expr1) ? "balanced" : "not balanced") << "\n";
    cout << "Expression \"" << expr2 << "\" is " << (isBalanced(expr2) ? "balanced" : "not balanced") << "\n";
}

void STLContainersDemo::demonstrateQueue() {
    cout << "\n=== std::queue Demonstration ===\n";
    
    queue<string> q; // FIFO container adapter - First In, First Out
    q.push("First"); // Add to back/rear - O(1)
    q.push("Second");
    q.push("Third");
    
    cout << "Queue size: " << q.size() << "\n"; // Number of elements waiting
    if (!q.empty()) { // Safety check before accessing front/back
        cout << "Front: " << q.front() << ", Back: " << q.back() << "\n"; // Access both ends
    }
    
    // Show queue contents visually (front to back) using temporary copy
    // Note: std::queue is an adapter; direct iteration is not supported
    // Cannot use: for (auto x : q) - this would cause compilation error!
    queue<string> temp = q; // Copy constructor - doesn't affect original
    cout << "Current queue (front to back): ";
    while (!temp.empty()) {
        cout << temp.front() << " "; // Shows FIFO order: First, Second, Third
        temp.pop();
    }
    cout << "\n";
    
    cout << "Dequeuing (FIFO order): ";
    while (!q.empty()) { // ESSENTIAL check - process elements in FIFO order safely
        cout << q.front() << " "; // Access front element - O(1)
        q.pop(); // Remove front element - O(1)
    }
    cout << "\n";
}

void STLContainersDemo::demonstratePriorityQueue() {
    cout << "\n=== std::priority_queue Demonstration ===\n";
    
    priority_queue<int> max_pq; // Max-heap by default - largest element has highest priority
    // Real-world analogy: scheduling tasks where higher priority executes first
    // Example: OS task scheduler, emergency room triage, network packet routing
    vector<int> nums = {3, 1, 4, 1, 5, 9, 2, 6};
    for (int n : nums) max_pq.push(n); // Insert with automatic sorting - O(log n)
    
    // Note: std::priority_queue is an adapter; direct iteration is not supported
    // Cannot iterate through std::priority_queue directly; must pop to access elements
    // Cannot use: for (auto x : max_pq) - this would cause compilation error!
    
    cout << "Max-heap (default): ";
    while (!max_pq.empty()) { // Safety check before accessing top
        cout << max_pq.top() << " "; // Always returns largest element - O(1)
        max_pq.pop(); // Remove largest - O(log n)
    }
    cout << "\n";
    
    // By default, priority_queue is a max-heap (largest element has highest priority)
    // To make it a min-heap, use std::greater<T> as the comparator
    // Template: priority_queue<Type, Container, Comparator>
    priority_queue<int, vector<int>, greater<int>> min_pq; // Min-heap - smallest has highest priority
    for (int n : nums) min_pq.push(n);
    
    cout << "Min-heap: ";
    while (!min_pq.empty()) { // Safety check before accessing top
        cout << min_pq.top() << " "; // Always returns smallest element
        min_pq.pop();
    }
    cout << "\n";
}

void STLContainersDemo::demonstrateSet() {
    cout << "\n=== std::set Demonstration ===\n";
    
    // Note: std::set stores elements in sorted (ascending) order by default
    // Uses std::less<T> comparator internally
    set<int> s = {5, 2, 8, 1, 9, 2}; // Duplicates will be ignored - Red-Black Tree (balanced BST)
    printContainer(s, "Set (sorted, unique)"); // Always sorted and unique
    
    auto result = s.insert(7); // Returns pair<iterator, bool> - iterator to element, bool if inserted
    cout << "Insert 7: " << (result.second ? "success" : "failed") << "\n";
    
    result = s.insert(5); // Duplicate - won't be inserted
    cout << "Insert 5 (duplicate): " << (result.second ? "success" : "failed") << "\n";
    
    auto it = s.find(8); // Find element - O(log n), much faster than linear search
    if (it != s.end()) { // ESSENTIAL check - always validate find() results
        cout << "Found: " << *it << "\n";
    } else {
        cout << "Element 8 not found\n";
    }
    
    auto lower = s.lower_bound(5); // First element >= 5 - O(log n)
    auto upper = s.upper_bound(7); // First element > 7 - O(log n)
    cout << "Elements in range [5, 7]: ";
    for (auto iter = lower; iter != upper; ++iter) { // Efficient range iteration
        cout << *iter << " ";
    }
    cout << "\n";
    
    cout << "Count of 5: " << s.count(5) << "\n"; // 0 or 1 for set (always unique)
    
    size_t erased = s.erase(5); // Remove element - O(log n), returns number of elements removed
    cout << "Erased " << erased << " occurrence(s) of 5\n";
    printContainer(s, "After erase(5)");
    
    // Custom ordering: descending order using std::greater<T>
    // Template: set<Type, Comparator>
    set<int, greater<int>> descending_set = {5, 2, 8, 1, 9};
    printContainer(descending_set, "Descending set (custom comparator)");
}

void STLContainersDemo::demonstrateMultiset() {
    cout << "\n=== std::multiset Demonstration ===\n";
    
    multiset<int> ms = {5, 2, 8, 1, 9, 2, 5}; // Allows duplicates - still sorted
    printContainer(ms, "Multiset (sorted, duplicates allowed)");
    
    cout << "Count of 5: " << ms.count(5) << "\n"; // Can be > 1, counts all occurrences
    cout << "Count of 2: " << ms.count(2) << "\n";
    
    auto range = ms.equal_range(5); // Returns pair of iterators [first, last) for value
    cout << "All occurrences of 5: ";
    for (auto it = range.first; it != range.second; ++it) {
        cout << *it << " ";
    }
    cout << "\n";
    
    auto pos = ms.find(5); // find() returns iterator to first occurrence
    if (pos != ms.end()) {
        ms.erase(pos); // Erase single occurrence at iterator position
    }
    printContainer(ms, "After erasing one occurrence of 5");
    
    // Demonstrate the difference: erase by value removes ALL occurrences
    size_t erased_count = ms.erase(2); // Erase all occurrences of 2
    cout << "Erased " << erased_count << " occurrence(s) of 2\n";
    printContainer(ms, "After erasing all occurrences of 2");
    
    cout << "\nErase methods comparison:\n";
    cout << "  erase(iterator) → removes ONE element at that position\n";
    cout << "  erase(value) → removes ALL elements with that value\n";
}

void STLContainersDemo::demonstrateMap() {
    cout << "\n=== std::map Demonstration ===\n";
    
    map<string, int> fruit_count; // Key-value pairs, sorted by key - Red-Black Tree
    fruit_count["apple"] = 5; // [] operator inserts if key doesn't exist, updates if it does
    fruit_count["banana"] = 3;
    fruit_count["orange"] = 8;
    
    cout << "Initial map:\n";
    for (const auto& pair : fruit_count) { // Iterates in sorted key order - O(n)
        cout << "  " << pair.first << ": " << pair.second << "\n"; // pair.first = key, pair.second = value
    }
    
    cout << "Apple count: " << fruit_count["apple"] << "\n"; // Access existing value - O(log n)
    cout << "Kiwi count: " << fruit_count["kiwi"] << "\n"; // Creates entry with default value (0) if key doesn't exist!
    
    auto it = fruit_count.find("banana"); // Safe lookup - O(log n), doesn't create if missing
    if (it != fruit_count.end()) {
        cout << "Found banana: " << it->second << "\n"; // Access value through iterator
    }
    
    fruit_count.insert({"grape", 12}); // Insert pair - won't overwrite existing, returns pair<iterator, bool>
    fruit_count["banana"] = 5; // Update existing value
    fruit_count.emplace("mango", 7); // Construct in-place - more efficient, avoids temporary objects
    
    cout << "Final map:\n";
    for (const auto& pair : fruit_count) {
        cout << "  " << pair.first << ": " << pair.second << "\n";
    }
    
    fruit_count.erase("kiwi"); // Remove by key - O(log n), does nothing if key doesn't exist
    cout << "After erasing kiwi, size: " << fruit_count.size() << "\n";
}

void STLContainersDemo::demonstrateMultimap() {
    cout << "\n=== std::multimap Demonstration ===\n";
    
    // Multimap is useful when a key maps to multiple values
    // Real use-cases: tag → documents, category → items, student → courses, etc.
    multimap<string, int> category_items; // Allows duplicate keys - still sorted
    category_items.insert({"fruit", 1}); // Must use insert(), no [] operator
    category_items.insert({"fruit", 2}); // Same key, different value
    category_items.insert({"fruit", 3});
    category_items.insert({"vegetable", 10});
    category_items.insert({"vegetable", 20});
    
    cout << "Multimap contents:\n";
    for (const auto& pair : category_items) { // Grouped by key, sorted order
        cout << "  " << pair.first << ": " << pair.second << "\n";
    }
    
    auto range = category_items.equal_range("fruit"); // Get all values for a key
    cout << "All fruits: ";
    for (auto it = range.first; it != range.second; ++it) {
        cout << it->second << " ";
    }
    cout << "\n";
    
    cout << "Count of 'fruit': " << category_items.count("fruit") << "\n"; // Number of elements with this key
    
    // Demonstrate erasing all entries with a given key
    size_t erased_count = category_items.erase("fruit"); // Removes ALL key-value pairs with this key
    cout << "Erased " << erased_count << " entries with key 'fruit'\n";
    
    cout << "After erasing all 'fruit' entries: ";
    for (const auto& pair : category_items) { // Custom loop to handle key-value pairs
        cout << pair.first << ":" << pair.second << " ";
    }
    cout << "\n";
}

void STLContainersDemo::demonstrateUnorderedSet() {
    cout << "\n=== std::unordered_set Demonstration ===\n";
    
    unordered_set<int> us = {5, 2, 8, 1, 9}; // Hash table - no ordering, unique elements
    printContainer(us, "Unordered set (hash-based, unique)"); // Order may vary between runs
    
    cout << "Size: " << us.size() << "\n";
    cout << "Bucket count: " << us.bucket_count() << "\n"; // Number of hash buckets
    cout << "Load factor: " << us.load_factor() << "\n"; // size() / bucket_count()
    cout << "Max load factor: " << us.max_load_factor() << "\n"; // Rehash threshold (usually 1.0)
    
    auto it = us.find(8); // Find element - O(1) average, O(n) worst case
    if (it != us.end()) {
        cout << "Found 8 in bucket: " << us.bucket(*it) << "\n"; // Which bucket contains this element
    }
    
    cout << "Hash of 8: " << us.hash_function()(8) << "\n"; // Hash value used for placement
}

void STLContainersDemo::demonstrateUnorderedMap() {
    cout << "\n=== std::unordered_map Demonstration ===\n";
    
    unordered_map<string, int> color_codes; // Hash table with key-value pairs
    color_codes["red"] = 255; // Fast insertion/access - O(1) average
    color_codes["green"] = 128;
    color_codes["blue"] = 64;
    
    cout << "Initial unordered_map:\n";
    for (const auto& pair : color_codes) { // Order is unpredictable
        cout << "  " << pair.first << ": " << pair.second << "\n";
    }
    
    cout << "Value of 'green': " << color_codes["green"] << "\n"; // O(1) average access
    
    cout << "Load factor: " << color_codes.load_factor() << "\n"; // Performance indicator
    cout << "Bucket count: " << color_codes.bucket_count() << "\n";
    
    if (color_codes.find("purple") == color_codes.end()) { // Safe check without creating entry
        cout << "'purple' not found\n";
    }
    
    if (color_codes.count("red") > 0) { // Alternative existence check - returns 0 or 1
        cout << "Red is present\n";
    }
}

void STLContainersDemo::demonstrateContainerChoice() {
    cout << "\n=== Container Selection Guide ===\n";
    cout << "SEQUENCE CONTAINERS:\n";
    cout << "  vector - Use when:\n";
    cout << "    * Need random access to elements\n";
    cout << "    * Frequent insertion/deletion at the end\n";
    cout << "    * Memory efficiency is important\n";
    cout << "    * Cache-friendly access patterns\n\n";
    
    cout << "  deque - Use when:\n";
    cout << "    * Need insertion/deletion at both ends\n";
    cout << "    * Need random access but less memory constraints\n";
    cout << "    * Growing from both ends\n\n";
    
    cout << "  list - Use when:\n";
    cout << "    * Frequent insertion/deletion in the middle\n";
    cout << "    * Don't need random access\n";
    cout << "    * Size varies dramatically\n\n";
    
    cout << "ASSOCIATIVE CONTAINERS:\n";
    cout << "  set/map - Use when:\n";
    cout << "    * Need sorted data\n";
    cout << "    * Need to iterate in order\n";
    cout << "    * O(log n) operations are acceptable\n\n";
    
    cout << "  unordered_set/map - Use when:\n";
    cout << "    * Need fastest possible lookup\n";
    cout << "    * Order doesn't matter\n";
    cout << "    * O(1) average operations needed\n\n";
    
    cout << "CONTAINER ADAPTERS:\n";
    cout << "  stack - LIFO operations\n";
    cout << "  queue - FIFO operations\n";
    cout << "  priority_queue - Priority-based operations\n";
}

void STLContainersDemo::performanceTest() {
    cout << "\n=== Container Performance Comparison ===\n";
    
    const int N = 100000;
    
    auto start = std::chrono::high_resolution_clock::now();
    
    vector<int> vec;
    vec.reserve(N); // Pre-allocate to avoid reallocations during test
    for (int i = 0; i < N; ++i) {
        vec.push_back(i);
    }
    
    auto end = std::chrono::high_resolution_clock::now();
    auto vector_time = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    
    start = std::chrono::high_resolution_clock::now();
    
    list<int> lst;
    for (int i = 0; i < N; ++i) {
        lst.push_back(i);
    }
    
    end = std::chrono::high_resolution_clock::now();
    auto list_time = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    
    cout << "Insertion Performance (N=" << N << "):\n";
    cout << "  Vector push_back: " << vector_time.count() << " us\n";
    cout << "  List push_back: " << list_time.count() << " us\n";
    
    // Additional safety demonstration
    cout << "\nSafety Note: Always check container size before indexed access:\n";
    if (vec.size() > 10) {
        cout << "  vec.at(10) = " << vec.at(10) << " (safe with bounds checking)\n";
        cout << "  vec[10] = " << vec[10] << " (fast but no bounds checking)\n";
    }
}

void STLContainersDemo::demonstrateAll() {
    cout << "\n" << string(60, '=') << "\n";
    cout << "COMPREHENSIVE STL CONTAINERS DEMONSTRATION\n";
    cout << string(60, '=') << "\n";
    
    demonstrateVector();
    demonstrateArray();
    demonstrateDeque();
    demonstrateList();
    demonstrateForwardList();
    demonstrateStack();
    demonstrateQueue();
    demonstratePriorityQueue();
    demonstrateSet();
    demonstrateMultiset();
    demonstrateMap();
    demonstrateMultimap();
    demonstrateUnorderedSet();
    demonstrateUnorderedMap();
    performanceTest();
    demonstrateContainerChoice();
}

// =============================================================================
// STL ALGORITHMS DEMONSTRATIONS
// =============================================================================

void STLAlgorithmsDemo::demonstrateFindOperations() {
    cout << "\n=== Find Operations ===\n";
    
    vector<int> vec = {1, 3, 5, 7, 9, 11, 13, 15};
    
    auto it = find(vec.begin(), vec.end(), 7); // Linear search for value - O(n), works on any container
    if (it != vec.end()) { // ESSENTIAL check - always validate find() results
        cout << "Found 7 at position: " << (it - vec.begin()) << "\n"; // Iterator arithmetic for position
    } else {
        cout << "Value 7 not found in container\n";
    }
    
    auto even_it = find_if(vec.begin(), vec.end(), [](int x) { return x % 2 == 0; }); // Find with predicate (lambda)
    if (even_it == vec.end()) { // end() means not found
        cout << "No even numbers found\n";
    } else {
        cout << "First even number: " << *even_it << " at position " << (even_it - vec.begin()) << "\n";
    }
}

void STLAlgorithmsDemo::demonstrateCountOperations() {
    cout << "\n=== Count Operations ===\n";
    
    vector<int> vec = {1, 2, 3, 2, 4, 2, 5};
    
    int count_2 = count(vec.begin(), vec.end(), 2); // Count occurrences of specific value - O(n)
    cout << "Count of 2: " << count_2 << "\n";
    
    int count_even = count_if(vec.begin(), vec.end(), [](int x) { return x % 2 == 0; }); // Count with condition
    cout << "Count of even numbers: " << count_even << "\n";
}

void STLAlgorithmsDemo::demonstrateSearchOperations() {
    cout << "\n=== Search Operations ===\n";
    
    vector<int> vec = {1, 3, 5, 7, 9, 11, 13, 15}; // Must be sorted for binary search!
    
    bool found = binary_search(vec.begin(), vec.end(), 9); // Fast search in sorted range - O(log n)
    cout << "Binary search for 9: " << (found ? "found" : "not found") << "\n";
    
    auto lower = lower_bound(vec.begin(), vec.end(), 7); // First position where 7 could be inserted to maintain order
    auto upper = upper_bound(vec.begin(), vec.end(), 7); // First position after all 7s
    
    if (lower != vec.end()) { // Safety check for lower_bound result
        cout << "Lower bound of 7: position " << (lower - vec.begin()) << "\n";
    }
    if (upper != vec.end()) { // Safety check for upper_bound result
        cout << "Upper bound of 7: position " << (upper - vec.begin()) << "\n";
    } else {
        cout << "Upper bound of 7: end of container (would insert at end)\n";
    }
}

void STLAlgorithmsDemo::demonstrateCopyOperations() {
    cout << "\n=== Copy Operations ===\n";
    
    vector<int> source = {1, 2, 3, 4, 5};
    vector<int> dest(source.size()); // Pre-allocate destination with same size
    
    copy(source.begin(), source.end(), dest.begin()); // Copy all elements - O(n)
    cout << "After copy: ";
    for (int x : dest) cout << x << " ";
    cout << "\n";
    
    vector<int> dest_if;
    copy_if(source.begin(), source.end(), back_inserter(dest_if),  // back_inserter grows vector automatically
                 [](int x) { return x % 2 == 0; }); // Copy only elements matching condition
    cout << "After copy_if (even): ";
    for (int x : dest_if) cout << x << " ";
    cout << "\n";
}

void STLAlgorithmsDemo::demonstrateTransformOperations() {
    cout << "\n=== Transform Operations ===\n";
    
    vector<int> vec = {1, 2, 3, 4, 5};
    vector<int> doubled(vec.size()); // Pre-allocate destination
    
    transform(vec.begin(), vec.end(), doubled.begin(), [](int x) { return x * 2; }); // Apply function to each element - O(n)
    cout << "After transform (double): ";
    for (int x : doubled) cout << x << " ";
    cout << "\n";
}

void STLAlgorithmsDemo::demonstrateReplaceOperations() {
    cout << "\n=== Replace Operations ===\n";
    
    vector<int> vec = {1, 2, 3, 4, 5};
    replace(vec.begin(), vec.end(), 3, 99); // Replace all occurrences of 3 with 99 - O(n)
    cout << "After replace(3, 99): ";
    for (int x : vec) cout << x << " ";
    cout << "\n";
}

void STLAlgorithmsDemo::demonstrateRemoveOperations() {
    cout << "\n=== Remove Operations ===\n";
    
    vector<int> vec = {1, 2, 3, 2, 4, 2, 5};
    auto new_end = remove(vec.begin(), vec.end(), 2); // Doesn't actually remove, just moves non-matching to front
    vec.erase(new_end, vec.end()); // Actually remove elements from new_end to end - "erase-remove idiom"
    cout << "After remove(2): ";
    for (int x : vec) cout << x << " ";
    cout << "\n";
}

void STLAlgorithmsDemo::demonstrateReverseRotateOperations() {
    cout << "\n=== Reverse and Rotate Operations ===\n";
    
    vector<int> vec = {1, 2, 3, 4, 5};
    reverse(vec.begin(), vec.end()); // Reverse order in-place - O(n)
    cout << "After reverse: ";
    for (int x : vec) cout << x << " ";
    cout << "\n";
    
    if (vec.size() >= 2) { // Safety check before rotate - need at least 2 elements
        rotate(vec.begin(), vec.begin() + 2, vec.end()); // Rotate left by 2 positions - O(n)
        cout << "After rotate (by 2): "; // Elements at position 2+ move to front
        for (int x : vec) cout << x << " ";
        cout << "\n";
    } else {
        cout << "Vector too small for rotation demonstration\n";
    }
}

void STLAlgorithmsDemo::demonstrateShuffleOperations() {
    cout << "\n=== Shuffle Operations ===\n";
    
    vector<int> vec = {1, 2, 3, 4, 5};
    random_device rd; // Hardware random number generator (if available)
    mt19937 g(rd()); // Mersenne Twister generator seeded with random device
    shuffle(vec.begin(), vec.end(), g); // Randomly reorder elements - O(n)
    cout << "After shuffle: ";
    for (int x : vec) cout << x << " ";
    cout << "\n";
}

void STLAlgorithmsDemo::demonstratePartitionOperations() {
    cout << "\n=== Partition Operations ===\n";
    
    vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    auto pivot = partition(vec.begin(), vec.end(), [](int x) { return x % 2 == 0; }); // Reorder: true elements first - O(n)
    cout << "After partition (even first): ";
    for (int x : vec) cout << x << " ";
    cout << "\n";
    
    if (pivot != vec.end()) { // Safety check - partition might return end() if all elements match predicate
        cout << "Pivot at position: " << (pivot - vec.begin()) << "\n"; // Iterator to first false element
    } else {
        cout << "All elements matched the predicate\n";
    }
}

void STLAlgorithmsDemo::demonstrateSortOperations() {
    cout << "\n=== Sort Operations ===\n";
    
    vector<int> vec = {64, 34, 25, 12, 22, 11, 90};
    cout << "Original: ";
    for (int x : vec) cout << x << " ";
    cout << "\n";
    
    sort(vec.begin(), vec.end()); // Usually Quicksort or Introsort - O(n log n) average
    cout << "After sort(): ";
    for (int x : vec) cout << x << " ";
    cout << "\n";
    
    vector<int> vec2 = {64, 34, 25, 12, 22, 11, 90};
    stable_sort(vec2.begin(), vec2.end(), greater<int>()); // Preserves relative order of equal elements
    cout << "After stable_sort (descending): ";
    for (int x : vec2) cout << x << " ";
    cout << "\n";
}

void STLAlgorithmsDemo::demonstrateBinarySearchOperations() {
    cout << "\n=== Binary Search Operations ===\n";
    
    vector<int> vec = {1, 3, 5, 7, 9, 11, 13, 15};
    
    bool found = binary_search(vec.begin(), vec.end(), 7);
    cout << "binary_search(7): " << (found ? "found" : "not found") << "\n";
    
    auto lower = lower_bound(vec.begin(), vec.end(), 7);
    cout << "lower_bound(7): position " << (lower - vec.begin()) << "\n";
    
    auto upper = upper_bound(vec.begin(), vec.end(), 7);
    cout << "upper_bound(7): position " << (upper - vec.begin()) << "\n";
}

void STLAlgorithmsDemo::demonstrateMergeOperations() {
    cout << "\n=== Merge Operations ===\n";
    
    vector<int> vec1 = {1, 3, 5, 7};
    vector<int> vec2 = {2, 4, 6, 8};
    vector<int> result;
    
    merge(vec1.begin(), vec1.end(), vec2.begin(), vec2.end(), 
               back_inserter(result));
    cout << "After merge: ";
    for (int x : result) cout << x << " ";
    cout << "\n";
}

void STLAlgorithmsDemo::demonstrateHeapOperations() {
    cout << "\n=== Heap Operations ===\n";
    
    vector<int> vec = {3, 1, 4, 1, 5, 9, 2, 6};
    
    make_heap(vec.begin(), vec.end()); // Rearrange into max-heap - O(n), faster than n insertions
    cout << "After make_heap: ";
    for (int x : vec) cout << x << " "; // Largest element is now at front
    cout << "\n";
    
    vec.push_back(8); // Add element to back of vector
    push_heap(vec.begin(), vec.end()); // Restore heap property - O(log n), assumes last element is new
    cout << "After push_heap(8): ";
    for (int x : vec) cout << x << " ";
    cout << "\n";
    
    pop_heap(vec.begin(), vec.end()); // Move max element to back, restore heap for remaining - O(log n)
    vec.pop_back(); // Remove the max element that was moved to back
    cout << "After pop_heap: ";
    for (int x : vec) cout << x << " ";
    cout << "\n";
}

void STLAlgorithmsDemo::demonstrateMinMaxOperations() {
    cout << "\n=== Min/Max Operations ===\n";
    
    vector<int> vec = {3, 1, 4, 1, 5, 9, 2, 6};
    
    if (!vec.empty()) { // Safety check - min/max_element require non-empty containers
        auto min_elem = min_element(vec.begin(), vec.end()); // Find minimum element - O(n)
        auto max_elem = max_element(vec.begin(), vec.end()); // Find maximum element - O(n)
        
        cout << "Min element: " << *min_elem << " at position " << (min_elem - vec.begin()) << "\n";
        cout << "Max element: " << *max_elem << " at position " << (max_elem - vec.begin()) << "\n";
        
        auto minmax = minmax_element(vec.begin(), vec.end()); // Find both min and max in single pass - more efficient
        cout << "MinMax: [" << *minmax.first << ", " << *minmax.second << "]\n"; // Returns pair of iterators
    } else {
        cout << "Cannot find min/max of empty container\n";
    }
}

void STLAlgorithmsDemo::demonstrateNumericOperations() {
    cout << "\n=== Numeric Operations ===\n";
    
    vector<int> vec = {1, 2, 3, 4, 5};
    
    int sum = accumulate(vec.begin(), vec.end(), 0); // Sum all elements starting from 0 - O(n)
    cout << "Sum (accumulate): " << sum << "\n"; // 0 + 1 + 2 + 3 + 4 + 5 = 15
    
    int product = accumulate(vec.begin(), vec.end(), 1, multiplies<int>()); // Product using custom operation
    cout << "Product: " << product << "\n"; // 1 * 1 * 2 * 3 * 4 * 5 = 120
    
    vector<int> partial_sums(vec.size());
    partial_sum(vec.begin(), vec.end(), partial_sums.begin()); // Running sum: 1, 1+2, 1+2+3, etc.
    cout << "Partial sums: ";
    for (int x : partial_sums) cout << x << " "; // Output: 1 3 6 10 15
    cout << "\n";
    
    vector<int> sequence(10);
    iota(sequence.begin(), sequence.end(), 1); // Fill with incrementing values starting from 1
    cout << "Iota sequence (1-10): ";
    for (int x : sequence) cout << x << " "; // Output: 1 2 3 4 5 6 7 8 9 10
    cout << "\n";
}

void STLAlgorithmsDemo::demonstrateSetOperations() {
    cout << "\n=== Set Operations ===\n";
    
    vector<int> set1 = {1, 2, 3, 4, 5}; // Must be sorted for set operations!
    vector<int> set2 = {3, 4, 5, 6, 7};
    
    vector<int> union_result;
    set_union(set1.begin(), set1.end(), set2.begin(), set2.end(),  // Combine both sets - O(m+n)
                   back_inserter(union_result)); // Result: all unique elements from both
    cout << "Union: ";
    for (int x : union_result) cout << x << " "; // Output: 1 2 3 4 5 6 7
    cout << "\n";
    
    vector<int> intersection_result;
    set_intersection(set1.begin(), set1.end(), set2.begin(), set2.end(), // Find common elements - O(m+n)
                         back_inserter(intersection_result));
    cout << "Intersection: ";
    for (int x : intersection_result) cout << x << " "; // Output: 3 4 5
    cout << "\n";
}

void STLAlgorithmsDemo::demonstrateCustomPredicates() {
    cout << "\n=== Custom Predicates ===\n";
    
    vector<string> words = {"apple", "banana", "cherry", "date"};
    
    auto it = find_if(words.begin(), words.end(),  // Find first element matching condition
                          [](const string& s) { return s.length() > 5; }); // Lambda predicate
    if (it != words.end()) {
        cout << "First word longer than 5 chars: " << *it << "\n"; // "banana" has 6 chars
    }
    
    int count = count_if(words.begin(), words.end(), // Count elements matching condition
                             [](const string& s) { return s[0] == 'a'; }); // Words starting with 'a'
    cout << "Words starting with 'a': " << count << "\n"; // "apple" = 1
}

void STLAlgorithmsDemo::demonstrateFunctionObjects() {
    cout << "\n=== Function Objects ===\n";
    
    vector<int> vec = {5, 2, 8, 1, 9};
    
    sort(vec.begin(), vec.end(), greater<int>()); // Sort in descending order using function object
    cout << "Sorted descending (greater): ";
    for (int x : vec) cout << x << " "; // Output: 9 8 5 2 1
    cout << "\n";
    
    vector<int> vec2 = {1, 2, 3, 4, 5};
    transform(vec2.begin(), vec2.end(), vec2.begin(), negate<int>()); // Apply negation to each element
    cout << "After negate: ";
    for (int x : vec2) cout << x << " "; // Output: -1 -2 -3 -4 -5
    cout << "\n";
}

void STLAlgorithmsDemo::demonstrateAll() {
    cout << "\n" << string(60, '=') << "\n";
    cout << "COMPREHENSIVE STL ALGORITHMS DEMONSTRATION\n";
    cout << string(60, '=') << "\n";
    
    demonstrateFindOperations();
    demonstrateCountOperations();
    demonstrateSearchOperations();
    demonstrateCopyOperations();
    demonstrateTransformOperations();
    demonstrateReplaceOperations();
    demonstrateRemoveOperations();
    demonstrateReverseRotateOperations();
    demonstrateShuffleOperations();
    demonstratePartitionOperations();
    demonstrateSortOperations();
    demonstrateBinarySearchOperations();
    demonstrateMergeOperations();
    demonstrateHeapOperations();
    demonstrateMinMaxOperations();
    demonstrateNumericOperations();
    demonstrateSetOperations();
    demonstrateCustomPredicates();
    demonstrateFunctionObjects();
}

// =============================================================================
// STL ITERATORS DEMONSTRATIONS
// =============================================================================

void STLIteratorsDemo::demonstrateInputIterators() {
    cout << "\n=== Input Iterators ===\n";
    cout << "* Read-only, single-pass iterators\n";
    cout << "* Example: std::istream_iterator\n";
}

void STLIteratorsDemo::demonstrateOutputIterators() {
    cout << "\n=== Output Iterators ===\n";
    cout << "* Write-only, single-pass iterators\n";
    cout << "* Example: ostream_iterator\n";
}

void STLIteratorsDemo::demonstrateForwardIterators() {
    cout << "\n=== Forward Iterators ===\n";
    cout << "* Read/write, multi-pass, forward-only\n";
    cout << "* Example: forward_list iterators\n";
}

void STLIteratorsDemo::demonstrateBidirectionalIterators() {
    cout << "\n=== Bidirectional Iterators ===\n";
    cout << "* Forward + backward movement\n";
    cout << "* Example: list, set iterators\n";
}

void STLIteratorsDemo::demonstrateRandomAccessIterators() {
    cout << "\n=== Random Access Iterators ===\n";
    cout << "* All operations + random access\n";
    cout << "* Example: vector, array iterators\n";
}

void STLIteratorsDemo::demonstrateReverseIterators() {
    cout << "\n=== Reverse Iterators ===\n";
    vector<int> vec = {1, 2, 3, 4, 5};
    cout << "* Vector: ";
    for (const auto& elem : vec) cout << elem << " ";
    cout << "\n* Reverse: ";
    for (auto it = vec.rbegin(); it != vec.rend(); ++it) {
        cout << *it << " ";
    }
    cout << "\n";
}

void STLIteratorsDemo::demonstrateInsertIterators() {
    cout << "\n=== Insert Iterators ===\n";
    vector<int> vec = {1, 2, 3};
    vector<int> result;
    
    copy(vec.begin(), vec.end(), back_inserter(result));
    cout << "* After back_inserter copy: ";
    for (const auto& elem : result) cout << elem << " ";
    cout << "\n";
}

void STLIteratorsDemo::demonstrateStreamIterators() {
    cout << "\n=== Stream Iterators ===\n";
    vector<int> vec = {10, 20, 30, 40, 50};
    cout << "* Vector output with ostream_iterator: ";
    copy(vec.begin(), vec.end(), ostream_iterator<int>(cout, " "));
    cout << "\n";
}

void STLIteratorsDemo::demonstrateIteratorOperations() {
    cout << "\n=== Iterator Operations ===\n";
    vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    auto it = vec.begin();
    advance(it, 3);
    cout << "* After advance(3): " << *it << "\n";
    
    auto dist = distance(vec.begin(), it);
    cout << "* Distance from begin: " << dist << "\n";
}

void STLIteratorsDemo::demonstrateIteratorTraits() {
    cout << "\n=== Iterator Traits ===\n";
    cout << "* Iterator traits provide type information\n";
    cout << "* Used by algorithms to optimize for iterator types\n";
    cout << "* Example: std::iterator_traits<Iterator>::iterator_category\n";
}

void STLIteratorsDemo::demonstrateCustomIterators() {
    cout << "\n=== Custom Iterators ===\n";
    cout << "* Range-based custom iterator example:\n";
    
    cout << "* Range(1, 10, 2): ";
    for (int i = 1; i < 10; i += 2) {
        cout << i << " ";
    }
    cout << "\n";
}

void STLIteratorsDemo::demonstrateAll() {
    cout << "\n" << string(60, '=') << "\n";
    cout << "COMPREHENSIVE STL ITERATORS DEMONSTRATION\n";
    cout << string(60, '=') << "\n";
    
    demonstrateInputIterators();
    demonstrateOutputIterators();
    demonstrateForwardIterators();
    demonstrateBidirectionalIterators();
    demonstrateRandomAccessIterators();
    demonstrateReverseIterators();
    demonstrateInsertIterators();
    demonstrateStreamIterators();
    demonstrateIteratorOperations();
    demonstrateIteratorTraits();
    demonstrateCustomIterators();
}

// =============================================================================
// STL INTERVIEW QUESTIONS
// =============================================================================

void STLInterviewQuestions::findTwoSum() {
    cout << "\n=== Two Sum Problem ===\n";
    cout << "Problem: Find two numbers that add up to target\n";
    
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    
    unordered_map<int, int> num_to_index;
    cout << "Input: [";
    for (size_t i = 0; i < nums.size(); ++i) {
        cout << nums[i];
        if (i < nums.size() - 1) cout << ", ";
    }
    cout << "], target = " << target << "\n";
    
    for (size_t i = 0; i < nums.size(); ++i) {
        int complement = target - nums[i];
        if (num_to_index.find(complement) != num_to_index.end()) {
            cout << "Result: indices [" << num_to_index[complement] << ", " << i << "]\n";
            return;
        }
        num_to_index[nums[i]] = i;
    }
    cout << "No solution found\n";
}

void STLInterviewQuestions::topKFrequentElements() {
    cout << "\n=== Top K Frequent Elements ===\n";
    cout << "Problem: Find k most frequent elements\n";
    
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    int k = 2;
    
    cout << "Input: [";
    for (size_t i = 0; i < nums.size(); ++i) {
        cout << nums[i];
        if (i < nums.size() - 1) cout << ", ";
    }
    cout << "], k = " << k << "\n";
    
    unordered_map<int, int> freq;
    for (int num : nums) {
        freq[num]++;
    }
    
    auto comp = [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second;
    };
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> pq(comp);
    
    for (const auto& p : freq) {
        pq.push({p.first, p.second});
        if (pq.size() > static_cast<size_t>(k)) {
            pq.pop();
        }
    }
    
    vector<int> result;
    while (!pq.empty()) {
        result.push_back(pq.top().first);
        pq.pop();
    }
    
    cout << "Result: [";
    for (size_t i = 0; i < result.size(); ++i) {
        cout << result[i];
        if (i < result.size() - 1) cout << ", ";
    }
    cout << "]\n";
}

void STLInterviewQuestions::vectorVsList() {
    cout << "\n=== Vector vs List Performance ===\n";
    cout << "Comparing performance characteristics\n";
    
    const int N = 100000;
    
    auto start = std::chrono::high_resolution_clock::now();
    vector<int> vec;
    vec.reserve(N);
    for (int i = 0; i < N; ++i) {
        vec.push_back(i);
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto vector_insert = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    
    start = std::chrono::high_resolution_clock::now();
    list<int> lst;
    for (int i = 0; i < N; ++i) {
        lst.push_back(i);
    }
    end = std::chrono::high_resolution_clock::now();
    auto list_insert = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    
    cout << "\nInsertion performance:\n";
    cout << "  Vector: " << vector_insert.count() << " us\n";
    cout << "  List: " << list_insert.count() << " us\n";
    
    if (vec.size() > N/2) { // Safety check before accessing middle element
        start = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < 1000; ++i) {
            volatile int x = vec[N/2]; // Access middle element
            (void)x; // Suppress unused variable warning
        }
        end = std::chrono::high_resolution_clock::now();
        auto vector_access = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
        
        cout << "\nRandom access (1000 operations):\n";
        cout << "  Vector: " << vector_access.count() << " ns\n";
        cout << "  List: Not supported (no random access)\n";
    }
    
    cout << "\nKey differences:\n";
    cout << "* Vector: O(1) random access, O(1) amortized push_back\n";
    cout << "* List: O(1) insertion/deletion anywhere, O(n) access\n";
    cout << "* Vector: Better cache locality due to contiguous memory\n";
    cout << "* List: No reallocation, stable iterators\n";
}

void STLInterviewQuestions::demonstrateAll() {
    cout << "\n" << string(60, '=') << "\n";
    cout << "STL INTERVIEW QUESTIONS DEMONSTRATION\n";
    cout << string(60, '=') << "\n";
    
    findTwoSum();
    topKFrequentElements();
    vectorVsList();
}

// =============================================================================
// STL BEST PRACTICES
// =============================================================================

void STLBestPractices::demonstrateAll() {
    cout << "\n" << string(60, '=') << "\n";
    cout << "STL BEST PRACTICES DEMONSTRATION\n";
    cout << string(60, '=') << "\n";
    
    cout << "\n=== Container Selection Guide ===\n";
    cout << "* vector: Default choice, contiguous memory\n";
    cout << "* list: Frequent insertion/deletion in middle\n";
    cout << "* deque: Insertion/deletion at both ends\n";
    cout << "* set: Sorted unique elements\n";
    cout << "* unordered_set: Fast lookup, no ordering\n";
    
    cout << "\n=== Performance Tips ===\n";
    cout << "* Use reserve() for vectors when size is known\n";
    cout << "* Prefer emplace over insert for efficiency\n";
    cout << "* Use move semantics for large objects\n";
    cout << "* Choose algorithms over raw loops\n";
    
    cout << "\n=== Memory Management ===\n";
    cout << "* Use shrink_to_fit() to release unused capacity\n";
    cout << "* Consider memory layout: vector > deque > list\n";
    cout << "* Avoid frequent reallocations\n";
    
    cout << "\n=== Modern C++ Features ===\n";
    cout << "* Use auto for type deduction\n";
    cout << "* Range-based for loops\n";
    cout << "* Lambda expressions\n";
    cout << "* Smart pointers for RAII\n";
}

// =============================================================================
// TEMPLATE HELPER FUNCTIONS
// =============================================================================

template<typename Container>
void STLContainersDemo::printContainer(const Container& container, const string& name) {
    cout << name << ": ";
    for (const auto& elem : container) {
        cout << elem << " ";
    }
    cout << "\n";
}

// Explicit template instantiations
template void STLContainersDemo::printContainer<vector<int>>(const vector<int>&, const string&);
template void STLContainersDemo::printContainer<array<int, 5>>(const array<int, 5>&, const string&);
template void STLContainersDemo::printContainer<deque<int>>(const deque<int>&, const string&);
template void STLContainersDemo::printContainer<list<int>>(const list<int>&, const string&);
template void STLContainersDemo::printContainer<set<int>>(const set<int>&, const string&);
template void STLContainersDemo::printContainer<multiset<int>>(const multiset<int>&, const string&);
template void STLContainersDemo::printContainer<unordered_set<int>>(const unordered_set<int>&, const string&);

} // namespace CppBasics 
