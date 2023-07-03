// Here is an example of a recursive algorithm in C++ that calculates the factorial of a given number:
#include <iostream>
using namespace std;

int factorial(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * factorial(n-1);
    }
}

int main() {
    int n;
    cout << "Enter a number to calculate its factorial: ";
    cin >> n;
    cout << n << "! = " << factorial(n) << endl;
    return 0;
}
/*
This program uses a recursive approach to calculate the factorial of a given number. The factorial function takes an 
integer n as input and recursively calls itself with n-1 until it reaches the base case of n=0, at which point it returns 1. 
The final result is the product of n and the factorial of n-1. The main function takes input for the number to calculate 
the factorial of and calls the factorial function on that number, printing the result to the console.
*/
