#include <iostream>
#include <string>
using namespace std;

void main() {
 char input_char;
 int input_num;
 cout << "Enter a number between 1 and 10: ";
 cin >> input_char;
 input_num = input_char - '0'; // Converting character to integer
 input_num >= 1 && input_num <= 10 ? cout << "Valid input: " << input_num << endl 
  : cout << "Invalid input: " << input_char << endl;

}

/*
Output:
Enter a number between 1 and 10: J
Invalid input: J
Enter a number between 1 and 10: 1
valid input: 1
*/
