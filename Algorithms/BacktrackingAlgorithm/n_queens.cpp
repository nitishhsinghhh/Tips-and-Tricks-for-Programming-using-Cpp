/**
 * @file n_queens.cpp
 * @author Nitish Singh
 * @brief Backtracking solver for the N-Queens problem.
 * @version 0.1
 * @date 2026-05-15
 * * @copyright Copyright (c) 2016-2026
 */

#include <iostream>
#include <vector>

/**
 * @brief Checks whether a queen can be safely placed at a given position.
 *
 * This function validates the current position against previously placed
 * queens. Since queens are placed row by row, only the same column and
 * the two upper diagonals need to be checked.
 *
 * @param board The current state of the chessboard.
 * @param row The row where the queen is being considered.
 * @param col The column where the queen is being considered.
 * @return true If no previously placed queen can attack this position.
 * @return false If the position is under attack by another queen.
 */
bool isSafe(const std::vector<std::vector<int>>& board, int row, int col) {
    const int n = static_cast<int>(board.size());

    // Check same column
    for (int i = 0; i < row; ++i) {
        if (board[i][col] == 1) {
            return false;
        }
    }

    // Check upper-left diagonal
    for (int i = row - 1, j = col - 1;
         i >= 0 && j >= 0;
         --i, --j) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    // Check upper-right diagonal
    for (int i = row - 1, j = col + 1;
         i >= 0 && j < n;
         --i, ++j) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    return true;
}

/**
 * @brief Recursively solves the N-Queens problem using backtracking.
 *
 * The algorithm places one queen in each row and explores every possible
 * column. If a placement leads to a dead end, the queen is removed and
 * the algorithm backtracks to try the next available position.
 *
 * @param board The current state of the chessboard.
 * @param row The current row where a queen is to be placed.
 * @return true If a valid N-Queens solution is found.
 * @return false If no valid solution exists from the current state.
 */
bool solveNQueens(std::vector<std::vector<int>>& board, int row) {
    const int n = static_cast<int>(board.size());

    // Base case: all queens have been successfully placed.
    if (row >= n) {
        return true;
    }

    // Try placing a queen in every column of the current row.
    for (int col = 0; col < n; ++col) {
        if (isSafe(board, row, col)) {
            board[row][col] = 1;

            // Recursively solve the remaining rows.
            if (solveNQueens(board, row + 1)) {
                return true;
            }

            // Backtrack and remove the queen.
            board[row][col] = 0;
        }
    }

    return false;
}

/**
 * @brief Main entry point for the N-Queens solver.
 *
 * Reads the board size from standard input, initializes the chessboard,
 * and invokes the recursive backtracking solver. If a solution exists,
 * the resulting board configuration is printed.
 *
 * @return int Standard exit code (0 for success, 1 for invalid input).
 */
int main() {
    int num;

    std::cout << "Enter the size of the chessboard (num): ";
    std::cin >> num;

    if (num <= 0) {
        std::cerr << "Board size must be positive.\n";
        return 1;
    }

    std::vector<std::vector<int>> board(
        num, std::vector<int>(num, 0)
    );

    if (solveNQueens(board, 0)) {
        std::cout << "Solution found:\n";

        // Output the solved chessboard.
        for (int i = 0; i < num; ++i) {
            for (int j = 0; j < num; ++j) {
                std::cout << board[i][j] << ' ';
            }

            std::cout << '\n';
        }
    } else {
        std::cout << "No solution found.\n";
    }

    return 0;
}