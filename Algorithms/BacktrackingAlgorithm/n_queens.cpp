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