//Here is an example of a backtracking algorithm in C++ that solves the N-Queens problem:

#include <iostream>
#include <vector>
using namespace std;

bool isSafe(vector<vector<int>>& board, int row, int col) {
    // Check if any queens are in the same column
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 1) {
            return false;
        }
    }
    // Check if any queens are in the same diagonal
    int i = row, j = col;
    while (i >= 0 && j >= 0) {
        if (board[i][j] == 1) {
            return false;
        }
        i--;
        j--;
    }
    i = row, j = col;
    while (i >= 0 && j < board.size()) {
        if (board[i][j] == 1) {
            return false;
        }
        i--;
        j++;
    }
    // If no conflicts found, return true
    return true;
}

bool solveNQueens(vector<vector<int>>& board, int row) {
    // Base case: all queens placed
    if (row >= board.size()) {
        return true;
    }
    // Try placing the queen in each column of the current row
    for (int col = 0; col < board.size(); col++) {
        if (isSafe(board, row, col)) {
            board[row][col] = 1;
            // Recursively try to place the remaining queens
            if (solveNQueens(board, row+1)) {
                return true;
            }
            // If no solution found, backtrack and remove the queen from this cell
            board[row][col] = 0;
        }
    }
    // If no solution found for any column, return false
    return false;
}

int main() {
    int n;
    cout << "Enter the size of the chessboard (N): ";
    cin >> n;
    vector<vector<int>> board(n, vector<int>(n, 0));
    if (solveNQueens(board, 0)) {
        cout << "Solution found:" << endl;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board.size(); j++) {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
    } else {
        cout << "No solution found." << endl;
    }
    return 0;
}
/*
This program uses a backtracking algorithm to solve the N-Queens problem, which involves placing N queens on an NxN 
chessboard such that no two queens attack each other. The isSafe function checks if a given cell is safe to place a 
queen by checking if any other queens are in the same column or diagonal. The solveNQueens function uses a recursive 
backtracking approach to try placing the queens in each row, starting from the first row. It calls isSafe to check if 
the current cell is safe to place a queen, and if it is, it places the queen and recursively calls itself on the next row. 
If a solution is found, it returns true. If no solution is found for any column in a given row, it backtracks to the previous 
row and tries a different column. The main function takes input for the size of the chessboard and creates an empty board. It 
calls solveNQueens on the first row and prints the solution to the console if one is found.
*/
