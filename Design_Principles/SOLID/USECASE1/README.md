# Search Algorithm Example

This repository contains a simple example of implementing and using different search algorithms in C++ with object-oriented programming principles. The example includes two search algorithms: **Linear Search** and **Binary Search**. The code uses a factory pattern to create instances of the desired search algorithm dynamically.

## Table of Contents

- [Introduction](#introduction)
- [Project Structure](#project-structure)
- [How It Works](#how-it-works)
  - [Linear Search](#linear-search)
  - [Binary Search](#binary-search)
  - [Factory Class](#factory-class)
- [Usage](#usage)
- [Compilation](#compilation)
- [Contributing](#contributing)
- [License](#license)

## Introduction

This project demonstrates how to implement a base class for search algorithms and derive specific search algorithms (like Linear Search and Binary Search) from it. It also showcases the **Factory Design Pattern** to easily create instances of different search algorithms based on user input.

## Project Structure

The project consists of the following key components:

- **SearchAlgorithmBase**: An abstract base class defining the interface for search algorithms.
- **LinearSearch**: A derived class implementing linear search.
- **BinarySearch**: A derived class implementing binary search.
- **SearchAlgorithmFactory**: A factory class responsible for creating instances of search algorithms.

## How It Works

### Linear Search

Linear search goes through each element of an array sequentially and checks if it matches the target value. If the target is found, the index is returned; otherwise, `-1` is returned.

```cpp
int search(const std::vector<int>& arr, int target) const override {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == target) {
            return i; // Target found
        }
    }
    return -1; // Target not found
}
```

### Binary Search
Binary search works on sorted arrays. It repeatedly divides the array into two halves and checks whether the middle element is the target. It then either narrows the search to the left or right half depending on the comparison.

```cpp
int search(const std::vector<int>& arr, int target) const override {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) 
            return mid; // Target found
        else if (arr[mid] < target) 
            left = mid + 1; // Discard left half
        else 
            right = mid - 1; // Discard right half
    }

    return -1; // Target not found
}
```

### Factory Class
The SearchAlgorithmFactory class is responsible for creating instances of the SearchAlgorithmBase derived classes based on the input.

```cpp
static std::unique_ptr<SearchAlgorithmBase> createSearchAlgorithm(SearchAlgorithm algorithm) {
    switch (algorithm) {
        case SearchAlgorithm::Linear:
            return std::make_unique<LinearSearch>();
        case SearchAlgorithm::Binary:
            return std::make_unique<BinarySearch>();
        default:
            std::cerr << "Invalid search algorithm requested." << std::endl;
            return nullptr;
    }
}
```
This allows for flexibility in selecting the desired algorithm at runtime.

### Usage

To use the code:

Define the data you want to search through, as well as the target element you want to find.
Use the SearchAlgorithmFactory to create an instance of either LinearSearch or BinarySearch.
Call the search method to perform the search.

### Example

```cpp
std::vector<int> sortedData { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
std::vector<int> unsortedData { 5, 2, 8, 1, 9, 3, 4, 7, 6, 10 };
int target = 7;

// Create search algorithms using the factory
auto linearSearch = SearchAlgorithmFactory::createSearchAlgorithm(SearchAlgorithm::Linear);
auto binarySearch = SearchAlgorithmFactory::createSearchAlgorithm(SearchAlgorithm::Binary);

// Perform search
int linearResult = linearSearch->search(unsortedData, target);  // Linear search on unsorted data
int binaryResult = binarySearch->search(sortedData, target);    // Binary search on sorted data

std::cout << "Linear Search Result: " << linearResult << std::endl;
std::cout << "Binary Search Result: " << binaryResult << std::endl;
```

#### Compilation

To compile and run the code, follow these steps:

1. Make sure you have a C++ compiler installed (e.g., g++).
2. Download or clone the repository.
3. Use the following command to compile the program:
```
bash
g++ -std=c++11 -o search search.cpp
```
4. Run the program:
```
bash
./search
```

#### Contributing

Contributions are welcome! If you have any suggestions or improvements, feel free to open an issue or submit a pull request.
