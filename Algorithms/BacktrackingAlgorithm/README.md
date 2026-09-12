# Backtracking Algorithms

Backtracking is a systematic depth-first search technique for exploring a combinatorial search space. It incrementally constructs candidate solutions, rejects invalid partial states early, and restores the previous state when a branch cannot produce a valid solution.

```txt
Choose
   ↓
Apply choice
   ↓
Check constraint
   ↓
Invalid?
 ├── Yes → Undo → Return
 │
 └── No
      ↓
   Complete?
   ├── Yes → Record → Undo → Return
   │
   └── No
        ↓
      Recurse
        ↓
      Undo
```

Backtracking is therefore often a pruned form of exhaustive search, rather than simply "brute force."

## How Backtracking Works

1. Build a solution step by step.
2. At each step, test whether the current partial solution is still valid.
3. If it's invalid, **backtrack** (go one step back).
4. If it's valid, continue building the solution.
5. If a complete solution is reached, return it, record it, or evaluate it depending on the problem.

---

## State Space Tree

A state-space tree represents the sequence of decisions made while constructing candidate solutions. Each node represents a partial solution, each edge represents a decision, and leaves represent complete candidate solutions.

![image](https://github.com/nitishhsinghhh/Tips-and-Tricks-for-Programming-using-Cpp/assets/93253740/72e2e3da-b5a3-4d81-9149-7358a76639af)

## Backtracking Algorithm

```cpp
Backtrack(state):
    if state violates constraints:
        return

    if state is a complete solution:
        record state
        return

    for each possible choice:
        make choice
        Backtrack(state)
        undo choice
```

## Example Backtracking Approach

```sh
Problem: You want to find all the possible ways of arranging 2 boys and 1 girl on 3 benches. Constraint: Girl should not be on the middle bench.
```

```sh
Solution: There are 3! = 6 possible permutations. This example can be used to visualize the state-space tree. A permutation algorithm such as std::next_permutation enumerates the complete search space, whereas a backtracking implementation constructs permutations incrementally and can prune invalid partial arrangements before reaching a complete permutation.
```

All the possibilities are:

The following state space tree shows the possible solutions.

![image](https://github.com/nitishhsinghhh/Tips-and-Tricks-for-Programming-using-Cpp/assets/93253740/a8201900-13e2-4e1d-be1b-11bc08c5db74)

## Code Example in C++

Permutation generation provides the search space; backtracking provides the strategy for exploring that search space efficiently.

```cpp
/**
 * @file arrangement_permutation.cpp
 * @author Nitish Singh
 * @brief Brute-force permutation solver with positional constraints.
 * @version 0.1
 * @date 2026-04-27
 * * @copyright Copyright (c) 2026
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

/**
 * @brief Validates the seating arrangement based on specific social constraints.
 * * This function implements a constraint-check for a seating problem. 
 * The current business logic dictates that the character 'G' (Girl) 
 * cannot occupy the middle index of the arrangement.
 * * @param arrangement A vector of strings representing the sequence of people.
 * @return true If the arrangement satisfies the middle-bench constraint.
 * @return false If the arrangement violates the constraint (G is at index 1).
 */
bool isValid(const vector<string>& arrangement) {
    // Spatial Constraint: Index 1 represents the middle bench.
    return arrangement[1] != "G"; 
}

/**
 * @brief Main entry point for the arrangement solver.
 * * Utilizes the STL next_permutation to generate the state space and
 * filters valid states into a collection for output.
 * * @return int Standard exit code (0 for success).
 */
int main() {
    vector<string> people = {"B1", "B2", "G"};
    vector<vector<string>> validArrangements;

    // Sorting is a prerequisite for next_permutation to cover the entire state space.
    sort(people.begin(), people.end());
    
    do {
        if (isValid(people)) {
            validArrangements.push_back(people);
        }
    } while (next_permutation(people.begin(), people.end()));

    // Output valid arrangements to standard console
    for (const auto& arrangement : validArrangements) {
        for (const auto& person : arrangement) {
            cout << person << " ";
        }
        cout << endl;
    }

    return 0;
}
```

## N-Queens Problem using Backtracking in C++

```cpp
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

## Relationship Between Permutations and Backtracking

Permutation generation is closely related to backtracking because permutations naturally form a **state-space tree**.

For `N` elements, a permutation is constructed by making a sequence of choices:

```text
Choose the 1st element
        ↓
Choose the 2nd element
        ↓
Choose the 3rd element
        ↓
...
Complete permutation
```

For example, with:

```text
{B1, B2, G}
```

the search can begin with:

```text
                    {}
             /       |       \
           B1       B2        G
          /  \      /  \      /  \
        B2    G    B1   G    B1   B2
         |    |     |   |     |    |
         G    B2    G   B1    B2   B1
```

Each node represents a **partial permutation**, while each path from the root to a leaf represents a complete permutation.

This gives us an important relationship:

```text
Permutation Generation
        ↓
Defines the possible search space
        ↓
State-Space Tree
        ↓
Backtracking
        ↓
Explores the tree using
Choice → Constraint → Recursion → Undo
```

### Permutation Generation: Understanding the Search Space

This implementation does not use backtracking. It uses std::next_permutation() to enumerate the complete permutation space. We use it first to understand the search space that a backtracking algorithm can explore incrementally and prune.

We can generate all permutations using an algorithm such as:

```cpp
std::next_permutation()
```

For example:

```cpp
do {
    process(people);
} while (std::next_permutation(people.begin(), people.end()));
```

This enumerates the complete permutation space and then allows us to filter the results.

For three elements:

```text
3! = 6
```

possible permutations are generated.

However, this approach generally generates a **complete candidate before checking the constraint**.

### Permutation Generation With Backtracking

Backtracking builds the permutation incrementally.

```cpp
void backtrack(...)
{
    if (complete solution) {
        record solution;
        return;
    }

    for (each available element) {
        choose element;

        if (partial solution is valid) {
            backtrack(...);
        }

        undo choice;
    }
}
```

The important difference is **when the constraint is evaluated**.

With brute-force permutation generation:

```text
Generate complete permutation
        ↓
Check constraint
        ↓
Keep / discard
```

With backtracking:

```text
Make partial choice
        ↓
Check constraint
        ↓
Invalid? ───────→ Prune branch
        │
      Valid
        ↓
Continue recursively
```

### Why This Matters

Consider the constraint:

> The girl cannot sit on the middle bench.

If we have already constructed:

```text
B1 G
```

we immediately know that this partial arrangement can never become a valid solution because `G` is already occupying the middle position.

Therefore, we don't need to try:

```text
B1 G B2
```

at all.

The branch can be **pruned**:

```text
        {}
        |
       B1
      /  \
    B2    G
    |     ✗
    G    PRUNE
```

This is the fundamental advantage of backtracking.

### The Key Relationship

Permutation generation answers:

> **"What are all the possible arrangements?"**

Backtracking answers:

> **"Can I construct the arrangements incrementally while abandoning impossible branches as early as possible?"**

Therefore:

> **Permutation generation is a useful problem domain for understanding backtracking, because permutations naturally form a decision tree. Backtracking adds constraint checking, pruning, recursion, and state restoration to the exploration of that tree.**

This distinction is important:

```text
Permutation
    ≠
Backtracking

Instead:

Permutation
    ↓
Creates a combinatorial search space

Backtracking
    ↓
Provides a systematic way to explore that search space
while pruning invalid partial solutions.
```

### From Permutations to N-Queens

This relationship becomes even clearer with N-Queens.

For N-Queens, we can think of the problem as choosing one column for each row:

```text
Row 0 → choose column
Row 1 → choose column
Row 2 → choose column
...
Row N-1 → choose column
```

Every sequence of choices represents a candidate arrangement.

Backtracking explores these choices:

```text
Choose column
      ↓
Check whether queen placement is safe
      ↓
Invalid?
  ├── Yes → prune
  └── No  → recurse
              ↓
          place next queen
              ↓
          eventually fail?
              ↓
             undo
```

Thus, both the permutation example and N-Queens follow the same fundamental model:

```text
                 Backtracking
                      │
       ┌──────────────┼──────────────┐
       ↓              ↓              ↓
     Choice        Constraint       Undo
       │              │              │
       └──────────────┼──────────────┘
                      ↓
                  Recursion
                      ↓
                   Pruning
```

The permutation example is therefore a simple way to introduce the **decision-tree structure**, while N-Queens demonstrates why **constraint checking and pruning** make backtracking powerful.
