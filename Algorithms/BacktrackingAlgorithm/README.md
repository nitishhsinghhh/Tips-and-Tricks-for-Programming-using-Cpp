# Backtracking Algorithms

Backtracking is a problem-solving algorithm that employs a brute force approach to finding the desired output. By trying out all possible solutions and choosing the best one, this method is effective for solving problems with multiple solutions. The term "backtracking" implies that if the current solution is unsuitable, the algorithm backtracks and explores other solutions, often utilizing recursion. Backtracking algorithms are problem-solving strategies that involve exploring different options until the best solution is found. They work by attempting different paths and backtracking if necessary, akin to solving a puzzle by testing different pieces until they fit together perfectly.

## How Backtracking Works

1. Build a solution step by step.
2. At each step, test whether the current partial solution is still valid.
3. If it's invalid, **backtrack** (go one step back).
4. If it's valid, continue building the solution.
5. If a full valid solution is found, record it.

---

## State Space Tree
A space state tree is a tree representing all the possible states (solution or nonsolution) of the problem from the root as an initial state to the leaf as a terminal state.

![image](https://github.com/nitishhsinghhh/Tips-and-Tricks-for-Programming-using-Cpp/assets/93253740/72e2e3da-b5a3-4d81-9149-7358a76639af)

## Backtracking Algorithm
```cpp
Backtrack(x)
    if x is not a solution
        return false
    if x is a new solution
        add to list of solutions
    backtrack(expand x)
```

## Example Backtracking Approach

```
Problem: You want to find all the possible ways of arranging 2 boys and 1 girl on 3 benches. Constraint: Girl should not be on the middle bench.
```
```
Solution: There are a total of 3! = 6 possibilities. We will try all the possibilities and get the possible solutions. We recursively try all the possibilities.
```
All the possibilities are:
<br>
The following state space tree shows the possible solutions.

![image](https://github.com/nitishhsinghhh/Tips-and-Tricks-for-Programming-using-Cpp/assets/93253740/a8201900-13e2-4e1d-be1b-11bc08c5db74)

##  Code Example in C++
```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isValid(const vector<string>& arrangement) {
    return arrangement[1] != "G"; // Girl not on middle bench
}

int main() {
    vector<string> people = {"B1", "B2", "G"};
    vector<vector<string>> validArrangements;

    sort(people.begin(), people.end());
    do {
        if (isValid(people)) {
            validArrangements.push_back(people);
        }
    } while (next_permutation(people.begin(), people.end()));

    // Output valid arrangements
    for (const auto& arrangement : validArrangements) {
        for (const auto& person : arrangement) {
            cout << person << " ";
        }
        cout << endl;
    }

    return 0;
}

```

# N-Queens Problem using Backtracking in C++

```cpp
/*
/**
 * @file n_queens.cpp
 * @author Nitish Singh
 * @email me.singhnitish@yandex.com
 * @brief This program demonstrates the use of a backtracking algorithm to solve the N-Queens problem.
 * @details The goal is to place N queens on an N x N chessboard such that no two queens attack each other.
 * It uses a recursive backtracking approach and prints the solution if one exists.
 */

#include <iostream>
#include <vector>

/**
 * @brief Checks if it's safe to place a queen at board[row][col].
 * 
 * @param board The current state of the chessboard.
 * @param row The row where the queen is to be placed.
 * @param col The column where the queen is to be placed.
 * @return true if it's safe to place the queen.
 * @return false if placing the queen leads to a conflict.
 */
bool isSafe(std::vector<std::vector<int>>& board, int row, int col) {
    // Check same column
    for (int i = 0; i < row; i++) 
        if (board[i][col] == 1) 
            return false;

    // Check upper left diagonal
    int i = row, j = col;
    while (i >= 0 && j >= 0) {
        if (board[i][j] == 1) {
            return false;
        }
        i--;
        j--;
    }

    // Check upper right diagonal
    i = row, j = col;
    while (i >= 0 && j < board.size()) {
        if (board[i][j] == 1) {
            return false;
        }
        i--;
        j++;
    }

    return true;
}

/**
 * @brief Attempts to place queens on the board using backtracking.
 * 
 * @param board The current state of the chessboard.
 * @param row The current row where we want to place a queen.
 * @return true if a solution is found.
 * @return false if no solution exists from this state.
 */
bool solveNQueens(std::vector<std::vector<int>>& board, int row) {
    // Base case: all queens have been placed
    if (row >= board.size()) 
        return true;

    // Try placing queen in all columns of current row
    for (int col = 0; col < board.size(); col++) {
        if (isSafe(board, row, col)) {
            board[row][col] = 1;

            // Recursively place the rest of the queens
            if (solveNQueens(board, row + 1)) 
                return true;

            // Backtrack
            board[row][col] = 0;
        }
    }
    return false;
}

/**
 * @brief Main function to accept board size and solve the N-Queens problem.
 * 
 * @return int Exit status.
 */
int main() {
    int num;
    std::cout << "Enter the size of the chessboard (num): ";
    std::cin >> num;

    std::vector<std::vector<int>> board(num, std::vector<int>(num, 0));

    if (solveNQueens(board, 0)) {
        std::cout << "Solution found:" << std::endl;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board.size(); j++) 
                std::cout << board[i][j] << " ";
            std::cout << std::endl;
        }
    }
    else {
        std::cout << "No solution found." << std::endl;
    }

    return 0;
}

```




