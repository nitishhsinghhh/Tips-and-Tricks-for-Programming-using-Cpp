# Backtracking Algorithms

Backtracking is a problem-solving algorithm that employs a brute force approach to finding the desired output. By trying out all possible solutions and choosing the best one, this method is effective for solving problems with multiple solutions. The term "backtracking" implies that if the current solution is unsuitable, the algorithm backtracks and explores other solutions, often utilizing recursion. Backtracking algorithms are problem-solving strategies that involve exploring different options until the best solution is found. They work by attempting different paths and backtracking if necessary, akin to solving a puzzle by testing different pieces until they fit together perfectly.

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

