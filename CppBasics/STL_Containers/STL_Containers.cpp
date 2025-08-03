#include "12_STL_Containers.h"
#include <algorithm>
#include <numeric>
#include <iterator>
#include <chrono>
#include <random>

namespace CppBasics {

// =============================================================================
// STL CONTAINERS DEMONSTRATIONS
// =============================================================================

void STLContainersDemo::demonstrateVector() {
    std::cout << "\n=== std::vector Demonstration ===\n";
    
    std::vector<int> vec = {1, 2, 3, 4, 5};
    printContainer(vec, "Initial vector");
    std::cout << "Size: " << vec.size() << ", Capacity: " << vec.capacity() << "\n";
    
    vec.push_back(6);
    vec.push_back(7);
    printContainer(vec, "After push_back(6,7)");
    std::cout << "Size: " << vec.size() << ", Capacity: " << vec.capacity() << "\n";
    
    vec.reserve(20);
    std::cout << "After reserve(20) - Capacity: " << vec.capacity() << "\n";
    
    vec.insert(vec.begin() + 2, 99);
    printContainer(vec, "After insert(begin+2, 99)");
    
    vec.erase(vec.begin() + 2);
    printContainer(vec, "After erase(begin+2)");
    
    std::cout << "Front: " << vec.front() << ", Back: " << vec.back() << "\n";
    std::cout << "At index 2: " << vec.at(2) << ", operator[2]: " << vec[2] << "\n";
    
    vec.shrink_to_fit();
    std::cout << "After shrink_to_fit() - Capacity: " << vec.capacity() << "\n";
}

void STLContainersDemo::demonstrateArray() {
    std::cout << "\n=== std::array Demonstration ===\n";
    
    std::array<int, 5> arr = {10, 20, 30, 40, 50};
    printContainer(arr, "Array");
    std::cout << "Size: " << arr.size() << ", Max size: " << arr.max_size() << "\n";
    
    std::cout << "Front: " << arr.front() << ", Back: " << arr.back() << "\n";
    std::cout << "At index 2: " << arr.at(2) << "\n";
    
    std::array<int, 5> arr2;
    arr2.fill(42);
    printContainer(arr2, "After fill(42)");
    
    arr.swap(arr2);
    printContainer(arr, "After swap");
}

void STLContainersDemo::demonstrateDeque() {
    std::cout << "\n=== std::deque Demonstration ===\n";
    
    std::deque<int> dq = {3, 4, 5};
    printContainer(dq, "Initial deque");
    
    dq.push_front(2);
    dq.push_front(1);
    dq.push_back(6);
    dq.push_back(7);
    printContainer(dq, "After push operations");
    
    dq.pop_front();
    dq.pop_back();
    printContainer(dq, "After pop operations");
    
    std::cout << "Element at index 2: " << dq[2] << "\n";
    
    dq.insert(dq.begin() + 1, 99);
    printContainer(dq, "After insert");
}

void STLContainersDemo::demonstrateList() {
    std::cout << "\n=== std::list Demonstration ===\n";
    
    std::list<int> lst = {5, 2, 8, 1, 9};
    printContainer(lst, "Initial list");
    
    lst.sort();
    printContainer(lst, "After sort()");
    
    lst.reverse();
    printContainer(lst, "After reverse()");
    
    std::list<int> other = {100, 200};
    auto splice_pos = lst.begin();
    std::advance(splice_pos, 2);
    lst.splice(splice_pos, other);
    printContainer(lst, "After splice");
    
    lst.remove(100);
    printContainer(lst, "After remove(100)");
    
    lst.push_back(9);
    lst.push_back(8);
    printContainer(lst, "After adding duplicates");
}

void STLContainersDemo::demonstrateForwardList() {
    std::cout << "\n=== std::forward_list Demonstration ===\n";
    
    std::forward_list<int> fl = {1, 2, 3, 4, 5};
    std::cout << "Initial forward_list: ";
    for (const auto& elem : fl) std::cout << elem << " ";
    std::cout << "\n";
    
    fl.insert_after(fl.begin(), 99);
    std::cout << "After insert_after(begin(), 99): ";
    for (const auto& elem : fl) std::cout << elem << " ";
    std::cout << "\n";
    
    fl.erase_after(fl.before_begin());
    std::cout << "After erase_after(before_begin()): ";
    for (const auto& elem : fl) std::cout << elem << " ";
    std::cout << "\n";
    
    fl.sort();
    std::cout << "After sort(): ";
    for (const auto& elem : fl) std::cout << elem << " ";
    std::cout << "\n";
}

void STLContainersDemo::demonstrateStack() {
    std::cout << "\n=== std::stack Demonstration ===\n";
    
    std::stack<int> stk;
    for (int i = 1; i <= 5; ++i) {
        stk.push(i * 10);
    }
    
    std::cout << "Stack size: " << stk.size() << "\n";
    std::cout << "Popping elements: ";
    while (!stk.empty()) {
        std::cout << stk.top() << " ";
        stk.pop();
    }
    std::cout << "\n";
    
    // Practical example: balanced parentheses
    std::string expr = "((()))";
    std::stack<char> paren_stack;
    bool balanced = true;
    
    for (char c : expr) {
        if (c == '(') {
            paren_stack.push(c);
        } else if (c == ')') {
            if (paren_stack.empty()) {
                balanced = false;
                break;
            }
            paren_stack.pop();
        }
    }
    
    balanced = balanced && paren_stack.empty();
    std::cout << "Expression \"" << expr << "\" is " << (balanced ? "balanced" : "not balanced") << "\n";
}

void STLContainersDemo::demonstrateQueue() {
    std::cout << "\n=== std::queue Demonstration ===\n";
    
    std::queue<std::string> q;
    q.push("First");
    q.push("Second");
    q.push("Third");
    
    std::cout << "Queue size: " << q.size() << "\n";
    std::cout << "Front: " << q.front() << ", Back: " << q.back() << "\n";
    
    std::cout << "Dequeuing: ";
    while (!q.empty()) {
        std::cout << q.front() << " ";
        q.pop();
    }
    std::cout << "\n";
}

void STLContainersDemo::demonstratePriorityQueue() {
    std::cout << "\n=== std::priority_queue Demonstration ===\n";
    
    std::priority_queue<int> max_pq;
    std::vector<int> nums = {3, 1, 4, 1, 5, 9, 2, 6};
    for (int n : nums) max_pq.push(n);
    
    std::cout << "Max-heap (default): ";
    while (!max_pq.empty()) {
        std::cout << max_pq.top() << " ";
        max_pq.pop();
    }
    std::cout << "\n";
    
    std::priority_queue<int, std::vector<int>, std::greater<int>> min_pq;
    for (int n : nums) min_pq.push(n);
    
    std::cout << "Min-heap: ";
    while (!min_pq.empty()) {
        std::cout << min_pq.top() << " ";
        min_pq.pop();
    }
    std::cout << "\n";
}

void STLContainersDemo::demonstrateSet() {
    std::cout << "\n=== std::set Demonstration ===\n";
    
    std::set<int> s = {5, 2, 8, 1, 9, 2}; // Duplicates will be ignored
    printContainer(s, "Set (sorted, unique)");
    
    auto result = s.insert(7);
    std::cout << "Insert 7: " << (result.second ? "success" : "failed") << "\n";
    
    result = s.insert(5); // Duplicate
    std::cout << "Insert 5 (duplicate): " << (result.second ? "success" : "failed") << "\n";
    
    auto it = s.find(8);
    if (it != s.end()) {
        std::cout << "Found: " << *it << "\n";
    }
    
    auto lower = s.lower_bound(5);
    auto upper = s.upper_bound(7);
    std::cout << "Elements in range [5, 7]: ";
    for (auto iter = lower; iter != upper; ++iter) {
        std::cout << *iter << " ";
    }
    std::cout << "\n";
    
    std::cout << "Count of 5: " << s.count(5) << "\n";
    
    s.erase(5);
    printContainer(s, "After erase(5)");
}

void STLContainersDemo::demonstrateMultiset() {
    std::cout << "\n=== std::multiset Demonstration ===\n";
    
    std::multiset<int> ms = {5, 2, 8, 1, 9, 2, 5}; // Allows duplicates
    printContainer(ms, "Multiset (sorted, duplicates allowed)");
    
    std::cout << "Count of 5: " << ms.count(5) << "\n";
    std::cout << "Count of 2: " << ms.count(2) << "\n";
    
    auto range = ms.equal_range(5);
    std::cout << "All occurrences of 5: ";
    for (auto it = range.first; it != range.second; ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n";
    
    auto pos = ms.find(5);
    if (pos != ms.end()) {
        ms.erase(pos);
    }
    printContainer(ms, "After erasing one occurrence of 5");
}

void STLContainersDemo::demonstrateMap() {
    std::cout << "\n=== std::map Demonstration ===\n";
    
    std::map<std::string, int> fruit_count;
    fruit_count["apple"] = 5;
    fruit_count["banana"] = 3;
    fruit_count["orange"] = 8;
    
    std::cout << "Initial map:\n";
    for (const auto& pair : fruit_count) {
        std::cout << "  " << pair.first << ": " << pair.second << "\n";
    }
    
    std::cout << "Apple count: " << fruit_count["apple"] << "\n";
    std::cout << "Kiwi count: " << fruit_count["kiwi"] << "\n"; // Creates entry with 0
    
    auto it = fruit_count.find("banana");
    if (it != fruit_count.end()) {
        std::cout << "Found banana: " << it->second << "\n";
    }
    
    fruit_count.insert({"grape", 12});
    fruit_count["banana"] = 5; // Update existing
    fruit_count.emplace("mango", 7);
    
    std::cout << "Final map:\n";
    for (const auto& pair : fruit_count) {
        std::cout << "  " << pair.first << ": " << pair.second << "\n";
    }
    
    fruit_count.erase("kiwi");
    std::cout << "After erasing kiwi, size: " << fruit_count.size() << "\n";
}

void STLContainersDemo::demonstrateMultimap() {
    std::cout << "\n=== std::multimap Demonstration ===\n";
    
    std::multimap<std::string, int> category_items;
    category_items.insert({"fruit", 1});
    category_items.insert({"fruit", 2});
    category_items.insert({"fruit", 3});
    category_items.insert({"vegetable", 10});
    category_items.insert({"vegetable", 20});
    
    std::cout << "Multimap contents:\n";
    for (const auto& pair : category_items) {
        std::cout << "  " << pair.first << ": " << pair.second << "\n";
    }
    
    auto range = category_items.equal_range("fruit");
    std::cout << "All fruits: ";
    for (auto it = range.first; it != range.second; ++it) {
        std::cout << it->second << " ";
    }
    std::cout << "\n";
    
    std::cout << "Count of 'fruit': " << category_items.count("fruit") << "\n";
}

void STLContainersDemo::demonstrateUnorderedSet() {
    std::cout << "\n=== std::unordered_set Demonstration ===\n";
    
    std::unordered_set<int> us = {5, 2, 8, 1, 9};
    printContainer(us, "Unordered set (hash-based, unique)");
    
    std::cout << "Size: " << us.size() << "\n";
    std::cout << "Bucket count: " << us.bucket_count() << "\n";
    std::cout << "Load factor: " << us.load_factor() << "\n";
    std::cout << "Max load factor: " << us.max_load_factor() << "\n";
    
    auto it = us.find(8);
    if (it != us.end()) {
        std::cout << "Found 8 in bucket: " << us.bucket(*it) << "\n";
    }
    
    std::cout << "Hash of 8: " << us.hash_function()(8) << "\n";
}

void STLContainersDemo::demonstrateUnorderedMap() {
    std::cout << "\n=== std::unordered_map Demonstration ===\n";
    
    std::unordered_map<std::string, int> color_codes;
    color_codes["red"] = 255;
    color_codes["green"] = 128;
    color_codes["blue"] = 64;
    
    std::cout << "Initial unordered_map:\n";
    for (const auto& pair : color_codes) {
        std::cout << "  " << pair.first << ": " << pair.second << "\n";
    }
    
    std::cout << "Value of 'green': " << color_codes["green"] << "\n";
    
    std::cout << "Load factor: " << color_codes.load_factor() << "\n";
    std::cout << "Bucket count: " << color_codes.bucket_count() << "\n";
    
    if (color_codes.find("purple") == color_codes.end()) {
        std::cout << "'purple' not found\n";
    }
    
    if (color_codes.count("red") > 0) {
        std::cout << "Red is present\n";
    }
}

void STLContainersDemo::demonstrateContainerChoice() {
    std::cout << "\n=== Container Selection Guide ===\n";
    std::cout << "SEQUENCE CONTAINERS:\n";
    std::cout << "  std::vector - Use when:\n";
    std::cout << "    * Need random access to elements\n";
    std::cout << "    * Frequent insertion/deletion at the end\n";
    std::cout << "    * Memory efficiency is important\n";
    std::cout << "    * Cache-friendly access patterns\n\n";
    
    std::cout << "  std::deque - Use when:\n";
    std::cout << "    * Need insertion/deletion at both ends\n";
    std::cout << "    * Need random access but less memory constraints\n";
    std::cout << "    * Growing from both ends\n\n";
    
    std::cout << "  std::list - Use when:\n";
    std::cout << "    * Frequent insertion/deletion in the middle\n";
    std::cout << "    * Don't need random access\n";
    std::cout << "    * Size varies dramatically\n\n";
    
    std::cout << "ASSOCIATIVE CONTAINERS:\n";
    std::cout << "  std::set/map - Use when:\n";
    std::cout << "    * Need sorted data\n";
    std::cout << "    * Need to iterate in order\n";
    std::cout << "    * O(log n) operations are acceptable\n\n";
    
    std::cout << "  std::unordered_set/map - Use when:\n";
    std::cout << "    * Need fastest possible lookup\n";
    std::cout << "    * Order doesn't matter\n";
    std::cout << "    * O(1) average operations needed\n\n";
    
    std::cout << "CONTAINER ADAPTERS:\n";
    std::cout << "  std::stack - LIFO operations\n";
    std::cout << "  std::queue - FIFO operations\n";
    std::cout << "  std::priority_queue - Priority-based operations\n";
}

void STLContainersDemo::performanceTest() {
    std::cout << "\n=== Container Performance Comparison ===\n";
    
    const int N = 100000;
    
    auto start = std::chrono::high_resolution_clock::now();
    
    std::vector<int> vec;
    vec.reserve(N);
    for (int i = 0; i < N; ++i) {
        vec.push_back(i);
    }
    
    auto end = std::chrono::high_resolution_clock::now();
    auto vector_time = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    
    start = std::chrono::high_resolution_clock::now();
    
    std::list<int> lst;
    for (int i = 0; i < N; ++i) {
        lst.push_back(i);
    }
    
    end = std::chrono::high_resolution_clock::now();
    auto list_time = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    
    std::cout << "Insertion Performance (N=" << N << "):\n";
    std::cout << "  Vector push_back: " << vector_time.count() << " us\n";
    std::cout << "  List push_back: " << list_time.count() << " us\n";
}

void STLContainersDemo::demonstrateAll() {
    std::cout << "\n" << std::string(60, '=') << "\n";
    std::cout << "COMPREHENSIVE STL CONTAINERS DEMONSTRATION\n";
    std::cout << std::string(60, '=') << "\n";
    
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
    std::cout << "\n=== Find Operations ===\n";
    
    std::vector<int> vec = {1, 3, 5, 7, 9, 11, 13, 15};
    
    auto it = std::find(vec.begin(), vec.end(), 7);
    if (it != vec.end()) {
        std::cout << "Found 7 at position: " << (it - vec.begin()) << "\n";
    }
    
    auto even_it = std::find_if(vec.begin(), vec.end(), [](int x) { return x % 2 == 0; });
    if (even_it == vec.end()) {
        std::cout << "No even numbers found\n";
    }
}

void STLAlgorithmsDemo::demonstrateCountOperations() {
    std::cout << "\n=== Count Operations ===\n";
    
    std::vector<int> vec = {1, 2, 3, 2, 4, 2, 5};
    
    int count_2 = std::count(vec.begin(), vec.end(), 2);
    std::cout << "Count of 2: " << count_2 << "\n";
    
    int count_even = std::count_if(vec.begin(), vec.end(), [](int x) { return x % 2 == 0; });
    std::cout << "Count of even numbers: " << count_even << "\n";
}

void STLAlgorithmsDemo::demonstrateSearchOperations() {
    std::cout << "\n=== Search Operations ===\n";
    
    std::vector<int> vec = {1, 3, 5, 7, 9, 11, 13, 15};
    
    bool found = std::binary_search(vec.begin(), vec.end(), 9);
    std::cout << "Binary search for 9: " << (found ? "found" : "not found") << "\n";
    
    auto lower = std::lower_bound(vec.begin(), vec.end(), 7);
    auto upper = std::upper_bound(vec.begin(), vec.end(), 7);
    std::cout << "Lower bound of 7: position " << (lower - vec.begin()) << "\n";
    std::cout << "Upper bound of 7: position " << (upper - vec.begin()) << "\n";
}

void STLAlgorithmsDemo::demonstrateCopyOperations() {
    std::cout << "\n=== Copy Operations ===\n";
    
    std::vector<int> source = {1, 2, 3, 4, 5};
    std::vector<int> dest(source.size());
    
    std::copy(source.begin(), source.end(), dest.begin());
    std::cout << "After copy: ";
    for (int x : dest) std::cout << x << " ";
    std::cout << "\n";
    
    std::vector<int> dest_if;
    std::copy_if(source.begin(), source.end(), std::back_inserter(dest_if), 
                 [](int x) { return x % 2 == 0; });
    std::cout << "After copy_if (even): ";
    for (int x : dest_if) std::cout << x << " ";
    std::cout << "\n";
}

void STLAlgorithmsDemo::demonstrateTransformOperations() {
    std::cout << "\n=== Transform Operations ===\n";
    
    std::vector<int> vec = {1, 2, 3, 4, 5};
    std::vector<int> doubled(vec.size());
    
    std::transform(vec.begin(), vec.end(), doubled.begin(), [](int x) { return x * 2; });
    std::cout << "After transform (double): ";
    for (int x : doubled) std::cout << x << " ";
    std::cout << "\n";
}

void STLAlgorithmsDemo::demonstrateReplaceOperations() {
    std::cout << "\n=== Replace Operations ===\n";
    
    std::vector<int> vec = {1, 2, 3, 4, 5};
    std::replace(vec.begin(), vec.end(), 3, 99);
    std::cout << "After replace(3, 99): ";
    for (int x : vec) std::cout << x << " ";
    std::cout << "\n";
}

void STLAlgorithmsDemo::demonstrateRemoveOperations() {
    std::cout << "\n=== Remove Operations ===\n";
    
    std::vector<int> vec = {1, 2, 3, 2, 4, 2, 5};
    auto new_end = std::remove(vec.begin(), vec.end(), 2);
    vec.erase(new_end, vec.end());
    std::cout << "After remove(2): ";
    for (int x : vec) std::cout << x << " ";
    std::cout << "\n";
}

void STLAlgorithmsDemo::demonstrateReverseRotateOperations() {
    std::cout << "\n=== Reverse and Rotate Operations ===\n";
    
    std::vector<int> vec = {1, 2, 3, 4, 5};
    std::reverse(vec.begin(), vec.end());
    std::cout << "After reverse: ";
    for (int x : vec) std::cout << x << " ";
    std::cout << "\n";
    
    std::rotate(vec.begin(), vec.begin() + 2, vec.end());
    std::cout << "After rotate (by 2): ";
    for (int x : vec) std::cout << x << " ";
    std::cout << "\n";
}

void STLAlgorithmsDemo::demonstrateShuffleOperations() {
    std::cout << "\n=== Shuffle Operations ===\n";
    
    std::vector<int> vec = {1, 2, 3, 4, 5};
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(vec.begin(), vec.end(), g);
    std::cout << "After shuffle: ";
    for (int x : vec) std::cout << x << " ";
    std::cout << "\n";
}

void STLAlgorithmsDemo::demonstratePartitionOperations() {
    std::cout << "\n=== Partition Operations ===\n";
    
    std::vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    auto pivot = std::partition(vec.begin(), vec.end(), [](int x) { return x % 2 == 0; });
    std::cout << "After partition (even first): ";
    for (int x : vec) std::cout << x << " ";
    std::cout << "\n";
    std::cout << "Pivot at position: " << (pivot - vec.begin()) << "\n";
}

void STLAlgorithmsDemo::demonstrateSortOperations() {
    std::cout << "\n=== Sort Operations ===\n";
    
    std::vector<int> vec = {64, 34, 25, 12, 22, 11, 90};
    std::cout << "Original: ";
    for (int x : vec) std::cout << x << " ";
    std::cout << "\n";
    
    std::sort(vec.begin(), vec.end());
    std::cout << "After sort(): ";
    for (int x : vec) std::cout << x << " ";
    std::cout << "\n";
    
    std::vector<int> vec2 = {64, 34, 25, 12, 22, 11, 90};
    std::stable_sort(vec2.begin(), vec2.end(), std::greater<int>());
    std::cout << "After stable_sort (descending): ";
    for (int x : vec2) std::cout << x << " ";
    std::cout << "\n";
}

void STLAlgorithmsDemo::demonstrateBinarySearchOperations() {
    std::cout << "\n=== Binary Search Operations ===\n";
    
    std::vector<int> vec = {1, 3, 5, 7, 9, 11, 13, 15};
    
    bool found = std::binary_search(vec.begin(), vec.end(), 7);
    std::cout << "binary_search(7): " << (found ? "found" : "not found") << "\n";
    
    auto lower = std::lower_bound(vec.begin(), vec.end(), 7);
    std::cout << "lower_bound(7): position " << (lower - vec.begin()) << "\n";
    
    auto upper = std::upper_bound(vec.begin(), vec.end(), 7);
    std::cout << "upper_bound(7): position " << (upper - vec.begin()) << "\n";
}

void STLAlgorithmsDemo::demonstrateMergeOperations() {
    std::cout << "\n=== Merge Operations ===\n";
    
    std::vector<int> vec1 = {1, 3, 5, 7};
    std::vector<int> vec2 = {2, 4, 6, 8};
    std::vector<int> result;
    
    std::merge(vec1.begin(), vec1.end(), vec2.begin(), vec2.end(), 
               std::back_inserter(result));
    std::cout << "After merge: ";
    for (int x : result) std::cout << x << " ";
    std::cout << "\n";
}

void STLAlgorithmsDemo::demonstrateHeapOperations() {
    std::cout << "\n=== Heap Operations ===\n";
    
    std::vector<int> vec = {3, 1, 4, 1, 5, 9, 2, 6};
    
    std::make_heap(vec.begin(), vec.end());
    std::cout << "After make_heap: ";
    for (int x : vec) std::cout << x << " ";
    std::cout << "\n";
    
    vec.push_back(8);
    std::push_heap(vec.begin(), vec.end());
    std::cout << "After push_heap(8): ";
    for (int x : vec) std::cout << x << " ";
    std::cout << "\n";
    
    std::pop_heap(vec.begin(), vec.end());
    vec.pop_back();
    std::cout << "After pop_heap: ";
    for (int x : vec) std::cout << x << " ";
    std::cout << "\n";
}

void STLAlgorithmsDemo::demonstrateMinMaxOperations() {
    std::cout << "\n=== Min/Max Operations ===\n";
    
    std::vector<int> vec = {3, 1, 4, 1, 5, 9, 2, 6};
    
    auto min_elem = std::min_element(vec.begin(), vec.end());
    auto max_elem = std::max_element(vec.begin(), vec.end());
    
    std::cout << "Min element: " << *min_elem << " at position " << (min_elem - vec.begin()) << "\n";
    std::cout << "Max element: " << *max_elem << " at position " << (max_elem - vec.begin()) << "\n";
    
    auto minmax = std::minmax_element(vec.begin(), vec.end());
    std::cout << "MinMax: [" << *minmax.first << ", " << *minmax.second << "]\n";
}

void STLAlgorithmsDemo::demonstrateNumericOperations() {
    std::cout << "\n=== Numeric Operations ===\n";
    
    std::vector<int> vec = {1, 2, 3, 4, 5};
    
    int sum = std::accumulate(vec.begin(), vec.end(), 0);
    std::cout << "Sum (accumulate): " << sum << "\n";
    
    int product = std::accumulate(vec.begin(), vec.end(), 1, std::multiplies<int>());
    std::cout << "Product: " << product << "\n";
    
    std::vector<int> partial_sums(vec.size());
    std::partial_sum(vec.begin(), vec.end(), partial_sums.begin());
    std::cout << "Partial sums: ";
    for (int x : partial_sums) std::cout << x << " ";
    std::cout << "\n";
    
    std::vector<int> sequence(10);
    std::iota(sequence.begin(), sequence.end(), 1);
    std::cout << "Iota sequence (1-10): ";
    for (int x : sequence) std::cout << x << " ";
    std::cout << "\n";
}

void STLAlgorithmsDemo::demonstrateSetOperations() {
    std::cout << "\n=== Set Operations ===\n";
    
    std::vector<int> set1 = {1, 2, 3, 4, 5};
    std::vector<int> set2 = {3, 4, 5, 6, 7};
    
    std::vector<int> union_result;
    std::set_union(set1.begin(), set1.end(), set2.begin(), set2.end(), 
                   std::back_inserter(union_result));
    std::cout << "Union: ";
    for (int x : union_result) std::cout << x << " ";
    std::cout << "\n";
    
    std::vector<int> intersection_result;
    std::set_intersection(set1.begin(), set1.end(), set2.begin(), set2.end(),
                         std::back_inserter(intersection_result));
    std::cout << "Intersection: ";
    for (int x : intersection_result) std::cout << x << " ";
    std::cout << "\n";
}

void STLAlgorithmsDemo::demonstrateCustomPredicates() {
    std::cout << "\n=== Custom Predicates ===\n";
    
    std::vector<std::string> words = {"apple", "banana", "cherry", "date"};
    
    auto it = std::find_if(words.begin(), words.end(), 
                          [](const std::string& s) { return s.length() > 5; });
    if (it != words.end()) {
        std::cout << "First word longer than 5 chars: " << *it << "\n";
    }
    
    int count = std::count_if(words.begin(), words.end(),
                             [](const std::string& s) { return s[0] == 'a'; });
    std::cout << "Words starting with 'a': " << count << "\n";
}

void STLAlgorithmsDemo::demonstrateFunctionObjects() {
    std::cout << "\n=== Function Objects ===\n";
    
    std::vector<int> vec = {5, 2, 8, 1, 9};
    
    std::sort(vec.begin(), vec.end(), std::greater<int>());
    std::cout << "Sorted descending (greater): ";
    for (int x : vec) std::cout << x << " ";
    std::cout << "\n";
    
    std::vector<int> vec2 = {1, 2, 3, 4, 5};
    std::transform(vec2.begin(), vec2.end(), vec2.begin(), std::negate<int>());
    std::cout << "After negate: ";
    for (int x : vec2) std::cout << x << " ";
    std::cout << "\n";
}

void STLAlgorithmsDemo::demonstrateAll() {
    std::cout << "\n" << std::string(60, '=') << "\n";
    std::cout << "COMPREHENSIVE STL ALGORITHMS DEMONSTRATION\n";
    std::cout << std::string(60, '=') << "\n";
    
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
    std::cout << "\n=== Input Iterators ===\n";
    std::cout << "* Read-only, single-pass iterators\n";
    std::cout << "* Example: std::istream_iterator\n";
}

void STLIteratorsDemo::demonstrateOutputIterators() {
    std::cout << "\n=== Output Iterators ===\n";
    std::cout << "* Write-only, single-pass iterators\n";
    std::cout << "* Example: std::ostream_iterator\n";
}

void STLIteratorsDemo::demonstrateForwardIterators() {
    std::cout << "\n=== Forward Iterators ===\n";
    std::cout << "* Read/write, multi-pass, forward-only\n";
    std::cout << "* Example: std::forward_list iterators\n";
}

void STLIteratorsDemo::demonstrateBidirectionalIterators() {
    std::cout << "\n=== Bidirectional Iterators ===\n";
    std::cout << "* Forward + backward movement\n";
    std::cout << "* Example: std::list, std::set iterators\n";
}

void STLIteratorsDemo::demonstrateRandomAccessIterators() {
    std::cout << "\n=== Random Access Iterators ===\n";
    std::cout << "* All operations + random access\n";
    std::cout << "* Example: std::vector, std::array iterators\n";
}

void STLIteratorsDemo::demonstrateReverseIterators() {
    std::cout << "\n=== Reverse Iterators ===\n";
    std::vector<int> vec = {1, 2, 3, 4, 5};
    std::cout << "* Vector: ";
    for (const auto& elem : vec) std::cout << elem << " ";
    std::cout << "\n* Reverse: ";
    for (auto it = vec.rbegin(); it != vec.rend(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n";
}

void STLIteratorsDemo::demonstrateInsertIterators() {
    std::cout << "\n=== Insert Iterators ===\n";
    std::vector<int> vec = {1, 2, 3};
    std::vector<int> result;
    
    std::copy(vec.begin(), vec.end(), std::back_inserter(result));
    std::cout << "* After back_inserter copy: ";
    for (const auto& elem : result) std::cout << elem << " ";
    std::cout << "\n";
}

void STLIteratorsDemo::demonstrateStreamIterators() {
    std::cout << "\n=== Stream Iterators ===\n";
    std::vector<int> vec = {10, 20, 30, 40, 50};
    std::cout << "* Vector output with ostream_iterator: ";
    std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << "\n";
}

void STLIteratorsDemo::demonstrateIteratorOperations() {
    std::cout << "\n=== Iterator Operations ===\n";
    std::vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    auto it = vec.begin();
    std::advance(it, 3);
    std::cout << "* After advance(3): " << *it << "\n";
    
    auto distance = std::distance(vec.begin(), it);
    std::cout << "* Distance from begin: " << distance << "\n";
}

void STLIteratorsDemo::demonstrateIteratorTraits() {
    std::cout << "\n=== Iterator Traits ===\n";
    std::cout << "* Iterator traits provide type information\n";
    std::cout << "* Used by algorithms to optimize for iterator types\n";
    std::cout << "* Example: std::iterator_traits<Iterator>::iterator_category\n";
}

void STLIteratorsDemo::demonstrateCustomIterators() {
    std::cout << "\n=== Custom Iterators ===\n";
    std::cout << "* Range-based custom iterator example:\n";
    
    std::cout << "* Range(1, 10, 2): ";
    for (int i = 1; i < 10; i += 2) {
        std::cout << i << " ";
    }
    std::cout << "\n";
}

void STLIteratorsDemo::demonstrateAll() {
    std::cout << "\n" << std::string(60, '=') << "\n";
    std::cout << "COMPREHENSIVE STL ITERATORS DEMONSTRATION\n";
    std::cout << std::string(60, '=') << "\n";
    
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
    std::cout << "\n=== Two Sum Problem ===\n";
    std::cout << "Problem: Find two numbers that add up to target\n";
    
    std::vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    
    std::unordered_map<int, int> num_to_index;
    std::cout << "Input: [";
    for (size_t i = 0; i < nums.size(); ++i) {
        std::cout << nums[i];
        if (i < nums.size() - 1) std::cout << ", ";
    }
    std::cout << "], target = " << target << "\n";
    
    for (size_t i = 0; i < nums.size(); ++i) {
        int complement = target - nums[i];
        if (num_to_index.find(complement) != num_to_index.end()) {
            std::cout << "Result: indices [" << num_to_index[complement] << ", " << i << "]\n";
            return;
        }
        num_to_index[nums[i]] = i;
    }
    std::cout << "No solution found\n";
}

void STLInterviewQuestions::topKFrequentElements() {
    std::cout << "\n=== Top K Frequent Elements ===\n";
    std::cout << "Problem: Find k most frequent elements\n";
    
    std::vector<int> nums = {1, 1, 1, 2, 2, 3};
    int k = 2;
    
    std::cout << "Input: [";
    for (size_t i = 0; i < nums.size(); ++i) {
        std::cout << nums[i];
        if (i < nums.size() - 1) std::cout << ", ";
    }
    std::cout << "], k = " << k << "\n";
    
    std::unordered_map<int, int> freq;
    for (int num : nums) {
        freq[num]++;
    }
    
    auto comp = [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
        return a.second > b.second;
    };
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, decltype(comp)> pq(comp);
    
    for (const auto& p : freq) {
        pq.push({p.first, p.second});
        if (pq.size() > static_cast<size_t>(k)) {
            pq.pop();
        }
    }
    
    std::vector<int> result;
    while (!pq.empty()) {
        result.push_back(pq.top().first);
        pq.pop();
    }
    
    std::cout << "Result: [";
    for (size_t i = 0; i < result.size(); ++i) {
        std::cout << result[i];
        if (i < result.size() - 1) std::cout << ", ";
    }
    std::cout << "]\n";
}

void STLInterviewQuestions::vectorVsList() {
    std::cout << "\n=== Vector vs List Performance ===\n";
    std::cout << "Comparing performance characteristics\n";
    
    const int N = 100000;
    
    auto start = std::chrono::high_resolution_clock::now();
    std::vector<int> vec;
    vec.reserve(N);
    for (int i = 0; i < N; ++i) {
        vec.push_back(i);
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto vector_insert = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    
    start = std::chrono::high_resolution_clock::now();
    std::list<int> lst;
    for (int i = 0; i < N; ++i) {
        lst.push_back(i);
    }
    end = std::chrono::high_resolution_clock::now();
    auto list_insert = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    
    std::cout << "\nInsertion performance:\n";
    std::cout << "  Vector: " << vector_insert.count() << " us\n";
    std::cout << "  List: " << list_insert.count() << " us\n";
    
    start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < 1000; ++i) {
        volatile int x = vec[N/2];
        (void)x; // Suppress unused variable warning
    }
    end = std::chrono::high_resolution_clock::now();
    auto vector_access = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
    
    std::cout << "\nRandom access (1000 operations):\n";
    std::cout << "  Vector: " << vector_access.count() << " ns\n";
    std::cout << "  List: Not supported (no random access)\n";
    
    std::cout << "\nKey differences:\n";
    std::cout << "* Vector: O(1) random access, O(1) amortized push_back\n";
    std::cout << "* List: O(1) insertion/deletion anywhere, O(n) access\n";
    std::cout << "* Vector: Better cache locality due to contiguous memory\n";
    std::cout << "* List: No reallocation, stable iterators\n";
}

void STLInterviewQuestions::demonstrateAll() {
    std::cout << "\n" << std::string(60, '=') << "\n";
    std::cout << "STL INTERVIEW QUESTIONS DEMONSTRATION\n";
    std::cout << std::string(60, '=') << "\n";
    
    findTwoSum();
    topKFrequentElements();
    vectorVsList();
}

// =============================================================================
// STL BEST PRACTICES
// =============================================================================

void STLBestPractices::demonstrateAll() {
    std::cout << "\n" << std::string(60, '=') << "\n";
    std::cout << "STL BEST PRACTICES DEMONSTRATION\n";
    std::cout << std::string(60, '=') << "\n";
    
    std::cout << "\n=== Container Selection Guide ===\n";
    std::cout << "* std::vector: Default choice, contiguous memory\n";
    std::cout << "* std::list: Frequent insertion/deletion in middle\n";
    std::cout << "* std::deque: Insertion/deletion at both ends\n";
    std::cout << "* std::set: Sorted unique elements\n";
    std::cout << "* std::unordered_set: Fast lookup, no ordering\n";
    
    std::cout << "\n=== Performance Tips ===\n";
    std::cout << "* Use reserve() for vectors when size is known\n";
    std::cout << "* Prefer emplace over insert for efficiency\n";
    std::cout << "* Use move semantics for large objects\n";
    std::cout << "* Choose algorithms over raw loops\n";
    
    std::cout << "\n=== Memory Management ===\n";
    std::cout << "* Use shrink_to_fit() to release unused capacity\n";
    std::cout << "* Consider memory layout: vector > deque > list\n";
    std::cout << "* Avoid frequent reallocations\n";
    
    std::cout << "\n=== Modern C++ Features ===\n";
    std::cout << "* Use auto for type deduction\n";
    std::cout << "* Range-based for loops\n";
    std::cout << "* Lambda expressions\n";
    std::cout << "* Smart pointers for RAII\n";
}

// =============================================================================
// TEMPLATE HELPER FUNCTIONS
// =============================================================================

template<typename Container>
void STLContainersDemo::printContainer(const Container& container, const std::string& name) {
    std::cout << name << ": ";
    for (const auto& elem : container) {
        std::cout << elem << " ";
    }
    std::cout << "\n";
}

// Explicit template instantiations
template void STLContainersDemo::printContainer<std::vector<int>>(const std::vector<int>&, const std::string&);
template void STLContainersDemo::printContainer<std::array<int, 5>>(const std::array<int, 5>&, const std::string&);
template void STLContainersDemo::printContainer<std::deque<int>>(const std::deque<int>&, const std::string&);
template void STLContainersDemo::printContainer<std::list<int>>(const std::list<int>&, const std::string&);
template void STLContainersDemo::printContainer<std::set<int>>(const std::set<int>&, const std::string&);
template void STLContainersDemo::printContainer<std::multiset<int>>(const std::multiset<int>&, const std::string&);
template void STLContainersDemo::printContainer<std::unordered_set<int>>(const std::unordered_set<int>&, const std::string&);

} // namespace CppBasics 
