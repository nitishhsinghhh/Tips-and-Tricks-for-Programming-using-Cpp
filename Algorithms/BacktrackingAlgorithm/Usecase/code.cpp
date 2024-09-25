/*
Author: Nitish Singh
Date: February 26, 2024; September 25, 2024
Email ID: me.singhnitish@yandex.com

Problem Statement:
This program demonstrates the use of a backtracking algorithm to solve the num-Queens problem, which involves placing num queens on an NxN chessboard such that no two queens attack each other.

Solution:
The program uses a backtracking algorithm to solve the num-Queens problem. The isSafe function checks if a given cell is safe to place a queen by examining if 
any other queens are in the same column or diagonal. The solveNQueens function uses a recursive backtracking approach to attempt placing the queens in each row, 
starting from the first row. It calls isSafe to verify if the current cell is safe to place a queen and, if it is, places the queen and recursively calls itself 
on the next row. If a solution is found, it returns true. If no solution is found for any column in a given row, it backtracks to the previous row and tries a 
different column. The main function takes input for the size of the chessboard and creates an empty board. It calls solveNQueens on the first row and prints the 
solution to the console if one is found.

Additional Information:
- The program uses a backtracking algorithm to solve the num-Queens problem, ensuring that no two queens can attack each other on the chessboard.
*/

#include <iostream>
#include <vector>

bool isSafe(std::vector<std::vector<int>>& board, int row, int col) {
	// Check if any queens are in the same column
	for (int i = 0; i < row; i++) 
		if (board[i][col] == 1) 
			return false;

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

bool solveNQueens(std::vector<std::vector<int>>& board, int row) {
	// Base case: all queens placed
	if (row >= board.size()) 
		return true;

	// Try placing the queen in each column of the current row
	for (int col = 0; col < board.size(); col++) {
		if (isSafe(board, row, col)) {
			board[row][col] = 1;
			// Recursively try to place the remaining queens
			if (solveNQueens(board, row + 1)) 
				return true;
		
			// If no solution found, backtrack and remove the queen from this cell
			board[row][col] = 0;
		}
	}
	// If no solution found for any column, return false
	return false;
}

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
	else 
		std::cout << "No solution found." << std::endl;

	return 0;
}

/*
Enter the size of the chessboard (num): 4
Solution found:
0 1 0 0
0 0 0 1
1 0 0 0
0 0 1 0
*/