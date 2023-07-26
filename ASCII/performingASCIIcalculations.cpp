#include <iostream>
using namespace std;

void main() {
 char char1 = '3';
 char char2 = '7';
 int num1 = char1 - '0'; // converting character to integer
 int num2 = char2 - '0'; // converting character to integer
 int sum = num1 + num2;
 cout << "The sum of " << char1 << " and " << char2 << " is " << sum << endl;

}

// Output: The sum of 3 and 7 is 10
