/*
Here is an example of a brute force algorithm in C++ that finds all the prime numbers within a given range:
*/

#include <iostream>
using namespace std;

bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i < n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int start, end;
    cout << "Enter the range (start and end): ";
    cin >> start >> end;
    cout << "Prime numbers between " << start << " and " << end << " are: ";
    for (int i = start; i <= end; i++) {
        if (isPrime(i)) {
            cout << i << " ";
        }
    }
    cout << endl;
    return 0;
}

/*
This program uses a brute force approach to check every number in the given range to see if it is prime or not. 
The isPrime function checks if a given number is prime by iterating through all the numbers from 2 to n-1 and 
checking if any of them divide n evenly. If none do, the function returns true indicating that n is prime. The 
main function takes input for the range of numbers to check and uses a for loop to iterate through all the numbers 
in the range, calling the isPrime function on each one. If a number is prime, it is printed to the console.
*/
