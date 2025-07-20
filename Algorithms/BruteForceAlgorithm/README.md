# Brute Force Algorithm Collection

This repository contains simple brute force algorithms written in C++ to help beginners understand basic algorithm design and problem-solving techniques.

## Overview

Brute force algorithms solve problems by checking all possible solutions. Though not always efficient, this approach is important for building foundational understanding in algorithm development.

The code in this repository includes examples such as:
- Prime number detection within a range
- Simple linear and nested loop problems
- Brute force string matching
- Base cases for backtracking problems

### Prime Number Detection Within a Range
```cpp
/**
 * @file prime_number_bruteforce.cpp
 * @brief Brute force algorithm to find all prime numbers in a given range.
 */

#include <iostream>

/**
 * @brief Checks if a number is prime using brute force.
 * @param n The number to check.
 * @return true if n is prime, false otherwise.
 */
bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i < n; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

/**
 * @brief Main function to find prime numbers in a user-defined range.
 */
int main() {
    int start, end;
    std::cout << "Enter the range (start and end): ";
    std::cin >> start >> end;

    std::cout << "Prime numbers between " << start << " and " << end << " are: ";
    for (int i = start; i <= end; ++i) {
        if (isPrime(i)) std::cout << i << " ";
    }
    std::cout << std::endl;
    return 0;
}
```

### Simple Linear and Nested Loop Problem (Sum of Pairs)
```cpp
/**
 * @file sum_of_pairs.cpp
 * @brief Brute force example to find all pairs that sum to a target.
 */

#include <iostream>
#include <vector>

/**
 * @brief Finds and prints all pairs of elements that sum to a given target.
 * @param arr The input vector.
 * @param target The target sum.
 */
void findPairs(const std::vector<int>& arr, int target) {
    for (size_t i = 0; i < arr.size(); ++i) {
        for (size_t j = i + 1; j < arr.size(); ++j) {
            if (arr[i] + arr[j] == target) {
                std::cout << "(" << arr[i] << ", " << arr[j] << ")\n";
            }
        }
    }
}

/**
 * @brief Main function.
 */
int main() {
    std::vector<int> numbers = {1, 3, 5, 2, 4, 6};
    int target = 7;
    std::cout << "Pairs summing to " << target << ":\n";
    findPairs(numbers, target);
    return 0;
}

```

### Brute Force String Matching
```cpp
/**
 * @file string_match.cpp
 * @brief Brute force approach to find substring matches.
 */

#include <iostream>
#include <string>

/**
 * @brief Searches for a pattern in a text using brute force.
 * @param text The main text to search in.
 * @param pattern The pattern to find.
 */
void searchPattern(const std::string& text, const std::string& pattern) {
    int n = text.size();
    int m = pattern.size();

    for (int i = 0; i <= n - m; ++i) {
        int j = 0;
        while (j < m && text[i + j] == pattern[j]) {
            ++j;
        }
        if (j == m) {
            std::cout << "Pattern found at index " << i << "\n";
        }
    }
}

/**
 * @brief Main function.
 */
int main() {
    std::string text = "bruteforcebrutematch";
    std::string pattern = "brute";
    searchPattern(text, pattern);
    return 0;
}
```

### Base Case for Backtracking (N-Queens Problem with 1 Queen)

```
/**
 * @file one_queen_board.cpp
 * @brief Base case for N-Queens problem using brute force for 1 queen.
 */

#include <iostream>

/**
 * @brief Checks if placing a queen at (row, col) is safe.
 * @param board The chessboard.
 * @param row Current row index.
 * @param col Current column index.
 * @return true if safe, false otherwise.
 */
bool isSafe(int board[1][1], int row, int col) {
    // Only one cell, always safe
    return true;
}

/**
 * @brief Attempts to solve the N-Queens problem for 1 queen.
 */
void solveNQueens() {
    int board[1][1] = {0};

    if (isSafe(board, 0, 0)) {
        board[0][0] = 1;
        std::cout << "Solution found:\n";
        std::cout << board[0][0] << "\n";
    } else {
        std::cout << "No solution\n";
    }
}

/**
 * @brief Main function.
 */
int main() {
    solveNQueens();
    return 0;
}
```

### Brute Force Algorithm to Find Prime Numbers in a Given Range Using C Plus Plus

```cpp
#include <iostream>

/**
 * @brief Checks whether a number is prime using brute-force method.
 * 
 * @param n Integer to check.
 * @return true if n is prime, false otherwise.
 */
bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i < n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

/**
 * @brief Main function to read range from user and print all prime numbers in that range.
 * 
 * @return int Exit code.
 */
int main() {
    int start, end;

    std::cout << "Enter the range (start and end): ";
    std::cin >> start >> end;

    std::cout << "Prime numbers between " << start << " and " << end << " are: ";

    for (int i = start; i <= end; i++) {
        if (isPrime(i)) {
            std::cout << i << " ";
        }
    }

    std::cout << std::endl;
    return 0;
}
```






