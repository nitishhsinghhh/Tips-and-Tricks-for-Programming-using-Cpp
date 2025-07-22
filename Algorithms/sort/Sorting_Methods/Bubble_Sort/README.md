# What is Bubble Sort?
Bubble Sort is a simple comparison-based sorting algorithm. It works by repeatedly swapping adjacent elements if they are in the wrong order. This process is continued until the entire array is sorted.

# Key Characteristics
- Time Complexity: Worst-case is O(n^2); Best-case is O(n) (if already sorted)
- Space Complexity: $$O(1)$$ (in-place sorting)
- Stable Sort: Yes
- Simple but Inefficient for Large Arrays

## C++ Code  
```cpp
#include <iostream>
#include <vector>
#include <algorithm>

/**
 * @brief Interface for sorting strategies.
 */
class ISortStrategy {
public:
    /**
     * @brief Pure virtual method to sort a collection of integers.
     * @param numbers Reference to the vector to be sorted.
     */
    virtual void sort(std::vector<int>& numbers) = 0;

    /// Virtual destructor for safe polymorphic usage.
    virtual ~ISortStrategy() = default;
};

/**
 * @brief Concrete implementation of bubble sort algorithm.
 */
class BubbleSort : public ISortStrategy {
public:
    /**
     * @brief Sorts the given vector of integers using bubble sort.
     * @param numbers Reference to the vector to be sorted.
     */
    void sort(std::vector<int>& numbers) override {
        int size = static_cast<int>(numbers.size());
        if (size <= 1)
            return;

        for (int endIndex = size - 1; endIndex > 0; --endIndex) 
            for (int currentIndex = 0; currentIndex < endIndex; ++currentIndex) 
                if (numbers[currentIndex] > numbers[currentIndex + 1]) 
                    std::swap(numbers[currentIndex], numbers[currentIndex + 1]);        
    }
};

/**
 * @brief Utility class for handling and printing integer vectors.
 */
class NumberHandler {
public:
    /**
     * @brief Prints the elements of a vector separated by spaces.
     * @param numbers The vector to be printed.
     */
    void print(const std::vector<int>& numbers) const {
        for (int number : numbers)
            std::cout << number << " ";
        std::cout << std::endl;
    }
};

/**
 * @brief Main application that uses a sorting strategy to sort numbers.
 */
class SortApplication {
private:
    ISortStrategy* sorter;
    NumberHandler printer;

public:
    /**
     * @brief Constructor injecting a sorting strategy.
     * @param strategy Pointer to the sorting strategy to use.
     */
    SortApplication(ISortStrategy* strategy) : sorter(strategy) {}

    /**
     * @brief Executes the sorting process on a sample vector.
     */
    void run() {
        std::vector<int> numbers = {5, 2, 9, 3, 1, 6};

        std::cout << "Unsorted array: ";
        printer.print(numbers);

        sorter->sort(numbers);

        std::cout << "Sorted array: ";
        printer.print(numbers);
    }
};

/**
 * @brief Entry point of the program.
 * @return int Exit code.
 */
int main() {
    BubbleSort bubbleSortAlgorithm;
    SortApplication app(&bubbleSortAlgorithm);
    app.run();

    return 0;
}
```

# How It Works (Step-by-Step)
- Start from the beginning of the array.
- Compare adjacent elements: if the current one is greater than the next, swap them.
- Repeat this process for every element up to the end of the array.
- After each full pass, the largest unsorted element is pushed to the end, like a bubble rising.
- Reduce the pass length by one and repeat until no swaps are needed.

## How This Code Applies SOLID Principles

| Principle | Implementation Example                                               |
|-----------|----------------------------------------------------------------------|
| **S - SRP** | BubbleSort only sorts, NumberHandler only prints                |
| **O - OCP** | Add other sorting strategies by inheriting ISortStrategy         |
| **L - LSP** | BubbleSort properly substitutes ISortStrategy                  |
| **I - ISP** | ISortStrategy keeps interface minimal and relevant               |
| **D - DIP** | SortApplication depends on abstraction (ISortStrategy), not concrete class |

## Bubble Sort Progression Example

Sorting the array: `{5, 2, 9, 3, 1, 6}`

| Pass | Array State             | Largest Bubble to End |
|------|-------------------------|------------------------|
| 1    | 2, 5, 3, 1, 6, 9        | 9                      |
| 2    | 2, 3, 1, 5, 6, 9        | 6                      |
| 3    | 2, 1, 3, 5, 6, 9        | 5                      |
| 4    | 1, 2, 3, 5, 6, 9        | 3                      |
| 5    | Already sorted          | —                      |

## ## ⚖️ Bubble Sort: Pros and Cons

|   Pros                        |    Cons                           |
|-------------------------------|-----------------------------------|
| Simple to understand          | Slow for large datasets           |
| Easy to implement             | High time complexity (O(n^2)) |
| Works well for small arrays   | Not suitable for performance apps |

## Why Learn Bubble Sort in Competitive Programming?
Even though it's not performant for big problems, bubble sort helps you understand:

- Fundamentals of algorithm design (loops, swaps, comparisons)
- Problem constraints where inefficient algorithms can still work (e.g., small inputs)
- Edge case handling (like duplicates, single elements, reverse-sorted arrays)

- ## Where Bubble Sort Might Be Useful

| Use Case                      | Why It Works                                      |
|------------------------------|---------------------------------------------------|
| Small input size problems     | Time complexity isn't a deal-breaker              |
| Teaching/debugging environments | Easy to visualize and trace step-by-step       |
| Custom logic inside swapping  | You can modify the algorithm easily for variants |
| Contest warm-up problems      | Quick to implement under pressure                |

## Competitive Tip
Even if you don't use it in final solutions, understanding bubble sort helps you appreciate how more advanced sorting algorithms work and what optimizations matter.

