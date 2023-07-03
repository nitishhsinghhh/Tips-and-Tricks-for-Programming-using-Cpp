// Here is an example of a dynamic programming algorithm in C++ that solves the Fibonacci sequence:

#include <iostream>
#include <vector>
using namespace std;

int fibonacci(int n) {
    vector<int> memo(n + 1, 0);
    memo[1] = 1;
    for (int i = 2; i <= n; i++) {
        memo[i] = memo[i - 1] + memo[i - 2];
    }
    return memo[n];
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;
    cout << "The " << n << "th Fibonacci number is " << fibonacci(n) << endl;
    return 0;
}

/* 
This program uses a dynamic programming algorithm to calculate the nth number in the Fibonacci sequence. The fibonacci 
function takes an integer n as input and uses a vector to store the results of previous computations. It initializes the 
first two numbers in the sequence as 0 and 1, and then iteratively computes each subsequent number by adding the previous 
two numbers together. The function returns the nth number in the sequence. The main function takes input for n and calls 
the fibonacci function to calculate the nth number, printing the result to the console. The dynamic programming approach 
allows the function to avoid redundant computations by storing and reusing the results of previous computations, making it 
more efficient than a naive recursive approach.
*/
