#pragma once

#include <iostream>
#include <vector>
#include <array>
#include <deque>
#include <list>
#include <forward_list>
#include <stack>
#include <queue> 
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <numeric>
#include <functional>
#include <iterator>
#include <memory>
#include <chrono>
#include <random>
#include <mutex>
#include <thread>

namespace CppBasics {

// =============================================================================
// STL CONTAINERS AND ALGORITHMS
// =============================================================================

class STLContainersDemo {
public:
    // Sequence Containers
    static void demonstrateVector();
    static void demonstrateArray();
    static void demonstrateDeque();
    static void demonstrateList();
    static void demonstrateForwardList();
    
    // Container Adapters
    static void demonstrateStack();
    static void demonstrateQueue();
    static void demonstratePriorityQueue();
    
    // Associative Containers
    static void demonstrateSet();
    static void demonstrateMultiset();
    static void demonstrateMap();
    static void demonstrateMultimap();
    
    // Unordered Associative Containers
    static void demonstrateUnorderedSet();
    static void demonstrateUnorderedMap();
    
    // Container Comparison and Performance
    static void compareContainerPerformance();
    static void demonstrateContainerChoice();
    
    // Performance testing
    static void performanceTest();
    
    // Complete demonstration
    static void demonstrateAll();

private:
    template<typename Container>
    static void printContainer(const Container& c, const std::string& name);
};

class STLAlgorithmsDemo {
public:
    // Non-modifying sequence operations
    static void demonstrateFindOperations();
    static void demonstrateCountOperations();
    static void demonstrateSearchOperations();
    
    // Modifying sequence operations
    static void demonstrateCopyOperations();
    static void demonstrateTransformOperations();
    static void demonstrateReplaceOperations();
    static void demonstrateRemoveOperations();
    static void demonstrateReverseRotateOperations();
    static void demonstrateShuffleOperations();
    
    // Partitioning operations
    static void demonstratePartitionOperations();
    
    // Sorting operations
    static void demonstrateSortOperations();
    static void demonstrateBinarySearchOperations();
    static void demonstrateMergeOperations();
    static void demonstrateHeapOperations();
    
    // Min/max operations
    static void demonstrateMinMaxOperations();
    
    // Numeric operations
    static void demonstrateNumericOperations();
    
    // Set operations (on sorted ranges)
    static void demonstrateSetOperations();
    
    // Custom predicates and function objects
    static void demonstrateCustomPredicates();
    static void demonstrateFunctionObjects();
    
    // Complete demonstration
    static void demonstrateAll();

private:
    // Helper structures for demonstrations
    struct Person {
        std::string name;
        int age;
        
        Person(const std::string& n, int a) : name(n), age(a) {}
        
        bool operator<(const Person& other) const { return age < other.age; }
        bool operator==(const Person& other) const { return name == other.name && age == other.age; }
        
        friend std::ostream& operator<<(std::ostream& os, const Person& p) {
            return os << "{" << p.name << ", " << p.age << "}";
        }
    };
    
    // Custom predicates
    struct IsEven {
        bool operator()(int n) const { return n % 2 == 0; }
    };
    
    struct IsOlderThan {
        int threshold;
        IsOlderThan(int t) : threshold(t) {}
        bool operator()(const Person& p) const { return p.age > threshold; }
    };
    
    template<typename Container>
    static void printContainer(const Container& c, const std::string& name);
};

class STLIteratorsDemo {
public:
    // Iterator categories
    static void demonstrateInputIterators();
    static void demonstrateOutputIterators();
    static void demonstrateForwardIterators();
    static void demonstrateBidirectionalIterators();
    static void demonstrateRandomAccessIterators();
    
    // Iterator adapters
    static void demonstrateReverseIterators();
    static void demonstrateInsertIterators();
    static void demonstrateStreamIterators();
    
    // Iterator operations
    static void demonstrateIteratorOperations();
    static void demonstrateIteratorTraits();
    
    // Custom iterators
    static void demonstrateCustomIterators();
    
    // Complete demonstration
    static void demonstrateAll();

private:
    // Custom iterator example
    template<typename T>
    class RangeIterator {
    private:
        T current;
        T step;
        
    public:
        using iterator_category = std::forward_iterator_tag;
        using value_type = T;
        using difference_type = std::ptrdiff_t;
        using pointer = T*;
        using reference = T&;
        
        RangeIterator(T start, T s = T(1)) : current(start), step(s) {}
        
        T operator*() const { return current; }
        RangeIterator& operator++() { current += step; return *this; }
        RangeIterator operator++(int) { RangeIterator temp = *this; ++(*this); return temp; }
        
        bool operator==(const RangeIterator& other) const { return current == other.current; }
        bool operator!=(const RangeIterator& other) const { return !(*this == other); }
    };
    
    template<typename T>
    class Range {
    private:
        T start_val, end_val, step_val;
        
    public:
        Range(T start, T end, T step = T(1)) : start_val(start), end_val(end), step_val(step) {}
        
        RangeIterator<T> begin() const { return RangeIterator<T>(start_val, step_val); }
        RangeIterator<T> end() const { return RangeIterator<T>(end_val, step_val); }
    };
};

class STLInterviewQuestions {
public:
    // Common interview problems using STL
    static void findTwoSum();
    static void findDuplicates();
    static void mergeSortedArrays();
    static void topKFrequentElements();
    static void validParentheses();
    static void longestCommonPrefix();
    static void groupAnagrams();
    static void intersectionOfArrays();
    static void kthLargestElement();
    static void reverseWordsInString();
    
    // Performance comparison questions
    static void vectorVsList();
    static void setVsUnorderedSet();
    static void mapVsUnorderedMap();
    static void arrayVsVector();
    
    // STL gotchas and common mistakes
    static void commonSTLMistakes();
    static void iteratorInvalidation();
    static void containerExceptionSafety();
    
    // Complete demonstration
    static void demonstrateAll();

private:
    // Helper functions
    template<typename T>
    static void printVector(const std::vector<T>& vec, const std::string& name);
    
    template<typename Container>
    static void benchmarkContainer(const std::string& name, std::function<void(Container&)> operation);
};

class STLBestPractices {
public:
    // Container selection guidelines
    static void containerSelectionGuide();
    static void whenToUseWhichContainer();
    
    // Performance best practices
    static void reserveAndCapacity();
    static void emplaceVsInsert();
    static void moveSemantics();
    static void algorithmComplexity();
    
    // Memory management
    static void memoryEfficiency();
    static void customAllocators();
    
    // Exception safety
    static void exceptionSafetyInSTL();
    static void strongExceptionGuarantee();
    
    // Modern C++ STL features
    static void modernSTLFeatures();
    static void rangeBasedAlgorithms();
    
    // Complete demonstration
    static void demonstrateAll();

private:
    // Performance measurement utilities
    template<typename Func>
    static double measureTime(Func&& f);
    
    template<typename Container>
    static void measureInsertionPerformance(const std::string& name);
    
    template<typename Container>
    static void measureSearchPerformance(const std::string& name);
};

// Utility classes for advanced STL usage
template<typename T>
class CircularBuffer {
private:
    std::vector<T> buffer;
    size_t head, tail, count, capacity;
    
public:
    explicit CircularBuffer(size_t size);
    
    void push(const T& item);
    void push(T&& item);
    T pop();
    
    bool empty() const { return count == 0; }
    bool full() const { return count == capacity; }
    size_t size() const { return count; }
    
    // Iterator support
    class iterator {
    private:
        CircularBuffer* buffer;
        size_t index;
        
    public:
        using iterator_category = std::forward_iterator_tag;
        using value_type = T;
        using difference_type = std::ptrdiff_t;
        using pointer = T*;
        using reference = T&;
        
        iterator(CircularBuffer* buf, size_t idx) : buffer(buf), index(idx) {}
        
        T& operator*() { return buffer->buffer[(buffer->head + index) % buffer->capacity]; }
        iterator& operator++() { ++index; return *this; }
        iterator operator++(int) { iterator temp = *this; ++(*this); return temp; }
        
        bool operator==(const iterator& other) const { return index == other.index; }
        bool operator!=(const iterator& other) const { return !(*this == other); }
    };
    
    iterator begin() { return iterator(this, 0); }
    iterator end() { return iterator(this, count); }
};

// Thread-safe container wrapper
template<typename Container>
class ThreadSafeContainer {
private:
    mutable std::mutex mtx;
    Container container;
    
public:
    template<typename... Args>
    ThreadSafeContainer(Args&&... args) : container(std::forward<Args>(args)...) {}
    
    template<typename... Args>
    auto insert(Args&&... args) -> decltype(container.insert(std::forward<Args>(args)...)) {
        std::lock_guard<std::mutex> lock(mtx);
        return container.insert(std::forward<Args>(args)...);
    }
    
    template<typename... Args>
    auto find(Args&&... args) -> decltype(container.find(std::forward<Args>(args)...)) {
        std::lock_guard<std::mutex> lock(mtx);
        return container.find(std::forward<Args>(args)...);
    }
    
    size_t size() const {
        std::lock_guard<std::mutex> lock(mtx);
        return container.size();
    }
    
    bool empty() const {
        std::lock_guard<std::mutex> lock(mtx);
        return container.empty();
    }
    
    // Safe iteration with callback
    template<typename Func>
    void for_each(Func&& f) const {
        std::lock_guard<std::mutex> lock(mtx);
        std::for_each(container.begin(), container.end(), std::forward<Func>(f));
    }
};

} // namespace CppBasics 
